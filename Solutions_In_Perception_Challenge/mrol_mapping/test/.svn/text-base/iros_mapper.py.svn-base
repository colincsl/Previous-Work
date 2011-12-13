'''File to build map from a directory of depth images and save to file'''
from __future__ import division
import mrol_mapping.poseutil as poseutil
import mrol_mapping.mapper as mapper
import mrol_mapping.pointcloud as pointcloud
import mrol_mapping.util as util
import depth_image

import mrol_mapping.occupiedlist as occupiedlist
import mrol_mapping.quantizer as quantizer

import os
import numpy as np
import sys

res = 0.04
visualise = True
make_free = False

def get_pointcloud(fname):
    xyzs = depth_image.image_to_points(fname)
    pc = pointcloud.PointCloud(xyzs)
    # remove ceiling and floor
    pc.boxfilter(zmin=-15, zmax=0.5)
    return pc
    
def get_freespace(xyzs, pose, voxelmap):
    # TODO consider using mapper._build_sensor_model() and mapper.generate_freespace() instead.
    # resampling to align with grid. bad hack, but makes ray_cast easier.
    res = voxelmap.get_resolution()
    xyzs = poseutil.transformpoints(xyzs,pose)
    voxs = occupiedlist.pointstovoxels(xyzs, res)
    voxs = quantizer.uniquerows(voxs, 0)
    X = occupiedlist.voxelstopoints(voxs, res)
    free_pts = voxelmap.free_space_ray_trace(X,pose[:3])
    return free_pts
        
    

if __name__ == '__main__':
    try:
        datadir = sys.argv[1]
        outfname = sys.argv[2]+".map"
        fnames = os.listdir(datadir)
        fnames.sort()
        fnames = [datadir + '/' + fname for fname in fnames if fname.endswith('.png')]
    except:
        print 'Need to specify a valid directory for input and file name for output'
        sys.exit()

    # variable initialisation
    iros_map = mapper.VoxelMap(res,levels=5)
    iros_free_map = mapper.VoxelMap(res,levels=1)
    bestpose = poseutil.Pose3D()
    pc = get_pointcloud(fnames.pop(0))
    iros_map.add_points(pc, bestpose)
    if visualise:
        iros_map.display(changes=True)
    if make_free:
        freepts = get_freespace(pc.points, bestpose, iros_map)
        pcfree = pointcloud.PointCloud(freepts)
        iros_free_map.add_points(pcfree,None)
        if visualise:
            iros_free_map.display(npts=1000000)

    for fname in fnames:
        print fname, 
        pc = get_pointcloud(fname)
        bestpose = iros_map.align_points(pc, bestpose)[0]
        iros_map.add_points(pc, bestpose)
        if make_free:
            freepts = get_freespace(pc.points, bestpose, iros_map)
            pcfree = pointcloud.PointCloud(freepts)
            iros_free_map.add_points(pcfree,None)
        print bestpose

    iros_map.save(outfname)
    if make_free:
        iros_free_map.save(outfname+"free")
    print 'Map saved to', outfname
