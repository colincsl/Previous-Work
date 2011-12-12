function [X,Y,Z] = vcluster3(X,Y,Z,resolution);

xsize = ceil(range(X) / resolution)+1;
ysize = ceil(range(Y) / resolution)+1;
zsize = ceil(range(Z) / resolution)+1;

if (xsize*ysize*zsize > 1e5)
    %disp('splitting');
    ind = Z > median(Z);
    [X1,Y1,Z1] = vcluster3(X(ind),Y(ind),Z(ind),resolution);
    [X2,Y2,Z2] = vcluster3(X(~ind),Y(~ind),Z(~ind),resolution);
    X = [X1;X2];
    Y = [Y1;Y2];
    Z = [Z1;Z2];
    %h=plot3(X,Y,Z,'.'); 
    %set(h,'MarkerSize',0.5);
    %axis equal
    %size(X)
    return
end


minx = min(X);
miny = min(Y);
minz = min(Z);

Xsum = zeros(xsize,ysize,zsize);
Ysum = zeros(xsize,ysize,zsize);
Zsum = zeros(xsize,ysize,zsize);
Count = zeros(xsize,ysize,zsize);

for i=1:length(X),
    xbin = ceil( (X(i) - minx)/resolution)+1;
    ybin = ceil( (Y(i) - miny)/resolution)+1;
    zbin = ceil( (Z(i) - minz)/resolution)+1;
    
    Xsum(xbin,ybin,zbin) = Xsum(xbin,ybin,zbin) + X(i);
    Ysum(xbin,ybin,zbin) = Ysum(xbin,ybin,zbin) + Y(i);
    Zsum(xbin,ybin,zbin) = Zsum(xbin,ybin,zbin) + Z(i);
    Count(xbin,ybin,zbin) = Count(xbin,ybin,zbin) + 1;
end
ind = Count(:) > 0;
%sum(ind)
X = Xsum(ind) ./ Count(ind);
Y = Ysum(ind) ./ Count(ind);
Z = Zsum(ind) ./ Count(ind);
%h=plot3(X,Y,Z,'.');
%set(h,'MarkerSize',0.5);
%axis equal