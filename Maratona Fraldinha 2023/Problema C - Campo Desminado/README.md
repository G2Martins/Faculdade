# Problema C - Campo Desminado

* **Limite de tempo:** 1s

## Descrição do Problema

[cite_start]As tropas da Nlogônia estão se preparando para mais uma batalha contra as tropas da Quadradônia. [cite: 42] [cite_start]Ao chegarem em uma área para fixar uma base militar, o general Visconde utilizou um aparelho de alta tecnologia para verificar a existência de minas terrestres. [cite: 43] [cite_start]O aparelho retornou um mapa retangular $N \times M$ nas dimensões da referida área, em que a posição (1, 1) é o canto esquerdo inferior e o (N, M) é o canto direito superior. [cite: 44] [cite_start]No mapa obtido, é possível visualizar as posições contendo minas terrestres e aquelas posições consideradas seguras. [cite: 45]

[cite_start]No arsenal das tropas, um subordinado verificou que existem K detonadores de minas terrestres. [cite: 46] [cite_start]Para ocuparem o terreno em segurança, o general Visconde ordena a detonação de K minas na área, que é percorrida de acordo com o mapa, começando pela posição (1, 1). [cite: 47] [cite_start]O percorrimento é então feito linha a linha, em que para cada linha, percorrem-se todas as posições da esquerda para a direita. [cite: 48] [cite_start]Claro, uma mina terrestre é sempre detonada durante o percurso caso exista um detonador disponível. [cite: 49]

[cite_start]Após esse serviço pesado, o general Visconde gostaria de saber como ficou o mapa de minas, mas também com informações adicionais sobre a existência de minas na vizinhança em relação a cada posição do mapa. [cite: 50] [cite_start]São consideradas posições vizinhas aquelas que fazem fronteira com uma posição (i, j) na vertical, na horizontal e na diagonal. [cite: 51]

## Entrada

[cite_start]A primeira linha da entrada descreve os três inteiros N, M e K ($1 \le N, M \le 1000$, $0 \le K \le NM$), separados por um espaço em branco. [cite: 53] [cite_start]As próximas N linhas descrevem o mapa de minas terrestres, em que cada linha contém exatamente M caracteres ($1 \le N, M \le 100$). [cite: 54] [cite_start]A posição dada pela i-ésima linha e a j-ésima coluna pode ser "*", indicando a existência de uma mina terrestre, ou "." indicando terreno seguro. [cite: 55, 56]

## Saída

[cite_start]Imprima N linhas, cada uma contendo M inteiros separados por espaço em branco, descrevendo o mapa (N, M) após a retirada de K minas terrestres. [cite: 58] [cite_start]Para cada posição i, j do mapa, imprima "-1" no caso de permanência de uma mina na área, ou o inteiro $x_{i,j}$ indicando a quantidade de minas nas 9 posições vizinhas. [cite: 59]

## Exemplo

| Entrada           | Saída     |
| :---------------- | :-------- |
| 3 3 1             | [cite_start]0 0 0 [cite: 62] |
| .*.               | [cite_start]0 1 1 [cite: 62] |
| ..* | [cite_start]0 1 * [cite: 62] |
| *..               |           |
| 3 4 2             | [cite_start]0 0 0 0 [cite: 62] |
| **** | [cite_start]0 0 1 1 [cite: 62] |
| **** | [cite_start]2 2 2 * 2 [cite: 62] |
| **** |           |
| 5 5 3             | * [cite_start]5 6 * [cite: 62] |
| ***..             | * * [cite_start]3 3 * [cite: 62] |
| .*..              | * [cite_start]2 * 3 * 2 * 1 [cite: 62] |
| *.*.              |           |

## Notas

[cite_start]No primeiro exemplo de teste, a mina terrestre na posição (2,2) foi removida por ser a primeira a aparecer no percurso da tropa e existe apenas um detonador disponível. [cite: 64] [cite_start]A outra mina terrestre não pôde ser removida por não haver detonadores disponíveis, então deve-se contabilizá-la nas posições vizinhas do mapa. [cite: 65]