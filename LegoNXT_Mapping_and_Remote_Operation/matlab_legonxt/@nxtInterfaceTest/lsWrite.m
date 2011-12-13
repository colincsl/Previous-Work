function lsWrite(obj, inputPort, message, responseLen)
%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

if obj.doShowMessages
    fprintf('lsWrite: input port %d, message = ', inputPort);
    fprintf('0x%x ', message);
    fprintf(', responseLen = %d\n', responseLen);
end

