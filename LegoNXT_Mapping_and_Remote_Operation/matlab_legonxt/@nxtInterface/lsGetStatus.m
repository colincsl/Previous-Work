function [status,bytesAvailable] = lsGetStatus(obj, inputPort)
% lsGetStatus  Returns bytes available to be read from an I2C device 
% 
%   [S, B] = lsGetStatus(OBJ, P) returns the number of bytes available
%   to be read from a digital device that is connected to input port P 
%   of the LEGO NXT and uses the low-speed digital (I2C) communication 
%   protocol. P should be 0, 1, 2 or 3 (corresponding to input ports '1', 
%   '2', '3' and '4', respectively).
%  
%    S is the status of the I2C communication. It is 0 if the 
%       communication was successful.
%    B is the number of bytes available to be read from the digital 
%      device. It is only valid if status S is zero.
%   
%   See also nxtInterface/lsRead, nxtInterface/lsWrite

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

[resp,status] = sendMessage(obj, [...
    obj.getNXTCommand('LSGETSTATUS') ...
    uint8(inputPort) ...
    ]);

if status == 0
    bytesAvailable = uint8(resp(1));
else
    bytesAvailable = uint8(0);
end
