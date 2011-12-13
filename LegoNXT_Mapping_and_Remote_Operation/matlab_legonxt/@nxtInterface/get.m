function out = get(obj, varargin)
% GET Get Lego NXT interface object properties
% 
%   V = GET(OBJ, 'P') returns the value, V, of the property P for 
%   the LEGO-NXT interface object.
%
%   S = GET(OBJ, 'P1', 'P2', ...) returns a structure, S, where
%   S.V1 is the value of property P1, S.V2 is the value of property P2, 
%   and so on. 
%
%   V = GET(OBJ) returns a structure, V, with the current values of all 
%   the properties of the LEGO-NXT interface object. Each fieldname is the
%   name of a property, and the field value is the corresponding property 
%   value.
% 
%   The list of properties recognized by GET:
%
%    Property          Value
%   ----------------------------------
%   'SerialPort'       A string identifying the Bluetooth serial 
%                      port (e.g., 'COM40')
%   'Timeout'          The timeout value (in seconds) when reading from,
%                      or writing to, the Bluetooth serial port.
%   'NumRetries'       The number of times to try resending a message to 
%                      the LEGO NXT if there are timeout problems.
%   'ResponseCheck'    A string indicating whether OBJ should always 
%                      check for responses from the LegoNXT. 
%
% See also nxtInterface/set
% 

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

obj.checkDeleted();

if isempty(varargin)
    varargin = {'SerialPort', 'Timeout', 'NumRetries', 'ResponseCheck'};
end

out = [];

for i=1:length(varargin)
    
   switch lower(varargin{i})
       case 'serialport'       
           out.SerialPort  = obj.getSerialPortInfo();

       case 'timeout'
           [ignore, out.Timeout] = obj.getSerialPortInfo();
           
       case 'numretries'
           out.NumRetries = obj.getNumRetries();
           
       case 'responsecheck'
           if obj.getAlwaysCheckResponse()
               out.ResponseCheck = 'always';
           else
               out.ResponseCheck = 'auto';
           end
                                 
       otherwise
           customError('new', ...
               'nxtInterface/get: ''%s'' is not a valid parameter', ...
               varargin{i});             
   end

end

if length(varargin)==1
    fnames = fieldnames(out);
    out = out.(fnames{1});
end
