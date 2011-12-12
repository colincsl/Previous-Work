function model = X3D2model(filename)
tic
fid = fopen(filename);

tmp_header = fgetl(fid);

model_ = zeros(5E+5, 4);

txt = 0;
while(txt ~= -1)
    tmp = fgets(fid);
    
    i = 1;
    txt = str2num(fgets(fid));
    while (size(txt, 2) == 3)
        if txt(1) ~=0 && txt(2) ~=0 && txt(3) ~=0
            model_(i, 1:3) = txt;
            i = i+1;
        end
        txt = str2num(fgets(fid));
    end
    i
    toc
    tic
    'Positions done'
    i=1;
    txt = str2num(fgets(fid));
    while (size(txt, 2) == 3)
        if txt(1) ~=0 && txt(2) ~=0 && txt(3) ~=0
            model_(i, 4) = txt(1);
            i = i+1;
        end
        txt = str2num(fgets(fid));
    end
    'Colors done'
    
    model = model_(1:i, :);
        
    toc
    
end