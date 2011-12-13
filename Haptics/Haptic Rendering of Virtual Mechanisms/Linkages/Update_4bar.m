function hObject = Update_Callback(hObject, eventdata, handles)
%

obj = guidata(hObject);

global ks Cd EE_gain
global G_P Gone_P Gravity
global B_M B_I B_CG_P B_CS1_P B_CS2_P
global Bone_M Bone_I Bone_CG_P Bone_CS1_P Bone_CS2_P Bone_CS3_P Bone_CS4_P 
global Btwo_M Btwo_I Btwo_CG_P Btwo_CS1_P Btwo_CS2_P

%get info from gui
C_len = str2double(get(obj.C_LENGTH, 'String'));
G_len = str2double(get(obj.G_LENGTH, 'String'));
L_len = str2double(get(obj.L_LENGTH, 'String'));
R_len = str2double(get(obj.R_LENGTH, 'String'));

B_M = str2double(get(obj.R_M, 'String'));
Bone_M = str2double(get(obj.C_M, 'String'));
Btwo_M = str2double(get(obj.L_M, 'String'));

Gravity = str2double(get(obj.GRAVITY, 'String'));
ks = str2double(get(obj.SPRING, 'String'));
Cd = str2double(get(obj.DAMPER, 'String'));

%ground points
G_P = [G_len/2 0 0];
Gone_P = [-G_len/2 0 0];

%Right
B_CS1_P = G_P;
B_CS2_P = [G_P(1), R_len, 0];
B_CG_P = [G_P(1), R_len/2, 0];

%Left
Btwo_CS1_P = [Gone_P(1), L_len, 0];
Btwo_CS2_P = [Gone_P(1), 0, 0];
Btwo_CG_P = [Gone_P(1), L_len/2, 0];

%Coupler
Bone_CS1_P = [G_P(1), R_len, 0]; %right
Bone_CS2_P = [Gone_P(1), L_len, 0]; %left
Bone_CG_P =  [0, (L_len+R_len)/2, 0];

len = ((R_len-L_len)^2+G_len^2)^.5;
ang = asin((G_P(1)-Gone_P(1))/(G_len));
a = ang*180/pi;

Bone_CS3_P = [len*cos(ang), (L_len+R_len)/2 + .15*len*sin(ang(1)), 0];  %sensor+actuator
Bone_CS4_P = [len*cos(ang), (L_len+R_len)/2 + .15*len*sin(ang(1)), 0];

%inertias
width = .1;     %y
depth = .05;    %z

B_I = B_M*...
    [width^2+depth^2  -R_len*width      -R_len*depth;...
    -R_len*width      R_len^2+depth^2   -width*depth;...
    -R_len*depth      -width*depth      R_len^2+width^2]


Bone_I = Bone_M*...
    [width^2+depth^2  -len*width      -len*depth;...
    -len*width      len^2+depth^2   -width*depth;...
    -len*depth      -width*depth      len^2+width^2];

Btwo_I = B_M*...
    [width^2+depth^2  -L_len*width      -L_len*depth;...
    -L_len*width      L_len^2+depth^2   -width*depth;...
    -L_len*depth      -width*depth      L_len^2+width^2];

% B_I = 100*B_I;
% Bone_I = 100*Bone_I;
% Btwo_I = 100*Btwo_I;

max_C = Bone_CS3_P(2);
min_C = max_C - min(L_len, R_len);
cen_C = (max_C+min_C)/2;
dia_C = max_C-min_C;

EE_gain = dia_C / .033
EE_trans = [len*cos(ang) cen_C 0]

guidata(hObject,obj)

