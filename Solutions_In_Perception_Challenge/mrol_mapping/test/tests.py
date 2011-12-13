#! /usr/bin/python

import os
import subprocess

# find all tests
test_files = [tf for tf in os.listdir('.') if tf.endswith('_test.py')]

# postpone slow tests
slow_tests = '''
mapper_test.py
align_segment_test.py
'''.split()

test_files = list(set(test_files) - set(slow_tests))

#nose_command = 'nosetests -svx --with-coverage'.split()
nose_command = 'nosetests -svx --pdb --pdb-failures'.split()
#nose_command = 'nosetests -sv'.split()

subprocess.call(nose_command + test_files)
print 'Running slow tests'
subprocess.call(nose_command + slow_tests)

print 'For test coverage, use the nosetests coverage option and view results with'
print 'python-coverage report --omit=/usr/share'
