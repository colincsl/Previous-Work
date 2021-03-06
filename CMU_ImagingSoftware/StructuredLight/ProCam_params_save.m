% % 
% ProCamCalib returns values in pixels; convert from px to mm;
mm = 30/200;
% % 



% Camera  0 (1280 x 960)
% dim_c = [1280; 960];
% =========
% Intrinsics
% ----------
KK_c =  [ 2.9094363924979370e+003, 0., 5.6135140172486842e+002;
          0., 2.9005535404537773e+003, 4.1307747838169354e+002;...
          0., 0., 1. ];
kc_c =  [ -5.5588791592987255e-002, -2.8196950476479937e-001, -2.7012062551373429e-003, -2.3929509505650893e-003 ];

% reprojection RMSE (pixels) = 0.4360502

% Extrinsics
% ----------
rot_c = [ 1.0, 0.0, 0.0;...
             0.0, 1.0, 0.0;...
             0.0, 0.0, 1.0 ];
trans_c = [ 0.0;...
                0.0;...
                0.0 ];


            
% Projector  0 (1280 x 1024)
% ============
% Intrinsics
% ----------
KK_p =  [ 2.7211361932937461e+003, 0., 6.5524360815560033e+002;...
        0., 2.7147858057232438e+003, 1.0635065321177633e+003;...
        0., 0., 1. ];
kc_p = [ -1.1374716830810004e-001, 2.9824472536737683e-002, 4.2374640439779804e-004, 9.2894172554078497e-004 ];
% reprojection RMSE (pixels) = 1.7147328

% Extrinsics
% ----------
rot_p = [ 9.5914083031869302e-001, 1.7324908373982789e-003, -2.8292378141659713e-001;...
        -5.5592997334871164e-002, 9.8164129376343356e-001, -1.8245489586683442e-001;...
          2.7741356539090356e-001, 1.9072852134369081e-001, 9.4162855993388184e-001 ];
trans_p = [ 4.3093752584481135e+003;...
            9.5161371936096998e+001;...
            1.3057955294889686e+002 ]*mm;

% % 

fc_c = [KK_c(1,1); KK_c(2,2)];
fc_p = [KK_p(1,1); KK_p(2,2)];

cc_c = [KK_c(1, 3); KK_c(2,3)];
cc_p = [KK_p(1, 3); KK_p(2,3)];

alpha_c_c = 0;
alpha_c_p = 0;

% size of kc should be 5, not 4 as given wit ProCamCalib
kc_c = [kc_c, 0];
kc_p = [kc_p, 0];