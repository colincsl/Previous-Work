function display(nxt)
%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

nxt.checkDeleted();

serialObj = nxt.getSerialObj();

fprintf(' LegoNXT Interface object\n');
fprintf('  Bluetooth Serial Port:\n');
if ~isempty(serialObj)
    fprintf('    name   : %s\n', serialObj.port);
    fprintf('    status : %s\n', serialObj.status);
    fprintf('    timeout: %.1f sec\n', serialObj.timeout);
else
    fprintf('    NOT CONNECTED\n');
end

fprintf('  Check for responses from Lego NXT: ');
   if nxt.getAlwaysCheckResponse(),
       fprintf('ALWAYS\n');
   else
       fprintf('AUTO\n');
   end
end
