# Problema G - Gabarito

* **Limite de tempo:** 1s

## Descrição do Problema

Patrícia resolveu fazer uma prova de múltipla escolha. [cite_start]Cada questão possui cinco alternativas, de "A" a "E" e resolveu aplicá-la em sua turma de Cálculo. [cite: 174] [cite_start]Para poder se concentrar na organização da Maratona Fraldinha IESB 2023, ela pediu que a sua monitora, Ofélia, fizesse a correção das avaliações, dado um gabarito. [cite: 175] [cite_start]Ofélia, por sua vez, ao notar que era uma tarefa puramente mecânica, pediu sua ajuda para escrever um corretor automatizado das provas que calcule a nota final do estudante, de acordo com o gabarito. [cite: 176]

## Entrada

[cite_start]A entrada possui um inteiro $n$, que indica o número de questões. [cite: 178] A segunda linha da entrada, possui $n$ caracteres, de "A" a "E", separados por um espaço, indicando a escolha do estudante para cada questão. [cite_start]A terceira e última linha da entrada, possui $n$ caracteres, "A" a "E", separados por um espaço, indicando a opção correta para cada questão. [cite: 179]

**Restrições:**
* [cite_start]$1 \le n \le 10^5$ [cite: 181]

## Saída

[cite_start]Imprima a nota do estudante, de 0 a 100. [cite: 183] [cite_start]Se sua resposta for x e a resposta do juiz for y, ela será considerada correta $|x-y|\le10^{-2}.$ [cite: 183]

## Exemplo

| Entrada      | Saída          |
| :----------- | :------------- |
| [cite_start]3 [cite: 185]        | [cite_start]33.3333333333 [cite: 185] |
| [cite_start]ADC [cite: 185]      |                |
| [cite_start]ABD [cite: 185]      |                |
| [cite_start]5 [cite: 185]        | [cite_start]0.0000000000 [cite: 185] |
| [cite_start]AAAAA [cite: 185]    |                |
| [cite_start]CEBDB [cite: 185]    |                |
| [cite_start]5 [cite: 185]        | [cite_start]100.0000000000 [cite: 185] |
| [cite_start]CEADB [cite: 185]    |                |
| [cite_start]CEADB [cite: 185]    |                |