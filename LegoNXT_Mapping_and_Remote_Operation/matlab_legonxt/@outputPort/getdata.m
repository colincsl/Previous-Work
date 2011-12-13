function val = getdata(obj)
% GETDATA  Get the current value of the rotation sensor
%
%   V = getdata(OBJ) returns the current value, V, from the rotation
%   sensor in the motor. V is in units of degrees. 
%

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

s = getOutputState(obj.getNXTInterfaceObj(), obj.getOutputPort());
val = s.rotationCount;

%     s.port = resp(1);
%     s.powerSetPoint = leBytesToInt(resp(2), 'int8');
%     s.mode = resp(3);
%     s.regulationMode = resp(4);
%     s.turnRatio = leBytesToInt(resp(5), 'int8');
%     s.runState = resp(6);
%     s.tachoLimit = leBytesToInt(resp(7:10), 'uint32');
%     s.tachoCount = leBytesToInt(resp(11:14), 'int32');
%     s.blockTachoCount = leBytesToInt(resp(15:18), 'int32');
%     s.rotationCount = leBytesToInt(resp(19:22), 'int32');


