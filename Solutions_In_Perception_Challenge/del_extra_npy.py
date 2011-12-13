
import sys, os, pdb

#folder = sys.argv[1]
folder = '/home/colin/repo/team_franklin/mrol_sip/data/'

dirs = os.walk(folder)

root = []
folders = []
files = []

for i in dirs:
	root.append(i[0])
	folders.append(i[1])
	files.append(i[2])

data_files = files[0]
data_files.sort()
print data_files
#pdb.set_trace()



for fold_i in range(len(root)):
	for file_i in files[fold_i]:
		if file_i.find('.npz')>=0:
			os.system('echo '+ root[fold_i]+'/'+file_i)
			os.system('rm '+ root[fold_i]+'/'+file_i)
