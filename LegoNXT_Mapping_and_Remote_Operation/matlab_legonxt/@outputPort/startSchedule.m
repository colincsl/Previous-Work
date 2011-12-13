function startSchedule(obj, schedule)
% startSchedule  Start the motor to follow a sequence of power setpoints
%
%   startSchedule(OBJ, S) starts the motor connected to the output port
%   using a schedule, S, that specifies power setpoints and their
%   durations. S is an Nx2 matrix, where S(:,1) is the sequence of power
%   setpoints and S(:,2) is corresponding time duration (in seconds) of
%   each setpoint.
%    
%       Note: 
%       1) startSchedule is a non-blocking command, that is, it returns
%          to the caller immediately after initiating the schedule.
%        2) startSchedule calls STOP(obj) at the end of the schedule.  
%
%   startSchedule(OBJ, 'cancel') cancels a schedule that has been initiated
%   by a previous call to startSchedule.
%
%  Examples:
%    % To start a motor at power = +10 for 0.5 seconds, followed 
%    % by power = +20 for 1.75 seconds.
%      S = [10 0.5; 20 1.75];
%      startSchedule(obj, S);
%
%    % To start a motor at power = +10 for 1 second, then reverse 
%    % it for 1 second
%      startSchedule(obj, [10 1; -10 1]);
%
%   % To ramp up a motor to a power setpoint of 50, and hold that for 10
%   % seconds
%      startScehdule(obj, [10 0.3; 20 0.3; 30 0.3; 40 0.3; 50 10]);
%
% See also outputPort/start, outputPort/stop

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30


if ischar(schedule) && strcmpi(schedule, 'cancel')   
    timerObj = timerfind('name', 'MotorPowerSchedule');
    if ~isempty(timerObj)
        stop(timerObj);
        delete(timerObj);
        stop(obj); % stop motor
    end
    return;
end

if ~(isnumeric(schedule) && ndims(schedule)==2 && size(schedule,2)==2)
    errMsg = sprintf('%s\n%s\n%s', ...
                     'Incorrect format for schedule', ...
                     'schedule should be an Nx2 matrix', ...
                     ' col 1 => power set points, col 2 => durations\n');
    customError('new', errMsg);
end

powersets = schedule(:,1);
durations = schedule(:,2);
if ~all(obj.checkPowerValue(powersets))
    customError('new', 'Power should be an integer between -100 and +100');
end

index = 0;
baseT = clock;
timerObj = timer('startDelay', 0, 'executionMode', 'fixedspacing', ...
    'timerFcn', @startScheduleCallback, 'name', 'MotorPowerSchedule');
start(timerObj);

% ------------
    function startScheduleCallback(timerobj, eventdata) %#ok<INUSD>
        if index < numel(durations)
            stop(timerobj);
            index = index+1;
            start(obj, powersets(index)); % start motor
            set(timerobj, 'startDelay', durations(index), 'period', durations(index));
            start(timerobj); % restart timer with new startdelay
        else % reached end of list
            % disp('startSchedule: reached end');
            stop(timerobj);
            delete(timerobj);
            stop(obj); % stop motor
        end
        % fprintf('startSchedule: elapsed time=%.2f power=%d\n', ...
        % etime(clock, baseT), powersets(index));
    end

end

