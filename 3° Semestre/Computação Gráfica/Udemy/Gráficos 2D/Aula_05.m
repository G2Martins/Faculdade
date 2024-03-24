%% Parâmetros
x = 20:29;
y = randi([5 25], 1, 10);

%% Bar(y)
bar(y)

%% Bar(x,y)
bar(x,y)

%% Barras horinzontais
barh(x,y)

%% Personalizanodo
% Cor
bar(x,y,'r')

% largura
bar(x, y, 1)

%% Estilo
y = [2 5 3 ; 6 2 7; 1 8 4; 3 6 3; 1 4 6];
x = 1:5;

% Normal
bar(x,y)

% Histograma 1
figure(1)
bar(x,y,'hist')

% Histograma 2 = Centralizado
figure(2)
bar(x,y,'histc')

% Empilhado
bar(x,y,'stacked')
