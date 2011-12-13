% ard = serial('COM4', 'BAUD', 9600)
% % 
% % 
% fopen(ard)
% fprintf(ard, '*IDN?');
% out = fscanf(ard)

% input = 0;
% i=0;
% % all = zeros(100, 1);
% while (input < 800)
%     i = i+1;
%     input = fscanf(ard);
%     plot(i,input, '--g')
%     pause(.05)
% end

t=cputime();
t2 = cputime();

while (t2 - t < 1)
    pVal = fgetl(ard)
    
    if (pVal > 500)
        fwrite(ard, 0);
    elseif (pVal <= 500)
        fwrite(ard, 1);
    end
    pause(.05)
    t2 = cputime();
end