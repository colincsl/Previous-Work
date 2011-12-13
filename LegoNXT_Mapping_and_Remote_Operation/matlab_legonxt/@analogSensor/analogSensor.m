function obj = analogSensor(nxtIntObj, portid, sensorType)
% analogSensor  Create a LEGO NXT Analog Sensor object 
% 
%   OBJ = analogSensor(NXTI, P, T) constructs a LEGO NXT analog sensor 
%   object, OBJ. 
%   
%    NXTI - A valid nxtInterface object
%    P    - The input port to which the analog sensor is connected. P 
%           should be '1', '2', '3' or '4'.
%    T    - The type of the analog sensor. T should be a string with
%           one of the following values:
%
%       T           Description
%     --------------------------------------------
%     'none'         no sensor connected 
%     'touch'        touch sensor
%     'temperature'  temperature sensor
%     'light'        light sensor (based on ambient light)
%     'light_fon'    light sensor with floodlight enabled
%     'sound'        sound sensor (human-perceivable frequencies)
%     'sound_all'    sound sensor (all frequencies)
%
%     It is not possible to change the type of a sensor once the 
%     sensor object is created. 
%
%   See also analogSensor/Contents, distanceSensor, nxtInterface

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

%------------------------
% Specify and initialize member variables

m_nxtInterfaceObj = [];
m_isEnabled = false;
m_portInfo = struct('label', [], 'number', []);
m_nxtSensorConstants = [];
m_sensorConfig = struct('type', [], ...
                        'nxtTypeTxt', [], 'nxtType', [], ...
                        'nxtModeTxt', [], 'nxtMode', []);

initialize();
clear nxtIntObj portid sensorType

%------------------------
% Create the handle to be returned to the caller

obj.getEnabled = @getEnabled;
obj.setEnabled = @setEnabled;
obj.getNXTInterfaceObj = @getNXTInterfaceObj;
obj.getInputPort = @getInputPort;
obj.getSensorType= @getSensorType;
obj.getNXTSensorType = @getNXTSensorType;
obj.getNXTSensorMode = @getNXTSensorMode;
obj.setNXTSensorMode = @setNXTSensorMode;
obj.initializePort = @initializePort;

obj = class(obj, 'analogSensor');
initializePort();

%%

    function initialize()
        if ~(isa(nxtIntObj, 'nxtInterface') || isa(nxtIntObj, 'nxtInterfaceTest'))
            customError('new', 'Input parameter is not an nxtInterface object');
        end
        m_nxtInterfaceObj = nxtIntObj;
        
        %---------
        m_nxtSensorConstants = legoNXTConstants('sensor');
        
        %---------
        nxtConstants = legoNXTConstants('nxtGeneric');
        m_portInfo.label = portid;
        m_portInfo.number = nxtConstants.inputPortName2Number(portid);
        if isempty(m_portInfo.number)
            customError('new', '''%s'' is not a valid input port', portid);            
        end

        %---------
        % mapping from sensorType to the type values used by
        % @nxtInterface/setInputMode
        type2nxttype = {'none'        'NO_SENSOR'
                        'touch'       'SWITCH'
                        'light'       'LIGHT_INACTIVE'
                        'light_fon'   'LIGHT_ACTIVE'
                        'sound'       'SOUND_DBA'
                        'sound_all'   'SOUND_DB'
                        'temperature' 'TEMPERATURE'};

        idx = strmatch(lower(sensorType), type2nxttype(:,1), 'exact');
        if isempty(idx)
            customError('new', '''%s'' is not a valid sensor type', sensorType);
        else
            nxtSensorType = type2nxttype{idx(1), 2};
        end

        % ----
        
        m_sensorConfig.type = sensorType;
        setNXTSensorType(nxtSensorType);
        setNXTSensorMode('PCTFULLSCALE'); % default mode
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

    function out = getSensorType()
        out = m_sensorConfig.type;
    end

    function [nxtType,nxtTypeTxt] = getNXTSensorType()
        nxtType = m_sensorConfig.nxtType;
        nxtTypeTxt = m_sensorConfig.nxtTypeTxt;        
    end

    function [mode,modetxt] = getNXTSensorMode()
        mode = m_sensorConfig.nxtMode;
        modetxt = m_sensorConfig.nxtModeTxt;
    end

    function setNXTSensorMode(newMode)
        if ~ischar(newMode)
            customError('new', 'sensor mode should be a string');
        end
        if isfield(m_nxtSensorConstants.mode, newMode)
            m_sensorConfig.nxtModeTxt = newMode;
            m_sensorConfig.nxtMode  = m_nxtSensorConstants.mode.(newMode);
        else
            customError('new', '''%s'' is not a valid sensor mode', newMode);
        end
    end

    function setNXTSensorType(newType)
        if ~ischar(newType)
            customError('new', 'NXT sensor type should be a string');
        end
        if isfield(m_nxtSensorConstants.type, newType)
            m_sensorConfig.nxtTypeTxt = newType;
            m_sensorConfig.nxtType = m_nxtSensorConstants.type.(newType);
        else
            customError('new', '''%s'' is not a valid NXT sensor type', newType);
        end
    end
    
    function initializePort()
        setInputMode(getNXTInterfaceObj(), ...
            getInputPort(), ...
            getNXTSensorType(), ...
            getNXTSensorMode());
    end    

end

