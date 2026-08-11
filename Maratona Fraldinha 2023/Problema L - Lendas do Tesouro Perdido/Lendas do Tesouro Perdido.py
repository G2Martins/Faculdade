# Maratona Fraldinha 2023 - Problema L: Lendas do Tesouro Perdido

def solve_lendas_do_tesouro():
    n = int(input()) # Lê o número de elementos do vetor 'a'
    a = list(map(int, input().split())) # Lê os elementos do vetor 'a'

    # Se a lista estiver vazia, não há subsequência, então o tamanho é 0.
    if n == 0:
        print(0)
        return

    # dp_val[val] armazenará o comprimento máximo de uma subsequência válida
    # que termina com o valor 'val'.
    # A subsequência deve começar com 1 e adjacentes diferem em exatamente 1.
    # O valor máximo de a_i é n, então precisamos de n+1 posições (índices de 0 a n).
    # Adicionamos uma posição extra para evitar erros de índice (n+2).
    dp_val = [0] * (n + 2) 

    # Variável para armazenar o comprimento máximo da subsequência completa.
    # Uma subsequência válida deve começar em 1 e terminar em 1.
    overall_max_len = 0

    # Itera sobre cada número 'x' no vetor de entrada 'a'.
    for x in a:
        current_max_for_x = 0 # Armazena o comprimento máximo para a subsequência terminando em 'x' na iteração atual.
        
        # Possibilidade 1: A subsequência chega a 'x' vindo de 'x-1'.
        # Verifica se 'x-1' é um valor válido (maior ou igual a 1)
        # e se já existe uma subsequência válida terminando em 'x-1' (dp_val[x-1] > 0).
        if x - 1 >= 1 and dp_val[x-1] > 0:
            current_max_for_x = max(current_max_for_x, dp_val[x-1] + 1)
        
        # Possibilidade 2: A subsequência chega a 'x' vindo de 'x+1'.
        # Verifica se 'x+1' é um valor válido (menor ou igual a n)
        # e se já existe uma subsequência válida terminando em 'x+1' (dp_val[x+1] > 0).
        if x + 1 <= n and dp_val[x+1] > 0:
            current_max_for_x = max(current_max_for_x, dp_val[x+1] + 1)

        # Possibilidade 3: Se 'x' é 1, ele pode iniciar uma nova subsequência de comprimento 1.
        # Esta é a condição de partida da subsequência.
        if x == 1:
            current_max_for_x = max(current_max_for_x, 1)

        # Atualiza o valor de dp_val[x] com o maior comprimento encontrado para subsequências
        # que terminam em 'x'. É importante pegar o máximo com o valor existente
        # porque ocorrências anteriores de 'x' podem ter levado a um caminho mais longo.
        if current_max_for_x > 0: # Só atualiza se um caminho válido foi encontrado.
            dp_val[x] = max(dp_val[x], current_max_for_x)
        
        # Se o elemento atual 'x' é 1, ele pode ser o final da subsequência mais longa que
        # começa em 1 e termina em 1.
        # Portanto, atualizamos o `overall_max_len` com `dp_val[1]`.
        if x == 1:
            overall_max_len = max(overall_max_len, dp_val[1])
            
    print(overall_max_len) # Imprime o tamanho da maior subsequência que satisfaz as restrições

solve_lendas_do_tesouro()