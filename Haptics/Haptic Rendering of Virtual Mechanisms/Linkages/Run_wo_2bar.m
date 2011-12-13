function [] = Run_wo_2bar(hObject)
%RUN_WO_4BAR Summary of this function goes here
%   Detailed explanation goes here
obj = guidata(hObject);

load_system('double_wo_haptics');
%qc_load_model('double_wo_haptics');
disp('System Loaded')

try
    qc_start_model('double_wo_haptics');
catch
end

% disp('System downloaded')

% qc_build_model('fourbar_wo_haptics');
% disp('System Built')

% qc_connect_model('fourbar_wo_haptics');
% disp('System Connected')
% qc_start_model('double_wo_haptics');
disp('System Started')

set(obj.sys_out, 'String', 'Running 2bar without feeback...')

try
    while(qc_is_model_loaded('double_wo_haptics'))
        pause(1);
    end
catch
    pause(1);
end

set(obj.sys_out, 'String','Waiting...')


global F_x F_y

r_wo_tot = 0;
r_wo = zeros(length(F_x), 1);
for i = 100:1:min(1000, length(F_x))
    r_wo(i) = (F_x(i)^2 + F_y(i)^2)^.5;
    r_wo_tot = r_wo_tot + r_wo(i);
    axes(obj.data_plot)   
    set(obj.link_plot, 'Color', [.5 .5 .5]);        
end
    plot(F_y(:), F_x(:), '-b'); hold on
% ave_r_wo = abs(.5 - (r_wo_tot / length(F_x)));
% ave_r_wo = ((r_wo_tot / length(F_x)));
dev = std(r_wo);

set(obj.DIST_WO, 'String', num2str(dev));
% set(obj.sys_out, 'String', '   ')

guidata(hObject, obj);