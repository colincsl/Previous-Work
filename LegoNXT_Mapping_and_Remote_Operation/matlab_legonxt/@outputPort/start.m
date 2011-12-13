function start(obj, powerSetPoint)
% START  Start the motor connected to the output port
% 
%   START(OBJ) starts the motor connected to the output port, using the
%   power setpoint previously specified using SET(OBJ,'Power', ...).
%
%   START(OBJ, P) uses P as the power setpoint, overriding the value
%   specified using SET. P should be an integer between -100 and +100. 
%
%    It is safe to call START repeatedly. For example, the following
%    commands will start the motor at power +30, maintain it for 0.5 sec,
%    and then switch to a lower power setting (+10). 
%      start(obj, 30);
%      pause(0.5);
%      start(obj, 10);
%
% See also outputPort/set, outputPort/stop

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

% *** NOTES ON INPUTS TO SETOUTPUTSTATE
% 
% powerSetPoint: -100 to +100 power level 
%    abs(powerSetPoint) => denotes % of full power capabilities of the  motor
%    sign(powerSetPoint) => rotation direction (+ = forward, - = reverse)
% For powerSetPoint to work, mode.MOTORON must be set and 
%                            runState must not be IDLE
%
% turnRatio: specifies the proportional turning ratio for two synchronized
%     motors (e.g., to acheive smooth turns). Should be in the range
%     [-100,100]. ONly valid if mode.MOTORON & REGULATED and  regulationMode.MOTOR_SYNC 
%     runState is non-idle and powerSEtPoint is nonzero.
%     Values must be set for at least two motors.
%
% tachoLimit: the number of degrees to rotate the motor. The sign of the
%     powerSetPoint specifies the direction of rotation.

if ~exist('powerSetPoint', 'var'),
    powerSetPoint = obj.getDefault('Power');
else
   if obj.checkPowerValue(powerSetPoint) == 0
       customError('new', 'Power should be an integer between -100 and +100');
   end
end

nxt = obj.getNXTInterfaceObj();
motor = obj.getMotorConstants();

setOutputState(nxt, struct( ...
    'port',           obj.getOutputPort(), ...
    'powerSetPoint',  int8(powerSetPoint), ...
    'mode',           motor.mode.MOTORON + motor.mode.REGULATED + motor.mode.BRAKE, ...
    'regulationMode', motor.regulationMode.MOTOR_SPEED, ...
    'turnRatio',      0, ...
    'runState',       motor.runState.RUNNING, ...
    'tachoLimit',     0 ...
    ) ...
)

obj.setRunning(true);
