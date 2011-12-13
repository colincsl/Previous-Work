function delete(obj)
% DELETE  Deletes an output port object
%
%   DELETE(OBJ) deletes an output port object. This stops any ongoing motor
%   movement or startSchedule(). The object should no longer be used and
%   should be removed from the workspace using CLEAR.
%

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

if obj.getRunning()
    stop(obj, 'coast'); 
end

startSchedule(obj, 'cancel');

