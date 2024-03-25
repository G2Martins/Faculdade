%% Atividade 01
% 1 = Branco
% 0 = Preto

fundo = zeros(200, 400, 'logical')
fundo(51:150, 21:380) = 1;
imshow(fundo)

%% Atividade 02
I1 = linspace(0,1, 400)
I2 = ones(200,1, 'double')

Image = I2 * I1

imshow(Image)

%% Atividade 03
fundo = zeros(200, 400,'double')
imshow(fundo)

fundo(51:150, 21:380, 1) = 255;
fundo(51:150, 21:380, 2) = 255;
fundo(51:150, 21:380, 3) = 0;



