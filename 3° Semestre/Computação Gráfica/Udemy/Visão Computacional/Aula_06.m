%% Brilho
inputImage = im2double(imread('arara.jpg'));

outputImage = inputImage + 0.2; % Adicionando Brilho, porém precisar fazer uma saturação
                                % pelo fato de que ao adicionar 0.2,
                                % pode-se ultrapassar o limite de 1

outputImage(outputImage > 1) = 1; 
outputImage(outputImage < 0) = 0;        

figure(), imshow(inputImage)
figure(), imshow(outputImage)


%% Contraste
inputImage = im2double(imread('arara.jpg'));

% Operação Monádica
outputImage = inputImage * 1.2; % Aumentando o Constrate

% Saturação
outputImage(outputImage > 1) = 1; 
outputImage(outputImage < 0) = 0;        

figure(), imshow(inputImage)
figure(), imshow(outputImage)



%% Negativo
inputImage = im2double(imread('arara.jpg'));

% Operação Monádica
outputImage = 1 - inputImage;
     
figure(), imshow(inputImage)
figure(), imshow(outputImage)


%% Limiarização
inputImage = double(rgb2gray(imread('spider.png'))) / 255;

L = 0.5;
outputImage = (inputImage < L);
imshow(outputImage)


%% Segmentação de Cores
clc, clear, close all;
inputImage = double(imread('tomates.jpg')) / 255;
imshow(inputImage)

% Obter referências
[u,v] = ginput(1);
u = round(u);
v = round(v);

Rref = inputImage(v, u, 1)
Gref = inputImage(v, u, 2)
Bref = inputImage(v, u, 3)

% Escolher o parâmetro a
% Parâmetro 'a' é um parâmetro que aumenta a banda da caor de referência
% para pegar pequenas diferenças de tonalidades
a = 0.2;

% Obter as máscaras de cada camada
IR = (Rref - a < inputImage(:,:,1) & inputImage(:,:,1) < Rref + a)
IG = (Gref - a < inputImage(:,:,2) & inputImage(:,:,2) < Gref + a)
IB = (Bref - a < inputImage(:,:,3) & inputImage(:,:,3) < Bref + a)

% Realizar a operação AND e obter máscara final
I = IR & IG & IB;

figure(), imshow(inputImage)
figure(), imshow(I)




%% Posterização
inputImage = rgb2gray(imread('arara.jpg'))

B = 40;
outputImage = B * floor(inputImage/B);

figure(), imshow(inputImage)
figure(), imshow(outputImage)


%% Equalização 
inputImage = rgb2gray(imread('arara.jpg'))

outputImage = histeq(inputImage)

figure(), imshow(inputImage)
figure(), imshow(outputImage)
