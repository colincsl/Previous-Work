function stop(obj, stopType)
% STOP  Stop the motor connected to the output port
%
%   stop(OBJ) stops the motor connected to the output port, using the
%   StopType previously specified using SET(OBJ, 'StopType', ...).
%
%   stop(OBJ, T) uses T as the StopType, overriding the value specified
%   using SET. T should be 'brake' or 'coast'.
%
%    It is safe to call STOP repeatedly. For example, the following
%    commands will start the motor, actively brake it for 1 second, and
%    then turn off the power entirely (with StopType = 'coast').
%      start(obj, 30);
%      stop(obj, 'brake');
%      pause(1);
%      stop(obj, 'coast);
%
% See also outputPort/set, outputPort/start

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

nxt = obj.getNXTInterfaceObj();
motor = obj.getMotorConstants();

if ~exist('stopType', 'var')
    stopType = obj.getDefault('StopType');
end

switch lower(stopType)
    case 'brake',
        brake();
    case 'coast'
        coast();
    otherwise
        error('StopType should be ''brake'' or ''coast''');
end

obj.setRunning(false);

%% =====================================================
    function brake()
        setOutputState(nxt, struct( ...
            'port',           obj.getOutputPort(), ...
            'powerSetPoint',  0, ...
            'mode',           motor.mode.MOTORON + motor.mode.REGULATED + motor.mode.BRAKE, ...
            'regulationMode', motor.regulationMode.MOTOR_SPEED, ...
            'turnRatio',      0, ...
            'runState',       motor.runState.RUNNING, ...
            'tachoLimit',     0 ...
            ) ...
        );
    end

    function coast()
        setOutputState(nxt, struct( ...
            'port',           obj.getOutputPort(), ...
            'powerSetPoint',  0, ...
            'mode',           motor.mode.REGULATED, ...
            'regulationMode', motor.regulationMode.MOTOR_SPEED, ...
            'turnRatio',      0, ...
            'runState',       motor.runState.IDLE , ...
            'tachoLimit',     0 ...
            ) ...
        );
    end

%% =====================================================
end
