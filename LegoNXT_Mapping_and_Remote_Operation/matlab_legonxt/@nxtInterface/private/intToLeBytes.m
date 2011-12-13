function byteArray = intToLeBytes(x)
% byteArray = intToLeBytes(x)
% Takes an integer and converts to a byte array sequence
% in little endian order(i.e., LSB first)
% Example: 
%  leBytesToInt(intToLeBytes(int32(-1000)), 'int32')

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

persistent systemIsLittleEndian

if isempty(systemIsLittleEndian)
    [ignore,ignore,endian]=computer;
    systemIsLittleEndian = (endian=='L');  % LSB occurs first
end

if ~isinteger(x)
    error('Input should be an integer datatype');
end

byteArray = typecast(x, 'uint8');

% if the system already uses little-endian order, then
% the bytes are in the proper sequence. Otherwise, 
% reorder them.
if ~systemIsLittleEndian
    byteArray = byteArray(end:-1:1);
end
      
