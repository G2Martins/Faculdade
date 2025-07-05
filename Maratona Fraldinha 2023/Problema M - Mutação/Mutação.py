# Maratona Fraldinha 2023 - Problema M: Mutação

def solve_mutacao():
    n, d = map(int, input().split()) # Lê a dimensão da matriz (n) e o valor do dado (d) 
    matrix = []
    for _ in range(n):
        matrix.append(list(map(int, input().split()))) # Lê a configuração do tabuleiro 
        
    temp_matrix = [row[:] for row in matrix] 

    
    effective_d = d % 4 

    if effective_d == 0:
        
        pass
    else:
        
        for layer in range(n // 2):
            
            # 1. Extrair os elementos da camada atual em ordem horária
            current_layer_elements = []
            
            # Canto superior esquerdo
            current_layer_elements.append(temp_matrix[layer][layer])
            # Canto superior direito
            current_layer_elements.append(temp_matrix[layer][n - 1 - layer])
            # Canto inferior direito
            current_layer_elements.append(temp_matrix[n - 1 - layer][n - 1 - layer])
            # Canto inferior esquerdo
            current_layer_elements.append(temp_matrix[n - 1 - layer][layer])
            
            
            rotated_elements = current_layer_elements[-effective_d:] + current_layer_elements[:-effective_d]

            # 2. Colocar os elementos rotacionados de volta na matriz nas suas posições originais da camada
            # Canto superior esquerdo
            matrix[layer][layer] = rotated_elements[0]
            # Canto superior direito
            matrix[layer][n - 1 - layer] = rotated_elements[1]
            # Canto inferior direito
            matrix[n - 1 - layer][n - 1 - layer] = rotated_elements[2]
            # Canto inferior esquerdo
            matrix[n - 1 - layer][layer] = rotated_elements[3]

    
    for row in matrix:
        print(*row) 

solve_mutacao()