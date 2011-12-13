function obj = inputPort(nxtIntObj, portid, sensorType)
% inputPort  Create a LEGO NXT input port object 
% 
%   OBJ = inputPort(NXTI, P, T) constructs a LEGO NXT input port 
%   object, OBJ. It serves as an generic (and consistent) interface 
%   to different sensors that can be attached to a single input port.
%   
%    NXTI - A valid nxtInterface object
%    P    - The input port represented by this object. P should
%           be '1', '2', '3' or '4'.
%    T    - The type of the sensor connected to this input port. T 
%           should be a string with one of the following values:
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
%     'distance'     ultrasonic distance sensor
%
%     It is possible to change the type of a sensor once the 
%     input port object is created, using inputPort/set.
%
%   See also inputPort/set, outputPort, nxtInterface

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

% The inputPort object is a wrapper around the actual object, which
% is either an analogSensor or a distanceSensor. The actual sensor
% can be changed during the lifetime of the inputPort object (in 
% other words, the inputPort object allows one to have, and pass 
% around, a consistent reference).

%------------------------
% Specify and initialize member variables

m_nxtInterfaceObj = [];
m_portInfo = struct('label', [], 'number', []);
m_sensorObj = [];

initialize();
clear nxtIntObj portid sensorType

%------------------------
% Create the handle to be returned to the caller

obj.getSensorObj = @getSensorObj;
obj.setSensorObj = @setSensorObj;

obj = class(obj, 'inputPort');

%%

    function initialize()
        if ~(isa(nxtIntObj, 'nxtInterface') || isa(nxtIntObj, 'nxtInterfaceTest'))
            customError('new', 'Input parameter is not an nxtInterface object');
        end
        m_nxtInterfaceObj = nxtIntObj;

        %-------
        nxtConstants = legoNXTConstants('nxtGeneric');
        if length(portid)>4 && strcmpi(portid(1:4), 'port')
            portid(1:4) = [];
        end
        m_portInfo.label = portid;
        m_portInfo.number = nxtConstants.inputPortName2Number(portid);
        if isempty(m_portInfo.number)
            customError('new', '''%s'' is not a valid input port', portid);
        end        
        
        %-------
        setSensorObj(sensorType);
    end

%%

    function setSensorObj(newSensorType)
        if ~isempty(m_sensorObj)
            disable(m_sensorObj);
        end
        newSensorType = lower(newSensorType);        
        switch newSensorType
            case {'none' 'touch' 'light' 'light_fon' ...
                  'sound' 'sound_all' 'temperature' };
                m_sensorObj = analogSensor(m_nxtInterfaceObj, ...
                                           m_portInfo.label, ...
                                           newSensorType);
            case 'distance'
                m_sensorObj = distanceSensor(m_nxtInterfaceObj, ...
                                             m_portInfo.label);
            otherwise
                customError('new', ...
                    '''%s'' is not a valid sensor type', newSensorType);
        end
        enable(m_sensorObj);
    end


    function out = getSensorObj()
        out = m_sensorObj;
    end

end




