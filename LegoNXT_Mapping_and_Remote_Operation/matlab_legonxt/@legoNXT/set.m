function set(obj, varargin)
% SET  Set legoNXT object properties
% 
%   V = SET(OBJ, 'P', V) sets the property P of the legoNXT object OBJ
%   to the value V.
%
%   SET(OBJ) displays a list of recognized properties, as well the 
%   range of allowed values for each property.
%
%   The list of properties recognized by SET:
%
%   Property            Description
%   ----------------------------------------------
%   'AutoKeepAlive'    Can be 'on' or 'off'. If on, a "keep alive" is
%                      periodically sent to the LEGO NXT brick to ensure
%                      that it does not go into sleep mode. 
%
% See also legoNXT/get

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

obj.checkDeleted();

if numel(varargin)==0,
    fprintf('	AutoKeepAlive: [ on | off ]\n');
    return;
end

p = inputParser;
p.FunctionName = 'legoNXT/set';
p.CaseSensitive = false;
p.addParamValue('AutoKeepAlive', []);
p.parse(varargin{:});

if ~isempty(p.Results.AutoKeepAlive)
    switch p.Results.AutoKeepAlive
        case {'on', 'off'}
            autoKeepAlive(obj, p.Results.AutoKeepAlive);
        otherwise
            customError('new', 'AutoKeepAlive should be ''on'' or ''off''');
    end
end

