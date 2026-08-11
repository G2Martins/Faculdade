
def merge_sort(arr):
    if len(arr) <= 1:
        return arr
    meio = len(arr) // 2

    esquerda = []
    direita = []

    for i in range(0, meio):
        esquerda.append(arr[i])

    for i in range(meio, len(arr)):
        direita.append(arr[i])
    
    esquerda_ordenada = merge_sort(esquerda)
    direita_ordenada = merge_sort(direita)
    
    return merge(esquerda_ordenada, direita_ordenada)

def merge(esquerda, direita):
    resultado = []

    i_esq = 0
    i_dir = 0

    # Enquanto eu tenho elementos dos dois lados
    while i_esq < len(esquerda) and i_dir < len(direita):
        
        if esquerda[i_esq] < direita[i_dir]:
            resultado.append(esquerda[i_esq])
            i_esq += 1
        else:
            resultado.append(direita[i_dir])
            i_dir += 1

    while i_dir < len(direita):
        resultado.append(direita[i_dir])
        i_dir += 1

    while i_esq < len(esquerda):
        resultado.append(esquerda[i_esq])
        i_esq += 1