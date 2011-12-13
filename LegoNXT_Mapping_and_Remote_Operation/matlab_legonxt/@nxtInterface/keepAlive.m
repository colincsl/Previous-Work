function msecTillSleep = keepAlive(nxt, verbosity)
% keepAlive   Resets the internal sleep timer of the LEGO NXT
% 
%   keepAlive(OBJ) sends a direct command to the LEGO NXT to reset its 
%   internal sleep timer. The NXT's timer is a counter that is decremented 
%   every millisecond; when it reaches zero, the NXT shuts itself off. The 
%   keepAlive() message resets the timer back to its starting value 
%   (typically 600000 milliseconds, that is, 10 minutes).
% 
%   M = keepAlive(OBJ) resets the NXT's sleep timer, and returns a 
%   value, M, that is the number of milliseconds until the next automatic
%   shutdown.

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

if ~exist('verbosity', 'var')
    verbosity = 'verbose';
end

if nargout == 0
    sendMessage(nxt, [ ...
        nxt.getNXTCommand('KEEPALIVE') ...
        ]); %#ok<NBRAK>
else
    [resp,status] = sendMessage(nxt, [...
        nxt.getNXTCommand('KEEPALIVE') ...
        ]); %#ok<NBRAK>

    if status == 0
        msecTillSleep = leBytesToInt(resp(1:4), 'uint32');
    else
        msecTillSleep = uint32(0);
    end
end

if ~strcmp(verbosity, 'silent')
    disp('KeepAlive message sent to the Lego NXT');
end
