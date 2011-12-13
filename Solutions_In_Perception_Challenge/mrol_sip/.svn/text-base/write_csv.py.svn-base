'''
Entry into the Solutions In Perception Challenge, 2011
University at Buffalo - Team Franklin
Authors: Colin Lea, Julian Ryde, Nick Hillier
Contact: colincsl@gmail.com

This is used by the detector to output CSV files with object positions/identities.
'''

import csv
import numpy as np
import time

class write2csv:

	def __init__(self,filename, run=0):
		self.fid = csv.writer(open(filename, 'wb'), delimiter=',')
		self.run = run
		self.insert_header()
		
		
	def insert_header(self):
		header = ["Ts", "Run", "Frame", "dID", "oID", "R11", "R12", "R13", "R21", "R22", "R23", "R31", "R32", "R33", "Tx", "Ty", "Tz"]
		self.fid.writerow(header)
		
	def write_data(self, data):
		# data is a dictionary with elements time, frame, dID, oID, R (3x3), T (3x1)
		
		rot_write = np.reshape(data['R'], 9)
#		print rot_write
		
		data_write = []
		data_write.append(data['time'])
		data_write.append(self.run)
		data_write.append(data['frame'])
		data_write.append(data['dID'])
		data_write.append(data['oID'])
	
		for i in range(9):
			data_write.append((rot_write[i]))
			
		trans = data['T']
		for i in range(3):
			data_write.append(trans[i])		
			
		self.fid.writerow(data_write)

if __name__ == "__main__":
	
	#Filename: RUN<run ID> <Team Name> <yyyy><mm><dd> <HH:MM: SS>.csv
	runID = 0
	teamName = 'teamFranklin'
	time_ = time.gmtime()
	filename = 'RUN'+ '%04i' %runID + "_" + teamName + "_" +  '%4i%02i%02i' %(time_[0], time_[1], time_[2]) +"_" + '%02i'%time_[3] + ':' + '%02i'%time_[4] +':'+ '%02i'%time_[5] + '.csv'
	tmp_writer = write2csv('data/'+filename, run='%03i'%0)
	tmp_writer.insert_header()
	
	t = '10.22.34.046'
	frame = '%04i' %100
	dID=0
	oID='cylinder'
	R = np.array([[1,2,3],[4,5,6],[7,8,9]])
	trans = np.array([-1,-2,-3])
	
	out = {'time':t, 'frame':frame, 'dID':dID, 'oID':oID, 'R':R, 'T':trans}
	tmp_writer.write_data(out)
	
