#!/usr/bin/env python

import sys, os

import mrol_mapping.mapper as mapper
import numpy as np
import mrol_mapping.mrol as mrol
import mrol_mapping.poseutil as poseutil
import mrol_mapping.pointcloud as pointcloud
import time
import read_groundtruth as truth

import pdb

scale = 1 #small pointclouds aren't visualized well
n_levels = 4
bb_xmin = -.12
bb_xmax = .12
bb_ymin = -.12#5
bb_ymax = .12
bb_zmin = -0.012#-.05
bb_zmax = .30

#bb_xmin = -.25
#bb_xmax = .25
#bb_ymin = -.5#5
#bb_ymax = .5
#bb_zmin = -0.015#-.05
#bb_zmax = .30

res = 0.002#.04
add_transThresh = .03 # in meters
add_rotThresh   = 5.0 # in degrees
#basedir = '/home/colin/sip_data/training_new/pointclouds_object_24'
basedir = '/home/colin/sip_data/training_new/pointclouds_obj16'
save_file = '/home/colin/repo/perception_repo/data/tmp_g1.txt'



# Vertical is y

#def testPose(x):
#	x_ = np.array([x[0],x[1],x[2],0,0,x[4]])
##	x_ = np.array([x[0],x[1],x[2],x[3],x[4],x[5]])
#	return x_

#def transformPC(pc, T):
##	pdb.set_trace()
#	T = np.matrix(T)
#	pc
#	out = np.zeros(pc.shape)
#	for i in range(pc.shape[0]):
#		if not any(np.isnan(pc[i,:])):
##			pdb.set_trace()
#			vec = np.array([pc[i,0], pc[i,1], pc[i,2], 1])
#			out[i,:] = (T * np.matrix(vec).T)[:3].T
#		else:
#			out[i,:] = np.NaN

#	print 'Done T'
''' Get all pointcloud filenames '''

dirs = os.walk(basedir)

root = []
folders = []
files = []
good_file_reg = []
good_file_pc = []
good_file_reg_all = []

for i in dirs:
	root.append(i[0])
	folders.append(i[1])
	files.append(i[2])

for i in range(len(root)):
#			for j in range(len(folders)):
	if root[i].find("pointclouds_"):
		for j in range(len(files[i])):
			if files[i][j].find(".npy")>-1 and files[i][j].find('reg_')>-1:
				good_file_reg.append(root[i]+'/'+files[i][j])			
			elif files[i][j].find(".npy")>-1 and files[i][j].find('pc_')>-1:
				good_file_pc.append(root[i]+'/'+files[i][j])
			elif files[i][j].find(".npz")>-1 and files[i][j].find('reg_')>-1:
				good_file_reg_all.append(root[i]+'/'+files[i][j])			

good_file_reg.sort()
good_file_reg_all.sort()
good_file_pc.sort()
file_count = len(good_file_pc)


pose_list = []
truth_T = truth.getTransformations()


for i in range(truth_T.shape[2]):
	P =  poseutil.Pose3D()
	P.setMatrix(truth_T[:,:,i])	
#	pose_list.append(np.array([0,0,0,0,0,0]))
	pose_list.append(P)


#Set centroid to zero
#for i in range(file_count):
#	pose_list.append(np.load(good_file_reg_all[i])['pose'])
#	
#centroid = np.mean(pose_list, axis=0)
#pose_list = np.array(pose_list)

#pose_list[:,0] -= centroid[0]
#pose_list[:,1] -= centroid[1]
#pose_list[:,2] -= centroid[2]

''' '''


'''Setup'''

P =  poseutil.Pose3D()
#Pose is a 3x4 transformation matrix
#mat = np.asarray( ((1,0,0,0),\
#                   (0,1,0,0),\
#                   (0,0,1,0)) )
#P.setMatrix(mat)



point_clouds = {}
PCs = []
vmap = mapper.VoxelMap(res, levels = n_levels)


vmap.display(npts=4e5)


'''Match -- original test data'''
if 0:

	cloud1 = np.load(good_file_pc[0]) #use good_file_reg
	xyzs = np.array((cloud1['x']*scale, cloud1['y']*scale, cloud1['z']*scale)).T
	pc = pointcloud.PointCloud(xyzs)
	#pc.boxfilter(xmin=bb_xmin, xmax=bb_xmax,ymin=bb_ymin, ymax=bb_ymax,zmin=bb_zmin, zmax=bb_zmax)
	pose = pose_list[0]#np.load(good_file_reg_all[0])['pose']
	pc.set(pose)
	PCs.append(pc)
	vmap.add_points(PCs[0], PCs[0].pose)
	


	guessPose = PCs[0].pose
	
	cloud2 = np.load(good_file_reg[1])	
	xyzs = np.array((cloud2['x'], cloud2['y'], cloud2['z'])).T
	pc = pointcloud.PointCloud(xyzs)
	
	start = time.time()
	bestpose, maxcost = vmap.align_points(pc, guessPose)
	taken = time.time() - start
	print 'Scanmatch time:', taken, 'seconds'
	print "Pose: ", bestpose
	print "Max cost: ", maxcost


#	PCs[0].display(color=(1,0,0))

	#check_localise(bestpose, truepose)


'''Create 3D model using MROL align -- NIST data'''
start = time.time()
if 1:
	PCs_added = 0
	if file_count > 1:
		for j in range(0,file_count, 1):
			print 'File %i of %i' %(j, file_count)
			data = np.load(good_file_pc[j]) #should be good_file_reg
			xyzs = np.array((data['x']*scale, data['y']*scale, data['z']*scale)).T

			pose = pose_list[j]#np.load(good_file_reg_all[j])['pose']
			pose_zero = poseutil.Pose3D()
			pose_zero.set((0,0,0,0,0,0))

			xyzs = poseutil.transformPoints(xyzs, pose.getMatrix())
			pc = pointcloud.PointCloud(xyzs)
			pc.pose = pose_zero#pose
#			pdb.set_trace()
			pc.boxfilter(xmin=bb_xmin, xmax=bb_xmax,ymin=bb_ymin, ymax=bb_ymax,zmin=bb_zmin, zmax=bb_zmax)
#			print pose


			if j==0: #Don't try to align first pose
				vmap.add_points(pc, pc.pose)
			else:
				guessPose = pose_zero#pose_list[i]#np.load(good_file_reg_all[i])['pose']
				bestPose = guessPose
				
#				print guessPose
				bestPose, maxcost = vmap.align_points(pc, guessPose)
#				bestPose, maxcost = vmap.align_points(pc, guessPose, True) #only 2D alignment
				disp = np.array(bestPose.getTuple())
				if all(np.abs(disp[:3]) < add_transThresh) and all(np.abs(disp[3:])<add_rotThresh*3.14/180.):
					vmap.add_points(pc, bestPose)
					PCs_added +=1
					print '%i PCs added'%PCs_added
				print "Best Pose: ", bestPose		
#				pdb.set_trace()					
#				guessPose = bestpose
#				print "Pose from ground: ", guessPose	
#			pdb.set_trace()
	print '%i of %i point clouds were added' %(PCs_added, file_count)

#	cloud1 = np.load(good_file_pc[0]) #use good_file_reg
#	xyzs = np.array((cloud1['x']*scale, cloud1['y']*scale, cloud1['z']*scale)).T
#	pc = pointcloud.PointCloud(xyzs)
#	#pc.boxfilter(xmin=bb_xmin, xmax=bb_xmax,ymin=bb_ymin, ymax=bb_ymax,zmin=bb_zmin, zmax=bb_zmax)
#	pose = pose_list[0]#np.load(good_file_reg_all[0])['pose']
#	pc.set(pose)
#	PCs.append(pc)
#	vmap.add_points(PCs[0], PCs[0].pose)


#	if file_count > 1:
#		for j in range(1,file_count):
#			data = np.load(good_file_pc[j]) #should be good_file_reg
#			xyzs = np.array((data['x']*scale, data['y']*scale, data['z']*scale)).T					
#			pc = pointcloud.PointCloud(xyzs)
#			pc.pose = pose_list[j]#np.load(good_file_reg_all[j])['pose']			
#			pc.boxfilter(xmin=bb_xmin, xmax=bb_xmax,ymin=bb_ymin, ymax=bb_ymax,zmin=bb_zmin, zmax=bb_zmax)
##			print pc.pose
#			PCs.append(pc)

#	pdb.set_trace()
	start = time.time()
	
#	for i in range(1,len(PCs)):
#		print 'Aligning scan', i
#		#Pose+pointcloud:
#		#Use ground truth pose as-is
#		guessPose = pose_list[i]#np.load(good_file_reg_all[i])['pose']
#		xyzs = PCs[i]
#		
#		bestpose, maxcost = vmap.align_points(xyzs, guessPose)
#		vmap.add_points(xyzs, bestpose)
#		guessPose = bestpose
#		print "Pose from ground: ", guessPose	
#		print "Best Pose: ", guessPose			

	taken = time.time() - start
	print 'Mapbuild time:', taken, 'seconds'



#from enthought.mayavi.mlab import *
'''Merge NIST dataset using the ground truth pose (no MROL)'''
if 0:
	if file_count > 1:
		for j in range(file_count):
			data = np.load(good_file_pc[j]) #should be good_file_reg
			xyzs = np.array((data['x']*scale, data['y']*scale, data['z']*scale)).T

			pose = pose_list[j]#np.load(good_file_reg_all[j])['pose']
			pose_zero = poseutil.Pose3D()
			pose_zero.set((0,0,0,0,0,0))

			xyzs = poseutil.transformPoints(xyzs, pose.getMatrix())
			pc = pointcloud.PointCloud(xyzs)
			pc.pose = pose_zero#pose
			
			pc.boxfilter(xmin=bb_xmin, xmax=bb_xmax,ymin=bb_ymin, ymax=bb_ymax,zmin=bb_zmin, zmax=bb_zmax)
			print pose
			
			vmap.add_points(pc, pc.pose)



'''Test localization of outputted model with original scene'''
if 0:
	cloud1 = np.load(good_file_pc[0]) #use good_file_reg
	xyzs = np.array((cloud1['x']*scale, cloud1['y']*scale, cloud1['z']*scale)).T
	pc = pointcloud.PointCloud(xyzs)
	pc.boxfilter(xmin=bb_xmin, xmax=bb_xmax,ymin=bb_ymin, ymax=bb_ymax,zmin=bb_zmin, zmax=bb_zmax)
	pose = pose_list[0]#(0,0,0,0,0,0)#
#	pc.pose = pose
	PCs.append(pc)

	vmap.add_points(PCs[0], PCs[0].pose)

	''' Import object '''
	data = np.load('data/merged_PC_aligned.npy')
	xyzs = np.array((data[:,0], data[:,1], data[:,2])).T
	centroid = np.mean(xyzs, axis=0)
	xyzs[:,0] -= centroid[0]
	xyzs[:,1] -= centroid[1]
	xyzs[:,2] -= centroid[2]
	
#	pose = (0,0,0,0,0,0)#pose_list[0]
	centroid_vmap = np.mean(vmap.get_points().points, axis=0)
	guessPose = (centroid_vmap[0], centroid_vmap[1], centroid_vmap[2], 0, 0, 0) #(0,0,0,0,0,0)#pose_list[0]#(0,0,0,0,0,0)
#	xyzs = np.array((data['x'], data['y'], data['z'])).T
	pc = pointcloud.PointCloud(xyzs)
	
	bestpose, maxcost = vmap.align_points(pc, guessPose)
	pdb.set_trace()
	vmap.add_points(pc, bestpose)
	print "GuessPose: ", guessPose
	print "BestPose: ", bestpose
	print "Max cost: ", maxcost

print 'Complete'

if 1:
	data = vmap.get_points()
	rad = .1
	data.boxfilter(xmin=-rad, xmax=rad,ymin=-rad, ymax=rad,zmin=-.1, zmax=bb_zmax)
	data.display()

pdb.set_trace()
#data = vmap.get_points().points
#np.save('merged_PC_aligned', data)
data_p = data.points
save_file = '/home/colin/repo/perception_repo/data/tmp.txt'
f = file(save_file, 'w')
for i in range(data_p.shape[0]):
    f.write("%f %f %f\n" % (float(data_p[i,0]), float(data_p[i,1]), float(data_p[i,2])))
    print i




        
