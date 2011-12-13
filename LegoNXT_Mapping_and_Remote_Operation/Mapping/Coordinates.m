classdef Coordinates
% create a coordinate system for robots and objects

   properties
       robotX;
       robotY;
       height;
       length;
       map;
       subplotX;
       subplotY;
       subplotP;
       heading;
       
   end

   methods
       
       %%constructor
       function obj = Coordinates(xt, yt, startX, startY)
          obj.height = yt;
          obj.length = xt;
          obj.map = zeros(obj.length, obj.height);
          obj.robotX = startX;
          obj.robotY = startY;
          obj.heading = 90;
          
          %create border
          for i=1:obj.height
            obj.map(obj.length, i) = 1;
            obj.map(1,i) = 1;
          end

          for i=1:obj.length
            obj.map(i,obj.height) = 1;
            obj.map(i, 1) = 1;
          end                  
       end


       %% initialize plot figure
       function plotInit(obj)

%           %draw border
%              for i=1:obj.length;
%                for j=1:obj.height;
%                    if (obj.map(i, j) ~= 0)
%                        plot(i, j, 'db')
%                        axis([0 obj.length+1 0 obj.height+1]);
%                        hold on
%                    end
%                end
%              end
       end
       
             
       %% update current robot position on map
       function plotUpdateRobot(obj, handle)    
           axes(handle.Map)
           plot(obj.robotX, obj.robotY, 'or');
           hold on;         
       end
       
       
       %% update object positions
       function plotUpdateObjects(obj)
           %plot objects
           subplot(obj.subplotX, obj.subplotY, obj.subplotP);
           for i=2:obj.length-1;
               for j=2:obj.height-1;
                   if (obj.map(i, j) ~= 0)
                       plot(i, j, 'db')
                       axis([0 obj.length+1 0 obj.height+1]);
                       hold on
                   end
               end
           end
           
       end         
           
       end
      
end
