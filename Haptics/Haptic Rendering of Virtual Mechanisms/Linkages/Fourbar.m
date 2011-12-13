function varargout = Fourbar(varargin)
% FOURBAR M-file for Fourbar.fig
%      FOURBAR, by itself, creates a new FOURBAR or raises the existing
%      singleton*.
%
%      H = FOURBAR returns the handle to a new FOURBAR or the handle to
%      the existing singleton*.
%
%      FOURBAR('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in FOURBAR.M with the given input arguments.
%
%      FOURBAR('Property','Value',...) creates a new FOURBAR or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before Fourbar_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to Fourbar_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help Fourbar

% Last Modified by GUIDE v2.5 27-May-2009 10:05:21

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @Fourbar_OpeningFcn, ...
                   'gui_OutputFcn',  @Fourbar_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before Fourbar is made visible.
function Fourbar_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to Fourbar (see VARARGIN)

% Choose default command line output for Fourbar

handles.output = hObject;


% handles.Run_w = 'fourbar_w_haptics';
% handles.Run_wo = 'fourbar_wo_haptics';
% load_system('fourbar_w_haptics');
% load_system(handles.Run_wo);

% qc_download_model('fourbar_w_haptics')

% qc_build_model(handles.Run_w);
% qc_build_model(handles.Run_wo);


handles.linkages = 4; %4 = fourbar, 2 = double pend, 5 = fivebar

guidata(hObject, handles)
handles = guidata(hObject);

Default(hObject)
Plot_data(hObject);
Update_Callback(hObject)

% Update handles structure
guidata(hObject, handles);




% UIWAIT makes Fourbar wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = Fourbar_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;



function G_LENGTH_Callback(hObject, eventdata, handles)
% hObject    handle to G_LENGTH (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of G_LENGTH as text
%        str2double(get(hObject,'String')) returns contents of G_LENGTH as a double


% --- Executes during object creation, after setting all properties.
function G_LENGTH_CreateFcn(hObject, eventdata, handles)
% hObject    handle to G_LENGTH (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function L_LENGTH_Callback(hObject, eventdata, handles)
% hObject    handle to L_LENGTH (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of L_LENGTH as text
%        str2double(get(hObject,'String')) returns contents of L_LENGTH as a double


% --- Executes during object creation, after setting all properties.
function L_LENGTH_CreateFcn(hObject, eventdata, handles)
% hObject    handle to L_LENGTH (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function R_LENGTH_Callback(hObject, eventdata, handles)
% hObject    handle to R_LENGTH (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of R_LENGTH as text
%        str2double(get(hObject,'String')) returns contents of R_LENGTH as a double


% --- Executes during object creation, after setting all properties.
function R_LENGTH_CreateFcn(hObject, eventdata, handles)
% hObject    handle to R_LENGTH (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function C_LENGTH_Callback(hObject, eventdata, handles)
% hObject    handle to C_LENGTH (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of C_LENGTH as text
%        str2double(get(hObject,'String')) returns contents of C_LENGTH as a double


% --- Executes during object creation, after setting all properties.
function C_LENGTH_CreateFcn(hObject, eventdata, handles)
% hObject    handle to C_LENGTH (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit5_Callback(hObject, eventdata, handles)
% hObject    handle to edit5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit5 as text
%        str2double(get(hObject,'String')) returns contents of edit5 as a double


% --- Executes during object creation, after setting all properties.
function edit5_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

% --- Executes during object creation, after setting all properties.
function edit48_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit42 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

% --- Executes during object creation, after setting all properties.
function edit42_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit42 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

function L_M_Callback(hObject, eventdata, handles)
% hObject    handle to L_M (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of L_M as text
%        str2double(get(hObject,'String')) returns contents of L_M as a double


% --- Executes during object creation, after setting all properties.
function L_M_CreateFcn(hObject, eventdata, handles)
% hObject    handle to L_M (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function R_M_Callback(hObject, eventdata, handles)
% hObject    handle to R_M (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of R_M as text
%        str2double(get(hObject,'String')) returns contents of R_M as a double


% --- Executes during object creation, after setting all properties.
function R_M_CreateFcn(hObject, eventdata, handles)
% hObject    handle to R_M (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function C_M_Callback(hObject, eventdata, handles)
% hObject    handle to C_M (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of C_M as text
%        str2double(get(hObject,'String')) returns contents of C_M as a double


% --- Executes during object creation, after setting all properties.
function C_M_CreateFcn(hObject, eventdata, handles)
% hObject    handle to C_M (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function GRAVITY_Callback(hObject, eventdata, handles)
% hObject    handle to GRAVITY (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of GRAVITY as text
%        str2double(get(hObject,'String')) returns contents of GRAVITY as a double
global Gravity
Gravity = str2num(get(hObject.GRAVITY, 'String'));
set(hObject.GRAVITY, 'String', num2str(Gravity));


% --- Executes during object creation, after setting all properties.
function GRAVITY_CreateFcn(hObject, eventdata, handles)
% hObject    handle to GRAVITY (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function SPRING_Callback(hObject, eventdata, handles)
% hObject    handle to SPRING (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of SPRING as text
%        str2double(get(hObject,'String')) returns contents of SPRING as a double
global ks
ks = str2num(get(hObject.SPRING, 'String'));
set(hObject.SPRING, 'String', num2str(ks));

% --- Executes during object creation, after setting all properties.
function SPRING_CreateFcn(hObject, eventdata, handles)
% hObject    handle to SPRING (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function DAMPER_Callback(hObject, eventdata, handles)
% hObject    handle to DAMPER (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of DAMPER as text
%        str2double(get(hObject,'String')) returns contents of DAMPER as a double


% --- Executes during object creation, after setting all properties.
function DAMPER_CreateFcn(hObject, eventdata, handles)
% hObject    handle to DAMPER (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% % --- Executes on button press in RUN_WO.
% function RUN_WO_Callback(hObject, eventdata, handles)
% % hObject    handle to RUN_WO (see GCBO)
% % eventdata  reserved - to be defined in a future version of MATLAB
% % handles    structure with handles and user data (see GUIDATA)
% obj = guidata(hObject);
% 
% disp('Running Fourbar demo w/o haptic feedback...')
% set(obj.sys_out, 'String', 'Running w/o ...')
% sim('fourbar_wo_haptics.mdl');
% set(obj.sys_out, 'String','Waiting...')
% 
% global F_x F_y
% 
% r_wo_tot = 0;
% r_wo = zeros(length(F_x), 1);
% for i = 1:3:length(F_x)
%     r_wo(i) = (F_x(i)^2 + F_y(i)^2)^.5;
%     r_wo_tot = r_wo_tot + r_wo(i);
%     axes(obj.data_plot)   
%     set(obj.link_plot, 'Color', [.5 .5 .5]);        
%     plot(F_y(i), F_x(i), '-b'); hold on
% end
% % ave_r_wo = abs(.5 - (r_wo_tot / length(F_x)));
% % ave_r_wo = ((r_wo_tot / length(F_x)));
% dev = std(r_wo);
% 
% set(obj.DIST_WO, 'String', num2str(dev));
% set(obj.sys_out, 'String', '   ')
% guidata(hObject, obj);
% 
% disp('End Fourbar demo w/o haptic feedback.')

%--------------------------------------------------------------------------
%--------------------------------------------------------------------------

% --- Executes on button press in RUN_WO.
function RUN_WO_Callback(hObject, eventdata, handles)
% hObject    handle to RUN_WO (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
obj = guidata(hObject);

disp('Running demo w/o haptic feedback...')
set(obj.sys_out, 'String', 'Running w/o ...')

global links

switch links
    case 2
        Run_wo_2bar(hObject);
    case 4
        Run_wo_4bar(hObject);
    otherwise
        disp('Error in RUN_WO_Callback')
end

disp('End demo w/o haptic feedback.')
guidata(hObject, obj);


%--------------------------------------------------------------------------
%--------------------------------------------------------------------------


% --- Executes on button press in RUN_W.
function RUN_W_Callback(hObject, eventdata, handles)
% hObject    handle to RUN_W (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


obj = guidata(hObject);

disp('Running demo with haptic feedback...')

load_system('fourbar_w_haptics')

set(obj.sys_out, 'String', 'Running with feeback...')

% qc_connect_model('fourbar_w_haptics')
qc_start_model('fourbar_w_haptics');

    set(obj.sys_out, 'String', 'Running with feeback...')
%     qc_start_model('fourbar_w_haptics');


try
    while(qc_is_model_loaded('fourbar_w_haptics'))
        pause(1);
    end
catch
    pause(1);
end

% qc_stop_model('fourbar_w_haptics');
% close_system('fourbar_w_haptics', 1);

set(obj.sys_out, 'String', 'Waiting...');
% pause(1)
global F_x_w2 F_y_w2 EE_trans
r_w_tot = 0;
length(F_x_w2)
r_w = zeros(length(F_x_w2), 1);

for i = 100:2:min(1000,length(F_x_w2))
    r_w(i) = ((F_x_w2(i, 2)-EE_trans(1))^2 + (F_y_w2(i,2)^2)-EE_trans(2))^.5;
    r_w_tot = r_w_tot + r_w(i);
    axes(obj.data_plot)
    set(obj.link_plot, 'Color', [.5 .5 .5]);    
end
    plot(F_x_w2(:,2), F_y_w2(:,2), '--r'); hold on
% ave_r_w = abs(.5 - (r_w_tot / length(F_x_w2)))
% ave_r_w = ((r_w_tot / length(F_x_w2)));
dev = std(r_w);

set(obj.DIST_W, 'String', num2str(dev));
set(obj.sys_out, 'String', '   ')
guidata(hObject, obj);

disp('End Fourbar demo with haptic feedback.')


%--------------------------------------------------------------------------
%--------------------------------------------------------------------------

% --- Executes during object creation, after setting all properties.
function DIST_WO_CreateFcn(hObject, eventdata, handles)
% hObject    handle to DIST_WO (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

% --- Executes during object creation, after setting all properties.
function DIST_W_CreateFcn(hObject, eventdata, handles)
% hObject    handle to DIST_W (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in Quit.
function Quit_Callback(hObject, eventdata, handles)
% hObject    handle to Quit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
obj = guidata(hObject);
% qc_remove_downloaded_model('fourbar_w_haptics')
% qc_remove_downloaded_model('fourbar_wo_haptics')
delete(obj.figure1)

%--------------------------------------------------------------------------
%--------------------------------------------------------------------------

%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function Default(hObject)
obj = guidata(hObject);

global ks Cd
global G_P Gone_P Gravity
global B_M B_I B_CG_P B_CS1_P B_CS2_P
global Bone_M Bone_I Bone_CG_P Bone_CS1_P Bone_CS2_P Bone_CS3_P Bone_CS4_P 
global Btwo_M Btwo_I Btwo_CG_P Btwo_CS1_P Btwo_CS2_P 
global Five_C2_M

G_len = G_P(1) - Gone_P(1);
L_len = Btwo_CS1_P(2) - Btwo_CS2_P(2);
R_len = B_CS2_P(2) - B_CS1_P(2);

%fourbar
set(obj.G_LENGTH, 'String', num2str(G_len));
set(obj.L_LENGTH, 'String', num2str(L_len));
set(obj.R_LENGTH, 'String', num2str(R_len));

set(obj.C_M, 'String', num2str(Bone_M));
set(obj.L_M, 'String', num2str(Btwo_M));
set(obj.R_M, 'String', num2str(B_M));

%settings
set(obj.GRAVITY, 'String', num2str(Gravity));
set(obj.SPRING, 'String', num2str(ks));
set(obj.DAMPER, 'String', num2str(Cd));

%double
set(obj.Double_base_len, 'String', num2str(R_len));
set(obj.Double_follow_len, 'String', num2str(G_len));

set(obj.Double_base_M, 'String', num2str(B_M));
set(obj.Double_follow_M, 'String', num2str(Bone_M));

% %fivebar
% set(obj.Five_G_len, 'String', num2str(G_len));
% set(obj.Five_L_len, 'String', num2str(L_len));
% set(obj.Five_R_len, 'String', num2str(R_len));
% 
% set(obj.Five_C_M, 'String', num2str(Bone_M));
% set(obj.Five_L_M, 'String', num2str(Btwo_M));
% set(obj.Five_R_M, 'String', num2str(B_M));
% set(obj.Five_C2_M, 'String', num2str(Five_C2_M));

%window
set(obj.select_fourbar, 'Value', 1);
set(obj.select_double, 'Value', 0);
% set(obj.select_five, 'Value', 0);
% set(obj.select_sixbar, 'Value', 0);

guidata(hObject, obj)

%--------------------------------------------------------------------------
%--------------------------------------------------------------------------


% % --- Executes on button press in Update.
function Update_Callback(hObject, eventdata, handles)
% obj = guidata(hObject);
global links

if links == 2
    Update_2bar(hObject);
elseif links == 4
    Update_4bar(hObject);

% EE_trans = 0.0000    0.2500         0
elseif links == 5
    Update_5bar(hObject);
else
    disp('Cannot update')
end

Plot_data(hObject);

% guidata(hObject, obj);

% %
% 
% obj = guidata(hObject);
% 
% global ks Cd EE_gain
% global G_P Gone_P Gravity
% global B_M B_I B_CG_P B_CS1_P B_CS2_P
% global Bone_M Bone_I Bone_CG_P Bone_CS1_P Bone_CS2_P Bone_CS3_P Bone_CS4_P 
% global Btwo_M Btwo_I Btwo_CG_P Btwo_CS1_P Btwo_CS2_P
% 
% %get info from gui
% C_len = str2double(get(obj.C_LENGTH, 'String'));
% G_len = str2double(get(obj.G_LENGTH, 'String'));
% L_len = str2double(get(obj.L_LENGTH, 'String'));
% R_len = str2double(get(obj.R_LENGTH, 'String'));
% 
% B_M = str2double(get(obj.R_M, 'String'));
% Bone_M = str2double(get(obj.C_M, 'String'));
% Btwo_M = str2double(get(obj.L_M, 'String'));
% 
% Gravity = str2double(get(obj.GRAVITY, 'String'));
% ks = str2double(get(obj.SPRING, 'String'));
% Cd = str2double(get(obj.DAMPER, 'String'));
% 
% %ground points
% G_P = [G_len/2 0 0];
% Gone_P = [-G_len/2 0 0];
% 
% %Right
% B_CS1_P = G_P;
% B_CS2_P = [G_P(1), R_len, 0];
% B_CG_P = [G_P(1), R_len/2, 0];
% 
% %Left
% Btwo_CS1_P = [Gone_P(1), L_len, 0];
% Btwo_CS2_P = [Gone_P(1), 0, 0];
% Btwo_CG_P = [Gone_P(1), L_len/2, 0];
% 
% %Coupler
% Bone_CS1_P = [G_P(1), R_len, 0]; %right
% Bone_CS2_P = [Gone_P(1), L_len, 0]; %left
% Bone_CG_P =  [0, (L_len+R_len)/2, 0];
% 
% len = ((R_len-L_len)^2+G_len^2)^.5;
% ang = asin((G_P(1)-Gone_P(1))/(G_len));
% a = ang*180/pi;
% 
% Bone_CS3_P = [len*cos(ang), (L_len+R_len)/2 + .15*len*sin(ang(1)), 0];  %sensor+actuator
% Bone_CS4_P = [len*cos(ang), (L_len+R_len)/2 + .15*len*sin(ang(1)), 0];
% 
% %inertias
% width = .1;     %y
% depth = .05;    %z
% 
% B_I = B_M*...
%     [width^2+depth^2  -R_len*width      -R_len*depth;...
%     -R_len*width      R_len^2+depth^2   -width*depth;...
%     -R_len*depth      -width*depth      R_len^2+width^2]
% 
% 
% Bone_I = Bone_M*...
%     [width^2+depth^2  -len*width      -len*depth;...
%     -len*width      len^2+depth^2   -width*depth;...
%     -len*depth      -width*depth      len^2+width^2];
% 
% Btwo_I = B_M*...
%     [width^2+depth^2  -L_len*width      -L_len*depth;...
%     -L_len*width      L_len^2+depth^2   -width*depth;...
%     -L_len*depth      -width*depth      L_len^2+width^2];
% 
% % B_I = 100*B_I;
% % Bone_I = 100*Bone_I;
% % Btwo_I = 100*Btwo_I;
% 
% max_C = Bone_CS3_P(2);
% min_C = max_C - min(L_len, R_len);
% cen_C = (max_C+min_C)/2;
% dia_C = max_C-min_C;
% 
% EE_gain = dia_C / .033
% EE_trans = [len*cos(ang) cen_C 0]
% 
% guidata(hObject,obj)
% 
% Plot_data(hObject);



%--------------------------------------------------------------------------
%--------------------------------------------------------------------------
function Plot_data(hObject)

% obj = guidata(hObject)

% links = obj.linkages
global links


if links == 2
    Plot_data_2bar(hObject);    
elseif links == 3
    
elseif links == 4    
    Plot_data_4bar(hObject);
elseif links == 5
    Plot_data_5bar(hObject);
elseif links == 6
    
else
    disp('Incorrect number of linkages')
end

% guidata(hObject, obj);


% obj = guidata(hObject);
% 
% global G_P Gone_P EE_gain
% global B_CG_P B_CS1_P B_CS2_P
% global Bone_CG_P Bone_CS1_P Bone_CS2_P Bone_CS3_P Bone_CS4_P 
% global Btwo_CG_P Btwo_CS1_P Btwo_CS2_P
% 
% 
% width = 5;
% marker = 10;
% % clf
% % plot(0,0)
% cla
% 
% % r = ((B_CS2_P(2) - B_CS1_P(2))/2);
% r = .5;
% mid = (Bone_CS2_P(2) + Bone_CS1_P(2))/2;
% i = (0:.1:2*pi);
% trans = [Bone_CS4_P(1)-Bone_CG_P(1) Bone_CS4_P(2)-Bone_CG_P(2)];
% 
% axes(obj.data_plot)
% cla
% plot(r*cos(i), r*sin(i), '--g', 'LineWidth', 3);hold on;
% 
% axes(obj.link_plot)
% set(obj.link_plot, 'Color', [.314 .318 .314]);
% axis off
% cla
% 
% 
% %ground link
% line([B_CS1_P(1);Btwo_CS2_P(1)], [B_CS1_P(2);Btwo_CS2_P(2)], 'Color', [0 0 1], 'LineWidth', 3)
% 
% %right
% plot((B_CS1_P(1)),(B_CS1_P(2)), 'ob', 'MarkerSize', marker, 'MarkerFace', [0 0 0]); hold on
% plot((B_CS2_P(1)), (B_CS2_P(2)), 'or', 'MarkerSize', marker, 'MarkerFace', [0 0 0]); hold on;
% line([B_CS1_P(1);B_CS2_P(1)], [B_CS1_P(2);B_CS2_P(2)], 'Color', [1 0 0], 'LineWidth', width)
% % coupler
% plot(Bone_CS1_P(1), Bone_CS1_P(2), 'or', 'MarkerSize', marker, 'MarkerFace', [0 0 0]); hold on;
% plot(Bone_CS2_P(1), Bone_CS2_P(2), 'or', 'MarkerSize', marker, 'MarkerFace', [0 0 0]); hold on;
% plot(Bone_CS3_P(1), Bone_CS3_P(2), '^y', 'MarkerSize', marker, 'MarkerFace', [0 0 0]); hold on;
% 
% line([B_CS2_P(1);Btwo_CS1_P(1)], [B_CS2_P(2);Btwo_CS1_P(2)], 'Color', [1 0 0], 'LineWidth', width) %coupler bar
% line([Bone_CS1_P(1);Bone_CS3_P(1)], [Bone_CS1_P(2);Bone_CS3_P(2)], 'Color', [1 1 0], 'LineWidth', width) %coupler bar
% line([Bone_CS2_P(1);Bone_CS3_P(1)], [Bone_CS2_P(2);Bone_CS3_P(2)], 'Color', [1 1 0], 'LineWidth', width) %coupler bar
% 
% %left
% plot(Btwo_CS1_P(1), Btwo_CS1_P(2), 'or', 'MarkerSize', marker, 'MarkerFace', [0 0 0]); hold on;
% plot(Btwo_CS2_P(1), Btwo_CS2_P(2), 'ob', 'MarkerSize', marker, 'MarkerFace', [0 0 0]); hold on;
% line([Btwo_CS1_P(1);Btwo_CS2_P(1)], [Btwo_CS1_P(2);Btwo_CS2_P(2)], 'Color', [1 0 0], 'LineWidth', width)
% 
% axes(obj.data_plot);
% axes('Visible', 'off')
% set(obj.data_plot, 'Color', [.75 .75 .75]);    
% 
% guidata(hObject, obj)


%--------------------------------------------------------------------------
%--------------------------------------------------------------------------

function Double_base_len_Callback(hObject, eventdata, handles)
% hObject    handle to Double_base_len (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of Double_base_len as text
%        str2double(get(hObject,'String')) returns contents of Double_base_len as a double


% --- Executes during object creation, after setting all properties.
function Double_base_len_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Double_base_len (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function Double_follow_len_Callback(hObject, eventdata, handles)
% hObject    handle to Double_follow_len (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of Double_follow_len as text
%        str2double(get(hObject,'String')) returns contents of Double_follow_len as a double


% --- Executes during object creation, after setting all properties.
function Double_follow_len_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Double_follow_len (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function Double_base_M_Callback(hObject, eventdata, handles)
% hObject    handle to Double_base_M (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of Double_base_M as text
%        str2double(get(hObject,'String')) returns contents of Double_base_M as a double


% --- Executes during object creation, after setting all properties.
function Double_base_M_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Double_base_M (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function Double_follow_M_Callback(hObject, eventdata, handles)
% hObject    handle to Double_follow_M (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of Double_follow_M as text
%        str2double(get(hObject,'String')) returns contents of Double_follow_M as a double


% --- Executes during object creation, after setting all properties.
function Double_follow_M_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Double_follow_M (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in select_fourbar.
function select_fourbar_Callback(hObject, eventdata, handles)
% hObject    handle to select_fourbar (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
obj = guidata(hObject);

global links
links = 4;

set(obj.select_fourbar, 'Value', 1);
set(obj.select_double, 'Value', 0);
% set(obj.select_five, 'Value', 0);
% set(obj.select_sixbar, 'Value', 0);

guidata(hObject, obj);

% --- Executes on button press in select_double.
function select_double_Callback(hObject, eventdata, handles)
% hObject    handle to select_double (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
obj = guidata(hObject);

global links
links = 2;
set(obj.select_double, 'Value', 1);
set(obj.select_fourbar, 'Value', 0);
% set(obj.select_five, 'Value', 0);
% set(obj.select_sixbar, 'Value', 0);

guidata(hObject, obj);


