function result = waitForResponse(serialObj)
% Waits for a response over a serial port. 
% The response is stored in result (a byte array).
% if isempty(result), then the wait has timed out.

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

packLength = uint8(fread(serialObj, 2)); % with timeout
if ~isempty(packLength)
    packLength = leBytesToInt(packLength, 'uint16');
    result = uint8(fread(serialObj, serialObj.BytesAvailable));
%     if packLength ~= length(result)
%         warning('LEGONXT:unexpectedResponse', 'Problem with response message length');
%     end
else
    % timeout
    result = [];
end

