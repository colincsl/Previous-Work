% addpath('C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\Data\calibration')
addpath('..\..\Data\calibration')
addpath('..\..\StructuredLight\hdr')
addpath('..\..\hdr');
clc
warning off all
tic


url_base = pwd; %get current directory
url_ = [url_base, '\'];
% bracket = [1/8, 1/4, 1/2, 1, 1.9];
n_exposures = length(bracket);

for cam = ['L', 'R']

    run(['curve_SV_', cam])

    im_calib = cell(n_exposures, 1);

    for j = 1:n_exposures
        im_orig = imread([url_, cam, bracket{j}, '.tif']);
%         for i = 1:3
%             im_orig_2(:,:,i) = im_orig(:,:,i);
%         end
        im_calib{j}= (color_calib(im_orig, C));
%           im_calib{j} = uint16((color_calib(uint16(im_orig), C)));
%         im_calib{j} = color_calib(im_orig_2, C);
    end
    hdr = make_calib_hdr(im_calib, bracket_real', C);
    rgb = im2double(tonemap(hdr));
    imwrite(im2double(rgb), [url_base, '\hdr_', cam, '.jpg'], 'jpg');

%     save([url_base, '\rgb'],'rgb', 'bracket', 'n_patterns', 'url_base', 'url_');

    warning on all
end