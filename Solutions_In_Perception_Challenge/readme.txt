Entry into the Solutions In Perception Challenge, 2011
University at Buffalo - Team Franklin
Authors: Colin Lea, Julian Ryde, Nick Hillier, Jason Corso
Contact: colincsl@gmail.com
Updated at 9am, May 3, 2011


Most code is in Python so the instructions may be slightly different than most teams in the competition. Most importantly there are a handful of Python modules required (described below). 

There are no major changes to the requirements since the preliminary code submission other than the inclusion of opencv (which should already be included with ROS...)

There are a couple bash scripts included in the base of the repository to do batch object generation and batch testing. You can reference these or the code at the bottom of this readme for an example of how to run the code from the command line.

All object data and results data is stored in the folder mrol_sip/data.

--General requirements--

1) install ROS diamondback
2) install the openni-kinect and perception-pcl-addons ros packages
3) install the tod_stub:
3a) cd somewhere nice for installing rubbish that you don't know what it does.
3b) rosinstall ./tod_stub_dev https://code.ros.org/svn/wg-ros-pkg/branches/trunk_diamondback/stacks/object_recognition/tod_stub/tod_stub.install
3c) add "source /PATH_TO_INSTALL_DIR/tod_stub_dev/setup.bash" to ~/.bashrc

--Our Requirements--
Folders:
	*mrol_sip
	*kinect_tools
	*mrol_mapping
	*Necessary Python modules: mayavi2 python2.6 python-scipy python-matplotlib python-tk python-nose python-numpy cython python2.6-dev python-visual
	
*!*To install python modules in Ubuntu/Debian run:
	sudo apt-get install mayavi2 python2.6 python-scipy python-numpy python-matplotlib python-tk cython python-visual

*!*Run the file 'add_all_to_path.sh' to add the folders to PYTHONPATH and ROS_PACKAGE_PATH
or do it yourself:
	-The mrol_sip, mrol_mapping, and kinect_tools folders should be added to PYTHONPATH.
	-mrol_sip, kinect tools, mrol_mapping should be added to your ROS_PACKAGE_PATH

*!* SIFT must be compiled
In mrol_sip/sift run make

*!* Cython-fast must be compiled
In mrol_mapping/mrol_mapping/cython run compile.sh

*!* run:
rosmake mrol_sip
rosmake kinect_tools


---RUNNING---

To run either the trainer or detector individually see the commands below. This is similar to the examples on the competition webpage with a minor change (viz_on can added for the detector if wanted; by default is on).

Data files are stored in 'mrol_sip/data/' for both the trainer and detector.

The initialization procedure varies linearly with the number of objects. It could take around a minute for 50 objects.

--trainer.py--
General form to run:
rosrun tod_stub trainer -B <BAGFILE_NAME>.bag --fiducial <FIDUCIAL_NAME>.yml -C <USER_DEFINED_CONFIG_FILE>.yaml --image <IMAGE_TOPIC> --camera_info <CAMERA_INFO_TOPIC> --points <POINT_CLOUD2_TOPIC> --team_name <TEAM_NAME> --run_number <RUN_ID> --object_id <OBJECT_ID> --pose pose

Example command to run:
rosrun mrol_sip trainer.py -B ~/tod_stub_dev/tod_stub/bin/obj16.bag --fiducial fiducial.yaml -C config.yaml --image image --camera_info camera_info --points points2 --team_name TeamFranklin --run_number 0 --object_id example --pose pose

--detector.py--
General form to run:
rosrun mrol_sip detector.py -B <BAGFILE_NAME>.bag -C <USER_DEFINED_CONFIG_FILE>.yaml --image <IMAGE_TOPIC> --camera_info <CAMERA_INFO_TOPIC> --points <POINT_CLOUD2_TOPIC> --team_name <TEAM_NAME> --run_number <RUN_ID> --viz_on <0 or 1 for off or on>

Example command to run
rosrun mrol_sip detector.py -B ~/tod_stub_dev/tod_stub/bin/obj16test.bag -C config.yaml --image image --camera_info camera_info --points points2 --team_name teamFranklin --run_number 0 --viz_on 1
