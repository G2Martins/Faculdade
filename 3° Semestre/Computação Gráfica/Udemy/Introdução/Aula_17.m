%% Operações matemáticas

A_3x3 = [1 2 3; 4 5 6; 7 8 9];
B_3x3 = [2 4 6; 1 3 5; 8 6 4];
C_3x2 = [1 2; 3 4; 5 6];
D_2x3 = [5 7 9; 4 6 8];

% Soma
A_3x3 + B_3x3;
A_3x3 + 10

% Subtração
B_3x3 - A_3x3
B_3x3 - 10

% Multiplicação
C_3x2 * D_2x3

% Divisão
A_3x3 / B_3x3
A_3x3 / 100

% Multiplicação (elemento a elemento)
A_3x3 .* B_3x3

% Divisão (elemento a elemento)
A_3x3 ./ B_3x3