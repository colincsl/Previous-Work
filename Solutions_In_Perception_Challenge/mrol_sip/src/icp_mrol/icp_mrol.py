''' Author: Julian Ryde and Nick Hillier'''
# Establish correspondences
# Estimate transformation parameters using mean square cost function
# alternative just use an optimisation toolbox
# Transform points with improved pose
# reiterate
import roslib
roslib.load_manifest('mrol-mapping-ros-pkg')
import rospy

import numpy as np

import mrol_mapping.poseutil as poseutil
import mrol_mapping.visualiser.robotvisualiser as robotvisualiser


# TODO work out why "import pyflann" doesn't work
import sys
import subprocess
def get_shell_response(cmd):
    p = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)
    stdout, stderr = p.communicate()
    return stdout

flann_paths = [get_shell_response('rospack find flann')[:-1]+'/python']
for flann_path in flann_paths:
    sys.path.append(flann_path)
    try:
        print sys.path[-1]
        import pyflann
        break
    except (OSError, ImportError):
        sys.path.pop()

flann = pyflann.FLANN()

visualise = False
def initvisualiser():
    global visualise, vis
    visualise = True
    vis = robotvisualiser.Visualiser(title='ICP Visualiser')
    vis.clear()

def buildindex(Q):
    flann.build_index(Q)

def __associate(P, threshold, return_dists=False):
    '''Assumes the set of points Q (the map) is much larger than P (the scan) and establishes those 
    points in Q that best associate with or correspond to the points in P.  
    Best is currently judged based on proximity.  Returns two arrays of 
    associated points.
    Need to call build index before this. Points further than threshold are 
    considered to have no corresponding points'''

    Qinds, dists = flann.nn_index(P)
    # Pinds selects those points in P with a partner in Q
    # Julian believes dists is the square of the distance but is not sure
    
    # TODO flann library supports rejection thresholds Julian wonders
    Pinds = dists < threshold**2
    Qinds = Qinds[Pinds]

    if return_dists:
        return Qinds, Pinds, dists
    else:
        dist = np.sqrt(np.mean(dists[Pinds]))
        return Qinds, Pinds, dist

def __calctransform(P, Q):
    ''' Assumes the points in P and Q are associated '''
    assert P.shape == Q.shape
    # A, B matrices symbolically produced from derviation.py
    # however n's because derviation is for one point
    px, py, pz = np.sum(P, axis=0)
    px2, py2, pz2 = np.sum(P**2, axis=0)
    pxpy = np.sum(P[:, 0] * P[:, 1])
    pxpz = np.sum(P[:, 0] * P[:, 2])
    pypz = np.sum(P[:, 1] * P[:, 2])
    n = P.shape[0]
    A = np.array((
    [py2 + pz2,     -pxpy,     -pxpz,   0, -pz,  py],
    [    -pxpy, px2 + pz2,     -pypz,  pz,   0, -px],
    [    -pxpz,     -pypz, px2 + py2, -py,  px,   0],
    [        0,        pz,       -py,   n,   0,   0],
    [      -pz,         0,        px,   0,   n,   0],
    [       py,       -px,         0,   0,   0,   n]
    ))

    qx, qy, qz = np.sum(Q, axis=0)

    pzqy = np.sum(P[:, 2] * Q[:, 1])
    pyqz = np.sum(P[:, 1] * Q[:, 2])
    pxqz = np.sum(P[:, 0] * Q[:, 2])
    pzqx = np.sum(P[:, 2] * Q[:, 0])
    pyqx = np.sum(P[:, 1] * Q[:, 0])
    pxqy = np.sum(P[:, 0] * Q[:, 1])
    
    B = np.array((
    [pzqy - pyqz],
    [pxqz - pzqx],
    [pyqx - pxqy],
    [    px - qx],
    [    py - qy],
    [    pz - qz]
    ))

    X = np.linalg.solve(A, -B)
    # X is rotx, roty, rotz, x, y, z
    return np.squeeze(np.vstack((X[3:], X[:3])))

def align(initialpose, P, Q, terminate_threshold, reject_threshold=0.5, iterations=50, quiet=True):
    '''Given two sets of corresponding points (P, Q) and an initial guess 
    transform calculate the transform from P to Q. (i.e. P is scan, Q is map)'''
    assert(type(P[0][0]) == type(Q[0][0])), 'P and Q must be of the same data type'
    P = poseutil.transformPoints(P, poseutil.mat(initialpose))
    # looping without re-associating does improve but I think it is negligible, 
    # compared to error due to associations
    initialposemat = poseutil.mat(initialpose)
    bestposemat = poseutil.mat((0, 0, 0, 0, 0, 0))
    buildindex(Q)

    if visualise:
        vis.clear()
        Qvis = Q.copy()
        if len(Qvis) > 1e5:
            print "resampling for visualiser"
            Qvis = util.volumetricsample(Qvis, 0.1)
        vis.addmappts(Qvis)
        vis.setleftpts(P)
    last_dist = 0.0
    # TODO decide whether to bail early from this loop
    for iteration in range(iterations):
        Qinds, Pinds, dists = __associate(P, reject_threshold, return_dists=True)
        associated_pts = np.array([Q[ind] for ind in Qinds])
        dist = np.sqrt(np.mean(dists[Pinds]))        
        if len(P[Pinds]) == 0 or len(associated_pts) == 0:
            if not quiet:
                print "No points within association distance"
            return np.array([0,0,0,0,0,0]), 0
        X = __calctransform(P[Pinds], associated_pts)
        bestposemat = np.dot(bestposemat, poseutil.mat(X))
        P = poseutil.transformPoints(P, poseutil.mat(X))
        if visualise:
            # TODO set this threshold
            inds = dists < terminate_threshold 
            vis.setrightpts(P[inds])
            vis.setleftpts(P[np.logical_not(inds)])
        if not quiet:
            print iteration, dist
        if dist < terminate_threshold: break
        if np.abs(dist - last_dist) < 1e-9:
            if not quiet:
                print "Warning, no longer converging and termination threshold not reached. Possible local minima. Try changing the rejection threshold."
            break
        if iteration == iterations-1:
            print "Warning, maximum iterations reached."
        last_dist = dist
    bestposemat = np.dot(bestposemat, initialposemat)
    #inlier_pts, outlier_pts = classify_pts(P, Pinds)
    return np.array(poseutil.posetuple(bestposemat)), dist #, inlier_pts, outlier_pts

def segment(P_aligned, Q, reject_threshold, rebuild_index=False):
    # TODO can we check if the index is already built and not rebuild if not necessary?
    if rebuild_index:
        buildindex(Q)
    Qinds, Pinds, dist = __associate(P_aligned, reject_threshold)
    inlier_pts, outlier_pts = classify_pts(P_aligned, Pinds)
    return inlier_pts, outlier_pts
    
def classify_pts(P, Pinds):
    inlier_pts = P[Pinds] 
    outlier_pts = P[np.logical_not(Pinds)]
    return inlier_pts, outlier_pts
    
def cost(pose, P, Q, threshold=0.5, rebuild=True):
    '''Cost function based on root mean squared distance to approximate nearest 
    neighbour. '''
    if rebuild:
        buildindex(Q)
    # TODO refactor this into a class so make the requirement to call 
    # buildindex less error prone
    P = poseutil.transformPoints(P, poseutil.mat(pose))
    Qinds, Pinds, dist = __associate(P, threshold)
    return dist
