function msecTillSleep = keepAlive(obj)
%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

if obj.doShowMessages
    fprintf('keepAlive: called at %s\n', datestr(now, 13));
end

msecTillSleep = 6000;
