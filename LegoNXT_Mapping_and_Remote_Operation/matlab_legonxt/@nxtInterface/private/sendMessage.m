function [resp,status] = sendMessage(nxt, msg)
% Sends a message to the LEGO NXT. msg should be a byte array, and
% nxt should be a nxtInterface object.
%
%  sendMessage(nxt, msg)
%    The message is sent. A response from the NXT is not requested (unless
%    if the 'ResponseCheck' property of the nxtInterface object is set 
%    to 'always').
%
%  [resp,status] = sendMessage(nxt, msg)
%    The message is sent, and a response is requested from the NXT.
%    resp is the response (a byte array), and status is a status code.
%    status=0 indicates that the command was successful (see
%    statusCode2Text() for interpretation of other status codes).
%   

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

nxt.checkDeleted();

serialObj = nxt.getSerialObj();

nxt_SEND_RESPONSE = nxt.getNXTConstant('HDR_SEND_RESPONSE');
nxt_NO_RESPONSE = nxt.getNXTConstant('HDR_NO_RESPONSE');

if ~strcmp(serialObj.Status,'open')
    % Serial port should have been opened when the object was created.
    % Most likely it was closed by some other program
    fprintf('nxtInterface: Serial connection (%s) is not open\n', serialObj.Port);
    try
        openSerialPort(nxt);
    catch
        customError('replacetop', 'Unable to re-open the Serial connection');
    end
    fprintf('Connection successfully re-opened\n');
end

% check whether response is needed
if (nargout > 0) || nxt.getAlwaysCheckResponse()
    msg = [nxt_SEND_RESPONSE msg];
else
    msg = [nxt_NO_RESPONSE msg];
end

% dispatch the message
msgLength = intToLeBytes(uint16(length(msg)));
maxTrials = nxt.getNumRetries() + 1; % ensure we do it at least once
success = false;

for trialNumber=1:maxTrials
    try
        fwrite(serialObj, uint8([msgLength msg]) ); % with timeout
        success=true;
        break;
    catch
        if trialNumber < maxTrials
            % fprintf('LEGO NXT timeout -- Resending %s message\n', ...
            %    nxt.nxtCommand2Text(msg(2)));
            pause(0.3);
        else
            break;
        end
    end
end

if ~success
    customError('replacetop', 'Error sending a message to the NXT');
end

% get response if needed
if msg(1) == nxt_SEND_RESPONSE
    
    ret = waitForResponse(serialObj); % with timeout
    if isempty(ret)
        customError('new', 'Timed out waiting for NXT response');
    elseif ret(1) ~= 2 || numel(ret) < 3
        customError('new', 'Received garbled message from NXT');
    end
    
    cmdCode = ret(2);
    statusCode = ret(3);
    if statusCode ~= 0
        cmdName = nxt.nxtCommand2Text(cmdCode);
        statusName = statusCode2Text(statusCode);        
        errorText = sprintf('Problem with NXT command %s (0x%x): %s (0x%x)', ...
            cmdName, cmdCode, statusName, statusCode);
        customError('new', errorText); 
    end

    if nargout > 0, resp = ret(4:end); end
    if nargout > 1, status = statusCode; end
    
else
    % No response requested
    assert(nargout == 0);
end


