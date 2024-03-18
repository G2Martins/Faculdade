%% O que é uma variável simbolica?
% São variáveis que não precisam guardar um valor, apenas seu símbolo

%% Como usar no OCTAVE?
pkg load symbolic


%% Criando uma variável simbolica
syms x

y = (x+2) ^2

%% Função Expand()
expand(y)

%% Função Simplify()
simplitfy(x^2 + 4*x +4)

%% Função Solve()
y = x^2 + 3*x - 9
x_resposta = solve(y) % Encontra as raízes dessa expressão
double(x_resposta) % Exibe em valor numerico

%% Função Pretty ()
pretty(x_resposta)
% /   3 sqrt(5)   3 \
% | - --------- - - |
% |       2       2 |
% |                 |
% |  3 sqrt(5)   3  |
% |  --------- - -  |
% \      2       2  /

y = x^2/354 + 3*x/5753 + 9/253/x
%                 2
%  3 x     9      x
% ---- + ----- + ---
% 5753   253 x   354
