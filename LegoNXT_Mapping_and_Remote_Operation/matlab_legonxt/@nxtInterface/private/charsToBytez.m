function byteArray = charsToBytez(s)
% Produces a zero-terminated sequence of bytes
% from the character sequence s

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

if ~ischar(s)
    error('Input must be a string');
end

byteArray = [uint8(s) 0];

