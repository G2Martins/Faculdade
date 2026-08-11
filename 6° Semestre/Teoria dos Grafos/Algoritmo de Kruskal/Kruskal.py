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
    @abstractmethod
    def colorir_grafo(self):
        pass
    @abstractmethod
    def kruskal_mst(self):
        pass
    

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
        self.rotulos = list(rotulos)
        self.lista_adjacencia = {rotulo: [] for rotulo in rotulos}
        self.arestas = []

    def numero_de_vertices(self):
        return self._numero_de_vertices
    
    def numero_de_arestas(self):
        return len(self.arestas)
    
    def adicionar_aresta(self, u, v, peso=1):
        if u in self.lista_adjacencia and v in self.lista_adjacencia:
            self.lista_adjacencia[u].append((v, peso))
            self.lista_adjacencia[v].append((u, peso))
            self.arestas.append((u, v, peso))
    
    def remover_aresta(self, u, v):
        if u not in self.lista_adjacencia or v not in self.lista_adjacencia:
            return

        # Encontra e remove a aresta de u para v
        aresta_em_u = None
        for vizinho, peso in self.lista_adjacencia[u]:
            if vizinho == v:
                aresta_em_u = (vizinho, peso)
                break
        
        # Encontra e remove a aresta de v para u
        aresta_em_v = None
        for vizinho, peso in self.lista_adjacencia[v]:
            if vizinho == u:
                aresta_em_v = (vizinho, peso)
                break

        # Se a aresta existir em ambas as listas, remove
        if aresta_em_u and aresta_em_v:
            self.lista_adjacencia[u].remove(aresta_em_u)
            self.lista_adjacencia[v].remove(aresta_em_v)
            
            # Remove da lista principal de arestas também
            peso_aresta = aresta_em_u[1]
            aresta_global1 = (u, v, peso_aresta)
            aresta_global2 = (v, u, peso_aresta)
            if aresta_global1 in self.arestas:
                self.arestas.remove(aresta_global1)
            elif aresta_global2 in self.arestas:
                self.arestas.remove(aresta_global2)
    
    def sequencia_de_graus(self):
        sequencia = [len(self.lista_adjacencia[rotulo]) for rotulo in self.rotulos]
        sequencia.sort()
        return sequencia
    
    def imprimir(self):
        print("Lista de Adjacência (com pesos):")
        for rotulo in sorted(self.lista_adjacencia.keys()):
            vizinhos_formatados = ", ".join([f"('{v}', {p})" for v, p in self.lista_adjacencia[rotulo]])
            print(f"{rotulo} -> [ {vizinhos_formatados} ]")
    
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
        return self.arestas
    
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

    def is_seguro(self, vertice, cor, cores):
        for vizinho in self.lista_adjacencia[vertice]:
            if cores.get(vizinho) == cor:
                return False
        return True

    def resolver_coloracao_util(self, k, cores, indice_vertice):
        if indice_vertice == self.numero_de_vertices():
            return True
        vertice_atual = self.rotulos[indice_vertice]
        
        for cor in range(1, k + 1):
            print(f"Tentando colorir a aula {vertice_atual} com {k} horários...")
            if self.is_seguro(vertice_atual, cor, cores):
                cores[vertice_atual] = cor
                if self.resolver_coloracao_util(k, cores, indice_vertice + 1):
                    return True
                cores[vertice_atual] = 0 # Backtrack
        return False

    def colorir_grafo(self):
        num_vertices = self.numero_de_vertices()
        for k in range(1, num_vertices + 2):
            cores = {vertice: 0 for vertice in self.rotulos}
            if self.resolver_coloracao_util(k, cores, 0):
                return k, cores
        return None, None # Em caso de erro
    
    def kruskal_mst(self):
        # Dicionário para o Union-Find, armazena o pai de cada componente
        parent = {vertice: vertice for vertice in self.rotulos}

        # Função auxiliar para encontrar o representante (raiz) de um conjunto
        def find(vertice):
            if parent[vertice] == vertice:
                return vertice
            parent[vertice] = find(parent[vertice]) 
            return parent[vertice]
    
        def union(v1, v2):
            raiz1 = find(v1)
            raiz2 = find(v2)
            if raiz1 != raiz2:
                parent[raiz2] = raiz1

        # Passo 1: Ordenar todas as arestas pelo peso 
        arestas_ordenadas = sorted(self.arestas, key=lambda item: item[2])
        
        arvore_geradora_minima = []
        custo_total = 0

        # Passo 3: Iterar sobre as arestas ordenadas 
        for u, v, peso in arestas_ordenadas:
            # Passo 3.1: Verificar se adicionar a aresta forma um ciclo
            if find(u) != find(v):
                # Passo 3.2: Se não forma ciclo, une os componentes e adiciona à MST 
                union(u, v)
                arvore_geradora_minima.append((u, v, peso))
                custo_total += peso
        
        return arvore_geradora_minima, custo_total

if __name__ == '__main__':
    vertices = ['A', 'B', 'C', 'D', 'E']
    g = GrafoEsparso(vertices)
    
    arestas_com_peso = [
        ('A', 'D', 1),
        ('C', 'E', 2),
        ('A', 'B', 3),
        ('B', 'D', 4),
        ('B', 'C', 5),
        ('D', 'E', 6)
    ]

    for u, v, peso in arestas_com_peso:
        g.adicionar_aresta(u, v, peso)
        
    print("--- Grafo Ponderado Original ---")
    g.imprimir()
    print("-" * 30)

    print("--- Executando o Algoritmo de Kruskal ---")
    mst, custo = g.kruskal_mst()
    
    print("\nÁrvore Geradora Mínima (MST) encontrada:")
    for u, v, peso in mst:
        print(f"  Aresta: ({u} - {v}), Peso: {peso}")
        
    print(f"\nCusto Total da MST: {custo}")