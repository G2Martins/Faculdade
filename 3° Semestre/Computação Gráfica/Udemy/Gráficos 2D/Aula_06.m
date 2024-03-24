%% Gráficos de sequência discreta -> stem()

x = 0:10:360
y = sind(x)

% stem(Y)
figure(1)
stem(y)

figure(2)
stem(x,y)

% stem(X, Y)
stem(x,y)

% Sobrepor dados
x = [0:10:360]'
y  = [sind(x), 2 *cosd(x)]
stem(x,y)


%% Gráfico de dispersão
x = linspace(0, 2*pi, 80)
y = sin(x) + rand(1, 80)

% scatter(x, y)
scatter(x, y, '.','r')
grid minor

%% Gráfico de escada
x = linspace(0, 2*pi, 50)
y = sin(x)

stairs(x, y)
grid on

%% Gráfocps com barra de erro - errobar(...)
x = linspace(0, 100, 20);
y = 3*x + randi([5 15], 1, 20);

erro = 7*ones(1, 20);

% errorbar(y, erro)
errorbar(x, y, erro)

errorbar(x, y, erro, 'horinzontal')

errorbar(x, y, erro, 'o')

errorbar(x, y, erro, '.')


