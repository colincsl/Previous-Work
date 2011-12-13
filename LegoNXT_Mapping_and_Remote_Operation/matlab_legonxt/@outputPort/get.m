function out = get(obj, varargin)
% GET  Get output port object properties
%
%   V = GET(OBJ, 'P') returns the value, V, of the property P for 
%   the outputPort object.
%
%   S = GET(OBJ, 'P1', 'P2', ...) returns a structure, S, where
%   S.V1 is the value of property P1, S.V2 is the value of property P2, 
%   and so on. 
%
%   S = GET(OBJ) returns a structure, S, with the current values of all 
%   the properties of the outputPort object.
% 
%   The list of properties recognized by GET:
%
%    Property       Value
%   ----------------------------------
%   'Port'          The NXT output port represented by this object  
%   'Power'         The power setpoint used with start()
%   'StopType'      The stop type used with stop()
%   'Running'       A boolean, indicating whether the motor is running
%                   or not.
%   'RunningTime'   The time elapsed since the motor started running.
%                   This is NaN if the motor is currently stopped.
%   'StoppedTime'   The time elapsed since the motor stopped running.
%                   This is NaN if the motor is currently running.
%
% See also outputPort/set, outputPort/start, outputPort/stop

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

if isempty(varargin)
    varargin = {'port', 'power', 'stoptype', ...
                'running', 'runningtime', 'stoppedtime'};
end

out = [];

for i=1:length(varargin)
    
   switch lower(varargin{i})
       case 'port'
           [ignore, portName] = obj.getOutputPort();
           out.Port = portName;

       case 'power'
           out.Power = obj.getDefault('Power');

       case 'stoptype',
           out.StopType = obj.getDefault('StopType');

       case 'running'           
           out.Running = obj.getRunning();
           
       case 'runningtime'
           out.RunningTime = nan;
           if obj.getRunning()
               out.RunningTime = obj.timeSinceTransition();
           end
           
       case 'stoppedtime'
           out.StoppedTime = nan;
           if ~obj.getRunning()
               out.StoppedTime = obj.timeSinceTransition();
           end
           
       otherwise
           customError('new', ...
               'outputPort/get: ''%s'' is not a valid parameter', ...
               varargin{i});           
   end

end

if length(varargin)==1
    fnames = fieldnames(out);
    out = out.(fnames{1});
end
