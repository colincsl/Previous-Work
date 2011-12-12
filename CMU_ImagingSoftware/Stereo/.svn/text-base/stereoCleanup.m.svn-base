% % Interpolate and cleanup model. Then output using X3D
% Input: im_depth (3 channel depthmap)

root_folder = 'C:\Users\colin\Desktop\subterranean_summer_scholars';
addpath([root_folder, '\trunk\StructuredLight']);

%Interpolate 
im_interp = interpImage(im_depth, 9);

% Cleanup model using standard deviation and gradient filters, include size
% and threshold for STD filter.
model2 = cleanupModel(im_interp, model, 11, 15); %depthmap, pointcloud, std dev threshold size (SxS), std dev thresh const (mm)
% model2(:,4)=model2(:,4)*.6;


url_ = [root_folder, '\trunk\Data\model_cleanup_'];
outputModel_dir([url_, ''], model2);