%% Conversões de dados e imagens
I = imread('arara.jpg');

%% Imagem unit8 em double
image_double = double(I)/255
% OU
image_double_1 = im2double(I)

%% Imagem double em unit8
image_uint8 = uint8(image_double * 255)
% OU
image_uint8_1 = im2uint8(image_double)

%% Imagem colorida para escalas de cinza
Igray = rgb2gray(I);

imshow(I);
figure(); imshow(Igray)

%% Imagem escalas de cinza para binária
I = imread('castle.jpeg')
Igray = rgb2gray(I);
imhist(Igray)

L = graythresh(Igray) * 255 % Define automaticamente um limiar ideal para imagem
                            % Sem precisar olhar o histograma
I2 = (Igray > L)
imshow(I2)

%% Imagens Coloridas para Binárias
I = imread('Bolas_2.png')
imshow(I)

Rref = 255;
Gref = 255;
Bref = 0;

Ir = (I(:,:,1)== Rref), figure(), imshow(Ir);
Ig = (I(:,:,2)== Gref), figure(), imshow(Ig);
Ib = (I(:,:,3)== Bref), figure(), imshow(Ib);

I2 = Ir & Ig & Ib
figure(), imshow(I2)
