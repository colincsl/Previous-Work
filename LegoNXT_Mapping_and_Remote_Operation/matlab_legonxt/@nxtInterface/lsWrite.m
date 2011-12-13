function lsWrite(obj, inputPort, message, responseLen)
% lsWrite  Writes bytes to an I2C device connected to the LEGO NXT
% 
%   lsWrite(OBJ, P, M, L) writes a sequence of bytes to a digital device 
%   that is connected to input port P of the LEGO NXT and uses 
%   the low-speed digital (I2C) communication protocol. 
%
%    P should be 0, 1, 2 or 3 (corresponding to input ports '1', '2', 
%     '3' and '4', respectively).
%    M is the byte sequence to be sent. It should be a Nx1 array, and
%      each element should an integer in the range [0,255].
%    L is the expected length of the response from the I2C device. 
%    
%   See also nxtInterface/lsGetStatus, nxtInterface/lsRead

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

maxLen = obj.getNXTConstant('MAX_LSDATA_LEN');

if (length(message) > maxLen) || (responseLen > maxLen)
    customError('new', ...
        'Message and response must both be less than %d bytes', maxLen);
end

% It turns out to be important to get a response to the LSWRITE message
% The communication with the ultrasonic sensor (the subsequent LSREAD
% commands) do not work otherwise.

[resp,status] = sendMessage(obj, [...
    obj.getNXTCommand('LSWRITE') ...
    uint8(inputPort) ...
    uint8(length(message)) ...
    uint8(responseLen) ...
    uint8(message) ...
    ]); %#ok<NASGU>


