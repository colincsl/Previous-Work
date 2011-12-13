function setInputMode(obj, port, sensorType, sensorMode)
%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

if obj.doShowMessages
    fprintf('setInputMode: port %d, type 0x%x, mode 0x%x\n', ...
    port, sensorType, sensorMode);
end

