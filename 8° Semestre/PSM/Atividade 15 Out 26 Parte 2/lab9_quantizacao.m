%% =====================================================================
%   IESB - Engenharia da Computacao
%   Processamento de Sinais Multimidia - Atividade de Laboratorio n. 09
%   Quantizacao de imagens em N niveis de cinza
%
%   1) Quantiza cada imagem em alguns valores de N e exibe as versoes
%      (quantiza.m)
%   2) Calcula o erro relativo para 2 <= N <= 256 e plota Erelat x N
%      (curva_quantizacao.m)
%   3) Compara as tres imagens entre si e com a previsao teorica do erro
%      de quantizacao uniforme: E_teo(N) = (D^2/12) / media(X^2), D = 1/(N-1)
%
%   Arquivos necessarios na mesma pasta (Current Folder do MATLAB):
%       quantiza.m, curva_quantizacao.m
%       img1_fotografia.png, img2_textura.png, img3_desenho.png
%   Saidas: figuras + pasta "resultados" com as versoes quantizadas em PNG
%% =====================================================================
clear; close all; clc;

%% ---------------- Parametros ----------------------------------------
arquivos = {'img1_fotografia.png', 'img2_textura.png', 'img3_desenho.png'};
nomes    = {'Fotografia', 'Textura', 'Desenho'};
Nmostra  = [256 64 32 16 8 5 3 2];       % versoes exibidas (Figura 1)
Ntabela  = [2 3 4 5 8 16 32 64 128 255 256];

pastaSaida = 'resultados';
if ~exist(pastaSaida, 'dir'), mkdir(pastaSaida); end

%% ---------------- Casos de controle ---------------------------------
% (a) rampa de 0 a 1 quantizada com N = 5 deve conter so 0, .25, .5, .75, 1
rampa = repmat(linspace(0, 1, 256), 16, 1);
assert(isequal(unique(quantiza(rampa, 5))', [0 0.25 0.5 0.75 1]), ...
       'Controle (a) falhou: niveis de N = 5 incorretos');

E   = cell(1, numel(arquivos));
Pot = zeros(1, numel(arquivos));          % media(X^2) de cada imagem

%% ---------------- Processamento de cada imagem ----------------------
for k = 1:numel(arquivos)

    % --- Leitura, conversao para cinza e para reais em [0, 1]
    X = imread(arquivos{k});
    if size(X, 3) == 3
        X = rgb2gray(X);
    end
    X = im2double(X);
    Pot(k) = mean(X(:).^2);

    % (b) imagem de 8 bits com N = 256 niveis deve voltar identica
    assert(isequal(quantiza(X, 256), X), ...
           'Controle (b) falhou: N = 256 alterou a imagem');

    % --- Figura 1: versoes quantizadas (2 x 4, como no roteiro)
    figure('Name', sprintf('%s - quantizacao', nomes{k}), 'NumberTitle', 'off');
    for i = 1:numel(Nmostra)
        [Y, Ei] = quantiza(X, Nmostra(i));
        subplot(2, 4, i);
        imshow(Y);
        title(sprintf('N = %d  (E = %.1e)', Nmostra(i), Ei));
        imwrite(Y, fullfile(pastaSaida, sprintf('img%d_N%03d.png', k, Nmostra(i))));
    end

    % --- Figura 2: curva Erelat x N (rotina pedida no enunciado)
    [E{k}, Nvet] = curva_quantizacao(X, nomes{k});

    % --- Tabela no Command Window
    fprintf('\n=== Imagem %d (%s) - %d niveis distintos na original ===\n', ...
            k, nomes{k}, numel(unique(X)));
    fprintf('%6s %14s %14s\n', 'N', 'Erelat', 'E_teorico');
    for N = Ntabela
        Eteo = (1/(N-1))^2 / 12 / Pot(k);
        fprintf('%6d %14.3e %14.3e\n', N, E{k}(Nvet == N), Eteo);
    end
end

%% ---------------- Comparacao entre imagens e com a teoria -----------
% Escala log-log: o erro teorico vira uma reta de inclinacao -2
figure('Name', 'Erelat x N - comparacao', 'NumberTitle', 'off');
cores = lines(numel(arquivos));
for k = 1:numel(arquivos)
    loglog(Nvet, E{k}, '-', 'Color', cores(k, :), 'LineWidth', 1.5, ...
           'DisplayName', nomes{k});
    hold on;
    loglog(Nvet, (1./(Nvet-1)).^2 / 12 / Pot(k), ':', 'Color', cores(k, :), ...
           'LineWidth', 1.2, 'DisplayName', [nomes{k} ' (teorico)']);
end
hold off;
grid on;
xlim([2 256]);
xlabel('Quantidade de niveis de cinza N');
ylabel('Erro relativo E_{relat}');
title('Erro relativo x N: medido (continuo) e teorico \Delta^2/12 (pontilhado)');
legend('Location', 'southwest');

fprintf('\nImagens salvas na pasta "%s".\n', pastaSaida);
