
import sys
import numpy as np

import mrol_mapping.mapper as mapper
import mrol_mapping.mrol as mrol
import mrol_mapping.poseutil as poseutil
import mrol_mapping.pointcloud as pointcloud
import time

import pdb

res = .002
n_levels = 4

if len(sys.argv) > 1:
	input_file = sys.argv[1]
else:
	input_file = '/home/colin/repo/perception_repo/data/obj16_best.npy'
	
	
vmap = mapper.VoxelMap(res, levels = n_levels)
#vmap.display(npts=4e5)
	

input_pc = np.load(input_file)

pc = pointcloud.PointCloud(input_pc)
vmap.add_points(pc, poseutil.Pose3D())

point1 = np.array([-.2, 0, 0])
point2 = np.array([0,0,0])

tmp = vmap.ray_trace_pts(point1, point2, return_extras=False)

pdb.set_trace()
