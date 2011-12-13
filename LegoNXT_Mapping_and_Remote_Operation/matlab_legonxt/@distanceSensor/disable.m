function disable(obj)
% DISABLE  Disables data collection from the distance sensor
% 
%    disable(OBJ)  disables the collection of data from an ultrasonic
%    distance sensor. 
%
% See also distanceSensor/enable, distanceSensor/getdata

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

if ~obj.getEnabled()
    return;   
end

nxti = obj.getNXTInterfaceObj();
inputPort =  obj.getInputPort();

% Assume that the port is configured to talk to a digital sensor

% turn off the ultrasonic digital sensor
usCmds = obj.getUltrasonicCommands();
cmd = usCmds.SENSOR_OFF(1:end-1);
responseLen = usCmds.SENSOR_OFF(end);

lsWrite(nxti, inputPort, cmd, responseLen);

obj.setEnabled(false);

