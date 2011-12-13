function H = pointFind(handle)
%input position you want the robot to move to.
    
H = handle;
        disp(H.xInput);
        disp(H.yInput);
        
H = avoidObstacles(H);            
         
 while (H.robotY ~= H.yInput) || (H.robotX ~= H.xInput)
        
        %if point is higher than current robot position:
        while (H.yInput > H.robotY) && H.object_Up == 0
                if H.NXT_Connect == 1
                    H = detectObj(H);
                else
                    pause(.25)
                end

                while (H.robotH ~= 90)
                    H = turn_Left(H);
                end
        
                H = forward(H);
                plot(H.Map, H.robotX, H.robotY, 'or');    
        end
        
        %if point is lower than current robot position:        
        while (H.yInput < H.robotY)&& H.object_Down == 0
                if H.NXT_Connect == 1            
                    H = detectObj(H);          
                else
                    pause(.25)
                end
                
                while (H.robotH ~= 270)
                    H = turn_Left(H);
                end
            
                            
                H = forward(H);                   
                plot(H.Map, H.robotX, H.robotY, 'or'); 
        end
               
        
        %if point is more left than current robot position:        
        while (H.xInput < H.robotX)&& H.object_Left == 0
                if H.NXT_Connect == 1            
                    H = detectObj(H); 
                else
                    pause(.25)                    
                end

                while (H.robotH ~= 180)
                    H = turn_Left(H);
                end
            
                H = forward(H);            

                plot(H.Map, H.robotX, H.robotY, 'or');        
        end               
         
    
        %if point is more right than current robot position:        
        while (H.xInput > H.robotX)&& H.object_Right == 0
                if H.NXT_Connect == 1            
                    H = detectObj(H);    
                else
                    pause(.25)                    
                end        
            while (H.robotH ~= 0)
                H = turn_Left(H);
            end
           
                H = forward(H);             

                plot(H.Map, H.robotX, H.robotY, 'or');        
                %hold on;                
        end    
 end
 
end