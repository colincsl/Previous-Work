function out = getSensorInfo(obj)
%  Interrogates the ultrasonic sensor for type and version information.
%  obj - A legoNXT object
%  out - A structure with fields 'ProductID', 'SensorType',
%        'SensorVersion' and 'MeasurementUnits'

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

if ~obj.getEnabled()
    out = [];
    fprintf('Ultrasonic distance sensor has not been enabled\n');
    return;
end

usCmds = obj.getUltrasonicCommands();
nxt = obj.getNXTInterfaceObj();
inputPort =  obj.getInputPort();

try
    version = talkToSensor(nxt, inputPort, usCmds.READ_VERSION);
    productid = talkToSensor(nxt, inputPort, usCmds.READ_PRODUCTID);
    sensortype = talkToSensor(nxt, inputPort, usCmds.READ_SENSORTYPE);
    measunits = talkToSensor(nxt, inputPort, usCmds.READ_MEASUNITS);
    
    out.ProductID = bytezToChar(productid);
    out.SensorType = bytezToChar(sensortype);
    out.SensorVersion = bytezToChar(version);
    out.MeasurementUnits = bytezToChar(measunits);    
catch
    fprintf('Unable to talk to Ultrasonic distance sensor\n');
    fprintf('Ensure that the LEGO NXT is on, and that the \n');
    fprintf('sensor is connected to the correct input port.\n');
    
    out.ProductID = '';
    out.SensorType = '';
    out.SensorVersion = '';
    out.MeasurementUnits = '';
end

end

%-------------------------
% Convert a byte sequence that is a zero-terminated string
% into a MATLAB string.
function out = bytezToChar(byteseq)
  out = char(byteseq(1:find(byteseq==0,1)-1)).';
end
