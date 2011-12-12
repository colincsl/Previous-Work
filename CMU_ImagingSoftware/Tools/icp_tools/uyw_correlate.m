function correlation = uyw_correlate(template, window)

%size of the image window that we will try to
%find the template in
dim = size(window);

%dimensions of the full template to slide around
tsize = size(template);

%this is the half window size
%so that we can position the template
%across the image window such that it
%is centered at (i,j) and spanning
%shift pixels to all sides
shift1 = floor(tsize(1)/2);
shift2 = floor(tsize(2)/2);

%initialize the correlation map which
%is the same size as the template and holds
%the correlation values (lower = higher corr)
%corresponding to each (i,j) centroid
correlation = [];

%create a temporary image with a black border 
%large enough to house half the template
%to simplify the number of if-statements and
%edge calculations
twindow = zeros(dim + tsize);

%copy the original image to the center of the
%new image
twindow(1+shift1:shift1+dim(1), ...
    1+shift2:shift2+dim(2)) = window;

twindowsize = size(twindow);

for i = 1+shift1:shift1 + dim(1)
    for j = 1+shift2:shift2 + dim(2)
        %the start location of the area to
        %compare with the template
        begin1 = i-shift1;
        begin2 = j-shift2;
        
        match = twindow(begin1:begin1+tsize(1)-1,...
            begin2:begin2+tsize(2)-1);
   
        %represent each image matrix as a vector    
        a = double(match(:));
        b = double(template(:));
        
        %normalize the vectors such that intensity does
        %not affect the correlation calculation
        a = a / norm(a);
        b = b / norm(b);
            
        %output the sum squared error between the two data vectors
        correlation(i-shift1,j-shift2) = sqrt(sum((a-b).^2));
    end
end