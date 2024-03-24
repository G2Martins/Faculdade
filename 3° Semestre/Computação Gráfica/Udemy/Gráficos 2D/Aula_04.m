%% Gráficos de funções

x = 0:0.01:2*pi;
y = sin(x);
plot(x,y)

%% fplot()
% Função depende apenas de uma única variável
fun_1 = @(x) sin(x);
fun_2 = @(x) x.^2;

fplot(fun_1, [0 4*pi], 'g')
fplot(fun_2, [-10 10], 'g')

%% fimplicit()
% Função depende apenas de 2 Variáveis

% x^2 + y^2 = r^2
% x^2 + y^2 - r^2 = 0

% Coloca o ponto para elevar elemento a elemento
fun2 = @(x, y) x.^2 + y.^2 - 1
fimplicit(fun2, [-2 2 -2 2], 'm')