
'''
Overview:
*input: Nx6 dense pointcloud
*use read_groundtruth() to get plane
	-transform 3 points to get plane...
	- set everything below and behind as NaN or black
*form image
*run SIFT on remaining pixels 

TODO: Why is the z value in 'accept_z' -.65. Shouldn't it be 0?

TODO: problem - can't load sift from another folder
Answer: load from that folder intead of using './sift'
'''

import sys, os
import numpy as np
from numpy.linalg import svd
#import scipy
import scipy.misc as sm
import pylab as pl
import sift

import mrol_mapping.mapper as mapper
import mrol_mapping.mrol as mrol
import mrol_mapping.poseutil as poseutil
import mrol_mapping.pointcloud as pointcloud

import read_groundtruth as truth

import time
import pdb



if len(sys.argv) > 1:
	input_file = sys.argv[1]
else:
	input_file = '/home/colin/sip_data/training_new/pointclouds_obj16/pc_1302023598.npy'
#	input_file = '/home/colin/sip_data/training_new/pointclouds_obj16/pc_1302023524.npy'	
#	input_file = '/home/colin/repo/perception_repo/data/obj16_best.npy'	
	
pc = np.load(input_file)
pc_range = np.array([pc['x'],pc['y'], pc['z']]) 
pc_color = np.array([pc['r'],pc['g'], pc['b']]) 

# 3 coords in local frame
plane_pts = np.matrix([[0,0,0,1], [.01,0,0,1], [0,.01,0,1]], dtype = np.float)
#plane_pts_o = np.matrix([[0,0,0,1], [1,0,0,1], [0,1,0,1]], dtype = np.float)

truth_T = truth.getTransformations()
#print truth_T

#transform plane from local frame to sensor frame
frame = 0
for i in range(3):
#	plane_pts[i] = (np.matrix(truth_T[:,:,frame])*plane_pts[i,:].T).T
	plane_pts[i] = (plane_pts[i,:]*np.matrix(truth_T[:,:,frame]))

print plane_pts

U,S,V = svd(plane_pts[0:3, 0:3])
V = V.T.conj()
N_x = np.array(V[:,0])
N_y = np.array(V[:,1])
N_z = np.array(V[:,2])

accept_x = np.sum((pc_range*N_x[np.newaxis,:]), axis=1)
accept_y = np.sum((pc_range*N_y[np.newaxis,:]), axis=1)
accept_z = np.sum((pc_range*N_z[np.newaxis,:]), axis=1)

accept = (accept_z > -.65) * (np.abs(accept_x) < .05)* (np.abs(accept_y) > .25) * (np.abs(accept_y) < .5)

pos_vec = pc_range * accept
color_vec = pc_color * accept

pos = np.reshape(pos_vec.T, (480, 640, 3))
img = np.reshape(color_vec.T, (480, 640, 3))

#pl.imshow(pos[:,:,2])
#pl.imshow(img)
#pl.show()

#pdb.set_trace()

im = sm.toimage(img[:,:,0])
im.save('sift/tmp_sift_img.pgm')
imagename = 'tmp_sift_img.pgm'
resultname = 'tmp_features'
os.system("sift/sift <"+imagename+">"+resultname)
#os.system('chmod og=rwx tmp_sift_img2.jpg')
#sm.imsave('tmp_sift_img.jpg', img)
#sift.process_image('tmp_sift_img2.pgm', 'tmp_features')
feat = sift.read_features_from_file('tmp_features')

sift.plot_features(img, feat[0])




