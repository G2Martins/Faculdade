function Y = dilata2(X, metodo)
%DILATA2 Dilata (amplia) uma imagem em escala de cinza pelo fator 2.
%   Y = DILATA2(X) recebe a imagem X (em escala de cinza ou RGB) e devolve
%   a imagem Y com o dobro de linhas e o dobro de colunas.
%
%   Metodo: insercao de zeros seguida de convolucao, feita separadamente
%   na vertical e na horizontal (filtro separavel h' * h).
%
%   Y = DILATA2(X, METODO) escolhe o filtro de interpolacao h:
%     'vizinho' (padrao)  h = [1 1]       -> o pixel inserido recebe a copia
%                                            do pixel de referencia
%                                            (vizinho mais proximo)
%     'linear'            h = [1/2 1 1/2] -> o pixel inserido recebe a media
%                                            dos dois pixels de referencia
%                                            (bilinear, em 2D)
%   Nos dois casos as amostras originais sao preservadas nas posicoes
%   impares, logo comprime2(dilata2(X)) devolve exatamente X.
%
%   Exemplo:
%       Y = dilata2(X);             % 32x32 -> 64x64, vizinho mais proximo
%       Y = dilata2(X, 'linear');   % 32x32 -> 64x64, interpolacao linear

if nargin < 2
    metodo = 'vizinho';
end

% Conversao para escala de cinza em reais no intervalo [0, 1]
if size(X, 3) == 3
    X = rgb2gray(X);
end
X = im2double(X);

% Filtro de interpolacao (soma 2 em cada direcao: compensa os zeros
% inseridos e preserva o brilho medio da imagem)
switch metodo
    case 'vizinho'
        h = [1 1];
    case 'linear'
        h = [1/2 1 1/2];
    otherwise
        error('dilata2: metodo deve ser ''vizinho'' ou ''linear''.');
end

[L, C] = size(X);

% Repete a ultima linha e a ultima coluna: assim o pixel inserido depois da
% borda tem um vizinho real para a media e a borda nao escurece
X = X([1:L L], [1:C C]);

% 1) Insercao de zeros: as amostras originais vao para as posicoes impares
Z = zeros(2*(L+1), 2*(C+1));
Z(1:2:end, 1:2:end) = X;

% 2) Convolucao separavel: colunas com h (vertical), depois linhas com h
%    (horizontal). conv2(u, v, A) faz exatamente essa sequencia.
Y = conv2(h, h, Z);

% 3) Descarta o atraso do filtro e o excesso da borda: fica 2L x 2C
s = ceil(numel(h)/2);
Y = Y(s:s+2*L-1, s:s+2*C-1);
end
