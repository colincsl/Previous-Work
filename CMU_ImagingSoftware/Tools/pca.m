function [coeff, score, x] = pca(depthmap)
%PCA Summary of this function goes here
%   Detailed explanation goes here
imtool(depthmap(:,:,3))
k=1;
for j = 1:size(depthmap,1)
    for i = 1:size(depthmap,2)
        if depthmap(j,i) > 0
            model(k,:) = [j, i, depthmap(j,i)];
            k=k+1;
        end
    end
end
% k
fprintf('%5.0f non-zero elements used in PCA\n', k);


[e, v] = eig(model'*model);
'Eigenvectors'
e
[coeff, score] = princomp(model);

figure(1)
plot3([0 coeff(1,1)], [0 coeff(2,1)], [0 coeff(3,1)], 'r'); hold on;
plot3([0 coeff(1,2)], [0 coeff(2,2)], [0 coeff(3,2)], 'g'); hold on;
plot3([0 coeff(1,3)], [0 coeff(2,3)], [0 coeff(3,3)], 'b'); hold on;
xlabel('X');
ylabel('Y');
zlabel('Z');
title('PCA of depth map; Importance: R > G > B');
axis([-1 1 -1 1 -1 1])

figure(2)
plot(score(:,1), 'or'); hold on;
plot(score(:,2), 'og'); hold on;
plot(score(:,3), 'ob'); hold on;
title('PCA analysis')
xlabel('Component 1')
ylabel('Component 2')
zlabel('Component 3')


x=model;
end

