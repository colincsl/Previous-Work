function obj = nxtInterfaceTest(printstatus)
% nxtInterfaceTest  Creates a dummy nxtInterface object
%
%   OBJ = nxtInterfaceTest() constructs a "dummy" object with a subset
%   of the methods of the nxtInterface object. OBJ can be used as a 
%   drop-in replacement for an nxtInterface object in order to test
%   code without an actual LEGO NXT system being present.
%   
%    Note: This object does not really "simulate" an nxtInterface object. 
%    For example, there is no attempt to maintain any internal state, and 
%    most of the methods simply print a message to the command line. 

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

if nargin == 0,
    printstatus = 'print';
end

if strcmp(printstatus, 'noprint')
    obj.doShowMessages = false;
else
    obj.doShowMessages = true;
end

obj = class(obj, 'nxtInterfaceTest');

