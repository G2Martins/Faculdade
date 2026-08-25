# Exercício — Lexer / Tokenizer do MineonScript (Aula 04)

**Enunciado:**

> **A.** Implemente os fragmentos apresentados anteriormente em um tradutor incompleto para a análise léxica de um código em arquivo `.mines`.
>
> **B.** Acrescente ao código os tokens para reconhecimento de: 1. Comentário de Linha (`//`); 2. Multiplicação (`*`); 3. Divisão (`/`); 4. Leia; 5. Maior, Menor e negação.
>
> **C.** Ao executar o programa, por intermédio do argumento `-coment`, ele deve considerar os Comentários de Linha de código.

**Entrega:** [lexer.py](lexer.py) (tradutor) · [exemplo.mines](exemplo.mines) (arquivo de teste)

---

## Como executar

```bash
python lexer.py exemplo.mines            # comentários descartados (padrão)
python lexer.py exemplo.mines -coment    # comentários entram no fluxo de tokens
```

Saída: uma linha por token, com número da linha, tipo e lexema, e o total no fim.

---

## A. Os fragmentos do slide, montados

O Material 3 traz três pedaços soltos. O tradutor junta os três e adiciona só a casca que faltava (ler o arquivo, tratar argumento, imprimir).

| Fragmento do slide | Onde ficou |
|---|---|
| Lista `TOKENS` (nome, padrão) | `TOKENS` em [lexer.py](lexer.py) |
| `compilar_tokens()` — `re.compile` de cada padrão | `compilar_tokens()`, idêntico ao slide |
| Laço `while pos < len(codigo)` com `padrao.match(codigo, pos)` | `analisar()` |

O laço é o coração e vale entender antes de mexer:

```python
while pos < len(codigo):
    match = None
    for tipo, padrao in TOKENS_COMP:     # varre a lista DE CIMA PARA BAIXO
        match = padrao.match(codigo, pos)  # tenta casar ancorado na posição atual
        if match:
            ...
            pos = match.end(0)           # avança o cursor pelo tamanho do lexema
            break                        # PRIMEIRO que casar vence
    if not match:
        raise SyntaxError(...)           # nenhum padrão casou = caractere ilegal
```

Duas propriedades saem daí, e são a origem de tudo que vem depois:

1. **`padrao.match(codigo, pos)` é ancorado** — tenta casar exatamente na posição `pos`, não procura adiante (isso seria `search`). É o que faz o lexer varrer o texto da esquerda para a direita sem pular caractere.
2. **O primeiro padrão que casa vence** (`break`). Não existe "escolhe o casamento mais longo". Logo **a ordem da lista `TOKENS` é a regra de desempate** — e um padrão que é prefixo de outro tem que vir depois dele.

## B. Os tokens acrescentados

A ordem em que eles entram não foi inventada: o `TOKENS_FONTE` do **Material 3 (Aula 03)** já mostrava a lista completa do professor, e ela foi cortada exatamente em `SUB` — que é onde `MULT` e `DIV` entram. Os novos tokens foram encaixados nas posições que aquela lista indica.

| # | Token | Padrão | Posição na lista | Por quê ali |
|---|---|---|---|---|
| 1 | `COMENTARIO` | `r"//.*"` | **1º, antes de tudo** | `//` é prefixo de `/`. Ver prova abaixo. |
| 2 | `MULT` | `r"\*"` | depois de `SUB` | `*` é metacaractere de regex (repetição) — precisa do escape `\*` |
| 3 | `DIV` | `r"/"` | depois de `MULT` | tem que vir **depois** de `COMENTARIO` |
| 4 | `LEIA` | `r"\bleia\b"` | depois de `ESCREVA` | mesma posição do `TOKENS_FONTE` da Aula 03 |
| 5 | `MAIOR` | `r">"` | depois de `IGUAL` | idem |
| 6 | `MENOR` | `r"<"` | depois de `MAIOR` | idem |
| 7 | `NEGACAO` | `r"!"` | depois de `MENOR` | idem |

### Por que `COMENTARIO` tem que vir antes de `DIV` — prova

Se `COMENTARIO` for colocado depois de `DIV`, o lexer chega em `//`, testa `DIV` primeiro, casa com a primeira barra e para. Rodando os dois cenários sobre a entrada `// comentario\nx = 4 / 2\nretorna 0`:

```
ordem CORRETA  (COMENTARIO antes de DIV):
  NOME IGUAL NUMERO DIV NUMERO RETORNO NUMERO

ordem QUEBRADA (COMENTARIO depois de DIV):
  DIV DIV NOME NOME IGUAL NUMERO DIV NUMERO RETORNO NUMERO
   ^^^^^^^^^^^^^^^ o comentário vazou como lixo no fluxo de tokens
```

O comentário virou `DIV DIV NOME NOME` e seguiu para o parser, que vai reclamar de um erro de sintaxe numa linha onde não há erro nenhum. **É o mesmo princípio do `IGUALDADE` antes de `IGUAL`** que já estava no slide — o professor deu o exemplo, o exercício cobra a aplicação.

### Por que `NOME` fica em último

`NOME` (`[a-zA-Z_][a-zA-Z0-9_]*`) casa com qualquer palavra reservada também — `se`, `escreva` e `retorna` são todos identificadores válidos pela regex. Se `NOME` subisse na lista, **nenhuma palavra reservada seria reconhecida**: viraria tudo `NOME`.

### O papel do `\b` nas palavras reservadas

`\b` é âncora de fronteira de palavra. É o que separa a palavra reservada do identificador que começa igual:

```
sexo = 1          →  NOME('sexo')          ✅  \bse\b não casa: não há fronteira entre "se" e "xo"
se sexo > 0 { }   →  SE   NOME('sexo') ...  ✅
```

Sem o `\b`, o padrão `r"se"` casaria com o começo de `sexo` e o lexer emitiria `SE` + `NOME('xo')` — uma variável partida ao meio. Testado, é o comportamento correto acima.

## C. O argumento `-coment`

Comentário é informação para humano, não para o compilador: o padrão de um lexer é **descartar** comentário junto com espaço em branco. Por isso o comportamento normal do programa joga fora, e `-coment` é que liga a inclusão.

A implementação reaproveita o mecanismo que o slide já usava para o `ESPACO` (`if tipo != "ESPACO"`), só que generalizado para um conjunto:

```python
DESCARTADOS = {"ESPACO", "COMENTARIO"}
...
descartados = DESCARTADOS - {"COMENTARIO"} if manter_comentario else DESCARTADOS
if tipo not in descartados:
    tokens.append((tipo, match.group(0), linha))
```

Repare que o comentário é **sempre reconhecido** — o que muda é só se ele é guardado. Tem que ser assim: se o padrão não fosse testado, o `//` cairia no `raise SyntaxError` e o programa morreria em qualquer arquivo comentado.

Verificação no [exemplo.mines](exemplo.mines), que tem 4 comentários:

```
python lexer.py exemplo.mines             →  91 tokens
python lexer.py exemplo.mines -coment     →  95 tokens   (91 + 4 COMENTARIO)
```

---

## Decisões de projeto

1. **O token carrega o lexema, não só o tipo.** O fragmento do slide faz `tokens.append(tipo)`, guardando só o nome. Isso perde a informação de *qual* número ou *qual* nome de variável foi lido — e sem isso o parser da próxima etapa não consegue montar a AST (`NUMERO NUMERO` não diz se é `2 + 3` ou `7 + 9`). A lista guarda `(tipo, lexema, linha)`.

2. **Erro léxico informa linha e coluna.** O slide levanta `SyntaxError` com o caractere. Recuperação de erro léxico é conteúdo da ementa (aula de 18/08), e apontar a posição é o mínimo útil: `Caractere inesperado: '@' (linha 2, coluna 7)`. As duas contas saem de `codigo.count("\n", 0, pos)` e `codigo.rfind("\n", 0, pos)` — uma linha cada, sem precisar rastrear estado no laço.

3. **Sem `argparse`.** Um único flag posicional-livre não paga o custo de configurar um parser de argumentos; `"-coment" in sys.argv` resolve. Além disso `-coment` (traço simples + palavra) não é o estilo que o `argparse` assume por padrão.

4. **Saída em tabela com número de linha.** É o que se olha para conferir a olho se o lexer acertou. Total no rodapé porque a verificação do item C é uma diferença de contagem.

5. **Erros vão para `stderr` e o programa sai com código 1.** Permite encadear o lexer com o parser depois (`python lexer.py x.mines && python parser.py ...`) sem que uma falha passe despercebida.

---

## Saída (trecho, `exemplo.mines`)

```
LINHA  TOKEN         LEXEMA
    4  LEIA          'leia'
    4  ABRE_PAR      '('
    4  NOME          'n1'
    4  FECHA_PAR     ')'
    6  NOME          'media'
    6  IGUAL         '='
    6  ABRE_PAR      '('
    6  NOME          'n1'
    6  SOMA          '+'
    6  NOME          'n2'
    6  FECHA_PAR     ')'
    6  DIV           '/'
    6  NUMERO        '2'
    8  SE            'se'
    8  NOME          'media'
    8  IGUALDADE     '=='
    8  NUMERO        '10'
    8  ABRE_CHAVE    '{'
    9  ESCREVA       'escreva'
    9  ABRE_PAR      '('
    9  TEXTO         '"Nota maxima!"'
    9  FECHA_PAR     ')'
   10  FECHA_CHAVE   '}'
   ...

91 tokens reconhecidos.
```

Casos verificados: os 24 tokens exercitados pelo `exemplo.mines` · `-coment` incluindo os 4 comentários · palavra reservada vs. identificador (`sexo`) · caractere ilegal (`@`) com linha/coluna · arquivo inexistente · argumento faltando.

---

## Observações para as próximas aulas

1. **`escreva`/`leia` é o dialeto oficial do lexer.** O BNF do Material 3 escreve as mesmas instruções como `print`/`input`, mas as duas listas de tokens do professor (Aula 03 e Aula 04) usam `ESCREVA`/`LEIA`. Para o tradutor, vale o lexer. Ver [Aula03/Questionario.md](../Aula03/Questionario.md), observação 2.

2. **Faltam tokens para fechar a gramática do Material 3.** O `<condicional>` do BNF usa `senao`, que está na lista, mas não há token para vírgula (`,`) nem para os operadores `>=` / `<=` (que também não existem no BNF — a gramática só tem `==`, `<`, `>`). Se a gramática crescer, `>=` e `<=` têm que entrar **antes** de `MAIOR` e `MENOR`, pela mesma regra de prefixo do `COMENTARIO`.

3. **`TEXTO` não atravessa linha.** O padrão `r"\".*?\""` usa `.`, que não casa `\n`. String aberta e não fechada na mesma linha cai no erro léxico — comportamento aceitável, mas a mensagem fala em "caractere inesperado `\"`", que não é o diagnóstico mais claro. Melhorar quando entrar recuperação de erros.

4. **Próximo passo é o parser.** O lexer entrega a lista de tokens; a etapa seguinte consome essa lista e monta a AST seguindo o BNF do Material 3. É por isso que a decisão 1 (guardar o lexema) importa agora.
