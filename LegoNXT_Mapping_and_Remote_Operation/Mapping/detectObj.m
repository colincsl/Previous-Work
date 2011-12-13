function h = detectObj(handle)
%detect is objects are close in range to the robot using the ultrasonic
%sensor

h = handle;
objDist = 5; %set ultrasonic distance

data = getdata(h.UltrasonicData);

%plot ultrasonic data
    t = clock;        
    plot(h.Ultrasonic, data, t, '-r');
                
        if (data <16)
            objDist = data
            objposX = uint32(h.robotX + objDist*cosd(h.robotH));
            objposY = uint32(h.robotY + objDist*sind(h.robotH));
            h.map.map(objposX, objposY) = 1;
            
            plot(h.Map, objposX, objposY, 'db');
        end