%% =====================================================================
%  Atividade 20/ago - Processamento de Sinais Multimidia
%  Espectrograma de uma senoide com frequencia linearmente crescente
%  (chirp linear) analisada pelo algoritmo de STFT da atividade 13/ago.
%
%  Requer: meu_espectrograma.m (mesma pasta)
% =====================================================================
clear; close all; clc;

%% --- i) Frequencia de amostragem ------------------------------------
fs = 8000;                  % Hz
ws = 2*pi*fs;               % frequencia angular de amostragem (rad/s)

%% --- ii) Vetor tempo (2,0 s) ----------------------------------------
T = 2;                      % duracao, em segundos
t = 1/fs : 1/fs : T;        % 16000 amostras

%% --- iii) Frequencia angular variavel no tempo -----------------------
%  w(t) = (ws/2)*t   ->  cresce linearmente de 0 a ws em 2 s
w = (ws/2) * t;

%% --- iv) Senoide x(t) = sen(theta(t)),  d(theta)/dt = w(t) ----------
%  Integrando: theta(t) = (ws/4)*t^2 = (pi*fs/2)*t^2
%  ATENCAO: a fase e a INTEGRAL da frequencia angular. Usar
%  sin(w.*t) estaria ERRADO (daria o DOBRO da frequencia instantanea).
theta = (ws/4) * t.^2;
x     = sin(theta);

%  Frequencia instantanea teorica, em Hz:
%  f_i(t) = w(t)/(2*pi) = (fs/2)*t  ->  0 Hz em t=0 e 8000 Hz em t=2 s
f_inst = (fs/2) * t;

%% --- v) Espectrograma ------------------------------------------------
duracao_ms = 30;            % janela da STFT, em ms (~240 amostras)
[X, f_pico] = meu_espectrograma(x, duracao_ms, fs, true);

[N_meio, n_trechos] = size(X);
N          = 2 * N_meio;
eixo_freq  = (0:N_meio-1) * (fs / N);
eixo_tempo = ((0:n_trechos-1) * N) / fs;

% Figura 1: espectrograma
figure;
imagesc(eixo_tempo, eixo_freq, 20*log10(X + eps));
axis xy;
xlabel('Tempo (s)');
ylabel('Frequencia (Hz)');
title('Espectrograma (STFT) - chirp linear, \omega(t) = (\omega_s/2)t');
colorbar; colormap jet;

% Figura 2: frequencia de pico medida x frequencia instantanea teorica
figure;
plot(eixo_tempo, f_pico, 'o-'); hold on;
plot(t, f_inst, '--', 'LineWidth', 1.2);
yline(fs/2, ':', 'Nyquist (f_s/2)');
xlabel('Tempo (s)');
ylabel('Frequencia (Hz)');
title('Frequencia dominante: medida (STFT) x teorica');
legend('f_{pico} medida', 'f_i(t) = (f_s/2)t teorica', 'Location', 'northwest');
ylim([0 fs]); grid on;

%% --- Relatorio no terminal -------------------------------------------
fprintf('\n--- Frequencia de pico por trecho ---\n');
fprintf('%6s %10s %14s %14s\n', 'trecho', 't (s)', 'f_pico (Hz)', 'f_i teor (Hz)');
for n = 1:n_trechos
    tc = eixo_tempo(n) + (N/2)/fs;          % centro do trecho
    fprintf('%6d %10.3f %14.1f %14.1f\n', n, eixo_tempo(n), f_pico(n), (fs/2)*tc);
end

fprintf('\nCruzamento de Nyquist em t = %.2f s (f_i = %d Hz).\n', 1, fs/2);
fprintf('A partir dai a frequencia observada e o rebatimento fs - f_i(t).\n');
