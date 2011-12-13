function playTone(obj, frequency, duration)
%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

if obj.doShowMessages
    fprintf('playTone: frequency=%d Hz, duration=%d msec\n', ...
        frequency, duration);
end
