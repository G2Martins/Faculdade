# Teste 4 — Tokenizer (Google Forms) — Gabarito

**Resultado:** 6/6 · conteúdo = [Aula 04.pdf](Aula%2004.pdf) (Material 3 — Tokenizer / Código Lexer) e o exercício entregue em [lexer.py](lexer.py).

---

## Gabarito

| # | Questão | Resposta |
|---|---|---|
| 1 | Qual é a função principal de um tokenizer? | Identificar e classificar partes do código como palavras-chave, símbolos ou valores |
| 2 | O que significa o quantificador `*?` em `"​.*?"`? | Captura de forma não gulosa (lazy), parando no primeiro fechamento de aspas |
| 3 | Função ou necessidade de compilar um padrão de *regular expression* | Comparar os tokens de forma mais eficiente |
| 4 | O que acontece se o lexer encontrar um caractere inesperado? | Lança uma exceção `SyntaxError` |
| 5 | O que é um lexer? | Um programa que divide o código em tokens |
| 6 | De uma forma geral, qual é o token ignorado pelo lexer? *(caixa de seleção)* | **`ESPACO` e `COMENTARIO`** — os dois |

## As três que valem explicação

**Q2 — `*?` é lazy.** Sem o `?`, o `.*` seria guloso e engoliria tudo até a **última** aspa da linha: `"a" + "b"` viraria um único TEXTO. Com `*?` o motor para no primeiro fechamento e devolve dois tokens TEXTO, que é o comportamento correto. O cheat sheet de regex define assim: *"match the minimum number of times — known as a lazy quantifier"*.

**Q3 — por que compilar a regex.** `re.compile` lê o padrão caractere a caractere, valida a sintaxe e o converte em **autômato** (máquina de estados finitos com estado inicial, transições e estado de aceitação). Isso acontece uma vez, fora do laço; sem a compilação prévia o padrão seria reinterpretado a cada posição do código-fonte. Por isso a alternativa certa é a que fala em comparar os tokens de forma mais eficiente — é a única que menciona desempenho.

**Q6 — a pegadinha: são DOIS tokens, não um.** O enunciado usa singular ("qual é o token ignorado"), mas é caixa de seleção e exige `ESPACO` **e** `COMENTARIO`. Marcar só `ESPACO` dá 0/1.

O fragmento do slide (página 4 do PDF) tem apenas `if tipo != "ESPACO"` e induz ao erro — mas aquele é o **tradutor incompleto**. O item C do próprio exercício manda reconhecer comentário de linha e exibi-lo somente com a flag `-coment`, o que significa que no comportamento padrão do lexer terminado o comentário também é descartado. É o que o nosso [lexer.py](lexer.py) faz:

```python
DESCARTADOS = {"ESPACO", "COMENTARIO"}
```

O critério é o mesmo para os dois: nem espaço nem comentário carregam significado para o parser. A diferença está em que o comentário precisa continuar sendo **reconhecido** pela regex mesmo quando descartado — se o padrão não fosse testado, o `//` cairia no `raise SyntaxError` e o programa morreria em qualquer arquivo comentado.

## Para a P1

- `*?` = lazy · `*` = greedy. Em token de string sempre lazy.
- `re.compile` = padrão vira autômato (MEF), uma vez só, fora do laço.
- Caractere que não casa com nenhum padrão = `SyntaxError`, nunca "ignora e continua".
- Tokens descartados pelo lexer: **espaço e comentário**.
