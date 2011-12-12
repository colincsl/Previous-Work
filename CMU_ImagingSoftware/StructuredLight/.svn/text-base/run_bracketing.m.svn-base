% % % % % % % % Inputs % % % % % % % 
root_folder = 'C:\Users\colin\Desktop\subterranean_summer_scholars';
experiment_folder = '\trunk\Data\Cave';
experiment_name = 'Exp2_p1';
n_patterns = 11;
bracket = [1/8, 1/4, 1/2, 1, 1.9];
% % % % % % % % % % % % % % % % % % 

% % % % run_bracketing.m % % % % %
% Use: Take pictures for use with structured light (HDR version)
% Output: images saved to file, data stored to .mat file
% Camera must be plugged in and the projector should be set at 1280x1024
% A new folder is created at the location of your experiment folder
% (appended by the time of the experiment)
% 
% Author: Colin lea (colincsl@gmail.com)
% Date: August 12, 2010
% % % % % % % % % % % % % % % % % % % 

clearvars -except vid n_patterns root_folder experiment_name bracket
close all
clc


output_folder = [root_folder, experiment_folder, datestr(now,'_mm_dd__HHMM')];
output_url = [output_folder, '\', experiment_name];
n_bracket = length(bracket);

% make folder
system(['mkdir ', output_folder]);

% Setup camera
if ~exist('vid', 'var')
    camera_setup
end

% Init timer for whole event
total_time = tic;
%Start the camera. If running, restart to reset the trigger count
if isrunning(vid)
    stop(vid);
    pause(.5);
    start(vid);
else
    start(vid);
end

% Initialize vars
pattern = cell(n_patterns*2, 1);

% % Get all SL patterns -- vertical then horizontal
dir = 0;
j=1;
for i = 0:2:40
    pattern{j} = zeros(1024, 1280,3, 'uint8');
    if i < 10
        filename = ['C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\graycodes\pattern-1280x1024-00', num2str(i), '.bmp'];            
    else
        filename = ['C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\graycodes\pattern-1280x1024-0',num2str(i), '.bmp'];
    end
    img = imread(filename);
    % Set grayscale color to the RGB values of the pattern 
    % [RGB required for fullscreen function ]
    pattern{j}(:, :, 1) = img;  
    pattern{j}(:, :, 2) = img;  
    pattern{j}(:, :, 3) = img;
    j=j+1;
end

% Create full light and no light references (w=white, b=black)
[pattern{'w'}] = display_pattern(-1);
[pattern{'b'}] = display_pattern(0);

% Get black and white reference images
fullscreen(pattern{'w'}, 2);  
pause(.25)
im{'w'} = getImage(vid);
filename = [output_url, 'w'];
getExposureBracket(vid, bracket, filename);
pause(.25)
fullscreen(pattern{'b'}, 2);    
pause(.25)
im{'b'} = getImage(vid);
filename = [output_url, 'b'];
getExposureBracket(vid, bracket, filename);
pause(.25)

% Display patterns & record images
fprintf('Display pattern #');
for i = 1:n_patterns*2-1 %(!21!)
    fullscreen(pattern{i}, 2) % Put onto external projector
    fprintf('%d...', i);
    pause(.25); %it takes time to project
%     if i <= 11
        filename = [output_url, 'p', num2str(i)];
        getExposureBracket(vid, bracket, filename);
%     elseif i > 11
%         filename = [output_url, 'p', num2str(i)];
%         getExposureBracket(vid, bracket, filename);
%     end
    pause(.01)
end
fprintf('\n');
clear pattern img

% Stop the camera from recording and clear screen
stop(vid)
closescreen()

im_diff = im{'w'} - im{'b'};

% Plot white, black, and diff
figure(1)
subplot(1,3,1)
imshow(im{'w'})
subplot(1,3,2)
imshow(im{'b'})
subplot(1,3,3)
imshow(im_diff)