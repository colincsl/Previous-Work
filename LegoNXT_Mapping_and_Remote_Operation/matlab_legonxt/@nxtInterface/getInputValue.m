function s = getInputValue(obj, inputPort)
% GetInputValue  Returns the current value from an analog sensor
% 
%   S = getInputValue(OBJ, P) returns a structure, S, that specifies
%   the current state of the analog sensor connected to input port P.
%   In case of error, S is an empty array ([]). P should be 0, 1, 2 or 3 
%   (corresponding to input ports '1', '2', '3' and '4', respectively).
% 
%   The structure S has the following fields. Typically, the field of 
%   interest is 'scaledValue'.
%    -----------------------------------------------------------------
%    For details of the input type, mode, and the various values (raw vs. 
%    normalized vs. scaled) see the sensorConstants() function in 
%    legoNXTConstants.m. 
%    -----------------------------------------------------------------
%  
%     port         - The input port whose status is being queried
%     isValid      
%     isCalibrated 
%     sensorType   - The current type of the sensor (see setInputMode)
%     sensorMode   - The current mode of the sensor 
%     rawValue     - The raw value registered by the sensor. This is a 
%                    subset of the 10-bit sensor range.
%     normalizedValue - The raw value rescaled by the firmware to exploit 
%                    the full 10-bit range. 
%     scaledValue   - The transformation specified by the sensor mode is 
%                    applied. 
%     calibratedValue - This value does not appear to be used by the
%                    LEGO NXT firmware.
% 
%   See also nxtInterface/setInputMode, nxtInterface/resetScaledValue

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

[resp,status] = sendMessage(obj, [...
    obj.getNXTCommand('GETINPUTVALUES') ...
    uint8(inputPort) ...
    ]);

if status == 0
    s.port = resp(1);
    s.isValid = resp(2);
    s.isCalibrated = resp(3);
    s.sensorType = resp(4);
    s.sensorMode = resp(5);
    s.rawValue = leBytesToInt(resp(6:7), 'uint16');
    s.normalizedValue = leBytesToInt(resp(8:9), 'uint16');
    s.scaledValue = leBytesToInt(resp(10:11), 'int16');
    % the doc says calibratedValue is "currently unused"
    s.calibratedValue = leBytesToInt(resp(12:13), 'int16');
else
    s = [];
end

