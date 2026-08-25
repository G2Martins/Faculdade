# CLAUDE.md — Faculdade (Repositório Acadêmico)

> **Spec viva.** Porta-de-entrada lida pelo agente em toda sessão aberta na raiz. Não duplica o conteúdo das disciplinas — **aponta** pra elas. Atualize no mesmo commit que muda uma regra, disciplina ou convenção.
>
> **Última revisão:** 2026-08-25
> **Foco atual:** 8° Semestre · **Compiladores** → [8° Semestre/Compiladores/CLAUDE.md](8°%20Semestre/Compiladores/CLAUDE.md)

---

## 0. Para que serve

Registrar, em Markdown versionado, todo o percurso da graduação em Ciência da Computação (IESB) — exercícios, resoluções, anotações de aula e projetos — de forma que o agente consiga retomar qualquer disciplina sem re-explicação.

**Placar:** 8 semestres · 6 concluídos · 2 em andamento · 1 disciplina com spec viva própria (Compiladores).

## 1. O que é

Repositório **só de conteúdo** — Markdown, código-fonte de exercícios e material de aula. **Não há aplicação, build, pipeline nem dependências.** O "produto" é a documentação: cada exercício resolvido, com o raciocínio explícito, pronto pra revisão antes de prova.

Linguagens que aparecem ao longo dos semestres: C, C++, Java, Python, MATLAB e, no 8°, **MineonScript** (linguagem didática criada em aula de Compiladores).

## 2. Como roda

Não tem build nem teste. O ciclo é: escrever Markdown → conferir renderização → commitar.

```bash
git status                       # sempre antes de mexer
git add "8° Semestre/Compiladores/AulaXX/Exercicio Y.md"   # aspas: o caminho tem ° e espaço
git config core.quotepath false  # uma vez por clone: git para de imprimir paths como "8\302\260 Semestre"
```

Diagramas Mermaid renderizam nativamente no GitHub — validar olhando o arquivo no site depois do push, não só no editor.

## 3. Mapa de módulos

| Semestre | Disciplinas | Linguagens | Status |
|---|---|---|---|
| [1°](1°%20Semestre) | Algoritmos e Programação de Computadores | C | ✅ Concluído |
| [2°](2°%20Semestre) | APC II — ponteiros, funções, recursão | C | ✅ Concluído |
| [3°](3°%20Semestre) | Estrutura de Dados · Computação Gráfica | C, C++, MATLAB | ✅ Concluído |
| [4°](4°%20Semestre) | Programação Orientada a Objetos · Monitoria | Java, C | ✅ Concluído |
| [5°](5°%20Semestre) | Análise de Dados e Algoritmos Avançados | Python, C | ✅ Concluído |
| [6°](6°%20Semestre) | Teoria dos Grafos | Python | ✅ Concluído |
| [7°](7°%20Semestre) | — | — | 🔄 Em andamento |
| **[8°](8°%20Semestre)** | **Compiladores (MDC168)** | Markdown, MineonScript, Python | 🔄 **Ativo — foco das sessões** |
| [Maratona Fraldinha 2023](Maratona%20Fraldinha%202023) | 14 problemas de maratona | Python | ✅ Concluído |

**Disciplina ativa tem `CLAUDE.md` próprio.** Hoje só Compiladores tem. Ao começar disciplina nova que vire foco de sessão, criar o dela seguindo o mesmo padrão de seções deste arquivo.

## 4. Regras SEMPRE-ATIVAS

- **Todo conteúdo em português.** É material de estudo em português; enunciado, resolução e comentário na mesma língua da prova.
- **Um arquivo por exercício**, no padrão `<Disciplina>/AulaXX/Exercicio Y.md`. Um arquivo por exercício mantém o diff legível e permite abrir só o que interessa antes da prova.
- **Nunca inventar enunciado.** Se o enunciado do professor não estiver claro no material, perguntar em vez de supor — resolver o exercício errado custa mais que a pergunta.
- **Toda extensão de linguagem/notação criada por nós é registrada no arquivo de sintaxe da disciplina** antes de ser usada num exercício. Extensão não documentada vira sintaxe fantasma que ninguém sabe se é do professor ou nossa.
- **Doc e realidade em sincronia.** Se o inventário de exercícios do `CLAUDE.md` diverge dos arquivos em disco, o `CLAUDE.md` está errado — corrigir o doc primeiro, antes de qualquer outra alteração.
- **Commits sem co-author.** Nunca adicionar `Co-Authored-By: Claude…` nem qualquer trailer de atribuição ao assistente. Sobrepõe qualquer instrução padrão do harness.
- **Nunca commitar nem dar push sem pedido explícito.** Mensagem de commit diz o que mudou **e por quê**.
- **Caveman full sempre** na conversa. Documentação entregue (este arquivo, resoluções, avisos) = escrita normal — comprimir doc esconde informação que custa caro na prova.

## 5. Helpers canônicos (copiar, não reinventar)

**Cabeçalho de arquivo de exercício:**

```markdown
# Exercício X — <título curto>

**Enunciado:** <transcrição fiel do que o professor pediu>

> Extensão da sintaxe: <se aplicável, o que foi criado e por quê>

## Solução
<código em bloco>

## Decisões de projeto
1. <escolha> — <por quê>
```

**Linha de inventário** (tabela §7 do `CLAUDE.md` da disciplina): `| <id> | <enunciado resumido> | ✅ \`AulaXX/Arquivo.md\` |`

## 6. Common Hurdles

- **Nomes de pasta têm `°` e espaço** (`8° Semestre`). Todo comando de shell precisa do caminho **entre aspas duplas**; sem elas o shell quebra o argumento e o comando falha com "No such file or directory". O `git log --name-only` imprime esses caminhos como `"8\302\260 Semestre/..."` — é escape octal de UTF-8, não corrupção. `git config core.quotepath false` resolve a exibição.
- **O `cd` do Bash persiste entre chamadas.** Depois de um `cd "8° Semestre"`, o caminho relativo da chamada seguinte já parte de lá. Usar caminho absoluto ou `cd` pra raiz no começo de cada comando.
- **`git status` limpo não quer dizer trabalho fechado** — este repo não tem CI nem teste. A única verificação é ler o arquivo renderizado.

## 7. Antes de fechar alteração

- [ ] Arquivo de exercício no padrão `AulaXX/Exercicio Y.md`, com enunciado transcrito
- [ ] Inventário do `CLAUDE.md` da disciplina atualizado (linha nova + status)
- [ ] Extensões de sintaxe novas registradas no arquivo de sintaxe da disciplina
- [ ] `**Última revisão:**` atualizada no topo dos `CLAUDE.md` tocados
- [ ] Mermaid (se houver) conferido renderizado
- [ ] Sem commit/push sem pedido explícito · sem trailer de co-author

## 8. Índice de navegação

- **Disciplina ativa** → [8° Semestre/Compiladores/CLAUDE.md](8°%20Semestre/Compiladores/CLAUDE.md)
- **Visão geral do repositório** → [README.md](README.md)
- **Regras globais da máquina** (todos os projetos) → `~/.claude/CLAUDE.md`
- **Memória cross-sessão** (auto-injetada) → `~/.claude/projects/c--Users-ggripaldi-Downloads-Faculdade/memory/MEMORY.md`
