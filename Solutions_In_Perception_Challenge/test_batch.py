
import sys, os, pdb

#folder = sys.argv[1]
folder = '/home/colin/sip_data/NIST_test/'

os.system('source add_all_to_path.sh')


dirs = os.walk(folder)

root = []
folders = []
files = []

for i in dirs:
	root.append(i[0])
	folders.append(i[1])
	files.append(i[2])

data_files = files
data_files.sort()
print data_files
print "Len: ", len(data_files[0])

for i in range(len(data_files[0])):
	if data_files[0][i].find('.bag')>=0:
#		if data_files[i][0].find('.zip')>=0:
#			os.system('unzip '+folder+data_files[i][0])
#			data_files[i][0] = data_files[i][0:data_files[i][0].find('.zip')]
#			pass
#		pdb.set_trace()		
		f = folder+data_files[0][i]
		print f
		os.system('rosrun mrol_sip detector.py -B %s -C config.yaml --image  /camera/rgb/image_color --points /camera/rgb/points --team_name TeamFranklin --run_number %i' % (f, i))
		
		

