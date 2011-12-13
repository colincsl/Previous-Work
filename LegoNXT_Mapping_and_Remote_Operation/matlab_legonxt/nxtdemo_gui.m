function varargout = nxtdemo_gui(varargin)
% FIGURENXTGUI M-file for figureNxtGUI.fig
%      FIGURENXTGUI, by itself, creates a new FIGURENXTGUI or raises the existing
%      singleton*.
%
%      H = FIGURENXTGUI returns the handle to a new FIGURENXTGUI or the handle to
%      the existing singleton*.
%
%      FIGURENXTGUI('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in FIGURENXTGUI.M with the given input arguments.
%
%      FIGURENXTGUI('Property','Value',...) creates a new FIGURENXTGUI or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before nxtdemo_gui_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to nxtdemo_gui_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help figureNxtGUI

% Last Modified by GUIDE v2.5 14-Dec-2007 12:53:07

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @nxtdemo_gui_OpeningFcn, ...
                   'gui_OutputFcn',  @nxtdemo_gui_OutputFcn, ...
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

% --- Executes just before figureNxtGUI is made visible.
function nxtdemo_gui_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to figureNxtGUI (see VARARGIN)

% Choose default command line output for figureNxtGUI
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes figureNxtGUI wait for user response (see UIRESUME)
% uiwait(handles.figureNxtGUI);


% --- Outputs from this function are returned to the command line.
function varargout = nxtdemo_gui_OutputFcn(hObject, eventdata, handles)
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --------------------------------------------------------------------
function FileMenu_Callback(hObject, eventdata, handles)
% hObject    handle to FileMenu (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% --------------------------------------------------------------------
function CloseMenuItem_Callback(hObject, eventdata, handles)
% hObject    handle to CloseMenuItem (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
selection = questdlg(['Close ' get(handles.figureNxtGUI,'Name') '?'],...
                     ['Close ' get(handles.figureNxtGUI,'Name') '...'],...
                     'Yes','No','Yes');
if strcmp(selection,'No')
    return;
end

delete(handles.figureNxtGUI)

% --- Executes on selection change in popupSensor1.
function popupSensor1_Callback(hObject, eventdata, handles) 

% --- Executes during object creation, after setting all properties.
function popupSensor1_CreateFcn(hObject, eventdata, handles)

% --- Executes on selection change in popupSensor2.
function popupSensor2_Callback(hObject, eventdata, handles)

% --- Executes during object creation, after setting all properties.
function popupSensor2_CreateFcn(hObject, eventdata, handles)

% --- Executes on selection change in popupSensor3.
function popupSensor3_Callback(hObject, eventdata, handles)

% --- Executes during object creation, after setting all properties.
function popupSensor3_CreateFcn(hObject, eventdata, handles)

% --- Executes on selection change in popupSensor4.
function popupSensor4_Callback(hObject, eventdata, handles)

% --- Executes during object creation, after setting all properties.
function popupSensor4_CreateFcn(hObject, eventdata, handles)

% --- Executes on slider movement.
function sliderMotorA_Callback(hObject, eventdata, handles)

% --- Executes during object creation, after setting all properties.
function sliderMotorA_CreateFcn(hObject, eventdata, handles)

% --- Executes on slider movement.
function sliderMotorB_Callback(hObject, eventdata, handles)

% --- Executes during object creation, after setting all properties.
function sliderMotorB_CreateFcn(hObject, eventdata, handles)

% --- Executes on slider movement.
function sliderMotorC_Callback(hObject, eventdata, handles)

% --- Executes during object creation, after setting all properties.
function sliderMotorC_CreateFcn(hObject, eventdata, handles)

% --- Executes on button press in pushbuttonMotorA.
function pushbuttonMotorA_Callback(hObject, eventdata, handles)

% --- Executes on button press in pushbuttonMotorB.
function pushbuttonMotorB_Callback(hObject, eventdata, handles)

% --- Executes on button press in pushbuttonMotorC.
function pushbuttonMotorC_Callback(hObject, eventdata, handles)

% --- Executes on button press in toggleMotorA.
function toggleMotorA_Callback(hObject, eventdata, handles)

% --- Executes on button press in toggleMotorB.
function toggleMotorB_Callback(hObject, eventdata, handles)

% --- Executes on button press in toggleMotorC.
function toggleMotorC_Callback(hObject, eventdata, handles)

% --- Executes on button press in checkboxMotorBC.
function checkboxMotorBC_Callback(hObject, eventdata, handles)

