'''Author: Julian Ryde'''
from __future__ import division
import numpy as np
import pylab
import sys
import mrol_mapping.pointcloud as pointcloud

# TODO generalise this so we can put it into MROL_mapping lib

def load_image(fname):
    ''' Load a depth image, generated from Blender '''
    di = pylab.imread(fname)
    # convert to ranges
    # blender map scale factor = 0.2
    blender_map = 0.2
    di /= blender_map
    return di


def image_to_points(di, max_range=5., fov=np.radians(75)):
    ''' Convert a depth image to point cloud'''
    
    # horizontal field of view setting in blender in degrees
    #fov = np.radians(75)

    # at edge tan fov/2 = 320 / a where a is the adjacent pixel length
    a = 0.5 * di.shape[1] / np.tan(fov/2)

    cols = np.arange(0, di.shape[1]) - di.shape[1]/2 + 0.5
    rows = np.arange(0, di.shape[0]) - di.shape[0]/2 + 0.5
    rows.shape = -1, 1

    f = di / a
    # scale factors between image plane and real space position of 
    # point, then by similar shapes, one is just a scale factor enlargement of the other
    # Blender z buffer returns not the range to the point but the distance from the camera plane, namely the z distance.

    # TODO could use a masked array for performance

    # camera looking along the x-axis
    Y = -f * cols
    Z = -f * rows
    X = f * a 

    #inds = np.logical_and(di < di.max(), di > 0)
    inds = np.logical_and(di < max_range, di > 0)
    
    xyzs = np.vstack((X[inds], Y[inds], Z[inds])).T
    pc = pointcloud.PointCloud(xyzs)
    return pc
    
def depth_discont_simple(di, tol=0.2):
    dx = np.diff(di, axis=0)
    #dx = np.vstack([np.zeros(di.shape[1]),dx])
    #dx = np.vstack([np.zeros(di.shape[1]),dx[:-1,:],np.zeros(di.shape[1])])
    dx = np.vstack([dx,np.zeros(di.shape[1])])
    dx = np.abs(dx)
    dx[dx < tol] = 0
    dy = np.diff(di, axis=1)
    #dy = np.hstack([np.atleast_2d(np.zeros(di.shape[0])).T,dy])
    #dy = np.hstack([np.atleast_2d(np.zeros(di.shape[0])).T,dy[:,:-1],np.atleast_2d(np.zeros(di.shape[0])).T])
    dy = np.hstack([dy,np.atleast_2d(np.zeros(di.shape[0])).T])
    dy = np.abs(dy)
    dy[dy < tol] = 0
    diff_im = np.sqrt(dx**2 + dy**2)
    #import pydb; pydb.set_trace()
    di_diff = np.zeros(di.shape)
    di_diff[diff_im > 0] = di[diff_im > 0]
    import pdb;pdb.set_trace()
    import pylab
    pylab.ion()
    pylab.imshow(di_diff)
    import scipy.ndimage as ndimage
    #di_diff = ndimage.minimum_filter(di_diff, size=(1,1))
    #for i in range(di_diff.shape[0]):
    #    for j in range(di_diff.shape[1]-1):
    #        p1 = di_diff[i,j]
    #        p2 = di_diff[i,j+1]
    #        if p1 == 0 or p2 == 0:
    #           continue
    #        if p1 > p2:
    #            p1 = 0
    #        elif p2 > p1:
    #            p2 = 0
    #        di_diff[i,j] = p1
    #        di_diff[i,j+1] = p2
    return di_diff
    
def depth_discont_sobel(di, tol=0.5):
    import scipy.ndimage as ndimage
    dx = ndimage.convolve(di,[[-1,0,1],[-2,0,2],[-1,0,1]])
    dy = ndimage.convolve(di,[[-1,-2,-1],[0,0,0],[1,2,1]])
    diff_im = np.sqrt(dx**2 + dy**2)
    diff_im[diff_im < tol] = 0
    #import pydb; pydb.set_trace()
    di_diff = np.zeros(di.shape)
    di_diff[diff_im > 0] = di[diff_im > 0]
    #import pdb;pdb.set_trace()
    #import pylab
    #pylab.ion()
    di_diff = ndimage.minimum_filter(di_diff, size=(2,2))
    #for i in range(di_diff.shape[0]):
    #    for j in range(di_diff.shape[1]-1):
    #        p1 = di_diff[i,j]
    #        p2 = di_diff[i,j+1]
    #        if p1 == 0 or p2 == 0:
    #           continue
    #        if p1 > p2:
    #            p1 = 0
    #        elif p2 > p1:
    #            p2 = 0
    #        di_diff[i,j] = p1
    #        di_diff[i,j+1] = p2
    #import pdb;pdb.set_trace()
    #pylab.imshow(di_diff)
    return di_diff

def depth_filt_min_non_zero(p1,p2):
    if p1 == 0 or p2 == 0:
        return
    if p1 > p2:
        p1 = 0
        return
    if p2 > p1:
        p2 = 0
        return
    return
    

def depth_disconts2(di, tol=0.2):
    import pydb;pydb.set_trace()
    import scipy.ndimage as ndimage
    ndimage.gaussian_filter(di,sigma=(5,5))
    ndimage.gaussian_derivative()
    ndimage.median_filter()
    return di_diff

if __name__ == '__main__':
    fname = sys.argv[1]
    xyzs = image_to_points(fname)
    import mrol_mapping.visualiser.dispxyz as dispxyz
    dispxyz.showpts(xyzs)
    print 'Escape to close window'
