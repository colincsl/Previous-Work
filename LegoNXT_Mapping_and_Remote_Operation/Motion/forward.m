    function h = forward(handle)
    %drives robot forward and changes it's coordinates
        h = handle;
        if h.NXT_Connect == 1
            h = detectObj(h);
        end
        distance = get(h.DistanceSlider, 'Value');
        h = avoidObstacles(h);
            
        switch h.robotH
            case {0, 360}
                obj = h.object_Right;
            case 90
                obj = h.object_Up;
            case 180
                obj = h.object_Left;
            case 270
                obj = h.object_Right;
            otherwise
                obj = h.object;
        end
        
        if obj == 0
            if h.NXT_Connect == 1
                stop(h.Lmotor);
                stop(h.Rmotor);
                %pause(.2);
                start(h.Lmotor, 30);
                start(h.Rmotor, 30);
                time = .5*distance/4;
                pause(time);
                stop(h.Lmotor);
                stop(h.Rmotor);    
            end
        
                h.robotX = h.robotX + distance*cosd(h.robotH);
                h.robotY = h.robotY + distance*sind(h.robotH);  
                set(h.Xpos, 'String', h.robotX);%show position on figure
                set(h.Ypos, 'String', h.robotY);%show position on figure

        end
    end