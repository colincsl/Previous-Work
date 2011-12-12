function [voxels] = depth2voxel(depth)
%DEPTH2VOXEL Summary of this function goes here
%   Detailed explanation goes here
[im_y, im_x, im_z] = size(depth);

minX = inf;
minY = inf;
minZ = inf;
maxX = 0;
maxY = 0;
maxZ = 0;

for j = 1:im_y
    for i = 1:im_x
        if depth(j,i,1) < minX
            minX = depth(j,i,1);
        elseif depth(j,i, 1) > maxX
            maxX = depth(j,i,1);
        end
        
        if depth(j,i,2) < minY
            minY = depth(j,i,2);
        elseif depth(j,i,2) > maxY
            maxY = depth(j,i,2);
        end
        
        if depth(j,i,3) < minZ && depth(j,i,3) > 0
            minZ = depth(j,i,3);
        elseif depth(j,i,3) > maxZ
            maxZ = depth(j,i,3);
        end
    end
end

rangeZ = maxZ - minZ;

binSize = [8, 8, 10];
startPos = [minX, minY, minZ]; %x y z
% fprintf('Starting position (x,y,z): %4.0f %4.0f %4.0f\n', startPos);
rez = [100,100,100]; % 100 voxels in each direction

voxels = cell(rez);

% Settings
voxels{1,1,1} = {'StartPos', startPos, 'binSize', binSize, 'rez', rez, 'rangeZ', rangeZ, 'avgX', (minX+maxX)/2, 'avgY',(minY+maxY)/2};


for j = 1:im_y
    for i = 1:im_x
        z_ = depth(j,i,3);
        
        if z_ > 0
            x_ = depth(j,i,1);
            y_ = depth(j,i,2);
            color = depth(j,i,4);
            val = getVoxelValue([x_, y_, z_], 0, startPos, binSize);
            voxels{val(1), val(2), val(3)} = [x_, y_, z_, color];
        end
    end
end

end

