function [status,bytesRead,response] = lsRead(obj, inputPort)
% lsRead  Reads bytes from an I2C device connected to the LEGO NXT
% 
%   [S,B,R] = lsRead(OBJ, P) reads bytes from a digital device that 
%   is connected to input port P of the LEGO NXT and uses the low-speed 
%   digital (I2C) communication protocol. P should be 0, 1, 2 or 3 
%   (corresponding to input ports '1', '2', '3' and '4', respectively).
% 
%    S is the status of the I2C communication. It is 0 if the 
%       communication was successful.
%    B is number of bytes that were read.
%    R is a array (of type UINT8) that is the actual sequence of bytes 
%      returned by the I2C device. Only the first B bytes are valid. 
% 
%   Note: Before calling lsRead(), check whether there are bytes available
%   to be read using lsGetStatus(). Otherwise, lsRead() may result in a 
%   timeout.
% 
%   See also nxtInterface/lsGetStatus, nxtInterface/lsWrite

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

[resp,status] = sendMessage(obj, [...
    obj.getNXTCommand('LSREAD') ...
    inputPort ...
    ]);

if status == 0
    bytesRead = uint8(resp(1));
    response = resp(2:end);
else
    bytesRead = uint8(0);
    response = [];
end
