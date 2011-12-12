%% Select section, clean, pca, output to X3D

% depth = voxelPinhole(vox);
depth_sect = voxelPinhole(vox,0,0,0,depth);
[coeff, scores] = pca(depth_sect);
depth_clean = cleanupVoxels(depth_sect);
% [coeff, scores] = pca(depth_clean);
vox_clean = depth2voxel(depth_clean);

outputVoxel(vox_clean, 'Checkers_sect');

%% Clean current depth map and output to X3D
depth_clean = cleanupVoxels(depth, 4);

vox_clean = depth2voxel(depth_clean);

outputVoxel(vox_clean, 'clean');


%% Voxelize, Clean up model, and output to X3D
vox = model2voxel(model2);
% outputVoxel(vox, 'SV_raw_aug19');

% depth = voxelPinhole(vox);
% depth_clean = cleanupVoxels(depth, 2);
[vox_clean, model] = cleanupVoxels2(vox, 5);

outputModel('SL_Cave_1312_clean', model);

% vox_clean = depth2voxel(depth_clean);
% vox_clean = depth2voxel(depth);

% outputVoxel(vox_clean, 'SV_clean_aug19');