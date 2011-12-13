
source add_all_to_path.sh


#for i in 1 #{1..9}
#do
#rosrun mrol_sip detector.py -B ~/sip_data/training_new/object_0$i.bag -C config.yaml --image image_color --camera_info camera_info --points points --team_name teamFranklin --run_number $i --viz_on 1
#done

for i in {1..9}
do
rosrun mrol_sip detector.py -B ~/sip_data/training_new/object_0$i.bag -C config.yaml --image image_color --camera_info camera_info --points points --team_name teamFranklin --run_number $i --viz_on 1
done

#for i in {10..35}
#do
#rosrun mrol_sip detector.py -B ~/sip_data/training_new/object_$i.bag -C config.yaml --image image_color --camera_info camera_info --points points --team_name teamFranklin --run_number $i --viz_on 1
#done


#rosrun mrol_sip detector.py -B ~/sip_data/training_new/object_02.bag -C config.yaml --image image_color --camera_info camera_info --points points --team_name teamFranklin --run_number 2 --viz_on 0


#rosrun mrol_sip detector.py -B ~/sip_data/testing/T_23.bag -C config.yaml --image image_color --camera_info camera_info --points points --team_name teamFranklin --run_number 0 --viz_on 1
