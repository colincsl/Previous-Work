classdef Wii
%WII Summary of this class goes here
%   Detailed explanation goes here

   properties
       X;
       Y;
       Z;
       XA;
       YA;
       ZA;
       Dist;
       DistA;
       Lmotor;
       Rmotor;
       Mode;
       ExitProgram;
       
       motorXDiv;
       motorYDiv;
       
   end

   methods
       
    function obj = Wii(Lmotor, Rmotor, divX, divY)
        obj.Lmotor = Lmotor;
        obj.Rmotor = Rmotor;
        obj.XA = zeros(1000, 1);
        obj.YA = zeros(1000, 1);
        obj.DistA = zeros(1000, 1);
        obj.motorXDiv=divX;
        obj.motorYDiv=divY;
        %obj.Mode = 0;
        %obj.ExitProgram = 0;
    end
   end
end 
