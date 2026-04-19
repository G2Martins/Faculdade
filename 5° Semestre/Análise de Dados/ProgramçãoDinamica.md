## ---------------------------------------------------------------------
## Exercício 1: Fibonacci com Programação Dinâmica
## ---------------------------------------------------------------------

## ----------------------------------------------------------------------
## Exercício 2: Problema da Mochila 0/1
## ----------------------------------------------------------------------  

### Resolve o problema da mochila 0/1 usando programação dinâmica.
    - Argumentos:
        itens (list): Lista de tuplas, onde cada tupla contém (peso, valor) do item 
        Ex: [(w1,v1), (w2,v2), ...]
        capacidade_maxima (int): A capacidade máxima de peso da mochila.

    Retorna:
        tuple: (valor_maximo_obtido, itens_selecionados_indices)
        
        itens_selecionados_indices é uma lista de índices (0-indexado) dos itens escolhidos.

## ----------------------------------------------------------------------
## Exercício 3: Maior Subsequência Comum (LCS)
## ----------------------------------------------------------------------

### Encontra o comprimento da Maior Subsequência Comum (LCS) entre duas strings e a própria subsequência.

    - Argumentos:
        str1 (str): A primeira string.
        str2 (str): A segunda string.

    Retorna:
        tuple: (comprimento_lcs, subsequencia_lcs)


## ----------------------------------------------------------------------
## Exercício 6: Distância de Edição (Levenshtein)
## ----------------------------------------------------------------------

### Calcula a distância de Levenshtein entre duas strings e mostra as operações.
    - Argumentos:
        str1 (str): A primeira string (origem).
        str2 (str): A segunda string (destino).

    - Retorna:
        tuple: (distancia, operacoes)
               distancia (int): A distância de Levenshtein.
               operacoes (list): Lista de strings descrevendo as transformações.