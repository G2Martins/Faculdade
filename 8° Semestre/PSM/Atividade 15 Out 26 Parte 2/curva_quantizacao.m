function [Erelat, Nvet] = curva_quantizacao(X, nome)
%CURVA_QUANTIZACAO Erro relativo de quantizacao para 2 <= N <= 256.
%   [Erelat, Nvet] = CURVA_QUANTIZACAO(X) chama QUANTIZA para cada
%   N = 2, 3, ..., 256, guarda o erro relativo de cada caso no vetor Erelat
%   (Erelat(i) corresponde a N = Nvet(i)) e plota o grafico Erelat x N.
%
%   CURVA_QUANTIZACAO(X, NOME) usa NOME no titulo do grafico.
%
%   Exemplo:
%       [E, N] = curva_quantizacao(imread('img2_textura.png'), 'Textura');

if nargin < 2
    nome = 'imagem';
end

Nvet   = 2:256;
Erelat = zeros(size(Nvet));
for i = 1:numel(Nvet)
    [~, Erelat(i)] = quantiza(X, Nvet(i));
end

figure('Name', ['Erelat x N - ' nome], 'NumberTitle', 'off');
plot(Nvet, Erelat, 'LineWidth', 1.5);
grid on;
xlim([2 256]);
xlabel('Quantidade de niveis de cinza N');
ylabel('Erro relativo E_{relat}');
title(['Erro relativo de quantizacao x N - ' nome]);
end
