#!/usr/bin/env/ python

#from system import echo
import sys, os
#from scipy import*
from numpy import*
sys.path.append('/Users/Colin/Desktop/backup/CLEA/SkillTransfer/libsvm-3.0/')
sys.path.append('/Users/Colin/Desktop/backup/CLEA/SkillTransfer/libsvm-3.0/python')
sys.path.append('/Users/Colin/Desktop/backup/CLEA/SkillTransfer/libsvm-3.0/tools')
#from svmutil import*
# from pylab import*
#import pylab as plot
#import mpl_toolkits.mplot3d.axes3d as Axes3D
#zimport time

#os.system("echo Input size: "+ str(len(sys.argv)))



#Data format
#TIME POSITION ORIENTATION VELOCITY BUTTONS FORCE TORQUE RAW_POSITION RAW_ORIENTATION RAW_VELOCITY

class fileIn:
# 	time = []
# 	pos = 3*[]
# 	orn = 4*[]
# 	vel = 3*[]	
# 	but = 3*[]
	fname = ''

	def __init__(self, arg):
		self.fname = arg
		self.fin = file(self.fname, 'r')
		
	def readHeader(self):
		header = self.fin.readline()
#		os.system("echo " + header)
		return 
		
	def readData(self):
		txt = self.fin.readline()
		data = txt
		print data
		return txt
		
	def readAllData(self):
		time = []
		pos = 3*[]
		orn = 4*[]
		vel = 3*[]	
		but = 3*[]		

		for line in self.fin:
			data = line.split()
			time.append(float(data[0]))
			pos.append([ float(data[1]), float(data[2]), float(data[3]) ])
			orn.append([ float(data[4]), float(data[5]), float(data[6]), float(data[7]) ])
			vel.append([ float(data[8]), float(data[9]), float(data[10]) ])	
			but.append([ float(data[11]), float(data[12]), float(data[13]) ])
		
		self.time = array(time)
		self.pos = array(pos)
		self.orn = array(orn)
		self.vel = array(vel)
		self.but = array(but)
	
############################
	

############## SVM ################

class falcon_svr:
	def __init__(self, data):
		self.data = data
		self.data.readHeader()
		self.data.readAllData()

	def compute_svr(self):
		#svm_train(data.pos[:,1], data.time, '-s 4')
		#file_out = open('svr_tmp.txt', 'w')
		# file_out.write(str(self.data.pos[:,1:3]))
		savetxt('svr_pos', self.data.pos)
		savetxt('svr_time', self.data.time)
		os.system("echo " + str(self.data.pos.shape))
		os.system("python libsvm-3.0/tools/easy.py " + str(self.data.pos[1,:]))




########### Main ############


if len(sys.argv) > 0:
	os.system("echo Inputs:")
	#for a in sys.argv:
	#os.system("echo "+ str(a))
	filename = sys.argv[1]
else:
	os.system("No args provided")


os.system("echo Input size: "+ str(len(sys.argv)))


data = fileIn(filename)
fal = falcon_svr(data)
os.system("echo " + filename)
fal.compute_svr()
#f.readHeader()
# text = f.readAllData()
# x = array(f.pos)



# if '__name__' == '__main__':
# 	os.system("echo Input size: "+ str(len(sys.argv)))
# 
# 	if len(sys.argv) > 0:
# 		os.system("echo Inputs:")
# 		#for a in sys.argv:
# 		#os.system("echo "+ str(a))
# 		filename = sys.argv[1]
# 	else:
# 		os.system("echo error")
# 		print 'no arguments provided'
# 
# 
# 
# 	os.system("echo Input size: "+ str(len(sys.argv)))
# 
# 
# 	os.system('echo 0')
# 	data = fileIn(filename)
# 	os.system("echo 1")
# 	fal = falcon_svr(data)
# 	os.system("echo " + filename)
# 	f.readHeader()
# 	text = f.readAllData()
# 	x = array(f.pos)



#############################

#fig=plot.figure()
#ax = Axes3D.Axes3D(fig)
# ax = fig.add_plot(111, projection='3d')
#window = fig.canvas.manager.window
# ax.plot3D(x[:,0], x[:,1], x[:,2])

#ax.set_xlabel('X (normalize)')
#ax.set_ylabel('Y (normalize)')
#ax.set_zlabel('Z (normalize)')
#ax.set_xlim(-3, 3)
# ax.set_ylim(0, .015)
# ax.set_zlim(-.15, .15)
#fig.add_axes(ax)

def animate():
	for i in range(0,200):
		ax.plot3D(x[i:i+3,0], x[i:i+3,1], x[i:i+3,2], 'bo')
		ax.set_xlim(-.050, .050)
		ax.set_ylim(-.050, .050)		
# 		ax.set_zlim(-.050, .050)				
# 		ax.set_xlim((-0.15, 0.15))
# 		fig.set_xlim(-.15, .15)
# 		ax.set_ylim((-0.15, 0.15))
		fig.canvas.draw()

#fig.canvas.manager.window.after(10,animate)
#plot.show()	




