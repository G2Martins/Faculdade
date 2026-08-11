# Maratona Fraldinha 2023 - Problema N: Números Balanceados

# Dicionário para memoização, para armazenar resultados de chamadas já computadas.
# Isso evita recálculos e melhora a performance para strings repetidas ou subproblemas.
memo = {}

def is_balanced_recursive(s):
    # Verifica se o resultado para a string 's' já está na memoização.
    if s in memo:
        return memo[s]

    # Caso base: Se a string estiver vazia, ela é considerada balanceada
    # (pois "deixa de ser um número inteiro").
    if not s:
        memo[s] = True
        return True

    # Variáveis para controle:
    # `pairs_found`: Indica se algum par correspondente foi encontrado na string atual.
    # `all_children_balanced`: Assume que todas as próximas remoções levarão a um estado balanceado,
    #                         até que uma delas prove o contrário.
    pairs_found = False
    all_children_balanced = True 

    # Itera sobre a string para encontrar pares adjacentes de dígitos iguais. 
    for i in range(len(s) - 1):
        if s[i] == s[i+1]: # Encontrou um par 
            pairs_found = True
            # Cria a nova string removendo o par encontrado.
            new_s = s[:i] + s[i+2:]
            
            # Recursivamente, verifica se a nova string é balanceada.
            # Se *qualquer* remoção de par levar a um estado não balanceado,
            # a string original não é balanceada.
            if not is_balanced_recursive(new_s):
                all_children_balanced = False
                break # Uma ramificação não balanceada foi encontrada, pode parar de verificar esta string.

    # Se nenhum par foi encontrado na string e ela não está vazia,
    # então não é possível remover um par, e, portanto, a string não é balanceada.
    if not pairs_found:
        memo[s] = False
        return False
    
    # Se chegamos aqui, pares foram encontrados.
    # O resultado é `all_children_balanced`: se todas as remoções levaram a estados balanceados.
    memo[s] = all_children_balanced
    return all_children_balanced

def solve_numeros_balanceados():
    s = input() # Lê a string de entrada, composta por 'n' dígitos numéricos e 'n' é par. 
    
    # Reinicia o dicionário de memoização para cada execução da função principal,
    # útil se houvessem múltiplos casos de teste no input, mas o problema sugere um único.
    global memo
    memo = {} 

    if is_balanced_recursive(s):
        print("sim") # Imprime "sim" se o número de entrada for balanceado 
    else:
        print("nao") # Imprime "nao" caso contrário

solve_numeros_balanceados()