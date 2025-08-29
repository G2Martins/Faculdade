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


class GrafoDenso(Grafo):
    def __init__(self, rotulos):
        self._numero_de_vertices = len(rotulos)
        self._numero_de_arestas = 0
        self.rotulos = list(rotulos)
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
            if idx_u == idx_v: self.matriz_adjacencia[idx_u][idx_v] = 1
            else:
                self.matriz_adjacencia[idx_u][idx_v] = 1
                self.matriz_adjacencia[idx_v][idx_u] = 1
            self._numero_de_arestas += 1
    def remover_aresta(self, u, v):
        idx_u = self.rotulos_para_indices[u]
        idx_v = self.rotulos_para_indices[v]
        if self.matriz_adjacencia[idx_u][idx_v] == 1:
            if idx_u == idx_v: self.matriz_adjacencia[idx_u][idx_v] = 0
            else:
                self.matriz_adjacencia[idx_u][idx_v] = 0
                self.matriz_adjacencia[idx_v][idx_u] = 0
            self._numero_de_arestas -= 1
    def sequencia_de_graus(self):
        sequencia = [sum(self.matriz_adjacencia[i]) for i in range(self._numero_de_vertices)]
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
            if self.matriz_adjacencia[i][i] == 1: return False
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
        for i in range(self.numero_de_vertices()):
            for j in range(i, self.numero_de_vertices()):
                if self.matriz_adjacencia[i][j] == 1:
                    u = self.rotulos[i]
                    v = self.rotulos[j]
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
    G1 = GrafoDenso(['A', 'B', 'C', 'D'])
    G1.adicionar_aresta('A', 'B')
    G1.adicionar_aresta('B', 'C')
    G1.adicionar_aresta('C', 'D')
    G1.adicionar_aresta('D', 'A')

    G2 = GrafoDenso(['W', 'X', 'Y', 'Z'])
    G2.adicionar_aresta('W', 'X')
    G2.adicionar_aresta('X', 'Y')
    G2.adicionar_aresta('Y', 'Z')
    G2.adicionar_aresta('Z', 'W')

    G3 = GrafoDenso(['P1', 'P2', 'P3', 'P4'])
    G3.adicionar_aresta('P1', 'P2')
    G3.adicionar_aresta('P1', 'P3')
    G3.adicionar_aresta('P1', 'P4')
    
    print("")
    print(f"G1 e G2 são isomorfos? {G1.is_isomorfo(G2)}")
    print(f"G1 e G3 são isomorfos? {G1.is_isomorfo(G3)}")