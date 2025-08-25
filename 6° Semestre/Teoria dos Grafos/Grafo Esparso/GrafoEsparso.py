from abc import ABC, abstractmethod

class Grafo(ABC):
    @abstractmethod
    def numero_de_vertices(self): pass
    @abstractmethod
    def numero_de_arestas(self): pass
    @abstractmethod
    def sequencia_de_graus(self): pass
    @abstractmethod
    def adicionar_aresta(self, u, v): pass
    @abstractmethod
    def remover_aresta(self, u, v): pass
    @abstractmethod
    def imprimir(self): pass
    @abstractmethod
    def is_simples(self): pass
    @abstractmethod
    def is_nulo(self): pass
    @abstractmethod
    def is_completo(self): pass
    @abstractmethod
    def get_vertices(self): pass
    @abstractmethod
    def get_arestas(self): pass
    @abstractmethod
    def is_subgrafo(self, outro_grafo): pass
    @abstractmethod
    def is_subgrafo_gerador(self, outro_grafo): pass
    @abstractmethod
    def is_subgrafo_induzido(self, outro_grafo): pass


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

    def get_vertices(self):
        return set(self.rotulos)

    def get_arestas(self):
        arestas = set()
        for u, vizinhos in self.lista_adjacencia.items():
            for v in vizinhos:
                arestas.add(tuple(sorted((u, v))))
        return arestas

    def is_subgrafo(self, outro_grafo):
        vertices_self = self.get_vertices()
        arestas_self = self.get_arestas()
        vertices_outro = outro_grafo.get_vertices()
        arestas_outro = outro_grafo.get_arestas()
        
        return vertices_self.issubset(vertices_outro) and arestas_self.issubset(arestas_outro)

    def is_subgrafo_gerador(self, outro_grafo):
        return self.is_subgrafo(outro_grafo) and self.get_vertices() == outro_grafo.get_vertices()

    def is_subgrafo_induzido(self, outro_grafo):
        if not self.get_vertices().issubset(outro_grafo.get_vertices()):
            return False
            
        arestas_induzidas = set()
        vertices_self = self.get_vertices()
        for u, v in outro_grafo.get_arestas():
            if u in vertices_self and v in vertices_self:
                arestas_induzidas.add(tuple(sorted((u,v))))
        
        return self.get_arestas() == arestas_induzidas


if __name__ == '__main__':
    # Grafo principal G
    G = GrafoEsparso(['A', 'B', 'C', 'D'])
    G.adicionar_aresta('A', 'B')
    G.adicionar_aresta('A', 'C')
    G.adicionar_aresta('B', 'C')
    G.adicionar_aresta('C', 'D')
    print("--- Grafo Principal G ---")
    G.imprimir()
    print("-" * 45)

    H1 = GrafoEsparso(['A', 'B', 'C'])
    H1.adicionar_aresta('A', 'B')
    H1.adicionar_aresta('B', 'C')
    print("--- Grafo H1 (Subgrafo de G?) ---")
    H1.imprimir()
    print(f"H1 é subgrafo de G? {H1.is_subgrafo(G)}")
    print(f"H1 é subgrafo gerador de G? {H1.is_subgrafo_gerador(G)}")
    print(f"H1 é subgrafo induzido de G? {H1.is_subgrafo_induzido(G)}")
    print("-" * 45)
    
    H2 = GrafoEsparso(['A', 'B', 'C', 'D'])
    H2.adicionar_aresta('A', 'B')
    H2.adicionar_aresta('C', 'D')
    print("--- Grafo H2 (Subgrafo Gerador de G?) ---")
    H2.imprimir()
    print(f"H2 é subgrafo de G? {H2.is_subgrafo(G)}")
    print(f"H2 é subgrafo gerador de G? {H2.is_subgrafo_gerador(G)}")
    print(f"H2 é subgrafo induzido de G? {H2.is_subgrafo_induzido(G)}")
    print("-" * 45)

    H3 = GrafoEsparso(['A', 'B', 'C'])
    H3.adicionar_aresta('A', 'B')
    H3.adicionar_aresta('A', 'C')
    H3.adicionar_aresta('B', 'C')
    print("--- Grafo H3 (Subgrafo Induzido de G?) ---")
    H3.imprimir()
    print(f"H3 é subgrafo de G? {H3.is_subgrafo(G)}")
    print(f"H3 é subgrafo gerador de G? {H3.is_subgrafo_gerador(G)}")
    print(f"H3 é subgrafo induzido de G? {H3.is_subgrafo_induzido(G)}")
    print("-" * 45)