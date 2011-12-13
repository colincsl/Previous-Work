function nxtdemo(comPort)
% NXTDEMO  Runs a gui for controlling LEGO Mindstorms NXT over Bluetooth
%
%   NXTDEMO('PORT') opens a gui for communicating with a LEGO Mindstorms
%   NXT over a Bluetooth serial port. PORT is the name of the serial port
%   (e.g., 'COM5', 'COM40') that has been assigned by the Bluetooth driver.
%
%   NXTDEMO('test') opens up a gui using a "dummy" LEGO Mindstorms NXT.
%   This option allows the gui to be used without an actual LEGO Mindstorms
%   NXT system.
%
%   Example: 
%       % To open a gui using Bluetooth serial port 'COM4'
%       nxtdemo('COM4'); 
%
%       % To open a gui using a test or a "dummy" LEGO NXT system
%       nxtdemo('test'); 
%
% See also legoNXT, nxtInterface
%
% For general information on LEGO Mindstorms, see
%    http://mindstorms.lego.com/   

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

if ~isempty(findobj(0, 'tag', 'figureNxtGUI'))
    fprintf('NXT GUI demo is already running\n');
    return;
end

if ~exist('comPort', 'var')
    comPort = 'test';
end

if strcmp(comPort, 'test') || strcmp(comPort, 'testd')
    fprintf('nxtdemo: Using a dummy NXT Interface\n');
end

%----------

g_nxt = legoNXT(comPort);
set(g_nxt, 'AutoKeepAlive', 'on');

%----------

g_handles = guidata(nxtdemo_gui('visible', 'off'));
g_imagefiles = [];
g_images = []; 
g_backgroundColor = [.95 .95 .95];
g_mouseButtonIsDown = false;

%----------

loadImages();
initializeFigure();
setupBrickDisplay();

updateSensor{1} = initSensor('1');
updateSensor{2} = initSensor('2');
updateSensor{3} = initSensor('3');
updateSensor{4} = initSensor('4');

initMotor('A');
initMotor('B');
initMotor('C');

initMotorSync('B', 'C');

g_timerObj = timer('Period', 0.1, ...
                   'executionMode', 'fixedSpacing', ...
                   'TimerFcn', @timerCallback, ...
                   'Name', 'NXTDemoGUI_SensorTimer');
start(g_timerObj);
set(g_handles.figureNxtGUI, 'visible', 'on');


%% -----------------------------------------------------------------
    function loadImages()
        % define image files for each kind of image
        g_imagefiles.touch    = 'touch.jpg';
        g_imagefiles.light    = 'light.jpg';
        g_imagefiles.distance = 'ultrasonic.jpg';
        g_imagefiles.sound    = 'sound.jpg';
        g_imagefiles.nosensor = 'nosensors.jpg';
        g_imagefiles.brick    = 'brick.jpg';
        g_imagefiles.motor    = 'motor.jpg';

        % now load the image files
        fldnames = fieldnames(g_imagefiles);
        for i=1:length(fldnames)
            filename = ['nxtdemo_images/' g_imagefiles.(fldnames{i})];
            g_images.(fldnames{i}) = imread(filename);
        end        
    end


    function initializeFigure()
        figName = 'Controlling LEGO Mindstorms NXT from MATLAB';
        set(g_handles.figureNxtGUI, ...
            'color', g_backgroundColor, ...
            'name', figName, ...
            'DeleteFcn', @figureDeleteCallback);        
    end


    function setupBrickDisplay()
        showimage(g_handles.axesNXTBrick, 'brick');
        set(g_handles.axesBackground, ...
            'xlim', [0 1], ...
            'ylim', [0 1], ...
            'visible', 'off');
        
        % draw the lines bewteen the NXT brick to each port
        params = {'color', 'k', ...
                  'linewidth', 2, ...
                  'parent', g_handles.axesBackground};
        % lines for input ports (Port1, Port2, Port3, Port4)
        line([0.14 0.14 0.436 0.436], [0.26 0.32 0.32 0.35], params{:});   
        line([0.377 0.377 0.47 0.47], [0.26 0.295 0.295 0.35], params{:}); 
        line([0.61 0.61 0.507 0.507], [0.26 0.295 0.295 0.35], params{:}); 
        line([0.85 0.85 0.542 0.542], [0.26 0.32 0.32 0.35], params{:});   
        % lines for output ports (PortA, PortB, PortC)
        line([0.20 0.20 0.437 0.437], [0.80 0.74 0.74 0.68], params{:});   
        line([0.527 0.527 0.471 0.471], [0.80 0.77 0.77 0.68], params{:}); 
        line([0.86 0.86 0.505 0.505], [0.80 0.74 0.74 0.68], params{:});   
    end


    % -------------------------
    function figureDeleteCallback(hobj, eventdata) %#ok<INUSD>
        stop(g_timerObj);
        delete(g_timerObj);
        set(g_nxt, 'AutoKeepAlive', 'off');
        delete(g_nxt);
    end


    % -------------------------
    function timerCallback(hobj, eventdata) %#ok<INUSD>
        for i=1:length(updateSensor)
            updateSensor{i}();
        end
    end


%% -----------------------------------------------------------------
    function updateFcn = initSensor(portID)
        hpopup = g_handles.(['popupSensor' portID]);
        himage = g_handles.(['axesSensor', portID]);
        haxdata = g_handles.(['axesDataSensor' portID]);
        htextbox = g_handles.(['textboxSensor' portID]);
        nxtSensorPort = g_nxt.(['Port' portID]);
        sensorIsActive = false;
        
        sensorList = {'none', 'touch', 'distance', 'sound', 'light'};
        set(hpopup,  'String', sensorList);
        set(hpopup, 'Callback', @sensorChangedCallback);
        showimage(himage, 'nosensor');
        
        % The sensor history will be plotted in haxdata. A rectangle 
        % (hrect) shows the current sensor value, and a line (hline) shows
        % the recent history of the values. 
        npts = 30; % number of points in the sensor history
        set(haxdata, 'xlim', [1 npts+2], 'ylim', [0 100], ...
                     'visible', 'off', 'nextplot', 'add');
        hrect = rectangle('position',[npts+1 0 1 1], ...
                          'facecolor', [1 0 0], ...
                          'edgecolor', [1 0 0], ...
                          'parent', haxdata);                      
        hline = plot(1:npts, zeros(1,npts), 'parent', haxdata);
        set(htextbox, 'backgroundcolor', g_backgroundColor, ...
            'horizontalalignment', 'left', 'fontsize', 8, 'String', '');
                        
        updateFcn = @updateDataGauge; 

        
        % -------------------------
        % Called on each sensor reading
        function updateDataGauge()
            if sensorIsActive
                newval = getdata(nxtSensorPort);
                if isempty(newval)
                    set(htextbox, 'String', 'NXT comm. problem');
                else
                    set(htextbox, 'String', '');
                    newval = max(newval,1);
                    data = get(hline, 'ydata');
                    % update display of sensor value history
                    data(1:npts-1) = data(2:npts);
                    data(end) = newval;
                    set(hline, 'ydata', data);
                    % update display of current sensor value 
                    set(hrect, 'position', [npts+1 0 1 newval]);
                end
            end
        end

        
        % -------------------------
        % Called when the user chooses a new sensor type
        function sensorChangedCallback(hobj, eventdata) %#ok<INUSD>
            % callback from a popup
            choices = get(hobj, 'String');
            selection = choices{get(hobj, 'Value')};
            
            % stop data timer before switching sensor type below
            set(nxtSensorPort, 'type', selection);
            sensorIsActive = true;
            switch selection
                case 'none',
                    showimage(himage, 'nosensor');
                    sensorIsActive = false;
                case 'touch'
                    showimage(himage, 'touch');
                case 'distance'
                     showimage(himage, 'distance');
                case 'sound'
                    showimage(himage, 'sound');
                case 'light',
                    showimage(himage, 'light');
            end            
        end
        
    end % of initSensor


%% -----------------------------------------------------------------
    function initMotor(portID)
        htoggle = g_handles.(['toggleMotor' portID]);
        hslider = g_handles.(['sliderMotor', portID]);
        himage = g_handles.(['axesMotor' portID]);
        hlabel = g_handles.(['labelMotor' portID]);
        htextbox = g_handles.(['textboxMotor' portID]);
        nxtMotorPort = g_nxt.(['Port' portID]);
        
        set(hlabel, 'backgroundcolor', g_backgroundColor);
        set(htoggle, 'String', 'Run');
        set(hslider, 'Min', -100, 'Max', 100, ...
                     'Value', 0, 'SliderStep', [0.02 0.1], ...
                     'interruptible', 'off', 'busyaction', 'queue');
        set(htextbox, 'backgroundcolor', g_backgroundColor, ...
            'horizontalalignment', 'left', 'fontsize', 8, 'String', '');
                 
        showimage(himage, 'motor');
        
        set(htoggle, 'Callback', @toggleMotorStatus);
        set(hslider, 'Callback', @changeMotorPower);
        
        % make a colormap with 202 (= length(-100:100)+1) entries
        colors = make_colormap(202);
        changeMotorPower(hslider, []); % initialize slider        

        
        % -------------------------
        % Called when the user clicks on the Run/Running button
        function toggleMotorStatus(hobj, eventdata) %#ok<INUSD>
            % callback from a toggle button
            if get(hobj, 'Value') == 1
                % stop -> start transition
                currentMotorPower = round(get(hslider, 'Value'));
                try
                    start(nxtMotorPort, currentMotorPower);
                    set(htextbox, 'string', '');
                catch
                    set(htextbox, 'string', 'NXT comm. problem');
                end                
                set(hobj, 'String', 'Running');                
            else
                % start -> stop transition
                try
                    stop(nxtMotorPort, 'coast');
                    set(htextbox, 'string', '');
                catch
                    set(htextbox, 'string', 'NXT comm. problem');
                end                
                set(hobj, 'String', 'Run');
            end
        end 

        
        % -------------------------
        % Called when the user changes the motor power setpoint
        function changeMotorPower(hobj, eventdata) %#ok<INUSD>
            % callback from a slider object
            val = round(get(hobj, 'Value'));
            colorIndex = val+101;
            set(hlabel, 'string', sprintf('%d', val));
            set(hobj, 'backgroundcolor', colors(colorIndex,:));
            if get(htoggle, 'Value') == 1
                % motor is running, turn if off
                set(htoggle, 'Value', 0);
                toggleMotorStatus(htoggle, []);
            end
        end
        
    end % of initMotor


%% -----------------------------------------------------------------
    function initMotorSync(portID1, portID2)
        htoggle1 = g_handles.(['toggleMotor' portID1]);
        htoggle2 = g_handles.(['toggleMotor' portID2]);
        hslider1 = g_handles.(['sliderMotor', portID1]);
        hslider2 = g_handles.(['sliderMotor', portID2]);
        
        set(g_handles.checkboxMotorBC, 'backgroundcolor', g_backgroundColor);
        set(g_handles.checkboxMotorBC, 'callback', @toggleSyncStatus);
        hline = line([0.55 0.82], [0.955 0.955], ...
            'linewidth', 1, 'color', 'k', ...
            'parent', g_handles.axesBackground);
        
        % -------------------------
        % Called when checkbox state is changed
        function toggleSyncStatus(hobj, eventdata)  %#ok<INUSD>
            if get(hobj, 'Value') == 1                
               % going from unsync -> sync state
               fixCallback(htoggle1, htoggle2);
               fixCallback(htoggle2, htoggle1);
               fixCallback(hslider1, hslider2);
               fixCallback(hslider2, hslider1);
            else
                % going from sync -> unsync state
                set(htoggle1, 'callback', get(htoggle1, 'userdata'));
                set(htoggle2, 'callback', get(htoggle2, 'userdata'));                
                set(hslider1, 'callback', get(hslider1, 'userdata'));
                set(hslider2, 'callback', get(hslider2, 'userdata'));
            end
        end

        % -------------------------        
        function fixCallback(obj, linkedObj)
            % reset the state of the widget
            set(obj, 'Value', 0);
            feval(get(obj, 'callback'), obj, []);
            % stash the actual callback in the userdata of the widget
            set(obj, 'userdata', get(obj, 'callback'));
            set(obj, 'callback', {@syncMotorState, linkedObj});
        end
        
        % -------------------------
        % Called when either motor state is toggled
        function syncMotorState(thisObj, eventdata, linkedObj)
            set(linkedObj, 'Value', get(thisObj, 'Value'));
            feval(get(thisObj, 'userdata'), thisObj, eventdata);
            feval(get(linkedObj, 'userdata'), linkedObj, eventdata);
        end                
    end

%% -----------------------------------------------------------------
    function showimage(imAxes, imagename)
        image(g_images.(imagename), 'parent', imAxes);
        axis(imAxes, 'equal');
        axis(imAxes, 'off');
    end

end % of nxtdemo


%%
function c = make_colormap(n)
v01 = ((linspace(0, 1, n/2)).^(1/4)).';
v10 = flipud(v01);
z = zeros(n/2,1);
c = [v10 z z; z v01 z]; % red -> 0 -> green
% c = [v10 z z; z z v01]; % red -> 0 -> blue
end
