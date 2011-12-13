       function plotXY(obj)
           
           %plot robot location
           plot(obj.robotX, obj.robotY, 'or');
           
           %plot objects
           for i=1:obj.length;
               for j=1:obj.height;
                   if (obj.map(obj.length, obj.height) ~= 0)
                       plot(obj.length, obj.height, 'db');
                   end
               end
           end
           
        end