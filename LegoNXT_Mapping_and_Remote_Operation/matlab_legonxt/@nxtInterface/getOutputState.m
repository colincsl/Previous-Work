function s = getOutputState(obj, outputPort)
% GetOutputState  Gets the state of a motor on the LEGO NXT
%
%   S = getOutputState(OBJ, P) returns a structure, S, that specifies
%   the state of the motor connected to Port P on the LEGO NXT. P 
%   must be 0, 1 or 2 (corresponding to output ports 'A', 'B' and 'C',
%   respectively).
% 
%   The structure S has the following fields. The first seven fields
%   are the same as those used by setOutputState():
%      port           - The output port whose status is being queried
%      powerSetPoint   
%      mode
%      regulationMode
%      turnRatio
%      runState
%      tachoLimit
%   The following three fields are unique to getOutputState():
%      tachoCount
%      blockTachoCount
%      rotationCount  - The current value of the rotation sensor
%
%   See also nxtInterface/setOutputState, nxtInterface/resetMotorPosition

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

[resp,status] = sendMessage(obj, [...
    obj.getNXTCommand('GETOUTPUTSTATE') ...
    uint8(outputPort) ...
    ]);

if status == 0
    s.port = resp(1);
    s.powerSetPoint = leBytesToInt(resp(2), 'int8');
    s.mode = resp(3);
    s.regulationMode = resp(4);
    s.turnRatio = leBytesToInt(resp(5), 'int8');
    s.runState = resp(6);
    s.tachoLimit = leBytesToInt(resp(7:10), 'uint32');
    s.tachoCount = leBytesToInt(resp(11:14), 'int32');
    s.blockTachoCount = leBytesToInt(resp(15:18), 'int32');
    s.rotationCount = leBytesToInt(resp(19:22), 'int32');
else
    s = [];
end
