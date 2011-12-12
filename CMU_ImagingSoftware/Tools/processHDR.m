% addpath('C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\StructuredLight\hdr\SLexp')
% addpath('C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\StructuredLight\hdr')
addpath('\Users\Colin\Documents\CMU\trunk\hdr\SLexp')
addpath('\Users\Colin\Documents\CMU\trunk\hdr')
clc
warning off all
tic
% '\Users\Colin\Documents\CMU\subterranean_summer_scholars\trunk\'

% url_base = ['C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\Data\',...
%             'hdrTest_08_17__1742\'];
% url_base = pwd; %get current directory
% url_base ='\Users\Colin\Documents\CMU\trunk\Data\9_3_2010_Bruceton\StructuredLight\data_09_03__1031'
% url_base =   '/Users/Colin/Documents/CMU/trunk/Data/9_3_2010_Bruceton/StructuredLight/data_09_03__1031'
url_base = pwd;
% url_base = '/Users/Colin/Documents/CMU/trunk/Data/9_3_2010_Bruceton/StructuredLight/data_09_03__1031'

url_ = [url_base, '/Exp2_p1'];

n_patterns = 21;
% n_pattern = 3;
bracket = [1/8, 1/4, 1/2, 1, 1.9];
n_exposures = length(bracket);
curve_SL

im_calib = cell(n_exposures, 1);
% im = cell(n_exposures,1);
% hdr = cell(n_patterns, 1);
rgb = cell(n_patterns, 1);
im_ = zeros(960, 1280, 3);

fprintf('Patterns complete: ')
for i = 1:n_patterns
    for j = 1:n_exposures
        im_orig = uint16(imread([url_, 'p', num2str(i), 'e', num2str(j), '.jpg']));
        im_(:,:,1) = im_orig; im_(:,:,2) = im_orig; im_(:,:,3) = im_orig;
%         imshow(im_)
        im_calib{j} = uint16(color_calib(im_, C));
%         im_calib{j} = color_calib(im_, C);
% 'k'
    end
    hdr = make_calib_hdr(im_calib, bracket, C);
    rgb{i} = im2double(tonemap(hdr));
%     imwrite(im2double(rgb{i}), [url_base, '\hdr_p', num2str(i), '.jpg'], 'jpg');
    imwrite(im2double(rgb{i}), ['hdr_p', num2str(i), '.jpg'], 'jpg');
%     fprintf('%1.0f...', i);
end
fprintf('\n');

% get white and black HDRs
for i = ['w', 'b']
    for j = 1:n_exposures
        im_orig = imread([url_, i, 'e', num2str(j), '.jpg']);
        im_(:,:,1) = im_orig; im_(:,:,2) = im_orig; im_(:,:,3) = im_orig;
        im_calib{j} = uint16(color_calib(im_, C));
    end
    hdr = make_calib_hdr(im_calib, bracket, C);
    rgb{i} = im2double(tonemap(hdr));
%     imwrite(im2double(rgb{i}), [url_base, '/hdr_', i, '.jpg'], 'jpg');
    imwrite(im2double(rgb{i}), ['hdr_', i, '.jpg'], 'jpg');
end

rgb{'d'} = rgb{'w'}-rgb{'b'};
% imwrite(im2double(rgb{'d'}), [url_base, '/hdr_diff', '.jpg'], 'jpg');
imwrite(im2double(rgb{'d'}), ['hdr_diff', '.jpg'], 'jpg');

% save([url_base, '/rgb'],'rgb', 'bracket', 'n_patterns', 'url_base', 'url_');
save('rgb','rgb', 'bracket', 'n_patterns', 'url_base', 'url_');

warning on all
toc