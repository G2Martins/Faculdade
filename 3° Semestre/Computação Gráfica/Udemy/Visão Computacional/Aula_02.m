%% Entendendo a ferramenta de Histograma e ginput()
I = imread('castle.jpeg')
imshow(I)

% Gera o histograma da imagem
imhist(I)

% ginput
[u,v] = ginput(1)

u = round(u)
v = round(v)
