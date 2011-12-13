function out = setOutputState(obj, s)
% setOutputState  Sets the state of a motor on the LEGO NXT
% 
%   setOutputState(OBJ, S) sets the state of the motor on the LEGO NXT
%   using the values specified by the structure S. 
%
%   The structure S should have the following fields (the case of the field
%   names should be followed exactly). 
%     --------------------------------------------------
%      For details of the various constants, see the 
%      motorConstants() function in legoNXTConstants.m
%     --------------------------------------------------
%     port           
%       The output port (0, 1, or 2, corresponding to ports 'A', 'B'
%       and 'C', respectively).
%
%     powerSetPoint 
%       The power level of the motor. This should be an integer in the 
%       range [-100,100]. Larger absolute values indicate greater motor 
%       power. Negative values specify reverse motion. For powerSetPoint 
%       to be effective, MOTORON must be set for the mode, and runState 
%       must not be IDLE.
%
%     mode
%       A bitmask that specifies the mode of the motor. Must of one or more
%       of COAST (0x00), MOTORON (0x01), BRAKE (0x02) or REGULATED (0x04).
%
%     regulationMode
%       Specifies how the power level is to be regulated. Must be one of
%       IDLE (0x00), MOTOR_SPEED (0x01), or MOTOR_SYNC (0x02).
%
%     turnRatio
%       Specifies the proportional turning ratio for two synchronized
%       motors (e.g., to acheive smooth turns). turnRation should be 
%       an integer in the range [-100,100] and is valid only if: 
%         * mode is MOTORON and REGULATED, 
%         * regulationMode is MOTOR_SYNC,
%         * runState is not IDLE, 
%         * powerSetPoint is non-zero, and
%         * the above values are set for at least two motors.
%
%     runState
%        Must be one of IDLE (0x00), RAMPUP (0x10), RUNNING (0x20), 
%        or RAMPDOWN (0x40).
%
%     tachoLimit
%        The number of degrees to rotate the motor. The sign of the
%        powerSetPoint specifies the direction of rotation.
%
%
%   Examples:
%        % To statrt the motor on Port B, with power +20 
%        % and with power regulation
%          setOutputState(obj, struct( ...
%              'port',           1, ...
%              'powerSetPoint',  20, ...
%              'mode',           MOTORON + REGULATED + BRAKE, ...
%              'regulationMode', MOTOR_SPEED, ...
%              'turnRatio',      0, ...
%              'runState',       RUNNING, ...
%              'tachoLimit',     0 ...
%              ) ...
%           );
%
%       % To stop the motor on Port B
%          setOutputState(obj, struct( ...
%              'port',           1, ...
%              'powerSetPoint',  0, ...
%              'mode',           REGULATED, ...
%              'regulationMode', MOTOR_SPEED, ...
%              'turnRatio',      0, ...
%              'runState',       IDLE , ...
%              'tachoLimit',     0 ...
%              ) ...
%           );
%
%   See also nxtInterface/getOutputState, nxtInterface/resetMotorPosition

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

msg = [obj.getNXTCommand('SETOUTPUTSTATE') ...
        uint8(s.port)...
        intToLeBytes(int8(s.powerSetPoint))...
        uint8(s.mode)...
        uint8(s.regulationMode)...
        intToLeBytes(int8(s.turnRatio))...
        uint8(s.runState)...
        intToLeBytes(uint32(s.tachoLimit)) ...
       ];
    
if nargout > 0
    out = sendMessage(obj,msg);
else    
    sendMessage(obj,msg);
end

% Note 1: powerSetPoint and turnRation can't simply be cast
%  as int8. When the message is converted to a sequence of uint8's,
%  the  negative values are lost (i.e., uint8(int8(-10)) = 0).
%  intToLeBytes does the correct typecasting.
%
% Note 2: The spec says tachoLimit is 5 bytes, but this likely a
%  a doc error, since (a) it is described as a ULONG, and (b)
%  GETOUTPUTSTATE returns tachoLimit as a 4-byte ULONG. The above
%  code assumes that tachoLimit is 4 bytes.
