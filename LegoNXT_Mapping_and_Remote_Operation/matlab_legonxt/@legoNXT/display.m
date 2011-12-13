function display(obj)
%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

obj.checkDeleted();

fprintf(' Lego NXT object\n');

fprintf('  Serial port: %s\n', get(obj, 'SerialPort'));
fprintf('  Automatic KeepAlive messages to NXT: ');
info = autoKeepAlive(obj, 'info');
if info.keepAliveEnabled
    fprintf('ON, every %.2f s\n', info.keepAlivePeriod);
else
    fprintf('OFF\n');
end

fprintf('  Input ports\n');
showSensorInfo('Port1');
showSensorInfo('Port2');
showSensorInfo('Port3');
showSensorInfo('Port4');

fprintf('  Output ports\n');
showMotorInfo('PortA');
showMotorInfo('PortB');
showMotorInfo('PortC');

%%
    function showMotorInfo(portName)
       portObj =  obj.getPortObject(portName);
       if get(portObj, 'Running')
           fprintf('    %s: Running for %.2f sec\n', ...
               portName, get(portObj, 'RunningTime'));
       else
           fprintf('    %s: Stopped for %.2f sec\n', ...
               portName, get(portObj, 'StoppedTime'));           
       end

    end

    function showSensorInfo(portName)
        portObj = obj.getPortObject(portName);
        sensorType = get(portObj, 'type');
        if strcmp(sensorType, 'none')            
            fprintf('    %s: %s\n', portName, sensorType);
        else
            fprintf('    %s: %s, mode = %s\n', portName, ...
                sensorType, get(portObj, 'mode'));
        end
    end
%%
end

