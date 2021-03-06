#!/bin/bash 

# Add paths to the PYTHONPATH and ROS_PACKAGE_PATH

export ROS_PACKAGE_PATH=$PWD/kinect_tools:$ROS_PACKAGE_PATH
export ROS_PACKAGE_PATH=$PWD/kinect_template:$ROS_PACKAGE_PATH
export ROS_PACKAGE_PATH=$PWD/mrol_sip:$ROS_PACKAGE_PATH

export PYTHONPATH=$PWD/mrol_sip/src:$PYTHONPATH
export PYTHONPATH=$PWD/mrol_sip/sift:$PYTHONPATH
export PYTHONPATH=$PWD/mrol_sip:$PYTHONPATH
export PYTHONPATH=$PWD/kinect_tools:$PYTHONPATH
export PYTHONPATH=$PWD/mrol_mapping/:$PYTHONPATH

