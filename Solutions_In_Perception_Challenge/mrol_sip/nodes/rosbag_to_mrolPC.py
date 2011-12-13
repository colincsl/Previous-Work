#! /usr/bin/python

'''
A simple script that reads in a rosbag containing PointCloud2 data and 
saves the PC2's as mrol readable point cloud files (actually just ascii  
text or numpy binary)

Takes source bag file path as an argument, with optional arguments of the
topic containing PointCloud2 data (defaults to '/camera/rgb/points')
and a maximum range (Default maximum range is 2.5 m).

Also takes a --text flag to output data in ascii format.

e.g. python rosbag_to_mrolPC.py 12345.bag --text

e.g. python rosbag_to_mrolPC.py 12345.bag '/camera/depth/points/' 3.5

e.g. python rosbag_to_mrolPC.py solutions_in_perception/NIST_example_data/obj16.bag 'points2'

Saves files as 'mrolpcTIMESTAMP.dat' (ascii) or 'mrolpcTIMESTAMP.npy' 
(numpy binary)
'''
import roslib
roslib.load_manifest('mrol_sip')
import rospy
import numpy as np
from sensor_msgs.msg import LaserScan
from sensor_msgs.msg import PointCloud2
from sensor_msgs.msg import PointField
import tf
import rosbag
import mrol_mapping.pointcloud as pointcloud
import sys
import rosutils_mrol.rosutils_mrol as rosutils


max_range = 2.5
topic = '/camera/rgb/points'
mrolPCbasename = 'mrolpc'

if __name__ == '__main__':
    if '-h' in sys.argv or len(sys.argv) < 2:
        print __doc__
        sys.exit()
    text = '--text' in sys.argv
    bagfilename = sys.argv[1]
    if len(sys.argv) == 3:
        topic = sys.argv[2]
    if len(sys.argv) == 4:
        max_range = sys.argv[3]
    bagfile = rosbag.Bag(bagfilename,'r')
    for topic, msg, ts in bagfile.read_messages(topics=topic):
        xyzs = rosutils.pc22xyzs(msg,max_range)
        filename = mrolPCbasename+str(ts.to_sec())
        if text:
            filename = filename+'.dat'
            pointcloud.save(filename,xyzs,text=True)
        else:
            pointcloud.save(filename,xyzs,)

