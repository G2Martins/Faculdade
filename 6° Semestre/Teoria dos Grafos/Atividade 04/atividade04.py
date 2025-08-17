from abc import ABC, abstractmethod

class Grafo(ABC):
    @abstractmethod
    def numero_de_vertices(self):
        pass

    @abstractmethod
    def numero_de_arestas(self):
        pass

    @abstractmethod
    def sequencia_de_graus(self):
        pass

    @abstractmethod
    def adicionar_aresta(self, u, v):
        pass

    @abstractmethod
    def remover_aresta(self, u, v):
        pass

    @abstractmethod
    def imprimir(self):
        pass

class GrafoDenso(Grafo):
    def __init__(self, rotulos):
        self._numero_de_vertices = len(rotulos)
        self._numero_de_arestas = 0
        self.rotulos = rotulos
        self.rotulos_para_indices = {rotulo: i for i, rotulo in enumerate(rotulos)}
        self.matriz_adjacencia = [[0] * self._numero_de_vertices for _ in range(self._numero_de_vertices)]

    def numero_de_vertices(self):
        return self._numero_de_vertices

    def numero_de_arestas(self):
        return self._numero_de_arestas

    def adicionar_aresta(self, u, v):
        idx_u = self.rotulos_para_indices[u]
        idx_v = self.rotulos_para_indices[v]
        
        if self.matriz_adjacencia[idx_u][idx_v] == 0:
            self.matriz_adjacencia[idx_u][idx_v] = 1
            self.matriz_adjacencia[idx_v][idx_u] = 1
            self._numero_de_arestas += 1
            print(f"Aresta adicionada entre {u} e {v}.")

    def remover_aresta(self, u, v):
        idx_u = self.rotulos_para_indices[u]
        idx_v = self.rotulos_para_indices[v]

        if self.matriz_adjacencia[idx_u][idx_v] == 1:
            self.matriz_adjacencia[idx_u][idx_v] = 0
            self.matriz_adjacencia[idx_v][idx_u] = 0
            self._numero_de_arestas -= 1
            print(f"Aresta removida entre {u} e {v}.")

    def sequencia_de_graus(self):
        sequencia = []
        for i in range(self._numero_de_vertices):
            grau = sum(self.matriz_adjacencia[i])
            sequencia.append(grau)
        sequencia.sort()
        return sequencia

    def imprimir(self):
        print("Matriz de Adjacência:")
        header = "  " + " ".join(self.rotulos)
        print(header)
        for i, rotulo in enumerate(self.rotulos):
            linha = rotulo + " " + " ".join(map(str, self.matriz_adjacencia[i]))
            print(linha)

if __name__ == '__main__':
    rotulos_vertices = ['A', 'B', 'C', 'D', 'E']
    grafo = GrafoDenso(rotulos_vertices)

    arestas_para_adicionar = [('A', 'B'), ('A', 'C'), ('C', 'D'), ('C', 'E'), ('B', 'D')]
    for u, v in arestas_para_adicionar:
        grafo.adicionar_aresta(u, v)
    
    print()
    grafo.imprimir()
    print()
    
    print(f"Número de vértices: {grafo.numero_de_vertices()}")
    print(f"Número de arestas: {grafo.numero_de_arestas()}")
    print(f"Sequência de graus: {grafo.sequencia_de_graus()}")
    
    print()
    grafo.remover_aresta('A', 'C')
    print()
    
    grafo.imprimir()