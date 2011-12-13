    function h = turn_Left(handle)
    h = handle;
    h = avoidObstacles(h);
    
            if h.NXT_Connect == 1
                stop(h.Lmotor);
                stop(h.Rmotor);
                pause(.25);
                start(h.Lmotor, -39);
                start(h.Rmotor,  39);
                pause(1.2);
                stop(h.Lmotor);
                stop(h.Rmotor);    
            end        

                        h.robotH =  mod((h.robotH + 90),360);   
                        set(h.heading, 'String', h.robotH);%show heading on figure
    end