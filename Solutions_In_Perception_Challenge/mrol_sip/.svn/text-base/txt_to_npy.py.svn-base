import sys
import numpy as np
import pdb

#Convert Nx3 pointcloud in a .txt file to a numpy pointcloud

if len(sys.argv) > 1:
    save_file = sys.argv[1]
else:
    save_file = '/home/colin/repo/perception_repo/data/obj16_best.txt'
    
if len(sys.argv) > 2:
    out_file = sys.argv[2]
else:
    out_file = save_file[:save_file.find('.txt')]
    
fid = open(save_file, 'r')

text = np.array(fid.read().split(), dtype=np.float)

pc = np.reshape(text, (text.shape[0]/3, 3))

np.save(out_file, pc)

