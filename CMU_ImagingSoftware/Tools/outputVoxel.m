function model = outputVoxel(voxel, filename)


if nargin < 2
    filename = ['Vox_', datestr(now,'mm-dd-yyyy__HH_MM_SS')];
else
    filename = ['Vox_', filename, '_', datestr(now,'mm-dd-yyyy__HH_MM_SS')];
end

[sizeX, sizeY, sizeZ] = size(voxel);
model = zeros(sizeX*sizeY*sizeZ, 4);

i = 1;
    for x = 1:sizeX
        for y = 1:sizeY
            for z = 1:sizeZ
                try
                    if ~isempty(voxel{x, y, z})
    %                     if size(voxel{x,y,z},1) > 1
    %                         model(i,:) = voxel{x, y, z}(1,:);
                            model(i,:) = [x, y, z, voxel{x, y, z}(1,4)];
    %                     end
                        i = i+1;
                    end
                catch
%                     'Error: One error is acceptable; Voxel(1,1,1) stores settings'
                end
            end
        end
    end
    
    model = unique(model, 'rows');
    fprintf('%3.0f voxels have been generated\n', size(model, 1));
    
    if size(model,1) > 0
        outputModel(filename, model);
    end
    
    
end