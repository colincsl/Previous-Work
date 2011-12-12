function im = getImage(vid)
% Get image from the camera. Checks if camera is running first.

if ~isrunning(vid)
    start(vid)
end

trigger(vid);

while strcmp(vid.Logging,'on')
    pause(.0001);
end

im = peekdata(vid, 1);

%     get(vid.source)
%     im = getsnapshot(vid);
%     imwrite(im2double(im), 'C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\StructuredLight\test1_1stripe.jpg', 'jpg')

end