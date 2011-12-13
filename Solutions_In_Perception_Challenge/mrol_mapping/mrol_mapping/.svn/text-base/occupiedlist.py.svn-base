from __future__ import division
import collections
import numpy as np
import scipy.stats as stats

import poseutil
import quantizer
import pointcloud

""" Dictionary of the currently implemented lattice quantizers """
latticefuncs = {'cubic':quantizer.quantize_cubic, 'bcc':quantizer.quantize_bcc, 'fcc':quantizer.quantize_fcc}

cdf_res = 0.01
cdf_halfwidth = 2
def _x_to_ind(X):
    '''Converts x to an index in the lookup table'''
    return np.int32((X + cdf_halfwidth)/cdf_res + 0.5)
    
normcdf = stats.norm.cdf(np.arange(-cdf_halfwidth, cdf_halfwidth, cdf_res))
# lookup table for the cdf
def cdf_approx(xs, sigma):
    return normcdf[_x_to_ind(xs)]

def loadxyz(fname, resolution):
    '''loads a list of points in x, y, z format from a file and makes an 
    occupied voxel list'''
    xyzs = np.loadtxt(fname)
    ol = OccupiedList(resolution)
    ol.addpoints(xyzs[:, 0:3])
    return ol

def pointstovoxels(X, resolution, latticetype='cubic'):
    '''Converts a list of points to integer voxel indices.'''
    # Possible lattice types currently include cubic, bcc and fcc.

    # TODO out of bound check required.
    #return latticefuncs[latticetype](X, resolution)
    #out = np.empty((X.shape[0], 4), dtype=np.int16) # uninitialised for speed
    #out[:,3] = 0 # set last column to zero
    out = np.empty(X.shape, dtype=np.int16) # uninitialised for speed
    np.round(X/resolution, out=out)
    #np.floor(X/resolution, out)
    return out

def voxelstopoints(A, resolution):
    """ Converts an array of integers voxel indices to an array of points """
    # TODO make this work for alternative lattices
    return A*resolution

def dilate(voxels):
    '''Add adjacent voxels, effectively blurring or smearing occupied voxel 
    list'''
    # blur/smear map instead of line above to include checking of adjacent voxels
    mg  = np.mgrid[-1:2, -1:2, -1:2]
    mg.shape = (3, 27, 1)
    voxels = np.array(voxels).T
    dilated = mg + voxels[:, np.newaxis, :]
    dilated = dilated.transpose((0, 2, 1)).reshape(3, -1).T
    return set(tuplelist(dilated))

def tuplelist(X):
    '''Converts an nx3 array to a list of tuples quickly this is useful for 
    bulk insertion into dictionaries and sets'''
    return zip(X[:, 0], X[:, 1], X[:, 2])

def _unpack(ids):
    '''converts an int64 array of voxel ids to an nx4 array of np.int16. 
    Near instantaneous in place operation'''
    ids.dtype = np.int16
    ids.shape = -1, 4
    #inds = ids.view(dtype=np.int16)
    return ids[:,:3]

def _pack(inds):
    '''converts an integer array of int16 voxels to an array of ids.'''
    assert inds.dtype == np.int16, 'inds needs to be np.int16'
    #assert inds.shape[1] == 4 
    # needs to be padded with a column of zeros

    # TODO could speed this up and make is faster by defining your own dtype
    # e.g. dt = dtype('i2,i2,i2') and du = dtype('S6') for the 6 byte key
    # Trouble is that you cannot hash the elements of the resulting array
    #dt = np.dtype('S6')
    #inds.dtype = dt

    X_int16 = np.empty((inds.shape[0], 4), dtype=np.int16)
    X_int16[:, :3] = inds
    X_int16[:, 3] = 0
    X_int16.dtype = np.int64
    X_int16.shape = -1
    return X_int16

    #return inds.view(np.dtype('S6'))

class BloomFilter:
    '''Special case counting bloom filter optimized for voxel indices'''

    def __init__(self, size):
        # TODO add probability of false positive as parameter
        self.size = int(6*size) # should this be prime or what?
        self.K = 2 # number of hash functions 
        self.bloomtable = np.zeros((self.K, self.size), dtype=np.int8) 
        # signed here although not needed makes update errors to the bloomtable 
        # easier to spot

    def __len__(self): 
        return self.size

    def __eq__(self, bf):
        return np.all(self.bloomtable == bf.bloomtable)

    def djbhash(self, i):
        """Hash function from D J Bernstein"""
        h = 5381L
        t = (h * 33) & 0xffffffffL
        h = t ^ i
        return h

    def fnvhash(self, i):
        """Fowler, Noll, Vo Hash function"""
        h = 2166136261
        t = (h * 16777619) & 0xffffffffL
        h = t ^ i
        return h

    #mask1 = eval('0b' + 32 * '01')
    #mask2 = eval('0b' + 32 * '10')
    def _hash_voxel_ids(self, ids):
        # Need a hash function that that can generate multiple hashes for given 
        # input and over a specified range
        inds = np.empty((2, ids.shape[0]), np.int64)
        inds[0] = self.fnvhash(ids)
        inds[1] = self.djbhash(ids)
        return inds % self.size

    def add_voxel_ids(self, ids):
        inds = self._hash_voxel_ids(ids)
        for i in range(self.K):
            for ind in inds[i]:  
                self.bloomtable[i,ind] += 1

    def remove_voxel_ids(self, ids):
        '''Decrement the counts for this counting bloom table but clamp to 
        zero'''
        inds = self._hash_voxel_ids(ids)
        for i in range(self.K):
            #to_change = self.bloomtable[i][inds[i]] 
            #to_change[to_change > 0] -= 1 
            remove_inds = inds[i][self.bloomtable[i][inds[i]] > 0]
            for ind in remove_inds:
                # select only those inds with counts > 0
                self.bloomtable[i, ind] -= 1
                #if np.any(to_change < 1):
                # only decrement those entries which are > 0

    def display(self): # debugging, for checking the distribution of the bloom table
        XX = np.where(self.bloomtable[0] > 0)[0]
        YY = np.where(self.bloomtable[1] > 0)[0]
        import pylab
        pylab.plot(XX, YY, '.')
        pylab.show()

    def contains(self, ids):
        '''Note that this is an approximation with tunable error.  False 
        positives are possible but false negatives are not.'''
        inds = self._hash_voxel_ids(ids)

        present = np.zeros((self.K, len(ids)), dtype=bool)
        for i in range(self.K):
            present[i] = self.bloomtable[i][inds[i]] > 0
        allpresent = present.sum(axis=0) == self.K
        return allpresent

class OccupiedList:
    """ stores a set of voxel indices list at multiple resolutions """

    def __init__(self, resolution, maxvoxels=1e6): 
        self.resolution = resolution
        
        # Worst case scenario for a cubic lattice is a point right on a 
        # diagonal corner, i.e. the probability is spread evenly between 
        # 8 cells (0.125). It seems reasonable to curtail the occupancy if 
        # it is half of this probability (1/4 of a cell diagonal if the cdf
        # was linear).
        self.occupancy_threshold = 0.5 * 1/8
        # below which voxels are removed and changes/increments of these are ignored unless re-added
        # occupancy scale factor # TODO maybe just use floats for occupancies?

        # voxels is a dictionary of np.int64 IDs that are the result of packing 4 np.int16
        self._voxels = collections.defaultdict(int)
        self.lattice = 'cubic' # should be one of the latticefuncs
        self.use_bloom = True
        self.use_KDE = False
        self.maxvoxels = maxvoxels
        if self.use_bloom:
            self.bloomfilter = BloomFilter(self.maxvoxels)

    def __eq__(self, o):
        if self.resolution != o.resolution or len(self) != len(o):
            return False
        for K, V in self._voxels.items():
            if o._voxels[K] != V:
                return False
        return True

    def __len__(self):
        return len(self._voxels)

    def __repr__(self): 
        occupancies = self.getoccupancies()
        occupancies.shape = -1, 1
        X = np.hstack((self.getvoxels(), occupancies))
        return str(X)

    def __sub__(self, ol):
        '''Set like subtraction'''
        # TODO in python 2.7 you can dict1.viewkeys() & dict2.viewkeys() to get 
        # the intersection of the keys on dictionary
        # TODO maybe quicker would be to find the intersection and then delete 
        # those voxels
        self_set = set(self._voxels.keys())
        ol_set = set(ol._voxels.keys())
        D = np.fromiter(self_set - ol_set, dtype=np.int64)
        D = _unpack(D)
        Dol = OccupiedList(self.resolution)
        increments = np.ones(len(D))
        Dol._update_voxels(D, increments)
        return Dol

    def getoccupancies(self):
        return np.asarray(self._voxels.values())

    def getvoxels(self):
        ids = np.asarray(self._voxels.keys())
        inds = _unpack(ids)
        return inds

    def getpoints(self):
        return voxelstopoints(self.getvoxels(), self.resolution)

    def display(self):
        pc = pointcloud.PointCloud(self.getpoints())
        pc.display()
    
    def KDE(self, x0, a0, sigma):
        '''Does a kernel density estimate for the point, x0 should be lattice 
        units and a0 is the coordinates of the nearest lattice point in lattice 
        units'''
        # calculate the kernel integrals between -inf, x0, x0 + 1 and inf
        integrals = np.zeros((3,3))
        for i, x in enumerate(x0):
            a = a0[i]
            #cumulative_integrals = stats.norm.cdf((a - 0.5, a + 0.5), loc=x, scale=sigma)
            cumulative_integrals = cdf_approx(np.asarray((a - x - 0.5, a - x + 0.5)), sigma=sigma)
            integrals[i] = np.diff(np.hstack((0, cumulative_integrals, 1)))
        # outer product returning a 3 * 3 * 3 array
        X = integrals[0].reshape(3,1,1)
        Y = integrals[1].reshape(1,3,1)
        Z = integrals[2].reshape(1,1,3)
        # return the kernel density integral over the volume of the lattice 
        # cell
        return X * Y * Z


    def _update_voxels(self, increment_inds, increments):
        # TODO is it worth merging multiple increments of the same voxel?
        ids = _pack(increment_inds)

        # Generate a list of newly added voxels and removed voxels for the 
        # bloom table update
        removed_ids = []
        new_ids = []
        for ID, increment in zip(ids, increments):
            if ID not in self._voxels:
                new_ids.append(ID)
            self._voxels[ID] += increment
            if self._voxels[ID] < self.occupancy_threshold: # see comment in 
                del self._voxels[ID]
                removed_ids.append(ID)

        removed_ids = np.asarray(removed_ids)
        new_ids = np.asarray(new_ids)
        if self.use_bloom:
            self.bloomfilter.add_voxel_ids(new_ids)
            self.bloomfilter.remove_voxel_ids(removed_ids) 

    # TODO do addpoints and removepoints properly by apportioning the point 
    # probability amongst surrounding voxels, like kernel density estimation.
    # This update should also be more sophisticated in terms of the sensor model.
    # TODO specify sigma as a covariance matrix
    # TODO specify sigma as a covariance matrix for each point to be added (this takes into account the pose of the sensor)
    def addpoints(self, xyzs, pose=None, increment=1, return_modified=False, sigma=0.5):
        """ convert points to voxel indices and append them to this occupied 
        voxel list """
        # TODO should really take a point cloud object rather than xyzs
        if len(xyzs) == 0:
            return
        xyzs = np.atleast_2d(xyzs) # for single points
        assert xyzs.shape[1] == 3, 'Points should be in a point cloud or n by 3 array format'
        if pose is not None:
            xyzs = pose.transformPoints(xyzs)

        inds = pointstovoxels(xyzs, self.resolution, self.lattice)
        # TODO check that voxel indices are not out of bounds


        if self.use_KDE:
            # TODO is similar to mgrid used in dilate, refactor these together or 
            # remove dilate as it is not needed now we are doing kernel density 
            # estimation
            surrounding_inds = np.int16((np.indices((3,3,3)) - 1).reshape(3, -1).T)

            # Add voxels to be incremented according to kernel density estimation
            increment_inds = []
            increments = []
            # TODO rather than use a list preallocate the array at 27 * len(xyzs)?
            # TODO make this work for single points
            for xyz, ind in zip(xyzs, inds):
                #increments.extend(np.int8(increment*self.KDE(xyz/self.resolution, ind)).ravel())
                kde = self.KDE(xyz/self.resolution, ind, sigma=sigma)
                #increments.extend(np.int8(increment*kde).ravel())
                increments.extend((increment*kde).ravel())
                # Now add these increments to the appropriate indices
                increment_inds.extend(ind + surrounding_inds)

            increment_inds = np.asarray(increment_inds)
            increments = np.asarray(increments)

            # remove increments that are too small to consider
            bigenough_inds = np.abs(increments) >= self.occupancy_threshold
            increments = increments[bigenough_inds]
            increment_inds = increment_inds[bigenough_inds]
        else:
            increment_inds = inds
            increments = np.ones(len(inds))*increment

        self._update_voxels(increment_inds, increments)

        assert len(self._voxels) < self.maxvoxels
        return increment_inds, increments

    def removepoints(self, xyzs, decrement=1, return_removed=False, **args):
        '''Decrement the observations in the voxels that the xyzs fall 
        into.'''
        return self.addpoints(xyzs, pose=None, increment=-decrement, return_modified=return_removed, **args)

        #If the delete flag is set, then remove the voxels that 
        #xyzs fall into. Return both the voxels that xyzs fall into and the 
        #total decrement amount for that voxel.

    def savexyz(self, fname):
        """ saves the finest occupied list to fname in x y z format """
        np.savetxt(fname, self.getpoints())

    def calccollisions(self, pose, xyzs, returntotal=True, query=False, out=None):
        '''The intersection of points with this occupied voxel list.
        If query then  return the density for each point after transformation 
        by the given pose, rather than just a count of hits.  out is an output 
        array for the result similar to numpy function.'''
        
        
        transformedpts, pose = poseutil.check_and_transform_points(xyzs,pose)
        
        #if type(pose) == type(poseutil.Pose3D()):
        #    if pose == poseutil.Pose3D():
        #        transformedpts = xyzs
        #    else:
        #        transformedpts = pose.transformPoints(xyzs)
        #else:
        #    if pose == None or (np.array(pose) == np.array((0, 0, 0, 0, 0, 0))).all() or (np.array(pose) == np.array((0.0, 0.0, 0.0, 0.0, 0.0, 0.0))).all():
        #        transformedpts = xyzs
        #    else:
        #        poseobj = poseutil.Pose3D()
        #        poseobj.set(pose)
        #        transformedpts = poseobj.transformPoints(xyzs)

        # TODO could speed this up by combining the transformPoints and division by 
        # resolution into one operation by generating a matrix that represents the 
        # transformation divided by the resolution and multiplying points through 
        # by that 
        # could also combine in the hash operation as well
        # in place operations and integer arithmetic might help
        transformedvoxels = pointstovoxels(transformedpts, self.resolution)
        ids = _pack(transformedvoxels)

        if query:
            if out is None:
                return [self._voxels[ID] for ID in ids]
            else:
                # TODO implement this
                raise NotImplemented
            #return sum(self._voxels[ID] for ID in ids)

        if self.use_bloom:
            present = self.bloomfilter.contains(ids)
            if returntotal:
                return np.sum(present) 
            else:
                return present
        else:
            # no range weighting TODO decide whether it is needed
            # Think the range weighting has been fixed by volumetric sampling

            if returntotal:
                return sum(ID in self._voxels for ID in ids)
            else:
                return [ID in self._voxels for ID in ids]

    def cost_func(self, pose, xyzs):
        return -self.calccollisions(pose, xyzs)
        #return self.calccollisions(pose, xyzs)

    def segment_ovl(self, pose, xyzs):
        ''' returns the inliers and outliers of the intersection of a point 
        cloud with this occupied voxel list.'''
        xyzs = poseutil.check_and_transform_points(xyzs, pose)[0]
        overlap_inds = np.array(self.calccollisions(None, xyzs, returntotal=False))
        inliers = xyzs[overlap_inds]
        outliers = xyzs[np.logical_not(overlap_inds)]
        return inliers, outliers

