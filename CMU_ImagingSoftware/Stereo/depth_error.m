% Find maximum error for stereo calculation
% eqn: e_max >= dl / [(baseline*focal) / (s_h/rez  *  dl   - 1)]
% dl = distance to object
% s_h = linear range (in x direction) at dist=d1

% From paper: Optimal Stereo Mast Configuration for Mobile Robots
% Authors: Huang, Krotkov -- Carnegie Mellon

% All units in millimeters

rez = 1280; %in x direction
x_range = 1828.8;
dl = 2000;
baseline = 260.35;
focal = 1350.4;
% focal = 2.8;

s_h = x_range / rez;

err = dl / ((baseline*focal) / (s_h/rez  *  dl   - 1))

