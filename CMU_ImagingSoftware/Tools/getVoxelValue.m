function [pos_out] = getVoxelValue(pos, voxel, startPos, binSize)
%GETVOXELVALUE Summary of this function goes here
%   Detailed explanation goes here

% 'voxel' input should be 0 if using your own startPos and binSize

if nargin < 4
    settings = voxel{1,1,1};
    startPos = cell2mat(settings(l(2)));
    binSize = cell2mat(settings(l(2)));
%     rez = cell2mat(settings(l(2)));
end

x = round((pos(1) - startPos(1)) / binSize(1));
y = round((pos(2) - startPos(2)) / binSize(2));
z = round((pos(3) - startPos(3)) / binSize(3));

pos_out = [x, y, z] + [1,1,1];

end

