
% DEMO1  C Support Vector Classification with LIBSVM.
%
% A linear SVM is applied to a non-separable data set (which can be varied by
% the parameters N, f and ov). The classifier is a C-style SVM with class
% weighting. LIBSVMSIM is used to compute a contour plot of the solution. To
% demonstrate probability estimation, all data points are marked where the
% probability of the prediction if below a certain level, e.g., pr=0.9. In this
% example arbitrary class labels are allowed.

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
f   = 0.7;             % relative error of the sample data
ov  = 0.6;             % overlapping of classes (0 .. 1)
C   = 100;             % trade-off parameter
ker = struct('type','linear');                  % kernel function
opt = struct('weight',1,'wlabel',1,'prob',1);   % LIBSVM options
pps = 1;               % plot problem and solution (0/1)
pr  = 0.9;             % mark all data points with probability < pr
rand('state',42);      % fixed state for random numbers

% --- generate the test problem ---

x = zeros(N,2);
x(:,1) = linspace(0,pi,N)';
x(1:2:N,2) = -sin(x(1:2:N,1))+1+f*(rand(N/2,1));
x(2:2:N,2) = sin(x(2:2:N,1))-ov+f*(rand(N/2,1)-1);
y = ones(N,1);         % class "1"
y(1:2:N) = 0;          % class "0"

if pps
  plot(x(:,1),-sin(x(:,1))+1,':', x(:,1),sin(x(:,1))-ov,':', ...
       x(1:2:N,1),x(1:2:N,2),'o',x(2:2:N,1),x(2:2:N,2),'x');
  pause;
end

% --- solve the problem ---

fprintf('Starting LIBSVM\n');
tic;
svm = libsvmopt(x,y,C,ker,opt);
fprintf('Optimization finished in %3.2f sec\n',toc);
[yp,pp] = libsvmsim(svm,x);
mc = sum((yp<0 & y==svm.label(1)) | (yp>=0 & y==svm.label(2)));
fprintf('Misclassifications: %d (%3.1f%%)\n',mc,100*mc/N);

% --- plot the solution ---

if pps
  [X1,X2] = meshgrid(0:.1:pi,-1:.1:1);
  Y = libsvmsim(svm,cat(3,X1,X2));
  hold on
  contour(X1,X2,Y,'k:');
  contour(X1,X2,Y,[0 0],'m');
  I = (pp<pr);   % unsafe predictions
  plot(x(I,1),x(I,2),'k.');
  hold off
end
