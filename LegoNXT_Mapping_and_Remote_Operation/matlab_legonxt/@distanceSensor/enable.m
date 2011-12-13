function enable(obj)
% ENABLE  Enables collection of data from the distance sensor
% 
%    enable(OBJ)  intializes and enables the collection of data
%    from an ultrasonic distance sensor. It should be called before 
%    the first call to GETDATA. It is safe for this function to be
%    called twice (i.e., it is safe to enable an already-enabled
%    sensor).
%
% See also distanceSensor/disable, distanceSensor/getdata

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

% --------------------------
% Assume the input port has already been configured
% to read/write to a digital sensor

% Pause for 100 ms to give the NXT brick time to configure
% the port (otherwise the subsequent ultrasonic message
% may not the recognized).
    
pause(0.1);

% --------------------------
% configure the ultrasonic digital sensor 

usCmds = obj.getUltrasonicCommands();
cmd = usCmds.SENSOR_CONTINUOUS(1:end-1);
responseLen = usCmds.SENSOR_CONTINUOUS(end);

try
    lsWrite(obj.getNXTInterfaceObj(), ...
            obj.getInputPort(), ...
            cmd, ...
            responseLen);
    obj.setEnabled(true);        
catch
    fprintf('Problem enabling the distance sensor.\n');
    fprintf('Ensure that the LEGO NXT is on, and that the\n');    
    fprintf('sensor is connected to the correct input port.\n');
    obj.setEnabled(false);
end

