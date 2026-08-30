function [X, f_pico] = meu_espectrograma(x, duracao_trecho, fs, usar_ms)
% MEU_ESPECTROGRAMA  Espectrograma via STFT com segmentacao sem sobreposicao.
%
%   [X, f_pico] = meu_espectrograma(x, duracao_trecho, fs, usar_ms)
%
%   Entradas:
%     x              - vetor com as amostras do sinal
%     duracao_trecho - duracao de cada trecho: em amostras (padrao) ou em ms
%                      (se usar_ms = true)
%     fs             - frequencia de amostragem, em Hz
%     usar_ms        - (opcional) true => duracao_trecho esta em ms
%
%   Saidas:
%     X      - matriz (N/2 x n_trechos) com |DFT| de cada trecho.
%              X(k,n) = amplitude do k-esimo harmonico no n-esimo trecho.
%     f_pico - vetor (1 x n_trechos) com a frequencia de pico, em Hz,
%              de cada trecho.
%
%   Algoritmo desenvolvido na Atividade de Laboratorio n. 01 (13/ago).

% --- 0) Tratamento de parametros ---
if nargin < 4
    usar_ms = false;
end
x = x(:);
if usar_ms
    N = round(duracao_trecho/1000 * fs);
else
    N = duracao_trecho;
end
if mod(N,2) ~= 0
    N = N - 1;
end

% --- 1) Segmentacao do sinal em trechos de N amostras ---
L_total   = length(x);
n_trechos = floor(L_total / N);
if n_trechos < 1
    error('Sinal mais curto que a duracao de um unico trecho.');
end

% --- 2) Alocacao das saidas ---
X      = zeros(N/2, n_trechos);
f_pico = zeros(1, n_trechos);
freqs  = (0:(N/2 - 1)) * (fs / N);
janela = hamming(N);

% --- 3) Loop: para cada trecho, calcula a DFT (via FFT) ---
for n = 1:n_trechos
    idx_inicio = (n-1)*N + 1;
    idx_fim    = idx_inicio + N - 1;
    trecho     = x(idx_inicio:idx_fim) .* janela;
    X_completo = fft(trecho);
    Xk         = abs(X_completo(1:N/2));
    X(:, n)    = Xk;

    % --- 4) Frequencia de pico do trecho ---
    [~, k_max] = max(Xk);
    f_pico(n)  = freqs(k_max);
end
end
