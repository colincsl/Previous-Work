function obj = legoNXT(comPort)
% LEGONXT  Creates a LegoNXT object
%
%   NXT = legoNXT('PORT') constructs a LEGO NXT object that uses the
%   "Direct command" Bluetooth API to communicate with the LEGO Mindstorms
%   NXT.  PORT is the name of the serial port (e.g., 'COM5', 'COM40') that
%   has been assigned by the Bluetooth driver
%
%   NXT = legoNXT('test') uses a "dummy" NXT Interface. This allows code 
%   using the legoNXT object to be exercised without a physical LEGO NXT 
%   system. 
%
%   Example: 
%       % To create a legoNXT object using Bluetooth serial port 'COM4'
%       nxt = legoNXT('COM4'); 
%
%       % To create an object with a dummy NXT interface
%       nxt = legoNXT('test');
%       start(nxt.PortA);
%       m = get(nxt.PortB);
%       val = getdata(nxt.Port1);
%
%   For general information on LEGO Mindstorms, see
%    http://mindstorms.lego.com/   

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

%------------------------
% Specify and initialize member variables

m_nxtInterfaceObj = [];
m_keepAliveTimer = [];
m_portObjects = [];

initialize();
clear comPort;

%------------------------
% Create the handle to be returned to the caller

obj.getNXTInterfaceObj = @getNXTInterfaceObj;
obj.getKeepAliveTimer = @getKeepAliveTimer;
obj.setKeepAliveTimer = @setKeepAliveTimer;
obj.getPortObject = @getPortObject;
obj.setDeleted = @setDeleted;
obj.checkDeleted = @checkDeleted;

obj = class(obj, 'legoNXT');
set(obj, 'AutoKeepAlive', 'on');


%%
    function initialize()
        try
            if strcmp(comPort, 'test')
                m_nxtInterfaceObj = nxtInterfaceTest('noprint');
            elseif strcmp(comPort, 'testd')
                m_nxtInterfaceObj = nxtInterfaceTest('print');
            else
                m_nxtInterfaceObj = nxtInterface(comPort);
            end
        catch
            customError('add', 'Unable to open a serial port connection to the Lego NXT');
        end
            
        % Initialize the ports (these cannot be changed once created).
        m_portObjects.PortA = outputPort(m_nxtInterfaceObj, 'PortA');
        m_portObjects.PortB = outputPort(m_nxtInterfaceObj, 'PortB');
        m_portObjects.PortC = outputPort(m_nxtInterfaceObj, 'PortC');
        m_portObjects.Port1 = inputPort(m_nxtInterfaceObj, 'Port1', 'none');
        m_portObjects.Port2 = inputPort(m_nxtInterfaceObj, 'Port2', 'none');
        m_portObjects.Port3 = inputPort(m_nxtInterfaceObj, 'Port3', 'none');
        m_portObjects.Port4 = inputPort(m_nxtInterfaceObj, 'Port4', 'none');        
    end


%% =========================================================
    function setDeleted()
        m_portObjects = [];
    end

    function checkDeleted()
        if isempty(m_portObjects);
            customError('new', 'Invalid legoNXT object\n');
        end
    end

    function out = getNXTInterfaceObj()
        out = m_nxtInterfaceObj;
    end

    function out = getPortObject(portname)
        out = m_portObjects.(portname);
    end

    function out = getKeepAliveTimer()
        out = m_keepAliveTimer;
    end

    function setKeepAliveTimer(timerObj)
        m_keepAliveTimer = timerObj;
    end


%% =========================================================
end
