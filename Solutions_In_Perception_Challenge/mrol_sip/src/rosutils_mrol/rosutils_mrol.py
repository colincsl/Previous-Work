'''Author: Nick Hillier'''
# Various utils for interacting with ROS

import roslib
roslib.load_manifest('mrol-mapping-ros-pkg')
import rospy

import numpy as np
import tf
import mrol_mapping.poseutil as poseutil

def makePose3D(transform):
    p = poseutil.Pose3D()
    R = tf.transformations.quaternion_matrix(transform[1])
    T = transform[0]
    #M = [R,T;0,0,0,0]
    M = np.zeros([4,4])
    M = R
    M[0:3,3:4] = np.asarray(T).reshape(3,1)    
    p.setMatrix(M)
    return p

from sensor_msgs.msg import PointCloud2
from sensor_msgs.msg import PointField 
def xyzs2pc2(xyzs,stamp,seq,frame_id):
    pc2Data = PointCloud2()
    if len(xyzs) != 0:
        if type(xyzs[0][0]) == np.float64:
            xyzs = np.array(xyzs,dtype=np.float32)
        
        pc2Data.is_dense = False
        pc2Data.is_bigendian = False
        pc2Data.height = 1
        pc2Data.width = len(xyzs)
        pc2Data.header.frame_id = frame_id
        pc2Data.header.seq = seq
        pc2Data.header.stamp = stamp;
        for i in range(3):
            pc2Field = PointField()
            if i == 0:
                pc2Field.name = 'x'
            elif i == 1:
                pc2Field.name = 'y'
            elif i == 2:
                pc2Field.name = 'z'
            else:
                pc2Field.name = 'unknown'
            pc2Field.count = 1
            #if type(xyzs[0][0]) == np.float64:
            #    pc2Field.datatype = 8 # FLOAT64
            #    dataLen = 8 # FLOAT64
            if type(xyzs[0][0]) == np.float32:
                pc2Field.datatype = 7 # FLOAT32
                dataLen = 4 # FLOAT32
            else:
                assert False, "unknown datatype"
            
            pc2Field.offset = i*dataLen
            pc2Data.fields.append(pc2Field)
        pc2Data.point_step = i*dataLen + dataLen;
        pc2Data.row_step = pc2Data.point_step * pc2Data.width;
        
        data_buf = xyzs.flatten().tostring()
        
        assert len(data_buf)/float(dataLen)/3.0 == len(xyzs), "len(data_buf)/4.0/3.0 = "+np.str(len(data_buf)/4.0/3.0)+" but len(xyzs) = "+np.str(len(xyzs))
        pc2Data.data = data_buf
    return pc2Data
    
def pc22xyzs(msg, max_range=100.):
    float32LE = np.dtype(np.float32,align='<')
    data = np.frombuffer(msg.data, dtype=float32LE)
    data_arr = data.reshape((-1,4))
    xyzsD = data_arr[:,0:3].copy()
    xyzsD = xyzsD[np.logical_not(np.isnan(xyzsD[:,1])),:]
    #import pydb;pydb.set_trace()
    ranges = (xyzsD[:,0]*xyzsD[:,0] + xyzsD[:,1]*xyzsD[:,1]) + xyzsD[:,2]*xyzsD[:,2]
    xyzs = xyzsD[(ranges < max_range**2),:]
    return xyzs
