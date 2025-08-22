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

class GrafoEsparso(Grafo):
    def __init__(self, rotulos):
        self._numero_de_vertices = len(rotulos)
        self._numero_de_arestas = 0
        self.rotulos = rotulos
        self.lista_adjacencia = {rotulo: [] for rotulo in rotulos}

    def numero_de_vertices(self):
        return self._numero_de_vertices

    def numero_de_arestas(self):
        return self._numero_de_arestas

    def adicionar_aresta(self, u, v):
        if u in self.lista_adjacencia and v in self.lista_adjacencia:
            self.lista_adjacencia[u].append(v)
            self.lista_adjacencia[v].append(u)
            self._numero_de_arestas += 1
        else:
            print("Um ou ambos os vértices não existem no grafo.")

    def remover_aresta(self, u, v):
        if u in self.lista_adjacencia and v in self.lista_adjacencia:
            if v in self.lista_adjacencia[u]:
                self.lista_adjacencia[u].remove(v)
                self.lista_adjacencia[v].remove(u)
                self._numero_de_arestas -= 1
            else:
                print(f"Não existe aresta entre {u} e {v} para remover.")
        else:
            print("Um ou ambos os vértices não existem no grafo.")

    def sequencia_de_graus(self):
        sequencia = []
        for rotulo in self.rotulos:
            grau = len(self.lista_adjacencia[rotulo])
            sequencia.append(grau)
        sequencia.sort()
        return sequencia

    def imprimir(self):
        print("Lista de Adjacência:")
        for rotulo in sorted(self.lista_adjacencia.keys()):
            vizinhos_formatados = ", ".join([f"'{vizinho}'" for vizinho in self.lista_adjacencia[rotulo]])
            print(f"{rotulo} -> [ [{vizinhos_formatados}] ]")

    def is_nulo(self):
        return self.numero_de_arestas() == 0

    def is_simples(self):
        for u in self.rotulos:
            vizinhos = self.lista_adjacencia[u]
            if u in vizinhos:
                return False
            if len(vizinhos) != len(set(vizinhos)):
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
    print()
    # Teste 1: Grafo Nulo
    grafo_nulo = GrafoEsparso(['A', 'B', 'C'])
    print(f"É nulo? {grafo_nulo.is_nulo()}")
    print(f"É simples? {grafo_nulo.is_simples()}")
    print(f"É completo? {grafo_nulo.is_completo()}")
    print("-" * 20)

    # Teste 2: Grafo com Arestas Múltiplas (Não Simples)
    grafo_multiplo = GrafoEsparso(['A', 'B', 'C'])
    grafo_multiplo.adicionar_aresta('A', 'B')
    grafo_multiplo.adicionar_aresta('A', 'B') # Aresta Múltipla
    grafo_multiplo.imprimir()
    print()
    print(f"É nulo? {grafo_multiplo.is_nulo()}")
    print(f"É simples? {grafo_multiplo.is_simples()}")
    print(f"É completo? {grafo_multiplo.is_completo()}")
    print("-" * 20)

    # Teste 3: Grafo Completo
    grafo_completo = GrafoEsparso(['A', 'B', 'C', 'D'])
    grafo_completo.adicionar_aresta('A', 'B')
    grafo_completo.adicionar_aresta('A', 'C')
    grafo_completo.adicionar_aresta('A', 'D')
    grafo_completo.adicionar_aresta('B', 'C')
    grafo_completo.adicionar_aresta('B', 'D')
    grafo_completo.adicionar_aresta('C', 'D')
    grafo_completo.imprimir()
    print()
    print(f"É nulo? {grafo_completo.is_nulo()}")
    print(f"É simples? {grafo_completo.is_simples()}")
    print(f"É completo? {grafo_completo.is_completo()}")
    print("-" * 20)