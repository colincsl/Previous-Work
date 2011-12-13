
'''
Overview:
*input: Nx6 dense pointcloud
*use read_groundtruth() to get plane
	-transform 3 points to get plane...
	- set everything below and behind as NaN or black
*form image
*run SIFT on remaining pixels 

TODO: Why is the z value in 'accept_z' -.65. Shouldn't it be 0?

TODO: problem - can't load sift from another folder
Answer: load from that folder intead of using './sift'
'''

import sys, os,time
import numpy as np
from numpy.linalg import svd
import scipy.misc as sm
import sift

#import mrol_mapping.mapper as mapper
#import mrol_mapping.mrol as mrol
import mrol_mapping.poseutil as poseutil
import mrol_mapping.pointcloud as pointcloud

#import read_groundtruth as truth

import pdb

class trainingFeatureExtractor:

	def __init__(self,objectID,pose_T, pointcloud=None, filename=None):
		#pointcloud should be Nx6
		self.name = objectID
		self.truth_T = pose_T
		self.pc = []
		if pointcloud == None and fileame != None:
			self.pc = self.load_data(filename)
		else:
			self.pc = pointcloud

		self.run()
		
	
	def load_data(self,input_file):
#		if input_file == None:
#			input_file = '/home/colin/sip_data/training_new/pointclouds_obj16/pc_1302023598.npy'
#		#	input_file = '/home/colin/sip_data/training_new/pointclouds_obj16/pc_1302023524.npy'	
#		#	input_file = '/home/colin/repo/perception_repo/data/obj16_best.npy'	
		return np.load(input_file)
		
	def run(self):
		self.extract_pc()
		self.extract_texture()
		
	def get_ROI(self):
		return self.pc_ROI
	
	def extract_pc(self):
#		pc_range = np.array([self.pc['x'],self.pc['y'], self.pc['z']]) 
#		pc_color = np.array([self.pc['r'],self.pc['g'], self.pc['b']]) 
		pc_range = np.array([self.pc[:,0],self.pc[:,1], self.pc[:,2]]) 
		pc_color = np.array([self.pc[:,3],self.pc[:,4], self.pc[:,5]])

		# Get Transform from local to sesor
		pc = poseutil.transformPoints(pc_range.T, self.truth_T)


		# Filters out data outside of the region of interest
		accept = (pc[:,2]>0.01) * (np.abs(pc[:,0]) < .2)* (np.abs(pc[:,1]) < .2)

		pos_vec = pc.T * accept		
		color_vec = pc_color * accept

		self.img_pos = np.reshape(pos_vec.T, (480, 640, 3))
		self.img_color = np.reshape(color_vec.T, (480, 640, 3))

		
		pc_tmp = np.sum(pc_range, axis=0)
		ROI_ind = np.nonzero(-np.isnan(pc_tmp))[0]
		self.pc_ROI = np.empty((ROI_ind.shape[0], 6))
		self.pc_ROI[:,:3] = pos_vec[:,ROI_ind].T
		self.pc_ROI[:,3:6] = color_vec[:,ROI_ind].T


	def display(self):
		import pylab as pl
		pl.imshow(self.img_pos[:,:,2])
		#pl.imshow(img)
		pl.show()
		
		
	def extract_texture(self):
		im = sm.toimage(self.img_color[:,:,0])
		baseDir = sys.argv[0][0:sys.argv[0].rfind('/')+1]
		imageName = baseDir+'data/'+self.name+'/tmp_sift_img.pgm'
		im.save(imageName)
#		im.save('sift/tmp_sift_img.pgm')		
		outputName = baseDir+'data/'+self.name+'/'+self.name+'_sift'
		outputName_tmp = baseDir+'data/'+self.name+'/'+self.name+'_sift_tmp'	
		os.system(baseDir+"sift/sift <"+imageName+">"+outputName_tmp)
#		sift.process_image(imagename, 'tmp_features')
		self.match_keys(outputName_tmp, outputName)
		self.append_sift(outputName_tmp, outputName)

	def append_sift(self, inputFile, outputFile):
#		pdb.set_trace()
		tmpFile = file(inputFile, 'r')
		
		try:
			outFile = file(outputFile, 'r')
			out_L1 =  outFile.readline().split()	
			out_count = int(out_L1[0])
			out_text = outFile.read()
		except:
			out_count = 0
			out_L1 = [out_count, 128]
			out_text = [] #''
		
		tmp_L1 =  tmpFile.readline().split()
		tmp_count = int(tmp_L1[0])
		
		new_count = tmp_count+out_count		#get total number of descriptors
		assert int(tmp_L1[1]) == int(out_L1[1])
		common_num = int(tmp_L1[1])

		tmp_text = tmpFile.read()
		
		newFile = file(outputFile, 'w')
		newFile.write(str(new_count) + ' ' + str(common_num) + '\n')
		if len(out_text) > 0:
			newFile.write(out_text)
		newFile.write(tmp_text)
		
		
	def match_keys(self, sceneFile, modelFile):
		sceneFeat = sift.read_features_from_file(sceneFile)[1]
		
		try:
			modelFeat = sift.read_features_from_file(modelFile)[1]
		except:
			return
		
		desc1=sceneFeat
		desc2=modelFeat
		
#		pdb.set_trace()			
		
#		t1=time.time()
		dist_ratio=.6
		desc1_shape = desc1.shape[0]
		
		matchscores=np.zeros(desc1_shape)
		
		dotProds = np.dot(desc1,desc2.T)
		dotProds *=.9999
		
		acos_dots= np.arccos(dotProds)
		indx = np.argsort(acos_dots,axis=1)
		
		range_ind = range(desc1_shape)
#		sig_keys = np.array(acos_dots[0,indx[:,0]] < dist_ratio * acos_dots[0,indx[:,1]])
		sig_keys = np.array(acos_dots[range_ind,indx[:,0]] < dist_ratio * acos_dots[range_ind,indx[:,1]])
		sig_keys_ind = np.nonzero(sig_keys)[0]
		matchscores[sig_keys_ind] = indx[sig_keys_ind,0]
#		print 'T1:',time.time()-t1
#		t2=time.time()
#		other=sift.match(desc1,desc2)
#		print 'T2:',time.time()-t2		
#		pdb.set_trace()

		return matchscores
		
		
		
		
		
		
		

	def display_features(self):
		feat = sift.read_features_from_file('data/'+self.name+'/'+self.name+'_sift')
		sift.plot_features(self.img_color, feat[0])


#if __name__ == "__main__":
#	fe = trainingFeatureExtractor('ObjectTmp')
#	fe.display_features()
#	fe.display()	
	


