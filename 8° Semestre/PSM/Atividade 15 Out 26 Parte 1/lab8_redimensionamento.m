%% =====================================================================
%   IESB - Engenharia da Computacao
%   Processamento de Sinais Multimidia - Atividade de Laboratorio n. 08
%   Redimensionamento de imagens (compressao e dilatacao pelo fator 2)
%
%   1) Reduz cada imagem por 2, sucessivas vezes, ate 32x32 (comprime2)
%   2) Dilata cada versao reduzida por 2, sucessivas vezes, ate voltar ao
%      tamanho original (dilata2), com vizinho mais proximo e com
%      interpolacao linear
%   3) Calcula o erro quadratico relativo Er entre a original e cada versao
%      reconstruida e plota Er x fator de redimensionamento
%
%   Arquivos necessarios na mesma pasta (Current Folder do MATLAB):
%       comprime2.m, dilata2.m
%       img1_fotografia.png, img2_textura.png, img3_desenho.png
%   Saidas: figuras + pasta "resultados" com todas as versoes em PNG
%% =====================================================================
clear; close all; clc;

%% ---------------- Parametros ----------------------------------------
arquivos = {'img1_fotografia.png', 'img2_textura.png', 'img3_desenho.png'};
nomes    = {'Fotografia', 'Textura', 'Desenho'};
metodos  = {'vizinho', 'linear'};
lado_min = 32;                 % reduz ate 32x32 pixels
espaco   = 10;                 % separacao (px) na montagem da Figura 1
recorte  = {[51 161], [193 193], [271 221]};  % canto sup. esq. (Figura 3)
tam_rec  = 128;                % lado do recorte ampliado (px)
fat_rec  = [2 3];              % recorte para os fatores 2^2 = 4 e 2^3 = 8

pastaSaida = 'resultados';
if ~exist(pastaSaida, 'dir'), mkdir(pastaSaida); end

Er = cell(1, numel(arquivos)); % Er{k}(i, m): imagem k, fator 2^i, metodo m

%% ---------------- Processamento de cada imagem ----------------------
for k = 1:numel(arquivos)

    % --- Leitura, conversao para cinza e para reais em [0, 1]
    X = imread(arquivos{k});
    if size(X, 3) == 3
        X = rgb2gray(X);
    end
    X = im2double(X);

    % --- Numero de reducoes ate o lado minimo (512 -> 32: 4 reducoes) e
    %     recorte para multiplo de 2^n_red (em imagens 512x512 nada muda)
    n_red = floor(log2(min(size(X)) / lado_min));
    p = 2^n_red;
    X = X(1:p*floor(end/p), 1:p*floor(end/p));
    [L, C] = size(X);

    % --- Caso de controle: dilatar e depois comprimir deve devolver
    %     exatamente a imagem (amostras originais ficam nas posicoes impares)
    assert(isequal(comprime2(dilata2(X, 'vizinho')), X) && ...
           isequal(comprime2(dilata2(X, 'linear')), X), ...
           'Caso de controle falhou: comprime2(dilata2(X)) ~= X');

    % --- 1) Reducoes sucessivas: red{1} = original, red{i+1} = red{i}/2
    red = cell(1, n_red + 1);
    red{1} = X;
    for i = 1:n_red
        red{i+1} = comprime2(red{i});
        [l, w] = size(red{i+1});
        arq = sprintf('img%d_reduzida_%dx%d.png', k, l, w);
        imwrite(red{i+1}, fullfile(pastaSaida, arq));
    end

    % --- 2) Dilatacoes sucessivas ate o tamanho original + 3) erro
    rec   = cell(numel(metodos), n_red);
    Er{k} = zeros(n_red, numel(metodos));
    for m = 1:numel(metodos)
        for i = 1:n_red
            Y = red{i+1};
            for j = 1:i                      % fator 2^i -> i dilatacoes
                Y = dilata2(Y, metodos{m});
            end
            rec{m, i} = Y;
            Er{k}(i, m) = sum((X(:) - Y(:)).^2) / sum(X(:).^2);
            imwrite(Y, fullfile(pastaSaida, sprintf('img%d_fator%02d_%s.png', ...
                    k, 2^i, metodos{m})));
        end
    end

    % --- Figura 1: original e versoes reduzidas, lado a lado, em escala
    %     real (alinhadas pela base, como na Figura 1 do roteiro)
    larg   = sum(cellfun(@(r) size(r, 2), red)) + espaco*n_red;
    canvas = ones(L, larg);
    c = 1;
    for i = 1:n_red + 1
        [l, w] = size(red{i});
        canvas(L-l+1:L, c:c+w-1) = red{i};
        c = c + w + espaco;
    end
    figure('Name', sprintf('%s - reducoes', nomes{k}), 'NumberTitle', 'off');
    imshow(canvas);
    title(sprintf('%s: original (%dx%d) e versoes reduzidas ate %dx%d', ...
          nomes{k}, L, C, size(red{end}, 1), size(red{end}, 2)));

    % --- Figura 2: versoes reconstruidas (linha 1: vizinho; linha 2: linear)
    figure('Name', sprintf('%s - reconstrucoes', nomes{k}), 'NumberTitle', 'off');
    for m = 1:numel(metodos)
        for i = 1:n_red
            subplot(numel(metodos), n_red, (m-1)*n_red + i);
            imshow(rec{m, i});
            title(sprintf('%s, fator %d (Er = %.4f)', metodos{m}, 2^i, ...
                          Er{k}(i, m)));
        end
    end

    % --- Figura 3: recorte ampliado (mesma regiao em todas as versoes)
    li = recorte{k}(1) + (0:tam_rec-1);
    co = recorte{k}(2) + (0:tam_rec-1);
    figure('Name', sprintf('%s - recorte', nomes{k}), 'NumberTitle', 'off');
    subplot(1, 1 + numel(metodos)*numel(fat_rec), 1);
    imshow(X(li, co));
    title('Original');
    q = 2;
    for i = fat_rec
        for m = 1:numel(metodos)
            subplot(1, 1 + numel(metodos)*numel(fat_rec), q);
            imshow(rec{m, i}(li, co));
            title(sprintf('%s, fator %d', metodos{m}, 2^i));
            q = q + 1;
        end
    end

    % --- Tabela no Command Window
    fprintf('\n=== Imagem %d (%s) - %dx%d px ===\n', k, nomes{k}, L, C);
    fprintf('%8s %16s %16s\n', 'Fator', 'Er (vizinho)', 'Er (linear)');
    fprintf('%8d %16.5f %16.5f\n', [2.^(1:n_red); Er{k}']);
end

%% ---------------- Grafico Er x fator de redimensionamento -----------
figure('Name', 'Er x fator', 'NumberTitle', 'off');
cores   = lines(numel(arquivos));
estilos = {'-o', '--s'};
hold on;
for k = 1:numel(arquivos)
    fatores = 2.^(1:size(Er{k}, 1));
    for m = 1:numel(metodos)
        plot(fatores, Er{k}(:, m), estilos{m}, 'Color', cores(k, :), ...
             'LineWidth', 1.5, ...
             'DisplayName', sprintf('%s (%s)', nomes{k}, metodos{m}));
    end
end
hold off;
set(gca, 'XScale', 'log', 'XTick', fatores);
xlabel('Fator de redimensionamento (reducao e posterior dilatacao)');
ylabel('Erro quadratico relativo E_r');
title('Erro quadratico relativo x fator de redimensionamento');
legend('Location', 'northwest');
grid on;

fprintf('\nImagens salvas na pasta "%s".\n', pastaSaida);
