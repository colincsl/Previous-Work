function [p1] = display_pattern(n_stripes)
% Use: Creates a binary set of strips -- currently only used for the black and
% white slides

% Input: n_stripes (# of white stripes)
% Output: image
% Notes: n_stripes = 0 produces a black background
% n_stripes = -1 produces a white background
% Author: Colin lea
% Date: July 1, 2010


% proj_w = 1024;
% proj_h = 768;
proj_w = 1280;
proj_h = 1024;

if (n_stripes == -1)
    p1 = ones(proj_h, proj_w, 3)*255;
elseif (n_stripes == 0)
    p1 = zeros(proj_h, proj_w, 3);
    
    
else %Otherwise produce the correct number of stripes
    stripe_width = proj_w/(n_stripes+1);
    p1 = zeros(proj_h, proj_w, 3);

    k = 0;
    j = 1;
    while(k < 2*n_stripes)
        for x = 1:stripe_width
            if mod(j, 2) == 0 && k*stripe_width + x <= proj_w
                p1(:,round(k*stripe_width) + x, :) = ones(proj_h,3)*255;
            end
        end

%         if k>0 && k*stripe_width < proj_w %mod(j, 2) == 0
%         end
        k=k+1;
        j=j+1;
    end
    
end

p1 = uint8(p1);
        