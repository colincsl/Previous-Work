function idText = convertIDToText(s, idToMatch)
% idText = convertIDToText(s, idToMatch)
%   s is a structure, where each field is a name (e.g., PLAYSOUND) 
%   and its value is a corresponding numeric id. 
%   This function does a reverse-lookup -- it takes a numeric id
%   and returns the name of the corresponding field. If idToMatch
%   does not match any field value in s, idText is [].
%
%    s.GETBATTERYLEVEL = 11;
%    s.STOPSOUNDPLAYBACK = 12;
%    convertIDToText(s, 11)  
%    ans =
%     'GETBATTERYLEVEL'

%   Copyright 2007 The MathWorks, Inc.
%   Revision: 1.0 Date: 2007/11/30

c = struct2cell(s);
fieldIDs = [c{:}];
fieldNames = fieldnames(s);

index = find(fieldIDs == idToMatch);
if ~isempty(index)
    idText = fieldNames{index};
else
    idText = [];
end


