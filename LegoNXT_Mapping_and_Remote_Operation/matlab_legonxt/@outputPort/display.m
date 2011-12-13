function display(obj)
%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

fprintf(' LEGO-NXT Motor Object\n');

s = get(obj, 'Port', 'Power', 'StopType', ...
            'Running', 'RunningTime', 'StoppedTime');
        
fprintf('  Output port: %s\n', s.Port);
fprintf('  Power: %d\n', s.Power);
fprintf('  StopType: ''%s''\n', s.StopType);

if s.Running
    fprintf('  Running: true\n');
    fprintf('  Running time: %.2f sec', s.RunningTime);
else
    fprintf('  Running: false\n');
    fprintf('  Stopped time: %.2f sec\n', s.StoppedTime);
end
