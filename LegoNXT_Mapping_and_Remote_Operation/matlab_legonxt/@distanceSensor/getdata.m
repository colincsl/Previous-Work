function val = getdata(obj)
% GETDATA  Get the current value from the distance sensor
%
%   V = getdata(OBJ) returns the current value, V, from the ultrasonic
%   distance sensor. If there is a communication problem, V is an 
%   empty array ([]).
%
%   The sensor must first be initialized by calling enable(OBJ).  
%
% See also distanceSensor/set, distanceSensor/enable

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

if ~obj.getEnabled()
    enable(obj);
end

usCmds = obj.getUltrasonicCommands();
nxti = obj.getNXTInterfaceObj();
[inputPort,portName] =  obj.getInputPort();

try
    response = talkToSensor(nxti, inputPort, usCmds.READ_MEASBYTE0);
catch
%     fprintf('Unable to get data from distance sensor on Port%s\n', ...
%         portName);     
%     fprintf(' Ensure that the LEGO NXT is on, and that the \n');
%     fprintf(' sensor is connected to the correct input port.\n');
    response = [];
end

if isempty(response)
    val = [];
else    
    val = response(1);
end
