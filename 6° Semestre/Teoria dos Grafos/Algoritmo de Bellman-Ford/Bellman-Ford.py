# Algoritmo de Bellman-Ford para encontrar os menores caminhos de um grafo

# Definição das arestas conforme o grafo da imagem
arestas = [
    # S -> A, S -> B, S -> D
    ('S', 'A', 3),
    ('S', 'B', 5),
    ('S', 'D', 2),
    # A -> C
    ('A', 'C', -5),
    # B -> C, B -> D
    ('B', 'C', 8),
    ('B', 'D', -9),
    # C -> D
    ('C', 'D', -3),
    # C -> A
    ('C', 'A', 6),
    # D -> C
    ('D', 'C', 8)
]

# Conjunto dos vértices presentes no grafo
vertices = set()
for origem, destino, peso in arestas:
    vertices.add(origem)
    vertices.add(destino)

# Função Bellman-Ford
def bellman_ford(arestas, vertices, origem):
    # Inicializa distância para todos os vértices como infinito
    distancias = {v: float('inf') for v in vertices}
    distancias[origem] = 0
    
    # Predecessores para recuperação do caminho
    predecessores = {v: None for v in vertices}
    
    # Relaxa todas as arestas V-1 vezes
    for i in range(len(vertices) - 1):
        for u, v, peso in arestas:
            if distancias[u] + peso < distancias[v]:
                distancias[v] = distancias[u] + peso
                predecessores[v] = u
    
    # Verifica ciclos negativos
    for u, v, peso in arestas:
        if distancias[u] + peso < distancias[v]:
            print("ATENÇÃO: O grafo possui ciclo negativo!")
            return None, None
    
    return distancias, predecessores

# Executa o algoritmo Bellman-Ford a partir do vértice inicial 'S'
distancias, predecessores = bellman_ford(arestas, vertices, 'S')

if distancias:
    print("Menor distância de S para cada vértice:")
    for v in vertices:
        print(f"S -> {v}: {distancias[v]}")
else:
    print("Não foi possível calcular devido a ciclo negativo.")

# Função opcional para imprimir o menor caminho até um destino
def imprimir_caminho(predecessores, destino):
    caminho = []
    atual = destino
    while atual:
        caminho.append(atual)
        atual = predecessores[atual]
    caminho.reverse()
    print(" -> ".join(caminho))

# Exemplo: imprimir caminho até D
if distancias:
    print("Menor caminho de S até D:")
    imprimir_caminho(predecessores, 'D')


# - O algoritmo checa a presença de ciclos negativos e avisa se encontrar um.
