function plot_pend(pos)

% for i = 1:10
%     r = 10;   
%     s = size(ang);
%     x = r*cos(ang(1))
%     y = r*sin(ang(1))
    
clf
    plot(pos(1),pos(2),'go'); hold on
    line([0;pos(1)], [0;pos(2)], 'Color', [1,0,0]);
    axis([-15 15 -15 15]);
%     pause(.75)
% end
end