import numpy as np
import occupiedlist
import quantizer

### SAMPLING UTILITIES ###

def getsample(P, N):
    # TODO more efficient version of this?
    if len(P) < N: return P
    np.random.shuffle(P)
    return P[:N]
    
def getfastsample(P, N):
    # Can return the same point twice, but is fast(er)
    if len(P) < N: return P
    rand_inds = np.random.randint(len(P),size=N) # flat distribution
    return P[rand_inds,:]

#def volumetricfastsample(P, res):
#    V = occupiedlist.pointstovoxels(P, res, unique=False)
#    VH = occupiedlist.hashrows(V)
#    mapvoxels = {}
#    mapvoxels.update(zip(VH,P)) # just takes last one that matches
#    return np.array(mapvoxels.values())    

def volumetricsample2(P, res):
    '''Return a subset of points where one has been selected at random from 
    each cell.'''
    np.random.shuffle(P)
    mapvoxels = {}
    # TODO use generators and numpy to optimize for speed?
    for p in P:
        pV = occupiedlist.pointstovoxels(p, res)
        mapvoxels[(pV[0], pV[1], pV[2])] = (p[0], p[1], p[2])
    return np.array(mapvoxels.values())

def volumetricsample(P, res):
    inds = occupiedlist.pointstovoxels(P, res)
    #np.random.shuffle(inds)
    # TODO accessing a private method should move this to occupiedlist, or make 
    # it part of the public api of occupiedlist?
    ids = occupiedlist._pack(inds)
    # This introduces a systematic error as inds_unique is just the first index encountered.
    ids_unique, inds_unique = np.unique1d(ids, return_index=True)
    return P[inds_unique]
    
def offsetvolsample(P,res):
    arr1 = volumetricsample(P,res)
    P = P + res/2.
    arr2 = volumetricsample(P,res)
    arr2 = arr2 - res/2.
    return np.vstack([arr1,arr2])

# TODO move this to pointcloud.py
def boxfilter(xyzs, mins, maxs):
    ''' mins is a list of minx, miny, minz and likewise for maxs, this operates 
    on the magnitudes of the values'''
    # TODO fails if xyzs has only one row 
    if len(xyzs) == 0:
        return xyzs
    xyzs = quantizer.tidy(xyzs)
    magnitudes = np.abs(xyzs)
    toonear = np.all(magnitudes < mins, axis=1)
    toofar = np.any(magnitudes > maxs, axis=1)
    select = np.logical_not(np.logical_or(toonear, toofar))
    #select = np.all(np.logical_and(magnitudes > rmin, magnitudes < rmax), axis=1)
    return xyzs[select, :]

    
### SEGMENTATION UILITIES ###

# The NULL hypothesis are the inliers. 
#
# http://en.wikipedia.org/wiki/Precision_and_recall
# http://en.wikipedia.org/wiki/Roc_curve

def segmentation_stats(inliers, outliers, trueinliers, trueoutliers):
    true_pos = [outls in trueoutliers for outls in outliers] # intersection of outliers
    true_neg = [inls in trueinliers for inls in inliers] # intersection of inliers
    false_pos = [outls in trueinliers for outls in outliers] # type I err
    false_neg = [inls in trueoutliers for inls in inliers] # type II err
    return true_pos, true_neg, false_neg, false_pos
    
def segmentation_summary(true_pos, true_neg, false_neg, false_pos, num_outliers, num_points):
    # False alarm rate
    FPR = float(sum(false_pos))/(sum(false_pos) + sum(true_neg))
    # Missed detection rate
    MDR = float(sum(false_neg))/(num_outliers)#(num_points) 
    # accuracy
    accuracy = float(sum(true_pos) + sum(true_neg))/num_points
    # specificity
    specificity = float(sum(true_neg)) / (sum(false_pos) + sum(true_neg))
    return FPR, MDR, accuracy, specificity

### FILE OPERATIONS ###

def get_mappoints_from_voxel_file(voxel_test_map_file):
    template_file = open(voxel_test_map_file)
    template_voxels = eval(template_file.read())
    map_resolution = template_voxels.pop('resolution')
    pts = []
    for ind in template_voxels.keys():
        pt = np.array(ind)*map_resolution
        pts.append(pt)
    map_points = np.array(pts)
    return map_points, map_resolution
    
def get_scan_points_from_file(voxel_test_query_scan_file):
    Pnew = np.loadtxt(voxel_test_query_scan_file)[:, :3]
    return Pnew

import mrol_mapping.poseutil as poseutil    
def get_scan_pose_from_file(voxel_test_query_pose_file):
    Ppose = np.loadtxt(voxel_test_query_pose_file)
    #T = transformations.translation_from_matrix(Ppose)
    #R = transformations.euler_from_matrix(Ppose)
    #return np.hstack((T, R))
    newPose = poseutil.Pose3D()
    newPose.setMatrix(Ppose)
    return newPose.getTuple()
