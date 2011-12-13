function set(obj, varargin)
% SET  Set Analog sensor object properties
% 
%   V = SET(OBJ, 'P', V) sets the property P of the object OBJ to
%   the value V.
%
%   SET(OBJ) displays a list of recognized properties, as well the 
%   range of allowed values for each property.
%
%   The list of properties recognized by SET:
%
%   Property    Description
%   ----------------------------------------------
%   'Mode'      This specifies how the raw sensed values are transformed
%               by the NXT firmware, and determines the value returned
%               by analogSensor/getdata. Possible values for this property
%               are given below. The default value is 'PCTFULLSCALE'.
%
%             Value              Summary of transformation
%             ----------------------------------------------------
%             'RAW'              No transformation applied 
%             'BOOLEAN'          0 (< 45% of range), 1(> 55% of range)
%             'TRANSITIONCNT'    # of transitions between 1 and 0
%             'PERIODCOUNTER'    # of transitions from 0 -> 1 -> 0
%          ** 'PCTFULLSCALE'     scaled to [0,100] range [default]
%             'CELSIUS'          degrees Celsius (0.1 deg)
%             'FAHRENHEIT'       degrees Fahrenheit (0.1 deg)
%
% See also analogSensor/get

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

if numel(varargin)==0,
    fprintf('	mode: [RAW | BOOLEAN | TRANSITIONCNT | PERIODCOUNTER |\n');
    fprintf('          PCTFULLSCALE | CELSIUS | FAHRENHEIT]\n');
    return;
end

p = inputParser;
p.FunctionName = 'analogSensor/set';
p.CaseSensitive = false;
p.addParamValue('Mode', []);
p.parse(varargin{:});

if ~isempty(p.Results.Mode) 
    [ignore,oldModeTxt] = obj.getNXTSensorMode();
    try
        obj.setNXTSensorMode(p.Results.Mode);
    catch
        obj.setNXTSensorMode(oldModeTxt);
        customError('replacetop', 'analogSensor/set: Unable to set sensor mode');
    end        
    obj.initializePort();
    enable(obj);    
end
