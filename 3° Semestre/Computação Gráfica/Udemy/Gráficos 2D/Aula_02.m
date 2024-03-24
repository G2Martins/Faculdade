% === 'Marker' ===
% 'o' Circle
% '+' Plus sign
% '*' Asterisk
% '.' point
% 'x' Cross
% 's' square
% 'd' Diamond
% '^' Upward-pointing triangle
% 'v' Downward-pointing triangle
% '>' Right-pointing triangle
% '<' Left-pointing triangle
% 'p' Pentagram


% === 'Color' ===
% 'red 'r'
% 'green' 'g'
% 'blue' 'b'
% 'cyan' 'c'
% 'magenta' 'm'
% 'yellow' 'y'
% 'black' 'k'
% 'white' 'w'

% === 'LineStyle' ===
% '-' Solid Line (Default)
% '--' Dashed line
% 'i' Dotted Line
% '-.' Dash-dot line

% === 'Line Width' ===
% Valor Numérico

%% Parâmetros dos gráficos
%% Plotagem 
figure(1)

plot(x,y,...
    'Color', 'r',...
    'LineStyle','--',...
    'Marker','x',...
    'LineWidth',2)
    
    grid on
    title('O título do gráfico')
    xlabel('Eixo X')
    ylabel('Eixo Y')
    xlim([0 2*pi])
    ylim([-3 3])
    legend('sin(x')

%% Sobreposição de Gráficos
x = linspace(0, 2*pi,100);
y1 = sin(x);
y2 = cos(x);

% Gerando as imagens separadamente
figure(1)
plot(x, y1)
    grid on
    title('O título do gráfico')
    xlabel('Eixo X')
    ylabel('Eixo Y')
    xlim([0 2*pi])
    ylim([-3 3])
    legend('sin(x)')

figure(2)
plot(x, y2)
    grid on
    title('O título do gráfico')
    xlabel('Eixo X')
    ylabel('Eixo Y')
    xlim([0 2*pi])
    ylim([-3 3])
    legend('cos(x')

% 1° forma de Gerar sobreposto
figure(1)
plot(x, y1)
hold on
plot(x, y2)
    grid on
    title('O título do gráfico')
    xlabel('Eixo X')
    ylabel('Eixo Y')
    xlim([0 2*pi])
    ylim([-3 3])
    legend('sin(x)','cos(x)')

% 2° forma de Gerar sobreposto
figure(1)
plot(x, y1, x, y2)
    grid on
    title('O título do gráfico')
    xlabel('Eixo X')
    ylabel('Eixo Y')
    xlim([0 2*pi])
    ylim([-3 3])
    legend('sin(x)','cos(x)')

%% Múltiplos gráficos na mesma figura
x = linspace(0, 2*pi,100);
y1 = sin(x);
y2 = sin(5*x);
y3 = sin(10*x);
y4 = sin(15*x);

%      Linhas, Colunas, posição no grid
subplot(2,2,1)
    plot(x,y1)
    grid on
    title('Sen(x)')
    xlabel('Eixo X')
    ylabel('Eixo Y')
    xlim([0 2*pi])
    ylim([-3 3])
    legend('sin(x)')

subplot(2,2,2)
    plot(x,y2)
    grid on
    title('Sen(5*x)')
    xlabel('Eixo X')
    ylabel('Eixo Y')
    xlim([0 2*pi])
    ylim([-3 3])
    legend('sin(5*x)')

subplot(2,2,3)
    plot(x,y3)
    grid on
    title('Sen(10*x)')
    xlabel('Eixo X')
    ylabel('Eixo Y')
    xlim([0 2*pi])
    ylim([-3 3])
    legend('sin(10*x)')

subplot(2,2,4)
    plot(x,y4)
    grid on
    title('Sen(15*x)')
    xlabel('Eixo X')
    ylabel('Eixo Y')
    xlim([0 2*pi])
    ylim([-3 3])
    legend('sin(15*x)')
