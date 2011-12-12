function imgs = getExposureBracket(vid, exposures, filename)
%%Get multiple exposure images from the camera.
% vid is the camera object
% exposures should be a vector containing all wanted exposure times
% returns the images in a cell if a return value is requested, otherwise
% returns nothing
% images saved in jpeg format
warning off all;

% if filename is listed then write images to file
if nargin < 3
    save = 0;
else
    save = 1;
end

% Stop camera if running
if isrunning(vid)
%     stop(vid);
    running = 1;
else
    start(vid)
    running = 0;
end

old_shutter = get(getselectedsource(vid), 'Shutter');
% camera_rez = get(vid, 'VideoResolution');

im_ = cell(length(exposures), 1);
k = 1;
for i = exposures
%     im_{k} = zeros(camera_rez(2), camera_rez(1));
    set(vid.source, 'Shutter', i*1000);
    pause(.2)    
    im_{k} = getSnapshot(vid);
%     imshow(getSnapshot(vid));
%     figure(2); imshow(im_{k});
    k=k+1;
end

% % im_ = zeros(camera_rez(2), camera_rez(1), length(exposures));
% % k = 1;
% % for i = exposures
% %     set(vid.source, 'Shutter', i*1000);
% %     im_(:,:,k) = getSnapshot(vid);
% % %     imshow(getSnapshot(vid))
% %     imshow(im_(:,:,k));    
% %     k=k+1;
% % end

% Reset to original shutter speed
set(vid.source, 'Shutter', old_shutter);
stop(vid)

% toc
% tic
% Save all of the images as jpegs
if save == 1
    for i = 1:size(im_, 1)
%         imwrite(im2double([im_{i}; im_{i}; im_{i}]), [filename, 'e', num2str(i), '.jpg'], 'jpg');
        imwrite(im2double(im_{i}), [filename, 'e', num2str(i), '.jpg'], 'jpg');
%         imwrite(im2double(im_(:,:,i)), [filename, 'e', num2str(i), '.jpg'], 'jpg');
    end
end
% toc

if nargout > 0
    img = cell(length(bracket),1);
    for i = 1:length(bracket)
        img{i} = [im_{i}; im_{i}; im_{i}];
    end
end

% If camera was running, restart
if running == 1 
    start(vid)
end    

warning on all
