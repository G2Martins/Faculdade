# Questionário — Compiladores e Interpretadores (gabarito comentado)

## 1) A fase de análise sintática verifica:

**✅ Se os tokens formam frases válidas na linguagem**

Fase 2 da tradução: recebe os tokens da léxica e monta a árvore da estrutura (AST — Árvore Sintática Abstrata), validando se a sequência obedece à gramática da linguagem.

## 2) Na fase de codificação ou geração de código, o compilador:

**✅ Cria o código de máquina ou intermediário**

Fase 4 (final) da tradução: escreve o arquivo de saída — código objeto, intermediário ou de máquina. Não executa nada.

## 3) A fase de análise semântica garante:

**✅ Que as operações fazem sentido na linguagem**

Fase 3 (opcional): valida regras e variáveis — tipos compatíveis, variável declarada antes do uso, operação permitida. Sintaticamente correto ≠ semanticamente válido.

## 4) O pipeline de tradução é:

**✅ Um conjunto de fases que traduzem código fonte até código executável**

Léxica → Sintática → Semântica → Codificação (tradução), depois Ligação e Montagem até linguagem de máquina.

## 5) Um interpretador é:

**✅ Um programa que executa o código linha por linha**

O "tradutor simultâneo": lê, traduz e executa cada linha na hora. Começa imediatamente, mas re-traduz linhas repetidas (laço de mil repetições = mil traduções).

## 6) A fase de análise léxica tem como função:

**✅ Converter código em tokens**

Fase 1, o "leitor": transforma o texto do código-fonte em tokens (palavras reservadas, identificadores, números, símbolos).

## 7) Um compilador é:

**✅ Um programa que traduz código fonte para linguagem de máquina antes da execução**

O "tradutor do livro": traduz tudo de uma vez e gera um novo artefato (executável). Execução depois é rápida e independente do compilador.

## 8) A diferença principal entre compilação e interpretação é:

**✅ Compilação traduz antes da execução, interpretação traduz durante a execução**

Diferença central. Compilação: etapa prévia obrigatória, execução rápida. Interpretação: início imediato, tradução repetida em laços.

---

## Resumo rápido

| # | Resposta |
|---|---|
| 1 | Tokens formam frases válidas |
| 2 | Cria código de máquina/intermediário |
| 3 | Operações fazem sentido |
| 4 | Conjunto de fases fonte→executável |
| 5 | Executa linha por linha |
| 6 | Converte código em tokens |
| 7 | Traduz antes da execução |
| 8 | Compila antes / interpreta durante |
