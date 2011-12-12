% Use: Setup Point Grey Camera
% Input: [none]
% Output: vid [variable]
% Notes: 
% *Run the image acquisition toolbox (imaqtool) before using this script to do
% calibration. This file puts the camera into manual mode so that color
% balance doesn't change over the course of the experiment.
% *Calibration not required if generating hdr images
% * Trigger is set to take up to 75 images manually
% 
% Author: Colin lea
% Date: June, 2010


imaqreset

vid = videoinput('dcam',1, 'Y16_1280x960');
% vid = videoinput('dcam',1, 'F7_Y16_1392x1040');


% Set camera parameters
set(vid.source, 'AutoExposureMode', 'manual');
set(vid.source, 'AutoExposureControl', 'absolute');
set(vid.source, 'GainMode', 'manual');
set(vid.source, 'ShutterMode', 'manual');
set(vid.source, 'ShutterControl', 'absolute');

% % Auto Exposure Absolute =  1.355
% Indoor, lights on
set(vid.source, 'AutoExposure', 450);
set(vid.source, 'AutoExposureAbsolute', 0);
set(vid.source, 'ShutterAbsolute', .0001);
set(vid.source, 'Shutter', 300);

set(vid.source, 'BrightnessAbsolute', 0);
set(vid.source, 'Gain', 350);
set(vid.source, 'GainAbsolute', 0);


% Set Trigger/logging settings
triggerconfig(vid, 'Manual')
set(vid,'FramesPerTrigger',1)
set(vid, 'TriggerRepeat', 75)
