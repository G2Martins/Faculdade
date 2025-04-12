lista = [64, 34, 25, 12, 22, 11, 90]

n = len(lista)

# Percorre todos os elementos da lista
for i in range(n):
    # Últimos i elementos já estão no lugar certo
    for j in range(0, n-i-1):
        # Percorre a lista de 0 a n-i-1
        # Troca se o elemento encontrado for maior que o próximo elemento
        if lista[j] > lista[j+1] :
            lista[j], lista[j+1] = lista[j+1], lista[j]

print ("Lista ordenada:", lista)