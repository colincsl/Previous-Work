#!/usr/bin/env python

working_dir = '/home/colin/repo/perception_repo/' # needed to import kinect_tools

''' Kinect Template w/ OpenNI driver:
This file outlines what is necessary to work with a Kinect. It subscribes to images, point clouds, and other parameters and publishes two images. The launch file 'run_openni_template.launch' runs this script and displays the RGB and depth/modified images to screen. Example functions are included in /kinect_tools/image_tools.py. 

Notes:
-This assumes you want to use numpy to manipulate images. If you are only using OpenCV this is not absolutely necessary. 
-Color is published in the format Blue-Green-Red
-This version uses the Primesense OpenNI kinect driver
-Depth values are float32 in meters
'''

import roslib; roslib.load_manifest('kinect_template')
import rospy
import tf
import numpy as np
import numpy.linalg as lin
import cv
import string
import time
import sys
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
from sensor_msgs.msg import CameraInfo
from sensor_msgs.msg import PointCloud2
from std_msgs.msg import String


sys.path.append((working_dir + 'kinect_tools'))

#try:
#import image_tools as tools
#except:
#	print 'image_tools not found'
	
#import cProfile
#command = """reactor.run()"""
#cProfile.runctx( command, globals(), locals(), filename="OpenGLContext.profile" )



class kinect_template:

	def __init__(self):

		#Subscribe to the Kinect's RGB/depth images and camera info
		self.sub_depth = rospy.Subscriber('/camera/depth/image', Image, self.image_callback)
		self.sub_depth_points = rospy.Subscriber('/camera/depth/points2', PointCloud2, self.pointcloud_callback)
		self.sub_rgb = rospy.Subscriber('/camera/rgb/image_color', Image, self.image_callback)
		self.sub_depth_camera = rospy.Subscriber('/camera/depth/camera_info', CameraInfo, self.params_callback)

		"""
		Available (Published) data

		Append each to '/camera/' (ie /camera/depth/camera_info):
			depth/camera_info	depth/image		depth/disparity	depth/points2
			rgb/camera_info		rgb/image_color		rgb/image_mono
			
		Don't append these to '/camera/':
			/openni_camera/parameter_descriptions	/openni_camera_parameter_updates

		"""

		# We will publish RGB and depth images to display on the screen
		self.pub_img_1 = rospy.Publisher('img_out', Image)
		self.pub_img_2 = rospy.Publisher('img_out2', Image)

		# We can find transforms between the camera and the world
		# Before getting the transforms we must init the tf_listener. You must wait until after the init function to get this or else you don't recieve any data.
		self.tf_listener = tf.TransformListener()
		self.tf_depth2rgb = None

		# CvBridge is used to convert published ROS images to 'CvMat' OpenCV (or Numpy) matrices
		self.bridge = CvBridge()

		#Initialize input and modified images
		self.depth_raw = None
		self.rgb_raw = None

		#Init the output images
		self.img_out_1 = None #self.rgb_raw
		self.img_out_2 = None #self.depth_raw
		
		#Create projection matrix defining the physical per-unit x and y values at each pixel
		#Once initialized multiple this by the distance to get 3D values
		#For an example see 'calc_normals()' in /kinect_tools/image_tools.py
		self.coords_basis = np.zeros((480, 640, 3), dtype=np.float32)		

		# Determine frames per second
		self.fps_time = time.time()

		# We use this variable to know when we are running image functions (to prevent overload)
		self.processing = 0






	def params_callback(self, data):
		# Get information about the camera parameters and the cam/world transformation. 
		# The published data is stored in 'data'. These parameters don't change so we only call this function once and then unsubscribe from the message.

		# Get the transformation between our camera and world coordinates
		if self.tf_depth2rgb == None:
			# To Find which frames are available use the following:
			#print self.tf_listener.allFramesAsString()

			# The tf returns a (position, quaternion) tuple
			self.tf_depth2rgb = self.tf_listener.lookupTransform('/openni_depth_frame', '/openni_rgb_frame', rospy.Time(0))
		
		# Get camera matrix parameters
		self.info_depth_camera = data
		
		# The data is generally stored in vector form. Grab the camera matrix and reshape.
		self.info_depth_cam_mat = np.array(data.K).reshape(3,3)

		x_cosine = np.ndarray(480, dtype=np.float32)
		y_cosine = np.ndarray(640, dtype=np.float32)		
	
		# The data we are given is depth, so to find actual x/y/z we need to know the length of each ray. To account for this we need to factor in the angle of the ray from the camera pinhole. 	
		# Kinect: Horizontal FoV = 57*,  Vertical FoV = 43*	
		for i in range(480):
			x_cosine[i] = 1 / np.cos( ( float(i) - 240. ) / 240. * 28.5 * np.pi / 180. )
		for i in range(640):
			y_cosine[i] = 1 / np.cos( ( float(i) - 320. ) / 320. * 21.5 * np.pi / 180. )			

		# Create a matrix to project points from image->3D space
		for i in range(480):
			offset_y = self.info_depth_cam_mat[1,2]
			self.coords_basis[i,:,0] = ([i-offset_y,1,1] / self.info_depth_cam_mat[0,0])[0] * y_cosine
	#		print [i-offset_y,1,1] / self.info_depth_cam_mat[0,0]

		for j in range(640):
			offset_x = self.info_depth_cam_mat[0,2]
			self.coords_basis[:,j,1] = ([1,j-offset_x,1] / self.info_depth_cam_mat[1,1])[1] * x_cosine

		# Depth is unit (1)
		self.coords_basis[:,:,2] = np.ones((480, 640))			
		
		# Unsubscribe from any more messages 		
		self.sub_depth_camera.unregister()
		







	def pointcloud_callback(self, data):
		# The data isn't explicitly used in our file, but we will import it anyway.
		# This uses a pointcloud2 datastructure.
		# Datasheet http://www.ros.org/doc/api/sensor_msgs/html/msg/PointCloud2.html
			self.point_cloud = data


	def image_callback(self, data):
		# Assign incoming Kinect images to depth/rgb images
		# and run fucntions on images

		#Depth
		# depth images are recieved as float32 values. To output to the screen these need to be changed to np.int8
		if data.encoding == '32FC1':
			# We convert a ROS image to an OpenCV CvMat to a Numpy array w/ cv_bridge
			# Conversion from CvMat to ndarray is just passing a reference and changing a header
			self.depth_raw = np.asarray(self.bridge.imgmsg_to_cv(data))
			
		#RGB
		elif data.encoding == 'rgb8':
			self.rgb_raw = np.asarray(self.bridge.imgmsg_to_cv(data))


		'''
		Only process data if there isn't another process running. If you process at every image callback you end up starting many parallel processes which makes each frame take much longer and in general lags the video.	
		'''
		if self.processing == 0 and self.depth_raw != None and self.rgb_raw != None:
			self.main()
		





	def main(self):
		self.processing = 1

		# Framerate:
		print 'FPS: ' + str((1/(time.time()-self.fps_time)))
		self.fps_time = time.time()

		#Publish output
		self.img_out_1 = self.rgb_raw		
		# The depth is in meters and thus is a low number. Multiple (or equalize) to make it more visible
		#self.img_out_2 = np.minimum(self.depth_raw	* 30, 255)

		# Example functions from image_tools
		#self.img_out_2 = tools.normalize_depth(self.depth_raw)
		#self.img_out_2 = tools.background_subtraction(self.depth_raw, max_depth=50)
		#self.img_out_2 = tools.find_edges(self.depth_raw)
#		self.img_out_2 = tools.calc_normals(self.depth_raw, self.coords_basis)		
		self.img_out_2 = self.calc_normals()		
		
		#convert bgr to rgb color for output
		cv.CvtColor(self.img_out_1, self.img_out_1, cv.CV_BGR2RGB)

		# We must convert to uint8 and from a numpy array to ROS image before publishing
		self.pub_img_1.publish( self.bridge.cv_to_imgmsg(np.uint8(self.img_out_1)) )
		self.pub_img_2.publish( self.bridge.cv_to_imgmsg(np.uint8(self.img_out_2)) )		

		self.processing = 0










	def calc_normals(self):

			# find magnitude of displacment (3d) in x & y axes.
			depth_in = np.float32(self.depth_raw)
			coords_basis = self.coords_basis
		
#			depth = np.ndarray((480, 640, 3), dtype=depth_in.dtype)
			dx = np.ndarray((478, 638), np.float32)
			dy = np.ndarray((478, 638), np.float32)
			dz = np.ndarray((478, 638), np.float32)

	#		n_cross = np.ndarray((480, 640, 3), np.float32)
			denom = np.ndarray((478, 638, 3))
	#		denom = np.ndarray((480, 640, 3))		
	#		x_mag = np.ndarray((480, 640, 1), np.float32)
	#		y_mag = np.ndarray((480, 640, 1), np.float32)
		
		
#			depth = depth_in
#			depth = np.dstack((depth_in, depth_in, depth_in))
			depth = np.nan_to_num(depth_in)
#			depth[:,:,1] = depth[:,:,0]
#			depth[:,:,2] = depth[:,:,0]				
			
			


			#For normal, look at eqn 20 here:
			#http://mathworld.wolfram.com/NormalVector.html
			#
			#                    a x b
			# normal = ----------------------------
			#          sqrt( |a|^2 |b|^2 - |ab|^2 )
			#

			dz = depth[1:479, 1:639] - depth[1:479, 0:638]
			dx = (coords_basis[1:479, 1:639, 0] - coords_basis[0:478, 1:639, 0]) * dz
			dy = (coords_basis[1:479, 1:639, 1] - coords_basis[1:479, 0:638, 1]) * dz
			
			x_mag = np.sqrt(dx**2 + dz**2)
			y_mag = np.sqrt(dy**2 + dz**2)	
			
#			x_mag[np.isnan(x_mag)] = 1
#			y_mag[np.isnan(y_mag)] = 1					 		
			x_mag[x_mag==0] = 1
			y_mag[y_mag==0] = 1
#			y_mag = np.maximum(np.sqrt(np.sum(dy**2, axis=2)) 	, .001)
#			x_mag = np.sqrt(np.tensordot(dx, dx.conj(), axes=3) #apparently this way is faster
#			y_mag = np.sqrt(np.tensordot(dy, dy.conj(), axes=3)) #apparently this way is faster

			#normalize
			dx = dx/x_mag
			dy = dy/y_mag
#			dx = dx / np.dstack((x_mag, x_mag, x_mag))
#			dy = np.divide(dy, np.dstack((y_mag, y_mag, y_mag)))

			dot = 0#dx*dy
#			denom = np.maximum(np.sqrt(x_mag*y_mag) - dot**2, 1)		
			denom[:,:,0] = np.maximum(x_mag * y_mag - dot**2, 0)	
			denom[:,:,1] = denom[:,:,0]
			denom[:,:,2] = denom[:,:,0]			
			
			a = np.dstack((dx, np.zeros(dx.shape), dz/x_mag))
			b = np.dstack((np.zeros(dx.shape), dy, dz/y_mag))			
			
			dn = np.cross(a, b) / denom			
#			print dn.shape


			img_out = np.maximum(np.minimum(128+dn*128/np.max(np.abs(dn)), 255), 0)

#			print dx[100:210, 100:110]
			m = np.nanmax(b)
#			print dn
#			print np.nanmax(np.abs(dn))

#			print dn

			return np.minimum(dz*100, 255)#x_mag*255/m








def main(args):
	#We must first initialize this as a node to register in ROS
	rospy.init_node('kinect_template', anonymous=True)
	kinect = kinect_template()
	try:
		rospy.spin()
	except KeyboardInterrupt:
		print 'Closing...'

if __name__ =='__main__':
	main(sys.argv)

