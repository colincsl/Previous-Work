% LEGO-NXT Interface Object Functions.
%   
% General
%   nxtInterface       - Create a Lego Mindstorms NXT Interface object
%   delete             - Close a Lego Mindstorms NXT Interface object
%   get                - Get Lego NXT interface object properties
%   set                - Set Lego NXT interface object properties
%
% General NXT direct commands
%   playSoundFile      - Plays a sound file on the LEGO NXT
%   stopSoundPlayback  - Stops the playback of a sound file on the LEGO NXT.
%   playTone           - plays a tone on the LEGO NXT
%   getBatteryLevel    - Returns the current battery level of the LEGO NXT
%   keepAlive          - Resets the internal sleep timer of the LEGO NXT
%   startProgram       - Executes a program on the LEGO NXT
%   stopProgram        - Stops the execution of a program on the LEGO NXT
%
% NXT direct commands for motors
%   setOutputState     - Sets the state of a motor on the LEGO NXT
%   getOutputState     - Gets the state of a motor on the LEGO NXT
%   resetMotorPosition - Resets the counters for a motor on the LEGO NXT
%
% NXT direct commands for analog sensors
%   setInputMode       - Sets the type and mode of a sensor on the LEGO NXT
%   resetScaledValue   - Resets "scaled" sensor values
%   getInputValue      - Returns the current value from an analog sensor
%
% NXT direct commands for I2C (low-speed digital) communication
%   lsGetStatus        - Returns bytes available to be read from an I2C device 
%   lsRead             - Reads bytes from an I2C device connected to the LEGO NXT
%   lsWrite            - Writes bytes to an I2C device connected to the LEGO NXT

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30
