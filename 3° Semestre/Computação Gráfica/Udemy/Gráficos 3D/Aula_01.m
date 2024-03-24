x = linspace(-2*pi, 2*pi, 50);
y = sin(x);
z = cos(x);

% Plotar gráfico
figure()
    plot3(x,y,z, 'LineWidth', 3)
    grid 

%% Criar uma matriz de pontos para superfície Trimedimensional

% Sequência de valores para o eixo x
x = -3:1:3;

% Sequência de valores para o eixo y
y = -5:1:5;

% Cria a Matriz de coordenadas X E Y
[X, Y] = meshgrid(x,y) 

% Função Mesh 1 - Gráfico de Malha
Z = ones(size(X)) % Igual as matrizes X e Y

figure()
    mesh(X, Y, Z)

% Função Mesh 2 - Gráfico de Malha
x = -2:0.1:2;
y = -2:0.1:2;
[X, Y] = meshgrid(x,y)

Z = X.*exp(-X.^2 - Y.^2);


figure()
    mesh(X, Y, Z)
    % OU
    surf(X,Y,Z)

%% Plot do gráfico = UTILIZANDO A FUNÇÃO COLORMAP

% Parâmetros para a função colormap
% 'jet' 'hsv', 'gray', 'hot', 'cool', 'spring', 'summer', 'autumn', 'winter'
% 'bone', 'copper', 'pink', 'flag', 'lines', 'prism', 'white'

figure()
    mesh(X, Y, Z)
        title('Gráfico de Superficie 3D')
        xlabel('Eixo X')
        ylabel('Eixo Y')
        zlabel('Eixo Z')
        colormap('jet')

