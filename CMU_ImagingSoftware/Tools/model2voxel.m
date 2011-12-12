function [voxels] = model2voxel(model, binSize, rez, startPos)
% Convert pointcloud model to voxel form

if nargin < 3
    
    if nargin < 2
        binSize = [10, 10, 10];
    end
    
    minX = inf;
    minY = inf;
    minZ = inf;
    maxX = 0;
    maxY = 0;
    maxZ = 0;
    
    for i = 1:size(model,1)
        if model(i, 1) < minX
            minX = model(i,1);
        elseif model(i, 1) > maxX
            maxX = model(i,1);
        end
        
        if model(i,2) < minY
            minY = model(i,2);
        elseif model(i,2) > maxY
            maxY = model(i,2);
        end
        
        if model(i,3) < minZ && model(i,3) > 0
            minZ = model(i,3);
        elseif model(i,3) > maxZ
            maxZ = model(i,3);
        end
    end
    
    rangeX = maxX - minX;
    rangeY = maxY - minY;
    rangeZ = maxZ - minZ;
    
    startPos = [minX, minY, minZ]; %x y z
    fprintf('Starting position (x,y,z): %4.0f %4.0f %4.0f\n', startPos);
%     rez = [100,100,100]; % 100 voxels in each direction
    rez = round([rangeX/binSize(1), rangeY/binSize(2) rangeZ/binSize(3)])
end

voxels = cell(rez);

% Settings
voxels{1,1,1} = {'StartPos', startPos, 'binSize', binSize, 'rez', rez, 'rangeZ', rangeZ, 'avgX', (minX+maxX)/2, 'avgY',(minY+maxY)/2};

% voxels('Settings') = {'startingPos' = startPos)
% k = 0;
for i = 1:size(model,1)
   if model(i,1) ~= 0 && model(i,1) ~= 2 && model(i,3) ~= 0
       val = getVoxelValue(model(i,:), 0, startPos, binSize);
       
    if val(1) ~= 1 && val(2) ~=1 && val(3) ~=1
       if val(1) > 0 && val(1) <= rez(1) && val(2) > 0 && val(2) <= rez(2) && val(3) > 0 && val(3) <= rez(3) 
           voxels{val(1), val(2), val(3)} = [voxels{val(1), val(2), val(3)}; model(i,:)];

       end
    end
    %    m = mod((model(i, 1) - start_pos(1)),binSize);
   end
end
% i

end
