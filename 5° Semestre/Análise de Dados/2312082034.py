import time 

# Versão recursiva simples
def exercicio_1_1_fib_recursivo_simples(n):
    if n <= 1:
        return n
        
    return exercicio_1_1_fib_recursivo_simples(n-1) + exercicio_1_1_fib_recursivo_simples(n-2)

def exercicio_1_2_fib_recursivo_memoizacao(n, memo=None):
    if n < 0:
        raise ValueError("A entrada deve ser um inteiro não negativo")
    if memo is None:
        memo = {}
    if n in memo:
        return memo[n]
    if n <= 1:
        return n
    else:
        resultado = exercicio_1_2_fib_recursivo_memoizacao(n-1, memo) + exercicio_1_2_fib_recursivo_memoizacao(n-2, memo)
        memo[n] = resultado
        return resultado

def exercicio_1_3_fib_iterativo(n):
    if n < 0:
        raise ValueError("A entrada deve ser um inteiro não negativo")
    elif n <= 1:
        return n
    else:
        a, b = 0, 1
        for _ in range(2, n + 1):
            a, b = b, a + b
        return b


def exercicio_2_mochila(itens, capacidade_maxima):
    
    num_itens = len(itens)
    # dp[i][w] armazenará o valor máximo que pode ser obtido com os primeiros 'i' itens
    # e uma capacidade máxima de 'w'.
    # Adicionamos +1 para facilitar a indexação (de 1 a num_itens e de 0 a capacidade_maxima).
    dp = [[0 for _ in range(capacidade_maxima + 1)] for _ in range(num_itens + 1)]

    # Preenche a tabela dp
    for i in range(1, num_itens + 1):
        peso_item_atual, valor_item_atual = itens[i-1] # i-1 porque os itens são 0-indexados
        for w in range(capacidade_maxima + 1):
            if peso_item_atual <= w:
                # Opção 1: Incluir o item atual
                # Valor do item atual + valor máximo com os itens restantes e capacidade restante
                valor_com_item = valor_item_atual + dp[i-1][w - peso_item_atual]
                # Opção 2: Não incluir o item atual
                # Valor máximo com os itens restantes e a mesma capacidade
                valor_sem_item = dp[i-1][w]
                dp[i][w] = max(valor_com_item, valor_sem_item)
            else:
                # Se o item atual é mais pesado que a capacidade 'w', não podemos incluí-lo
                dp[i][w] = dp[i-1][w]

    valor_maximo_obtido = dp[num_itens][capacidade_maxima]

    
    itens_selecionados_indices = []
    w = capacidade_maxima
    for i in range(num_itens, 0, -1):
        if dp[i][w] != dp[i-1][w]: # Significa que o item 'i' foi incluído
            itens_selecionados_indices.append(i-1) # Adiciona o índice original do item
            peso_item_atual, _ = itens[i-1]
            w -= peso_item_atual

    itens_selecionados_indices.reverse() # Para ter os índices em ordem crescente
    return valor_maximo_obtido, itens_selecionados_indices


def exercicio_3_lcs(str1, str2):
    m = len(str1)
    n = len(str2)

    # dp[i][j] conterá o comprimento da LCS de str1[0..i-1] e str2[0..j-1]
    dp = [[0 for _ in range(n + 1)] for _ in range(m + 1)]

    # Preenchendo a tabela dp de forma bottom-up
    for i in range(m + 1):
        for j in range(n + 1):
            if i == 0 or j == 0:
                dp[i][j] = 0
            elif str1[i-1] == str2[j-1]:
                dp[i][j] = dp[i-1][j-1] + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])

    comprimento_lcs = dp[m][n]

    # Reconstruindo a LCS
    subsequencia_lcs_chars = []
    i, j = m, n
    while i > 0 and j > 0:
        if str1[i-1] == str2[j-1]:
            subsequencia_lcs_chars.append(str1[i-1])
            i -= 1
            j -= 1
        elif dp[i-1][j] > dp[i][j-1]:
            i -= 1
        else:
            j -= 1

    subsequencia_lcs = "".join(reversed(subsequencia_lcs_chars))
    return comprimento_lcs, subsequencia_lcs


def exercicio_6_distancia_edicao(str1, str2):
    m = len(str1)
    n = len(str2)

    # dp[i][j] será a distância de edição entre str1[:i] e str2[:j]
    dp = [[0 for _ in range(n + 1)] for _ in range(m + 1)]

    # Casos base
    for i in range(m + 1):
        dp[i][0] = i  # Custo de deletar todos os caracteres de str1 para obter uma string vazia
    for j in range(n + 1):
        dp[0][j] = j  # Custo de inserir todos os caracteres de str2 em uma string vazia

    # Preenchendo a tabela dp
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            custo_substituicao = 0 if str1[i-1] == str2[j-1] else 1
            dp[i][j] = min(dp[i-1][j] + 1,        # Deleção de str1[i-1]
                           dp[i][j-1] + 1,        # Inserção de str2[j-1]
                           dp[i-1][j-1] + custo_substituicao) # Substituição ou match

    distancia = dp[m][n]

    # Reconstruindo as operações
    operacoes = []
    i, j = m, n
    s1_list = list(str1) 

    while i > 0 or j > 0:
        custo_substituicao_atual = 0 if i > 0 and j > 0 and str1[i-1] == str2[j-1] else 1

        if i > 0 and j > 0 and dp[i][j] == dp[i-1][j-1] + custo_substituicao_atual:
            if custo_substituicao_atual == 1:
                operacoes.append(f"Substituir '{str1[i-1]}' por '{str2[j-1]}' na posição {i-1} (original)")
                s1_list[i-1] = str2[j-1] 

            i -= 1
            j -= 1
        elif j > 0 and dp[i][j] == dp[i][j-1] + 1:
            operacoes.append(f"Inserir '{str2[j-1]}' na posição {i} (após char original {s1_list[i-1] if i > 0 else 'início'})")
            s1_list.insert(i, str2[j-1]) # Simula a inserção
            j -= 1
        elif i > 0 and dp[i][j] == dp[i-1][j] + 1:
            operacoes.append(f"Deletar '{str1[i-1]}' da posição {i-1} (original)")
            del s1_list[i-1] # Simula a deleção
            i -= 1
        else: # Caso de dp[0][0]
            break


    return distancia, list(reversed(operacoes))

def main():
    print("--- Exercício 1: Fibonacci ---")
    ns_fibonacci = [5, 10, 20, 30, 40, 45] 

    print("\nTestando Fibonacci Recursivo Simples:")
    for n_fib in ns_fibonacci:
        inicio = time.time()
        resultado = exercicio_1_1_fib_recursivo_simples(n_fib)
        fim = time.time()
        print(f"F({n_fib}) = {resultado}, Tempo: {fim - inicio:.6f} segundos")

    print("\nTestando Fibonacci Recursivo com Memoização:")
    for n_fib in ns_fibonacci + [40, 45]: # Adicionando valores maiores para memoização
        inicio = time.time()
        resultado = exercicio_1_2_fib_recursivo_memoizacao(n_fib)
        fim = time.time()
        print(f"F({n_fib}) = {resultado}, Tempo: {fim - inicio:.6f} segundos")

    print("\nTestando Fibonacci Iterativo:")
    for n_fib in ns_fibonacci + [40, 45]: # Adicionando valores maiores para iterativo
        inicio = time.time()
        resultado = exercicio_1_3_fib_iterativo(n_fib)
        fim = time.time()
        print(f"F({n_fib}) = {resultado}, Tempo: {fim - inicio:.6f} segundos")


    print("\n\n--- Exercício 2: Problema da Mochila 0/1 ---")
    itens_mochila = [(10, 60), (20, 100), (30, 120)] # (peso, valor)
    capacidade_w = 50
    print(f"Itens: {itens_mochila}, Capacidade Máxima: {capacidade_w}")
    valor_max, itens_selecionados = exercicio_2_mochila(itens_mochila, capacidade_w)
    print(f"Valor máximo obtido: {valor_max}")
    print(f"Índices dos itens selecionados (0-indexado): {itens_selecionados}")
    print("Itens selecionados (peso, valor):")
    for i in itens_selecionados:
        print(f"  - {itens_mochila[i]}")

    itens_mochila_2 = [(2, 3), (3, 4), (4, 5), (5, 6)]
    capacidade_w_2 = 8
    print(f"\nItens: {itens_mochila_2}, Capacidade Máxima: {capacidade_w_2}")
    valor_max_2, itens_selecionados_2 = exercicio_2_mochila(itens_mochila_2, capacidade_w_2)
    print(f"Valor máximo obtido: {valor_max_2}")
    print(f"Índices dos itens selecionados (0-indexado): {itens_selecionados_2}")
    print("Itens selecionados (peso, valor):")
    for i in itens_selecionados_2:
        print(f"  - {itens_mochila_2[i]}")


    print("\n\n--- Exercício 3: Maior Subsequência Comum (LCS) ---")
    str1_lcs = "AGGTAB"
    str2_lcs = "GXTXAYB"
    comprimento, subsequencia = exercicio_3_lcs(str1_lcs, str2_lcs)
    print(f"String 1: \"{str1_lcs}\"")
    print(f"String 2: \"{str2_lcs}\"")
    print(f"Comprimento da LCS: {comprimento}")
    print(f"Subsequência LCS: \"{subsequencia}\"")

    str1_lcs_2 = "ABCDGH"
    str2_lcs_2 = "AEDFHR"
    comprimento_2, subsequencia_2 = exercicio_3_lcs(str1_lcs_2, str2_lcs_2)
    print(f"\nString 1: \"{str1_lcs_2}\"")
    print(f"String 2: \"{str2_lcs_2}\"")
    print(f"Comprimento da LCS: {comprimento_2}")
    print(f"Subsequência LCS: \"{subsequencia_2}\"")

    str1_lcs_3 = "programacao"
    str2_lcs_3 = "dinamica"
    comprimento_3, subsequencia_3 = exercicio_3_lcs(str1_lcs_3, str2_lcs_3)
    print(f"\nString 1: \"{str1_lcs_3}\"")
    print(f"String 2: \"{str2_lcs_3}\"")
    print(f"Comprimento da LCS: {comprimento_3}")
    print(f"Subsequência LCS: \"{subsequencia_3}\"")


    print("\n\n--- Exercício 6: Distância de Edição (Levenshtein) ---")
    str1_lev = "kitten"
    str2_lev = "sitting"
    dist, ops = exercicio_6_distancia_edicao(str1_lev, str2_lev)
    print(f"String 1: \"{str1_lev}\"")
    print(f"String 2: \"{str2_lev}\"")
    print(f"Distância de Edição: {dist}")
    print("Operações para transformar str1 em str2:")
    for op in ops:
        print(f"  - {op}")

    str1_lev_2 = "flaw"
    str2_lev_2 = "lawn"
    dist_2, ops_2 = exercicio_6_distancia_edicao(str1_lev_2, str2_lev_2)
    print(f"\nString 1: \"{str1_lev_2}\"")
    print(f"String 2: \"{str2_lev_2}\"")
    print(f"Distância de Edição: {dist_2}")
    print("Operações para transformar str1 em str2:")
    for op in ops_2:
        print(f"  - {op}")

    str1_lev_3 = "domingo"
    str2_lev_3 = "sabado"
    dist_3, ops_3 = exercicio_6_distancia_edicao(str1_lev_3, str2_lev_3)
    print(f"\nString 1: \"{str1_lev_3}\"")
    print(f"String 2: \"{str2_lev_3}\"")
    print(f"Distância de Edição: {dist_3}")
    print("Operações para transformar str1 em str2:")
    for op in ops_3:
        print(f"  - {op}")

if __name__ == "__main__":
    main()