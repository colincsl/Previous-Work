#!/usr/bin/env python

working_dir = '/home/colin/repo/perception_repo/' # needed to import kinect_tools
#bag_name = 'blue_bowl_test.bag'
bag_name = 't0026.bag'

''' Convert rosbag to output rgb+depth data


'''

import roslib; roslib.load_manifest('kinect_template')
import rospy
import rosbag
import numpy as np
import cv
import sys
import os
import time
import string
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
from std_msgs.msg import String
#from sensor_msgs.msg import CameraInfo
from sensor_msgs.msg import PointCloud2

import point_cloud
import struct
import pdb

class bag2data:

	def __init__(self, filename):
		print filename
		try:
			self.bag = rosbag.Bag(filename, 'r')
		except rosbag.bag.ROSBagUnindexedException:
			print 't'		
			self.bag = rosbag.Bag(filename, 'w', allow_unindexed=True)
			print 't2'			
			self.bag.reindex()
#			self.bag.close()
#			self.bag = rosbag.Bag(filename, 'r', allow_unindexed=False)
			print 'Bag reindexed'
			
			
		self.pub_img = rospy.Publisher('img_out', Image)
		self.img = None
		
		self.bridge = CvBridge()
		
		
	def view_depth(self):
		print 'start'
		t0 = None		
		for topic, msg, t in self.bag.read_messages():
			print t
			self.img = msg
			if self.img != None:
				self.pub_img.publish(self.img)
		print 'end'		


	def convert(self):
	
		#Make a directory in .../kinect_tools/output/TIME to put the images
		out_dir_ext = time.ctime() #name output folder by time
		output_dir = working_dir + 'kinect_tools/output/' + out_dir_ext + '/'
		os.mkdir(output_dir)		
		self.output_dir = output_dir		
		
		topic_list = []
		topic_frame = [0]
		i_frame = 0
	
		#Go through all of the messages in the bag
		for topic, msg, t in self.bag.read_messages():
			i_num = 0
			img_num = None
			
			#Check which image it is (ie rgb or depth). Title the image differently dependend on name. Output is .../kinect_tools/output/TIME/imgNUM_FRAME.jpg
			# NUM is the topic index and FRAME is the message number
			for i_topic in topic_list:
				if topic == i_topic:
					img_num = i_num
					i_frame = topic_frame[i_num]
					break
				else:
					i_num+=1
					
					
					
			if img_num == None:
				topic_list.append(topic)
				topic_frame.append(0)
				img_num = i_num
				i_frame = topic_frame[img_num]
				print topic_list
			
			try:
				self.img = np.array(self.bridge.imgmsg_to_cv(msg))
			except:
				print 'Recieved non-image message!'
			
			if self.img != None: 
				filename = output_dir + 'img' + str(img_num) + '_' + str(topic_frame[img_num]) + '.jpg'		
				print filename
				try:
					if img_num == 1:
						self.img = self.img*60
					cv.SaveImage(filename, self.img)
				except:
					'print error!!!!!!!!'
				self.pub_img.publish(self.bridge.cv_to_imgmsg( self.img ))
				topic_frame[img_num] += 1
#				i_frame += 1
#				print 'Output frame: ' + str(i_frame-1)
#				print 'Output frame: ' + str(topic_frame[img_num])		
				
#				time.sleep(1)	

				
		print 'Done converting'		



	def convert_3D(self):
	
		#Make a directory in .../kinect_tools/output/TIME to put the images
		out_dir_ext = time.ctime() #name output folder by time
		output_dir = working_dir + 'kinect_tools/output/' + out_dir_ext + '/'
		os.mkdir(output_dir)
		self.output_dir = output_dir				
		
		print "Output_dir: " + str(output_dir)
			
		msg_generator  = self.bag.read_messages(topics=('/camera/depth/points2', '/camera/rgb/image_color'))
		
		
		color_index = 0
		depth_index = 0
		
		
		while 1:
#			pdb.set_trace()
#			try:
			topic, msg, t = msg_generator.next()			
			print topic
			if topic == '/camera/depth/points2':
				self.save_depth_img(msg, depth_index)
				self.save_color_img(msg, color_index)									
				depth_index += 1				
			else:
#					self.save_color_img(msg, color_index)												
				color_index +=1
#			except:
#				print 'Done saving images'
#				break
		
				
				
	def save_depth_img(self, msg, img_num):
		img = np.empty((480,640), dtype=np.float32)
		pts = []
		
#		print msg.fields
		for p in point_cloud.read_points(msg):
			pts.append(p[2])
			
		img = np.reshape(pts, (480, 640))				
		max_px = np.nanmax(img)
		min_px = np.nanmin(img)
		scale = int(255 / (max_px-min_px))
		filename = self.output_dir + 'img_depth_' + str(img_num) + '.jpg'		
		cv.SaveImage(filename, img*scale)
	
	def save_color_img(self, msg, img_num):
	
		img = np.empty((480,640), dtype=np.float32)
		pts = []
		
#		print msg.fields
		for p in point_cloud.read_points(msg):
#			print len(p)
#			pts.append(p[3])
			x=1
		print 0
		print p[3]
		x = struct.pack('f', p[3])
		print x	
			
		img = np.reshape(pts, (480, 640))				
#		max_px = np.nanmax(img)
#		min_px = np.nanmin(img)
#		scale = int(255 / (max_px-min_px))
		filename = self.output_dir + 'img_color_' + str(img_num) + '.jpg'		
		cv.SaveImage(filename, np.uint8(img))	
	
	
#	
#		img = np.array(self.bridge.imgmsg_to_cv(msg))	
#		cv.CvtColor(img, img, cv.CV_BGR2RGB)
#		max_px = np.nanmax(img)
#		min_px = np.nanmin(img)
#		scale = int(255 / (max_px-min_px))
#		filename = self.output_dir + 'img_color_' + str(img_num) + '.jpg'		
#		cv.SaveImage(filename, img*scale)

		

	#		pub_img.publish(self.bridge.cv_to_imgmsg(np.uint8(img*100)))		
						



def main(args):
	rospy.init_node('bag_convertor', anonymous=True)
	filename = working_dir + 'kinect_tools/output/' + bag_name
	bag = bag2data( filename )
	
	bag.convert_3D()
		
	
#	bag.convert()
	
	try:
		rospy.spin()
	except KeyboardInterrupt:
		'Closing'


if __name__ == "__main__":
#	print sys.argv
	main(sys.argv)
