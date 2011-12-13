function H = avoidObstacles(H)


clearance = get(H.DistanceSlider, 'Value'); 
H.object = 0;
H.object_Up = 0;
H.object_Down = 0;
H.object_Left = 0;
H.object_Right = 0;

for j = (H.robotY - clearance):(H.robotY + clearance)         %y
    for i = (H.robotX - clearance):(H.robotX + clearance)     %x
        try
            if (H.map.map(i,j) == 1)

                 if H.NXT_Connect == 1
                     stop(H.Lmotor);
                     stop(H.Rmotor);
                 end
                 H.object = 1;

                 if (j-H.robotY > 0) %&& (i - H.robotX == 0)
                    H.object_Up = 1;
                    disp('Object up')
                 elseif (j-H.robotY < 0) %&& (i - H.robotX == 0)
                    H.object_Down = 1;
                    disp('Object down')
                 end

                 if (i - H.robotX > 0 ) %&& (j-H.robotY == 0)
                    H.object_Right = 1;
                    disp('Object right')
                 elseif (i - H.robotX < 0)% && (j-H.robotY == 0)
                    H.object_Left = 1;
                    disp('Object left')
                 end



                 set(H.input_text, 'String', 'Object in front of robot. Move another way');
                 disp('Object!')
                 pause(.25);
            end     
        catch ObjError
            disp('Boundary Error')
        end
        
    end
end

end
