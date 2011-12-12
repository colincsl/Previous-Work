% addpath('C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\StructuredLight\hdr\SLexp')
% addpath('C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\StructuredLight\hdr')
clc
warning off all
tic

% url_base = ['C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\Data\',...
%             'hdrTest_08_13__1742\'];
url_base = ['\Users\colin\Documents\CMU\trunk\Data\',...
            '8_17_2010_Cave\StructuredLight\Cave_08_17__1218\'];


url_ = [url_base, 'hdr_'];

n_patterns = 21;
% n_pattern = 3;
bracket = [1/8, 1/4, 1/2, 1];
n_exposures = length(bracket);
curve_SL

im_calib = cell(n_exposures, 1);
% im = cell(n_exposures,1);
% hdr = cell(n_patterns, 1);
rgb = cell(n_patterns, 1);
im_ = zeros(960, 1280, 3);

for i = 1:n_patterns
    for j = 1:n_exposures
        im_orig = imread([url_, 'p', num2str(i), 'e', num2str(j), '.jpg']);
        im_(:,:,1) = im_orig; im_(:,:,2) = im_orig; im_(:,:,3) = im_orig;
%         imshow(im_)
        im_calib{j} = uint16(color_calib(im_, C));
    end
    hdr = make_calib_hdr(im_calib, bracket, C);
    rgb{i} = im2double(tonemap(hdr));
    imwrite(im2double(rgb{i}), [url_base, 'hdr', num2str(i), '.jpg'], 'jpg');
end

% get white and black HDRs
for i = ['w', 'b']
    for j = 1:n_exposures
        im_orig = imread([url_, i, 'e', num2str(j), '.jpg']);
        im_(:,:,1) = im_orig; im_(:,:,2) = im_orig; im_(:,:,3) = im_orig;
        im_calib{j} = uint16(color_calib(im_, C));
    end
    hdr = make_calib_hdr(im_calib, bracket, C);
    rgb{i} = im2double(tonemap(hdr));
    imwrite(im2double(rgb{i}), [url_base, 'hdr_', i, '.jpg'], 'jpg');
end

rgb{'d'} = rgb{'w'}-rgb{'b'};
imwrite(im2double(rgb{'d'}), [url_base, 'hdr_diff', '.jpg'], 'jpg');

save([url_base, 'rgb'],'rgb', 'hdr', 'bracket', 'n_patterns', 'url_base', 'url_');

warning on all
toc
%%
% % % % % % % % % % % % % % % % % % % % % % % % % % % %
% % % % % % % % Process hdr images % % % % % % % % % %
% % % % % % % % % % % % % % % % % % % % % % % % % % % % %
% addpath('C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\Data')
addpath('\Users\colin\Documents\CMU\trunk\Data')
addpath('/Users/Colin/Documents/CMU/trunk/ImagingSoftware/StructuredLight');
addpath('/Users/Colin/Documents/CMU/trunk/Data/8_17_2010_Cave/StructuredLight/Cave_08_17__1218')
% addpath('C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\StructuredLight\')
addpath('\Users\colin\Documents\CMU\trunk\ImagingSoftware\StructuredLight\')
url_base = ['\Users\colin\Documents\CMU\trunk\Data\',...
            '8_17_2010_Cave\StructuredLight\Cave_08_17__1218'];
        
url_ = [url_base, 'hdr_'];


% clear all
load rgb.mat
addpath(url_base);

url_base = ['\Users\colin\Documents\CMU\trunk\Data\',...
            '8_17_2010_Cave\StructuredLight\Cave_08_17__1218\'];
        
url_ = [url_base, 'hdr_'];

% % Remember to change the rez parameters in SLI_bin_decode_dual_b.m with
% the respective gray code-based values
x_num_images = 9;
y_num_images = 10;
im_gray_x = zeros(size(rgb{'w'}(:,:,1), 1), size(rgb{'w'}(:,:,1), 2), x_num_images); %Initialize for graycode values
im_gray_y = zeros(size(rgb{'w'}(:,:,1), 1), size(rgb{'w'}(:,:,1), 2), y_num_images); %Initialize for graycode values
% im_gray_x = zeros(size(rgb{'w'}, 1), size(rgb{'w'}, 2), ceil(n_patterns/2)-2); %Initialize for graycode values
% im_gray_y = zeros(size(rgb{'w'}, 1), size(rgb{'w'}, 2), floor(n_patterns/2)-1); %Initialize for graycode values

% Undistort
fprintf('Decoding patterns\n');

for i = 1:x_num_images%round(n_patterns/2)-2
%     im_gray_x = SLI_bin_decode_a_hdr(rgb{i}, im_gray_x, rgb{'w'}, i); %Get graycode values from image intensity
    im_gray_x = SLI_bin_decode_a(rgb{i}(:,:,1), im_gray_x, rgb{'w'}(:,:,1), rgb{'d'}(:,:,1), i); %Get graycode values from image intensity    
end
for i = round(n_patterns/2)+1:round(n_patterns/2)+y_num_images%n_patterns-2
%     im_gray_y = SLI_bin_decode_a_hdr(rgb{i}, im_gray_y, rgb{'w'}, i-round(n_patterns/2)); %Get graycode values from image intensity
    im_gray_y = SLI_bin_decode_a(rgb{i}(:,:,1), im_gray_y, rgb{'w'}(:,:,1), rgb{'d'}(:,:,1), i-round(n_patterns/2)); %Get graycode values from image intensity
end

% im_gray_x = im_gray_x(:,:,2:11);
% im_gray_y = im_gray_y(:,:,2:10)

% Convert to binary code. Decode image
im_dec_x = gray2dec(im_gray_x); %get decimal value from graycode for each pixel; Courtesy Siggraph paper: http://mesh.brown.edu/byo3d/
im_dec_y = gray2dec(im_gray_y); %get decimal value from graycode for each pixel; Courtesy Siggraph paper: http://mesh.brown.edu/byo3d/

im_white = rgb{'w'};
% im_white = imread([url_, 'w']);

try
clear im_gray_x im_gray_y rgb
end

fprintf('Decoding image\n');
[model, im_depth] = SLI_bin_decode_dual_b(im_white, im_dec_x, im_dec_y); %generate 3D model from decoded values

model(:,4) = model(:,4)*65536;
% Output raw model
% outputModel_dir(url_, model);
outputModel_dir('hdr', model);
save(url_, 'model', 'im_depth', 'im_dec_x', 'im_dec_y');

% % cleanup model
im_interp = interpImage(im_depth, 12);
model2 = cleanupModel(im_interp, model, 9, 100);
model2(:,4) = model2(:,4)*65536;

% save images im im depth model     % % Save for remote testing
fprintf('%10.0f points generated\n', size(model,1));
disp('Start writing to X3D file')

% outputModel_dir([url_, '_cleanup'], model2);
outputModel_dir(['hdr_', '_cleanup'], model2);
disp('Save .mat file')

disp('File complete')
toc(total_time)

