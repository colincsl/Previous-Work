
% DEMO4  Epsilon Support Vector Regression with LIBSVM.
%
% A one-dimensional regression problem is solved by an epsilon-style SVM, i.e.,
% the user has to provide the insensitivity zone in addition to the trade-off
% parameter C. Again, the simulation is done by LIBSVMSIM.

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


N   = 200;             % number of samples
f   = 0.2;             % relative error of the sample data
C   = 100;             % trade-off parameter
e   = 0.2;             % insensitivity zone epsilon
s   = 1;               % width of Gauss kernel
pps = 1;               % plot problem and solution (0/1)
rand('state',42);      % fixed state for random numbers

% --- generate the test problem ---

x  = linspace(-4,4,N)';
ys = (1-x+2*x.^2).*exp(-.5*x.^2);
y  = ys+f*max(abs(ys))*(2*rand(size(ys))-1)/2;

if pps
  plot(x,y,'*',x,ys,'-');
  pause;
end

% --- solve the problem ---

disp('Starting LIBSVM')
ker = struct('type','gauss','width',s);
tic;
svm = libsvmopt(x,y,C,e,ker);
t = toc;
nsv = length(svm.coef);
nbv = length(find(abs(svm.coef)==C));
fprintf('Support Vectors : %d (%3.1f%%)\n',nsv,100*nsv/N);
fprintf('Bounded SVs     : %d (%3.1f%%)\n',nbv,100*nbv/N);
fprintf('Bias Term       : %g\n',svm.bias);
fprintf('Optimization finished in %3.2f sec\n',t);

% --- plot the solution ---

if pps
  Y = libsvmsim(svm,x);
  plot(x,y,'*',x,Y,'-',x,[Y-e,Y+e],':');
end
