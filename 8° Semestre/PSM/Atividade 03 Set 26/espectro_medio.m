function [P_medio, f, n_trechos] = espectro_medio(x, N, fs, sobrep, tipo_janela)
% Estimativa espectral media via STFT: media das colunas do espectrograma
% de potencia. sobrep = 0 e janela retangular  -> Bartlett.
%                sobrep = 0.5 e janela Hamming -> Welch.

if nargin < 4 || isempty(sobrep),      sobrep = 0;              end
if nargin < 5 || isempty(tipo_janela), tipo_janela = 'hamming'; end
x = x(:);
if mod(N,2) ~= 0, N = N - 1; end

n = (0:N-1)';
switch lower(tipo_janela)
    case 'retangular', w = ones(N,1);
    case 'hamming',    w = 0.54 - 0.46*cos(2*pi*n/(N-1));
    case 'hann',       w = 0.50 - 0.50*cos(2*pi*n/(N-1));
    otherwise, error('Janela desconhecida: %s', tipo_janela);
end
U = sum(w.^2);   % normaliza a energia da janela; nao altera MNF/MDF

passo   = max(1, round(N*(1-sobrep)));
inicios = 1 : passo : (length(x) - N + 1);
n_trechos = numel(inicios);
if n_trechos < 1, error('Sinal mais curto que um trecho.'); end

P_medio = zeros(N/2, 1);
for i = 1:n_trechos
    trecho  = x(inicios(i) : inicios(i)+N-1) .* w;
    Xc      = fft(trecho);
    P_medio = P_medio + (abs(Xc(1:N/2)).^2) / U;
end
P_medio = P_medio / n_trechos;
f = (0:(N/2 - 1))' * (fs / N);
end
