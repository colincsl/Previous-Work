function H = WiiNav(H)
%H is the handle from the GUI
%make into integers for motor control
    
try    
    x_multiplier = 2;
    y_multiplier = 4;
    
    ax = int8(H.wii.X*x_multiplier);
    ay = -int8(H.wii.Y*y_multiplier);
    
    dt = cputime - H.clk;
    H.clk = cputime;
    width = 17;
    
catch e_init
    disp('Error in WiiNav initialize')
    e_init
end

    %turn left
    if (ax < -6 && H.MODE == 1 && H.object_Left == 0)
        try
        vel_L = double(ay + (ax - 6));
        vel_R = double(ay);
        
        if H.NXT_Connect == 1    
            start(H.Lmotor, vel_L);
            start(H.Rmotor, vel_R);
        end
        
        dh = atand(((vel_R-vel_L)/width))       
        H.robotH = mod((H.robotH + (dh*dt)), 360);
        
        v = (vel_R+vel_L)/2 %average velocity of the two sides        

        H.robotX = int8(H.robotX + v*cosd(H.robotH)*dt);
        H.robotY = int8(H.robotY + v*sind(H.robotH)*dt);        

        
        catch
            disp('Error in WiiNav turning left.')
        end        

    %turn right
    elseif (ax > 6 && H.MODE == 1 && H.object_Right == 0)
        try
            
        vel_L = double(ay);
        vel_R = double(ay + (abs(ax) - 6));
        
        if H.NXT_Connect == 1    
            start(H.Lmotor, vel_L);
            start(H.Rmotor, vel_R);
        end
        
        dh = atand((vel_R-vel_L)/width);
        H.robotH = mod((H.robotH + (dh*dt)), 360);
        
        v = (vel_R+vel_L)/2 %average velocity of the two sides
        
        H.robotX = int8(H.robotX + v*cosd(H.robotH)*dt);
        H.robotY = int8(H.robotY + v*sind(H.robotH)*dt);        

        catch
            disp('Error in WiiNav while turning right.')
        end
    %go straight    
    elseif (ay ~= 0)
        try
        
        vel_L = double(ay);
        vel_R = double(ay);
        
        if H.NXT_Connect == 1    
            start(H.Lmotor, vel_L);
            start(H.Rmotor, vel_R);
        end  
        
        v = (vel_R+vel_L)/2 %average velocity of the two sides
        
        H.robotX = int8(H.robotX + v*cosd(H.robotH)*dt);
        H.robotY = int8(H.robotY + v*sind(H.robotH)*dt);  
        
        catch
            disp('Error in WiiNav while going straight')
        end
        
    else
        if H.NXT_Connect == 1
            stop(H.Lmotor);
            stop(H.Rmotor);
        end
    end
end