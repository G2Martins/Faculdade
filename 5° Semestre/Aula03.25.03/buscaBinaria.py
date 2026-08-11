def busca_binaria(alvo, arr):
    # Tenho meu valor
    # Dividir a lista no meio
        # Decidir um Meio
        # Ajustar indice da sua busca
    # Olhar onde cheguei
        # É meu elemento ? terminei
        # Não é 
        # Meu elemento é maior ou menor do onde estou?
            # Se Maior, busco so na metade direita (Dos maiores)
            # Se nao, busco so na metade esquerda (Dos menores)
    
    # Lista tem 11 elemento
    esquerda = 0
    direita = len(arr) - 1 # 10

    while esquerda <= direita:
        meio = (esquerda + direita) // 2  # 5

        if arr[meio] == alvo:  # se o quinto elemento é o meu alvo
            return meio  # Retorna o indice do meio
        else:
            if arr[meio] < alvo:
                esquerda = meio + 1
            else:
                direita = meio - 1
    
    return -1    