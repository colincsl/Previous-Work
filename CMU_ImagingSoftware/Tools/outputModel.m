function outputModel(filename, model)
% Use: Take an image and rectify it based on camera and projector distortions
% Input:  filename (string), model (point cloud)
% Output: X3D file
% Notes: *filename does not include the .x3d extention. 
% *Use Meshlab to view the pointcloud
% Model should include color information
% 
% Author: Colin lea
% Date: June, 2010


%   Filename should be a string

if nargin < 2
    model = filename;
    filename = 'model2';
end

% if filename < 40
%     filename = ['C:\Users\colin\Desktop\subterranean_summer_scholars\trunk\Data\SLmodels\', filename, '.x3d']
% else
    filename = [filename, '.x3d']
% end

fid = fopen(filename, 'w+');



%% Header/footer and parameter text
header = [
'<Scene> ',...
'<Group> ',...
'   <Background groundColor=''1 1 1'' skyColor=''1 1 1''/>' ...
' ',...
'	<Shape>',...
'		<Appearance>',...
'			<Material diffuseColor="1 0 0"/>',...
'		</Appearance>',...
'		<PointSet>',...
'			<Coordinate point='' '];


color = [
''' />',...
'<Color color='''];

footer = [
'''/>',...
'		</PointSet> ',...
'	</Shape>',...
'</Group>',...
'</Scene> '];

%% Write to file

% m = zeros(size(model, 1), 4);
% 
% for i = 1:size(model, 1)
%     try
%         m(i,:) = cell2mat(model{i})';
%     catch
%         
%         size(cell2mat(model{i}))
%         is
%         pause(1)
%     end
% end
    
fprintf(fid, '%s', header); %write header
fprintf(fid, '%1.3f %1.3f %1.3f\n', model(:,1:3)'); %write x,y,z coords
% fprintf(fid, '');

fprintf(fid, '%s \n', color); %write color parameters
fprintf(fid, '%1.2f %1.2f %1.2f \n', [model(:,4), model(:,4), model(:,4)]'); %write rgb colors

fprintf(fid, '%s\n', footer);

fclose(fid);


end









