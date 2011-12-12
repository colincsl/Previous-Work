% Data from checkerboard analysis


%%
if ~exist('Xd_x', 'var')
    % X direction
    [Xd_x, Xd_y] = ginput(6);
    % % Y direction
    [Yd_x, Yd_y] = ginput(6);
end


Xd2x=Xd_x;
Xd2y=Xd_y;
Yd2x=Yd_x;
Yd2y=Yd_y;


Xd_x = round(Xd2y);
Xd_y = round(Xd2x);
Yd_x = round(Yd2y);
Yd_y = round(Yd2x);

k=1;
for i = 1:2:6
    Xs(k) = sqrt((im_depth(Xd_x(i),Xd_y(i),1)-im_depth(Xd_x(i+1),Xd_y(i+1),1))^2 + (im_depth(Xd_x(i),Xd_y(i),2)-im_depth(Xd_x(i+1),Xd_y(i+1),2))^2 + (im_depth(Xd_x(i),Xd_y(i),3)-im_depth(Xd_x(i+1),Xd_y(i+1),3))^2);
    Ys(k) = sqrt((im_depth(Yd_x(i),Yd_y(i),1)-im_depth(Yd_x(i+1),Yd_y(i+1),1))^2 + (im_depth(Yd_x(i),Yd_y(i),2)-im_depth(Yd_x(i+1),Yd_y(i+1),2))^2 + (im_depth(Yd_x(i),Yd_y(i),3)-im_depth(Yd_x(i+1),Yd_y(i+1),3))^2);
    k=k+1;
end

%%

[Xd_x, Xd_y] = ginput(4);

Xd_x(5) = Xd_x(1);
Xd_y(5) = Xd_y(1);

Xd_x = round(Xd_x);
Xd_y = round(Xd_y);

k=1;
for i = 1:4
    Xs(k) = sqrt((im_depth(Xd_y(i),Xd_x(i),1)-im_depth(Xd_y(i+1),Xd_x(i+1),1))^2 + (im_depth(Xd_y(i),Xd_x(i),2)-im_depth(Xd_y(i+1),Xd_x(i+1),2))^2 + (im_depth(Xd_y(i),Xd_x(i),3)-im_depth(Xd_y(i+1),Xd_x(i+1),3))^2);
%     Ys(k) = sqrt((im_depth(Yd_x(i),Yd_y(i),1)-im_depth(Yd_x(i+1),Yd_y(i+1),1))^2 + (im_depth(Yd_x(i),Yd_y(i),2)-im_depth(Yd_x(i+1),Yd_y(i+1),2))^2 + (im_depth(Yd_x(i),Yd_y(i),3)-im_depth(Yd_x(i+1),Yd_y(i+1),3))^2);
    k=k+1;
end


