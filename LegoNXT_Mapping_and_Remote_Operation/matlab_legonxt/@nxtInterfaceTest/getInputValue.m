function s = getInputValue(obj, inputPort)
%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

if obj.doShowMessages
    fprintf('getInputValue: port %d\n', inputPort);
end

if rand(1) < 1
    s.port = inputPort;
    s.isValid = 0;
    s.isCalibrated = 0;
    s.sensorType = 0;
    s.sensorMode = 0;
    s.rawValue = 123;
    s.normalizedValue = 123;    
    s.scaledValue = ceil(rand(1,1)*100);
    s.calibratedValue = 0;
else
    s = [];
end


