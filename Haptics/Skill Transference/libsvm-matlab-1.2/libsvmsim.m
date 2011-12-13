
% LIBSVMSIM  Simulate Support Vector Machine.
%
% Syntax:
%   y = libsvmsim(svm,x);
%   [y,p] = libsvmsim(svm,x);
%
% Input Arguments:
%   svm - Support vector machine (struct, described in LIBSVMOPT).
%   x   - Input data (size M*n). In general, x may be a multidimensional array
%         with the last dimension of size n.
%
% Output Arguments:
%   y   - Simulated output (size M*1). In general, y will be a multidimensional
%         array with scalar last dimension. For classification, y>0 predicts the
%         first class label of svm.label, y<0 the second.
%   p   - Predicted probabilities for classification (size M*1). In general,
%         p will be a multidimensional array with scalar last dimension. The
%         SVM must contain probability information. p contains the probability
%         values for the predicted class (in the above sense). The probability
%         for the other (not predicted) class is 1-p.

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
