%% Parâmetro dos gráficos
x = linspace(0, 2*pi,100);
y = sin(x);

figure(1)
plot(x, y, x, 2*y)

% Grade
grid on % ou off
grid minor

% Título
title('O Titulo do Gráfico')

% Nomear os eixos
xlabel('Eixo X')
ylabel('Eixo Y')

% Redimensionar os eixos
xlim([0 2*pi])
ylim([-3 3])

% Legenda
legend('Legenda 1', 'legenda 2')
legend('sin(x)', '2*sin(x)')