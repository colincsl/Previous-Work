function setInputMode(obj, port, sensorType, sensorMode)
% setInputMode Sets the type and mode of a sensor on the LEGO NXT
%
%   setInputMode(OBJ, P, T, M) sets the sensor connected to port P 
%   of the LEGO NXT to type T and mode M. 
% 
%    P should be 0, 1, 2 or 3 (corresponding to input ports '1', '2'
%    '3' and '4', respectively).
%
%     --------------------------------------------------
%      For details of the various constants, see the 
%      sensorConstants() function in legoNXTConstants.m
%     --------------------------------------------------
%
%    T should be one of 
%       NO_SENSOR      (0x00)
%       SWITCH         (0x01)
%       TEMPERATURE    (0x02)
%       REFLECTION     (0x03)
%       ANGLE          (0x04)
%       LIGHT_ACTIVE   (0x05)
%       LIGHT_INACTIVE (0x06)
%       SOUND_DB       (0x07)
%       SOUND_DBA      (0x08)
%       LOWSPEED       (0x0A)
%       LOWSPEED_9V    (0x0B)
%
%    M should be one of
%        RAW           (0x00)
%        BOOLEAN       (0x20)
%        TRANSITIONCNT (0x40)
%        PERIODCOUNTER (0x60)
%        PCTFULLSCALE  (0x80)
%        CELSIUS       (0xA0)
%        FAHRENHEIT    (0xC0)
%        ANGLESTEP     (0xE0)
%        SLOPEMASK     (0x1F)
%        MODEMASK      (0xE0)
% 
%   See also nxtInterface/getInputValue, nxtInterface/resetScaledValue

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

sendMessage(obj, [...
    obj.getNXTCommand('SETINPUTMODE') ...
    uint8(port) ...
    uint8(sensorType) ...
    uint8(sensorMode) ...
    ]);

