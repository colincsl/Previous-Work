function writeProcessed( filename, data, time )
%WRITEPROCESSED Summary of this function goes here
%   Detailed explanation goes here


fid = fopen(filename, 'w');


fprintf(fid, ['TIME POSITION ORIENTATION VELOCITY BUTTONS FORCE TORQUE RAW_POSITION RAW_ORIENTATION RAW_VELOCITY',  '\n'])
% fwrite(fid, 'TIME POSITION ORIENTATION VELOCITY BUTTONS FORCE TORQUE RAW_POSITION RAW_ORIENTATION RAW_VELOCITY')


for i = 1:length(data)
    try
%         fprintf(fid, [num2str(time(i)), '\t', num2str(data(i,:)), '\t', num2str(zeros(1,24)), '\r']);
    fprintf(fid, [num2str(time(i)), ' ', num2str(data(i,:)), ' ', num2str(zeros(1,24)), '\n']);
    catch
        disp(['Error: ', filename])
    end
end


fclose(fid)



end

