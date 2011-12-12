% Data from cardbard box in Cave 8/4/10

clc
dist2box = 1525; %mm
box_actual = 304.8; %mm (12 in)
box_actual_y = (12+3/8)*25.4;


SV_x = [293.1, 292, 291.0, 287, 283, 283, 295];
SV_y = [293, 283, 284, 289, 295];

SV_mean_x = mean(SV_x);
SV_mean_y = mean(SV_y);
box_actual - mean(SV_x)
box_actual_y - mean(SV_y)

SV_x_std = std(SV_x);
SV_y_std = std(SV_y);

SV_box_error_x = (box_actual - SV_mean_x) / dist2box * 100;
SV_box_error_y = (box_actual_y - SV_mean_y) / dist2box * 100;

% % 

SL_x = [327, 326, 320, 320.4, 323, 323,  327,  324, 320, 321];
SL_y = [288, 286, 290, 291,  293, 290.8, 293.8, 291, 296, 294 ];
SL_x_std = std(SL_x);
SL_y_std = std(SL_y);

SL_mean_x = mean(SL_x);
SL_mean_y = mean(SL_y);

box_actual - mean(SL_x)
box_actual_y - mean(SL_y)

SL_box_error_x = (box_actual - SL_mean_x) / dist2box * 100;
SL_box_error_y = (box_actual_y - SL_mean_y) / dist2box * 100;
