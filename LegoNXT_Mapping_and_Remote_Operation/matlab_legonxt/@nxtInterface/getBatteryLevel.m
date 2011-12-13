function millivolts = getBatteryLevel(obj)
% getBatteryLevel  Returns the current battery level of the LEGO NXT
% 
%   L = getBatteryLevel(OBJ) returns the current battery level, L, of the 
%   LEGO NXT. L is in units of millivolts. An L of 0 indicates a problem
%   during communication with the LEGO NXT

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

[resp,status] = sendMessage(obj, [...
    obj.getNXTCommand('GETBATTERYLEVEL') ...
    ]); %#ok<NBRAK>

if status == 0
    millivolts = leBytesToInt(resp(1:2), 'uint16');
else
    millivolts = uint32(0);
end

