#! /bin/bash
fname=fast
cython $fname.pyx
#gcc -shared -pthread -fPIC -fwrapv -O3 -ffast-math -Wall -fno-strict-aliasing -I/usr/include/python2.6 -o $fname.so $fname.c
gcc -shared -pthread -fPIC -fwrapv -O3 -Wall -fno-strict-aliasing -I/usr/include/python2.6 -o $fname.so $fname.c
