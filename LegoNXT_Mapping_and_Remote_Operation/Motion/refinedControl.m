function [map] = refinedControl(H, map, Lmotor, Rmotor)
    


if (isButtonPressed('UP')&& H.MODE == 2 && H.object_Up == 0)
    H = forward(H);         
               subplot(2,2,3)       
               plotUpdateRobot(map);
end
                
if (isButtonPressed('DOWN')&& H.MODE == 2 && H.object_Down == 0)
    H = backward(H);               
                subplot(2,2,3)       
                plotUpdateRobot(map); 
end
          
if (isButtonPressed('LEFT')&& H.MODE == 2 && H.object_Left == 0)
    H = turn_Left(H);      
end

if (isButtonPressed('RIGHT')&& H.MODE == 2 && H.object_Right == 0)
    H = turn_Right(H);
end

end