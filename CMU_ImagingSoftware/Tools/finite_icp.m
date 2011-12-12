addpath('C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\Analysis\finite_icp')
addpath('C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\Analysis\icp')

load color_checkers_test
clc
th = deg2rad(15);
rot = [cos(th) -sin(th) 0;...
       sin(th)  cos(th) 0;...
       0        0       1];
   
m = unique(model, 'rows');   
model_rot = m(:,1:3)*rot;

% % Finite ICP
% Test 1: input rotation = 15*, output rotation = 15.537*
% Test 2: input rotation = 15*, input is subset of whole; output = 10.552*
% [model_out, T] = ICP_finite(m(1:100:27680,1:3), model_rot(1:100:227680, :));
% T

% % (Analytical) ICP
% Test 1: input = 15*; output = 15*
[R, T] = icp(model_rot(1:100:227680, :), m(1:100:17680,1:3));

R
T