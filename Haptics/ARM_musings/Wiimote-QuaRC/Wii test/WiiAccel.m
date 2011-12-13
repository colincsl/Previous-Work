% function WiiAccel()

addpath('C:\Documents and Settings\colinlea\Desktop\Wii2\WiiLAB_Matlab\WiimoteFunctions')


global X Y Z
% X = 1;
% Y = 1;
% Z = 1;
[X Y Z] = getWiimoteAccel()

% end