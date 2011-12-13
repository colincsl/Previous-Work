function [ similarity ] = similarity( pos_a, pos_b )
%SIMILARITY Summary of this function goes here
%   Detailed explanation goes here

similarity = 0;

if length(pos_a) - length(pos_b) < 5
    
    for i = 1:length(pos_a)
        similarity = similarity + sqrt(sum((pos_a(i,:) - pos_b(i, :)).^2));
    end
    
else
    display('Inputs are not equal in length')
end


end

