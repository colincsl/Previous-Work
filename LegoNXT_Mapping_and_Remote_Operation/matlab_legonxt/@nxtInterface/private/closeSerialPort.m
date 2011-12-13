function closeSerialPort(nxt)
% Closes the serial port previously opened by a call to openSerialPort().
% nxt is an nxtInterface object.

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

serialObj = nxt.getSerialObj();

if isa(serialObj, 'serial')
    if strcmp(serialObj.status, 'open')
        fclose(serialObj);
    end
    % Note that we don't delete the serial object
    % This makes subsequent fopen()'s much faster.
end
