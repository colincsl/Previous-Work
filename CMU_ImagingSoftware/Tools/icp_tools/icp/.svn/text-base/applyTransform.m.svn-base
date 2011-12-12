% [nx,ny,nz] = applyTransform(T,x,y,z)
% 
%   Apply a transform to x,y,z.  Applies to 2D and 3D points.
%
%   T - a 2x2,3x3, or 4x4 transformation
%   x,y,z - axis to be rotated about
%
%   nx,ny,nz - transformed points
%
%--------------------------------------------------------------------
% Aaron Morris                                              2.26.2005
%--------------------------------------------------------------------
function [nx,ny,nz] = applyTransform(T,x,y,z)

if isempty(x)
    nx=[]; ny=[]; nz =[];
end

[rows,cols]=size(T);

if (nargin==4 & length(x)*length(y)*length(z) > 1e5 & 0)
    half = floor(length(rows)/2);
    [nx1,ny1,nz1] = applyTransform(T,x(1:half),y(1:half),z(1:half));
    [nx2,ny2,nz2] = applyTransform(T,x(half+1:end),y(half+1:end),z(half+1:end));
    nx=[nx1;nx2];
    ny=[ny1;ny2];
    nz=[nz1;nz2];
    return
end

if(nargin==3)
    
    %we have a rotation matrix for 2D
    if(rows==2 & cols==2) 
        im2Temp=T*[x y]';
        im2Temp=im2Temp';
        
        nx = im2Temp(:,1);
        ny = im2Temp(:,2);
        return
    end
    
    %we have rotation/translation for 2D
    if(rows==3 & cols==3) 
        im2Temp = T*[[x y]'; ones(1, length(x))];
        im2Temp = im2Temp(1:2, :)';
    
        nx = im2Temp(:,1);
        ny = im2Temp(:,2);
        return
    end
    
    disp('Error: specified matrix cannot be applied.');
    nx=[];ny=[];
    
elseif(nargin==4)
    
    %we have a rotation matrix for 3D
    if(rows==3 & cols==3)
        im2Temp=T*[x y z]';
        im2Temp=im2Temp';
        
        nx = im2Temp(:,1);
        ny = im2Temp(:,2);
        nz = im2Temp(:,3);
        return
    end
    
    if(rows==3 & cols==4)
       T = [T; [0 0 0 1]];
       rows=4;
    end
    
    %we have a rotation/translation matrix for 3D
    if(rows==4 & cols==4) 
        im2Temp = T*[[x y z]'; ones(1, length(z))];
        im2Temp = im2Temp(1:3, :)';
    
        nx = im2Temp(:,1);
        ny = im2Temp(:,2);
        nz = im2Temp(:,3);
        return
    end
    
    disp('Error: specified matrix cannot be applied.');
    nx=[];ny=[];nz=[];
    
end