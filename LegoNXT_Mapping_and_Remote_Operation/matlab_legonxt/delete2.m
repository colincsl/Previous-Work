clear
clc

addpath('C:\NXT\matlab_legonxt');

nxt = legoNXT('COM6');

c = clock; 
duration  = 5; 
i=0;

light = nxt.Port3;
set(nxt.Port2, 'type', 'light');

dataLight = [];

while (etime (clock, c) < duration)
    %get data
    dataL = getdata(nxt.Port3)
    dataLight = [dataLight; dataL];

    
    
    i = i + 1;
end

size = length(dataLight);
i = [1:length(dataLight)];
 %plot
hold on;
plot(i, dataLight, '-r');
axis([0 size 0 255]);
stop(Lmotor);
stop(Rmotor);