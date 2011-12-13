
% LIBSVMOPT  Optimize Support Vector Machine with LIBSVM.
%
% SVM Classification:
%   svm = libsvmopt(x,y,C,ker); 
%   svm = libsvmopt(x,y,nu,ker,'style','nu'); 
%
% One-Class SVM:
%   svm = libsvmopt(x,[],nu,ker);
%
% SVM Regression:
%   svm = libsvmopt(x,y,C,e,ker); 
%   svm = libsvmopt(x,y,C,nu,ker,'style','nu'); 
%
% Passing Options:
%   svm = libsvmopt(...,'opt1',value1,'opt2',value2,...); 
%   svm = libsvmopt(...,opt); 
%
% Multiple Output Arguments:
%   [a,b] = libsvm(...);
%   [a,I,b] = libsvm(...);
%
% Input Arguments:
%   x   - Input data (size N*n). In general, x may be a multidimensional array
%         with last dimension (input space) of size n.
%   y   - Output data (size N*1). In general, y may be a multidimensional array
%         with scalar last dimension (output space). For classification problems,
%         y must contain not more than 2 different class labels; if the solution
%         is requested as [a,b] or [a,I,b], these values must be -1 and +1.
%   C   - Upper bound for Lagrange multipliers (positive scalar).
%   e   - Insensitivity zone for regression (non-negative scalar).
%   nu  - Parameter nu (0 < nu <= 1).
%   ker - Kernel function (struct, see below).
%   opt - Optimizer options (struct, see below).
%
% Output Arguments:
%   svm - Support vector machine (struct, see below).
%   a   - Coefficient vector (size N*1, or Nsv*1 if "I" is requested).
%   I   - Index vector (size Nsv*1).
%   b   - Bias term (scalar).
%
% Kernel Function:
% All information about the kernel function is stored in a struct variable with
% the following fields:
%   type   - linear :  k(x,y) = x'*y
%            poly   :  k(x,y) = (x'*y+c)^d
%            gauss  :  k(x,y) = exp(-0.5*(norm(x-y)/s)^2)
%            tanh   :  k(x,y) = tanh(g*x'*y+c)
%   degree - Degree d of polynomial kernel (positive scalar).
%   offset - Offset c of polynomial and tanh kernel (scalar, negative for tanh).
%   width  - Width s of Gauss kernel (positive scalar).
%   gamma  - Slope g of the tanh kernel (positive scalar).
%
% Standard Output Format:
% The output is a struct containing all information needed to simulate the SVM:
%   coef  - Coefficients of the support vectors (size Nsv*1).
%   vect  - Support vectors (size Nsv*n, sub-matrix of x).
%   ker   - Kernel function (struct, see above).
%   bias  - Bias term (scalar).
%   label - Vector of class labels (size 1*2), only for classification.
%   prob  - Probability parameters (size 1*2), only if requested.
%
% Alternative Output Format:
% The solution can also be requested as coefficient vector and bias term [a,b],
% where "a" contains the coefficients in the order of the input data. If an
% additional index vector is requested [a,I,b], then "a" contains only nonzero
% entries and "I" their positions with respect to the input data. In both cases,
% class labels +1 and -1 must be used for classification, since no information
% about the labels is returned. The sign of the decision function f(x) is
% adjusted so that sign(f(x)) is the predicted class label.
%
% Options:
% LIBSVM can be adjusted by several options, which are passed as a struct
% variable or as key/value pairs. If an option is omitted, its default value is
% used. Invalid fields produce warnings. The options are:
%   style   - SVM style ('nu' or 'C'/'eps'). Default: 'C'/'eps'
%   tol     - Tolerance for KKT check (positive scalar). Default: 1e-3.
%   shrink  - Shrinking heuristics (0/1). Default: 1
%   weight  - Weight for class "wlabel" (positive scalar). Default: 1
%   wlabel  - Label of class to be weighted (scalar). Default: -1
%   cache   - Cache size. It can be given as string in kB or MB, or as number of
%             rows (where a row contains N elements). Default: '40MB'
%   prob    - Compute probability information for classification (0/1).
%             Default: 0
%   verbose - Verbosity level (0/1). Default: 0

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
