function set(obj, varargin)
% SET  Set input port object properties
% 
%   V = SET(OBJ, 'P', V) sets the property P of the inputPort object OBJ
%   to the value V.
%
%   SET(OBJ) displays a list of recognized properties, as well the 
%   range of allowed values for each property.
%
%   The list of properties recognized by SET:
%
%   Property    Description
%   ----------------------------------------------
%   'Type'     The type of the sensor connected to this input port.
%              see 'help inputPort' for a list of valid values.
% 
%   'Mode'     This specifies how the raw sensed values are transformed
%              by the NXT firmware, and determines the value returned
%              by inputPort/getdata. Possible values for this property
%              are given below. THIS PROPERTY IS NOT APPLICABLE IF 
%              THE TYPE IS 'distance'
%
%             Value              Summary of transformation
%             ----------------------------------------------------
%             'RAW'              No transformation applied 
%             'BOOLEAN'          0 (< 45% of range), 1(> 55% of range)
%             'TRANSITIONCNT'    # of transitions between 1 and 0
%             'PERIODCOUNTER'    # of transitions from 0 -> 1 -> 0
%             'PCTFULLSCALE'     scaled to [0,100] range [default]
%             'CELSIUS'          degrees Celsius (0.1 deg)
%             'FAHRENHEIT'       degrees Fahrenheit (0.1 deg)
%
% See also inputPort/get

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

if numel(varargin)==0,
    fprintf('	type: [none | touch | temperature | light | light_fon |\n');
    fprintf('          sound | sound_all | distance]\n');
    fprintf('	mode: [RAW | BOOLEAN | TRANSITIONCNT | PERIODCOUNTER |\n');
    fprintf('          PCTFULLSCALE | CELSIUS | FAHRENHEIT]\n');
    return;
end

p = inputParser;
p.FunctionName = 'inputPort/set';
p.CaseSensitive = false;
p.addParamValue('type', []);
p.addParamValue('mode', []);

p.parse(varargin{:});
 
if ~isempty(p.Results.type) 
    try
        obj.setSensorObj(p.Results.type);
    catch
        customError('replacetop', 'inputPort/set: Unable to set sensor type');
    end
end

if ~isempty(p.Results.mode)
    try
        set(obj.getSensorObj(), 'mode', p.Results.mode);
    catch
        customError('replacetop', 'inputPort/set: Unable to set sensor mode');
    end
end

