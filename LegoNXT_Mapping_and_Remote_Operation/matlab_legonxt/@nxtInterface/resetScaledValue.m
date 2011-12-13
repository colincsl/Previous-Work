function resetScaledValue(obj, inputPort)
% resetScaledValue   Resets "scaled" sensor values
% 
%   resetScaledValue(OBJ, P) resets the scaled value returned by the 
%   analog sensor connected to input port P. More precisely, it resets
%   the 'scaledValue' field in the structure returned by getInputValue().
% 
%     P should be 0, 1, 2 or 3 (corresponding to input ports '1', '2' '3' 
%     and '4', respectively).
% 
%     Note: The resetting is applicable only when the sensor mode is set 
%     to TRANSITIONCNT or PERIODCOUNTER (where the scaled value is a 
%     cumulative count of some sort). 
%   
%   See also nxtInterface/setInputValue, nxtInterface/getInputValue

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

sendMessage(obj, [ ...
    obj.getNXTCommand('RESETINPUTSCALEDVALUE') ...
    uint8(inputPort) ...
    ]);
