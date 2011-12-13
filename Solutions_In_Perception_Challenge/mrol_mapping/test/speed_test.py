#!/usr/bin/env python
from __future__ import division
import numpy as np
import time
import mrol_mapping.occupiedlist as occupiedlist
import mrol_mapping.poseutil as poseutil
import collections
import mrol_mapping.cython.fast as fast

import scipy.spatial as spatial

import unittest

# TODO run this speed test on real/simulated from blender data?

class SpeedTest(unittest.TestCase):
    def setUp(self):
        #np.random.seed(6)
        self.mpts = 100000 #Adding a zero here changes the cython results dramatically
        self.npts = 10000
        self.high = 50
        self.M = np.random.randint(0, self.high, (self.mpts, 3)).astype(np.int16)
        self.P = np.random.randint(0, self.high, (self.npts, 3)).astype(np.int16)
        
        self.testpose = (-2., 42., 80., 0.2, 0.1, 2.6)
        self.testposeinv = poseutil.inverse(self.testpose)
        self.Pxformed = poseutil.check_and_transform_points(self.P, self.testpose)[0]
        
        self.ol = occupiedlist.OccupiedList(1)
        self.ol.addpoints(self.M)

        self.Mkdt = spatial.cKDTree(self.M)

        self.maparray = np.zeros((self.high, self.high, self.high), dtype=np.bool)
        #self.maparray = ndsparse.ndsparse((self.high, self.high, self.high))
        self.maparray[self.M[:, 0], self.M[:, 1], self.M[:, 2]] = True

        # set up packed arrays map
        ids = occupiedlist._pack(self.M)
        self.mapvoxels_int16 = dict.fromkeys(ids, 1)
        self.mapset = set(ids)
        #self.mapvoxels_int16 = collections.defaultdict(int)
        #for ID in ids:
        #    self.mapvoxels_int16[ID.tostring()] += 1

        # bloom map
        self.bloom = occupiedlist.BloomFilter(self.mpts)
        self.bloom.add_voxel_ids(occupiedlist._pack(self.M))

        # dictionary of dictionaries
        #D = dict.fromkeys(self.mpts[:,0], dict())
        self.Pint = self.P.astype(int)

        D = dict()
        # first initialise
        for a, b, c in self.M:
            D.setdefault(a, dict())
            D[a].setdefault(b, dict())
            D[a][b][c] = 0
        for a, b, c in self.M:
            D[a][b][c] += 1
        self.nestedDict = D

    def nested_dict(self):
        D = self.nestedDict
        #ainds = np.where([i in D for i in self.P[:, 0]])[0]
        #binds = [self.P[i, 1] in D[self.P[i, 0]] for i in ainds]
        #cinds = ainds[np.array(binds)]
        #return sum(self.P[c, 2] in D[self.P[c, 0]][self.P[c, 1]] for c in cinds)

        #overlap = 0
        #for a, b, c in self.P:
            #if a in D and b in D[a] and c in D[a][b]:
                #overlap += 1

        overlap = sum(a in D and b in D[a] and c in D[a][b] for a, b, c in self.P)

        #overlap = fast.nested_intersection(D, self.Pint) 
        # cython version slower than python!

        return overlap

    def calccollisions_voxel_overlap(self):
        overlap = self.ol.calccollisions(None, self.P)
        return overlap
        
    def calccollisions_voxel_overlap_slow(self):
        self.ol.use_bloom = False
        overlap = self.ol.calccollisions(None, self.P)
        return overlap
        
    def packed_overlap_with_bloom(self):
        #PV = occupiedlist.pointstovoxels(self.P, 1)
        #ids = occupiedlist._pack(PV)
        ids = occupiedlist._pack(self.P)
        #import pydb; pydb.set_trace()
        overlaps = self.bloom.contains(ids)

        #return len(overlap)
        return np.sum(overlaps)

    def binaryarray_overlap(self):
        return np.sum(self.maparray[self.P[:, 0], self.P[:, 1], self.P[:, 2]])

    def kdtree_overlap(self):
        dists, inds = self.Mkdt.query(self.P, k=1, p=1)
        return sum(dists < 1)

    def transform_and_query(self):
        #overlap = self.ol.calccollisions(self.testposeinv, self.Pxformed)
        overlap = self.ol.calccollisions(self.testposeinv, self.Pxformed)
        return overlap

    def packed_set(self):
        Pset = occupiedlist._pack(self.P)
        overlap = self.mapset.intersection(Pset)
        return len(overlap)

    #def test_map_update(self):

    def test_map_query(self):
        # TODO re-write the comparison methods to operate on the same 
        # data sets as those that call an OccupiedList object.
        funcs = [
                self.nested_dict,
                self.calccollisions_voxel_overlap_slow,
                self.calccollisions_voxel_overlap,
                self.binaryarray_overlap,
                self.kdtree_overlap,
                self.packed_overlap_with_bloom,
                self.transform_and_query,
                #self.packed_set,
                ]

        expected_overlap = self.binaryarray_overlap()
        overlaps = []
        for func in funcs:
            print func.__name__, ':', 
            # execute set up code
            start = time.time()
            overlap = func()
            print
            print overlap, '/', len(self.P)
            overlaps.append(overlap)
            taken = time.time() - start
            rate = float(self.npts)/taken
            print rate*1e-6, 'million lookups/second'
            print
            assert rate > 1e5, 'Transformations and lookups not fast enough'

        # Make sure all overlaps are the same
        # TODO see above comment before re-enabling this assert
        #assert np.all(np.diff(overlaps) == 0)


if __name__ == '__main__':
    unittest.main()
