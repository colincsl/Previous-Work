% obj = RoombaInit(3);

% AllSensorsReadRoomba(obj);

% SetFwdVelRadiusRoomba(obj, .1, inf);
% pause(1.4);
% SetFwdVelRadiusRoomba(obj, 0, 0);
% pause(.5)
% 
% 
% SetFwdVelRadiusRoomba(obj, -.1, inf);
% pause(1.4);
% SetFwdVelRadiusRoomba(obj, 0, 0);
% pause(.5)
% 
% SetFwdVelRadiusRoomba(obj, .15, eps);
% pause(1);
% SetFwdVelRadiusRoomba(obj, 0, 0);
% pause(.5)
% 
% SetFwdVelRadiusRoomba(obj, .15, -eps);
% pause(1);
% SetFwdVelRadiusRoomba(obj, 0, 0);
% pause(.5)

obj = RoombaInit(1);

dist = .3;          %set distance to travel
dist_trav = 0;      %init distance
pause(.5);
while(dist_trav < dist)
    SetFwdVelRadiusRoomba(obj, .3, inf); %tell roomba to move forward (speed is .3, inf used for radius)
    dist_trav = dist_trav + DistanceSensorRoomba(obj); %find distance travelled
end
SetFwdVelRadiusRoomba(obj, 0,0); %stop roomba
pause(.5);

turnAngle(obj, .2, 180); %turn around
pause(.5);

dist = .3;          %reinitialize distances
dist_trav = 0;

while(dist_trav < dist)
    SetFwdVelRadiusRoomba(obj, .3, inf); %tell roomba to move forward (speed is .3, inf used for radius)
    dist_trav = dist_trav + DistanceSensorRoomba(obj); %find distance travelled
end
SetFwdVelRadiusRoomba(obj, 0,0); %stop roomba
pause(.5);

turnAngle(obj, .2, -180); %turn back around