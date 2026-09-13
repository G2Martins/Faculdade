function [mnf, mdf] = mnf_mdf(P, fs, N_dft)
% Frequencia media e mediana, versoes discretas (material de aula):
%   k_MNF = SOMA k|X[k]|^2 / SOMA |X[k]|^2
%   SOMA ate k_MDF |X[k]|^2 = metade da potencia total
% N_dft = comprimento da DFT que gerou P (N nas estimativas, L no sinal completo).

P = P(:);
k = (0:length(P)-1)';
total = sum(P);
if total <= 0, error('Espectro de potencia nulo.'); end

k_mnf = sum(k .* P) / total;

% k_MDF nao e inteiro: interpola em vez de arredondar
alvo = total/2;
acum = cumsum(P);
i2 = find(acum >= alvo, 1, 'first');
if i2 == 1
    k_mdf = 0;
else
    k_mdf = (i2-2) + (alvo - acum(i2-1)) / (acum(i2) - acum(i2-1));
end

mnf = k_mnf * fs / N_dft;
mdf = k_mdf * fs / N_dft;
end
