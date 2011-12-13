import sys
import numpy as np

import mrol_mapping.mapper as mapper
import mrol_mapping.poseutil as poseutil
import mrol_mapping.occupiedlist as occupiedlist
import mrol_mapping.pointcloud as pointcloud
import mrol_mapping.visualiser.robotvisualiser as robotvisualiser
import mrol_mapping.quantizer as quantizer
import os

sys.path.append('../test')
import iros_mapper


import signal
def signal_handler(signal, frame):
    import pdb; pdb.set_trace()
signal.signal(signal.SIGINT, signal_handler)

#fname =  '/jcr/data3d/lamp/present/0002.png'
load_pc = True# for loading point clouds from the Kinect from npy files
try:
    datadir = sys.argv[1]
    fnames = os.listdir(datadir)
    fnames.sort()
    if load_pc:
        fnames = [datadir + '/' + fname for fname in fnames if fname.startswith('mrolpc')]
    else:
        fnames = [datadir + '/' + fname for fname in fnames if fname.endswith('.png')]
except:
    print 'Need to specify a valid directory for input'
    sys.exit()
visualise = True
long_term = False

   
bestpose = poseutil.Pose3D(X=(0,0,0,0,0,0))
pc_xform = poseutil.Pose3D(X=(0,0,0,-np.pi/2.,0,-np.pi/2.))
res = 0.01
segment_map = mapper.VoxelMap(res,levels=3)
pc = pointcloud.load(fnames.pop(0))
#pc = pointcloud.PointCloud(pc)
pc = pointcloud.PointCloud(pc_xform.transformPoints(pc))
segment_map.add_points(pc, bestpose)
object_map = mapper.VoxelMap(res/4.,levels=1)


#freespace_ol = segment_map.generate_freespace2(resolution = res*2, minR=0.4, maxR=3)
#freespace_ol = segment_map.generate_freespace(res, minR=0.25, maxR=0.75) # *4 for speed during testing, should just be res

free_space_res = res

pc_vox = occupiedlist.pointstovoxels(pc.points, free_space_res)
pc_vox = quantizer.uniquerows(pc_vox, 0)
pc_pts = occupiedlist.voxelstopoints(pc_vox, free_space_res)
pc_regular = pointcloud.PointCloud(pc_pts)
freespace = segment_map.free_space_ray_trace(pc_regular,(0,0,0),free_space_res,voxel_offset=2.5)
freespace_ol = occupiedlist.OccupiedList(free_space_res)
freespace_ol.addpoints(freespace.points)

#import pdb;pdb.set_trace()
#vis = robotvisualiser.Visualiser(npts=2e6)
#vis.addmappts(segment_map.get_points().points)
#vis.addmappts(freespace_ol.getpoints())
#free_pc = pointcloud.PointCloud(freespace_ol.getpoints())
#free_pc.display()



if visualise:
    vis = robotvisualiser.Visualiser(npts=2e6)
    vis.set_orthographic(Bool=True)
    vis.setminmax(-1.5,1.5)
    #objvis = robotvisualiser.Visualiser()
    #objvis.set_orthographic(Bool=True)
    #objvis.setminmax(-1.5,1.5)

pc_xform = poseutil.Pose3D(X=(0,0,0,-np.pi/2.,0,-np.pi/2.))
count = 0
for fname in fnames:
    if load_pc:
        pc = pointcloud.load(fname)
        pc = pointcloud.PointCloud(pc_xform.transformPoints(pc))
    else:
        pc = get_pointcloud(fname)
    print fname,
    bestpose = segment_map.align_points(pc, bestpose)[0]
    print bestpose
    hits, new_points  = segment_map.mrol.getfinest().segment_ovl(bestpose,pc.points)
    if long_term:
        # if we wanted a long-term map without dynamic object coruption 
        inliers, outliers = freespace_ol.segment_ovl(None, new_points)
        object_map.add_points(pointcloud.PointCloud(inliers), None)
        segment_map.add_points(pointcloud.PointCloud(outliers), None)
         #if freespace2:
        #    if len(inliers) > 0:
        #        tmp_freespace_ol = segment_map.generate_freespace2(inliers,pose=bestpose)
        #    else:
        #        # nothing to segment?
        #        import pdb;pdb.set_trace()
        #        tmp_freespace_ol = occupiedlist.OccupiedList(1)
        #else:
        #    tmp_freespace_ol = segment_map.generate_freespace(res,pose=bestpose)
        #
        #freespace_ol.addpoints(tmp_freespace_ol.getpoints(), None)
    else:
        # if we are just trying to segment out the cup to make a model, and it's not moving.
        inliers, outliers = freespace_ol.segment_ovl(bestpose,pc.points)
        #TODO only add points if overlap is good?
        if count == 0:
            object_map.add_points(pointcloud.PointCloud(inliers), None)
            segment_map.add_points(pointcloud.PointCloud(new_points), None)
        else:
            if len(inliers)/len(object_map) > 0.5:
                object_map.add_points(pointcloud.PointCloud(inliers), None)
                segment_map.add_points(pointcloud.PointCloud(new_points), None)
            else: 
                print "Not adding to map"

    if visualise:
        print "Visualising"
        vis.clear()
        vis.addmappts(segment_map.get_points().points)
        vis.setrobotpose(bestpose.getMatrix())
        vis.addtrajectorypoint(bestpose.getTuple()[0:3])
        if long_term:
            if len(outliers) > 0:
                vis.setrightpts(outliers) # new map points
        else:
            vis.setrightpts(new_points)
        if len(inliers) > 0:
            vis.setleftpts(inliers) # segmented points
            #pointcloud.save(fname+"_seg",inliers)
            #np.save(fname+"_pose",np.asarray(bestpose.getTuple()))
        
        #objvis.clear()
        #objvis.addmappts(object_map.get_points().points)
        #free_pc = pointcloud.PointCloud(freespace_ol.getpoints())
        #P = free_pc.display()
        #import pdb;pdb.set_trace()
    count +=1
import pdb;pdb.set_trace()
segment_map.save("segment_map.map")
object_map.save("object_map.map")
