!#/bin/bash

source add_all_to_path.sh

set txt1 = '~/sip_data/NIST_train/obj'
set txt2 = '_with_pose.bag'
for i in {1..9}
do
	echo  "~/sip_data/wg_training/object_0${i}.bag"
	rosrun mrol_sip trainer.py -B "/home/colin/sip_data/wg_training/object_0${i}.bag"  --fiducial fiducial.yaml -C config.yaml --image image --camera_info camera_info --points points2 --team_name TeamFranklin --run_number 0 --pose pose --object_id object_$i
done

#for i in {1..15}
#do
#	rosrun mrol_sip trainer.py -B ~/sip_data/NIST_train/object_0$i.bag --fiducial fiducial.yaml -C config.yaml --image image --camera_info camera_info --points points --team_name TeamFranklin --run_number 0 --pose pose --object_id object_0$i 
#done

#rosrun mrol_sip trainer.py -B ~/sip_data/training_new/object_12.bag --fiducial fiducial.yaml -C config.yaml --image image --camera_info camera_info --points points --team_name TeamFranklin --run_number 0 --pose pose --object_id object_12 

#for i in 01
#do
#	rosrun mrol_sip trainer.py -B ~/sip_data/training_new/object_$i.bag --fiducial fiducial.yaml -C config.yaml --image image --camera_info camera_info --points points --team_name TeamFranklin --run_number 0 --pose pose --object_id object_$i_tmp 
#done
