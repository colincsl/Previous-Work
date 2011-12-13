function out = get(obj, varargin)
% GET  Get Distance sensor object properties
%
%   V = GET(OBJ, 'P') returns the value, V, of the property P for 
%   the Distance sensor object.
%
%   S = GET(OBJ, 'P1', 'P2', ...) returns a structure, S, where
%   S.V1 is the value of property P1, S.V2 is the value of property P2, 
%   and so on. 
%
%   S = GET(OBJ) returns a structure, S, with the current values of all 
%   the properties of the Distance sensor object.
% 
%   The list of properties recognized by GET:
%
%    Property       Value
%   ----------------------------------
%   'Port'          The input port to which the sensor is connected 
%   'Type'          The type of the sensor. Always returns 'distance'.
%   'Info'          Other information about the distance sensor, such as
%                   the units used and the sensor version.
%   'NxtType'       The distanceSensor object configures the input port
%                   to talk to a digital sensor, using a code recognized
%                   by the NXT firmware. The 'NxtType' gives the name for 
%                   this code so that it can be looked up in the NXT 
%                   documentation or in legoNXTConstants.m. 
%   'Mode'          The mode of the input port to which the sensor is 
%                   connected. Always returns 'RAW'.
%
%
% See also distanceSensor/set

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

if isempty(varargin)
    varargin = {'port', 'type', 'nxttype', 'mode', 'info'};
end

out = [];

for i=1:length(varargin)
    
   switch lower(varargin{i})
       case 'port'
           [ignore, portName] = obj.getInputPort();
           out.Port = portName;     

       case 'type'
           out.Type = obj.getSensorType();

       case 'nxttype'
           [ignore,nxtTypeTxt] = obj.getNXTSensorType();
           out.NxtType = nxtTypeTxt;
           
       case 'mode',
           [ignore,modeTxt] = obj.getNXTSensorMode();
           out.Mode = modeTxt;
           
       case 'info'
           out.Info = getSensorInfo(obj);
                                 
       otherwise
           customError('new', ...
               'distanceSensor/get: ''%s'' is not a valid parameter', ...
               varargin{i});
   end

end

if length(varargin)==1
    fnames = fieldnames(out);
    out = out.(fnames{1});
end
