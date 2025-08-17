import networkx as nx
import numpy as np

# 1. Crie um grafo não orientado
G = nx.Graph()

# 2. Defina os vértices e as arestas
num_vertices = 5
arestas = [(0, 1), (0, 2), (1, 2), (1, 3), (2, 4), (3, 4)]

# Adicione os nós (vértices) e as arestas ao grafo
G.add_nodes_from(range(num_vertices))
G.add_edges_from(arestas)

# 3. Gere a matriz de adjacência
# A função do networkx retorna uma matriz em formato esparso (scipy),
# então convertemos para um array numpy denso para facilitar a visualização.
matriz_adj = nx.to_numpy_array(G, nodelist=sorted(G.nodes()))

# 4. Imprima a matriz
print("Vértices:", sorted(G.nodes()))
print("Matriz de Adjacência:")
print(matriz_adj)