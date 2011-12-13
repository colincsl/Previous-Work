
% MEXLIBSVM  Compile LIBSVMOPT and LIBSVMSIM.

% ------------------------------------------------------------------------------
% MATLAB Interface for LIBSVM, Version 1.2
%
% Copyright (C) 2004-2005 Michael Vogt
% Written by Michael Vogt, Atanas Ayarov and Bennet Gedan
% 
% This program is free software; you can redistribute it and/or modify it
% under the terms of the GNU General Public License as published by the Free
% Software Foundation; either version 2 of the License, or (at your option)
% any later version.
% ------------------------------------------------------------------------------

mainpath = fileparts(mfilename('fullpath'));
libpath  = fullfile(mainpath,'libsvm');
srcpath  = fullfile(mainpath,'source');

if ~exist(fullfile(libpath,'svm.cpp')) | ~exist(fullfile(libpath,'svm.h'))
  error(['LIBSVM not found in ',libpath]);
end

eval(['mex -outdir ''',mainpath,''' -I''',libpath,''' ', ...
      '''',fullfile(srcpath,'libsvmopt.c'),''' ', ...
      '''',fullfile(srcpath,'libsvmaux.c'),''' ', ...
      '''',fullfile(libpath,'svm.cpp'),'''']);

eval(['mex -outdir ''',mainpath,''' -I''',libpath,''' ', ...
      '''',fullfile(srcpath,'libsvmsim.c'),''' ', ...
      '''',fullfile(srcpath,'libsvmaux.c'),''' ', ...
      '''',fullfile(libpath,'svm.cpp'),'''']);
