function [depthmap] = voxelPinhole(voxel, rez, pos, rot, im_depth)
% generate a depthmap from any point in the image
% rot = yaw, pitch, roll

% Get setting params from voxel
settings = voxel{1,1,1};
startPos = cell2mat(settings(2));
binSize = cell2mat(settings(4))
vRez = cell2mat(settings(6))
max_dist = cell2mat(settings(8));
midX = cell2mat(settings(10));
midY = cell2mat(settings(12));

if nargin < 2
    rez = vRez;
%     bin = [30, 10, 50];
    pos = [midX, midY, startPos(3)];
%     pos = [0,0, startPos(3)];
%     rot = [0, 0, 0];
    max_dist = max_dist/binSize(3);
elseif nargin == 5
    imshow(im_depth(:,:,3), []);
    [x, y] = ginput(2);
    x = round(x);
    y = round(y);
    
    s = 2;
    x_d = [0, 0];
    y_d = [0, 0];
    while (x_d(1) == 0 || y_d(1) == 0 || x_d(2) == 0 || y_d(2) == 0)
        tLx = []; tLy = []; bRx = []; bRy = []; %top left
        
        for j = -s:s
            for i = -s:s
                if im_depth(y(1)+j, x(1)+i, 1) ~=0
                    tLx = [tLx; im_depth(y(1)+j, x(1)+i, 1)];
                end
                if im_depth(y(1)+j, x(1)+i, 2) ~=0
                    tLy = [tLy; im_depth(y(1)+j, x(1)+i, 2)];
                end
                if im_depth(y(2)+j, x(2)+i, 1) ~=0
                    bRx = [bRx; im_depth(y(2)+j, x(2)+i, 1)];
                end
                if im_depth(y(2)+j, x(2)+i, 2) ~=0
                    bRy = [bRy; im_depth(y(2)+j, x(2)+i, 2)];
                end
            end
        end

        x_d = round([median(tLx), median(bRx)]);
        y_d = round([median(tLy), median(bRy)]);
        s = s+1;
    end
    
%     x_d = [im_depth(y(1), x(1), 1); im_depth(y(2), x(2), 1)]
%     y_d = [im_depth(y(1), x(1), 2); im_depth(y(2), x(2), 2)]
    
    z_d = [inf; 0];
    for j = y(1):y(2)
        for i = x(1):x(2)
            if im_depth(j, i, 3) < z_d(1) && im_depth(j,i,3) ~= 0
                z_d(1) = im_depth(j,i,3);
            elseif im_depth(j,i,3) > z_d(2)
                z_d(2) = im_depth(j,i,3);
            end
        end
    end
    
    rez = round([(x_d(2)-x_d(1))/binSize(1); (y_d(2)-y_d(1))/binSize(2)])
%     pos = round([mean(x_d), mean(y_d), z_d(1)])
    pos = round([mean(x_d), mean(y_d), startPos(3)])
%     rot = [0, 0, 0];
    max_dist = z_d(2)/binSize(3);
end

depthmap = zeros(rez(2), rez(1), 4);

% syms x real;
boundX = [pos(1) - binSize(1)*rez(1)/2; pos(1) + binSize(1)*rez(1)/2];
boundY = [pos(2) - binSize(2)*rez(2)/2; pos(2) + binSize(2)*rez(2)/2];
boundZ = [pos(3), pos(3) + max_dist*binSize(3)];

boundX_diff = boundX(2) - boundX(1);
boundY_diff = boundY(2) - boundY(1);

x_c = 0;
for x = boundX(1) : boundX_diff/rez(1) : boundX(2) - 1
    x_c = x_c+1;
    y_c = 0;

    for y = boundY(1) : boundY_diff/rez(2) : boundY(2) - 1
        y_c = y_c + 1;

        for z = boundZ(1) : binSize(3) : boundZ(2) - 1
            vox_pos_in = round([x, y, z]);
            voxInd = getVoxelValue(vox_pos_in, 0, startPos, binSize);
            
            if voxInd(1) > 0 && voxInd(2) > 0 && voxInd(3) > 0 && voxInd(1) <= vRez(1) && voxInd(2) <= vRez(2) && voxInd(3) <= vRez(3) && (voxInd(1) ~=1 && voxInd(2) ~= 0 && voxInd(3) ~=0)
                tmp = voxel{voxInd(1), voxInd(2), voxInd(3)};

                if ~isempty(tmp)
                    if depthmap(y_c, x_c, 3) == 0
                        depthmap(y_c, x_c, 1) = x-pos(1);
                        depthmap(y_c, x_c, 2) = y-pos(2);
                        depthmap(y_c, x_c, 3) = z-pos(3);
                        depthmap(y_c, x_c, 4) = tmp(1,4);
                        break
                        
                    end
                end
            end
        end
    end
end


end

