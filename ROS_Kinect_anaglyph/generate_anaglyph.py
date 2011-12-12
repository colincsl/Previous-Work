#!/usr/bin/env python

import roslib; roslib.load_manifest('kinect_anaglyph')
import rospy
import sys
import cv
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
from std_msgs.msg import String

class anaglyph:

	def __init__(self):
		self.pub = rospy.Publisher('anaglyph_img', Image)
		self.sub_depth = rospy.Subscriber('/kinect/depth/image_raw', Image, self.cb_depth)
		self.sub_rgb = rospy.Subscriber('/kinect/rgb/image_raw', Image, self.cb_rgb)

		self.bridge = CvBridge()

		self.img_out = cv.CreateMat(480, 640, cv.CV_8UC3)
		self.img_depth = cv.CreateMat(480, 640, cv.CV_8UC1)
		self.img_r = cv.CreateMat(480, 640, cv.CV_8UC1)
		self.img_g = cv.CreateMat(480, 640, cv.CV_8UC1)
		self.img_b = cv.CreateMat(480, 640, cv.CV_8UC1)
		self.img_rgb = cv.CreateMat(480, 640, cv.CV_8UC3)

		self.r_offset = cv.CreateMat(480, 640, cv.CV_8UC1)
		self.g_offset = cv.CreateMat(480, 640, cv.CV_8UC1)
		self.b_offset = cv.CreateMat(480, 640, cv.CV_8UC1)


	def cb_depth(self, data):
		self.img_depth = self.bridge.imgmsg_to_cv(data)

	def cb_rgb(self, data):
		rgb = self.bridge.imgmsg_to_cv(data)
		cv.MixChannels([rgb], [self.img_b, self.img_g, self.img_r], [(0,0), (1,1), (2,2)])	

		self.generate_output()

	def generate_output(self):
		cv.Copy(self.img_r, self.r_offset)
		cv.Copy(self.img_b, self.b_offset)
		cv.Copy(self.img_g, self.g_offset)
		
		for i in range (self.img_r.height-1):
			for j in range (self.img_r.width-1):
				if self.img_depth[i,j] < 255 and self.img_depth[i,j] >= 0:
					disp = int(round(self.img_depth[i,j]/5))
					print disp
					if j-disp > 0 and j-disp < self.img_r.width-1:

						self.r_offset[i,j] = self.img_r[i, j-disp]
						#self.r_offset[i,j-disp] = self.img_r[i, j]
						#self.b_offset[i,j-disp] = self.img_b[i, j]
						self.b_offset[i,j] = self.img_b[i, j-disp]
					if j+disp > 0 and j+disp < self.img_b.width-1:	
						#self.g_offset[i,j+disp] = self.img_g[i, j]
						self.g_offset[i,j] = self.img_g[i, j+disp]

		cv.MixChannels([self.r_offset, self.g_offset, self.b_offset], [self.img_out], [(0,0), (1,1), (2,2)])
		#cv.MixChannels([r_offset, self.img_g, self.img_b], [self.img_out], [(0,0), (1,1), (2,2)])
		img = self.bridge.cv_to_imgmsg(self.img_out)
		self.pub.publish(img)	

	#def publish(self)



def main(args):
	rospy.init_node('generate_anaglyph', anonymous=True)
	an = anaglyph()
	try:
		rospy.spin()
	except KeyboardInterrupt:
		print "Closing..."


if __name__ == '__main__':
	main(sys.argv)

