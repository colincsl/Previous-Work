function out = get(obj, varargin)
%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

if obj.doShowMessages
    fprintf('get nxtInterfaceTest: ');
    fprintf('%s ', varargin{:});
    fprintf('\n');
end

if isempty(varargin)
    varargin = {'SerialPort', 'Timeout', 'NumRetries', 'ResponseCheck'};
end

out = [];

for i=1:length(varargin)
    
   switch lower(varargin{i})
       case 'serialport'       
           out.SerialPort = '**TEST**';
             
       case 'timeout'
           out.Timeout = 0.5;
           
       case 'numretries'
           out.NumRetries = 2;
           
       case 'responsecheck'
           out.ResponseCheck = 'always';
                                 
       otherwise
           error('Unknown parameter to GET (%s)', varargin{i});
   end

end

if length(varargin)==1
    fnames = fieldnames(out);
    out = out.(fnames{1});
end
