function demo_tribot
% DEMO_TRIBOT  A demo program that controls a tribot with a touch sensor
%
%   DEMO_TRIBOT is a demo program for a tribot with a touch sensor. The 
%   tribot moves forward until the touch sensor is depressed. When this 
%   happens, the tribot plays a "Woops" sound, backs up, and turns
%   in a random direction (beeping all the while). After this action, it
%   starts moving forward again. The demo lasts for 20 seconds.
% 
%   Assumptions:
%    * The left and right wheels are connected to output ports B and C
%    * The touch sensor is connected to input port 1
%    * The COM port is 'COM40' 
%   The above assumptions (and the demo duration) can easily be changed 
%   by modifying the first few lines of the program.
%

nxt = legoNXT('COM5'); % change COM40 to the COM port in your setup
nxti = get(nxt, 'nxtInterface');

touchSensor = nxt.Port1;
leftMotor = nxt.PortB;
rightMotor = nxt.PortC;
demoDuration = 20; % duration of this demo, in seconds


mv = getBatteryLevel(nxti); % battery level in millivolts 
% mv is a 'uint16', so convert to double before doing any math
fprintf('Battery level is %.3f volts\n', double(mv)/1000);

warningTimer = timer('Period', 0.5, 'executionMode', 'fixedSpacing', ...
                     'TimerFcn', @warningTimerFcn);

% set default power levels
set(leftMotor, 'Power', 20);
set(rightMotor, 'Power', 20);

start(leftMotor); start(rightMotor);

starttime = clock;
try
    while etime(clock, starttime) < demoDuration
               
        if getdata(touchSensor) < 50
            start(warningTimer);
            
            % back up for 1 second
            start(leftMotor, -20); start(rightMotor, -20);
            pause(1);
            stop(leftMotor); stop(rightMotor);
                        
            % circle in a random direction for 3 seconds
            if rand(1) < 0.5
                start(leftMotor, -10); 
            else
                start(rightMotor, -10);
            end
            pause(3);
            
            % head in new direction
            start(leftMotor); start(rightMotor);
            
            stop(warningTimer);
        end % if
        
    end % while
    
catch
    disp(lasterr)
end

stop(leftMotor); stop(rightMotor);
playSoundFile(nxti, '! Attention.rso', 0);

delete(warningTimer);
delete(nxt);

%% -----------------------------------------------------

    function warningTimerFcn(obj,eventdata) %#ok<INUSD>
        if obj.TasksExecuted == 1
            % first timer tick
            playSoundFile(nxti, 'Woops.rso', 0);
        else
            playTone(nxti, 1000, 100); % frequency (Hz), duration (ms)
        end
    end

end
