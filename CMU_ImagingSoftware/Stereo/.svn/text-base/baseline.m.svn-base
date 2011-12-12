% Use: find the baseline for a stereo camera setup that is equivilent to
% that of a structured light setup
% Notes: The value is based on the idea that the pixel coverage (at
% distance) should be the same for both SL and St.
% SL = Structured Light
% St = Stereo
% Author: Colin Lea
% Date: 7-16-10
clc

% % Set distance here!
d = 6*12*25.4 %distance to object in mm

% % Camera parameters
% fov_p = deg2rad(39.54);
% fov_c = deg2rad(27.65);
% All FOV refer to the horizontal FOV
fov_p = deg2rad(24.04); % projector FOV
fov_c = deg2rad(26.19); % SL camera FOV

% fov_st = deg2rad(53.78); %Field of view for both St cameras
fov_st = deg2rad(97.4/2); %from spec sheet
rezStCam = 1280; %St camera resolution

% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % 
% % % % % % % Structured light parameters %%%%%%%%%%%%%%%%%%
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % 

xP = 0; % Projector position
xC = 481.7; % Camera position (baseline)
rezSLCam = 1280; % Structured light camera resolution
beta = deg2rad(14.96); %tilt from camera

% Projector positions @ distance (blue on plot)
hR_p = xP + tan(fov_p/2)*d;
hL_p = xP + tan(-fov_p/2)*d;

% Camera positions @ distance (red on plot)
hR_c = xC + tan(fov_c/2 - beta)*d;
hL_c = xC + tan(-fov_c/2 - beta)*d;

% Inner positions @ distance
hR_min = min(hR_c, hR_p); %Right inner
hL_max = max(hL_c, hL_p); %Left inner

% Outer positions @ distance
hR_max = max(hR_c, hR_p); %Right outer
hL_min = min(hL_c, hL_p); %Left outer

h_SL_inner = hR_min-hL_max; % Inner length @ distance
h_SL_outer = hR_max-hL_min; % Outer length @ distance





% We are looking for the amount of the projector FOV within the camera FOV
% So if the projector extends outside of the camera's view, account for
% this
if hR_min == hR_c
    rezSLCam = rezSLCam * (hR_c - hL_min) / (hR_p - hL_min);
end

% Find the number of pixels the proj FOV takes up of the total camera rez
SL_px = h_SL_inner/h_SL_outer*rezSLCam;
fprintf('Pixels used by SL: %f \n', SL_px);

% Plot SL FOVs
figure(1)
line([xP, hL_p],[0 d]); hold on; 
line([xP, hR_p],[0 d]); hold on;
line([xC, hL_c],[0 d], 'Color', [1 0 0]); hold on; 
line([xC, hR_c],[0 d], 'Color', [1 0 0]); hold on;
axis([-1500 2500 0 2500])



% % % % % % % % % % % % % % % % % % % % % % % % % % % % % 
% % % % % % % % % Stereo (St) % % % % % % % % % 
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % 
xL_s = 0; % Left camera distance

StRatio = SL_px/rezStCam; % Percent of pixels used from SL in comparison to resolution of St camera

hR_sL = xL_s + tan(fov_st/2)*d; % Left Cam Inner length @ distance
hL_sL = xL_s + tan(-fov_st/2)*d; % Left Cam Outer length @ distance
h_diff = hR_sL - hL_sL; % Length of individual camera @ distance
h_SL_inner = h_diff*StRatio; % Length in pixels for St camera taken up by scene


px_SL_St_cam_ratio = 4.6 / 3.75;
st_base = (2*tan(fov_st/2)*d - h_SL_inner);

hL_sR = st_base + tan(fov_st/2)*d;
hR_sR = st_base + tan(-fov_st/2)*d;

figure(2)
line([xL_s, hL_sL],[0 d], 'Color', [0 0 1]); hold on; 
line([xL_s, hR_sL],[0 d], 'Color', [0 0 1]); hold on;
line([st_base, hL_sR],[0 d], 'Color', [1 0 0]); hold on; 
line([st_base, hR_sR],[0 d], 'Color', [1 0 0]); hold on;
axis([-1500 2500 0 2500])
fprintf('Baseline (in): %f \n', st_base/25.4);
