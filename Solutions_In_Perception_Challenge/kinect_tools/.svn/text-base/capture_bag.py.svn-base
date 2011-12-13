#!/usr/bin/env python

working_dir = '/home/colin/repo/perception_repo/' # needed to import kinect_tools

'''
	Record rgb+depth data
	
	Usage: First run the following:
		roscore
		roslaunch openni_camera openni_kinect.launch
		roslaunch kinect_tools capture_images.launch
'''

import roslib; roslib.load_manifest('kinect_template')
import rospy
import rosbag
#import tf
import numpy as np
import cv
import string
import time
import sys
import select
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
from sensor_msgs.msg import CameraInfo
#from sensor_msgs.msg import PointCloud2
from std_msgs.msg import String


sys.path.append((working_dir + 'kinect_tools'))


class kinect_template:

	def __init__(self):

		#Subscribe to the Kinect's RGB/depth images and camera info
		self.sub_depth = rospy.Subscriber('/camera/depth/image', Image, self.image_callback)
#		self.sub_depth_points = rospy.Subscriber('/camera/depth/points2', PointCloud2, self.pointcloud_callback)
		self.sub_rgb = rospy.Subscriber('/camera/rgb/image_color', Image, self.image_callback)
#		self.sub_depth_camera = rospy.Subscriber('/camera/depth/camera_info', CameraInfo, self.params_callback)

		"""
		Available (Published) data

		Append each to '/camera/' (ie /camera/depth/camera_info):
			depth/camera_info	depth/image		depth/disparity	depth/points2
			rgb/camera_info		rgb/image_color		rgb/image_mono
			
		Don't append these to '/camera/':
			/openni_camera/parameter_descriptions	/openni_camera_parameter_updates

		"""

		# We will publish RGB and depth images to display on the screen
		self.pub_img_1 = rospy.Publisher('img_out1', Image)
		self.pub_img_2 = rospy.Publisher('img_out2', Image)
		
		
		# Put data into a rosbag
		
		bag_dir = working_dir + 'kinect_tools/output/' + 'bag_' + str(int(time.time())) + '.bag'
		print bag_dir
		self.bag = rosbag.Bag(bag_dir, 'w')
		

		# CvBridge is used to convert published ROS images to 'CvMat' OpenCV (or Numpy) matrices
		self.bridge = CvBridge()

		#Initialize input and modified images
		self.depth_raw = None
		self.rgb_raw = None

		#Init the output images
		self.img_out_1 = None #self.rgb_raw
		self.img_out_2 = None #self.depth_raw
		
		# We use this variable to know when we are running image functions (to prevent overload)
		self.processing = 0





#	def params_callback(self, data):
#		# Get information about the camera parameters and the cam/world transformation. 
#		# The published data is stored in 'data'. These parameters don't change so we only call this function once and then unsubscribe from the message.

#		# Get the transformation between our camera and world coordinates
#		if self.tf_depth2rgb == None:
#			# To Find which frames are available use the following:
#			#print self.tf_listener.allFramesAsString()

#			# The tf returns a (position, quaternion) tuple
#			self.tf_depth2rgb = self.tf_listener.lookupTransform('/openni_depth_frame', '/openni_rgb_frame', rospy.Time(0))
#		
#		# Get camera matrix parameters
#		self.info_depth_camera = data
#		
#		# The data is generally stored in vector form. Grab the camera matrix and reshape.
#		self.info_depth_cam_mat = np.array(data.K).reshape(3,3)

#		x_cosine = np.ndarray(480, dtype=np.float32)
#		y_cosine = np.ndarray(640, dtype=np.float32)		
#	
#		# The data we are given is depth, so to find actual x/y/z we need to know the length of each ray. To account for this we need to factor in the angle of the ray from the camera pinhole. 	
#		# Kinect: Horizontal FoV = 57*,  Vertical FoV = 43*	
#		for i in range(480):
#			x_cosine[i] = 1 / np.cos( ( float(i) - 240. ) / 240. * 28.5 * np.pi / 180. )
#		for i in range(640):
#			y_cosine[i] = 1 / np.cos( ( float(i) - 320. ) / 320. * 21.5 * np.pi / 180. )			

#		# Create a matrix to project points from image->3D space
#		for i in range(480):
#			offset_y = self.info_depth_cam_mat[1,2]
#			self.coords_basis[i,:,0] = ([i-offset_y,1,1] / self.info_depth_cam_mat[0,0])[0] * y_cosine
#	#		print [i-offset_y,1,1] / self.info_depth_cam_mat[0,0]

#		for j in range(640):
#			offset_x = self.info_depth_cam_mat[0,2]
#			self.coords_basis[:,j,1] = ([1,j-offset_x,1] / self.info_depth_cam_mat[1,1])[1] * x_cosine

#		# Depth is unit (1)
#		self.coords_basis[:,:,2] = np.ones((480, 640))			
#		
#		# Unsubscribe from any more messages 		
#		self.sub_depth_camera.unregister()
#		







#	def pointcloud_callback(self, data):
#		# The data isn't explicitly used in our file, but we will import it anyway.
#		# This uses a pointcloud2 datastructure.
#		# Datasheet http://www.ros.org/doc/api/sensor_msgs/html/msg/PointCloud2.html
#			self.point_cloud = data


	def image_callback(self, data):
		# Assign incoming Kinect images to depth/rgb images
		# and run fucntions on images

		#Depth
		# depth images are recieved as float32 values. To output to the screen these need to be changed to np.int8
		if data.encoding == '32FC1':
			# We convert a ROS image to an OpenCV CvMat to a Numpy array w/ cv_bridge
			# Conversion from CvMat to ndarray is just passing a reference and changing a header
#			self.depth_raw = self.bridge.imgmsg_to_cv(data)
			self.depth_raw = data
			
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

#		x = select.select([sys.stdin],[],[],0.0001)
#		print x
		#convert bgr to rgb color for output
		cv.CvtColor(self.rgb_raw, self.rgb_raw, cv.CV_BGR2RGB)

		#Publish output
		self.img_out_1 = self.bridge.cv_to_imgmsg(np.uint8(self.rgb_raw))
#		self.img_out_2 = self.bridge.cv_to_imgmsg(np.uint8(self.depth_raw))
		self.img_out_2 = self.depth_raw		

		t = rospy.Time.now()
#		print t.to_sec()
		self.bag.write('/img_rgb', self.img_out_1, rospy.Time.now())		
		self.bag.write('/img_depth', self.img_out_2, rospy.Time.now())
		
#		self.bag.reindex()
		
		# We must convert to uint8 and from a numpy array to ROS image before publishing
		self.pub_img_1.publish( self.img_out_1 )
		self.pub_img_2.publish( self.img_out_2 )		

		self.processing = 0






def main(args):
	#We must first initialize this as a node to register in ROS
	rospy.init_node('kinect_template', anonymous=True)
	kinect = kinect_template()
	try:
		rospy.spin()
	except KeyboardInterrupt:
		kinect.bag.close()
		print 'Closing...'

if __name__ =='__main__':
	main(sys.argv)

