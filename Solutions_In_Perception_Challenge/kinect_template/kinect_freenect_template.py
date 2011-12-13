#!/usr/bin/env python

''' Kinect Template:
This file outlines what is necessary to work with a Kinect. It subscribes to images, point clouds, and other parameters and publishes two images. The launch file 'run_template.launch' runs this script and displays the RGB and depth/modified images to screen. Background subtraction is included as an example which produces a colorized output based on relative distances.

Notes:
-This assumes you want to use numpy to manipulate images. If you are only using OpenCV this is not absolutely necessary. 
-Color is published in the format Blue-Green-Red
-This version uses the open source freenect kinect drivers
'''

import roslib; roslib.load_manifest('kinect_template')
import rospy
import tf
import numpy as np
import cv
import string
import sys
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
from sensor_msgs.msg import CameraInfo
from sensor_msgs.msg import PointCloud2
from std_msgs.msg import String



class kinect_template:

	def __init__(self):

		#Subscribe to the Kinect's RGB/depth images and camera info
		self.sub_depth = rospy.Subscriber('/kinect/depth/image_raw', Image, self.image_callback)
		self.sub_depth_points = rospy.Subscriber('/kinect/depth/points2', PointCloud2, self.pointcloud_callback)
		self.sub_rgb = rospy.Subscriber('/kinect/rgb/image_rect_color', Image, self.image_callback)
		self.sub_depth_camera = rospy.Subscriber('/kinect/depth/camera_info', CameraInfo, self.params_callback)

		"""
		Available (Published) data

		Append each to '/kinect/' (ie /kinect/depth/camera_info):
			depth/camera_info	depth/image_raw		depth/points	depth/points2
			rgb/camera_info		rgb/image_raw		rgb/points	rgb/points2 	rgb/image_rect_color
			ir/camera_info		ir/image_raw
			imu
		Don't append these to '/kinect/':
			/kinect_driver/parameter_descriptions	/kinect_driver_parameter_updates

		"""

		# We will publish RGB and depth images to display on the screen
		self.pub_img_1 = rospy.Publisher('img_out', Image)
		self.pub_img_2 = rospy.Publisher('img_out2', Image)

		# We can find transforms between the camera and the world
		# Before getting the transforms we must init the tf_listener. You must wait until after the init function
		# to get this data or else you don't recieve any data.
		self.tf_listener = tf.TransformListener()
		self.tf_depth2world = None

		# CvBridge is used to convert published ROS images to 'CvMat' OpenCV matrices (or then Numpy arrays)
		self.bridge = CvBridge()

		#Initialize input and modified images
		self.depth_raw = np.zeros((480, 640), dtype=np.uint8)
		self.depth_mod = np.zeros((480, 640), dtype=np.uint8)
		self.rgb_raw = np.zeros((480, 640, 3), dtype=np.uint8)
		self.rgb_mod = np.zeros((480, 640, 3), dtype=np.uint8)

		#Init the output images
		self.img_out_1 = self.rgb_raw
		self.img_out_2 = self.depth_raw

		# We use this variable to know when we are running image functions (to prevent overload)
		self.processing = 0


	def params_callback(self, data):
		# Get information about the camera parameters and the cam/world transformation. The published data is stored in 		# 'data'. These parameters don't change so we only call this function once and then unsubscribe from the message.

		# Get the transformation between our camera and world coordinates
		if self.tf_depth2world == None:
			print self.tf_listener.allFramesAsString()
			# returns (position, quaternion)
			self.tf_depth2world = self.tf_listener.lookupTransform('/kinect_depth', '/world', rospy.Time(0))

		# Get camera matrix parameter
		if data.header.frame_id == '/kinect_depth':
			self.info_depth_camera = data
			# The data is generally stored in vector form. Grab the camera matrix and reshape.
			self.info_depth_cam_mat = np.array(data.K).reshape(3,3)
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
		if data.encoding == 'mono8':
			# We convert a ROS image to an OpenCV CvMat to a Numpy array
			# Conversion from CvMat to array is computationally trivial (change to the header)
			self.depth_raw = np.asarray(self.bridge.imgmsg_to_cv(data))
		#RGB
		elif data.encoding == 'rgb8':
			self.rgb_raw = np.asarray(self.bridge.imgmsg_to_cv(data))


		''' 	Only process data if there isn't another process running. If you process at every image callback
			you end up starting many parallel processes which makes each frame take much longer and in
			general lags the video.	
		'''
		if self.processing == 0 and self.depth_raw != None and self.rgb_raw != None:
#			self.img_out_2 = self.background_subtraction(255) # Max is 255. This is unitless 

			self.img_out_1 = self.rgb_raw
			self.img_out_2 = self.depth_raw

			mask = self.depth_raw < 255
			max_depth = (np.uint8(self.depth_raw*mask)).max()
			print max_depth


			#Publish output
			self.pub_img_1.publish( self.bridge.cv_to_imgmsg(self.img_out_1))
			self.pub_img_2.publish( self.bridge.cv_to_imgmsg(np.uint8(self.img_out_2*(255/max_depth))))
#			self.pub_img_2.publish( self.bridge.cv_to_imgmsg(self.img_out_2))



	def background_subtraction(self, depth_cutoff):
		# Remove data beyond the specified distance. Colorize the output based on distance to the point.

		self.processing = 1
#		self.depth_raw = np.uint8(self.depth_raw)
		# Create a mask that only includes pixels less than a specificed distance away
		mask = np.logical_and(self.depth_raw < depth_cutoff, self.depth_raw > 0)

		depth_masked = self.depth_raw*mask
		max_depth = depth_masked.max()

		
		# Colorize output. Anything in the background is designated pure red.
		# The foreground transitions from blue to green depending on distance.
		self.rgb_mod[:,:,2] = np.invert(mask)*255					# Red
		self.rgb_mod[:,:,0] = depth_masked*(depth_cutoff/max_depth)			# Blue
		self.rgb_mod[:,:,1] = 255*mask - depth_masked*(depth_cutoff/max_depth)		# Green

		# Output this image
		# self.img_out_2 = self.rgb_mod

		self.processing = 0

		return self.rgb_mod



def main(args):
	#We must first initialize this file for the script to register in ROS
	rospy.init_node('kinect_template', anonymous=True)
	kinect = kinect_template()

	try:
		rospy.spin()
	except KeyboardInterrupt:
		print 'Closing...'

if __name__=='__main__':
	main(sys.argv)

