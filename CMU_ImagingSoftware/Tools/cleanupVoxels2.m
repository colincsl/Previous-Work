function [vox_out, m] = cleanupVoxels2(vox, min_particles)
%CLEANUPVOXELS2 Summary of this function goes here
%   Detailed explanation goes here


if nargin < 2
    min_particles = 5;
end

vox_out = zeros(size(vox));
m = zeros(size(vox,1)*size(vox,2), 4);
rez = vox{1,1,1}{6};
size(m)
count = 1;
for i = 1:rez(1)
    for j = 1:rez(2)
        for k = 1:rez(3)
            try
            if ~isempty(vox{i,j,k})
%                 size(vox{i,j,k}, 1)
                    if size(vox{i,j,k}, 1) > min_particles
                        color = mean(vox{i,j,k}(:,4));
                        m(count,:) = [i,j,k, color];%vox{i,j,k}(1,:);
                        count = count+1;
                    else
                        vox{i,j,k} = [];
%                         i
                    end
            end
            catch
%                 [i,j,k]
%                 vox{i,j,k}(1,:)
            end
        end
    end
end
count
m = unique(m, 'rows');

% 
% for i = 1:size(vox, 1)-1
%     
%     dx = vox(i+1,1) - vox(i,1);
% %     dy = vox(i+1,2) - vox(i,2);
%     dz = vox(i+1,3) - vox(i,3);
%     
%     if dz/dx < 100
%         vox_out(i, :) = vox(i, :);
%     end
% end

end

