clc

global ks Cd
global G_P Gone_P Gravity
global B_M B_I B_CG_P B_CS1_P B_CS2_P
global Bone_M Bone_I Bone_CG_P Bone_CS1_P Bone_CS2_P Bone_CS3_P Bone_CS4_P 
global Btwo_M Btwo_I Btwo_CG_P Btwo_CS1_P Btwo_CS2_P 
global Bthree_M Bthree_I Bthree_CG_P Bthree_CS1_P Bthree_CS2_P 
global EE_gain EE_trans
global Five_C2_M


global links
links = 4;

%spring/damper
ks = 250;
Cd = 9;

EE_gain = 14;
EE_trans = [0 0 0];
Force_gain = [1/8 1/8 1/10];
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Link Parameters

%Ground
G_P = [.5 0 0];

%Ground 1
Gone_P = [-.5 0 0];

% Machine Environment
Gravity = 0;


% Body 0 - RIGHT
B_M = .10;
B_I = eye(3);

B_CS1_P = [G_P(1) 0 0];
B_CG_P = [B_CS1_P(1) .25 0];
B_CS2_P = [B_CS1_P(1) .5 0];


%Body 2 - LEFT

Btwo_M = .10;
Btwo_I = eye(3);

Btwo_CG_P = [Gone_P(1) .25 0];
Btwo_CS1_P = [Gone_P(1) .5 0];
Btwo_CS2_P = [Gone_P(1) 0 0];


% Body 1 - COUPLER

Bone_M = .50;
Bone_I = eye(3);

Bone_CG_P = [0 (B_CS2_P(2)+Btwo_CS1_P(2))/2 0];
Bone_CS1_P = [.5 B_CS2_P(2) 0];
Bone_CS2_P = [-.5 .5 0];
Bone_CS3_P = [0 .5+.2 0];
Bone_CS4_P = [0 .5+.2 0];

% Body 3 - 

Bthree_M = .10;
Bthree_I = eye(3);

Bthree_CS1_P = [G_P(1) .5 0];
Bthree_CS2_P = [G_P(1) 0 0];
Bthree_CG_P = (Bthree_CS1_P+Bthree_CS2_P)/2;


%fivebar
Five_C2_M = .5;

