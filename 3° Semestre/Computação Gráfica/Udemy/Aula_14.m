%% Criar Vetores e Matrizes 

% Criar um vetor linha
vetor_linha = [1, 2, 3, 4, 5]

% Criar um vetor coluna 
vetor_coluna = [1; 2; 3; 4; 5]  % 1
                                % 2
                                % 3
                                % 4
                                % 5

% Criar matriz
Matriz_A = [1 2 3 4 5; 5 4 3 2 1]

% 1     2     3     4     5
% 5     4     3     2     1 

Matriz_B = [123;    % 123
            123;    % 123
            123;]   % 123

%% Acessar Valores

% Acessar um valor de uma matriz
Matriz_A(2,4) % Exibe -> 2

% Acessar um valor de uma linha de uma Matriz
Matriz_A(2,:) % Exibe -> 5 4 3 2 1

%% Atribuir novos valores

% Atribuir novos valores à uma célula específica na Matriz
Matriz_A(2, 3) = 100

% Atribuir novos valores à uma linha específica na Matriz
Matriz_A(2, :) = [2, 4 ,6 , 8, 10]

% Atribuir novos valores à uma coluna específica na Matriz


%% Concatenação de Matrizes
A = [1 2 3 4 5]
B = [6 7 8 9 10]

% Concatenação de matrizes (horizontal)
C = [A B] % Exibe -> 1     2     3     4     5     6     7     8     9    10

% Concatenação de matrizes (vertical)
D = [A;B]  % 1     2     3     4     5
           % 6     7     8     9    10

