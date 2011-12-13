'''
Author: Julian Ryde
'''
from __future__ import division

import time
import numpy as np

import mrol_mapping.mapper as mapper
import mrol_mapping.poseutil as poseutil
import mrol_mapping.mrol as mrol 
import mrol_mapping.occupiedlist as occupiedlist
import mrol_mapping.pointcloud as pointcloud

import depth_image
import unittest

visualise = True

basedir = 'data/simulated/'

def load_poses(fname):
    # skip comment lines
    poses = {}
    P =  poseutil.Pose3D()
    for line in open(fname):
        if line.strip().startswith('#'):
            continue
        fields = line.split(None, 1)
        fname = fields[0]
        mat = np.asarray(eval(fields[1]))

        P = poseutil.Pose3D()
        # need to transpose from blender?
        P.setMatrix(mat.T)
        poses[fname] = P
    return poses

true_poses = load_poses(basedir + 'poses.txt')

def get_PC(i):
    '''Loads the i-th point cloud from test data and attach the true pose to 
    it'''
    fname = str(i).rjust(4, '0') + '.png'
    di = depth_image.load_image(basedir + fname)
    pc = depth_image.image_to_points(di, max_range=di.max())
    #pc = pointcloud.PointCloud(xyzs)
    # remove ceiling and floor
    # this could be done automatically with RANSAC
    # large horizontal plane cause problems when contraining pose in 
    # horizontal plane?
    # in noisy outdoor environments this is less of a problem?
    pc.boxfilter(zmin=-1.5, zmax=0.5)

    # Attach ground truth pose to the pointcloud
    try:
        pc.pose = true_poses[fname]
    except KeyError as ke:
        print ke
    return pc, di
    
# TODO add benchmark test

class Testposeutil(unittest.TestCase):

    def setUp(self):
        #np.random.seed(6)
        self.res = 0.04

        self.vmap = mapper.VoxelMap(self.res, levels=3)
        pc = get_PC(0)[0]
        self.vmap.add_points(pc, pc.pose)

    def check_localise(self, bestpose, truepose):
        #print 'Best:', bestpose
        #print 'True:', truepose
        poseerror = truepose.getCombined(bestpose.inverse())
        print 'Pose error:', poseerror
        pos_error = np.sum(np.abs(poseerror.get()[:3]))
        ang_error = np.sum(np.abs(poseerror.get()[3:]))
        print '\nPosition error (m):', pos_error
        print 'Angular error (degs):', np.degrees(ang_error) 

        position_tol = 0.04 # total position error tolerance
        angular_tol = np.radians(0.55)
        #self.assertTrue(pos_error < position_tol)
        #self.assertTrue(ang_error < angular_tol)
        #self.assertTrue(bestpose.is_close(truepose, position_tol, angular_tol))

    def test_Ascanmatch_6DOF(self): 
        # "A" prepended to run this first cos it is quick
        print "test_scanmatch_6DOF"
        vmap = self.vmap
        guessPose = get_PC(0)[0].pose
        pc1 = get_PC(1)[0]
        truepose = pc1.pose
        start = time.time()
        bestpose, maxcost = vmap.align_points(pc1, guessPose)
        taken = time.time() - start
        print 'Scanmatch time:', taken, 'seconds'
        self.check_localise(bestpose, truepose)

    def test_Ymapbuild_6DOF(self): 
        # "Z" prepended to run this last cos it is slow
        print "test_mapbuild_6DOF"
        vmap = self.vmap
        guessPose = vmap.trajectory[0]
        #guessPose = get_PC(0)[0].pose
        if visualise:
            vmap.display()
        start = time.time()
        for i in range(1, 16):
            print 'Aligning scan', i
            pc, di = get_PC(i)
            bestpose, maxcost = vmap.align_points(pc, guessPose)
            #bestpose = pc.pose # use the true value
            print 'Bestpose:',bestpose
            vmap.add_points(pc, bestpose)
            self.check_localise(bestpose, pc.pose)
            guessPose = bestpose
        taken = time.time() - start
        print 'Mapbuild time:', taken, 'seconds'
        print 'Map size (voxels):', len(vmap)
        import pdb; pdb.set_trace()
        print 'Perfect map has 19812 voxels, press "c" to continue.'
        # TODO possibly interesting to calculate the ideal compression with the 
        # true poses, might be possible to get better than that?

    def OFFtest_Zmapbuild_6DOF_feature(self): 
        # "Z" prepended to run this last cos it is slow
        print "test_mapbuild_6DOF_feature"
        #vmap = self.vmap
        vmap = mapper.VoxelMap(self.res, levels=5)
        pc, di = get_PC(0)
        di_disconts = depth_image.depth_discont_sobel(di)
        pc_disconts = depth_image.image_to_points(di_disconts)
        vmap.add_points(pc_disconts, pc.pose)
        guessPose = vmap.trajectory[0]
        #guessPose = get_PC(0)[0].pose
        if visualise:
            import mrol_mapping.visualiser.robotvisualiser as robotvisualiser
            vmap.display()
            import pylab
            pylab.ion()
            pylab.imshow(di_disconts)
            pylab.draw()
            PC_vis = robotvisualiser.Visualiser(title='points')
            PC_vis.setautominmax()
            PC_vis.addmappts(pc_disconts.points)
            #import pdb;pdb.set_trace()
        start = time.time()
        for i in range(1, 16):
            print 'Aligning scan', i
            pc, di = get_PC(i)
            print "extracting feature set"
            di_disconts = depth_image.depth_discont_sobel(di)
            pc_disconts = depth_image.image_to_points(di_disconts)
            if visualise:
                pylab.imshow(di_disconts)
                pylab.draw()
                PC_vis.clear()
                PC_vis.addmappts(pc_disconts.points)
                #import pdb;pdb.set_trace()
            print "performing alignment"
            bestpose, maxcost = vmap.align_points(pc_disconts, guessPose, full_data=True)
            #bestpose = pc.pose # use the true value
            print 'Bestpose:',bestpose
            #vmap.add_points(pc, bestpose)
            vmap.add_points(pc_disconts, bestpose)
            self.check_localise(bestpose, pc.pose)
            guessPose = bestpose
            #import pdb;pdb.set_trace()
        taken = time.time() - start
        print 'Mapbuild time:', taken, 'seconds'
        print 'Map size (voxels):', len(vmap)
        import pdb; pdb.set_trace()
        print 'Perfect map has 19812 voxels, press "c" to continue.'
        # TODO possibly interesting to calculate the ideal compression with the 
        # true poses, might be possible to get better than that?


    def OFFtest_saveload(self): # turned off because I run out of RAM and have to start paging.
        print "test_saveload"
        # TODO use tempfile module?
        vmap = self.vmap
        fname = '/tmp/vmap.map'
        vmap.save(fname)
        loaded = mapper.loadmap(fname)
        # TODO assert equals needs __eq__ method on VoxelMap

    def OFFtest_mapper_global_localisation(self):
        dx = 0.5
        dq = np.radians(15)
        spread_pose = poseutil.Pose3D((dx, dx, 0, 0, 0, dq))
        res = 0.04
        map_mrol = mrol.MROL(res, levels=4)
        #map_mrol.set_feature_range(8)
        self.P1.volumetricsample(self.res+0.01111)
        self.P2.volumetricsample(0.08)
        map_mrol.addpoints(self.P1)

        pc1 = get_PC(1)[0]
        guesspose = pc1.pose
        bestpose, maxo = map_mrol.match(pc1, guesspose, spread_pose)
        truepose = self.P2.pose

        if visualise:
            self.P1.display(color=(1,0,0))
            self.P2.pose = bestpose
            self.P2.display(color=(0,1,0))

        print 'Best:', bestpose
        print 'True:', truepose
        poseerror = truepose.getCombined(bestpose.inverse())
        pos_error = np.sum(np.abs(poseerror.get()[:3]))
        ang_error = np.sum(np.abs(poseerror.get()[3:]))
        print
        print 'Total Position error (m):  ', pos_error
        print 'Total Angular error (degs):', np.degrees(ang_error) 

        angular_tol = np.radians(2)
        position_tol = 0.05
        self.assertTrue(bestpose.is_close(truepose, position_tol, angular_tol))
        
    def test_Amapper_raytrace(self): # "A" prepended to run this first cos it is quick
        print "test_Amapper_raytrace"
        res = 0.04
        vm = mapper.VoxelMap(res, levels=3)
        xyzs = np.zeros([4, 3])
        xyzs[:, 1] = np.cumsum(np.ones(4))*res
        xyzs[3, :] = [0.5, 0.5, 0.5] # this one isn't ray traced out
        pc = pointcloud.PointCloud(xyzs)
        vm.add_points(pc, None)
        pose = (0, 0, 0, 0, 0, np.pi/2.)
        ray_occs_pc = vm.ray_trace(pose, 50*res)
        self.assertEqual(ray_occs_pc, pointcloud.PointCloud(occupiedlist.pointstovoxels(xyzs[:3], res, vm.lattice)))
        ray_occs_pc = vm.ray_trace_pts(xyzs[0,:],xyzs[2,:])
        self.assertEqual(ray_occs_pc, pointcloud.PointCloud(occupiedlist.pointstovoxels(xyzs[:3], res, vm.lattice)))
        ray_occs_pc = vm.ray_trace_pts(np.array([0,0,0]),xyzs[3,:])
        self.assertEqual(ray_occs_pc, pointcloud.PointCloud(occupiedlist.pointstovoxels(xyzs[3,:], res, vm.lattice)))
        ray_occs_pc = vm.ray_trace_pts(xyzs[2,:],xyzs[0,:])
        self.assertEqual(ray_occs_pc, pointcloud.PointCloud(occupiedlist.pointstovoxels(xyzs[:3], res, vm.lattice)))
        # TODO ray check perpendicular to a plane
        
        # test the free-space tracing
        pc_555 = pointcloud.PointCloud(xyzs[3,:])
        free_555_pc = vm.free_space_ray_trace(pc_555,np.asarray([0,0,0]),resolution=res)
        xyzs_free_555 = np.array( [[ 0.  ,  0.  ,  0.  ],
                                   [ 0.04,  0.04,  0.04],
                                   [ 0.08,  0.08,  0.08],
                                   [ 0.12,  0.12,  0.12],
                                   [ 0.16,  0.16,  0.16],
                                   [ 0.2 ,  0.2 ,  0.2 ],
                                   [ 0.24,  0.24,  0.24],
                                   [ 0.28,  0.28,  0.28],
                                   [ 0.32,  0.32,  0.32],
                                   [ 0.36,  0.36,  0.36],
                                   [ 0.4 ,  0.4 ,  0.4 ],
                                   [ 0.44,  0.44,  0.44]] )
        expected_555_pc = pointcloud.PointCloud(xyzs_free_555)
        self.assertEqual(expected_555_pc, free_555_pc)
        
if __name__ == '__main__':
    unittest.main()
