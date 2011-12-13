function Build_Map_highrez(varargin)
% BUILD_MAP M-file for Build_Map_highrez.fig
%      BUILD_MAP, by itself, creates a new BUILD_MAP or raises the existing
%      singleton*.
%
%      H = BUILD_MAP returns the handle to a new BUILD_MAP or the handle to
%      the existing singleton*.
%
%      BUILD_MAP('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in BUILD_MAP.M with the given input arguments.
%
%      BUILD_MAP('Property','Value',...) creates a new BUILD_MAP or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before Build_Map_highrez_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to Build_Map_highrez_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".

% Last Modified by GUIDE v2.5 07-Mar-2009 19:26:19

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @Build_Map_highrez_OpeningFcn, ...
                   'gui_OutputFcn',  @Build_Map_highrez_OutputFcn, ...
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


% --- Executes just before Build_Map_highrez is made visible.
function Build_Map_highrez_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to Build_Map_highrez (see VARARGIN)

% Choose default command line output for Build_Map_highrez
handles.output = hObject;

handles.x = 100;
handles.y = 100;
handles.map = zeros(handles.x,handles.y);   %default matrix
%map = zeros(handles.x,handles.y);   %default matrix
axis(handles.Map, [0 handles.x 0 handles.y]);

handles.object_list = zeros(1000,2);
handles.object_list_index = 1;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes Build_Map_highrez wait for user response (see UIRESUME)



% --- Outputs from this function are returned to the command line.
function varargout = Build_Map_highrez_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure

uiwait;

%handles = guidata(hObject);

%varargout{1} = handles.map

%guidata(hObject, handles);


% --- Executes on button press in Build.
function Build_Callback(hObject, eventdata, handles)
% hObject    handle to Build (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
H = guidata(hObject);
global map

in = input('Course type (1-2)')

if H.object_list_index > 2
% for i=1:H.object_list_index-1
%     x = H.object_list(i, 1);
%     y = H.object_list(i, 2);
%     H.map(x,y) = 1;
%     map(x, y) = 1;
% end

for i=2:H.object_list_index-1
    
    x = H.object_list(i-1, 1);
    y = H.object_list(i-1, 2);
    x2 = H.object_list(i, 1);
    y2 = H.object_list(i, 2);
    slope = (y-y2)/(x-x2);
        count = 0;
        n = x;
        m = y;
    while(round(n) ~= round(x2) && round(m) ~= round(y2) && n > 0 && m > 0)
        count = count + .1;
        if x2 > x
            n = n + count;
            m = m + slope;
        elseif x2<x
            n = n - count;
            m = m - slope ;           
        elseif y2 > y
            m = m + count;
            n = n + 1/slope;
        elseif y2 < y
            m = m - count;
            n = n - 1/slope;
        end

%         H.map(round(n),round(m)) = 1;
        map(round(n),round(m)) = 1;
    end
    
end
end

if in == 1
    for k = 200:300
        map(400, k) = 1;
        map(700, k) = 1;
    end

    for k = 300:700
        map(300, k) = 1;
        map(700, k) = 1;
    end    
    
    for h = -1:1
    for k = 300:520
        map(k, 300+h) = 1;
    end    
    end

    for h = -1:1
    for k = 480:700
        map(k, 490+h) = 1;
    end    
    end
    
    for k = 550:650
        map(600, k) = 1;
    end    
elseif in == 2
    for k = 200:700
        map(400, k) = 1;
        map(700, k) = 1;
    end
    
    for k = 30:50
        map(50, k) = 1;
    end
elseif in == 3
    for k = 200:700
        map(400, k) = 1;
        map(700, k) = 1;
    end
    
    for k = 300:380
        map(450, k) = 1;
        map(550, k) = 1;
        map(650, k) = 1;        
    end    
    
    
    
elseif in == 0
    disp('No map base')
end
    
    
% for i = 1:1000
%     for j = 1:1000
%         if map(i,j) ~= 1
%             map(i,j) = 0;
%         end
%     end
% end

uiresume
guidata(hObject, H)
close(gcf)


% --- Executes on selection change in popupmenu1.
function popupmenu1_Callback(hObject, eventdata, handles)
% hObject    handle to popupmenu1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = get(hObject,'String') returns popupmenu1 contents as cell array
%        contents{get(hObject,'Value')} returns selected item from popupmenu1


% --- Executes during object creation, after setting all properties.
function popupmenu1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to popupmenu1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function Size_Callback(hObject, eventdata, handles)
% hObject    handle to Size (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of Size as text
%        str2double(get(hObject,'String')) returns contents of Size as a double


% --- Executes during object creation, after setting all properties.
function Size_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Size (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in line.
function line_Callback(hObject, eventdata, handles)
% hObject    handle to line (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
    prompt = {'Enter Point 1','Enter Point 2'};
    dlg_title = 'Input coordinates';
    num_lines = 1;
    def = {'20','20'};
    coord = inputdlg(prompt,dlg_title,num_lines,def);
    


% --- Executes on button press in circle.
function circle_Callback(hObject, eventdata, handles)
% hObject    handle to circle (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)



function y_coord_Callback(hObject, eventdata, handles)
% hObject    handle to y_coord (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of y_coord as text
%        str2double(get(hObject,'String')) returns contents of y_coord as a double


% --- Executes during object creation, after setting all properties.
function y_coord_CreateFcn(hObject, eventdata, handles)
% hObject    handle to y_coord (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function x_coord_Callback(hObject, eventdata, handles)
% hObject    handle to x_coord (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of x_coord as text
%        str2double(get(hObject,'String')) returns contents of x_coord as a double


% --- Executes during object creation, after setting all properties.
function x_coord_CreateFcn(hObject, eventdata, handles)
% hObject    handle to x_coord (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in ChangeSize.
function ChangeSize_Callback(hObject, eventdata, handles)
% hObject    handle to ChangeSize (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
H = guidata(hObject);
x_ = get(H.x_coord, 'value');
y_ = get(H.y_coord, 'value');
H.x = x_;
H.y = y_;
axis(H.Map, [0 x_ 0 y_]);
guidata(hObject, handles);

% --- Executes on button press in CancelLast.
function CancelLast_Callback(hObject, eventdata, handles)
% hObject    handle to CancelLast (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
H = guidata(hObject);

i = H.object_list_index-1;
H.object_list(i,1) = 0;
H.object_list(i,2) = 0;
H.object_list_index = i;

guidata(hObject, handles);

% --- Executes on mouse press over figure background, over a disabled or
% --- inactive control, or over an axes background.
function figure1_WindowButtonDownFcn(hObject, eventdata, handles)
% hObject    handle to figure1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
try
H = guidata(hObject);
global map
pos = get(H.Map, 'CurrentPoint');
x = uint8(pos(1));
y = uint8(pos(1,2));
plot(H.Map, x,y, 'bd')

i = H.object_list_index;
H.object_list(i,1) = x;
H.object_list(i,2) = y;
H.object_list_index = H.object_list_index + 1;
%pos = [H.object_list(i,1), H.object_list(i,2)]

map(x,y) = 1;
guidata(hObject, H);

catch
end

