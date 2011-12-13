function set(obj, varargin)
% SET Set Lego NXT interface object properties
% 
%   V = SET(OBJ, 'P', V) sets the property P of the LEGO-NXT interface 
%   object to the value V.
%
%   SET(OBJ) displays a list of recognized properties, as well the 
%   range of allowed values for each property.
% 
%   The list of properties recognized by SET:
%
%    Property          Values
%   ----------------------------------
%   'ResponseCheck'    'always' => always check for responses from the 
%                          Lego NXT afer sending a direct command.
%                      'auto' (default) => check for responses only when 
%                          needed, e.g. when the command is a request 
%                          for information. 
%   'NumRetries'       The number of times to try resending a message to 
%                      the LEGO NXT if there are timeout problems. This
%                      should be an integer equal to, or greater than, 0.
%
% See also nxtInterface/get

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

obj.checkDeleted();

if numel(varargin)==0,
    fprintf('	ResponseCheck: [ auto | always ]\n');
    fprintf('	NumRetries: an integer that is 0 or greater\n');
    return;
end

p = inputParser;
p.FunctionName = 'legoNXT/set';
p.CaseSensitive = false;
p.addParamValue('ResponseCheck', [], ...
    @(x) checkString(x, {'auto', 'always'}));
p.addParamValue('NumRetries', []);
p.parse(varargin{:});

if ~isempty(p.Results.ResponseCheck)
    switch p.Results.ResponseCheck
        case 'auto',
            obj.setAlwaysCheckResponse(false);
        case 'always',
            obj.setAlwaysCheckResponse(true);
    end
end

if ~isempty(p.Results.NumRetries)
    try
        obj.setNumRetries(p.Results.NumRetries);
    catch
        customError('replacetop', 'nxtInterface/set: Unable to set NumRetries');
    end
end

end % of SET


%% ------------------------
function out = checkString(str, paramList)
    out = ~isempty(strmatch(lower(str), paramList));
end

