function msg = statusCode2Text(statusCode)
% Converts the status code returned by the LEGO NXT into
% a string.

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

switch statusCode
    case 0,  % 0x00
        msg = 'Success'; 
    case 32, % 0x20
        msg = 'Pending communication transaction in progress';
    case 64, % 0x40
        msg = 'Specified mailbox queue is empty';
    case 189, % 0xBD
        msg = 'Request failed (i.e. specified file not found)';
    case 190, % 0xBE
        msg = 'Unknown command opcode'; 
    case 191, % 0xBF
        msg = 'Insane packet';
    case 192, % 0xC0
        msg = 'Data contains out-of-range values';
    case 221, % 0xDD
        msg = 'Communication bus error';
    case 222, % 0xDE
        msg = 'No free memory in communication buffer';
    case 223, % 0xDF
        msg = 'Specified channel/connection is not valid';
    case 224, % 0xE0
        msg = 'Specified channel/connection not configured or busy';
    case 236, % 0xEC
        msg = 'No active program';
    case 237, % 0xED
        msg = 'Illegal size specified';
    case 238, % 0xEE
        msg = 'Illegal mailbox queue ID specified';
    case 239, % 0xEF
        msg = 'Attempted to access invalid field of a structure';
    case 240, % 0xF0
        msg = 'Bad input or output specified';
    case 251, % 0xFB
        msg = 'Insufficient memory available';
    case 255, % 0xFF
        msg = 'Bad arguments';
    otherwise
        msg = sprintf('status=0x%x', statusCode);
end

