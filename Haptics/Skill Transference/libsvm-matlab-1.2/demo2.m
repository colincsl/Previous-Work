
% DEMO2  Nu Support Vector Classification with LIBSVM.
%
% In this demo, a nu-style SVM is applied to a separable classification
% problem using a polynomial kernel function. As result the complete decision
% function is plotted; its intersection with the feature plane is the decision
% boundary. Since the solution is requested as separate variables [a,I,b], the
% class labels must be +1 and -1. This demo also demonstrates how to simulate
% the SVM completely with standard MATLAB commands (not using LIBSVMSIM). 

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


N   = 100;             % number of samples
f   = 0.2;             % relative error of the sample data
nu  = 0.5;             % SVM's nu parameter
d   = 2;               % degree of polynomial kernel
c   = 1;               % offset of polynomial kernel
pps = 1;               % plot problem and solution (0/1)
rand('state',42);      % fixed state for random numbers

% --- generate the test problem ---

x = zeros(N,2);
x(:,1) = linspace(-1,1,N)';
x(:,2) = x(:,1).^2+f*(2*rand(N,1)-1);

iu = find(x(:,2)>=x(:,1).^2);
il = find(x(:,2)< x(:,1).^2);
y = ones(N,1); y(il)=-1;       % labels must be "+1" and "-1" here

if pps
  plot(x(:,1),x(:,1).^2,'-',x(iu,1),x(iu,2),'*',x(il,1),x(il,2),'o');
  pause;
end

% --- solve the problem ---

fprintf('Starting LIBSVM\n');
ker = struct('type','poly','degree',d,'offset',c);
tic;
[a,I,b] = libsvmopt(x,y,nu,ker,'style','nu');
fprintf('Optimization finished in %3.2f sec\n',toc);

% --- plot the solution ---

if pps
  [X1,X2] = meshgrid(-1:.1:1,0:.1:1);
  Y = zeros(size(X1));
  for i=1:size(X1,1)
    for j=1:size(X1,2)
      Y(i,j) = a'*(x(I,:)*[X1(i,j);X2(i,j)]+c).^d + b;
    end
  end
  mesh(X1,X2,Y);
  hold on
  contour(X1,X2,Y,[0 0],'m');
  plot(x(:,1),x(:,1).^2,'-',x(iu,1),x(iu,2),'*',x(il,1),x(il,2),'o');
  hold off
end
