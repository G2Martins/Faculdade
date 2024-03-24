% Parâmetos do circuito
R = 1e3; % resistência em Ohms
C = 1e-6; % capacitância em Farads

% Função de transferência do circuito
s = tf('s');
H = 1/(R*C*s + 1);

% Cálculo da respsta em frequência e traçado do gráfico
f = logspace(0,6,100); % Frequência de teste de (de 1Hz a 1 MHz)
w = 2*pi*f; % Frequência em rad/s
[num,den] = tfdata(H); % Extrai os coeficientes numéricos da função de transferência
[mag, phase] = freqs(cell2mat(num), cell2mat(den), w); % Cálculo da resposta em frequência
 
%% ======= Gráficos =========
% Parâmetros: frequência e magnitude


%% Eixo X Logarítmico

semilogx(f, abs(mag))
xlabel('Frequência (Hz)');
ylabel('Magnitrude (dB)');
title('Resposta em frequência do circuito passa-baixas');
grid on

%% Eixo Y Logarítmico

semilogy(f, abs(mag))
xlabel('Frequência (Hz)');
ylabel('Magnitrude (dB)');
title('Resposta em frequência do circuito passa-baixas');
grid on

%% Eixo X e Y Logarítmico

loglog(f, abs(mag))
xlabel('Frequência (Hz)');
ylabel('Magnitrude (dB)');
title('Resposta em frequência do circuito passa-baixas');
grid on