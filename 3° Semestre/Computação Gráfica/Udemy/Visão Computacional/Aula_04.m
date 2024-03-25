%% Mudança de Escala da Imagem
inputImage = imread('arara.jpg')

% Fatores de alteração de escala
ru = 1.5 % Aumenta 50%
rv = 0.5 % Diminue 50%

% Matriz de Transformação
A = [ru, 0, 0;
     0, rv, 0;
     0,  0, 1]

tform = affine2d(A)
outputImage = imwarp(inputImage, tform)

figure(), imshow(inputImage), axis on
figure(), imshow(outputImage), axis on



%% Translação
inputImage = imread('arara.jpg')

% Translação
tu = 50;  % Pixels
tv = 100; % Pixels  

% Matriz de Transformação
A = [1, 0, tu;
     0, 1, tv;
     0, 0, 1];

% Transformação
tform = affine2d(A');
[outputImage, ref] = imwarp(inputImage, tform);

ref.XWorldLimits(1) = ref.XWorldLimits(1) - tu
ref.YWorldLimits(1) = ref.YWorldLimits(1) - tv

[outputImage, ref] = imwarp(inputImage, tform, 'OutputView',ref);

% Apresentação de Imagens
figure(), imshow(inputImage), axis on
figure(), imshow(outputImage), axis on



%% Rotação
inputImage = imread('arara.jpg')

% Angulo de Rotação
theta = 90; 

% Matriz de Transformação
A = [cosd(theta) -sind(theta) 0;
     sind(theta) cosd(theta) 0;
     0, 0, 1];

% Transformação
tform = affine2d(A');
[outputImage, ref] = imwarp(inputImage, tform);


% Apresentação de Imagens
figure(), imshow(inputImage), axis on
figure(), imshow(outputImage), axis on


%% Cisalhamento
inputImage = imread('arara.jpg')

% Fatores de cisalhamento
su = 0.5; 
sv = 0.5;  

% Matriz de Transformação
A = [1, su, 0;
     sv, 1, 0;
     0, 0, 1];

% Transformação
tform = affine2d(A');
[outputImage, ref] = imwarp(inputImage, tform);

% Apresentação de Imagens
figure(), imshow(inputImage), axis on
figure(), imshow(outputImage), axis on



%% Espelhamento
inputImage = imread('arara.jpg')


% Matriz de Transformação
A = [1, 0, 0;
     0, -1, 0;
     0, 0, 1];

% Transformação
tform = affine2d(A');
[outputImage, ref] = imwarp(inputImage, tform);

% Apresentação de Imagens
figure(), imshow(inputImage), axis on
figure(), imshow(outputImage), axis on



%% Imagem com várias transformações
inputImage = imread('arara.jpg')


% Matriz de Transformação - Espelhamento
A1 = [-1, 0, 0;
     0, -1, 0;
     0, 0, 1];

% Matriz de Transformação - Rotação
theta = 90; 

A2 = [cosd(theta) -sind(theta) 0;
     sind(theta) cosd(theta) 0;
     0, 0, 1];

% Matriz de Transformação - Cisalhamento
su = 0; 
sv = 0.5; 
 
A3 = [1, su, 0;
     sv, 1, 0;
     0, 0, 1];

% Matriz de Transformação Final
A = A1 * A2 * A3

% Transformação
tform = affine2d(A');
[outputImage, ref] = imwarp(inputImage, tform);

% Apresentação de Imagens
figure(), imshow(inputImage), axis on
figure(), imshow(outputImage), axis on

