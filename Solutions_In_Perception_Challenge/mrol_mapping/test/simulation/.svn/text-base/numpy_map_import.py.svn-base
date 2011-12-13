#!BPY

"""
Name: 'Import points'
Blender: 232
Group: 'Import'
Tooltip: 'Import points'
"""

import bpy#, meshtools
#from bpy import NMesh
#import numpy as np

#import time
file = '/home/colin/repo/perception_repo/tmp2.txt'

def read(filename):
    '''Read points in x, y, z format from file'''
	#start = time.clock()
    file = open(filename, "rb")
    objname = 'map'#bpy.sys.splitext(bpy.sys.basename(filename))[0]
    #data = np.load(filename)
    #me = NMesh.GetRaw()
    me = bpy.data.meshes.new('myMesh') 
	# Collect data from RAW format
    #for i in range(data.shape[0]):
   #     v = NMesh.Vert(data[i,0], data[i,1],data[i,2])
  #      me.verts.append(v)
            
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
    bpy.Object.GetSelected()[0].name = objname
    bpy.Redraw()
    #bpy.Window.DrawProgressBar(1.0, '')  # clear progressbar
	#file.close()
	#end = time.clock()
	#seconds = " in %.2f %s" % (end-start, "seconds")
    message = "Successfully imported " + bpy.sys.basename(filename)# + seconds
    meshtools.print_boxed(message)

def fs_callback(filename):
	#read(filename)
    read(filename)

fs_callback(file)
#bpy.Window.FileSelector(fs_callback, "Import Map")