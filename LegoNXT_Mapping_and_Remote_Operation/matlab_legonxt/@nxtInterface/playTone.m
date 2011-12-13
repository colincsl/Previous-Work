function playTone(obj, frequency, duration)
% playTone  Plays a tone on the LEGO NXT
% 
%   playTone(OBJ, F, T) plays a tone on the LEGO NXT with frequency F 
%   (in Hertz) for a duration of T milliseconds. F should be an integer
%   between 200 and 14000 Hz. 
% 
%   Example:
%     % Play a tone of 1000 Hertz for 0.3 seconds
%     playTone(obj, 1000, 300);
%
%   See also nxtInterface/playSoundFile, nxtInterface/stopSoundPlayback

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

sendMessage(obj, [...
    obj.getNXTCommand('PLAYTONE') ...
    intToLeBytes(uint16(frequency)) ...
    intToLeBytes(uint16(duration)) ...
    ]);
