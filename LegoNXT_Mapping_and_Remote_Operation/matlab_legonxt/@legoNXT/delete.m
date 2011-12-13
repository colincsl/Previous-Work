function delete(obj)
% DELETE Deletes a LegoNXT object
%
%   DELETE(OBJ) deletes an LEGONXT object. When OBJ is deleted, it 
%   becomes an invalid object and cannot be reconnected to the LEGO NXT.
%   It should be removed from the workspace with CLEAR. 
%
%   Note: DELETE closes the Bluetooth serial port used to communicate 
%   with the LEGO NXT. If the legoNXT object is created again, the 
%   serial port has to be re-opened and this may take a few seconds. 
%   

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

obj.checkDeleted();

delete(obj.getPortObject('PortA'));
delete(obj.getPortObject('PortB'));
delete(obj.getPortObject('PortC'));

delete(obj.getPortObject('Port1'));
delete(obj.getPortObject('Port2'));
delete(obj.getPortObject('Port3'));
delete(obj.getPortObject('Port4'));

set(obj, 'AutoKeepAlive', 'off');
delete(obj.getNXTInterfaceObj());
obj.setDeleted();
