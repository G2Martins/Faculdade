# Teoria dos Grafos

> Implementação dos principais algoritmos e estruturas de grafos em Python. Inclui representações por lista e matriz de adjacência, algoritmos de caminho mínimo, árvore geradora mínima e atividades práticas semanais.

---

## 📂 Estrutura

```
Teoria dos Grafos/
├── Grafo Esparso/              # GrafoEsparso.py — lista de adjacência
├── Grafo Denso/                # GrafoDenso.py — matriz de adjacência
├── Grafo Isomorfo/             # GrafoEsparsoIso.py, GrafoDensoIso.py
├── Grafo Coloracao/            # Coloração de vértices
├── Algoritmo de Bellman-Ford/  # Bellman-Ford.py — caminho mínimo c/ pesos negativos
├── Algoritmo de Kruskal/       # Kruskal.py — árvore geradora mínima
├── Atividade 01/               # Análise do grafo do metrô
├── Atividade 02/               # Problemas de conectividade
├── Atividade 03/               # Múltiplos exemplos de grafos
├── Atividade 04/               # Implementação de Dijkstra
├── Atividade 05/               # Implementação de Bellman-Ford
├── Atividade 11/               # Problemas avançados
├── Atividade 12/               # Problemas avançados com visualização
└── Material/                   # Slides e PDFs das aulas
```

---

## 🔧 Implementações

### GrafoEsparso.py (Lista de adjacência)
Métodos: `num_vertices`, `num_arestas`, `adicionar_aresta`, `remover_aresta`, `grau`, `sequencia_de_graus`, `is_simples`, `is_completo`, `is_nulo`, `is_subgrafo`, `is_subgrafo_gerador`, `is_subgrafo_induzido`.

### GrafoDenso.py (Matriz de adjacência)
Mesma interface do GrafoEsparso, com representação em matriz para grafos densos.

### Algoritmo de Bellman-Ford
Encontra o caminho mínimo a partir de uma fonte, suportando arestas com **pesos negativos**. Detecta ciclos negativos.

### Algoritmo de Kruskal
Constrói a **Árvore Geradora Mínima** (MST) de um grafo ponderado usando Union-Find.

---

## 📐 Propriedades Verificadas

| Propriedade | Descrição |
|-------------|-----------|
| `is_simples` | Sem laços nem arestas paralelas |
| `is_completo` | Todo par de vértices conectado |
| `is_nulo` | Sem arestas |
| `is_subgrafo` | Subconjunto de vértices/arestas |
| `is_subgrafo_gerador` | Mantém todos os vértices |
| `is_subgrafo_induzido` | Arestas entre vértices preservados |
| `is_isomorfo` | Estrutura topológica equivalente |

---

## 📚 Material das Aulas

| Arquivo | Conteúdo |
|---------|---------|
| Aula-01-IntroducaoGrafos.pdf | Conceitos fundamentais |
| Aula-02-representacao.pdf | Representações de grafos |
| Aula-03_Tipos_De_Grafos.pdf | Tipos e classificações |
| Aula-04_Coloração de Grafos.pdf | Coloração e número cromático |
| Aula-05_Percurso em Grafos.pptx | BFS e DFS |
| Aula-06_arvores.pdf | Árvores e spanning trees |
| Aula-08_caminho-minimo.pdf | Dijkstra e Bellman-Ford |
| Pacial-Arvores.pdf | Material de revisão — árvores |

---

![Python](https://img.shields.io/badge/Python-3776AB?style=flat&logo=python&logoColor=white)
