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
        
    @abstractmethod
    def is_simples(self):
        pass

    @abstractmethod
    def is_nulo(self):
        pass

    @abstractmethod
    def is_completo(self):
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
            if idx_u == idx_v:
                self.matriz_adjacencia[idx_u][idx_v] = 1
            else:
                self.matriz_adjacencia[idx_u][idx_v] = 1
                self.matriz_adjacencia[idx_v][idx_u] = 1
            self._numero_de_arestas += 1

    def remover_aresta(self, u, v):
        idx_u = self.rotulos_para_indices[u]
        idx_v = self.rotulos_para_indices[v]

        if self.matriz_adjacencia[idx_u][idx_v] == 1:
            if idx_u == idx_v:
                self.matriz_adjacencia[idx_u][idx_v] = 0
            else:
                self.matriz_adjacencia[idx_u][idx_v] = 0
                self.matriz_adjacencia[idx_v][idx_u] = 0
            self._numero_de_arestas -= 1

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

    def is_nulo(self):
        return self.numero_de_arestas() == 0

    def is_simples(self):
        for i in range(self.numero_de_vertices()):
            if self.matriz_adjacencia[i][i] == 1:
                return False
        return True 

    def is_completo(self):
        if not self.is_simples():
            return False
        
        v = self.numero_de_vertices()
        e = self.numero_de_arestas()
        max_arestas = v * (v - 1) / 2
        return e == max_arestas

if __name__ == '__main__':
    grafo_nulo = GrafoDenso(['A', 'B', 'C'])
    print(f"É nulo? {grafo_nulo.is_nulo()}")
    print(f"É simples? {grafo_nulo.is_simples()}")
    print(f"É completo? {grafo_nulo.is_completo()}")
    print("-" * 20)
    grafo_completo = GrafoDenso(['A', 'B', 'C'])
    grafo_completo.adicionar_aresta('A', 'B')
    grafo_completo.adicionar_aresta('A', 'C')
    grafo_completo.adicionar_aresta('B', 'C')
    grafo_completo.imprimir()
    print()
    print(f"É nulo? {grafo_completo.is_nulo()}")
    print(f"É simples? {grafo_completo.is_simples()}")
    print(f"É completo? {grafo_completo.is_completo()}")
    print("-" * 20)
    grafo_laco = GrafoDenso(['A', 'B', 'C'])
    grafo_laco.adicionar_aresta('A', 'B')
    grafo_laco.adicionar_aresta('A', 'A') 
 
    grafo_laco.imprimir()
    print()
    print(f"É nulo? {grafo_laco.is_nulo()}")
    print(f"É simples? {grafo_laco.is_simples()}")
    print(f"É completo? {grafo_laco.is_completo()}")
    print("-" * 20)