function delete(obj)
% DELETE Deletes a Lego Mindstorms NXT Interface object
%
%   DELETE(OBJ) closes the serial port associated with the  Lego NXT
%   interface object, OBJ. The object becomes invalid and cannot be
%   reconnected to the LEGO NXT. It should be removed from the workspace
%   with CLEAR.
%
%   Note: DELETE closes the Bluetooth serial port used to communicate 
%   with the LEGO NXT. If the nxtInterface object is created again, the 
%   serial port has to be re-opened and this may take a few seconds.
%

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

obj.checkDeleted();

% Once the serial port is closed, the next call to sendMessage 
% will throw an error.

closeSerialPort(obj);
obj.setDeleted();
