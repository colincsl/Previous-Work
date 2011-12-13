import unittest
import numpy as np
import copy

import mrol_mapping.mrol as mrol
import mrol_mapping.pointcloud as pointcloud


class test_mrol(unittest.TestCase):
    def setUp(self):
        self.base_res = 0.1
        self.levels = 5
        self.m = mrol.MROL(self.base_res, levels=self.levels)
        self.X = np.arange(0, 3, 0.1).reshape(-1, 3)

    def integrity_check(self, mapmrol):
        '''Caries at various integrity checks on an MROL.  For example making sure 
        that the sum of occupancies is the same at each level.'''
        totals = []
        for ol in mapmrol.mapvoxels:
            totals.append(sum(ol.getoccupancies()))
        totals = np.asarray(totals)
        # Check all the totals are equal
        self.assertTrue(np.all(totals == totals[0]))

    def test_equal(self):
        self.m.addpoints(self.X)
        mrovl = mrol.MROL(self.base_res, self.levels)
        mrovl.addpoints(self.X[:-1])
        self.assertNotEquals(self.m, mrovl)
        mrovl.addpoints(self.X[-1])
        self.assertEquals(self.m, mrovl)

    # TODO merge tests like these with equivalent test for occupiedlist?
    def test_addpoints(self):
        # Test adding a single point
        self.m.addpoints(self.X[0])
        self.integrity_check(self.m)
        # Test adding multiple points
        self.m.addpoints(self.X)
        self.integrity_check(self.m)

    def test_addremove(self):
        # addition and removal of same points should be idempotent
        self.m.addpoints(self.X)
        m_copy = copy.deepcopy(self.m)
        self.m.addpoints(self.X*2)
        self.m.removepoints(self.X*2)
        self.assertEquals(m_copy, self.m)

        
    def OFFtestMROLBasics(self):
        # check structural consistency
        res = self.base_res
        for i in range(self.levels):
            self.assertTrue(self.m.mapvoxels[-(i+1)].resolution == res)
            res = res*2
            self.assertTrue(len(self.m.mapvoxels[i]) == 0)
        # check the simple adding and retrieving of data
        self.m.addpoints(self.X)
        self.checkEqualObservations(len(self.m)-1, 1)
        self.checkEqualObservations(-1, 1)
        self.assertTrue(len(self.m.mapvoxels[0]) == 3)
        self.assertTrue(len(self.m.mapvoxels[1]) == 6)
        self.assertTrue(len(self.m.mapvoxels[2]) == 10)
        self.assertTrue(len(self.m.mapvoxels[3]) == 10)
        self.assertTrue(len(self.m.mapvoxels[4]) == 10)
        self.checkObservationConsistency(len(self.X)) 
        self.m.addpoints(self.X)
        self.checkEqualObservations(-1, 2)
        self.checkObservationConsistency(2*len(self.X))
        expected_voxels = (
                        (27,  28,  29),
                        (15,  16,  17),
                        ( 9,  10,  11),
                        ( 0,   1,   2),
                        (18,  19,  20 ),
                        ( 6,   7,   8),
                        (24,  25,  26),
                        (21,  22,  23),
                        (12,  13,  14),
                        ( 3,   4,   5),
                        )
        # Note: numerical precision makes some of these ambiguous
        self.checkExpectedVoxels(expected_voxels)
        expected_voxels = (
                        (0, 0, 1),
                        (2, 2, 2),
                        (3, 4, 4),
                        (4, 5, 6),
                        (6, 6, 7),
                        (8, 8, 8),
                        (9, 10, 10),
                        (10, 11, 12),
                        (12, 12, 13),
                        (14, 14, 15),
                        )
        level = self.levels-2
        self.checkExpectedVoxels(expected_voxels, level=level)
        expected_voxels = (
                        (0, 0, 0),
                        (1, 1, 1),
                        (2, 2, 2),
                        (2, 2, 3),
                        (4, 5, 5),
                        (3, 3, 4),
                        (4, 4, 4),
                        (5, 6, 6),
                        (6, 6, 6),
                        (7, 7, 7),
                        )
        level = self.levels-3
        self.checkExpectedVoxels(expected_voxels, level=level)
        expected_voxels = (
                        (0, 0, 0),
                        (0, 0, 1),
                        (1, 1, 1),
                        (2, 2, 2),
                        (3, 3, 3),
                        (3, 4, 4),
                        )
        level = self.levels-4
        self.checkExpectedVoxels(expected_voxels, level=level)
        expected_voxels = (
                        (0, 0, 0),
                        (1, 1, 1),
                        (2, 2, 2),
                        )
        level = 0
        self.checkExpectedVoxels(expected_voxels, level=level)
        
    # basic multires calccost check
    def OFFtestMROLCalcCosts(self):
        self.m.addpoints(self.X)
        pose = None
        costs = self.m.calccost(pose, self.X)
        self.assertTrue(costs == [-10, -10, -10, -10, -10])
        total_cost = self.m.objectivefuncMROL(pose, self.X)
        self.assertTrue(total_cost == np.sum(costs))
        
    def OFFtestMROLRemove(self):
        self.m.addpoints(self.X)
        self.m.addpoints(self.X)
        self.checkEqualObservations(-1, 2)
        self.checkObservationConsistency(2*len(self.X)) 
        xyzs_remove = self.X
        self.m.removepoints(xyzs_remove)
        #gone = self.m.removepoints(xyzs_remove)
        #self.assertTrue(len(gone) == 0)
        self.checkEqualObservations(-1, 1)
        self.checkObservationConsistency(len(self.X)) 
        xyzs_remove = self.X[0:5, :]
        #gone = self.m.removepoints(xyzs_remove)
        self.m.removepoints(xyzs_remove)
        self.checkObservationConsistency(len(self.X)/2) 
        self.checkEqualObservations(-1, 1)
        gone_expected = (
                        (0, 1, 2),
                        (3, 4, 5),
                        (6, 7, 8),
                        (9, 10, 11),
                        (12, 13, 14)
                        )
        gone = self.m.getvoxels()
        # TODO was not sure how to get this one working
        #self.setCheck(gone, gone_expected)
        ol = self.m.mapvoxels[4]
        pose = None
        overlap = ol.calccollisions(pose, xyzs_remove, returntotal=True) 
        self.assertEquals(overlap, 0)
        expected_totals = (7, 6, 5, 5, 5)
        for i, ol in enumerate(self.m.mapvoxels):
            overlap = ol.calccollisions(pose, self.X)
            self.assertEqual(overlap, expected_totals[i])
        #self.m.addpoints(self.X)
        #self.checkObservationConsistency(len(self.X)+len(self.X)/2)
        #self.m.removepoints(self.X, delete=True)
        #self.assertTrue(len(self.m.getfinest()) == 0)
    
    # TODO re-implement this test after the trajectory class is developed
    #def testMROLkeyframe
    #    # check keyframe set/get
    #    pose = (0, 0, 0, 0, 0, 0)
    #    self.m.setkeyframe(X, pose)
    #    self.assertTrue(occupiedlist.calccollisions(pose, self.m.getkeyframeset(), self.base_res, X) == 5)
    #    self.assertTrue(occupiedlist.calccollisions(pose, self.m.getkeyframeset(), self.base_res, self.X[6:, :]) == 0)
        
    def checkObservationConsistency(self, numobs):
        ''' Checks the total occupancy is consistent across all levels
        and that they are as expected'''
        for ol in self.m.mapvoxels:
            numpoints = np.sum(ol.getoccupancies())
            self.assertTrue(numpoints == numobs)
            
    def checkEqualObservations(self, level, numobs):
        ''' Checks that all cells at a given resolution level have the
        same occupancy and that they are as expected'''
        occupancies = self.m.mapvoxels[level].getoccupancies()
        for obs in occupancies:
            self.assertTrue(obs == numobs)
            
    def checkExpectedVoxels(self, voxels, level=-1):
        ''' Checks that the voxels contained in the mrol at the given 
        resolution are as expected'''
        self.setCheck(voxels, self.m.getvoxels(level=level))
        expected_points = np.array(voxels)*self.m.mapvoxels[level].resolution
        self.checkExpectedPoints(expected_points, level=level)
        
    def checkExpectedPoints(self, points, level=-1):
        ''' Checks that the points represented by the voxels in the mrol
        at the given resolution are as expected'''
        self.setCheck(points, self.m.getpoints(level=level))
        
    def setCheck(self, data1, data2):
        pc1 = pointcloud.PointCloud(data1)
        pc2 = pointcloud.PointCloud(data2)
        self.assertEqual(pc1, pc2)
        #data1_set = set((d[0], d[1], d[2]) for d in data1)
        #data2_set = set((d[0], d[1], d[2]) for d in data2)
        #self.assertTrue(data1_set == data2_set)
        
if __name__ == '__main__':
    unittest.main()
