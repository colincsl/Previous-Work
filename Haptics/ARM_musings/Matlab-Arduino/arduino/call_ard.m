function call_ard(ard, event)
p_Val = fscanf(ard);
p_num = str2double(p_Val);    
% l = size(p_Val)
if (p_num >= 0 && p_num <= 1023)
    if (p_num > 500)
        fwrite(ard, 0);
    else
        fwrite(ard, 1);
    end
end

end