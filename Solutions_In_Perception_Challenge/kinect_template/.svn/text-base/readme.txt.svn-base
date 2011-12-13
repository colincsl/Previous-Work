This folder is a template for using the Kinect with ROS. Run it using 'roslaunch kinect_template run_template.launch' in the terminal.


Remember to add the following to your bash script (~/.bashrc) so that ROS detects the folder:
export ROS_PACKAGE_PATH=/home/colin/sip/perception_repo:$ROS_PACKAGE_PATH

When adding new python/C++ files make sure to add executable permissions otherwise ROS will not compile.
sudo chmod +x FILENAME

If you want to find the min or max and you're using OpenNI, you must use np.nanmax(args) instead of .max() or else you may get 'nan' as your answer.




openni - float32, null are 'nan'
freenect - uint8, null are 255

"yup, NI supports registration in hardware. No need to calibrate 
plus some other features"

