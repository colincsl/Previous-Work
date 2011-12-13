function out = get(obj, varargin)
% GET  Get input port object properties
%
%   V = GET(OBJ, 'P') returns the value, V, of the property P for 
%   the inputPort object.
%
%   S = GET(OBJ, 'P1', 'P2', ...) returns a structure, S, where
%   S.V1 is the value of property P1, S.V2 is the value of property P2, 
%   and so on. 
%
%   S = GET(OBJ) returns a structure, S, with the current values of all 
%   the properties of the inputPort object.
%
% See also inputPort/set

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

out = get(obj.getSensorObj(), varargin{:});

