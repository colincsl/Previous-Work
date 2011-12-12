% [A,Err] = spin3DICPv11(Model, Scene, T0, eb, max_de, max_I)
% 
% Get the transform that moves scene into the model.
% This procedure uses 6D ICP approach where each point
% has an associated normal vector that is an average of
% all the triangular mesh planes linked to that point.
%
%   NOTE: This is still in the development phases... although it 
%         has demonstrated success.  I think I might need to put
%         more "spin" into it by using the scan center, but that
%         is on the todo list.
%
%   Model - list of <X,Y,Z,Xn,Yn,Zn> where X,Y,Z are model points
%           and Xn,Yn,Zn are normals at those points
%   Scene - list of <X,Y,Z> where X,Y,Z are scene points 
%           and Xn,Yn,Zn are normals at those points
%   T0 - the initial transform
%   eb - maximum acceptable translation error between model and scene
%   max_de - (optional) the maximum difference in error between 
%              iterations.  Default: 0.00001
%   max_I - (optional) the maximum number of iterations
%               before cutting out. Default: 30
%
%   
%   A - the final transfrom
%   Err - computed error between model and scene
%
%--------------------------------------------------------------------
% Aaron Morris                                              2.15.2006
%--------------------------------------------------------------------

function [A,Err,Std,percet_matched,counter] = ICP3D(Model, Scene, T0, varargin)
    
    %defaults
    MAX_INTERATIONS = 30;           %cycles of algorithm
    DERR_THRESHOLD = 0.00002;       %change in error
    MINMATCH = 0.4;                 %minimum percect match
    visual = 0;                     %display visuals for debug
    output =0;                     %write output to screen
    BOUND = [0.03 0.03 0.04];       %maximum TRANSLATIONAL deviation 
    CBOUND = 0;                     %enforce a circular bound
    LTOL = 0.05; %tolerance in the length in meters
    eb = 0.05;
    MV = 0.07;  %voxel resolution for model
    SV = 0.14;  %voxel resolution for the scene
    SEARCH = 0;
    
    
    MinMargin = hypot3(T0(1:3,4)')-LTOL;
    MaxMargin = hypot3(T0(1:3,4)')+LTOL;
    
    [xx,yy,zz]=vcluster3(Scene(:,1),Scene(:,2),Scene(:,3),SV);
    Scene = [xx yy zz];
    [xx,yy,zz]=vcluster3(Model(:,1),Model(:,2),Model(:,3),MV);
    Model = [xx yy zz];
    
    for i=1:2:length(varargin)
        switch upper(char(varargin(i)))
            case 'MAXI'
                MAX_INTERATIONS = cell2mat(varargin(i+1));    %cycles of algorithm
            case 'DERR'
                DERR_THRESHOLD = cell2mat(varargin(i+1));     %change in error
            case 'MINMATCH'
                MINMATCH = cell2mat(varargin(i+1));           %minimum percect match
            case 'VISUAL'
                visual = cell2mat(varargin(i+1));             %display visuals for debug
            case 'OUTPUT'
                output = cell2mat(varargin(i+1));             %write output to screen
            case 'TBOUND'
                BOUND = cell2mat(varargin(i+1));       %maximum deviation
            case 'EBOUND'
                eb = cell2mat(varargin(i+1));
            case 'PCOV' %acceptable percent of overlap
                PCOV = cell2mat(varargin(i+1));
            case 'LTOL' %acceptable percent of overlap
                LTOL = cell2mat(varargin(i+1));
            case 'MV' %maximum range
                MV = cell2mat(varargin(i+1));
            case 'SV' %maximum range
                SV = cell2mat(varargin(i+1));
            case 'CBOUND' %maximum range
                CBOUND = cell2mat(varargin(i+1));
            otherwise
                disp(['Invalid' varargin(i)])
        end
    end
                    
    counter = 0;
    oldErr = 99999999999; 
    tmove = [0 0 0]';
     
    xm = Model(:,1);
    ym = Model(:,2);
    zm = Model(:,3);
    
    if SEARCH == 0
        TRI = delaunay3(xm,ym,zm);
    end
    
    %get the size of Model and Scene
    A = T0;
    
    %initialize the Scene by applying transform
    [xs,ys,zs]=applyTransform(A,Scene(:,1),Scene(:,2),Scene(:,3));
    
    if(visual)
        figure(10),plot3(xm,ym,zm,'bX',xs,ys,zs,'r.');axis equal
        title('Original alignment');
    end
    
    %if(visual)
    %    figure(20),subplot(1,2,1);
    %    plot3(xm,ym,zm,'g.','MarkerSize',1);axis equal
    %    title('Model Plot');
    %end
    
    while (counter < MAX_INTERATIONS)
    
        %if(visual)
        %    figure(20),subplot(1,2,2);
        %    plot3(xs,ys,zs,'b.','MarkerSize',1);axis equal
        %    title('Scene Plot');
        %end
        
        M = [xm ym zm];
        S = [xs ys zs];
            
        %compute the nearest neighboor correspondences
        %ind = dsearchn(M,TRI,S);
        %ind = dsearchn([xm ym zm],TRI,[xs ys zs]);
        
        if SEARCH == 0
            ind = dsearchn([xm ym zm],TRI,[xs ys zs]);
        else
            ind =  dsearchn([xm ym zm],[xs ys zs]);
        end
      
        %pull out closest points from Model
        xm = Model(ind,1);
        ym = Model(ind,2);
        zm = Model(ind,3);
        
        %calculate the sum of square error
        err = sqrt((xm - xs).^2 + (ym - ys).^2 + (zm - zs).^2);
        
        %remove points with high error
        pts1 = find(err < eb);
        percet_used = length(pts1)/length(err);
        percet_matched = percet_used;
        
        ebc=1.1;
        while(percet_used <= MINMATCH & 0)
            pts1 = find(err < eb*ebc);
            percet_used = length(pts1)/length(err);
            ebc=ebc+0.1;
        end
        
        pts = pts1;
        
        if(visual)
            figure(6),plot3(xm(pts),ym(pts),zm(pts),'g.',...
                            xs(pts),ys(pts),zs(pts),'r.',...
                           [xm(pts) xs(pts)]',[ym(pts) ys(pts)]',[zm(pts) zs(pts)]',...
                           'MarkerSize',1); axis equal
            pause(0.1)
        end
        
        P1 = [xm(pts) ym(pts) zm(pts);];
        P2 = [xs(pts) ys(pts) zs(pts);];
        
        Err = mean(err(pts));
        Std = std(err(pts));
        
        derr = abs(oldErr - Err)
 
        if derr < DERR_THRESHOLD
            disp('Exit due to break')
            break;
        end
        
        oldErr = Err;
        
        if(output)
           Err
           derr
           percet_matched
           percet_used
        end
           
        P1c=P1';
        P2c=P2';
        
        %compute the transform 
        M = P2c * P1c';   
        [U, S, V] = svd(M);
        R3 = V*U';
        t3 = [ mean(P1(:, 1)); mean(P1(:, 2)); mean(P1(:, 3));]...
            - R3*[mean(P2(:, 1)); mean(P2(:, 2)); mean(P2(:, 3));];
        %t3=[0 0 0]';
       
        A2 = [R3 t3; 0 0 0 1]; 
        
        %apply the transform
        A = A2*A;
        CT = inv(A)*T0
        if(~isempty(BOUND) & ~CBOUND)
            badpts = find(abs(CT(1:3,4)) > BOUND');
          
            if ~isempty(badpts)
                CT(badpts,4) = sign(CT(badpts,4)).*(BOUND(badpts)');
                A = T0*inv(CT);
                disp('Exceeded bouds');
                CT
            end
            
        elseif CBOUND
            [TH,PHI,R] = cart2sph(A(1,4),A(2,4),A(3,4))
            
            if R < MinMargin
                disp('Under min margin')
                [A(1,4),A(2,4),A(3,4)] = ...
                    sph2cart(TH,PHI,MinMargin);
            end
        
            if R > MaxMargin
                disp('Over max margin')
                [A(1,4),A(2,4),A(3,4)] = ...
                    sph2cart(TH,PHI,MaxMargin);
            end
        end
        
        [xs,ys,zs]=applyTransform(A,Scene(:,1),Scene(:,2),Scene(:,3));
        
        %reset the Model
        xm = Model(:,1);
        ym = Model(:,2);
        zm = Model(:,3);
        
        %if(visual)
        %    figure(10),subplot(1,2,2);
        %    plot3(xm,ym,zm,'bX',xs,ys,zs,'m.','MarkerSize',4);
        %    axis equal;  
        %    title('Current Alignment');
        %    pause(0.1)
        %end
        
        counter = counter + 1;
    end
