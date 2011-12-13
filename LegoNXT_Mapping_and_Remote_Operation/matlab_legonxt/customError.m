function customError(whattodo, varargin)
% customError  Generate a error with a customized stack trace
%
%  customError(whattodo, ...) generates an error with the stack
%   trace specified by whattodo. The remaining arguments specify
%   the formatting of the error message (see SPRINTF).
%   whattodo can be one of:
%    'new'  -  The current message will be the only one on the stack trace.
%    'add'  -  The current message is added to the top of the stack trace.
%    'replacetop' - The current message replaces the message currently on 
%             the top of the stack trace.
%
%  Examples:
%   customError('new', 'Input parameter is not valid');
%   customError('replacetop', 'Input parameter to %s is not valid: %d', ...
%                      'myfunction', 17);
%

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

newMsg = sprintf(varargin{:});
switch whattodo
    case 'new'
        errm.message = newMsg;
    case 'add'
        le = lasterror;
        errm.message = sprintf('%s\n%s',newMsg,le.message);
    case 'replacetop'
        le = lasterror;        
        newlineIdx = strfind(le.message, 10); % search for newline
        if ~isempty(newlineIdx)
            le.message(1:newlineIdx(1))=[]; % delete top message
        end
        errm.message = sprintf('%s\n%s',newMsg,le.message);        
    otherwise
        error('Unknown option to customError');
end
        
errm.identifier = '';
errm.stack = struct('file',cell(0,1), ...
                    'name',cell(0,1),...
                    'line',cell(0,1));
error(errm);
