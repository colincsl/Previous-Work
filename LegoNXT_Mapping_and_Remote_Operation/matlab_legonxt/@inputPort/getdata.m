function val = getdata(obj)
% GETDATA  Get the current value from the sensor 
%
%   V = getdata(OBJ) returns the current value, V, from the sensor
%   connected to the input port. If the sensor is not of type 'distance', 
%   the interpretation of V depends upon the mode (see inputPort/get). If 
%   there is a communication problem, V is an empty array ([]).
%
% See also inputPort/set

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/3

val = getdata(obj.getSensorObj());
