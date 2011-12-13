function setOutputState(obj, s)
%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

if obj.doShowMessages
    fprintf('setOutputState: port=%d, power=%d, mode=0x%x, reg=0x%x, run=0x%x\n', ...
        s.port, s.powerSetPoint, s.mode, s.regulationMode, s.runState);
end

