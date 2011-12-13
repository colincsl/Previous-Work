function val = getdata(obj)
% GETDATA  Get the current value from the analog sensor
%
%   V = getdata(OBJ) returns the current value, V, from the analog
%   sensor. The interpretation of V depends upon the mode of the
%   sensor (see analogSensor/get). If there is a communication problem,
%   V is an empty array ([]).
%
%   The sensor must first be initialized by calling enable(OBJ).  
%
% See also analogSensor/set, analogSensor/enable

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

try
    s = getInputValue(obj.getNXTInterfaceObj(), obj.getInputPort());
catch
    s = [];
end

if isempty(s)
    [ignore,portName] = obj.getInputPort();
%     fprintf('Unable to get data from %s sensor on Port%s\n', ...
%         obj.getSensorType(), portName);
    val = [];
else
    val = s.scaledValue; % int16
end

% Fields in the structure s:
%   s.isValid  : uint8
%   s.sensorType : uint8
%   s.sensorMode : uint8
%   s.rawValue : uint16
%   s.normalizedValue : uint16
%   s.scaledValue : int16
