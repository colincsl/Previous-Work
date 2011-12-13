    function h = backward(handle)
        %drives robot backwards and changes it's coordinates
        h = handle;
        distance = get(h.DistanceSlider, 'Value');
        h = avoidObstacles(h);
        
        switch h.robotH
            case {0, 360}
                obj = h.object_Left;
            case 90
                obj = h.object_Down;
            case 180
                obj = h.object_Right;
            case 270
                obj = h.object_Left;
            otherwise
                obj = h.object;
        end
        
        
        if obj == 0
            if h.NXT_Connect == 1
                stop(h.Lmotor);
                stop(h.Rmotor);
                %pause(.1);
                start(h.Lmotor, -30);
                start(h.Rmotor, -30);
                time = .425*distance/2;
                pause(time);
                stop(h.Lmotor);
                stop(h.Rmotor);    
            end
        
                h.robotX = h.robotX - distance*cosd(h.robotH);
                h.robotY = h.robotY - distance*sind(h.robotH);  
                set(h.Xpos, 'String', h.robotX);%show position on figure
                set(h.Ypos, 'String', h.robotY);%show position on figure                

        end
    end