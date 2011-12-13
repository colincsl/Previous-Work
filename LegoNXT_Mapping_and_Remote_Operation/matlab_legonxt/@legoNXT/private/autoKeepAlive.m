function out = autoKeepAlive(obj, mode)
% Enables/Disables the automatic keepAlives to the legoNXT
%  mode: one of 'info', 'on', 'off'
%    'info' -> out is a structure with information about the
%              keep alive timer
%     'on'  -> Turn the keep alive on. Doesn't do anything if
%              the keep alives are already enabled.
%     'off'  -> Turn the keep alive off. Doesn't do anything if
%              the keep alives are already disabled.

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

keepAliveTimer = obj.getKeepAliveTimer();
timerIsValid = ~isempty(keepAliveTimer) && isvalid(keepAliveTimer);
out = [];

switch mode
    case 'info',
        out.keepAliveEnabled = timerIsValid && ...
            strcmp(keepAliveTimer.Running, 'on');
        if timerIsValid
            out.keepAlivePeriod = keepAliveTimer.Period;
        end

    case 'on',
        if timerIsValid
            if strcmp(keepAliveTimer.Running, 'off')
                start(keepAliveTimer);
            end
        else % timer doesn't exist or is invalid
            % there may be preexisting timers (if previous legoNXT objects
            % weren't deleted)
            timerName = ['LegoNXT_KeepAlive_' get(obj.getNXTInterfaceObj(),'SerialPort')];
            oldTimerObjs = timerfindall('name', timerName);
            if ~isempty(oldTimerObjs)
                stop(oldTimerObjs);
                delete(oldTimerObjs);
            end
            
            % create a new timer
            keepAliveTimer = timer('period', 300, ... 
                'timerfcn', {@timerCallback, obj.getNXTInterfaceObj()}, ...
                'executionMode', 'fixedSpacing', ...
                'startDelay', 5, ... % start after 5 sec
                'name', timerName);
            start(keepAliveTimer);
            obj.setKeepAliveTimer(keepAliveTimer);
            % fprintf('Automatic keepAlive timer started\n');
        end

    case 'off',
        if timerIsValid            
            stop(keepAliveTimer);
            delete(keepAliveTimer);
            % fprintf('Automatic keepAlive timer stopped\n');
        end
        obj.setKeepAliveTimer([]);

    otherwise
        error('Invalid autoKeepAlive mode');
end

end


%------------------
function timerCallback(timerObj, eventdata, nxtInterfaceObj) %#ok<INUSL>
    try
        keepAlive(nxtInterfaceObj);
    catch
        fprintf('Unable to send keepAlive message to the NXT.\n');
        fprintf('Turning off automatic keepAlive().\n');
        stop(timerObj);
        delete(timerObj);
    end
end
