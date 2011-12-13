
% DEMO3  One-Class Support Vector Classification with LIBSVM.
%
% The aim of a one-class SVM is to find the boundary of a data sample.
% One-class SVMs are always nu style; this demo uses a SVM with Gauss
% kernels. The solution can be illustrated as contour plot or as decision
% function (dependent on the variable pps).

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
f   = 0.5;             % relative error of the sample data
nu  = 0.001;           % SVM's nu parameter
s   = 0.6;             % width of Gaussian kernel
pps = 1;               % plot problem and solution (0/1/2)
rand('state',42);      % fixed state for random numbers

% --- generate the test problem ---

x=zeros(N,2);
x(:,1)=linspace(0,pi,N)';
x(1:2:N,2)=-sin(x(1:2:N,1))+1+f*(rand(N/2,1));
x(2:2:N,2)= sin(x(2:2:N,1))-0.5+f*(rand(N/2,1)-1);

if pps
  plot(x(:,1),x(:,2),'x');
  pause;
end

% --- solve the problem ---

disp('Starting LIBSVM')
ker = struct('type','gauss','width',s);
tic;
svm = libsvmopt(x,[],nu,ker);
fprintf('Optimization finished in %3.2f sec\n',toc);

% --- plot the solution ---

if pps
  [X1,X2] = meshgrid(-1:.1:4,-2:.1:2);
  Y = libsvmsim(svm,cat(3,X1,X2));
  if pps>1
    mesh(X1,X2,Y);
  else
    contour(X1,X2,Y,'k:');
  end
  hold on
  contour(X1,X2,Y,[0 0],'m');
  plot(x(:,1),x(:,2),'x');
  hold off
end
