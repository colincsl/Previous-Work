% % Used to process images manually. Uses several exposures and creats an HDR image 

warning off all
addpath('C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\hdr');
addpath('C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\hdr\SV_L');
addpath('C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\hdr\SV_R');


% % Stereo Vision -- left camera
% filename{1} = 'C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\StructuredLight\hdr\SV_L\SV_1-250l.tif';
% filename{2} = 'C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\StructuredLight\hdr\SV_L\SV_1-125l.tif';
% filename{3} = 'C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\StructuredLight\hdr\SV_L\SV_1-60l.tif';
% filename{4} = 'C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\StructuredLight\hdr\SV_L\SV_1-30l.tif';
% filename{5} = 'C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\StructuredLight\hdr\SV_L\SV_1-15l.tif';
% filename{6} = 'C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\StructuredLight\hdr\SV_L\SV_1-8l.tif';
% filename{7} = 'C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\StructuredLight\hdr\SV_L\SV_1-4l.tif';
% filename{8} = 'C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\StructuredLight\hdr\SV_L\SV_1-2l.tif';
% filename{9} = 'C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\StructuredLight\hdr\SV_L\SV_1l.tif';
% filename{10} = 'C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\StructuredLight\hdr\SV_L\SV_2l.tif';
% filename{11} = 'C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\StructuredLight\hdr\SV_L\SV_4l.tif';
% filename{12} = 'C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\StructuredLight\hdr\SV_L\SV_8l.tif';
% exp = [1/250, 1/125, 1/60, 1/30, 1/15, 1/8, 1/4, 1/2, 1, 2, 4, 8];
% curve_SV_L;

% Stereo Vision -- right camera
filename{1} = 'C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\StructuredLight\hdr\SV_R\SV_1-250r.tif';
filename{2} = 'C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\StructuredLight\hdr\SV_R\SV_1-125r.tif';
filename{3} = 'C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\StructuredLight\hdr\SV_R\SV_1-60r.tif';
filename{4} = 'C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\StructuredLight\hdr\SV_R\SV_1-30r.tif';
filename{5} = 'C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\StructuredLight\hdr\SV_R\SV_1-15r.tif';
filename{6} = 'C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\StructuredLight\hdr\SV_R\SV_1-8r.tif';
filename{7} = 'C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\StructuredLight\hdr\SV_R\SV_1-4r.tif';
filename{8} = 'C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\StructuredLight\hdr\SV_R\SV_1-2r.tif';
filename{9} = 'C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\StructuredLight\hdr\SV_R\SV_1r.tif';
filename{10} = 'C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\StructuredLight\hdr\SV_R\SV_2r.tif';
filename{11} = 'C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\StructuredLight\hdr\SV_R\SV_4r.tif';
filename{12} = 'C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\StructuredLight\hdr\SV_R\SV_8r.tif';
exp = [1/250, 1/125, 1/60, 1/30, 1/15, 1/8, 1/4, 1/2, 1, 2, 4, 8];
curve_SV_R;

% % SL exposure
% [1/60, 1/30, 1/15, 1/8, 1/4, 1/2, 1]

im  = cell(length(filename), 1);
im_c = cell(length(filename), 1);
for i = 1:length(filename)
    im{i} = imread(filename{i});
    im_c{i} = uint16(color_calib(im{i}, C));
end

hdr = make_calib_hdr(im_c, exp, C);

rgb = tonemap(hdr);
imshow(rgb)
