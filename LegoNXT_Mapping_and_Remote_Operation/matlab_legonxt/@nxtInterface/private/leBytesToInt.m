function out = leBytesToInt(array, dataType)
% out = leBytesToInt(array, dataType)
% Takes a byte sequence in little endian order (i.e., LSB first)
% and converts it to a native integer datatype.
% Example: 
%  leBytesToInt(intToLeBytes(int32(-1000)), 'int32')

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

persistent systemIsLittleEndian

if isempty(systemIsLittleEndian)
    [ignore,ignore,endian]=computer;
    systemIsLittleEndian = (endian=='L');  % LSB occurs first    
end

if ~isa(array, 'uint8')
    error('Array should be of type uint8');
end

% This will generate an error if length(array)
% is not appropriate for dataType, but it is
% simpler to expose the error than to handle it
% in some complicated way.
out = typecast(array, dataType);

% The data are assumed be in little-endian order already
% so nothing to do if system uses the same ordering.
if ~systemIsLittleEndian
   out = swapbytes(out); 
end
      
