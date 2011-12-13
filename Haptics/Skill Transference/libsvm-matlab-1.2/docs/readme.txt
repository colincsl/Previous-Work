
MATLAB Interface for LIBSVM, Version 1.2
========================================

Copyright (C) 2004-2005 Michael Vogt
Written by Michael Vogt, Atanas Ayarov and Bennet Gedan

This software package provides a MATLAB interface for LIBSVM,
a library for the optimization of support vector machines.

DESCRIPTION

The interface offers two commands LIBSVMOPT and LIBSVMSIM for the
optimization and the simulation of support vector machines. The usage
is explained in the MATLAB help files. Because both commands are
implemented as C MEX files, they need to be compiled from the sources
before. Several demos show the capabilites of LIBSVM.

The package is distributed as source code under the GNU General Public
License, see "license.txt" for details. Since LIBSVM uses a different
type of license, it is not included. To build the interface, you will
need LIBSVM 2.8 (or maybe a later version) available at

  http://www.csie.ntu.edu.tw/~cjlin/libsvm

Most features of LIBSVM are accessible. Currently, two things are
missing: Multiclass SVMs and support for sparse MATLAB matrices.

SYSTEM REQUIREMENTS

1. MATLAB 6.0 or higher.
2. A C++ compiler. On Microsoft Windows systems, Microsoft Visual
   C/C++ 6.0 and Borland Free Commandline Tools 5.5 have been testet.
   On Linux it has been compiled with GCC 3.3.

INSTALLATION

1. Configure the C++ compiler by typing "mex -setup" in the MATLAB
   command window and following the instructions.
2. Extract all files of the interface in a directory of your choice,
   and LIBSVM ("svm.cpp" and "svm.h") in the subdirectory "libsvm".
3. Add the main directory to the MATLAB search path.
4. Call "mexlibsvm" in order to compile the MEX functions.
