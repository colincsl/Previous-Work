
'''
Overview:
*input: Nx6 dense pointcloud
*Remove background
	-Find normals in self.img - SVD
	-RANSAC to find plane
'''

import sys, os
import numpy as np
from numpy.linalg import svd
import scipy.misc as sm
import pylab as pl
import sift
import random

import scipy.ndimage as nd

import time
import pdb


class ObjectFinder:

	def __init__(self, pc=None, x_dim=48/2, y_dim=64/2, sample_percent=.05):

		if pc != None:
			self.pc_range = pc[0,:,:]#np.array([pc['x'],pc['y'], pc['z']])
			self.pc_color = pc[1,:,:]
		else:
			input_file = '/home/colin/sip_data/training_new/pointclouds_obj16/pc_1302023598.npy'
			pc = np.load(input_file)
			self.pc_range = np.array([pc['x'],pc['y'], pc['z']])
			self.pc_color = np.array([pc['r'],pc['g'], pc['b']])
			
		self.x_dim = x_dim
		self.y_dim = y_dim
		self.sample_percent = sample_percent
		
		self.pos = np.reshape(self.pc_range, (480, 640, 3))
		self.img = np.reshape(self.pc_color, (480, 640, 3))		
			
			
	def run(self, min_=.6, max_=1.2):
#		start_time = time.time()
		self.find_normals()
		self.eliminate_bg(min_=min_, max_=max_)
		pc, im = self.eliminate_normals()	
		
		for i in range(1):
			model, offset = self.planar_ransac(pc)
#			print "Model: ", model, " Offset: ", offset
			pc, im  = self.eliminate_plane(model, offset)
		
#		print 'Elapsed time: ', time.time()-start_time	

		pc = pc[np.nonzero(pc > 0)[0]]
			
		return pc, im


	def display(self, im_disp):
		#pl.imshow(im_out, vmin=min_, vmax=max_)
		pl.imshow(im_disp) #im_disp=self.img[:,:,0]*(im_out_resize>0.5)
		pl.show()
		

	def find_normals(self):
		sample_iter = int(1/self.sample_percent)
		total_dim = int(np.sqrt(480*640 / (self.x_dim*self.y_dim)))
		
		self.pos_svd = np.reshape(self.pos, (-1, self.x_dim, self.y_dim, 3))

		part = np.empty((self.pos_svd.shape[0],self.x_dim*self.y_dim, 3))
		part_sq = np.empty((self.pos_svd.shape[0],self.x_dim,self.y_dim,3))
		
		k = 0
		for i in range(total_dim):
			for j in range(total_dim):
				part_sq[k]=self.pos[i*self.x_dim:(i+1)*self.x_dim,j*self.y_dim:(j+1)*self.y_dim,:]
				part[k] = np.reshape(self.pos[i*self.x_dim:(i+1)*self.x_dim,j*self.y_dim:(j+1)*self.y_dim,:], (self.x_dim*self.y_dim, 3))
				k+=1


		N_x = np.zeros((self.pos_svd.shape[0], 3))
		N_y = np.zeros((self.pos_svd.shape[0], 3))
		N_z = np.zeros((self.pos_svd.shape[0], 3))

		# part is M panels by x_dim*y_dim by 3

		for i in range(self.pos_svd.shape[0]):
		#	print i
			if -np.isnan(np.nansum(part[i])): #make sure the sum isn't 'nan'
#				tmp = np.reshape(part[i], (-1, 1))
#				tmp2 = tmp[np.nonzero(np.isnan(tmp) == 0)]			
#				tmp2 = tmp[np.nonzero(-np.isnan(tmp) > 0)]

				#Check which rows are NaN, select indices of those which are real
				tmp = (np.nonzero(np.isnan(np.sum(part[i], axis=1))==0))[0]
				tmp2 = part[i, tmp]
#				pdb.set_trace()
				part_svd = np.reshape(tmp2,(-1, 3))
				centroids = np.mean(part_svd, axis=0)

				_,_,V = svd(part_svd[::sample_iter,:]-centroids)
				V = V.T.conj()
				N_x[i,:] = np.array(V[:,0])
				N_y[i,:] = np.array(V[:,1])
				N_z[i,:] = np.array(V[:,2])


		self.N_img_x = np.reshape(N_x, (total_dim,total_dim,3))
		self.N_img_y = np.reshape(N_y, (total_dim,total_dim,3))
		self.N_img_z = np.reshape(N_z, (total_dim,total_dim,3))

	def eliminate_bg(self, min_=.6, max_=1.2):
		#Eliminate anything farther away than 1.2 meters or less than 0.6 meters
		self.pc_range[np.nonzero(self.pc_range[:,2] < min_)[0], :] = np.NaN
		self.pc_range[np.nonzero(self.pc_range[:,2] > max_)[0], :] = np.NaN
		
		self.pos[np.nonzero(self.pos[:,2] < min_)[0], :] = np.NaN
		self.pos[np.nonzero(self.pos[:,2] > max_)[0], :] = np.NaN
		

	def eliminate_normals(self):
		#for normal (horizonal) images use z, else use x. AND for horiz use y, else z
		max_ = np.max(self.N_img_x[:,:,2])
		min_ = .65*max_
		im_out = ((np.abs(self.N_img_x[:,:,2])>np.abs(self.N_img_y[:,:,2]))>min_)*np.abs(self.N_img_x[:,:,2])
		im_out_resize = nd.interpolation.zoom(im_out, [self.x_dim,self.y_dim], mode='nearest')
		mask = np.reshape(im_out_resize, (480*640,1))>.75

#		pdb.set_trace()
		pc_range_out = self.pc_range*mask
		pc_range_out[np.nonzero(np.sum(pc_range_out>0, axis=1)==0)[0], :] = np.NaN
#		pc_range_out = pc_range_out[np.nonzero(np.sum(pc_range_out>0, axis=1)>0)[0], :]
		masked_img = self.img[:,:,0]*(im_out_resize>0.5)
#		pl.imshow(masked_img)
#		pl.show()
		return pc_range_out, masked_img
		
	def eliminate_plane(self, model, offset, thresh=-0.02):
	
		pc = self.pc_range

		tmp_pos = (pc-offset)*model

		mask_vec = np.sum(tmp_pos, axis=1) < thresh
		mask_img = np.reshape(mask_vec, (480, 640))

		pc_range_out = pc * np.reshape(mask_vec, (-1, 1))
#	in!	pc_range_out[np.nonzero(np.nansum(pc_range_out, axis=1)==0)[0], :] = 0

		masked_img = self.img[:,:,0]*mask_img
		
#		pl.imshow(np.reshape(tmp_pos <.0,(480, 640)))
#		pl.imshow(masked_img)
#		pl.show()


		return pc_range_out, masked_img
		
		
	def planar_ransac(self, pc):
		#fit to model Ax  +By + Cz + D = 0 (a plane)
		sample_iter = 20
		pc = pc[np.nonzero(np.nansum(pc, axis=1)>0)[0], :]
		pc = pc[::sample_iter,:]
		pc_len = pc.shape[0]
		n=int(0.1*pc_len)		#size of random sample
#		print "Points: ", n
		k=15; 		#number of iteration
		err_thresh=0.01				#deviation - meters
		min_points=.5*pc_len	 	#minime amount of points within deviation		
		
		iter_ = 0
		best_model = None
		best_consensus_set = None
		best_error = np.inf
		best_offset = None
		
		while best_model == None:
			while iter_ < k:

				maybe_inliers = pc[np.random.randint(0, pc_len, (n))] #get n random points from pc
				offset = np.mean(maybe_inliers, axis=0)
				maybe_inliers -= offset
				# Find model
				_,_,Vs = svd(maybe_inliers)
				V = Vs.T.conj() 
				Normal = V[:,2]
				maybe_model = Normal
				consensus_set = maybe_inliers

				err = np.sum((pc-offset) * maybe_model, axis=1)
				consensus_set = pc[np.nonzero(err < err_thresh)[0]]
#				print consensus_set.shape, pc_len
			
				if consensus_set.shape[0] > min_points:
					_,_,Vs = svd(maybe_inliers)
					V = Vs.T.conj() 
					Normal = V[:,2]
					better_model = Normal
				
					offset = np.mean(consensus_set, axis=0)
					new_error = np.sum(np.sum((consensus_set-offset) * maybe_model, axis=1))
#					print new_error
				
					if abs(new_error) < best_error:
	#					print "iter: ", iter_
	#					print "e: ", best_error					
						best_model = better_model
						best_consensus_set = consensus_set
						best_error = abs(new_error)
						best_offset = offset
					
				iter_ += 1
			#if there is no model, decrease the number of points required for 'best' model
			min_points = min_points*3/4 
			iter_ = 0
			
		return best_model, best_offset




#pdb.set_trace()

#pl.imshow((np.abs(self.N_self.img_y[:,:,1])>0)*np.abs(self.N_self.img_y[:,:,1]))

#im = sm.toimage(self.img[:,:,0])
#im.save('sift/tmp_sift_self.img.pgm')
#imagename = 'tmp_sift_self.img.pgm'
#resultname = 'tmp_features'
#os.system("sift/sift <"+imagename+">"+resultname)
##os.system('chmod og=rwx tmp_sift_self.img2.jpg')
##sm.imsave('tmp_sift_self.img.jpg', self.img)
##sift.process_image('tmp_sift_self.img2.pgm', 'tmp_features')
#feat = sift.read_features_from_file('tmp_features')

#sift.plot_features(self.img, feat[0])

