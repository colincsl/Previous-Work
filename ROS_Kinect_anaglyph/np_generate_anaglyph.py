#!/usr/bin/env python

import roslib; roslib.load_manifest('kinect_anaglyph')
import rospy
import sys
import cv
import time
import numpy as np
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
from std_msgs.msg import String

class anaglyph:

	def __init__(self):
		self.pub_img = rospy.Publisher('anaglyph_img', Image)
		self.sub_depth = rospy.Subscriber('/kinect/depth/image_raw', Image, self.subscribe_callback,queue_size=1)
		self.sub_rgb = rospy.Subscriber('/kinect/rgb/image_raw', Image, self.subscribe_callback,queue_size=1)

		self.bridge = CvBridge()

		self.img_anaglyph = np.zeros((480, 640, 3), dtype=np.uint8)
		self.img_rgb = np.zeros((480, 640, 3), dtype=np.uint8)

		self.depth = np.zeros((480, 640), dtype=np.uint8)
		self.img_depth = np.zeros((480, 640), dtype=np.uint8)
#		self.r_offset  = np.zeros((480, 640), dtype=np.uint8)
#		self.g_offset  = np.zeros((480, 640), dtype=np.uint8)
#		self.b_offset  = np.zeros((480, 640), dtype=np.uint8)

		# Store offsets for green/magenta channels in one matrix
		self.offset_indices = np.zeros((480, 640, 2), dtype=np.uint16)

		self.index_basis_x = np.zeros((480, 640), dtype=np.uint16)
		self.index_basis_y = np.zeros((480, 640), dtype=np.uint16)

		# Store index base for x and y dimensions -- used to vectorize anaglyph operations
		for i in range(0, 640):
			self.index_basis_y[:,i] = i

		for i in range(0, 480):
			self.index_basis_x[i,:] = i

		self.processing = 0

		self.current_depth_time = time.time()
		self.current_rgb_time = time.time()


		self.timer_1 = time.time()
		self.timer_2 = time.time()

		self.rotation = np.array([[ 0.999979, 0.006497, -0.000801], 
					[-0.006498, 0.999978, -0.001054],
					[0.000794, 0.001059, 0.999999 ]])

#		self.transform = np.array([[526.6, 3.752, -201.2, 1.604e+04], 
#					[-3.215, 526.6, -14.29, 2.429e+04],  
#					[0.000794, 0.001059, -0.05648, 584.5]])

		print 'Done initializing'


	def subscribe_callback(self, data):
		# Assign incoming Kinect images to depth/rgb images and process data

		#Block data if it is currently being processed
		if self.processing == 0:

			#Incoming data:
			#Depth
			if data.encoding == 'mono8':
				depth = np.asarray(self.bridge.imgmsg_to_cv(data))
				self.img_depth = np.asarray(self.bridge.imgmsg_to_cv(data))
				self.current_depth_time = time.time()
			#RGB
			elif data.encoding == 'rgb8':
				self.img_rgb = np.asarray(self.bridge.imgmsg_to_cv(data))
				self.current_rgb_time = time.time()

			#If depth+rgb are both updated generate new anaglyph and publish output
			if np.abs(self.current_depth_time - self.current_rgb_time) < 0.1:
				self.generate_anaglyph()
#				self.pub_img.publish( self.bridge.cv_to_imgmsg(self.img_depth))
				self.pub_img.publish( self.bridge.cv_to_imgmsg(self.img_anaglyph))


	def generate_anaglyph(self):
		self.processing = 1
		timer = time.time()

#		mask = (self.img_depth > 0) & (self.img_depth < 255)
		mask = np.logical_and((self.img_depth > 0), (self.img_depth < 255))
#		self.depth = (5 - (self.img_depth*mask/4))*mask
		mod_depth = 2.5
		max_depth = (self.img_depth*mask).max()/mod_depth
		self.depth = (max_depth -(self.img_depth/mod_depth)) * mask
#		self.depth = np.maximum( (max_depth -(self.img_depth/mod_depth)) , 0) * mask

#		print 'Min depth: ' + str(self.depth.min())
#		print 'Max depth: ' + str(self.depth.max())
#		print 'Min depth: ' + str((self.img_depth*mask).min())
#		print 'Max depth: ' + str((self.img_depth*mask).max())

		# Find length to prevent indices from being higher than the image resolution
		max_length = self.img_rgb.shape[1]-1

		#Find offset green/magenta indices for new image (based on depth)
#		Green		
		self.offset_indices[:,:,0] = np.maximum(np.minimum(self.index_basis_y + self.depth, max_length), 0)
#		Magenta
		self.offset_indices[:,:,1] = np.maximum(np.minimum(self.index_basis_y - self.depth, max_length), 0)

		#Do lookup based on offset indices
		self.img_anaglyph[:,:,0] = self.img_rgb[self.index_basis_x, self.offset_indices[:,:,1], 2] #red
		self.img_anaglyph[:,:,2] = self.img_rgb[self.index_basis_x, self.offset_indices[:,:,1], 0] #blue
		self.img_anaglyph[:,:,1] = self.img_rgb[self.index_basis_x, self.offset_indices[:,:,0], 1] #green
#		self.r_offset = self.img_rgb[self.index_basis_x, self.offset_indices[:,:,1], 2] #red
#		self.b_offset = self.img_rgb[self.index_basis_x, self.offset_indices[:,:,1], 0] #blue
#		self.g_offset = self.img_rgb[self.index_basis_x, self.offset_indices[:,:,0], 1] #green


		print 'Framerate: ' + str(int(1/(time.time() - timer)))

#		cv.MixChannels([self.r_offset, self.g_offset, self.b_offset], [self.img_anaglyph], [(0,0), (1,1), (2,2)])

		self.processing = 0


def main(args):
	rospy.init_node('generate_anaglyph', anonymous=True)
	an = anaglyph()
	try:
		#an.generate_output()
		rospy.spin()
	except KeyboardInterrupt:
		print "Closing..."


if __name__ == '__main__':
	main(sys.argv)

