function [] = Plot_data_2bar(hObject)



obj = guidata(hObject);

global G_P Gone_P EE_gain
global B_CG_P B_CS1_P B_CS2_P
global Bone_CG_P Bone_CS1_P Bone_CS2_P Bone_CS3_P Bone_CS4_P 
% global Btwo_CG_P Btwo_CS1_P Btwo_CS2_P


width = 5;
marker = 10;
 
% plot(10,10)
cla

% r = ((B_CS2_P(2) - B_CS1_P(2))/2);
% r = .5;
r = B_CS2_P(2) - Bone_CS2_P(1); %add height of first bar and subtract the negative length of the second bar
% mid = (Bone_CS2_P(2) + Bone_CS1_P(2))/2;
i = (0:.1:2*pi);
% trans = [Bone_CS4_P(1)-Bone_CG_P(1) Bone_CS4_P(2)-Bone_CG_P(2)];

axes(obj.data_plot)
cla
plot(r*cos(i), r*sin(i), '--g', 'LineWidth', 3);hold on;

axes(obj.link_plot)
set(obj.link_plot, 'Color', [.314 .318 .314]);
axis equal
axis off
cla


%ground link
% line([B_CS1_P(1);Btwo_CS2_P(1)], [B_CS1_P(2);Btwo_CS2_P(2)], 'Color', [0 0 1], 'LineWidth', 3)

%right
plot((B_CS1_P(1)),(B_CS1_P(2)), 'ob', 'MarkerSize', marker, 'MarkerFace', [0 0 0]); hold on
plot((B_CS2_P(1)), (B_CS2_P(2)), 'or', 'MarkerSize', marker, 'MarkerFace', [0 0 0]); hold on;
line([B_CS1_P(1);B_CS2_P(1)], [B_CS1_P(2);B_CS2_P(2)], 'Color', [1 0 0], 'LineWidth', width)
% coupler
plot(Bone_CS1_P(1), Bone_CS1_P(2), 'or', 'MarkerSize', marker, 'MarkerFace', [0 0 0]); hold on;
plot(Bone_CS2_P(1), Bone_CS2_P(2), '^y', 'MarkerSize', marker, 'MarkerFace', [0 0 0]); hold on;
% plot(Bone_CS3_P(1), Bone_CS3_P(2), '^y', 'MarkerSize', marker, 'MarkerFace', [0 0 0]); hold on;

% line([B_CS2_P(1);Btwo_CS1_P(1)], [B_CS2_P(2);Btwo_CS1_P(2)], 'Color', [1 0 0], 'LineWidth', width) %coupler bar
line([Bone_CS1_P(1);Bone_CS3_P(1)], [Bone_CS1_P(2);Bone_CS3_P(2)], 'Color', [1 1 0], 'LineWidth', width) %coupler bar
% line([Bone_CS2_P(1);Bone_CS3_P(1)], [Bone_CS2_P(2);Bone_CS3_P(2)], 'Color', [1 1 0], 'LineWidth', width) %coupler bar

%left
% plot(Btwo_CS1_P(1), Btwo_CS1_P(2), 'or', 'MarkerSize', marker, 'MarkerFace', [0 0 0]); hold on;
% plot(Btwo_CS2_P(1), Btwo_CS2_P(2), 'ob', 'MarkerSize', marker, 'MarkerFace', [0 0 0]); hold on;
% line([Btwo_CS1_P(1);Btwo_CS2_P(1)], [Btwo_CS1_P(2);Btwo_CS2_P(2)], 'Color', [1 0 0], 'LineWidth', width)

axes(obj.data_plot);
axes('Visible', 'off')
set(obj.data_plot, 'Color', [.75 .75 .75]);    

guidata(hObject, obj)