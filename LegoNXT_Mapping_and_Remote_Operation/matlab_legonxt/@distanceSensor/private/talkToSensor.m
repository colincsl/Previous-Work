function val = talkToSensor(nxt, inputPort, cmdinfo)
% Gets data from the NXT ultrasonic sensor using the I2C protocol
%  nxt - an nxtInterface object
%  inputPort - A number (0,1,2,3) indicating the input port 
%  cmdinfo - command sequence to transmit to the ultrasonic sensor.
%            This should be a byte array, and the last element 
%            should be the expected length of the response.
%  val - The data returned by the ultrasonic sensor

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

command = cmdinfo(1:end-1);
responseLen = cmdinfo(end);

lsWrite(nxt, inputPort, command, responseLen);

TIMEOUT_SECS = 1.0; % timeout in seconds
val = [];
if responseLen == 0
    % no response expected
    return;   
end

% responseLen > 0
% The NXT commands may generate an error. This error
% will get propagated to the caller.

[status,bytesAvailable] = lsGetStatus(nxt, inputPort);
basetime = clock;
while (bytesAvailable == 0) && (etime(clock, basetime) < TIMEOUT_SECS)
    pause(.02); % wait for 20 msec
    [status,bytesAvailable] = lsGetStatus(nxt, inputPort);
end
if bytesAvailable > 0
    [status,bytesRead,response] = lsRead(nxt, inputPort);
    val = response;
else
    warning('DistanceSensor:ResponseTimeout', ...
        'Timed out waiting for response from ultrasonic sensor');
end
