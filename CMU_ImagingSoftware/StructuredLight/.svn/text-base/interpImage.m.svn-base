function [im_depth_interp] = interpImage(im_depth, thresh)
%INTERPIMAGE 
% Interpolates a depthmap given a specified threshold distance. 
% For distances outside the threshold, returns zeros.

    im_depth_interp = im_depth;

%     Get distance to nearest point and index to that point
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
            if dist < thresh && dist > 0
%                 ang = atan2((y_(i)-y), (x_(i)-x));
                tmp = im_depth(y_(i), x_(i), :);
%                 im_depth_interp(y, x, :) = [tmp(1),tmp(2),tmp(3),tmp(4)] + [sin(ang)*dist; cos(ang)*dist; 0; 0]';
                im_depth_interp(y, x, :) = [tmp(1),tmp(2),tmp(3),tmp(4)];
                interp_points = interp_points+1;
            end
            i=i+1;
        end
    end
    fprintf('%6.0f Interpolated points\n', interp_points);



end

