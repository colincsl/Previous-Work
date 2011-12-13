import sys
import numpy as np

import mrol_mapping.mapper as mapper
import mrol_mapping.poseutil as poseutil
import mrol_mapping.occupiedlist as occupiedlist
import mrol_mapping.pointcloud as pointcloud
import mrol_mapping.visualiser.robotvisualiser as robotvisualiser
import iros_mapper
import os

#fname =  '/jcr/data3d/lamp/present/0002.png'
try:
    datadir = sys.argv[1]
    fnames = os.listdir(datadir)
    fnames.sort()
    fnames = [datadir + '/' + fname for fname in fnames if fname.endswith('.png')]
except:
    print 'Need to specify a valid directory for input'
    sys.exit()
visualise = True
freespace2 = False#True # overall, True should be more-accurate, but initial setup will be slower
if visualise:
    vis = robotvisualiser.Visualiser()
    vis.set_orthographic(Bool=True)
absent_map = mapper.loadmap('absent.map')
res = absent_map.get_resolution()
if freespace2:
    freespace_ol = absent_map.generate_freespace2(resolution = res)
else:
    freespace_ol = absent_map.generate_freespace(res) # *4 for speed during testing, should just be res



#present_map = mapper.loadmap('present.map')
#pc = present_map.get_points()

#pc = iros_mapper.get_pointcloud(fname)
#bestpose = poseutil.Pose3D()
#bestpose.x = 0.8
#bestpose.y = 1
#bestpose.rotz = np.radians(-60)
#bestpose, overlap = absent_map.align_points(pc, bestpose)

#absent_map.add_points(pc, bestpose)

#present_ol = occupiedlist.OccupiedList(absent_map.get_resolution())
#present_ol.addpoints(pc.points, bestpose)
#
#ol = present_ol - absent_map.mrol.getfinest() 
#sensor_model = mapper._build_sensor_model(0.1)
#
#SM_points = sensor_model.getpoints()
#inds = ol.calccollisions(bestpose, SM_points, query=True)
#inds = np.array(inds)
#hits = pointcloud.PointCloud(SM_points[inds > 0])
#
#
#import pydb; pydb.set_trace()
#print ol
#absent_map.display()



segment_map = absent_map
bestpose = poseutil.Pose3D(X=(0.5,-0.5,0,0,0,np.pi/4))
for fname in fnames:
    pc = iros_mapper.get_pointcloud(fname)
    print fname,
    bestpose = segment_map.align_points(pc, bestpose)[0]
    print bestpose
    hits, new_points  = segment_map.mrol.getfinest().segment_ovl(bestpose,pc.points)
    inliers, outliers = freespace_ol.segment_ovl(None, new_points)
    segment_map.add_points(pointcloud.PointCloud(outliers), None)
    if freespace2:
        if len(inliers) > 0:
            tmp_freespace_ol = segment_map.generate_freespace2(inliers,pose=bestpose)
        else:
            # nothing to segment?
            import pdb;pdb.set_trace()
            tmp_freespace_ol = occupiedlist.OccupiedList(1)
    else:
        tmp_freespace_ol = segment_map.generate_freespace(res,pose=bestpose)
    
    freespace_ol.addpoints(tmp_freespace_ol.getpoints(), None)
    if visualise:
        print "Visualising"
        vis.clear()
        vis.addmappts(segment_map.get_points().points)
        vis.setrobotpose(bestpose.getMatrix())
        vis.addtrajectorypoint(bestpose.getTuple()[0:3])
        if len(inliers) > 0:
            vis.setrightpts(outliers) # new map points
            vis.setleftpts(inliers) # segmented points
        #    pointcloud.save(fname+"_seg",inliers)
        #    np.savetxt(fname+"_pose",bestpose)
        import pdb;pdb.set_trace()
segment_map.save("segment_map.map")
