function stopSoundPlayback(obj)
% stopSoundPlayback  Stops the playback of a sound file on the LEGO NXT.
%
%   stopSoundPlayback(OBJ) sends a direct command to the LEGO NXT to stop 
%   the playback of a sound file that was initiated using playSoundFile.
%
%   See also nxtInterface/playSoundFile, nxtInterface/playTone

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

sendMessage(obj, [
    obj.getNXTCommand('STOPSOUNDPLAYBACK') ...
    ]); %#ok<NBRAK>

