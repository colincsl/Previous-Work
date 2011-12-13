function disable(obj)
% DISABLE  Disables data collection from the analog sensor
% 
%    disable(OBJ)  disables the collection of data from an analog 
%    sensor. 
%
% See also analogSensor/enable, analogSensor/getdata

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

% Analog sensors don't need to be turned on or configured.  
% hence disabling is also a no-op.

obj.setEnabled(false);
