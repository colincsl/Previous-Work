function [status,bytesRead,response] = lsRead(obj, inputPort)
%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

if obj.doShowMessages
    fprintf('lsRead: input port %d\n', inputPort);
end

status = 0;
bytesRead = 1;
response = ceil(rand(1,1)*100);

