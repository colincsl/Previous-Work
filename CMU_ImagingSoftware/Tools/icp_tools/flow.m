% Compute the optical flow from imageA to imageB.
% imageA and imageB are grayscale uint8 images.
% Compute the flow on a grid spaced N pixels apart.
% outimage is a color uint8 image that shows the needle map overlayed
% on imageA.

function outimage = flow(imageA, imageB, N, SEARCH, TSIZE)
outimage = [];
imageA = rgb2gray(imageA);
imageB = rgb2gray(imageB);

%the size of the search window (2 * search)
%SEARCH = 20;

%size of the template window (2 * tsize)
%TSIZE = 10;

%display the first picture to plot the needle map
figure, imshow(imageA);

hold on
%size of the images
dim = size(imageA);

%defines for window limits based on the template size
TOP = dim(1) - TSIZE;
BOTTOM = 1 + TSIZE;
LEFT = 1 + TSIZE;
RIGHT = dim(2) - TSIZE;

%search through the entire pixel skipping N
%pixels vertically and horizontally
for i = 1:N:dim(1)
    for j = 1:N:dim(2)
        
        %grab the template from the first image
        template1 = imageA(max(1,i-TSIZE):min(dim(1),i+TSIZE), ...
            max(1,j-TSIZE):min(dim(2),j+TSIZE));
        
        %grab the search area (larger than the template) from
        %the second image. Save dimensions for later use
        window_dim1 = max(1, i-SEARCH):min(i+SEARCH, dim(1));
        window_dim2 = max(1, j-SEARCH):min(j+SEARCH, dim(2));
        window2 = imageB(window_dim1, window_dim2);

        %Only compute the optical flow if the template region
        %is discriminative enough such that there is no spacial
        %symmetry. This is an empirically defined standard 
        %deviation value that seemed to work well.
        if std(template1(:)) > 9
            %Compare with matlab's xcorr function
            cc = normxcorr2(template1, window2);
            %cc = cc(BOTTOM:end-TSIZE,LEFT:end-TSIZE);
            %imshow(cc,[]);
            %drawnow;

            %Calls the correlation function which returns 
            %a correlation map. The location of the minimum
            %distance value is the offset that the pixel 
            %moved to.
            %cc = uyw_correlate(template1, window2);
            
            %find the minimum distance = maximum correlation
            %for normxcorr, it is the max value we want to find
            [dy, dx] = find(cc == max(cc(:)));

            %remap the offset in the window coordinates to
            %a global offset value
            dx=dx(1) + window_dim2(1)-1;
            dy=dy(1) + window_dim1(1)-1;

            %plot the needle map
            %no y component
            plot([j dx],[i i],'r');  
            plot([j],[i],'o'); 
        end
    end
end
hold off

%save the image to file
%print  -dpng flow_tmp.png

%load the file back as a matrix
%outimage = imread('flow_tmp.png');
%close(gcf);
