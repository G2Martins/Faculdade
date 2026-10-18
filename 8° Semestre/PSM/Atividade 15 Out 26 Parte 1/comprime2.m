function Y = comprime2(X)
%COMPRIME2 Comprime (reduz) uma imagem em escala de cinza pelo fator 2.
%   Y = COMPRIME2(X) recebe a imagem X (em escala de cinza ou RGB) e
%   devolve a imagem Y com metade das linhas e metade das colunas.
%
%   Metodo: simples eliminacao de pixels adjacentes. De cada bloco 2x2
%   mantem-se apenas o pixel superior esquerdo (linhas e colunas impares);
%   os outros tres sao descartados. Nao ha filtro anti-aliasing antes da
%   subamostragem.
%
%   Exemplo:
%       X = imread('img1_fotografia.png');
%       Y = comprime2(X);          % 512x512 -> 256x256

% Conversao para escala de cinza em reais no intervalo [0, 1]
if size(X, 3) == 3
    X = rgb2gray(X);
end
X = im2double(X);

% Mantem 1 pixel a cada 2, na vertical e na horizontal
Y = X(1:2:end, 1:2:end);
end
