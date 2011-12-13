function obj = distanceSensor(nxtIntObj, portid)
% distanceSensor  Create a LEGO NXT Ultrasonic Distance Sensor object 
% 
%   OBJ = distanceSensor(NXTI, P) constructs a LEGO NXT Ultrasonic 
%   distance sensor object, OBJ.
%   
%    NXTI - A valid nxtInterface object
%    P    - The input port to which the analog sensor is connected. P 
%           should be '1', '2', '3' or '4'.
%
%   See also distanceSensor/Contents, analogSensor, nxtInterface

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

% The ultrasonic sensor is a digital sensor, and communicating with it 
% involves using a low-speed serial protocol (I2C) via the NXT brick.

%------------------------
% Specify and initialize member variables

m_nxtInterfaceObj = [];
m_isEnabled = false;
m_portInfo = struct('label', [], 'number', []);
m_nxtSensorConstants = [];
m_nxtUltrasonicConstants = [];
m_sensorConfig = struct('type', [], ...
                        'nxtTypeTxt', [], 'nxtType', [], ...
                        'nxtModeTxt', [], 'nxtMode', []);

initialize();
clear nxtIntObj portid 

%------------------------
% Create the handle to be returned to the caller

obj.getEnabled = @getEnabled;
obj.setEnabled = @setEnabled;
obj.getNXTInterfaceObj = @getNXTInterfaceObj;
obj.getInputPort = @getInputPort;
obj.getUltrasonicCommands = @getUltrasonicCommands;
obj.getSensorType= @getSensorType;
obj.getNXTSensorType = @getNXTSensorType;
obj.getNXTSensorMode = @getNXTSensorMode;

obj = class(obj, 'distanceSensor');
initializePort();

%%
    function initialize()
        if ~(isa(nxtIntObj, 'nxtInterface') || isa(nxtIntObj, 'nxtInterfaceTest'))
            customError('new', 'Input parameter is not an nxtInterface object');
        end
        m_nxtInterfaceObj = nxtIntObj;
        
        % ----
        m_nxtSensorConstants = legoNXTConstants('sensor');
        m_nxtUltrasonicConstants = legoNXTConstants('ultrasonicSensor');

        % ----
        nxtConstants = legoNXTConstants('nxtGeneric');
        m_portInfo.label = portid;
        m_portInfo.number = nxtConstants.inputPortName2Number(portid);
        if isempty(m_portInfo.number)
            customError('new', '''%s'' is not a valid input port', portid);
        end
        
    end

%%
    function out = getEnabled()
        out = m_isEnabled;
    end

    function setEnabled(newstate)
       m_isEnabled = logical(newstate);
    end

    function [portNum,portName] = getInputPort()
        portNum = m_portInfo.number;
        portName = m_portInfo.label;
    end

    function out = getNXTInterfaceObj()
        out = m_nxtInterfaceObj;
    end

    function out = getUltrasonicCommands()
        out = m_nxtUltrasonicConstants;
    end

    function out = getSensorType()
        out = 'distance';
    end

    function [nxtType,nxtTypeTxt] = getNXTSensorType()
        nxtType = m_nxtSensorConstants.type.LOWSPEED_9V;
        nxtTypeTxt = 'LOWSPEED_9V';        
    end

    function [mode,modetxt] = getNXTSensorMode()
        mode = m_nxtSensorConstants.mode.RAW;        
        modetxt = 'RAW';
    end

    function initializePort()
        setInputMode(getNXTInterfaceObj(), ...
            getInputPort(), ...
            getNXTSensorType(), ...
            getNXTSensorMode());
    end
%%
end

