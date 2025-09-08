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
    @abstractmethod
    def is_isomorfo(self, outro_grafo): pass

    @staticmethod
    def gerar_permutacoes(elementos):
        if len(elementos) <= 1:
            return [elementos]
        
        perms = []
        for i in range(len(elementos)):
            primeiro_elemento = elementos[i]
            elementos_restantes = elementos[:i] + elementos[i+1:]
            for p in Grafo.gerar_permutacoes(elementos_restantes):
                perms.append([primeiro_elemento] + p)
        return perms

    def verificar_isomorfismo(self, outro_grafo):
        if self.numero_de_vertices() != outro_grafo.numero_de_vertices():
            return False
        if self.numero_de_arestas() != outro_grafo.numero_de_arestas():
            return False
        if self.sequencia_de_graus() != outro_grafo.sequencia_de_graus():
            return False

        vertices_self = sorted(list(self.get_vertices()))
        vertices_outro = list(outro_grafo.get_vertices())
        arestas_outro = outro_grafo.get_arestas()
        
        todas_as_permutacoes = Grafo.gerar_permutacoes(vertices_outro)
        
        for p in todas_as_permutacoes:
            mapeamento = {vertices_self[i]: p[i] for i in range(self.numero_de_vertices())}
            
            arestas_self_mapeadas = set()
            for u, v in self.get_arestas():
                nova_aresta = tuple(sorted((mapeamento[u], mapeamento[v])))
                arestas_self_mapeadas.add(nova_aresta)
            
            if arestas_self_mapeadas == arestas_outro:
                return True
        
        return False


class GrafoEsparso(Grafo):
    def __init__(self, rotulos):
        self._numero_de_vertices = len(rotulos)
        self._numero_de_arestas = 0
        self.rotulos = list(rotulos)
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
    def remover_aresta(self, u, v):
        if u in self.lista_adjacencia and v in self.lista_adjacencia and v in self.lista_adjacencia[u]:
            self.lista_adjacencia[u].remove(v)
            self.lista_adjacencia[v].remove(u)
            self._numero_de_arestas -= 1
    def sequencia_de_graus(self):
        sequencia = [len(self.lista_adjacencia[rotulo]) for rotulo in self.rotulos]
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
            if u in vizinhos: return False
            if len(vizinhos) != len(set(vizinhos)): return False
        return True
    def is_completo(self):
        if not self.is_simples(): return False
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
        return self.get_vertices().issubset(outro_grafo.get_vertices()) and self.get_arestas().issubset(outro_grafo.get_arestas())
    def is_subgrafo_gerador(self, outro_grafo):
        return self.is_subgrafo(outro_grafo) and self.get_vertices() == outro_grafo.get_vertices()
    def is_subgrafo_induzido(self, outro_grafo):
        if not self.get_vertices().issubset(outro_grafo.get_vertices()): return False
        arestas_induzidas = set()
        vertices_self = self.get_vertices()
        for u, v in outro_grafo.get_arestas():
            if u in vertices_self and v in vertices_self:
                arestas_induzidas.add(tuple(sorted((u,v))))
        return self.get_arestas() == arestas_induzidas
    def is_isomorfo(self, outro_grafo):
        return self.verificar_isomorfismo(outro_grafo)

if __name__ == '__main__':
    G1 = GrafoEsparso(['A', 'B', 'C', 'D', 'E'])
    aulas = ['M', 'A', 'C', 'F', 'Q', 'P']
    