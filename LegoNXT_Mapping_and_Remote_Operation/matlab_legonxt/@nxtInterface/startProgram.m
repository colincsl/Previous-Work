function startProgram(obj, fileName)
% startProgram  Executes a program on the LEGO NXT
% 
%   startProgram(OBJ, FN) sends a direct command to the LEGO NXT to run
%   the program with filename FN.
% 
%   Note: 
%    1) The program file has to be already present on the NXT. 
%    2) Filenames on the NXT can be at most 19 characters.
%       (15 character name + '.' + 3 character extension).
%    3) Program files on the NXT have extension '.rxe'
%
%   Examples:
%       startProgram(obj, 'Demo.rxe');
%       startProgram(obj, 'Untitled-1.rxe');
%
%   See also nxtInterface/stopProgram

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

maxLen = obj.getNXTConstant('MAX_FILENAME_LEN');

if length(fileName) > maxLen,
    customError('new', 'Filename cannot be longer than %d characters', ...
        maxLen);
end

sendMessage(obj, [
    obj.getNXTCommand('STARTPROGRAM') ...
    charsToBytez(fileName) ...
    ]);
