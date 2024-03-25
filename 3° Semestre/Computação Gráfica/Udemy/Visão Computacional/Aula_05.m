%% Homografia planar
% Carregar e transformar a imagem
inputImage = imread('harrypotter.png')
imshow(inputImage)

[u, v] = ginput(4);
[U, V] = ginput(4);

% Pontos Originais
originalPoints = [round(u), round(v)]

% Pontos Futuros
futurePoints = [round(U), round(V)]

% Matriz de Transformação
tform = fitgeotrans(originalPoints, futurePoints, 'projective');

% Aplicar Transformação
outputImage = imwarp(inputImage, tform, 'OutputView', imref2d(size(inputImage)));

imshow(outputImage)