function closescreen()
%CLOSESCREEN Dispose FULLSCREEN() window
% TAKEN FROM MATLAB CENTRAL

global frame_java
try frame_java.dispose(); end
