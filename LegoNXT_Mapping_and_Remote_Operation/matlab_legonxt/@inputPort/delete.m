function delete(obj)
% DELETE  Deletes an input port object
%
%   DELETE(OBJ) deletes an input port object. The object should no longer 
%   be used and should be removed from the workspace using CLEAR.
%

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

obj.setSensorObj('none');

