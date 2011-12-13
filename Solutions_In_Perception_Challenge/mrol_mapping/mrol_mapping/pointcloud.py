'''Point cloud module

Author: Julian Ryde'''
import numpy as np
import os

import util

def nearest_neighbour(A, B):
    '''Determine the distances the nearest neighbours in B to the points in A.  
    Uses a slow but accurate and hopefully bug free method
    
    Note that order is important.
    '''
    # TODO quicker version of this
    NN_dists = []
    NN_inds = []
    for i, a in enumerate(A):
        dists = np.sum((B - a) ** 2, axis=1)
        ind = np.argmin(dists)
        NN_dists.append(dists[ind])
        NN_inds.append(ind)
    return np.asarray(np.sqrt(NN_dists)), np.asarray(NN_inds)

# TODO unit test for this?
def equal(A, B):
    '''Is true is the arrays A and B are equal ignoring their row order'''
    return PointCloud(A) == PointCloud(B)

def load(fname):
    '''Loads a point cloud from disk whether it is a text array, numpy 
    binary array, assumes that each row is a point and the first three 
    columns are the coordinates.'''
    try:
        X = np.loadtxt(fname, usecols=(0, 1, 2))
    except:
        X = np.load(fname)
    return X[:,:3]
    
def save(fname, xyzs, text=False):
    '''Save a point cloud to disk. By default it is saved as a numpy 
    binary array, but it can be saved as plain text by setting the 
    'text' flag'''
    if text:
        np.savetxt(fname,xyzs)
    else:
        np.save(fname,xyzs)

class PointCloud:
    # TODO point clouds should be stored as ints in millimetres?

    def __init__(self, arr):
        '''Initialise the point cloud with an array of points'''
        # TODO handle both n x 3 and 3 by n arrays 
        # TODO throw error if conversion to an arrays not successful
        self.addpoints(arr)
        self.pose = None

    def __eq__(self, pc, tol=0.00001):
        # TODO pick a proper value for this tol, like np.allclose
        if len(self) != len(pc):
            return False
        nn_dists = nearest_neighbour(self.points, pc.points)[0]
        return np.all(nn_dists < tol)
        
    # TODO a subtract operator?
        
    def __len__(self):
        return self.points.shape[0]
        
    def addpoints(self, arr):
        # TODO enable growing of the pointcloud points
        arr = np.asarray(arr)
        if len(arr) > 0:
            self.points = np.atleast_2d(arr)
        else:
            self.points = arr # empty pc object

    def display(self, color=None):
        # import here to avoid circular dependency
        import mrol_mapping.visualiser.dispxyz as dispxyz
        return dispxyz.showpts(self.points, pose=self.pose, color=color)

    # TODO merge other implementation of boxfilter into this
    def boxfilter(self, xmin=None, ymin=None, zmin=None, xmax=None, ymax=None, zmax=None):
        '''Remove points outside of specified limits'''
        for i, limit in enumerate([xmin, ymin, zmin]):
            if limit is not None:
                self.points = self.points[self.points[:,i] > limit]
        for i, limit in enumerate([xmax, ymax, zmax]):
            if limit is not None:
                self.points = self.points[self.points[:,i] < limit]

    # TODO move the util.volumetricsample code to here 
    def volumetricsample(self, res):
        '''Downsamples the point cloud volumetrically according to the 
        resolution'''
        self.points = util.volumetricsample(self.points, res)

class ScansDir: 
    # TODO deprecated, just use a list of file names and pointcloud load instead
    ''' Reads in a group of pointcloud files from a directory '''
    # adapted from icra2011/make_template
    def __init__(self, basedir, skip_to=None):
        self.basedir = basedir
        fnames = os.listdir(basedir)
        fnames.sort()
        self.basenames = []
        skip_flag = False
        for fname in fnames:
            # TODO pass in startswith as an argument or make all files saved with this interface start with mrolpc
            if not fname.startswith('mrolpc'): continue
            if skip_to:
                if (not fname.startswith(skip_to)) and (not skip_flag):
                    continue
                else:
                    skip_flag = True
            self.basenames.append(fname)

    def __iter__(self):
        return self

    def next(self):
        '''Returns a scan'''
        if len(self.basenames) == 0: raise StopIteration
        self.curname = self.basedir+'/'+self.basenames.pop(0)
        print self.curname
        xyzs = load(self.curname)
        return xyzs
