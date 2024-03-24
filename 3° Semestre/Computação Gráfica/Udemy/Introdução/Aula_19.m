%% Programação

%% Entrada de dados
clc, clear

% Valor numérico

N = input('Digite o numero de linhas da matriz: ');
M = input('Digite o numero de colunas da matriz');

A = zeros(N, M)

% Texto

nome = input('Digite o seu nome: ', 's'); % Define que é uma string

%% Operadores relacionais

% Maior que
6 > 4; % -> 1 (True)
6 > 8; % -> 0 (False)

% Menor que
5 < 9 % -> 1 (True)
5 < 2 % -> 0 (False)

% Maior ou igual a...
5 >= 5
6 >= 4
6 >= 9  

% Menor ou igual a...
5 <= 5
6 <= 4
6 <= 9

% Igual a...
6 == 6
6 == 4

% Diferente de 
6 ~= 6
6 ~= 4

%% Operadores Lógicos

% Operação AND (todas tem que ser verdadeiras)
1 & 1 % -> 1
1 & 0 % -> 0
0 & 0 % -> 0
(6 >5) & (4 > 3) % -> 1

% Operação OR (No minimo 1 condição deve ser verdadeira)
1 | 1 % -> 1
1 | 0 % -> 1
0 | 0 % -> 0

% Operação NOT (Inverter)
~1 % -> 0
~0 % -> 1

%% IF/ ELSE 

% IF

% if (expressão)
%       < Comando>
% end

% Exemplo 
x = 0;

if x > 0
    'X é positivo'
end

if x == 0
    'X é zero'
end

if x < 0
    'X é negativo'
end

% IF Else

% if (expressão)
%   <Comando se for Verdadeiro>
% else
%   <Comando se for Falso>
% end

% Exemplo 2

x = 4

if rem(x,2) == 0 % Resto da divisão de x por 2 for = a 0
    'X é Par'
else
    'X é Impar'
end

%% While

% while <expressao>
%       <comando>
% end

% EX 1:
x = 0;

while x <= 10
    x % Mostra o valor atual de x
    x = x+1;
end

% EX 2:
A = [2 5 8 4 6 5 1]
i = 1;
Soma = 0;

while i <= length(A)
    Soma = Soma + A(i)
    i = i +1;
end
   
%% FOR

% For <Variavel de controle = sequencia>
%   <código a ser executado>
% end

% EX 1:

for i = 1:10
    disp(i)
end

% EX 2:
base = 2;
expoentes = [1 2 3 4 5]
potencia = zeros(size(expoentes))

for i = 1:length(expoentes)
    potencia(i) = base^expoentes(i)
end

% EX 3:

A = 1:20
pares = []
impares = []

for i = A
   if rem(i,2) == 0
       pares = [pares, i]
   else
       impares = [impares, i]
   end
end