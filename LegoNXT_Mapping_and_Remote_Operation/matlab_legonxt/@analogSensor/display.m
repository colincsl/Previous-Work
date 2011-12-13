function display(obj)
%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

fprintf(' LEGO-NXT Analog Sensor Object\n');

s = get(obj, 'port', 'type', 'nxttype', 'mode');

fprintf('  Input port: %s\n', s.Port);
fprintf('  Sensor type: %s (%s)\n', s.Type, s.NxtType);
fprintf('  Sensor mode: %s\n', s.Mode);

