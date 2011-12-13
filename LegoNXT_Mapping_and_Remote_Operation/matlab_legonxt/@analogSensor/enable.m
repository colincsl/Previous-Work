function enable(obj)
% ENABLE  Enables collection of data from the analog sensor
% 
%    enable(OBJ)  intializes and enables the collection of data
%    from an analog sensor. It should be called before the first
%    call to GETDATA.
%
% See also analogSensor/disable, analogSensor/getdata

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

% Analog sensors don't need to be turned on or configured.  
% so enabling is a no-op.

obj.setEnabled(true);

