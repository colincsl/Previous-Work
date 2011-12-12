function [model_new] = cleanupModel(depthmap, model, std_size, std_val)
%Uses gradient and standard deviation filters to elliminate noise in a
%depthmap. The output is a clean point cloud.
% std_size is the length (in pixels) of the standard deviation filter. This
% should be an ODD number
% std_val is the threshold amount


if nargin < 3
    std_size = 13;
    std_val = 25.4;
end

[im_y, im_x] = size(depthmap(:,:,3));

[x, y] = gradient(depthmap(:,:,3));
a_z = sqrt(x.^2 + y.^2);
[x, y] = gradient(depthmap(:,:,1));
a_x = sqrt(x.^2 + y.^2);
e = entropyfilt(depthmap(:,:,3), ones(5,5));
std = stdfilt(depthmap(:,:,3), ones(std_size,std_size));

model_new = zeros(im_x*im_y, size(model,2));
size(model_new)

% imtool(e, []);
% imtool(std, []);
% imtool(a_z, []);
% imtool(a_x, []);

k=1;
for j = 1:im_y
    for i = 1:im_x
%         if a_z(j,i) < 103 && e(j,i) < .4 && std(j,i) < 150 && depthmap(j,i,3) < 275 && a_x(j,i) < 40 && dist < 50
        if a_z(j,i) < 100 && depthmap(j,i,3) > 0 && depthmap(j,i,3) < 8000 && ...
                a_x(j,i) < 100 && ...
                    e(j,i) < .001 && ...
                    std(j,i) < std_val
            model_new(k, :) = [depthmap(j,i,1), depthmap(j,i,2), depthmap(j,i,3), depthmap(j,i,4)];
            k = k+1;
        end
    end
end
% k;

model_new = unique(model_new, 'rows');

end

