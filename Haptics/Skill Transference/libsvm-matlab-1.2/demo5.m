
% DEMO5  Nu Support Vector Regression with LIBSVM.
%
% This demo shows how to solve a two-dimensional regession problem by a
% nu-style SVM (where nu is an alternative to the insensitivity zone). It
% also shows how to call LIBSVMOPT with multi-dimensional matrices. The
% computed regression function is shown as mesh together with the original
% function as transparent surface.

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
C   = 1;               % trade-off parameter
nu  = 0.05;            % SVM's nu parameter
s   = 1;               % standard deviation of Gauss kernel
pps = 1;               % plot problem and solution (0/1)
rand('state',42);      % fixed state for random numbers

% --- generate the test problem ---

[x,y] = meshgrid(linspace(-pi,pi,ceil(sqrt(N))));
zs = sin(x);
z  = zs+f*max(max(abs(zs)))*(2*rand(size(zs))-1)/2;

if pps
  mesh(x,y,zs);
  hold on;
  plot3(x,y,z,'bx');
  hold off;
  pause;
end

% --- solve the problem ---
'a'
disp('Starting LIBSVM')
ker = struct('type','gauss','width',s);
tic;
svm = libsvmopt(cat(3,x,y),z,C,nu,ker,'style','nu','verbose',1);
fprintf('Optimization finished in %3.2f sec\n',toc);
'b'
% --- plot the solution ---

if pps
  Z = libsvmsim(svm,cat(3,x,y));
  surf(x,y,zs,'FaceAlpha',0.4);
  shading('interp');
  hold on
  mesh(x,y,Z,'FaceAlpha',0,'EdgeColor',[0 0 0]);
  plot3(x,y,z,'bx');
  hold off;
  'c'
end
