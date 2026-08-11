import numpy as np

# 1. Defina os vértices e arestas
num_vertices = 5
arestas = [(0, 1), (0, 2), (1, 2), (1, 3), (2, 4), (3, 4)]
vertices = list(range(num_vertices))

# 2. Crie uma matriz N x N de zeros, onde N é o número de vértices
# O tipo 'int' é usado para que a matriz contenha números inteiros.
matriz_adj = np.zeros((num_vertices, num_vertices), dtype=int)

# 3. Preencha a matriz com base nas arestas
for u, v in arestas:
    # Como o grafo é não orientado, se existe uma aresta de u para v,
    # também existe uma de v para u.
    matriz_adj[u][v] = 1
    matriz_adj[v][u] = 1

# 4. Imprima a matriz
print("Vértices:", vertices)
print("Matriz de Adjacência:")
print(matriz_adj)