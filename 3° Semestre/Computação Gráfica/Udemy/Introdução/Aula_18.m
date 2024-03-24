%% Operações com Matrizes
A = randi([0,9], 3, 3)
B = randi([0,9], 1, 6)

% Determinante
det(A)

% Inversa
inv(A)

% Transposta
transpose(A)
A'

% Tamanho
size(A) % Retorna o número de linhas e colunas
[nA, mA] = size(A)

% Número de elementos
numel(A)

% Somatório
sum(A) % Soma cada coluna separadamente
% 8     9     2
% 9     6     5  sum -> 18    15    16
% 1     0     9
sum(sum(A)) % Soma tudo retorna em um unico valor -> 49

% Produto
prod(A) % Muliplica cada coluna separadamente -> 72     0    90
prod(prod(A)) % -> 0

% Mínimo
min(A) % Encontra o valor mínimo de cada coluna
       % 1     0     2

min(min(A)) % -> 0

% Máximo
max(A) % Encontra o valor Máximo de cada coluna
       % 9     9     9

max(max(A)) % -> 9

% Remover valores duplicados
unique(A)

