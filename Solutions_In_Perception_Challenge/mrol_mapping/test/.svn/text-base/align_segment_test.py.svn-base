'''Options --print_table
Author: Julian Ryde and Nick Hillier

This tests the alignment and segmentation interfaces of the meta class files.
'''

import unittest
import cProfile

# utility libraries
import numpy as np
import sys
import time
import os
# required libraries
#import tf.transformations as transformations
import mrol_mapping.poseutil as poseutil
import mrol_mapping.pointcloud as pointcloud
import mrol_mapping.util as util
# meta libraries (what we are actually testing against)
import mrol_mapping.occupiedlist as occupiedlist
import mrol_mapping.mrol as mrol

# TODO produce deterministic behaviour - the sampling of the point cloud introduces the randomness
    
def generate_tst_data_from_file(voxel_test_map_file, voxel_test_query_scan_file, voxel_test_query_pose_file):
    print 'Loading test data from', voxel_test_map_file, '...',
    Qfile, map_resolution = util.get_mappoints_from_voxel_file(voxel_test_map_file)
    Pfile = util.get_scan_points_from_file(voxel_test_query_scan_file)
    Pnew = util.boxfilter(Pfile, (2, 1, 3), (9, 4.5, 7))
    guess_pose = util.get_scan_pose_from_file(voxel_test_query_pose_file)
    print 'Complete'
    return Pnew, Qfile, guess_pose, map_resolution

def field_to_str(f, decimal_places=3):
    if type(f) == str:
        return f
    else:
        return str(np.around(f, decimal_places))
        

def randomsearch(mapset,res,Pall,guesspose):
    ''' Exhaustive search for ground truth
    This function is used to generate the "true pose" which is used to generate the check data 
    sets for the segmentation. It should not be used widely until it is implemented 
    properly (see notes in implementation) and has more generic input.'''
    poseobj = poseutil.Pose3D()
    # TODO this is only valid for small poses should do it properly by using
    # random rotations from transformations.py
    dx = 0.1
    dq = np.radians(1)
    bestoverlap = 0
    while True:
        #start = time.time()
        delta = np.hstack((np.random.normal(0, dx, 3), np.random.normal(0, dq, 3)))
        poseobj.set(guesspose + delta)
        overlap = occupiedlist.calccollisions(poseobj.getTuple(), mapset, res, Pall)
        if overlap > bestoverlap:
            bestoverlap = overlap
            # TODO now search around new pose and refine? alternatively just do this randomly
            print bestoverlap, ', ', poseobj
        #taken = time.time() - start
        #rate = 1/taken
        #print rate, 'Hz' # rate is around 50Hz
        

class testAlignSegment(unittest.TestCase):
    '''
    Class to test point cloud alignment and the segmentation functionality.
    nominally based on a given point cloud (P) representing the existing 
    map and a set of scan query points (Q).
    
    The voxel based tests (mapvoxels and mrol) can use a pre-processed file of
    voxels instead of P and Q if desired.

    The alignment method is based on a given cost function
    and uses optimization based techniques to minimise the alignment
    error.

    Alignment functions to test all should start with align_X, where X is one of:
    align_simple: functions take an initial guess pose, a given point cloud (P),
    a set of scan query points (Q) and return the aligned pose'''
    
    def setUp(self):
        self.datadir = 'data/stillscans/'
        self.Pall, self.Q, self.guesspose, self.res = generate_tst_data_from_file(self.datadir + 'empty-map.txt', self.datadir + '1271124950-scan.txt', self.datadir + '1271124950-pose.txt')
        # override guess pose to make it harder for the algorithms
        self.guesspose = np.array([-2, 42, 80, 0.2, 0.1, 2.58])
        # sampling
        self.P = util.volumetricsample(self.Pall, self.res) # shuffles P as well
        # setup the mrol for the alignment
        self.mapmrol = mrol.MROL(self.res, levels=5)
        self.mapmrol.addpoints(self.Q)
        # setup the occupiedlist for the segmentation
        mv = occupiedlist.pointstovoxels(self.Q, self.res)
        self.mapvoxels = {} 
        occupiedlist.increment(self.mapvoxels, mv)
        # setup a dilated occupiedlist for segmentation
        self.dilated = {} 
        mv = occupiedlist.dilate(self.mapmrol.getvoxels().keys())
        occupiedlist.increment(self.dilated, mv)
        # setup a mapset for fast alignment
        self.mapset = set(occupiedlist.hashrows(self.mapvoxels.keys()))
        # Ground truths and tolerances
        self.lin_tol = 1e-1
        self.ang_tol = np.deg2rad(2.0)
        self.truepose = np.array([-1.8572, 41.7913, 79.3341, np.deg2rad(12.4607), np.deg2rad(4.3733), np.deg2rad(147.2011)]) # Overlap: 6094, Pose (m, degrees): -1.8572 41.7913 79.3341 12.4607 4.3733 147.2011 
        self.truePoints = poseutil.transformPoints(self.Pall, poseutil.mat(self.truepose))
        # list the aligners to be tested
        self.aligners = [ 
                          self.align_mrol_optimize_00001,
                          self.align_mrol_optimize_11111,
                        ]     
        # list the segmenters to be tested
        self.segmenters = [ self.segment_ovl,
                            self.segment_ovl_dilated
                          ]
            
    def testAlignmentMethods(self):
        print "Test Alignment Methods"
        for method in self.aligners:
            aligner_name = method.__name__.replace('_', ' ')
            aligner_name = aligner_name.replace('align ', '')
            print 5*'-', aligner_name, 5*'-'
            # Execute the aligner and time it
            start_align = time.time()
            bestpose = method()[0]
            taken_align = time.time() - start_align
            overlap = occupiedlist.calccollisions(bestpose, self.mapset, self.res, self.Pall)
            # check accuracy and timeliness
            pose_error = np.fabs(bestpose - self.truepose)
            print pose_error, overlap, taken_align
            if not np.alltrue(pose_error < [self.lin_tol, self.lin_tol, self.lin_tol, self.ang_tol, self.ang_tol, self.ang_tol]):
                print pose_error[0], pose_error[1], pose_error[2], np.rad2deg(pose_error[3]), np.rad2deg(pose_error[4]), np.rad2deg(pose_error[5])
                self.assertTrue(pose_error[0] < self.lin_tol)
                self.assertTrue(pose_error[1] < self.lin_tol)
                self.assertTrue(pose_error[2] < self.lin_tol)
                self.assertTrue(pose_error[3] < self.ang_tol)
                self.assertTrue(pose_error[4] < self.ang_tol)
                self.assertTrue(pose_error[5] < self.ang_tol)
            
            # Pass/Fail metrics are specific to this dataset!
            #self.assertTrue(maxo>3700) #6070? 
            #self.assertTrue(taken_align < 0.25) 
        print "truepose overlap =", occupiedlist.calccollisions(self.truepose, self.mapset, self.res, self.Pall)
        
    def DISABLEtestProfile(self):
        for method in self.aligners:
            aligner_name = method.__name__.replace('_', ' ')
            aligner_name = aligner_name.replace('align ', '')
            fname = aligner_name+'.profile' 
            command = 'method()'
            cProfile.runctx( command, globals(), locals(), filename=fname)
        print '''
        RunSnake is a good program to view the profile results, see
        http://www.vrplumber.com/programming/runsnakerun/

        To install under ubuntu do

        sudo apt-get install python-setuptools python-profiler
        sudo easy_install RunSnakeRun

        Then run the viewer with
        '''
        print 'runsnake', fname
        
    def testSegmentationMethods(self):
        print "Test Segmentation Methods"
        # Test the segmentation independantly of the aligment using the "true" pose
        # report the confusion matrix or summary statustic (false alarm rate, etc?)
        temp_outliers = util.get_scan_points_from_file(os.path.join(self.datadir, '1271124950-new.txt'))
        dists = pointcloud.nearest_neighbour(self.Pall,temp_outliers)
        outliers_inds2 = dists < 0.01
        temp_inliers = self.Pall[np.logical_not(outliers_inds2)]
        self.assertTrue((temp_outliers.shape[0] + temp_inliers.shape[0]) == self.Pall.shape[0])
        self.trueoutliers = poseutil.transformPoints(temp_outliers, poseutil.mat(self.truepose))
        self.trueinliers = poseutil.transformPoints(temp_inliers, poseutil.mat(self.truepose))
        for method in self.segmenters:
            seg_name = method.__name__.replace('_', ' ')
            seg_name = seg_name.replace('segment ', '')
            print 5*'-', seg_name, 5*'-'
            # Execute the segmentation algorithm and time it
            start_seg = time.time()
            inliers,outliers = method(self.truePoints)
            taken_seg = time.time() - start_seg
            # check accuracy and timeliness
            true_pos, true_neg, false_neg, false_pos = util.segmentation_stats(inliers, outliers, self.trueinliers, self.trueoutliers)
            self.assertTrue(sum(true_pos) > 0)
            self.assertTrue(sum(true_neg) > 0)
            print sum(true_pos), sum(false_pos)
            print sum(false_neg), sum(true_neg)
            FPR, MDR, accuracy, specificity = util.segmentation_summary(true_pos, true_neg, false_neg, false_pos, self.trueoutliers.shape[0], self.Pall.shape[0])
            print "False +ve rate: ", FPR
            self.assertTrue(FPR < 0.05)
            print "Missed detection rate: ", MDR
            self.assertTrue(MDR < 0.15)
            print "accuracy: ", accuracy
            self.assertTrue(accuracy > 0.9)
            print "specifity: ", specificity
            self.assertTrue(specificity > 0.9)
            
                        
            
    
    def DISABLEtest___PoseSearch(self):
        print "Pose Search"
        randomsearch(self.mapset,self.res,self.Pall,self.truepose)

    '''alignment functions in the meta classes'''
    # removed the ANN objective function tests as the method wasn't very good.
    def align_mrol_optimize_11111(self):
        return self.mapmrol.optimise_alignment(self.P, self.guesspose, objective_func=self.mapmrol.objectivefuncMROL, weights=[1, 1, 1, 1, 1])
    def align_mrol_optimize_00001(self):
        return self.mapmrol.optimise_alignment(self.P, self.guesspose, objective_func=self.mapmrol.objectivefuncMROL, weights=[0, 0, 0, 0, 1])
    '''End of alignment functions to test'''
    
    '''segmentation functionality/functions'''
    # TODO these ovl segmentation methods should be implemented in the meta class as a function.
    def segment_ovl(self, P_pose_adjusted):
        return occupiedlist.segment_ovl(None, self.mapvoxels, self.res, P_pose_adjusted)
    def segment_ovl_dilated(self, P_pose_adjusted):
        return occupiedlist.segment_ovl(None, self.dilated, self.res, P_pose_adjusted)

    
if __name__ == '__main__':
    global profile
    if '-h' in sys.argv:
        print __doc__
        sys.exit()
    
    unittest.main()
    
    
    
    
