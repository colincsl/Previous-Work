function varargout = Copy_of_NXT_GUI(varargin)
% NXT_GUI M-file for NXT_GUI.fig
%      NXT_GUI, by itself, creates a new NXT_GUI or raises the existing
%      singleton*.
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Last Modified by GUIDE v2.5 02-Jan-2009 17:45:11
% paths
addpath('C:\NXT\matlab_legonxt');
addpath('C:\NXT\WiiLab\WiiLab_Matlab\WiimoteFunctions');
addpath('C:\NXT\Mapping');
addpath('C:\NXT\Motion');

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @Copy_of_NXT_GUI_OpeningFcn, ...
                   'gui_OutputFcn',  @Copy_of_NXT_GUI_OutputFcn, ...
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


% --- Executes just before NXT_GUI is made visible.
function Copy_of_NXT_GUI_OpeningFcn(hObject, eventdata, handles, varargin)
disp('opening')
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to NXT_GUI (see VARARGIN)

% Choose default command line output for NXT_GUI
handles.output = hObject;

handles.MODE = 0;
handles.EXITPROGRAM = 0;
handles.internet_mode = 0;

try
    NXT = legoNXT('COM18');
    set(handles.NXT_Connected_indicator, 'BackgroundColor', 'g')
    handles.Lmotor = NXT.portB;
    handles.Rmotor = NXT.portC;
    handles.NXT_Connect = 1;
    
    set(NXT.portB, 'StopType', 'brake');
    set(NXT.portC, 'StopType', 'brake');
    set(NXT.Port4, 'type', 'distance');
    handles.UltrasonicData = NXT.Port4;
    
    start(handles.Lmotor, 0);  
    start(handles.Rmotor, 0);
    
catch E1
    disp('NXT not connected')
    set(handles.NXT_Connected_indicator, 'BackgroundColor', 'r')
    
    handles.NXT_Connect = 0;
    handles.Lmotor = 0;
    handles.Rmotor = 0;
end

set(handles.Wii_Connect_indicator, 'BackgroundColor', 'r')

try
initializeWiimote();
if (isWiimoteConnected() == 1)
    set(handles.Wii_Connect_indicator, 'BackgroundColor', 'g')
end
catch
    disp('Wiimote not connected')
end

 handles.wii = Wii(handles.Lmotor, handles.Rmotor, 4, 4);
 handles.map = Coordinates(140, 100, 30, 10); %(Size X, Size Y, X robot position, Y robot position)
 handles.mapping = handles.map.map;
 handles.map_length = handles.map.length;
 handles.map_height = handles.map.height;
 handles.robotX = handles.map.robotX;
 handles.robotY = handles.map.robotY;
 handles.robotH = handles.map.heading;
 handles.object_Up = 0;
 handles.object_Down = 0;
 handles.object_Left = 0;
 handles.object_Right = 0;
 handles.object = 0;
 handles.clk = cputime;
    f_new = fopen ('C:\update.txt', 'r');
    text = fscanf(f_new, '%s');
    handles.i_text = text;
    fclose(f_new);
 guidata(hObject, handles);

 handles = guidata(hObject);
 handles.T = timer('TimerFcn', @(h, ev) timer_callback(hObject, eventdata),'execution', 'fixedRate', 'Period', .5);
 start(handles.T);
 
 internet_timer = timer('TimerFcn', @(h, ev)internet_callback(hObject, eventdata),'execution', 'fixedRate', 'Period', 1);
 handles.internet_timer = internet_timer;
 %start(handles.internet_timer);

set(handles.Xpos, 'String', handles.robotX);%show position on figure
set(handles.Ypos, 'String', handles.robotY);%show position on figure
set(handles.heading, 'String', handles.robotH);%show heading on figure
set(handles.DistanceText, 'String', '5');


           for i=1:handles.map.length;
               for j=1:handles.map.height;
                   if (handles.map.map(i, j) ~= 0)
                       plot(handles.Map, i, j, 'db')
                       hold on;
                   end
               end
           end
axis(handles.Map, [1 handles.map.length 1 handles.map.height]);
axis manual;
grid ON;


plot(handles.WiiY,(1:1:10), (1:1:10), '-r');
           
set(handles.input_text, 'String', 'On the wiimote press A for full wii control, 1 for refined control, or 2 for point finding. Press B to leave mode.')
handles.timeInit = cputime;

plot(handles.Map, handles.robotX, handles.robotY, 'or');

% Update handles structure    
guidata(hObject, handles);


% --- Outputs from this function are returned to the command line.
function varargout = Copy_of_NXT_GUI_OutputFcn(hObject, eventdata, handles) 
disp('output')
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;



% --- Executes on button press in WiimoteControl.
function WiimoteControl_Callback(hObject, eventdata, handles)
disp('wiimote CB')
% hObject    handle to WiimoteControl (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
H = guidata(hObject);
H.MODE = 1;
set(H.input_text, 'String', 'Wii Control Mode - Use Wiimote to control the robot.')
set(H.WiiNav_indicator, 'BackgroundColor', 'g')
set(H.Internet_indicator, 'BackgroundColor', 'r')
set(H.PointFind_indicator, 'BackgroundColor', 'r')
guidata(hObject, H);

% --------------------------------------------------------------------
function uipanel1_ButtonDownFcn(hObject, eventdata, handles)
% hObject    handle to uipanel1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

function input_text_Callback(hObject, eventdata, handles)
% hObject    handle to input_text (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of input_text as text
%        str2double(get(hObject,'String')) returns contents of input_text as a double

% --- Executes during object creation, after setting all properties.
function input_text_CreateFcn(hObject, eventdata, handles)
% hObject    handle to input_text (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end        

% --- Executes on button press in ExitProgram.
function ExitProgram_Callback(hObject, eventdata, handles)
disp('exit prog cb')
% hObject    handle to ExitProgram (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
H = guidata(hObject);
disp('Exit!');

try
stop(H.T);
stop(H.internet_timer);
stop(H.Lmotor);
stop(H.Rmotor);
delete(H.T);
delete(H.internet_timer);
catch
    disp('Error occurred while trying to quit program')
end
H.MODE = 0;
H.ExitProgram = 1;
delete(H.figure1);



% --- Executes on button press in UP.
function UP_Callback(hObject, eventdata, handles)
disp('up cb')
H = guidata(hObject);

while (H.robotH ~= 90)
    if H.robotH < 90 || H.robotH > 270
        H = turn_Left(H);
    else
        H = turn_Right(H);
    end
end
    
    H = forward(H);
    plot(H.Map, H.robotX, H.robotY, 'or')
    
guidata(hObject, H);


% --- Executes on button press in DOWN.
function DOWN_Callback(hObject, eventdata, handles)
disp('go backward')
H = guidata(hObject);

while (H.robotH ~= 270)
    if H.robotH > 270 || H.robotH < 90
        H = turn_Right(H);
    else
        H = turn_Left(H);
    end
end

    H = forward(H);
    plot(H.Map, H.robotX, H.robotY, 'or')

guidata(hObject, H);


% --- Executes on button press in LEFT.
function LEFT_Callback(hObject, eventdata, handles)
disp('left cb')
H = guidata(hObject);

while (H.robotH ~= 180)
    if H.robotH > 180
        H = turn_Right(H);
    else
        H = turn_Left(H);
    end
end

    H = forward(H);
    plot(H.Map, H.robotX, H.robotY, 'or')

guidata(hObject, H);


% --- Executes on button press in RIGHT.
function RIGHT_Callback(hObject, eventdata, handles)
disp('right')
H = guidata(hObject);

while (H.robotH ~= 0)
    if H.robotH < 180
        H = turn_Right(H);
    else    
        H = turn_Left(H);
    end
end

    H = forward(H);
    plot(H.Map, H.robotX, H.robotY, 'or')
    
guidata(hObject, H);

%%internet timer 
function internet_callback(hObject, eventdata)
disp('internet timer');
H = guidata(hObject);

text_old = H.i_text;

f_new = fopen ('C:\update.txt', 'r');
text = fscanf(f_new, '%s')
fclose(f_new);

if (isequal(text, text_old) == 0)
    H.i_text = text;
    guidata(hObject, H);
    
    if (str2double(text(1)) == 1)
        disp('Up')
        UP_Callback(hObject, eventdata, H);
    elseif (str2double(text(2)) == 1)
        disp('left')
        LEFT_Callback(hObject, eventdata, H);
    elseif (str2double(text(3)) == 1)
        disp('right')
        RIGHT_Callback(hObject, eventdata, H);        
    elseif (str2double(text(4)) == 1)
        disp('down')
        DOWN_Callback(hObject, eventdata, H);     
    else
        disp('Point find')
        H.i_coords = 1;
        x = str2double(strcat(text(5), text(6)))
        y = str2double(strcat(text(7), text(8)))
        H.xInput = (x);
        H.yInput = (y);
        guidata(hObject, H);        
        H = pointFind(H);
    end

    saveas(H.Map, 'C:\Program Files\Apache Software Foundation\Apache2.2\htdocs\map.jpg');
    %h = H.Map;
    %print('-h', 'C:\Program Files\Apache Software Foundation\Apache2.2\htdocs\map2.jpg');
    
end


%% timer
function timer_callback(hObject, eventdata)
disp('Timer');
h = guidata(hObject);
%update robot gui text values
set(h.Xpos, 'String', h.robotX);%show position on figure
set(h.Ypos, 'String', h.robotY);%show position on figure
set(h.heading, 'String', h.robotH);%show heading on figure

%check for wii button presses
try                                             %update wii data
if isWiimoteConnected()
    
[x y z] = getWiimoteAccel();
        h.wii.X = x;
        h.wii.Y = y;
        %h.wii.Z = z;        
    % plot wiimote data
    t1= cputime-10;
    t = cputime;
    
    plot(h.WiiX, x, t, 'ok', 'MarkerFaceColor', 'r', 'MarkerSize', 5)
    set(h.WiiX, 'XLim', [-10 10]);
    set(h.WiiX, 'YLim', [t1 t]);
    hold(h.WiiX, 'on')
    
    plot(h.WiiY, t, y, 'ok', 'MarkerFaceColor', 'g', 'MarkerSize', 5);
    set(h.WiiY, 'XLim', [t1 t]);
    set(h.WiiY, 'YLim', [-10 10]);
    hold(h.WiiY, 'on')
    
    plot(h.Ultrasonic, t, z, 'ok', 'MarkerFaceColor', 'b', 'MarkerSize', 5);
    set(h.Ultrasonic, 'XLim', [t1 t]);
    set(h.Ultrasonic, 'YLim', [-10 10]);
    hold(h.Ultrasonic, 'on')     
    
    %add dot on graph for new robot position
    plot(h.Map, h.robotX, h.robotY, 'or')    
    
    if (isButtonPressed('A'))
        h.MODE = 1;
    end

    if (isButtonPressed('B'))
        h.MODE = 0;
        start(h.Lmotor, 0);
        start(h.Rmotor, 0);
    end

    if (isButtonPressed('ONE'))
        h.MODE = 2;
    end

%     if ~(isButtonPressed('A')==1 && ~isButtonPressed('B')==1 && ~isButtonPressed('ONE')==1 && ~isButtonPressed('TWO')==1 && isButtonPressed('HOME')==1)
%         h.MODE = 0;
%         h.EXITPROGRAM= 1;
%     end

end
catch
    disp('Error in getting Wii data.')
end

%% WiiNav
try
if (h.MODE == 1) && (h.EXITPROGRAM == 0)
    set(h.input_text, 'String', 'Full Wiimote control');
    %disp('Now in Full Wiimote Control mode');
    
    
    if ~isWiimoteConnected()
        disp('Wiimote not connected');
        set(h.input_text, 'String', 'Wiimote not connected')   
        h.MODE = 0;
        set(h.WiiNav_indicator, 'BackgroundColor', 'r')
    end
    
    if (h.MODE == 1)&& (h.EXITPROGRAM == 0) && isWiimoteConnected()
        %time = clock - h.timeInit;    
        %[x y] = getWiimoteAccel();    
        %h.wii.X = x;
        %h.wii.Y = y;
        
        %plot(h.WiiX, x, cputime, 'r');
        %plot(h.WiiY, y, cputime, 'g');
         %add dot on graph for new robot position
        %plot(h.Map, h.robotX, h.robotY, 'or')   
    
        if h.NXT_Connect == 1
            h = detectObj(h);
        end

        try
        %h = avoidObstacles(h);
        h = WiiNav(h);
        catch
            disp('Error in WiiNav routine.')
        end
        
    end
    if h.NXT_Connect == 1 && h.MODE ~= 1
        stop(h.Lmotor);
        stop(h.Rmotor);
    end
       
end
catch
    disp('Error in WiiNav');
end


%% Fine Control
try
if h.MODE == 2 && h.EXITPROGRAM == 0
    set(h.input_text, 'String', 'Refined Control');
    disp('Now in refined control mode');
    while (~isButtonPressed('B') && h.MODE == 2);
    
        map = refinedControl(h, map, Lmotor, Rmotor);         
        if h.NXT_Connect == 1
            stop(h.Lmotor);
            stop(h.Rmotor);
        end
    end
    disp('Leaving refined control mode');
    h.MODE = 0;
    
end
catch
    disp('Error in wii fine control mode.')
end
    
% %% Point Find
% if (h.MODE == 3) && h.EXITPROGRAM== 0
% 
%         set(h.input_text, 'String', 'Point Finding mode');
%         disp('Now in point finding mode');
%             h = pointFind(h);
%         if h.NXT_Connect == 1    
%             stop(h.Lmotor);
%             stop(h.Rmotor);
%         end
%         disp('Robot now at destination');
%         h.MODE = 0;
%         set(h.PointFind_indicator, 'BackgroundColor', 'r')
%         guidata(hObject, h);
%     
% end


try
    %Quit everything
    if h.EXITPROGRAM == 1
        stop(h.T)
        delete(h.T);
        set(h.input_text, 'String', 'Exiting');
    end

catch
    disp('Error in EXITPROGRAM.')
end

guidata(hObject, h);


% --- Executes during object creation, after setting all properties.
function WiimoteControl_CreateFcn(hObject, eventdata, handles)
disp('create wii control')
% hObject    handle to WiimoteControl (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called


% --- Executes during object creation, after setting all properties.
function ExitMode_CreateFcn(hObject, eventdata, handles)
disp('create exit_mode')
% hObject    handle to ExitMode (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% --- Executes on button press in ExitMode.
function ExitMode_Callback(hObject, eventdata, handles)
% hObject    handle to ExitMode (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
disp('exit mode new')
H = guidata(hObject);
H.MODE = 0;
set(H.input_text, 'String', 'On the wiimote press A for full wii control, 1 for refined control, or 2 for point finding. Press B to leave mode.')
set(H.WiiNav_indicator, 'BackgroundColor', 'r')
set(H.Internet_indicator, 'BackgroundColor', 'r')
set(H.PointFind_indicator, 'BackgroundColor', 'r')
guidata(hObject,H)


% % --- Executes on button press in Refined_Mode.
% function Refined_Mode_Callback(hObject, eventdata, handles)
% disp('refined cb')
% % hObject    handle to FineControl (see GCBO)
% % eventdata  reserved - to be defined in a future version of MATLAB
% % handles    structure with handles and user data (see GUIDATA)
% H = guidata(hObject);
% H.MODE = 2;
% set(H.input_text, 'String', 'Refined control mode. Use D-pad on wiimote.')
% set(H.WiiNav_indicator, 'BackgroundColor', 'r')
% set(H.Internet_indicator, 'BackgroundColor', 'g')
% set(H.PointFind_indicator, 'BackgroundColor', 'r')
% disp('Refined')
% guidata(hObject, H);


% --- Executes on button press in Point_Find_Mode.
function Point_Find_Mode_Callback(hObject, eventdata, handles)
% hObject    handle to Pointfinding (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
H = guidata(hObject);
H.MODE = 3;

set(H.WiiNav_indicator, 'BackgroundColor', 'r')
set(H.Internet_indicator, 'BackgroundColor', 'r')
set(H.PointFind_indicator, 'BackgroundColor', 'g')

    prompt = {'Enter X coordinate:','Enter Y coordinate:'};
    dlg_title = 'Input coordinates';
    num_lines = 1;
    def = {'20','20'};
    coord = inputdlg(prompt,dlg_title,num_lines,def);
    H.xInput = str2num(coord{1});
    H.yInput = str2num(coord{2});

plot(H.Map, H.xInput, H.yInput, 'ko');
hold on;

set(H.input_text, 'String', 'Point Finding Mode.')
disp('Point Find')

guidata(hObject, H);

% --- If Enable == 'on', executes on mouse press in 5 pixel border.
% --- Otherwise, executes on mouse press in 5 pixel border or over DOWN.
function DOWN_ButtonDownFcn(hObject, eventdata, handles)
% hObject    handle to DOWN (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on key press with focus on DOWN and none of its controls.
function DOWN_KeyPressFcn(hObject, eventdata, handles)
% hObject    handle to DOWN (see GCBO)
% eventdata  structure with the following fields (see UICONTROL)
%	Key: name of the key that was pressed, in lower case
%	Character: character interpretation of the key(s) that was pressed
%	Modifier: name(s) of the modifier key(s) (i.e., control, shift) pressed
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in WiiNav_indicator.
function WiiNav_indicator_Callback(hObject, eventdata, handles)
% hObject    handle to WiiNav_indicator (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in Internet_indicator.
function Internet_indicator_Callback(hObject, eventdata, handles)
% hObject    handle to Internet_indicator (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in PointFind_indicator.
function PointFind_indicator_Callback(hObject, eventdata, handles)
% hObject    handle to PointFind_indicator (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in Wii_Connect_indicator.
function Wii_Connect_indicator_Callback(hObject, eventdata, handles)
% hObject    handle to Wii_Connect_indicator (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in NXT_Connected_indicator.
function NXT_Connected_indicator_Callback(hObject, eventdata, handles)
% hObject    handle to NXT_Connected_indicator (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in Turn_Left.
function Turn_Left_Callback(hObject, eventdata, handles)
% hObject    handle to Turn_Left (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
H = guidata(hObject);
H = turn_Left(H);
guidata(hObject, H);

% --- Executes on button press in Turn_Right.
function Turn_Right_Callback(hObject, eventdata, handles)
% hObject    handle to Turn_Right (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
H = guidata(hObject);
H = turn_Right(H);
guidata(hObject, H);

% --- Executes on slider movement.
function DistanceSlider_Callback(hObject, eventdata, handles)
% hObject    handle to DistanceSlider (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
H = guidata(hObject);
H.Distance = get(H.DistanceSlider, 'Value');
set(H.DistanceText, 'String', H.Distance);
guidata(hObject, H);
% Hints: get(hObject,'Value') returns position of slider
%        get(hObject,'Min') and get(hObject,'Max') to determine range of slider


% --- Executes during object creation, after setting all properties.
function DistanceSlider_CreateFcn(hObject, eventdata, handles)
% hObject    handle to DistanceSlider (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: slider controls usually have a light gray background.
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end


% --- Executes on button press in clearMap.
function clearMap_Callback(hObject, eventdata, handles)
% hObject    handle to clearMap (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
H = guidata(hObject);
disp('clear map')
%cla(H.Map, reset)
for i=2:H.map.length-1;
    for j = 2:H.map.height-1
        H.map.map(i, j) = 0;
    end
end

%draw new graph
           for i=1:H.map.length;
               for j=1:H.map.height;
                   if (H.map.map(i, j) ~= 0)
                       plot(H.Map, i, j, 'db')
                       hold on;
                   end
               end
           end
axis(H.Map, [1 H.map.length 1 H.map.height]);
axis manual;
grid ON;

guidata(hObject, H)

% --- Executes on mouse press over figure background, over a disabled or
% --- inactive control, or over an axes background.
function figure1_WindowButtonDownFcn(hObject, eventdata, handles)
% hObject    handle to figure1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
try
H = guidata(hObject);

pos = get(H.Map, 'CurrentPoint');
x = uint8(pos(1));
y = uint8(pos(1,2));
H.map.map(x, y) = 1;
plot(H.Map, x,y, 'bd')

guidata(hObject, H);
catch
end

% --------------------------------------------------------------------
function Untitled_1_Callback(hObject, eventdata, handles)
% hObject    handle to Untitled_1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in internet_mode.
function internet_mode_Callback(hObject, eventdata, handles)
% hObject    handle to internet_mode (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
H = guidata(hObject);

button_state = get(hObject,'Value');
disp('button working');

if button_state == get(hObject,'Max')
    disp('internet button pressed')
    stop(H.T); 
    start(H.internet_timer);
    set(H.WiiNav_indicator, 'BackgroundColor', 'r')
    set(H.Internet_indicator, 'BackgroundColor', 'g')
    set(H.PointFind_indicator, 'BackgroundColor', 'r')
else
    disp('internet button off')
    start(H.T); 
    stop(H.internet_timer);   
    set(H.WiiNav_indicator, 'BackgroundColor', 'r')
    set(H.Internet_indicator, 'BackgroundColor', 'r')
    set(H.PointFind_indicator, 'BackgroundColor', 'r')    
end


guidata(hObject, H);