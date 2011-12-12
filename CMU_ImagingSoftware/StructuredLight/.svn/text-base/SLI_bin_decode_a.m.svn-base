function im_gray = SLI_bin_decode_a(im_, im_gray, im_wh_ref, im_diff, pattern_count)
% Use: Decode the image from image intensity to graycode
% Input: im_ (current image), im_gray(current graycode value), im_wh_ref(white reference),
% im_diff(difference bwteen white and black referece), pattern_count(# of
% curernt pattern),
% Output: im_gray (new graycode value)
% 
% Author: Colin lea
% Date: June, 2010


% Image parameters
im_x = size(im_,2);
im_y = size(im_,1);

cmp_left = im_wh_ref - im_;
cmp_right = im_diff/2;

% For each line...
for y = 1:im_y
    for x = 1:im_x
        if cmp_left(y,x) < cmp_right(y,x)
%         if im_wh_ref(y, x) - im_(y, x) < im_diff(y,x)/2
            im_gray(y, x, pattern_count) = 1;
        end
    end
end