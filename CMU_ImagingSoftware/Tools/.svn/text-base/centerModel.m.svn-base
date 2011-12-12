function [m_out] = centerModel(m_in)
%CENTERMODEL Summary of this function goes here
%   Detailed explanation goes here

m_in = unique(m_in, 'rows');

x = mean(m_in(:,1));
y = mean(m_in(:,2));
z = mean(m_in(:,3));

m_out = [m_in(:,1)-x,...
         m_in(:,2)-y,...
         m_in(:,3)-z,...
         m_in(:,4)];
    

end

