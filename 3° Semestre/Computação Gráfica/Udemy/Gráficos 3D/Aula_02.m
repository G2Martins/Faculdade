%% Gráficos de Contorno
% Exemplo Teórico
clear; clc; close

% Cria um grid de coordenadas
x = linspace(-2*pi, 2*pi,100);
y = linspace(-2*pi, 2*pi,100);
[X, Y] = meshgrid(x, y);

% Define uma função para plotar
Z = sin(X) + cos(Y)

% plota o gráfico de cotorno 3D
figure()
    contour3(X,Y,Z,40)

% Exemplo do mundo real - Pico do Japão
clear; clc; close

load topo

[x,y] = meshgrid(1:size(topo, 2), 1:size(topo, 1))

figure()
    contour3(x,y, topo, 20, 'color', 'k')

%% Gráficos de Scatter 3D

% ==== Definindo os dados ===

% Coordenadas X
x = rand(100,1)

% Coordenadas Y
y = rand(100,1)

% Coordenadas Z
z = rand(100,1)

% Cor dos pontos baseada nas coordenadas X e Y
c = x.^2 + y.^2

% Plotagem gráfico

figure()
    scatter3(x,y,z,[], c,"filled")
    xlabel('Eixo X')
    ylabel('Eixo Y')
    zlabel('Eixo Z')
    colorbar

