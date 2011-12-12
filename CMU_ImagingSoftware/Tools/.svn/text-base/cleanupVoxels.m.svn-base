function [depthmap] = cleanupVoxels(depthmap_, iter)
%CLEANUPVOXELS Summary of this function goes here
%   Detailed explanation goes here

if nargin < 2
    iter = 1;
end

for it = 1:iter
    [x, y] = gradient(depthmap_(:,:,3));
    a_z = sqrt(x.^2 + y.^2);

%     e = entropyfilt(depthmap_(:,:,3));
%     std = stdfilt(depthmap_(:,:,3));
%     range = rangefilt(depthmap_(:,:,3));
%     imtool(a_z, []);
%     imtool(e, []);
%     imtool(std, []);
%     imtool(range, []);
    
    max_grad = 0;
    % Find max gradient value
    for j = 1:size(depthmap_,1);
        for i = 1:size(depthmap_,2);
            if abs(a_z(j,i)) > max_grad
                max_grad = abs(a_z(j,i));
            end
        end
    end
    max_grad


    depthmap = zeros(size(depthmap_));

    for j = 1:size(depthmap_,1);
        for i = 1:size(depthmap_,2);
            if abs(a_z(j,i)) < max_grad/4
                depthmap(j,i, 1) = depthmap_(j,i, 1);
                depthmap(j,i, 2) = depthmap_(j,i, 2);
                depthmap(j,i, 3) = depthmap_(j,i, 3);
                depthmap(j,i, 4) = depthmap_(j,i, 4);
            end
        end
    end
    
    depthmap_ = depthmap;
end
%     [x, y] = gradient(depthmap_(:,:,3));
%     a_z = sqrt(x.^2 + y.^2);
%     imtool(a_z, []);
end

