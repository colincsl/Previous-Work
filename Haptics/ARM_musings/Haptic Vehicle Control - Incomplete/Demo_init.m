global v_states map

v_states = [0, 0, 0]'; %x,y,h;

map = zeros(100);


for i = 1:100
    for j = 1:100
        map(i,j) = randn(1);
    end
end


map = round(map)