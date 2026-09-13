%% Atividade de Laboratorio n. 02 - Parte 2
%  Bartlett e Welch; MNF e MDF sobre as estimativas x sinal completo.
%  Rodar com esta pasta como Current Folder.
clear; close all; clc;

addpath(fullfile('..', 'Atividade 13 Ago 26'));   % meu_espectrograma.m

DUR_MS = 30;    % duracao da janela; N e derivado por sinal (resolucao ~33 Hz)
SOBREP = 0.5;   % sobreposicao do Welch, conforme enunciado

%% Sinal 1 - ruido branco filtrado (300-3000 Hz)
fs1 = 8000; T1 = 5; F_INF = 300; F_SUP = 3000;
rng(42);
L1 = fs1*T1;
R  = fft(randn(L1,1));
fr = (0:L1-1)' * (fs1/L1);
fr(fr > fs1/2) = fs1 - fr(fr > fs1/2);
R(fr < F_INF | fr > F_SUP) = 0;
x1 = real(ifft(R));  x1 = x1/max(abs(x1));

% banda plana: MNF e MDF teoricas = centro da banda
fprintf('Sinal 1 - referencia teorica: %.1f Hz\n', (F_INF+F_SUP)/2);
analisa('1 - Ruido branco filtrado (300-3000 Hz)', x1, fs1, DUR_MS, SOBREP);

%% Sinal 2 - notas musicais
[x2, fs2] = audioread('piano.wav');
x2 = mean(x2,2);  x2 = x2/max(abs(x2));
analisa('2 - Notas musicais (piano)', x2, fs2, DUR_MS, SOBREP);

%% Sinal 3 - voz
[x3, fs3] = audioread('audio_voz.wav');
x3 = mean(x3,2);  x3 = x3/max(abs(x3));
analisa('3 - Sinal de voz', x3, fs3, DUR_MS, SOBREP);


%% Funcao local
function analisa(nome, x, fs, dur_ms, sobrep)

N = round(dur_ms/1000 * fs);
if mod(N,2) ~= 0, N = N - 1; end
x = x(:);
L = length(x);
if mod(L,2) ~= 0, x = x(1:end-1); L = L - 1; end

fprintf('\n==============================================================\n');
fprintf('SINAL %s\n', nome);
fprintf('fs = %d Hz | %.2f s | N = %d | resolucao = %.1f Hz\n', ...
        fs, L/fs, N, fs/N);
fprintf('==============================================================\n');

% valor "real": DFT do sinal completo, sem STFT
P_real = abs(fft(x)); P_real = P_real(1:L/2).^2;
f_real = (0:(L/2-1))' * (fs/L);
[mnf_real, mdf_real] = mnf_mdf(P_real, fs, L);

[P_bar, f_bar, nt_bar] = espectro_medio(x, N, fs, 0, 'retangular');
[mnf_bar, mdf_bar]     = mnf_mdf(P_bar, fs, N);

[P_wel, f_wel, nt_wel] = espectro_medio(x, N, fs, sobrep, 'hamming');
[mnf_wel, mdf_wel]     = mnf_mdf(P_wel, fs, N);

% Bartlett direto da STFT da Atividade n. 01. Aquela funcao usa Hamming,
% entao isto e um Welch sem sobreposicao, nao um Bartlett estrito.
P_stft = mean(abs(meu_espectrograma(x, N, fs)).^2, 2);
[mnf_bs, mdf_bs] = mnf_mdf(P_stft, fs, N);

erro = @(vr, ve) 100*abs(vr-ve)/vr;

fprintf('\nTrechos: Bartlett = %d | Welch = %d\n\n', nt_bar, nt_wel);
fprintf('%-34s %10s %10s %11s %11s\n', 'Estimativa', 'MNF (Hz)', 'MDF (Hz)', 'Erro MNF %', 'Erro MDF %');
fprintf('%s\n', repmat('-', 1, 80));
fprintf('%-34s %10.2f %10.2f %11s %11s\n', 'Sinal completo (real)', mnf_real, mdf_real, '-', '-');
fprintf('%-34s %10.2f %10.2f %11.2f %11.2f\n', 'Bartlett (retangular)', ...
        mnf_bar, mdf_bar, erro(mnf_real,mnf_bar), erro(mdf_real,mdf_bar));
fprintf('%-34s %10.2f %10.2f %11.2f %11.2f\n', 'Welch (Hamming, 50%)', ...
        mnf_wel, mdf_wel, erro(mnf_real,mnf_wel), erro(mdf_real,mdf_wel));
fprintf('%-34s %10.2f %10.2f %11.2f %11.2f\n', 'Bartlett direto da STFT (At.01)', ...
        mnf_bs, mdf_bs, erro(mnf_real,mnf_bs), erro(mdf_real,mdf_bs));

% Figura 1: espectros normalizados pelo proprio maximo
figure('Name', nome);
plot(f_real, 10*log10(P_real/max(P_real) + eps), 'Color', [.8 .8 .8]); hold on;
plot(f_bar,  10*log10(P_bar /max(P_bar ) + eps), 'LineWidth', 1.4);
plot(f_wel,  10*log10(P_wel /max(P_wel ) + eps), 'LineWidth', 1.4);
xlabel('Frequencia (Hz)'); ylabel('Potencia normalizada (dB)');
title(['Estimativas espectrais - Sinal ', nome]);
legend('Sinal completo', 'Bartlett', 'Welch', 'Location', 'northeast');
xlim([0 fs/2]); grid on;
yl = ylim;
plot([mnf_real mnf_real], yl, '--k', 'HandleVisibility', 'off');
plot([mdf_real mdf_real], yl, ':k',  'HandleVisibility', 'off');
text(mnf_real, yl(2)-3, ' MNF real', 'FontSize', 8);
text(mdf_real, yl(1)+3, ' MDF real', 'FontSize', 8);

% Figura 2: erros percentuais
figure('Name', ['Erros - ', nome]);
bar([erro(mnf_real,mnf_bar) erro(mdf_real,mdf_bar); ...
     erro(mnf_real,mnf_wel) erro(mdf_real,mdf_wel)]);
set(gca, 'XTickLabel', {'Bartlett','Welch'});
ylabel('Erro percentual (%)');
title(['Erro das estimativas - Sinal ', nome]);
legend('MNF','MDF','Location','northeast'); grid on;
end
