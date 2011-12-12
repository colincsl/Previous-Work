#!/usr/bin/env python

import roslib; roslib.load_manifest('kinect_analglyph')
import rospy
import sys
import cv
from cv_bridge import CvBridge, CvBridgeError
from sensor_msgs.msg import Image
from std_msgs.msg import String

class anaglyph():

	def __init__(self):
		self.pub = rospy.Publisher('analglyph', Image)
		self.sub_depth = rospy.Subscribe('/kinect/depth/image_raw', Image, self.cb_depth)
		self.sub_rgb = rospy.Subscribe('/kinect/rgb/image_raw', Image, self.cb_rgb)

		self.bridge = CvBridge()

		self.img_out = cv.CreateMat(480, 640, cv.CV_8UC3)
		self.img_depth = cv.CreateMat(480, 640, cv.CV_8UC1)
		self.img_r = cv.CreateMat(480, 640, cv.CV_8UC1)
		self.img_g = cv.CreateMat(480, 640, cv.CV_8UC1)
		self.img_b = cv.CreateMat(480, 640, cv.CV_8UC1)
		self.img_rgb = cv.CreateMat(480, 640, cv.CV_8UC3)

	def cb_depth(self, data):
		self.img_depth = self.bridge.imgmsg_to_cv(data)

	def cb_rgb(self, data):
		rgb = self.bridge.imgmsg_to_cv(data)
		cv.MixChannels([rgb], [self.img_b, self.img_g, self.img_r], [(0,0), (1,1), (2,2)])	

	def generate_output(self)
		cv.MixChannels([self.img_r, self.img_g, self.img_b], [self.img_out], [(0,0), (1,1), (2,2)])
		img = self.bridge.cv_to_imgmsg(self.img_out)
		self.pub.publish(img)	

	#def publish(self)



def main(args):
	rospy.init_node('gen_anaglyph', anonymous=True)
	an = anaglyph()
	try:
		rospy.spin()
	except KeyboardInterrupt:
		print "Closing..."


if __name__ == '__main__':
	main(sys.argv)

