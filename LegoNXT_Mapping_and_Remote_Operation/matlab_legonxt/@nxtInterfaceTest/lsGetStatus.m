function [status,bytesAvailable] = lsGetStatus(obj, inputPort)
%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

if obj.doShowMessages
   fprintf('lsGetStatus: input port = %d\n', inputPort);
end

status = 0;
bytesAvailable = 1;

