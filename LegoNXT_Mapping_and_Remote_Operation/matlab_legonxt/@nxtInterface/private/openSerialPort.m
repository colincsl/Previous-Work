function openSerialPort(nxt)
% Opens the serial port connection. The connection should be closed
% using closeSerialPort. nxt is an nxtInterface object.

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

[comPort, timeoutSecs] = nxt.getSerialPortInfo();

serialObj = instrfind('Port', comPort);
if isempty(serialObj)
    % the serial port doens't exist, so create it
    serialObj = serial(comPort, 'BaudRate', 19200, ...
                  'DataBits', 8, 'Parity', 'none', 'StopBits', 1);              
   set(serialObj, 'timeout', timeoutSecs, 'errorFcn', @instrcallback);
else
   serialObj = serialObj(1); 
   serialObj.timeout = timeoutSecs;
end

if ~strcmp(serialObj.Status,'open')    
    try
        fprintf('Opening Serial port (%s) ... This may take a few seconds\n', serialObj.port);
        fopen(serialObj);
    catch
        delete(serialObj);
        customError('add', 'Unable to open Serial port (%s)', comPort);
    end
end

nxt.setSerialObj(serialObj);
