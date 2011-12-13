function stopProgram(obj)
% stopProgram   Stops the execution of a program on the LEGO NXT
%
%   stopProgram(OBJ) sends a direct command to the LEGO NXT to stop 
%   the execution of a program.
%
%   See also nxtInterface/startProgram

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

sendMessage(obj, [
    obj.getNXTCommand('STOPPROGRAM') ...
    ]); %#ok<NBRAK>

