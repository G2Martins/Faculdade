%%Polinômios

% Representação de Polinômios

% p(x) = x^2 + 2x - 5

%  x^2, x^1, x^0
p = [1, 2, -5]

% g(x) = 2x^5 + 5x^3 - 3x

%  x^5, x^4, x^3, x^2, x^1, x^0
g = [2, 0, 5, 0, -3, 0]

%% Calculo das raízes

Rp = roots(p) % Retorna as raizes do polinômio informado

Rg = roots(g) % Retorna as raizes do polinômio informado

%% Criar o polinômio a partir das raízes
% +------------+
%  Raízes
%  x= 5
%  x= 2
%  x= -7
% +------------+

% p(x) = (x-5)(x-2)(x+7)

p = poly([5, 2, -7])

% p(x) = 1*x^3 -39*x^1 + 70

%% Avaliação de polinômios
% Determinar o valor de x para obter a resposta do polinômio

% p(x) = x^2 + 2x - 5
p = [1, 2, -5];
x = 0:10
y = -20:0.2:20

% p(2) = 3
resposta = polyval(p,2)
% Resumindo passamos o polinomio para a função e damos um valor de x para
% obter resposta
% OU
% Passar uma matriz de valores
resp = polyval(p, x)
plot(x,resp)

resp_2 = polyval(p,y) 
plot(y, resp_2)

%% Regressão Polinomial

% Interpolação de polinômios
% uso da função polyfit para encontrar o polinômio que melhor que se ajusta
% a um conjunto de pontos dados.

% Definindo os dados
x = [1, 2, 3, 4, 5, 6];
y = [1.2 , 2.3, 3.6, 4.1, 5.1, 6.4];

figure;
    scatter(x, y, 'k', 'filled')

% Ajustando o polinômio
p = polyfit(x, y, 2)
% OU
p = polyfit(x, y, 5)

% Gerando valores para plotar a curva ajustada
x_fit = linspace(min(x), max(x), 100)
y_fit = polyval(p, x_fit)

% Plotando os dados e a curva
figure;
    scatter(x, y, 'k', 'filled');
    hold on;
    plot(x_fit,y_fit)
    xlabel("x_fit")
    ylabel("y_fit")
    legend('Dados', 'Polinômio P')
    grid minor;

%% Multiplicação e Divisão de Polinômios

f = [9, -5, 3, 7];
g = [6, -1, 2];

% Convolução (Multiplicação)
produto = conv(f,g)

% Deconvolução (Divisão)
[quociente, resto] = deconv(f, g)
