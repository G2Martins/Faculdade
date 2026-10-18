function [Y, Erelat] = quantiza(X, N)
%QUANTIZA Quantiza uma imagem em escala de cinza em N niveis de cinza.
%   [Y, Erelat] = QUANTIZA(X, N) recebe a imagem X (em escala de cinza ou
%   RGB) e a quantidade N de niveis de cinza (inteiro, 2 <= N <= 256).
%
%   A imagem e representada em reais no intervalo [0, 1] e cada pixel e
%   trocado pelo valor mais proximo entre os N niveis igualmente espacados
%       0, 1/(N-1), 2/(N-1), ..., 1
%   Ex.: N = 3 -> 0, 1/2 e 1;   N = 5 -> 0, 0.25, 0.5, 0.75 e 1;
%        N = 2 -> imagem binarizada (limiar em 0.5).
%
%   Saidas:
%       Y      - imagem quantizada (somente N valores possiveis)
%       Erelat - erro quadratico relativo entre a original X e Y:
%                Erelat = sum(|X - Y|^2) / sum(|X|^2)
%
%   Exemplo:
%       [Y, E] = quantiza(imread('img1_fotografia.png'), 8);

if ~isscalar(N) || N ~= round(N) || N < 2 || N > 256
    error('quantiza: N deve ser um inteiro entre 2 e 256.');
end

% Conversao para escala de cinza em reais no intervalo [0, 1]
if size(X, 3) == 3
    X = rgb2gray(X);
end
X = im2double(X);

% Indice do nivel mais proximo: round(X*(N-1)) e um inteiro de 0 a N-1.
% Dividindo por (N-1) volta-se ao valor do nivel no intervalo [0, 1].
Y = round(X * (N-1)) / (N-1);

% Erro quadratico relativo
Erelat = sum((X(:) - Y(:)).^2) / sum(X(:).^2);
end
