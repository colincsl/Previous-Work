function nxti = nxtInterface(comPort, timeoutSecs, numRetries)
% NXTINTERFACE Create a Lego Mindstorms NXT Interface object
%
%   NXT = nxtInterface('PORT') constructs an interface object to the 
%   LEGO Mindstorms NXT Brick. The interface uses the "Direct command" 
%   Bluetooth API for the Lego NXT.  PORT is the name of the serial port 
%   (e.g., 'COM5', 'COM40') that has been assigned by the Bluetooth driver. 
%
%     See BLUETOOTH.TXT for information on how  to set up the 
%     Bluetooth serial interface to the LEGO NXT. This must be 
%     done before nxtInterface() is called.
%
%   NXT = nxtInterface('PORT', T)  uses T as the timeout value
%   (in seconds) for the serial port communications. By default, 
%   T is 0.5 seconds.
%
%   NXT = nxtInterface('PORT', T, R)  uses R as the number of times 
%   to try resending the message if there are timeout problems. R should 
%   be an integer >= 0. By default, R is 2.
%
%   Examples:
%    % To construct an nxtInterface object
%      nxti = nxtInterface('COM40');
%
%    % To see the list of possible methods
%      methods(nxti)
%
%    % Examples of communication via the nxtInterface object
%      playTone(nxti, 1000, 300);
%      value = getBatteryLevel(nxti);
%      playSoundFile(nxt, 'Hello.rso', 0);
%
%   See also nxtInterface/Contents, legoNXT, nxtdemo
%
%   Related web sites: 
%    http://mindstorms.lego.com/   
%         For general information on LEGO Mindstorms
%    http://mindstorms.lego.com/Overview/NXTreme.aspx
%         For information on the Bluetooth Direct Command API

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

if ~exist('timeoutSecs', 'var')
    timeoutSecs = 0.5; % default timeout for serial i/o, in seconds
else
    ok = isnumeric(timeoutSecs) && numel(timeoutSecs)==1 && timeoutSecs > 0;
    if ~ok
        customError('new', 'timeoutSecs should be a positive number');
    end
end

if ~exist('numRetries', 'var')
    numRetries = 2; % number of times to retry sending data after a timeout
end

%------------------------
% Specify and initialize member variables
m_serialPortInfo = struct('comPort', [], 'timeOutSecs', []);
m_serialObj = [];
m_nxtConstants = [];
m_nxtCommands = [];
m_numRetries = [];
m_alwaysCheckResponse = false;

initialize();
clear comPort timeoutSecs numRetries

%------------------------
% Create the handle to be returned to the caller
nxti.getNumRetries = @getNumRetries;
nxti.setNumRetries = @setNumRetries;
nxti.getSerialObj = @getSerialObj;
nxti.setSerialObj = @setSerialObj;
nxti.setDeleted = @setDeleted;
nxti.checkDeleted = @checkDeleted;
nxti.getNXTConstant = @getNXTConstant;
nxti.getNXTCommand = @getNXTCommand;
nxti.getAlwaysCheckResponse = @getAlwaysCheckResponse;
nxti.setAlwaysCheckResponse = @setAlwaysCheckResponse;
nxti.nxtCommand2Text = @nxtCommand2Text;
nxti.getSerialPortInfo = @getSerialPortInfo;

% Create the class and initialize the object
nxti = class(nxti, 'nxtInterface');

% openSerialPort will either error or return a valid object
openSerialPort(nxti);

% Ensure that LEGO is responsive by asking for some data 
try
    msecTillSleep = keepAlive(nxti, 'silent');
    success = true;
catch
    success = false;
end

if ~success || msecTillSleep <= 0    
    msg = ['LEGO NXT is not responding to direct commands\n' ...
           '==> Turn the NXT off and on, re-establish the Bluetooth connection, and try again'];
    customError('new', msg);
end

set(nxti, 'ResponseCheck', 'auto');

%%
    function initialize()
        setNumRetries(numRetries);
        m_serialPortInfo.comPort = comPort;
        m_serialPortInfo.timeOutSecs = timeoutSecs;
        m_nxtConstants = legoNXTConstants('nxtGeneric');
        m_nxtCommands = legoNXTConstants('nxtCommands');        
    end

%% =========================================================

    function out = getNumRetries()
        out = m_numRetries;
    end

    function setNumRetries(val)
        if isnumeric(val) && numel(val)==1 && val >= 0 && rem(val,1)==0
            m_numRetries = val;
        else
            customError('new', 'numRetries should be a non-negative integer');
        end
    end

    function [comPort,timeoutSecs] = getSerialPortInfo()
        comPort = m_serialPortInfo.comPort;
        timeoutSecs = m_serialPortInfo.timeOutSecs;
    end
        
    function out = getSerialObj()
        out = m_serialObj;
    end

    function setSerialObj(newObj)
        m_serialObj = newObj;
    end

    function setDeleted()
        m_serialObj = [];
    end

    function checkDeleted()
        if isempty(m_serialObj);
            customError('new', 'Invalid nxtInterface object\n');
        end
    end

    function out = getNXTConstant(cmdName)
        out = m_nxtConstants.(cmdName);
    end

    function out = getNXTCommand(cmdName)
        out = m_nxtCommands.(cmdName);
    end

    function out = getAlwaysCheckResponse()
        out = m_alwaysCheckResponse;
    end

    function setAlwaysCheckResponse(newvalue)
        m_alwaysCheckResponse = logical(newvalue);
    end

    function cmdText = nxtCommand2Text(cmdID)
        cmdText = convertIDToText(m_nxtCommands, cmdID);
    end

%% =========================================================
end
