function s = getOutputState(obj, outputPort)
%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

if obj.doShowMessages
    fprintf('getOutputState: port %d', outputPort);
end

s.port = outputPort;
s.powerSetPoint = 17;
s.mode = 0;
s.regulationMode = 0;
s.turnRatio = 0;
s.runState = 0;
s.tachoLimit = 0;
s.tachoCount = 12345;
s.blockTachoCount = 12345;
s.rotationCount = 12345;
