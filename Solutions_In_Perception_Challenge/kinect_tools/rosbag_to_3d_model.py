#!/usr/bin/env python

working_dir = '/home/colin/repo/perception_repo/' # needed for importing kinect_tools
bag_dir = '/home/colin/sip_data/training_new/'

#Options
delete_pc_folder = 1
save_registered = 0
topic = 'points2' 

##Do batch convert
num_bags = 1#35
start_num = 1
bag_set = []

#for i in range(start_num, num_bags+start_num):
#	bag_set.append('object_%02i.bag'%i)

bag_dir='/home/colin/tod_stub_dev/tod_stub/bin/'
bag_set.append('obj16.bag')

#num_bags=1
#bag_set = []
#bag_set.append('test_01.bag')


#if bag_from_second_data_release:
#	topic = 'points'
#else:
#	topic = 'points2'


#print bag_set



''' Convert rosbag to output rgb+depth data


'''
import roslib; roslib.load_manifest('kinect_tools')
#import roslib; roslib.load_manifest('kinect_template')
import rospy
import rosbag
import numpy as np
import cv
import sys, os, shutil, time
import math
import string
from cv_bridge import CvBridge
from sensor_msgs.msg import Image, PointField, PointCloud2
import struct
from std_msgs.msg import String
#from sensor_msgs.msg import CameraInfo
import point_cloud
import cv_bridge
import scipy.io as sio #for saving to matlab file

import pdb

pub_img = rospy.Publisher('img_out', Image)
bridge = CvBridge()

#-----------------------------------------------------------------------------------------
class bag2model:

	pose = [] # Store 6 DOF pose: [x,y,z, r0, r1, r2]
	info = []

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
		
#-----------------------------------------------------------------------------------------		
#	def view_depth(self):
#		print 'start'
#		t0 = None		
#		for topic, msg, t in self.bag.read_messages():
#			print t
#			self.img = msg
#			if self.img != None:
#				self.pub_img.publish(self.img)
#		print 'end'		

#-----------------------------------------------------------------------------------------

	def next_depth(self, msg_generator):

		timer = time.time()

		try:
			_, cloud, ros_time = msg_generator.next()
		except:
			return
		frame = cloud.header.seq
		fmt = point_cloud._get_struct_fmt(cloud)
		width, height, point_step, row_step, data, isnan = cloud.width, cloud.height, cloud.point_step, cloud.row_step, cloud.data, math.isnan
		unpack_from = struct.Struct(fmt).unpack_from


		fmt_all = fmt+('4x4x4x'+fmt[1::])*(width*height-1)
		unpack_all_from = struct.Struct(fmt_all).unpack_from
		datum = unpack_all_from(data)

		pts_pos = np.array([datum[::4], datum[1::4], datum[2::4]], dtype='f4')
		pts_pos.transpose()
#		pts_pos = np.reshape(pts_pos, (pts_pos.shape[1], 3))
		
		pts_color_raw = np.array(datum[3::4], dtype = 'f4')
		pts_color_raw.dtype = np.uint8
		pts_color_raw = np.reshape(pts_color_raw, (width*height, 4))		
		pts_color = pts_color_raw[:,0:3]
		
		return pts_pos, pts_color, msg_generator, ros_time, frame
		
##-----------------------------------------------------------------------------------------

#	def save_registered(self, msg_generator):

#		timer = time.time()

#		try:
#			_, cloud, _ = msg_generator.next()
#		except:
#			return

#		fmt = point_cloud._get_struct_fmt(cloud)
#		width, height, point_step, row_step, data, isnan = cloud.width, cloud.height, cloud.point_step, cloud.row_step, cloud.data, math.isnan
#		unpack_from = struct.Struct(fmt).unpack_from


#		fmt_all = fmt+('4x4x4x'+fmt[1::])*(width*height-1)
#		unpack_all_from = struct.Struct(fmt_all).unpack_from
#		datum = unpack_all_from(data)

#		pts_pos = np.array([datum[::4], datum[1::4], datum[2::4]], dtype='f4')
#		pts_pos.transpose()
##		pts_pos = np.reshape(pts_pos, (pts_pos.shape[1], 3))
#		
#		pts_color_raw = np.array(datum[3::4], dtype = 'f4')
#		pts_color_raw.dtype = np.uint8
#		pts_color_raw = np.reshape(pts_color_raw, (width*height, 4))		
#		pts_color = pts_color_raw[:,0:3]
#		
#		
#		
#		return pts_pos, pts_color, msg_generator
		
#-----------------------------------------------------------------------------------------		
	def next_pose(self, msg_generator):
		try:
			_, new_pose, _ = msg_generator.next()
		except:
			return
			
		pose_formatted = new_pose.tvec[0],new_pose.tvec[1],new_pose.tvec[2], new_pose.rvec[0], new_pose.rvec[1], new_pose.rvec[2]

#		self.pose.append(pose_formatted)
		self.pose = pose_formatted
		print self.pose
		
		return msg_generator
#-----------------------------------------------------------------------------------------		
		
	def camera_info(self, msg_generator):
		try:
			_, info, time = msg_generator.next()
		except:
			return
			
		self.info = {'time':time.to_time(), 'height':info.height, 'width':info.width, 'D':info.D, 'K':info.K, 'R':info.R, 'P':info.P}
		
		return
		
#-----------------------------------------------------------------------------------------		
		
	def pts2img(self, pts_pos, pts_color):

		self.img_pos = np.empty((480,640, 3), 'f4')
#		self.img_color = np.empty((480,640, 3), 'u1')	

		self.img_color = np.reshape(pts_color, (480, 640, 3))
		
#		img_pos = np.reshape(pts_pos, (480, 640, 3))
		for i in range(3):
			self.img_pos[:,:,i]  = np.reshape(pts_pos[i,:], (480, 640))

#		print '%d ms to read %d points' % ((time.time() - timer))# * 1000, width * height)				

		min_ = np.nanmin(pts_pos)
		max_ = np.nanmax(pts_pos)
		scale = 255 / (max_-min_)
		self.img_pos -= min_
		self.img_pos *= scale
		
		cv.SaveImage('/home/colin/Desktop/rosbag_img_color.jpg', np.uint8(self.img_color.copy()))
		cv.SaveImage('/home/colin/Desktop/rosbag_img_depth.jpg', np.uint8(self.img_pos))		

		return self.img_pos, self.img_color

#-----------------------------------------------------------------------------------------

	def save_pts(self, pts_pos, pts_color, bag_name, file_prefix='pc', out_folder=[]):
		cloud = np.zeros(max(pts_pos.shape), dtype=[('x', 'f4'), ('y', 'f4'), ('z', 'f4'),('r', 'u1'),('g', 'u1'),('b', 'u1')])
#		pdb.set_trace()
		cloud['x'] = pts_pos[0,:]
		cloud['y'] = pts_pos[1,:]
		cloud['z'] = pts_pos[2,:]
		cloud['r'] = pts_color[:,0]
		cloud['g'] = pts_color[:,1]
		cloud['b'] = pts_color[:,2]	
		
		t = int(time.time())
		print bag_name
		if out_folder==[]:
			out_folder = bag_dir + 'pointclouds_' + bag_name[0:bag_name.find('.bag')] + '/'
		out_filename = out_folder + file_prefix +"_" + str(t)
		print out_filename

		if not os.access(out_folder, os.W_OK):
			os.mkdir(out_folder)
			
#		pdb.set_trace()
		
		#testing savemat using {'test':1} works. the cloud variable seems to have 	
		try:
			obj_dictionary = {'pointcloud':cloud, 'pose':self.pose, 'info':self.info}
			np.savez(out_filename, **obj_dictionary)

			obj2_dict = {"depth":self.img_pos, "color":self.img_color}
			try:
				obj2_dict['pose'] = self.pose[len(self.pose)-1]
			except:
				pass
			try:
				obj2_dict['info'] = self.info
			except:
				pass
		except:
			pass
			
#		sio.savemat(out_filename, {'pose':self.pose, 'info':self.info}, oned_as='row')
#		sio.savemat(out_filename, obj2_dict, oned_as='row')
		np.save(out_filename, cloud)
#-----------------------------------------------------------------------------------------		
		
		
	def combine_clouds_from_files(self):
		#walk through the point cloud folder and merge all of the point clouds into 1 datastructure
		folder = bag_dir
#		folder = bag_dir + 'pointclouds_' + bag_name[0:bag_name.find('.bag')] + '/'		
#		'/home/colin/sip_data/training/pointclouds_arm_hammer'

		dirs = os.walk(folder)
		
		root = []
		folders = []
		files = []
		good_file = []
		
		for i in dirs:
			root.append(i[0])
			folders.append(i[1])
			files.append(i[2])
		
		for i in range(len(root)):
#			for j in range(len(folders)):
			if root[i].find("pointclouds_"):
				for j in range(len(files[i])):
					if files[i][j].find(".np")>-1: #check if it is the correct datatype
						if files[i][j].find("combined")>-1:
#							print "Folder %s already combined" % root[i]
							break
						elif files[i][j].find("pc_")>-1:
							good_file.append(root[i]+'/'+files[i][j])			
	#			print good_file
			
			
				file_count = len(good_file)

				if file_count > 0:
					time = []			
					for j in range(file_count):
						t_start_ind = good_file[j].find('pc_')+3
						t_end_ind = good_file[j].find('.npy')				
						time.append(int(good_file[j][t_start_ind:t_end_ind]))
				
					sorted_time_ind = np.argsort(time)
					time = np.sort(time)

					cloud = np.zeros((file_count, 640*480), dtype=[('x', 'f4'), ('y', 'f4'), ('z', 'f4'),('r', 'u1'),('g', 'u1'),('b', 'u1')])							
					for j in range(file_count):				
						data = np.load(good_file[j])
						cloud[sorted_time_ind[j], :] = data

					np.savez(root[i]+'/combined', cloud, time)
				
				
				
		
	#TODO
#	def batch_convert_to_numpy(self):
	
		
		





def main(args):
	rospy.init_node('bag2model_convertor', anonymous=True)
	
	for i_files in range(len(bag_set)):
		bag_name = bag_set[i_files]
		filename = bag_dir + bag_name
		bag = bag2model( filename )
	
		num_imgs = 40
		img = np.empty((480, 640, num_imgs), dtype=np.float32)
		img_diff = np.empty((480, 640), dtype=np.float32)
	
		msg_cloud = bag.bag.read_messages(topics=topic)
		
		if save_registered == 1:
			msg_reg = bag.bag.read_messages(topics='points_registered')
		
		msg_pose = bag.bag.read_messages(topics='pose')
		msg_camera = bag.bag.read_messages(topics='camera_info')		
	

		#Remove old pointcloud files
		if delete_pc_folder:
			out_folder = bag_dir + 'pointclouds_' + bag_name[0:bag_name.find('.bag')] + '/'
			if os.access(out_folder, os.W_OK):
				shutil.rmtree(out_folder); 


		# while...throw ? (to use all msgs in bag)
		msg_count = 0
	#	for i in range(num_imgs):
	#	for i in range(4):	
		bag.camera_info(msg_camera)
		
		try:
			while 1:	

				timer = time.time()
#				pdb.set_trace()				
				pts_pos, pts_color, msg_cloud, _ = bag.next_depth(msg_cloud)
				msg = bag.next_pose(msg_pose)
				img_pos, img_color = bag.pts2img(pts_pos, pts_color)
				bag.save_pts(pts_pos, pts_color, bag_name)	
				if save_registered == 1:
					pts_pos_reg, pts_color_reg, msg_reg = bag.next_depth(msg_reg)
					bag.save_pts(pts_pos_reg, pts_color_reg, bag_name, 'reg')
		#		max_depth = np.nanmax(img[:,:,i])
		#		min_depth = np.nanmin(img[:,:,i])	
		#		print (max_depth - min_depth)		
		#		scale = 255.0/(max_depth - min_depth)
		#		img[:,:,i] = (img[:,:,i]-min_depth)*scale		
		#		img[:,:,i] = bag.next_depth()
		#		print img[:,:,i]
				pub_img.publish(bag.bridge.cv_to_imgmsg(np.array(np.uint8(img_color))))		
		#		pub_img.publish(bag.bridge.cv_to_imgmsg(np.uint8(img[:,:,i]*100)))		
				msg_count += 1
				print "Time per message: ", str(round(time.time()-timer))
		except:
			print "Finished processing all %i pointcloud messages in the rosbag" % msg_count
		
	#	max_depth = np.nanmax(img[:,:,i])
	#	min_depth = np.nanmin(img[:,:,i])	
	#	scale = 255/(max_depth - min_depth)
	
	#	img_diff = np.logical_and(img[:,:,i], img[:,:,0])
	#	for i in range(num_imgs):
	#		img[:,:,i] = np.uint8((img[:,:,i]-min_depth)*scale)

	#	print img[:,:,i]
	#	pdb.set_trace()
	#	img_diff = img[:,:,0]
	#	for i in range(8, num_imgs-1, 12):
	#		img_diff = (img[:,:,i] - img_diff < 50)*img_diff
	#	img_diff = np.logical_and(img[:,:,num_imgs-1], img[:,:,0])
	#	img_diff = img[:,:,num_imgs-1] - img[:,:,0]	
	#	print img_diff[200:210, 200:205]
	#	pub_img.publish(bag.bridge.cv_to_imgmsg(np.uint8(((img_diff ==0) * img[:,:,num_imgs-1]))))
	#	print img_diff


		bag.combine_clouds_from_files()
		print "Finished combining" + filename
	
	try:
		rospy.spin()
	except KeyboardInterrupt:
		'Closing'


if __name__ == "__main__":
#	print sys.argv
	main(sys.argv)
