#!/usr/bin/env python

''' Use this file to store image-based functions for the kinect

Current list:
	- background_subtraction
	- normalize_depth
	- find_edges
	- calc_normals

'''



import numpy as np
import cv


def background_subtraction(depth_raw, img_rgb=None, max_depth=255):

	if img_rgb == None:
		rez = np.shape(depth_raw)
		img_rgb = np.ndarray((rez[0], rez[1], 3))

	#depth_mod = self.depth_raw

	mask = np.logical_and(depth_raw < max_depth, depth_raw > 0)
	
	max_depth = np.nanmax(depth_raw*mask)
	min_depth = np.nanmin(depth_raw)
	span_depth = float(np.maximum(max_depth - min_depth, 0.1)) #use 'max' to prevent divide by zero
	span_max = float(255)
	
	print max_depth
	print min_depth

	depth_masked = depth_raw*mask
	
	#rez = np.shape(depth_raw)
	#rgb_mod = np.zeros((rez[0], rez[1], 3), dtype=depth_raw.dtype)

	print np.shape(depth_masked)
	print np.shape(img_rgb)		
	img_rgb[:,:,0] = depth_masked*float(span_max/span_depth)
	img_rgb[:,:,1] = max_depth*mask - depth_masked*float(span_max/span_depth)
	img_rgb[:,:,2] = np.invert(mask)*255

	return img_rgb



def normalize_depth(depth, copy=0):

	if copy == 1:
		img = depth.copy()
	else:
		img = depth
		
	mask = np.invert(np.isnan(depth))
	max_depth = np.nanmax(mask*depth)
	
	img = np.minimum(depth*mask*(255/max_depth), 255)
	
	if depth.dtype == np.uint8:
		img = np.uint8(img)
		
	return img
		


def find_edges(img, copy=0):

	if copy == 1:
		output = img
	else:
		output = img.copy()

	kernel = cv.fromarray(np.array([[0, 1, 0],[1,-4,1], [0,1,0]]))
	edges_in = cv.fromarray(img)
	edges_out = cv.CreateMat(480, 640, cv.CV_8UC1)
	#cv.Sobel(edges_in, edges_in, 1, 1, 3)
	cv.Filter2D(img, output, kernel)

	return output*5



def calc_normals(depth_in, coords_basis):
		# find magnitude of displacment (3d) in x & y axes.

		depth = np.ndarray((480, 640, 3), dtype=depth_in.dtype)
		dx = np.ndarray((480, 640, 3), np.float32)
		dy = np.ndarray((480, 640, 3), np.float32)
		dz = np.ndarray((480, 640, 3), np.float32)

#		n_cross = np.ndarray((480, 640, 3), np.float32)
		denom = np.ndarray((478, 638, 3))
#		denom = np.ndarray((480, 640, 3))		
#		x_mag = np.ndarray((480, 640, 1), np.float32)
#		y_mag = np.ndarray((480, 640, 1), np.float32)
		
		depth_in = np.nan_to_num(depth_in)
		depth[:,:,0] = depth_in
		depth[:,:,1] = depth[:,:,0]
		depth[:,:,2] = depth[:,:,0]	


		#For normal, look at eqn 20 here:
		#http://mathworld.wolfram.com/NormalVector.html
		#
		#                    a x b
		# normal = ----------------------------
		#          sqrt( |a|^2 |b|^2 - |ab|^2 )
		#

#		#Find dx and dy for each point. 
#		dx[0:478, 0:639] = coords_basis[1:479, 0:639]*depth[1:479, 0:639] - coords_basis[0:478, 0:639]*depth[0:478, 0:639]

#		dy[0:479, 0:638] = coords_basis[0:479, 1:639]*depth[0:479, 1:639] - coords_basis[0:479, 0:638]*depth[0:479, 0:638]

#		x_mag = np.sqrt(np.tensordot(dx, dx.conj(), axes=3)) #apparently this way is faster
#		y_mag = np.sqrt(np.tensordot(dy, dy.conj(), axes=3)) #apparently this way is faster

#		#normalize
#		dx = dx / x_mag
#		dy = dy / y_mag


#		dot = np.tensordot(dx, dy, axes=3)
#		denom[:,:,0] = np.maximum(np.sqrt(x_mag*y_mag) - dot**2, 1)
#		denom[:,:,1] = denom[:,:,0]
#		denom[:,:,2] = denom[:,:,0]
#		n_cross = np.cross(dx, dy)
#		dz = n_cross / denom





		dx = coords_basis[1:479, 1:639]*depth[1:479, 1:639] - coords_basis[0:478, 1:639]*depth[0:478, 1:639]

		dy = coords_basis[1:479, 1:639]*depth[1:479, 1:639] - coords_basis[1:479, 0:638]*depth[1:479, 0:638]

		x_mag = np.sqrt(np.tensordot(dx, dx.conj(), axes=3)) #apparently this way is faster
		y_mag = np.sqrt(np.tensordot(dy, dy.conj(), axes=3)) #apparently this way is faster

		#normalize
		dx = dx / x_mag
		dy = dy / y_mag


		dot = np.tensordot(dx, dy, axes=3)
		denom[:,:,0] = np.maximum(np.sqrt(x_mag*y_mag) - dot**2, 1)
		denom[:,:,1] = denom[:,:,0]
		denom[:,:,2] = denom[:,:,0]
		
		dz = np.cross(dx, dy) / denom


		img_out = np.maximum(np.minimum(128+dz*128*10000/np.max(dz), 255), 0)

		return img_out
		
		
		
		
		
		
#TODO def pointcloud2image(pc):




#TODO image2pointcloud

