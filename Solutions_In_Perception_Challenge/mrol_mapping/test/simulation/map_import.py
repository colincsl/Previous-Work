#!BPY

"""
Name: 'Import points'
Blender: 232
Group: 'Import'
Tooltip: 'Import points'
"""

import Blender, meshtools
from Blender import NMesh
#import time

def read(filename):
    '''Read points in x, y, z format from file'''
	#start = time.clock()
	file = open(filename, "rb")
	objname = Blender.sys.splitext(Blender.sys.basename(filename))[0]
	me = NMesh.GetRaw()	
	# Collect data from RAW format
	for line in file.readlines():
		try:
			try:
				f1, f2, f3, f4  = map(float, line.split())
			except: # raw triangle so take first three only 
				#f1, f2, f3, f4, f5, f6, f7, f8, f9 = map(float, line.split())
				f1, f2, f3 = map(float, line.split())
			v = NMesh.Vert(f1, f2, f3)
			me.verts.append(v)
		except:
			continue
	NMesh.PutRaw(me, objname)
	Blender.Object.GetSelected()[0].name = objname
	Blender.Redraw()
	Blender.Window.DrawProgressBar(1.0, '')  # clear progressbar
	file.close()
	#end = time.clock()
	#seconds = " in %.2f %s" % (end-start, "seconds")
	message = "Successfully imported " + Blender.sys.basename(filename)# + seconds
	meshtools.print_boxed(message)

def fs_callback(filename):
	read(filename)

Blender.Window.FileSelector(fs_callback, "Import Map")
