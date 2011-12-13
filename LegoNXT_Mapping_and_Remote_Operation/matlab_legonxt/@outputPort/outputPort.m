function obj = outputPort(nxtIntObj, portid)
% outputPort  Create a LEGO NXT output port object 
%
%   OBJ = outputPort(NXTI, P) constructs a LEGO NXT output port object OBJ.
%   It serves as a generic and simple interface for controlling LEGO 
%   NXT motors.
%
%    NXTI - A valid nxtInterface object
%    P    - The output port represented by this object. P should
%           be 'A', 'B', or 'C'.
% 
% See also outputPort/start, outputPort/stop, outputPort/set

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

%------------------------
% Specify and initialize member variables

m_nxtInterfaceObj = [];
m_isRunning = false;
m_lastTransitionTime = [];
m_defaults = struct('Power', [], 'StopType', []);
m_portInfo = struct('label', [], 'number', []);
m_nxtMotorConstants = [];

initialize();
clear nxtIntObj portid

%------------------------
% Create the handle to be returned to the caller

obj.getNXTInterfaceObj = @getNXTInterfaceObj;
obj.getOutputPort = @getOutputPort;
obj.getMotorConstants = @getMotorConstants;
obj.checkPowerValue = @checkPowerValue;
obj.getDefault = @getDefault;
obj.setDefault = @setDefault;
obj.getRunning = @getRunning;
obj.setRunning = @setRunning;
obj.timeSinceTransition = @timeSinceTransition;

obj = class(obj, 'outputPort');
setRunning(false);
set(obj, 'Power', 10, 'StopType', 'coast');
stop(obj);

%%
    function initialize()
        if ~(isa(nxtIntObj, 'nxtInterface') || isa(nxtIntObj, 'nxtInterfaceTest'))
            customError('new', 'Input parameter is not an nxtInterface object');
        end
        m_nxtInterfaceObj = nxtIntObj;
        
        %---------        
        m_nxtMotorConstants = legoNXTConstants('motor');

        %--------
        nxtConstants = legoNXTConstants('nxtGeneric');        
        if length(portid)>4 && strcmpi(portid(1:4), 'port')
            portid(1:4) = [];
        end
        m_portInfo.label = portid;
        m_portInfo.number = nxtConstants.outputPortName2Number(portid);
        if isempty(m_portInfo.number)
            customError('new', '''%s'' is not a valid output port', portid);
        end
        %-------
        m_lastTransitionTime = clock;
    end

%%
    function out = getNXTInterfaceObj()
        out = m_nxtInterfaceObj;
    end

    function [portNum,portName] = getOutputPort()
        portNum = m_portInfo.number;
        portName = m_portInfo.label;
    end

    function out = getDefault(name)        
        out = m_defaults.(name);
    end

    function setDefault(name, value)
        switch name
            case 'Power'
                if checkPowerValue(value)
                    m_defaults.Power = value;
                else
                    customError('new', 'Power should be an integer between -100 and +100');
                end
            case 'StopType'
                if ischar(value) && strmatch(lower(value), {'brake', 'coast'})
                    m_defaults.StopType = lower(value);
                else
                    customError('new', 'StopType should be ''brake'' or ''coast''');
                end
            otherwise
                % not a customError since this is an internal problem
                error('Unknown default name'); 
        end                
    end

    function out = getMotorConstants()
        out = m_nxtMotorConstants;
    end

    function out = checkPowerValue(x)
        if ~isnumeric(x)
            out = 0;
        else
            out = (rem(x,1) == 0) & (x >= -100) & (x <= 100);
        end
    end

    function out = getRunning()
        out = m_isRunning;
    end

    function setRunning(makerun)
       if ~m_isRunning && makerun
           % stop -> start transition
           m_isRunning = true;
           m_lastTransitionTime = clock;
       elseif m_isRunning && ~makerun
           % start -> stop transition
           m_isRunning = false;
           m_lastTransitionTime = clock;
       end
    end

    function out = timeSinceTransition()
        out = etime(clock, m_lastTransitionTime);
    end


end

