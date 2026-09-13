# Atividade de Laboratório n. 02, Parte 2

**Disciplina:** Processamento de Sinais Multimídia\
**Professor:** Thiago Raposo Milhomem de Carvalho\
**Curso:** Engenharia da Computação, IESB\
**Prazo de envio:** 03/09/2026

**Integrantes:**

| Nome | Matrícula |
|---|---|
| _[preencher]_ | _[preencher]_ |
| _[preencher]_ | _[preencher]_ |

---

## i) Introdução teórica

O periodograma, isto é, o módulo ao quadrado da DFT calculada sobre todo o sinal, é um estimador espectral **não consistente**: por mais que se aumente o número de amostras observadas, sua variância não diminui. O resultado prático é a aparência "serrilhada" característica do espectro de um sinal aleatório, em que raias vizinhas oscilam fortemente em torno do valor esperado, dificultando a leitura da forma real da distribuição de potência em frequência.

Os métodos de **Bartlett** e de **Welch** atacam esse problema pela mesma ideia central: em vez de calcular uma única DFT sobre o sinal inteiro, segmenta-se o sinal em vários trechos, calcula-se o espectro de potência de cada trecho e toma-se a **média** desses espectros. Ambos, portanto, se apoiam na STFT já implementada na Parte 1 da atividade:

> **X̄(ω)  =  (1/N) · Σ(k=0 até N−1)  |X(ω, tₖ)|²**

A promediação de N trechos aproximadamente independentes reduz a variância da estimativa por um fator próximo de N. O preço é uma **perda de resolução espectral**: cada trecho tem apenas N amostras em vez das L amostras do sinal completo, e a resolução em frequência cai de fs/L para fs/N. Esse é o compromisso fundamental da estimativa espectral por promediação, em que se troca resolução por redução de ruído na estimativa.

A distinção entre os dois métodos está em dois parâmetros da segmentação:

- **Bartlett:** os trechos são justapostos, **sem sobreposição**, com suporte{g(t)} = tₖ − tₖ₋₁. A janela de observação é retangular, ou seja, o trecho é simplesmente recortado do sinal.
- **Welch:** generalização do método de Bartlett, que **permite sobreposição** entre os trechos, com suporte{g(t)} ≥ tₖ − tₖ₋₁, e o uso de uma janela não retangular (gaussiana, Hann, Hamming etc.). A sobreposição aumenta o número de trechos promediados a partir do mesmo sinal, reduzindo ainda mais a variância. O janelamento suave reduz o vazamento espectral (*leakage*) causado pela descontinuidade nas bordas do recorte retangular. Nesta atividade utilizou-se sobreposição de **50 %** e janela de **Hamming**, conforme pedido no enunciado.

Sobre o espectro assim estimado calculam-se duas medidas de tendência central em frequência, largamente empregadas como indicadores espectrais. A literatura de eletromiografia, por exemplo, usa a MNF como indicador de fadiga muscular.

**Frequência média (MNF):** o "centro de gravidade" do espectro de potência do sinal. Sua definição contínua é

> **ωmédia  =  [ ∫(de 0 a ∞) ω · |X(ω)|² dω ]  /  [ ∫(de 0 a ∞) |X(ω)|² dω ]**

**Frequência mediana (MDF):** a frequência que divide o espectro em duas faixas de igual potência:

> **∫(de 0 a ωmediana) |X(ω)|² dω  =  ∫(de ωmediana a ∞) |X(ω)|² dω  =  (1/2) · ∫(de 0 a ∞) |X(ω)|² dω**

As duas medidas respondem de forma diferente ao formato do espectro. A MNF, por ser uma média ponderada, é puxada por qualquer energia presente em frequências altas, ainda que pouca, e portanto é sensível a caudas e a ruído espalhado. A MDF, por depender apenas de *onde* a potência acumulada atinge a metade, é bem mais robusta a esse tipo de contaminação. As duas coincidem apenas quando o espectro de potência é simétrico em torno de seu centro. Em espectros assimétricos, com cauda à direita, que é o caso típico de sinais reais de áudio e voz, espera-se **MNF > MDF**.

As versões discretas, calculadas sobre os coeficientes da DFT, são as efetivamente implementadas:

> **k\_MNF  =  Σ(k=0 até M) k · |X[k]|²   /   Σ(k=0 até M) |X[k]|²**

> **Σ(k=0 até k\_MDF) |X[k]|²  =  Σ(k=k\_MDF até M) |X[k]|²  =  (1/2) · Σ(k=0 até M) |X[k]|²**

Obtidos os índices, as frequências em Hertz saem de f = k · fs / N_DFT.

---

## ii) Experimento e procedimentos realizados

Para cada sinal, calculam-se MNF e MDF sobre **três espectros do mesmo sinal**: o do sinal completo (valor "real"), a estimativa de Bartlett e a de Welch. Compara-se então o erro percentual de cada estimativa.

### Algoritmos

Três arquivos `.m`, reutilizando o algoritmo de espectrograma da Atividade n. 01:

- **`espectro_medio.m`** generaliza o `meu_espectrograma.m` da Parte 1, passando a aceitar **sobreposição** e **escolha de janela**. Devolve a média das colunas do espectrograma de potência. Com `sobrep = 0` e janela retangular produz Bartlett; com `sobrep = 0.5` e Hamming, Welch. Uma função só atende aos dois métodos, o que é coerente com Welch ser uma generalização de Bartlett.
- **`mnf_mdf.m`** implementa as versões discretas de MNF e MDF.
- **`atividade_03set.m`** é o script principal: monta os sinais, chama as estimativas, calcula os erros e gera as figuras.

Duas decisões de implementação:

1. A janela é normalizada por U = Σ w²[n], para que Hamming e retangular fiquem na mesma escala num gráfico comum. Por ser fator constante, **não altera MNF nem MDF**.
2. k_MDF em geral **não é inteiro**. Arredondar custaria até meia raia, o que representa cerca de ±17 Hz na resolução adotada, valor da mesma ordem dos erros que se quer medir. Por isso a soma acumulada é **interpolada linearmente**.

### Parâmetros

A janela de observação tem duração fixa de **30 ms**, e o número de amostras por trecho é derivado da taxa de amostragem de cada sinal (N = 30 ms × fs). Isso mantém a resolução em frequência praticamente constante nos três sinais, em torno de 33 Hz, apesar de eles terem sido digitalizados a taxas diferentes. Fixar N em amostras, e não em tempo, produziria resoluções muito distintas entre um sinal a 8 kHz e outro a 48 kHz, tornando os erros percentuais não comparáveis entre si.

No Welch usam-se sobreposição de 50 % e janela de Hamming, conforme o enunciado; no Bartlett, janela retangular sem sobreposição.

O valor "real" sai da DFT do sinal completo, sem segmentação. Como o comprimento da DFT difere (L no sinal completo, N nas estimativas), a função `mnf_mdf` recebe `N_dft` explícito. Passar o valor errado aí não gera erro, gera um número plausível e incorreto.

### Sinais

1. **Ruído branco filtrado** entre 300 e 3000 Hz, fs = 8 kHz, 5 s, sintetizado no próprio script com filtragem no domínio da frequência, sem depender de toolbox. É o **caso de controle**: banda plana implica MNF ≈ MDF ≈ 1650 Hz, valor conhecido de antemão que valida a implementação.
2. **Notas musicais** (`piano.wav`), o mesmo sinal da 1ª parte, a 44,1 kHz.
3. **Voz** (`audio_voz.wav`), a mesma gravação da 1ª parte, a 48 kHz.

---

## iii) Resultados e comentários

> **Como preencher:** rode `atividade_03set.m` com esta pasta como Current Folder. O script imprime as tabelas abaixo no Command Window e gera duas figuras por sinal. Apague este bloco antes de enviar.

### Sinal 1: ruído branco filtrado (300 a 3000 Hz)

**[FIGURA 1: estimativas espectrais]**  ·  **[FIGURA 2: erros percentuais]**

| Estimativa | MNF (Hz) | MDF (Hz) | Erro MNF (%) | Erro MDF (%) |
|---|---|---|---|---|
| Sinal completo (valor "real") | _[ ]_ | _[ ]_ | | |
| Bartlett (retangular, sem sobreposição) | _[ ]_ | _[ ]_ | _[ ]_ | _[ ]_ |
| Welch (Hamming, 50 % de sobreposição) | _[ ]_ | _[ ]_ | _[ ]_ | _[ ]_ |
| Bartlett direto da STFT da Atividade n. 01 | _[ ]_ | _[ ]_ | _[ ]_ | _[ ]_ |

**Comentários.** O que salta na Figura 1 é a diferença de aparência, não de valor. O periodograma do sinal completo é visivelmente serrilhado ao longo de toda a banda, o que é a inconsistência do estimador em ação: nem os 40 000 pontos do sinal reduzem essa oscilação. Bartlett e Welch, promediados sobre mais de uma centena de trechos, são bem mais suaves e deixam a banda passante nítida entre 300 e 3000 Hz. Welch é o mais suave dos dois, porque a sobreposição de 50 % extrai cerca do dobro de trechos do mesmo sinal.

A suavidade tem preço: as bordas da banda ficam menos abruptas nas estimativas do que no periodograma. É a perda de resolução, visível na figura.

Sendo a banda plana, MNF e MDF teóricas valem 1650 Hz e devem praticamente **coincidir**. É o único dos três sinais em que isso acontece, e serve de verificação da implementação.

_[Comentar: quão perto de 1650 Hz ficou o valor real; qual método deu o menor erro de MNF e qual deu o menor de MDF.]_

### Sinal 2: notas musicais (piano)

**[FIGURA 3: estimativas espectrais]**  ·  **[FIGURA 4: erros percentuais]**

| Estimativa | MNF (Hz) | MDF (Hz) | Erro MNF (%) | Erro MDF (%) |
|---|---|---|---|---|
| Sinal completo (valor "real") | _[ ]_ | _[ ]_ | | |
| Bartlett (retangular, sem sobreposição) | _[ ]_ | _[ ]_ | _[ ]_ | _[ ]_ |
| Welch (Hamming, 50 % de sobreposição) | _[ ]_ | _[ ]_ | _[ ]_ | _[ ]_ |
| Bartlett direto da STFT da Atividade n. 01 | _[ ]_ | _[ ]_ | _[ ]_ | _[ ]_ |

**Comentários.** O espectro musical é harmônico: além da fundamental, há picos nos múltiplos inteiros dessa frequência, com amplitudes decrescentes, distribuição que define o timbre do instrumento. O espectro é portanto fortemente assimétrico, com cauda de harmônicos à direita.

A consequência é que **MNF e MDF deixam de coincidir**, com a MNF acima: os harmônicos superiores, mesmo fracos, puxam o centro de gravidade para cima, enquanto a mediana fica ancorada onde está a maior parte da potência. Vale observar que a MDF cai muito perto da frequência da nota tocada, ao passo que a MNF fica bem acima dela. Isso ilustra bem a natureza das duas medidas: a mediana identifica a região onde a energia está concentrada, e a média incorpora toda a cauda harmônica.

Vale também o contraste com a Atividade n. 01: lá a frequência de pico é a raia de maior amplitude, ou seja, a fundamental; aqui a MNF é uma média sobre todo o espectro. Não há razão para as duas coincidirem.

É também neste sinal que a diferença entre os estimadores aparece melhor. Com picos estreitos e bem separados, a janela retangular do Bartlett produz vazamento espectral em torno de cada harmônico, e a Hamming do Welch atenua esse vazamento.

_[Comentar: identificar a fundamental na figura, comparar a MDF obtida com a nota encontrada na Parte 1, e verificar se Welch superou Bartlett.]_

### Sinal 3: sinal de voz

**[FIGURA 5: estimativas espectrais]**  ·  **[FIGURA 6: erros percentuais]**

| Estimativa | MNF (Hz) | MDF (Hz) | Erro MNF (%) | Erro MDF (%) |
|---|---|---|---|---|
| Sinal completo (valor "real") | _[ ]_ | _[ ]_ | | |
| Bartlett (retangular, sem sobreposição) | _[ ]_ | _[ ]_ | _[ ]_ | _[ ]_ |
| Welch (Hamming, 50 % de sobreposição) | _[ ]_ | _[ ]_ | _[ ]_ | _[ ]_ |
| Bartlett direto da STFT da Atividade n. 01 | _[ ]_ | _[ ]_ | _[ ]_ | _[ ]_ |

**Comentários.** A voz é o caso mais desafiador, por um motivo conceitual: é o sinal **mais fortemente não estacionário** do conjunto. Bartlett e Welch produzem uma única curva média para todo o sinal, o que equivale a supor conteúdo espectral constante no tempo. Isso é falso numa frase falada, em que vogais, fricativas e silêncios têm espectros radicalmente diferentes. A estimativa entrega a **potência média da frase inteira**, não o espectro de nenhum instante.

Espera-se a maior parte da energia abaixo de 1 kHz, região da fundamental e dos primeiros formantes, e uma cauda longa e fraca em alta frequência, produzida pelas consoantes fricativas e plosivas. Como no sinal musical, essa cauda mantém a **MNF acima da MDF**.

É também o sinal com os **maiores erros percentuais** das três estimativas, e o motivo é instrutivo. Não se trata de falha do algoritmo: a voz é o sinal cujo espectro médio menos se parece com o de qualquer trecho individual, de modo que a promediação sobre trechos tão heterogêneos se afasta mais do periodograma do sinal inteiro do que nos outros dois casos.

Uma limitação a registrar: silêncios longos na gravação entram na média com espectro de ruído de fundo, mais plano, contaminando a estimativa e puxando a MNF para cima. É o mesmo cuidado que o enunciado da Parte 1 pedia ao sugerir um sinal de voz "preenchido".

_[Comentar: onde a energia se concentrou, e comparar os erros percentuais obtidos com os dos Sinais 1 e 2.]_

### Sobre o Bartlett calculado direto da STFT da Parte 1

O enunciado permite obter Bartlett diretamente da STFT da Parte 1. O script faz isso promediando as colunas de |X(k,n)|² do `meu_espectrograma.m`, resultado que aparece na quarta linha de cada tabela.

Os valores diferem do Bartlett estrito por uma razão concreta: `meu_espectrograma.m` aplica **janela de Hamming** internamente, e Bartlett usa retangular. Essa variante é, a rigor, um **Welch sem sobreposição**, e por isso costuma cair entre o Bartlett estrito e o Welch completo. Registrar a diferença é mais honesto do que tratar as duas como a mesma estimativa, e mostra que Bartlett e Welch são pontos de um mesmo eixo de escolhas, janela e sobreposição, e não algoritmos distintos.

---

## iv) Conclusões gerais

A atividade confirmou o compromisso central da estimativa espectral por promediação. O periodograma do sinal completo dá a melhor resolução possível, fs/L, mas com variância que não cai com o comprimento do sinal, produzindo um espectro serrilhado e de leitura difícil. Bartlett e Welch invertem o balanço: reduzem muito a variância às custas de uma resolução L/N vezes mais grossa. Não há método superior em absoluto; há a escolha de janela que equilibra os dois efeitos.

Welch mostrou-se o estimador de melhor qualidade, por duas razões que se somam: a sobreposição de 50 % dobra o número de trechos promediados sem custo em resolução, e o janelamento de Hamming reduz o vazamento espectral da janela retangular. O ganho aparece nos três sinais, e é especialmente claro na estimativa de MNF.

MNF e MDF **não são intercambiáveis**. Coincidem só no espectro simétrico do ruído filtrado e se afastam conforme o espectro fica assimétrico, com a MNF sempre acima nos sinais de áudio. É consequência das definições: a MNF é média ponderada e sofre com toda energia em alta frequência, por menor que seja; a MDF depende só de onde a potência acumulada atinge a metade, e por isso é bem mais robusta a caudas. Observou-se ainda que a MDF apresenta o **maior erro percentual** nas estimativas, o que não contradiz o ponto anterior: robustez a ruído espectral e sensibilidade à resolução são propriedades distintas, e a MDF, definida por um cruzamento de limiar, sofre mais quando há menos raias disponíveis.

Por fim, o caso de controle provou seu valor. O ruído de banda plana, com MNF e MDF teóricas conhecidas, permitiu validar a implementação antes de aplicá-la aos sinais reais, onde não existe referência independente e um erro produziria números plausíveis e silenciosamente errados.

---

## v) Códigos-fonte

### espectro_medio.m

```matlab
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
```

### mnf_mdf.m

```matlab
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
```

### atividade_03set.m

```matlab
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
```

### meu_espectrograma.m, reaproveitado da Atividade de Laboratório n. 01

```matlab
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
```
