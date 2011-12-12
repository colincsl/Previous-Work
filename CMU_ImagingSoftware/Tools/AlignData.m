% addpath('C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\Analysis\finite_icp')
% addpath('C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\Analysis\icp')
addpath('C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\Analysis\icp_tools')
addpath('C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\Analysis\icp_tools\icp')
addpath('C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\Data\robot_data_bruceton_mine_72810\small_corridor_909AM')

% load checker_TopLeft
% load checker_TopRight

% Small corridor 3DLidar Data
load rear_laser_unrolled.mat

clc
laser_model = [x, y, z];

model1 = unique(1000.*laser_model, 'rows');
model2 = unique(model(:,1:3), 'rows');


size1 = size(model1, 1);
size2 = size(model2, 1);

tic

% % Get rid of far away data
max_dist = 7000;
for i = 1:size1
    if abs(model1(i, 1)) > max_dist || abs(model1(i, 2)) > max_dist || abs(model1(i, 3)) > max_dist
        model1(i,:) = [0, 0, 0];
    end
end
% max_dist = max_dist+700;
for i = 1:size2
    if abs(model2(i, 1)) > max_dist || abs(model2(i, 2)) > max_dist || abs(model2(i, 3)) > max_dist
        model2(i,:) = [0, 0, 0];
    end
end
model1 = unique(model1, 'rows');
model2 = unique(model2, 'rows');

size1 = size(model1, 1);
size2 = size(model2, 1);

% % ------------ Roughly align models -------------
% 
% % % -- Stereo @ 0 deg in small corridor --
R = [1 0 0; 0 0 -1; 0 1 0]; %++
T = [0; 0; 600];
t = [R', T];
% % Initial Condition Transform
% [nx, ny, nz] = applyTransform(t, model2(:,1), model2(:,2), model2(:,3));
% model2 = [nx, ny, nz];

% % -- SL @ 0 deg in small corridor --
% R = [1 0 0; 0 1 0; 0 0 1]; %++
% T = [0; 0; 0];
% t = [R', T];
% Initial Condition Transform
[nx, ny, nz] = applyTransform(t, model2(:,1), model2(:,2), model2(:,3));
model2 = [nx, ny, nz];

icp_ = 0;
if icp_ == 1
    T = [1000, 1000, 1000];
    R=10;
    while(norm(T) > 10 && rad2deg(R(1,1)) > 1)
        [R, T] = icp(model1(1:1000:size1, 1:3), model2(1:1000:size2,1:3));
        t = [R, T; [0, 0, 0, 1]]
        [nx, ny, nz] = applyTransform(t, model2(:,1), model2(:,2),model2(:,3));
        model2 = [nx, ny, nz];
    end
end

model_out = [model1, .2.*ones(size1, 1);
            model2, .8.*ones(size2, 1)];
        
output_url = ['icp_SL_3D_', datestr(now,'yyyymmddTHHMMSS')]
outputModel(output_url, model_out);

disp('done');
toc

% % Decimate 3D laser model
% model_out = [model1(1:2:size1,1:3), .3.*ones(size1/2, 1)];
        
% output_url = ['3D_corr_decimate', datestr(now,'yyyymmddTHHMMSS')]
% outputModel(output_url, model_out);

%%
for i = 1:size1
    model1(i,4) = min((sqrt(model1(i,1)^2+model1(i,2)^2+model1(i,3)^2) - 300)/2700, 1);
end


