function playSoundFile(obj, fileName, keepLooping)
% playSoundFile  Plays a sound file on the LEGO NXT
% 
%   playSoundFile(OBJ, FN, LOOP) sends a direct command to the LEGO NXT
%   to play the sound file with name FN. If LOOP=0, the sound is played
%   once. If LOOP=1, the sound is played repeatedly until the next call 
%   to playSoundFile or stopSoundPlayback.
%
%   Note: 
%    1) The sound file has to be already present on the NXT. 
%    2) Filenames on the NXT can be at most 19 characters.
%       (15 character name + '.' + 3 character extension).
%    3) Sound files on the NXT have extension '.rso'
%    4) The default sound files on the NXT are 
%       'Hello', 'Woops', '! Click', '! Attention', '! Startup' 
%
%   Examples:
%     % Play the 'Hello' sound once
%       playSoundFile(obj, 'Hello.rso', 0)
%
%     % Play the '! Attention' sound repeatedly
%       playSoundFile(obj, '! Attention.rso', 1)
%
%   See also nxtInterface/stopSoundPlayback, nxtInterface/playTone

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

maxLen = obj.getNXTConstant('MAX_FILENAME_LEN');

if length(fileName) > maxLen,
    customError('new', 'Filename cannot be longer than %d characters', ...
        maxLen);
end

sendMessage(obj, [
    obj.getNXTCommand('PLAYSOUNDFILE') ...    
    uint8(keepLooping) ...
    charsToBytez(fileName) ...
    ]);
end
