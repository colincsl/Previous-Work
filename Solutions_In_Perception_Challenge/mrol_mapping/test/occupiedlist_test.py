#!/usr/bin/env python

import unittest
import time
import numpy as np
import test.pystone as pystone
import copy

import mrol_mapping.poseutil as poseutil
import mrol_mapping.occupiedlist as occupiedlist
import mrol_mapping.pointcloud as pointcloud

def benchmark():
    return pystone.pystones()[1]

# TODO some of these tests can be run on both occupiedlists and mrol
class Testoccupiedlist(unittest.TestCase):
    def setUp(self):
        self.X = np.arange(30).reshape(10, 3)
        self.ol = occupiedlist.OccupiedList(0.2)
        
    def testpointstoandfromvoxels(self):
        res = 0.5 # is only exact for 0.5
        # test for all lattice quantisation functions
        for funcstr in occupiedlist.latticefuncs:
            # test reciprocal nature of conversion
            A = occupiedlist.pointstovoxels(self.X, res, latticetype=funcstr)
            Y = occupiedlist.voxelstopoints(A, res)
            self.assertTrue(np.allclose(self.X, Y)) 
            X = np.array([1, 2, 3]).reshape(1, 3)
            # TODO currently does not handle single points
            A = occupiedlist.pointstovoxels(X, res, latticetype=funcstr) 
            self.assertTrue(np.allclose(X/res, A)) 
        
    def testsaveload(self):
        """ tests addpoints, savexyz, loadxyz and equals """
        # test savexyz and loadxyz
        self.ol.addpoints(self.X)
        self.ol.savexyz('/tmp/ol.xyz')
        ol2 = occupiedlist.loadxyz('/tmp/ol.xyz', 0.2)
        self.assertEqual(self.ol, ol2)

    def testlen(self):
        self.ol.addpoints(self.X)
        self.assertEquals(len(self.ol), 10)

    def testuniformposes(self):
        centrepose = poseutil.Pose3D()
        spreadpose = poseutil.Pose3D()
        spreadpose.set([1, 1, 0, 0, 0, 1])
        poses = poseutil.uniformposes(centrepose, spreadpose, 0.2, 0.1) 
        self.assertEquals(len(poses), 2541)
        # TODO test for 3D

    def testrefineposes(self):
        p = np.ones((2, 6))
        refined = poseutil.refineposes(p, 0.1, 0.1)
        #if refined.shape[0] != 27:
        #    #D = np.diff(np.sort(refined, axis=1), axis=0)
        #    print np.sort(refined, axis=1)
        #self.assertEquals(27, refined.shape[0]) 
        # TODO this is correct for 2D needs to be generalised for 6DOF 
        #self.assertEquals(27, refined.shape[0]) 
        self.assertEquals(64, refined.shape[0]) 

    def testaddremovepoints(self):
        #ol = self.ol
        #ol.addpoints(self.X)
        #self.assertEquals(len(ol), 10)
        #ol.addpoints(2*self.X)
        #self.assertEquals(len(ol), 20)
        #self.assertTrue(np.all(ol.getoccupancies() == 1))
        #self.assertTrue(ol.getvoxels().shape == (20,3))
        #ol.addpoints(self.X)
        ## Ensure that the distribution of occupancies is as expected
        #counts = tuple(np.bincount(ol.getoccupancies()))
        #expected_counts = (0, 10, 10)
        #self.assertEqual(expected_counts, counts)

        #ol.removepoints(self.X)
        #counts = tuple(np.bincount(ol.getoccupancies()))
        #expected_counts = (0, 20)
        #self.assertEqual(expected_counts, counts)
        #removed = ol.removepoints(self.X, return_removed=True)
        #self.assertEqual(removed.shape, (10, 3))

        ol = self.ol
        bloomtable = self.ol.bloomfilter.bloomtable

        # check removing points on empty does not cause problems
        ol.removepoints(self.X) 
        self.assertEqual(len(ol), 0)
        self.assertEqual(np.sum(bloomtable), 0)

        # check adding and removing same points leaves occupiedlist empty
        ol.addpoints(self.X)
        ol.removepoints(self.X)
        self.assertEqual(len(ol), 0)
        # check the bloom table is empty as well
        self.assertEqual(np.sum(bloomtable), 0)

        # adding and removing should be inverse of one another
        ol.addpoints(self.X)
        ol_copy = copy.deepcopy(ol)
        ol.addpoints(2*self.X)
        ol.removepoints(2*self.X)
        self.assertEqual(ol, ol_copy)


    def test_proximity(self):
        # point on voxel faces should be shared equally between two adjacent 
        # voxels
        res = 0.1
        for i in range(3):
            ol = occupiedlist.OccupiedList(res)
            expected = np.zeros((2,3), dtype=int)
            expected[1, i] = 1
            X = [0, 0, 0]
            X[i] = res/2
            ol.addpoints(X)
            voxels = ol.getvoxels()
            self.assertTrue(pointcloud.equal(expected, voxels))
            occs = ol.getoccupancies()
            self.assertTrue(np.allclose(occs, occs[0], atol=0.001))

        # point on corner should be shared equally between 8 adjacent voxels
        ol = occupiedlist.OccupiedList(res)
        ol.addpoints((res/2, res/2, res/2))
        occs = ol.getoccupancies()
        self.assertTrue(np.allclose(occs, occs[0], atol=0.01))

        # point in middle of voxels with small sigma should only update one voxel
        ol = occupiedlist.OccupiedList(res)
        ol.addpoints((0,0,0), sigma=0.1)
        occs = ol.getoccupancies()
        self.assertTrue(occs[0] > 0.99)
        voxels = ol.getvoxels()
        self.assertTrue(np.allclose(voxels, (0,0,0)))

    def testequals(self):
        X = np.random.random((10, 3))*10
        A = occupiedlist.OccupiedList(0.05)
        A.addpoints(X)
        B = occupiedlist.OccupiedList(0.05)
        B.addpoints(X)
        self.assertEquals(A, B)
        Z = np.asarray(((0,0,0),))
        B.addpoints(Z)
        self.assertNotEquals(A, B)

    def testcalccollisions(self):
        limit = 3
        res = 0.1
        olmap = occupiedlist.OccupiedList(res)
        map_pts = np.random.random((3000, 3)) * limit
        olmap.addpoints(map_pts)
        overlap = olmap.calccollisions(None, map_pts)
        # To check a possible bug where calccollisions returns the number
        # of voxels instead of the number of points
        self.assertEqual(map_pts.shape[0], overlap) 
        self.assertNotEqual(len(olmap), overlap) 
        xyzs = map_pts[:100,:]
        overlap = olmap.calccollisions(None, xyzs)
        self.assertEqual(100, overlap) 
        olmap.removepoints(xyzs)
        overlap = olmap.calccollisions(None, map_pts[100:,:])
        self.assertEqual(map_pts.shape[0]-100, overlap) 

        # test with query option
        #occupancies = olmap.calccollisions(None, map_pts[100:,:], query=True)

        np.random.seed(6)
        npts = 4000
        xyzs = 2*limit*np.random.random((npts, 3)) - limit
        pose = None

    def test_fastenough(self):
        limit = 3
        res = 0.1
        cpu_speed = benchmark()
        # test update rate, number of points that can be added per second
        olmap = occupiedlist.OccupiedList(res)
        map_pts = np.random.random((3000, 3)) * limit
        start = time.time()
        olmap.addpoints(map_pts)
        taken = time.time() - start
        update_rate = len(map_pts)/taken
        print 'Map update speed:', update_rate, 'points/s'
        self.assertTrue(update_rate > 2000, 'OccupiedList update rate too slow')
        # TODO normalise this assertion for current cpu speed?

        # test query rate
        xyzs = map_pts[:100,:]
        pose = np.array([ -2., 42., 80., 0.2, 0.1, 2.6])
        for P in [None, pose]:
            print 'Transformations and lookups per second, with pose,', P
            start = time.time()
            collision_list = olmap.calccollisions(P, xyzs, returntotal=False)
            taken = time.time() - start
            print 1e-6 * len(xyzs)/taken, 'million/s'
            normalised = taken * cpu_speed
            print 'Normalised: ', normalised
            #self.assertEqual(np.sum(collision_list), overlap)
            self.assertTrue(normalised < 250, 'Too slow')
        
    def testdilate(self):
        X = ((0,0,0), (100,100,100))
        dilated = occupiedlist.dilate(X)
        expected = set([(0, 1, 1), (99, 100, 99), (100, 100, 99), (100, 100, 101), (100, 100, 100), (1, 0, 0), (-1, -1, -1), (-1, 1, -1), (101, 100, 99), (99, 101, 101), (101, 101, 100), (99, 101, 100), (100, 101, 99), (101, 99, 101), (101, 99, 99), (100, 101, 100), (0, -1, -1), (0, 0, -1), (-1, 0, 1), (100, 101, 101), (0, -1, 1), (-1, 0, 0), (101, 100, 100), (1, -1, 1), (99, 99, 99), (100, 99, 100), (1, -1, -1), (101, 100, 101), (101, 99, 100), (-1, 0, -1), (0, 0, 1), (99, 99, 101), (99, 100, 100), (0, 0, 0), (101, 101, 99), (0, -1, 0), (99, 100, 101), (1, 1, 1), (1, 0, 1), (-1, 1, 0), (1, 1, 0), (-1, 1, 1), (-1, -1, 1), (100, 99, 101), (1, 0, -1), (1, -1, 0), (-1, -1, 0), (99, 101, 99), (100, 99, 99), (1, 1, -1), (0, 1, 0), (101, 101, 101), (0, 1, -1), (99, 99, 100)])
        self.assertEquals(54, len(expected.intersection(dilated)))

    #def test_bloom(self):
    #    bloom = occupiedlist.BloomFilter()
    #    X = np.int16(self.X)
    #    bloom.add_voxels(X)
    #    C = bloom.contains(X)
    #    self.assertEquals(C.sum(), 10)
    #    C = bloom.contains(X+100)
    #    self.assertEquals(C.sum(), 0)
        
if __name__ == '__main__':
    unittest.main()
    #suite = unittest.TestLoader().loadTestsFromTestCase(Testposeutil)
    #suite.addTests(unittest.TestLoader().loadTestsFromTestCase(Testoccupiedlist))
    #unittest.TextTestRunner(verbosity=2).run(suite)

