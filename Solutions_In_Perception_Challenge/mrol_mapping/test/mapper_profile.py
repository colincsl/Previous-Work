#! /usr/bin/python

import cProfile

import mapper_test

profile_class = mapper_test.profile_code()
command = 'profile_class.align()'

fname = 'mapper.profile' 
cProfile.runctx( command, globals(), locals(), filename=fname)

print '''
RunSnake is a good program to view these results, see
http://www.vrplumber.com/programming/runsnakerun/

To install under ubuntu do

sudo apt-get install python-setuptools python-profiler
sudo easy_install RunSnakeRun

Then run the viewer with
'''
print 'runsnake', fname
