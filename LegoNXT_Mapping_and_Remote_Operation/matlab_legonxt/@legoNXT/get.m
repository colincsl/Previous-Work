function out = get(obj, varargin)
% GET  Get legoNXT object properties
%
%   V = GET(OBJ, 'P') returns the value, V, of the property P for 
%   the legoNXT object.
%
%   S = GET(OBJ, 'P1', 'P2', ...) returns a structure, S, where
%   S.V1 is the value of property P1, S.V2 is the value of property P2, 
%   and so on. 
%
%   S = GET(OBJ) returns a structure, S, with the current values of all 
%   the properties of the legoNXT object.
%
%    Property         Value
%   -------------------------------------------------------------
%   'Port1'           Returns a handle to the inputPort object that
%   'Port2'           corresponds to the specified input port. 
%   'Port3'         
%   'Port4'
%
%   'PortA'           Returns a handle to the outputPort object that
%   'PortB'           corresponds to the specified output port. 
%   'PortC'        
% 
%   'AutoKeepAlive'   The current status of automatic keepalive 
%                     messages (see legoNXT/set)
% 
%   'SerialPort'      A string identifying the Bluetooth serial 
%                     port (e.g., 'COM40') that is being used.
%
%   'NXTInterface'    Returns a handle to an nxtInterface object. This
%                     handle allows access to the underlying "direct 
%                     command" interface to the LEGO NXT.
%
%  Examples:
%  % The inputPort and outputPort objects can also be accessed using
%  % the dot-notation. In the example below, p and q both refer to the 
%  % same inputPort object:
%     nxt = legoNXT('COM4');
%     p = get(nxt, 'Port1');
%     q = nxt.Port1;
%     val = getdata(p);
%
%  % To use the outputPort object
%     m = get(nxt, 'PortA'); % equivalent to nxt.PortA
%     start(m);
%     stop(m, 'brake');
%
%  % To use the nxtInterface object
%     nxti = get(nxt, 'NXTInterface');
%     playTone(nxti, 3000, 400);
%
% See also legoNXT/get, inputPort, outputPort, nxtInterface

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

obj.checkDeleted();

if isempty(varargin)
    varargin = {'NXTInterface', 'SerialPort', 'AutoKeepAlive', ...
                'PortA', 'PortB', 'PortC', ...
                'Port1', 'Port2', 'Port3', 'Port4'};
end

out = [];

for i=1:length(varargin)
    
   switch lower(varargin{i})
       case {'porta', 'portb', 'portc', 'port1', 'port2', 'port3', 'port4'}
           portname = ['Port' upper(varargin{i}(5))];
           out.(portname) = obj.getPortObject(portname);
            
       case 'nxtinterface'
           out.NxtInterface = obj.getNXTInterfaceObj();
           
       case 'serialport'       
           out.SerialPort = get(obj.getNXTInterfaceObj(), 'SerialPort');
               
       case 'autokeepalive',
           info = autoKeepAlive(obj, 'info');
           if info.keepAliveEnabled,               
               out.AutoKeepAlive = 'on';
           else
               out.AutoKeepAlive = 'off';
           end
                                 
       otherwise
           customError('new', ...
               'legoNXT/get: ''%s'' is not a valid parameter', ...
               varargin{i});           
   end

end

if length(varargin)==1
    fnames = fieldnames(out);
    out = out.(fnames{1});
end
