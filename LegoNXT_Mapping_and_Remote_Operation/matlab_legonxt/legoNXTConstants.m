function out = legoNXTConstants(which)
% legoNXTConstants  Returns a structure of constants used by LEGO NXT
%
%   S = legoNXTConstants(W) returns a structure of various constants used 
%     to send direct commands to the LEGO Mindstorms NXT. W is a string
%     that identifies the set of constants being requested:
%  
%     'nxtGeneric'  : Generic constants such the number and names
%                     of input and output ports and filename sizes.
%     'nxtCommands' : The codes and names of the various "direct" commands
%     'motor'       : Constants for motor control 
%     'sensor'      : Constants for configuring sensor types and modes
%     'ultrasonicSensor': Constants used in communicating with the 
%                     Ultrasonic sensor using the digital I2C protocol.
%
%   Note: 
%    The information returned by this function is based upon the LEGO
%    NXT programming documentation (esp. the Bluetooth Developer Kit),
%    available at
%       http://mindstorms.lego.com/Overview/NXTreme.aspx
%   and the "LabVIEW for NXT Advanced Programming Guide", available at
%       http://zone.ni.com/devzone/cda/tut/p/id/4435

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

switch which
    case 'nxtGeneric'
        out = nxtGenericConstants();
    case 'nxtCommands'
        out = nxtCommands();
    case 'motor'
        out = motorConstants();
    case 'sensor'
        out = sensorConstants();
    case 'ultrasonicSensor'
        out = ultrasonicSensorConstants();
    otherwise,
        error('Unknown constant type');
end
        
%% ======================================================================
    function nxt = nxtGenericConstants()
        % The direct command format is described in:
        %   Appendix 2-LEGO MINDSTORMS NXT Direct commands.pdf
        
        % Generic constants
        nxt.MAX_FILENAME_LEN  = 19;   % 15 char name + "." + 3-char extension
        nxt.MAX_LSDATA_LEN = 16;  % maximum length for LS (Low-Speed) data comm.

        % the names of the input ports and the corresponding port numbes
        nxt.inputPortNames   = {'1', '2', '3', '4'};
        nxt.inputPortNumbers = { 0    1    2    3 }; 

        % the names of the output ports and the corresponding port numbes
        nxt.outputPortNames   = {'A', 'B', 'C', 'ABC'};
        nxt.outputPortNumbers = { 0    1    2    255};
        
        % Flags used in first byte of the message
        nxt.HDR_SEND_RESPONSE = hex2uint('00'); % NXT will send back a response
        nxt.HDR_NO_RESPONSE   = hex2uint('80'); % NXT won't send back a response        
        
        nxt.inputPortName2Number = @(name) lookup(nxt.inputPortNames, ...
                                           nxt.inputPortNumbers, name);
        nxt.outputPortName2Number = @(name) lookup(nxt.outputPortNames, ...
                                           nxt.outputPortNumbers, name);

        function value = lookup(keys, values, testkey)
            value = [];
            if ~ischar(testkey), return; end
            idx = strmatch(testkey, keys, 'exact');
            if ~isempty(idx)
                value = values{idx};
            end
        end
    end

%% ======================================================================
    function cmd = nxtCommands()        
        % Flags used in the second byte of the message
        % to specify the command. See        
        %   Appendix 2-LEGO MINDSTORMS NXT Direct commands.pdf
        
        cmd.STARTPROGRAM       = hex2uint('00');
        cmd.STOPPROGRAM        = hex2uint('01');
        cmd.PLAYSOUNDFILE      = hex2uint('02');
        cmd.PLAYTONE           = hex2uint('03');
        cmd.SETOUTPUTSTATE     = hex2uint('04');
        cmd.SETINPUTMODE       = hex2uint('05');
        cmd.GETOUTPUTSTATE     = hex2uint('06');
        cmd.GETINPUTVALUES     = hex2uint('07');
        cmd.RESETINPUTSCALEDVALUE = hex2uint('08');
        cmd.RESETMOTORPOSITION = hex2uint('0A');
        cmd.GETBATTERYLEVEL    = hex2uint('0B');
        cmd.STOPSOUNDPLAYBACK  = hex2uint('0C');
        cmd.KEEPALIVE          = hex2uint('0D');
        cmd.LSGETSTATUS        = hex2uint('0E');
        cmd.LSWRITE            = hex2uint('0F');
        cmd.LSREAD             = hex2uint('10');
    end

%% ======================================================================
    function motor = motorConstants()
        % Flags used in motor control
        % The description of the modes and states is from the "LabVIEW for NXT
        % Advanced Programming Guide".
        %   ftp://ftp.ni.com/evaluation/mindstorms/LabVIEW_for_NXT_Advanced_Programming_Guide.pdf
        %   Also see: http://zone.ni.com/devzone/cda/tut/p/id/4435

        % The motor mode is a bitfield (i.e., several modes can be specified
        % together, e.g., motor.mode.MOTORON + motor.mode.REGULATED).
        %
        % MOTORON => must be set for any power to be provided to the motor
        % BRAKE => turns off "floating" of voltage between PWM values (i.e., motor
        %       is actively stopped rather than being allowed to coast to a stop).
        % REGULATED => enables regulation of motor speed (see motor.regulationMode)

        motor.mode.COAST     = hex2uint('00'); % motor can rotate freely
        motor.mode.MOTORON   = hex2uint('01'); % Enables PWM power to the port
        motor.mode.BRAKE     = hex2uint('02'); % applies electronic braking to port
        motor.mode.REGULATED = hex2uint('04'); % enables active power regulation

        % regulationMode is only valid if mode.REGULATED is set.
        % Only one regulationMode can be set (it is not a bitfield).
        % MOTOR_SPEED => the firmware tries to maintain a particular power
        %      setpoint (a particular speed) on the specified outputPort.
        % MOTOR_SYNC => the firmware actively tries to keep any two motors
        %      in sync regardless of load (for this to work, set
        %      regulationMode.MOTOR_SYNC on at least two motor motor ports).

        motor.regulationMode.IDLE        = hex2uint('00'); % regulation is disabled
        motor.regulationMode.MOTOR_SPEED = hex2uint('01'); % power control enabled
        motor.regulationMode.MOTOR_SYNC  = hex2uint('02'); % sync. of multiple outputs

        % Only one of the runState can be set (it is not a bitfield).
        %  IDLE => disable power to specified port
        %  RAMPUP => enbles rampup of power to power setpoint
        %  RUNNING => deliver power at setpoint
        %  RAMPDOWN => enables rampdown of power to power setpoint

        motor.runState.IDLE     = hex2uint('00'); % output will be idle
        motor.runState.RAMPUP   = hex2uint('10'); % output will ramp-up
        motor.runState.RUNNING  = hex2uint('20'); % output will be running
        motor.runState.RAMPDOWN = hex2uint('40'); % output will ramp-down
    end

%% ======================================================================
    function sensor = sensorConstants()
        % Flags used with sensor control
        % The description of the modes and types is from the "LabVIEW for NXT
        % Advanced Programming Guide".
        %   ftp://ftp.ni.com/evaluation/mindstorms/LabVIEW_for_NXT_Advanced_Programming_Guide.pdf

        % *** NOTE 1: The sensor modes are only applicable for analog
        %    sensors (everything except the LOWSPEED type, which is the
        %    digital ultrasonic sensor). The commands for 
        
        % The SETINPUTMODE commands only work with the analog sensors (light,
        % sound, touch). The ultrasonic sensor is digital (the one included with
        % the NXT brick is LOWSPEED_9V), and talking to it requires the
        % LSWRITE, LWREAD AND LSGETSTATUS command (LS = "low speed").
        % The commands to be sent to the ultrasonic sensor are specified
        % in "Appendix 7 Ultrasonic Sensor I2C communication protocol.pdf"
        
        sensor.type.NO_SENSOR      = hex2uint('00');
        sensor.type.SWITCH         = hex2uint('01'); % touch sensor
        sensor.type.TEMPERATURE    = hex2uint('02'); % temp. sensor
        sensor.type.REFLECTION     = hex2uint('03'); % light sensor
        sensor.type.ANGLE          = hex2uint('04'); % rotation sensor
        sensor.type.LIGHT_ACTIVE   = hex2uint('05'); % light sensor w/ floodlight
        sensor.type.LIGHT_INACTIVE = hex2uint('06'); % light sensor w/out floodlight
        sensor.type.SOUND_DB       = hex2uint('07'); % sound sensor w/ dB scaling
        sensor.type.SOUND_DBA      = hex2uint('08'); % sound sensor w/ dbA scaling
        sensor.type.CUSTOM         = hex2uint('09'); % unused
        sensor.type.LOWSPEED       = hex2uint('0A'); % I2C digital sensor (ultrasonic sensor)
        sensor.type.LOWSPEED_9V    = hex2uint('0B'); % I2C digital sensor, 9V power
        sensor.type.NUM_TYPES      = hex2uint('0C'); % unused

        % The light sensor detects luminance only, not color.
        %    see http://mindstorms.lego.com/Overview/Light_Sensor.aspx
        % The sound sensor can be configured to return DB or DBA.
        %    dBA:the sensitivity of the sensor is adjusted to the 
        %        range of frequencies audible to the human ear.
        %     dB: standard unadjusted decibels (all sounds are measured 
        %        with equal sensitivity)
        %    see http://mindstorms.lego.com/Overview/Sound_Sensor.aspx

        % The sensor mode specifies how the raw input is to be transformed.
        %
        % Raw values => a subset of the 10-bit sensor range.
        % Normalized values => the raw values rescaled (using firmware-internal
        %   scaling factors) to exploit the full 10-bit range. These values
        %   ignore the sensor mode.
        % Scaled values => The transformation specified by sensor mode is applied.
        %   The legal range of the scaled value depends on the mode.
        %     RAW : [0,1023]
        %     BOOLEAN: [0,1]
        %     TRANSITIONCNT : [0,65535]
        %     PERIODCOUNTER : [0,65535]
        %     PCTFULLSCALE:  [0,100]
        %     CELSIUS : [-200,700] (readings in 0.1 degrees)
        %     FAHRENHEIT : [-400,1580] (readings in 0.1 degrees)
        %     ANGLESTEPMODE : [0,65535]

        % report scaled value = raw value
        sensor.mode.RAW           = hex2uint('00');

        % report scaled value as 0 (if raw value exceeds 55% of total range)
        % or 1 (if raw value are less than 45% of total range).
        sensor.mode.BOOLEAN       = hex2uint('20');

        % Report scaled value as number of transitions between TRUE (1) and FALSE (0).
        sensor.mode.TRANSITIONCNT = hex2uint('40');

        % Report scaled value as number of transitions from FALSE to TRUE to FALSE.
        sensor.mode.PERIODCOUNTER = hex2uint('60');

        % Report scaled value as percentage of full scale reading for configured
        % sensor type.
        sensor.mode.PCTFULLSCALE  = hex2uint('80');

        % Scale temperature reading to degrees celsius.
        sensor.mode.CELSIUS       = hex2uint('A0');

        % Scale temperature reading to degrees Fahrenheit.
        sensor.mode.FAHRENHEIT    = hex2uint('C0');

        % Report scaled value as count of ticks on rotation sensor
        sensor.mode.ANGLESTEP     = hex2uint('E0');

        % Could not find documentation on these modes.
        sensor.mode.SLOPEMASK     = hex2uint('1F');
        sensor.mode.MODEMASK      = hex2uint('E0');
    end

%% ======================================================================
    function uscmd = ultrasonicSensorConstants()

        % The input ports on the NXT support a digital protocol called
        % 'I2C' that allows simple (low speed) serial communication.
        % The ultrasonic distance sensor is an I2C device; consequently,
        % configuring the sensor and retrieving data from it need to
        % follow a digital protocal specific to that device.
        
        % From the "Lego Mindstorms NXT Ultrasonic Sensor
        % I2C Communication Protocol". 
        % These are the commands that need to be transmitted
        % to the ultrasonic sensor (using the NXT LSWRITE command).        
        
        % ** The last column is the expected length of the response **

        uscmd.READ_VERSION = [2 hex2uint('00') 8];
        uscmd.READ_PRODUCTID = [2 hex2uint('08') 8];
        % This should return "Sonar" as a zero-delimted ASCII string
        uscmd.READ_SENSORTYPE = [2 hex2uint('10') 8];  
        % Read the measurement units (should return "10E-2m" as a 
        % zero-delimited ASCII string).
        uscmd.READ_MEASUNITS  = [2 hex2uint('14') 8];  
        
        % This returns the first byte of the measurement (the distance 
        % to the first object). It may be possible to program the sensor
        % to measure distances to multiple objects, and READ_MEASBYTE1..7
        % are used for those objects.
        uscmd.READ_MEASBYTE0  = [2 hex2uint('42') 1];        
        uscmd.READ_MEASBYTE1  = [2 hex2uint('43') 1];
        uscmd.READ_MEASBYTE2  = [2 hex2uint('44') 1];
                
        % turn off the sensor
        uscmd.SENSOR_OFF = [2 hex2uint('41') 0 0];
        % turn on continuous meas. mode (default)
        uscmd.SENSOR_CONTINUOUS = [2 hex2uint('41') 2 0];
        % do a warm reset of the sensor
        uscmd.SENSOR_RESET = [2 hex2uint('41') 2 4 0];
        
    end


%%
end

%% -------------------------------------------
function out = hex2uint(s)
out = uint8(hex2dec(s));
end
