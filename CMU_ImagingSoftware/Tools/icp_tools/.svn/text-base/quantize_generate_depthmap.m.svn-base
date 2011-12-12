function [range_image, brushfire_map, dsamp_image] = ...
    quantize_generate_depthmap(image, pts_x, pts_y, pts_z, ply_ang2dist, offset)
dim = size(image);

%range_image = zeros(dim(1:2));
brushfire_map = nan(dim(1:2), 'single');
counts = zeros(dim(1:2), 'single');
dsamp_image = zeros(dim(1:2), 'single');

%test
if (length(offset) == 4 && offset(4) ~= 0)
    R = rotx(deg2rad(offset(4)));
    e = R * [pts_x, pts_y, pts_z, ones(size(pts_x))]'; 
    pts_x = e(1, :)';
    pts_y = e(2, :)';
    pts_z = e(3, :)';
    clear e R;
end

r_x = zeros(size(pts_x));
r_y = zeros(size(pts_y));
r_h = zeros(size(pts_z));

%coordinates of the center of the image, roughly the center of projection
if ~exist('CENTX', 'var') || ~exist('CENTY', 'var') 
    CENTX = round(dim(2) / 2);
    CENTY = round(dim(1) / 2);
end
    
%estimate height map first to increase speed
r_h = sqrt((pts_x+offset(1)).^2 + (pts_y+offset(2)).^2 + (pts_z+offset(3)).^2);

for i = 1:length(pts_x)
    %transform the cartesian coord to great circle, incline coords
    [c,incl] = cart2gci(pts_x(i)+offset(1),pts_y(i)+offset(2), pts_z(i)+offset(3));
    
    %check if the point is within the field of view of the fisheye camera
    %nominally 180 degrees
    if c < pi/2 && c > 0
        %project the 3d coordinates to 2d pixel coordinates
        d = polyval(ply_ang2dist, c);
        x = round(d*cos(incl)) + CENTX;
        y = -round(d*sin(incl)) + CENTY;
        
        %note: use z depth or euclid distance?
        r_x(i) = x;
        r_y(i) = y;
        brushfire_map(y,x) = 0;
        dsamp_image(y,x) = r_h(i) + dsamp_image(y,x);
        counts(y,x) = counts(y,x) + 1;
        %height values estimated above
        %r_h(i) = pts_y(i);  % y is depth variable not z
        %range_image(y,x) = pts_y(i);
    end
end

dsamp_image = dsamp_image ./ counts;
dsamp_image(isnan(dsamp_image)) = 0;
clear count;

%delete duplicate points to reduce interp time
[B, I, J] = unique([r_x, r_y], 'rows');
r_x = B(:,1);
r_y = B(:,2);
r_h = r_h(I); 

%the range of points to grid for, everything outside these points is 
%considered n/a data
max_x = max(r_x);
min_x = min(r_x);
max_y = max(r_y);
min_y = min(r_y);

%TESTING
if min_x == 0
    a = sort(r_x);
    min_x = a(2);
end
if min_y == 0
    a = sort(r_y);
    min_y = a(2);
end

%use the triangle sovler to find interpolations
range_image = nan(dim(1:2), 'single');
grids = gridfit(r_x, r_y, r_h, min_x:max_x, min_y:max_y, 'tilesize', 100, 'solver', 'normal', 'interp', 'triangle');
%grids(find(isnan(grids)==1)) = 0; % keep nans in the image
range_image(min_y:max_y, min_x:max_x) = grids;