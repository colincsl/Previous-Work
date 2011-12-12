root_folder = 'C:\Users\colin\Desktop\subterranean_summer_scholars';
output_url = ['stereo_Cave_', num2str(im_num), '_', datestr(now,'yyyymmddTHHMMSS')];

% % Correlation parameters
inner_bin_size = 50;
% Actual outer bin dimensions = inner_bin+outer_bin
outer_bin_size = 0;
match_thresh = .9;
max_dist_err = 180;
interval_gain = 1/10;
delta_dist_x = inner_bin_size;

close all

% % Debug, interpolation options
% It is better to leave interpolation off and use stereoCleanup.m later
rectify_img = 0;
output_interp = 0;
show_fig = 0;
show_dual_fig = 0;
im_num = 5;
black_check = 0.1;
entropy_check = 1;%.02;
% % 

addpath([root_folder, '\trunk\StructuredLight']);
addpath([root_folder, '\trunk\Stereo\James_calibs\matlab']);

load Calib_Results_stereo

if rectify_img == 1
    leftIm = uint8(rgb2gray(imread([root_folder, '\trunk\Data\8_4_2010_Cave\Stereo\EL1.tif'])));
    rightIm = uint8(rgb2gray(imread([root_folder, '\trunk\Data\8_4_2010_Cave\Stereo\ER1.tif'])));

    rectify_stereo_pair
end

% imL = imread([root_folder, '\trunk\Stereo\left_rectified_22deg.bmp');
% imR = imread([root_folder, '\trunk\Stereo\right_rectified_22deg.bmp');

if im_num < 5
    imL = imread([root_folder, '\trunk\Data\8_4_2010_Cave\Stereo\left_rectified', num2str(im_num), '.bmp']);
    imR = imread([root_folder, '\trunk\Data\8_4_2010_Cave\Stereo\right_rectified', num2str(im_num), '.bmp']);
else
    im_num=1;
    imL = imread([root_folder, '\trunk\Stereo\left_rectified', num2str(im_num), '.bmp']);
    imR = imread([root_folder, '\trunk\Stereo\right_rectified', num2str(im_num), '.bmp']);
    im_num = 5;
end


% Bruceton 0d
% imL = imread([root_folder, '\trunk\Data\robot_data_bruceton_mine_72810\Stereo\B_exp1_0d_L_2-5s_good.tif');
% imR = imread([root_folder,
% '\trunk\Data\robot_data_bruceton_mine_72810\Stereo\B_exp1_0d_R_2-5s_good.tif');

% imshow(imL);
% pause(1);
% imshow(imR);

% Adaptive equalize images
imL_g = adapthisteq(imL);
imR_g = adapthisteq(imR);
% Create double image (Left+Right combined)
imC_g = zeros(size(imL_g,1), size(imL_g,2)+size(imR_g, 2));
imC_g(1:size(imL_g,1), 1:size(imL_g,2)) = imL_g; 
imC_g(1:size(imL_g,1), size(imL_g,2)+1:(size(imL_g,2)+size(imR_g,2))) = imR_g; 

% imtool(imL_g);
% imtool(imR_g);
% figure(5)
% imshow(imC_g, []);hold on;

% size_y = size(imL_g, 1);
% size_x = size(imL_g, 2);
imL_size = size(imL_g);
count = round(imL_size(1)*imL_size(2) / (inner_bin_size^2));
ptsL = zeros(count, 2);
ptsR = zeros(count, 2);



% % ---------------------Find corresponding points--------------------------
% output_url = ['stereo_Cave_', num2str(im_num), '_', datestr(now,'yyyymmddTHHMMSS')];

total_time = tic;
clc
% close all


% % ---------- Location-based parameters ----------------

if im_num == 5
% For 0 degrees @ Bruceton
    dist_x_max = 150;
else
    dist_x_max = 20;
end
    
dist_y_max = 0; % 
y_max = 900;

% % For 22 degrees @ Bruceton
% dist_x_max = 48; %@y=548,608: x={130:214}    @y=: x={55:207}
% dist_y_max = 62; % 10 sample sets taken; mean of 62.035, std of 3.8 (+6 samples: std=2.8)
% y_max = 710;


if show_dual_fig
    figure(5);
    imshow(imC_g, []);hold on;
end

% Get image sizes
imL_size = size(imL_g);
imR_size = size(imR_g);


k=1;
for y = (outer_bin_size+inner_bin_size+1)+200:  inner_bin_size*interval_gain  : y_max     %(size(imR_g, 1) - (outer_bin_size+inner_bin_size + dist_y_max))
   for x = (outer_bin_size+inner_bin_size+1):   inner_bin_size*interval_gain   :imR_size(2) - (outer_bin_size+inner_bin_size + dist_x_max + 150)

%         [x, y]
        dist_x = dist_x_max;
        dist_y = dist_y_max;

        try   
                inner_area = round([y-inner_bin_size/2,...
                                        y + inner_bin_size/2;... %top -> bottom 
                                    x-inner_bin_size/2,...
                                        x + inner_bin_size/2]);   %left -> right
% %             Right ==  inner                          
                imR_sec = imR_g(inner_area(1,1):inner_area(1,2), inner_area(2,1):inner_area(2,2));                                    
                
%                 if the image is too dark, assume shadow or
%                 non-detectble area
                if mean2(imR_sec)/256 > black_check && entropy(imR_sec)  > entropy_check

                    max_spec = [0, 0, 0];                         
                    dist_err = 0;
    %                 times=0;
                    while (max_spec(3) < match_thresh && dist_err < max_dist_err)
    %                 times = times+1

    % %                 determine template match outer area
                        outer_area = round([inner_area(1,1)-outer_bin_size/2 + dist_y,...
                                                    inner_area(1,2)+outer_bin_size/2 + dist_y;...
                                            inner_area(2,1)-outer_bin_size/2 + dist_x + dist_err,...
                                                    inner_area(2,2)+outer_bin_size/2 + dist_x + dist_err]);

    % %                 Left  ==  outer
                        imL_sec = imL_g(outer_area(1,1):outer_area(1,2), outer_area(2,1):outer_area(2,2));

    %                   Find correlation
                        corr = normxcorr2(imR_sec, imL_sec); %(img, template)

    %                   Find max value from correlation image
                        for j = 1:size(corr, 1)
                            for i = 1:size(corr, 2)
                                if corr(j, i) > abs(max_spec(3))
                                    max_spec = [j, i, abs(corr(j,i))]; %y, x, correlation
                                end
                            end
                        end

    % %                 Optional debugging prints/imgs (show debug[1])
                        if show_fig  == 1
                            fprintf('Max spec, px(y,x): %3.0f %3.0f val: %3.4f\n', max_spec);
                            fprintf('dx, dy = [%3.0f %3.0f]\n', [(max_spec(2)-size(imL_sec, 2)),(max_spec(1)-size(imL_sec, 1))]);   
                            [x+max_spec(2)-size(imL_sec, 2) + dist_x + dist_err + outer_bin_size/2, y+max_spec(1) - size(imL_sec, 1) + dist_y + outer_bin_size/2]
                            [x, y]
                            figure(1); imshow(imR_sec);
                            figure(2); imshow(imL_sec);            
                        end

    % %                 If high correlation, add left and right image points
                        if max_spec(3) > match_thresh
                            ptsL(k,:) = [x+max_spec(2)-size(imL_sec, 2) + dist_x + dist_err - outer_bin_size/2,...
                                            y+max_spec(1) - size(imL_sec, 1) + dist_y - outer_bin_size/2]; %(+outer??)
                            ptsR(k,:) = [x, y];
                            k = k+1;           
                            
%                             if max_spec(3) > .9
%                                 size_ = 3;
%                                 for j = -size_:size_
%                                     for i = -size_:size_
%                                         ptsL(k, :) = [ptsL(k-1, 1)+i, ptsL(k-1, 2)+j];
%                                         ptsR(k, :) = [ptsR(k-1, 1)+i, ptsR(k-1, 2)+j];
%                                         k=k+1;
%                                     end
%                                 end
%                             end

                            if show_dual_fig == 1
                                figure(5);
                                line([ptsL(k,1) size(imL_g,2)+ptsR(k,1)], [ptsL(k, 2) ptsR(k,2)], 'LineWidth', 1); hold on;
                                disp('x:')
                                [ptsL(k,1) ptsR(k,1)]
                                disp('y:')
                                [ptsL(k, 2) ptsR(k,2)]
                                max_spec(3)                            
                            end                
    %                         [x, y]
    %                         fprintf('dx, dy = [%3.0f %3.0f]\n', [(max_spec(2)-size(imL_sec, 2)),(max_spec(1)-size(imL_sec, 1))]);   
    %                             ptsL(k,:)-ptsR(k,:)
    %                             figure(1);plot(ptsL(k,1),ptsL(k,2)); hold on;
    %                             figure(2);plot(ptsR(k,1),ptsR(k,2)); hold on;
                        else
                            dist_err = dist_err + delta_dist_x;

                            if show_dual_fig
                                figure(5)
                                plot(size(imL_g, 2)+x, y, 'og', 'MarkerSize', 8);hold on
                                plot(x+max_spec(2)-size(imL_sec, 2) + dist_x + dist_err + outer_bin_size, y+max_spec(1) - size(imL_sec, 1) + dist_y + outer_bin_size, 'or', 'MarkerSize', 8);hold on
                            end            
                        end
                    end
                end
%         catch
%             fprintf('Bad point (x,y)=%4.0f %4.0f\n', [x, y]);
%             inner_area
%             outer_area
%             max_spec(3)
        end
%     x
    end
%     y
end
fprintf('%6.0f Pts obtained\n', k-1);
ptsL = ptsL(1:k-1, :);
ptsR = ptsR(1:k-1, :);

% % ------------------ Compute depth ------------------------------

% %% Stereo

% load Calib_Results_stereo
[XL, XR] = stereo_triangulation([ptsL(:,1)'; ptsL(:,2)'], [ptsR(:,1)'; ptsR(:,2)'], om, T, fc_left, cc_left, kc_left, alpha_c_left,      fc_right, cc_right, kc_right, alpha_c_right);        
disp('Stereo done');



% % ---------------Output to depth map------------------

im_depth = zeros(imL_size(1), imL_size(2), 4);

i=1;
k=1;
clear XC
XC(1,:) = (XL(1,:)+XR(1,:))/2;
XC(2,:) = (XL(2,:)+XR(2,:))/2;
XC(3,:) = (XL(3,:)+XR(3,:))/2;

while(i<size(ptsL, 1))    
        x = round(ptsL(i,1));
        y = round(ptsL(i,2));
        if abs(XL(3,i)) < 5000
            im_depth(y, x,1) = XL(1,i);
            im_depth(y, x,2) = XL(2,i);
            im_depth(y, x,3) = XL(3,i);            
%             im_depth(y, x,1) = XC(1,i);
%             im_depth(y, x,2) = XC(2,i);
%             im_depth(y, x,3) = XC(3,i);
            color = double(imL_g(y, x))/256;
            im_depth(y, x, 4) = color; 

            k = k+1;
        end
            i = i+1;
end
fprintf('Valid points: %6.0f\n', k);
% imtool(im_depth(:,:,3), []);
    im_depth_interp = im_depth;
% % --------------Interpolation------------------
if output_interp == 1
    [D, L] = bwdist(im_depth(:,:,3), 'euclidean');
%     im_depth_interp = im_depth;
%     imtool(D, [])
%     imtool(L, [])

    ind = zeros(size(im_depth(:,:,3), 1)*size(im_depth(:,:,3), 2), 1);
    x_size = size(im_depth(:,:,3), 2);

    i=0;
    for y = 1:size(im_depth(:,:,3), 1)
            ind(i*x_size+1:(i+1)*x_size) = L(y, :)';
            i=i+1;
    end

    [y_, x_] = ind2sub(size(im_depth(:,:,3)), ind);

    i=1;
    interp_points = 0;
    for y = 1:size(im_depth(:,:,3), 1)
        for x = 1:size(im_depth(:,:,3), 2)
            dist = sqrt((y_(i)-y)^2 + (x_(i)-x)^2);
            if dist < 3 && dist > 0
                ang = atan2((y_(i)-y), (x_(i)-x));
                tmp = im_depth(y_(i), x_(i), :);
                im_depth_interp(y, x, :) = [tmp(1),tmp(2),tmp(3),tmp(4)] + [sin(ang)*dist; cos(ang)*dist; 0; 0]';
                interp_points = interp_points+1;
            end
            i=i+1;
        end
    end
    fprintf('%6.0f Interpolated points\n', interp_points);

% 
%         i=1;
%         j=0;
%         tt=0;
%         for y = 1:size(im_depth(:,:,3), 1)
%             if y_(i) ~=0
%                 im_depth_interp(y, :, 1) = im_depth(y_(i), x_(j*x_size+1 : (j+1)*x_size), 1);
%                 im_depth_interp(y, :, 2) = im_depth(y_(i), x_(j*x_size+1 : (j+1)*x_size), 2);
%                 im_depth_interp(y, :, 3) = im_depth(y_(i), x_(j*x_size+1 : (j+1)*x_size), 3);
%                 tt = tt+1;
%             end
%                 i=i+x_size;
%                 j=j+1;
%         end
%     tt
end

% % -----------------Output to model-----------------
model = zeros(i, 4);

if output_interp == 1 %%%%note: should be == 1
    k=1;
    for y = 1:size(im_depth_interp, 1)
        for x = 1:size(im_depth_interp,2)
            if im_depth_interp(y, x, 1) ~= 0 && im_depth_interp(y, x, 2) ~= 0 && im_depth_interp(y, x, 3) ~= 0
                model(k, :) = im_depth_interp(y, x,:);
                k=k+1;
            end
        end
    end
    k
else
    k=1;
    for y = 1:size(im_depth, 1)
        for x = 1:size(im_depth,2)
            if im_depth(y, x, 1) ~= 0 && im_depth(y, x, 2) ~= 0 && im_depth(y, x, 3) ~= 0
                model(k, :) = im_depth(y, x,:);
                k=k+1;
            end
        end
    end
    k
end

% imtool(im_depth_interp(:,:,3), []);
outputModel(output_url, model);
toc(total_time);

save(output_url,  'model', 'im_depth', 'im_depth_interp', 'ptsL', 'ptsR', 'XL', 'XR');

% % %  Show correlations
% close all
% figure(5)
% imshow(imC_g, []);hold on;
% for i = 1:1:size(ptsL,1)
%     line([ptsL(i,1), size(imL_g,2)+ptsR(i,1)], [ptsL(i, 2), ptsR(i,2)], 'LineWidth', 1); hold on;
% end



% %
% %  Show correlations
% close all
figure(6)
imshow(imC_g, []);hold on;
for i = 1:2:size(ptsL,1)
%     line([ptsL(i,1), size(imL_g,2)+ptsR(i,1)], [ptsL(i, 2), ptsR(i,2)], 'LineWidth', 1); hold on;
    plot(ptsL(i,1), ptsL(i,2), 'or'); hold on;
    plot(size(imL_g,2)+ptsR(i,1), ptsR(i,2), 'og'); hold on;
end

