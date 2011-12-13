function resetMotorPosition(obj, outputPort, resetRelativeToLastPos)
% resetMotorPosition  Resets the counters for a motor on the LEGO NXT
% 
%   resetMotorPosition(obj, P, REL) resets the position counters of the 
%   motor connected to Port P on the LEGO NXT. If REL=1, the counters
%   are reset relative to the last movement.  
% 
%   See also nxtInterface/setOutputState, nxtInterface/resetMotorPosition

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

sendMessage(obj, [...
    obj.getNXTCommand('RESETMOTORPOSITION') ...    
    uint8(outputPort) ...
    uint8(resetRelativeToLastPos) ...
    ]);

