# Resumo P2 — Compiladores (Material 6 + Material 7)

**Prova:** P2 em **24/11/2026** · 16 questões × 0,50 = 8,00 pontos · **Q1–Q6 = Material 6** (Geração de Código) · **Q7–Q16 = Material 7** (CST), sendo as 4 últimas de desenhar ou ler árvore.

**Base deste resumo:** slides dos Materiais 5, 6 e 7 (PDFs em `Aula05/`, `Aula06/`, `Aula07/`), o código do Material 7 (executado), o Teste 6, o [Teste 7](../Aula07/Aula07%20Teste%207%20-%20Gabarito.md) e os três simulados desta pasta.

**Como usar:** ler as Partes 1 a 12 → resolver a Parte 13 (os 48 exercícios dos simulados) sem olhar → corrigir pela Parte 14 (gabarito unificado). Cada linha do gabarito diz qual parte do resumo resolve a questão.

> **Legenda de fonte:** **[M5] [M6] [M7]** = slides do professor · **[cód. M7]** = conferido rodando o código do Material 7 em 2026-11-14 · **[gab.]** = gabarito dos simulados. O repositório não tem o código completo do gerador do Material 6, então as regras de tradução da Parte 6 vêm dos trechos do slide somados aos gabaritos, que o autor dos simulados conferiu executando o transpilador.

---

## Parte 1 — O pipeline e os tipos de tradutor

| Fase | Produto | No transpilador MineonScript |
|---|---|---|
| Análise léxica (lexer / tokenizer) | lista de tokens | ✅ |
| Análise sintática (parser) | AST — no Material 7: CST → AST | ✅ |
| Análise semântica | checa tipos, variáveis não declaradas, escopo | ❌ **indisponível** [M6] |
| Geração de código | código na linguagem destino | ✅ (Python) |

Como as etapas se comunicam [gab. S3Q5]:

```python
tokens = lexer(codigo)                     # texto        → lista de tuplas (TIPO, VALOR)
ast    = Parser(tokens).parse_programa()   # tokens       → raiz da AST: NoAST do tipo PROGRAMA
python = transpilador_python(ast)          # AST          → texto do programa Python
```

**Tipos de tradutor** (cai em "qual alternativa descreve o transpilador" e "qual ferramenta é transpilador"):

| Ferramenta | O que faz | Exemplo |
|---|---|---|
| **Compilador** | alto nível → código de máquina / Assembly | GCC gerando código de máquina a partir de C |
| **Transpilador** (*source-to-source*) | alto nível → **outro alto nível**, mesma lógica | **MineonScript → Python**; **Babel** (JavaScript ES2015+ → JavaScript antigo) |
| **Interpretador** | executa linha a linha, sem gerar código em outra linguagem | CPython executando um script |
| **Montador** (*assembler*) | Assembly → código de máquina | — |
| **Ligador** (*linker*) | junta arquivos objeto num executável | — |

O objetivo do **gerador** num transpilador é traduzir a AST para outra linguagem de alto nível **mantendo o comportamento equivalente** — não otimizar registradores nem checar tipos [Teste 6].

---

## Parte 2 — O lexer do Material 6

**Funções do lexer [M6]:** agrupar caracteres em lexemas · categorizar cada lexema num tipo de token · **filtrar o ruído** (espaços, quebras de linha, comentários) · detectar erros léxicos.

Tabela `TOKENS` da versão final [M6]:

```python
TOKENS = [
    ("COMENTARIO", r"//.*"),      ("ESPACO",   r"\s+"),
    ("SE",       r"\bse\b"),      ("SENAO",    r"\bsenao\b"),
    ("ENQUANTO", r"\benquanto\b"),("ESCREVA",  r"\bescreva\b"),
    ("LEIA",     r"\bleia\b"),    ("RETORNO",  r"\bretorna\b"),
    ("IGUALDADE", r"=="),         ("IGUAL",    r"="),
    ("MAIOR", r">"), ("MENOR", r"<"), ("NEGACAO", r"!"),
    ("SOMA", r"\+"), ("SUB", r"-"), ("MUL", r"\*"), ("DIV", r"/"),
    ("ABRE_CHAVE", r"\{"), ("FECHA_CHAVE", r"\}"),
    ("ABRE_PAR", r"\("),   ("FECHA_PAR", r"\)"),
    ("NUMERO", r"\d+"), ("TEXTO", r"\".*?\""),
    ("NOME", r"[a-zA-Z_][a-zA-Z0-9_]*"),
]
```

O que cobra prova:

- **A ordem da lista é regra de desempate.** O laço para no **primeiro** padrão que casa: `COMENTARIO` (`//`) vem antes de `DIV` (`/`), `IGUALDADE` (`==`) antes de `IGUAL` (`=`), e `NOME` por último (senão engoliria `se`, `escreva`…).
- **`ESPACO` e `COMENTARIO` são reconhecidos e descartados** — não entram na lista de tokens. Por isso um comentário `//` **nunca chega à AST nem ao Python**; a única linha `#` do Python gerado é o cabeçalho fixo [gab. S1Q5].
- **Saída = lista de tuplas `(TIPO, VALOR)`**; o parser lê `tipo, valor = self.token_atual` [M6].
- **Tipo de token ≠ tipo de nó.** `NOME`, `ESCREVA`, `SOMA` são **tokens**; `IDENTIFICADOR`, `SAIDA`, `EXPRESSAO` são **nós da AST** [gab. S3Q2].
- Exemplo: `escreva(n + 1)` → `ESCREVA, ABRE_PAR, NOME, SOMA, NUMERO, FECHA_PAR` (6 tokens, nenhum `ESPACO`).
- **Erro léxico:** caractere que não casa com nenhum padrão → `SyntaxError: Caractere inesperado: '@' na posição 6`. A posição conta do zero: em `x = 2 @ 3`, `x`=0, espaço=1, `=`=2, espaço=3, `2`=4, espaço=5, `@`=**6**.

---

## Parte 3 — A gramática e o parser

### BNF dos Materiais 6 e 7

```text
<programa>   ::= <instrucoes> <retorno>
<instrucoes> ::= <instrucao> | <instrucao> <instrucoes>
<instrucao>  ::= <atribuicao> | <saida> | <entrada> | <condicional> | <loop>
<atribuicao> ::= NOME IGUAL <expressao>
<saida>      ::= ESCREVA ABRE_PAR <expressao> FECHA_PAR
<entrada>    ::= NOME IGUAL LEIA ABRE_PAR TEXTO FECHA_PAR
<condicional>::= SE <condicao> ABRE_CHAVE <instrucoes> FECHA_CHAVE
               | SE <condicao> ABRE_CHAVE <instrucoes> FECHA_CHAVE
                 SENAO ABRE_CHAVE <instrucoes> FECHA_CHAVE
<loop>       ::= ENQUANTO <condicao> ABRE_CHAVE <instrucoes> FECHA_CHAVE
<condicao>   ::= <expressao> <operador_relacional> <expressao>
               | NEGACAO <condicao>
<operador_relacional> ::= IGUALDADE | MENOR | MAIOR
<expressao>  ::= <termo> | <expressao> SOMA <termo> | <expressao> SUB <termo>
<termo>      ::= <fator> | <termo> MUL <fator> | <termo> DIV <fator>
<fator>      ::= NUMERO | NOME | ABRE_PAR <expressao> FECHA_PAR
<retorno>    ::= RETORNO NUMERO
```

O código dos dois materiais também aceita `TEXTO` como `<fator>` (é o que permite `escreva("VALOR INVALIDO")`).

**A mesma gramática em EBNF** (forma usada no código do Material 7):

```text
<expressao> ::= <termo> { ( SOMA | SUB ) <termo> }
<termo>     ::= <fator> { ( MUL | DIV ) <fator> }
```

A recursão à esquerda da BNF (`<expressao> SOMA <termo>`) e a repetição `{ }` da EBNF descrevem a mesma linguagem. O parser por **descida recursiva** (escrito à mão, um método por regra) não consegue chamar a si mesmo à esquerda, então implementa a repetição com um `while` — e é esse laço que monta a árvore **inclinada à esquerda** (Parte 7).

### O parser do Material 6

Métodos [M6]: `__init__`, `consumir(tipo_esperado)`, `parse_programa`, `parse_instrucoes`, `parse_instrucao`, `parse_atribuicao_ou_entrada`, `parse_saida`, `parse_condicional`, `parse_loop`, `parse_condicao`, `parse_expressao`, `parse_termo`, `parse_fator`, `parse_retorno`.

```python
def parse_fator(self):                     # [M6]
    tipo, valor = self.token_atual
    if tipo == "NUMERO":
        self.consumir("NUMERO");  return NoAST("NUMERO", valor=valor)
    elif tipo == "NOME":
        self.consumir("NOME");    return NoAST("IDENTIFICADOR", valor=valor)
    elif tipo == "TEXTO":
        self.consumir("TEXTO");   return NoAST("TEXTO", valor=valor)
    elif tipo == "ABRE_PAR":
        self.consumir("ABRE_PAR")
        exp = self.parse_expressao()
        self.consumir("FECHA_PAR")
        return exp                          # ← os parênteses não viram nó
```

**As 3 funções do parser [M6]:** validar a gramática (tokens na ordem certa) · construir a AST (lista linear → árvore) · mapear a precedência (valores prioritários em **nós mais fundos**).

### Consequências da gramática (pegadinhas certas)

1. **`retorna` é obrigatório no fim.** Sem ele: erro sintático `Esperado 'RETORNO', mas encontrado 'EOF'` [gab. S3Q6]. O lexer não reclama (não existe "token obrigatório" para o lexer).
2. **`retorna` aceita só número:** `retorna 0` ✅ · `retorna x` ❌ · `retorna x + 1` ❌.
3. **Negação sem parênteses:** `se ! x > 5 {` ✅. `se !(x > 5) {` ❌ **erro sintático** — `( )` só envolve `<expressao>`, nunca `<condicao>` [cód. M7: `esperado 'FECHA_PAR', encontrado 'IGUALDADE'` para `!(x == y)`]. Logo, "diferente" se escreve `! x == y`.
4. **Só três operadores relacionais:** `==`, `<`, `>` (não há `!=`, `>=`, `<=`).
5. **`leia` só existe dentro de atribuição:** `n = leia("Idade: ")`. `leia("x")` sozinho não deriva.
6. **Depois de `+` a gramática exige um `<termo>`:** `escreva(x + )` → erro sintático `Fator inesperado com token 'FECHA_PAR'` [gab. S2Q2].

---

## Parte 4 — Erros: léxico × sintático × semântico

| Tipo [M5] | Definição | Exemplos do slide |
|---|---|---|
| **Léxico** | símbolo ou palavra que não pertence ao vocabulário da linguagem | `prnt("Olá mundo")`, `int número# = 10;`, `floatt x = 5.0;` |
| **Sintático** | viola as regras gramaticais (a estrutura) | `if x > 10` sem `:` (Python), falta `;` (Java), `int main( {` (C) |
| **Semântico** | sintaticamente válido, mas sem sentido / não faz o que se queria | `"10" + 5`, divisão por zero, `if (idade = 18)` em C |

**Casos MineonScript que caem:**

| Programa | Onde a tradução para | O que acontece |
|---|---|---|
| `x = 2 @ 3` | **lexer** | `Caractere inesperado: '@' na posição 6` |
| `escreva(x + )` | **parser** | `Fator inesperado com token 'FECHA_PAR'` — os tokens existem, a ordem é que não vale |
| programa sem `retorna 0` | **parser** | `Esperado 'RETORNO', mas encontrado 'EOF'` |
| `x = (2 + 3` | **parser** | `esperado 'FECHA_PAR', encontrado 'EOF'` [cód. M7] |
| `se !(x == y) { … }` | **parser** | `esperado 'FECHA_PAR', encontrado 'IGUALDADE'` [cód. M7] |
| `escreva(total)` sem `total` antes | **nenhuma** — traduz sem erro | `NameError` só ao **executar** o Python |
| `x = "texto" + 10` | **nenhuma** — o parser aceita | erro de tipo só ao executar o Python [Teste 6] |
| comentário `// …` | nenhuma | descartado pelo lexer |

**Regra de bolso:** caractere que não existe na linguagem → **léxico**. Tokens que existem, em ordem errada → **sintático**. Tudo válido mas sem sentido → **semântico** — e como o MineonScript **não tem análise semântica**, esse erro passa pela transpilação e só estoura no Python, em tempo de execução.

---

## Parte 5 — A AST

```python
class NoAST:                                    # [M5]
    def __init__(self, tipo, valor=None, filhos=None):
        self.tipo = tipo
        self.valor = valor
        self.filhos = filhos if filhos is not None else []

    def __repr__(self, level=0):                # imprime [TIPO: valor] com recuo
        ret = "  " * level + f"[{self.tipo}"
        if self.valor is not None:
            ret += f": {self.valor}"
        ret += "]\n"
        for filho in self.filhos:
            ret += filho.__repr__(level + 1)
        return ret
```

| Nó | `valor` | Filhos |
|---|---|---|
| `PROGRAMA` | — | `[INSTRUCOES, RETORNO]` |
| `INSTRUCOES` | — | um por instrução |
| `ATRIBUICAO` | `"="` | `[IDENTIFICADOR, expressão]` |
| `ENTRADA` | — | `[IDENTIFICADOR, TEXTO]` |
| `SAIDA` | — | `[expressão]` |
| `CONDICIONAL` | — | `[CONDICAO, INSTRUCOES]` ou, com `senao`, `[CONDICAO, INSTRUCOES, INSTRUCOES]` |
| `LOOP` | — | `[CONDICAO, INSTRUCOES]` |
| `CONDICAO` | `"=="`, `"<"`, `">"` ou `"!"` | `[esq, dir]` — ou `[CONDICAO]` quando é `"!"` |
| `EXPRESSAO` | `"+"`, `"-"`, `"*"`, `"/"` | `[esq, dir]` |
| `NUMERO` / `IDENTIFICADOR` / `TEXTO` | o lexema | — |
| `RETORNO` | o número | — |

**O que a AST joga fora:** parênteses (a precedência vira profundidade) · chaves · o `=` (vira o `valor` de `ATRIBUICAO`) · palavras-chave (viram o **tipo** do nó: `escreva` → `SAIDA`) · as cadeias unitárias `<instrucao>`, `<expressao>`, `<termo>`, `<fator>` · espaços e comentários.

---

## Parte 6 — O gerador `transpilador_python`

Trecho oficial [M6]:

```python
def transpilador_python(no, nivel_indentacao=0):
    indent = "    " * nivel_indentacao          # 4 espaços por nível
    if no.tipo == "PROGRAMA":
        codigo_py = "# Código gerado via Transpilador MineonScript\n\n"
        for filho in no.filhos:
            codigo_py += transpilador_python(filho, nivel_indentacao)
        return codigo_py
    elif no.tipo == "INSTRUCOES":
        codigo_py = ""
        for filho in no.filhos:
            codigo_py += transpilador_python(filho, nivel_indentacao)
        return codigo_py
    elif no.tipo == "ATRIBUICAO":
        var_nome = no.filhos[0].valor
        exp = transpilador_python(no.filhos[1])
        return f"{indent}{var_nome} = {exp}\n"
    # ... demais nós: tabela abaixo
```

**É recursivo:** para traduzir um nó, chama `transpilador_python` sobre os filhos [gab. S1Q1].

| Nó | Python gerado |
|---|---|
| `PROGRAMA` | `# Código gerado via Transpilador MineonScript` + linha em branco + filhos |
| `INSTRUCOES` | os filhos, um após o outro, no mesmo nível |
| `ATRIBUICAO` | `x = <exp>` |
| `ENTRADA` | `n = input("Idade: ")` |
| `SAIDA` | `print(<exp>)` |
| `CONDICIONAL` | `if <cond>:` + bloco no nível + 1; com 3º filho, `else:` + bloco — **nunca `elif`** |
| `LOOP` | `while <cond>:` + bloco no nível + 1 |
| `CONDICAO` com operador | `<esq> <op> <dir>` — **sem parênteses** |
| `CONDICAO` com `"!"` | `not (<cond>)` |
| `EXPRESSAO` | `(<esq> <op> <dir>)` — **sempre com parênteses** [gab. S3Q4: `return f"({esq} {no.valor} {dir})"`] |
| `NUMERO` / `IDENTIFICADOR` / `TEXTO` | o próprio valor (o texto mantém as aspas) |
| `RETORNO` | `exit(0)` |

**Exemplos que caem:**

| MineonScript | Python gerado |
|---|---|
| `i = i + 1` | `i = (i + 1)` |
| `x = 2 + 3 * 4` | `x = (2 + (3 * 4))` |
| `r = a * b + c * d` | `r = ((a * b) + (c * d))` |
| `escreva(x + 1)` | `print((x + 1))` — parênteses duplos: os do `print` + os da EXPRESSAO |
| `enquanto i < 3 {` | `while i < 3:` |
| `se ! x > 5 {` | `if not (x > 5):` |
| `enquanto ! n == 0 {` | `while not (n == 0):` |
| `n = leia("Idade: ")` | `n = input("Idade: ")` |
| `retorna 0` | `exit(0)` |

Programa completo (Simulado 1, Q2), traduzido pelas regras:

```python
# Código gerado via Transpilador MineonScript

i = 0
while i < 3:
    print(i)
    i = (i + 1)
exit(0)
```

**Indentação:** 4 espaços × nível. Dentro de um `while` = nível 1 = 4 espaços; dentro de um `if` que está dentro de um `while` = nível 2 = **8 espaços** [gab. S2Q3].

**Por que envolver toda EXPRESSAO em parênteses?** Para que a precedência representada pela **forma da AST** seja preservada no Python, mesmo que alguns parênteses fiquem redundantes [gab. S3Q4]. Não deixa o código mais rápido, o Python não exige, e nada é calculado na transpilação.

---

## Parte 7 — Precedência e associatividade

- **Precedência:** `*` e `/` ficam no `<termo>`, um nível mais fundo que `+` e `-` (`<expressao>`). Nó mais fundo = avaliado primeiro [M6, Teste 6]. O parser **não** reordena tokens nem calcula nada; ele só posiciona os nós.
- **Mesma precedência → agrupa pela esquerda** ("dobra à esquerda"). No `cst_para_ast` [cód. M7]:

```python
esq = cst_para_ast(f[0])
for i in range(1, len(f), 2):              # [operando, op, operando, op, operando ...]
    esq = NoAST("EXPRESSAO", f[i].token.texto, [esq, cst_para_ast(f[i + 1])])
```

| Instrução | AST (forma) | Python | Resultado |
|---|---|---|---|
| `z = 10 - 4 - 3` | `-( -(10, 4), 3 )` | `z = ((10 - 4) - 3)` | **3** (pela direita daria 9) |
| `q = 100 / 10 / 5` | `/( /(100, 10), 5 )` | `q = ((100 / 10) / 5)` | **2.0** — o `/` do Python devolve float (pela direita daria 50.0) |
| `x = 2 + 3 * 4` | `+( 2, *(3, 4) )` | `x = (2 + (3 * 4))` | 14 |
| `area = base * altura / 2` | `/( *(base, altura), 2 )` | `area = ((base * altura) / 2)` | — |

**Lendo uma AST de volta para a instrução — quando pôr parênteses:**

- um nó de **menor** precedência (`+`/`-`) **abaixo** de um de maior (`*`/`/`) → parênteses nele: `*( +(a, b), c )` = `(a + b) * c`;
- um nó de **mesma** precedência como **filho direito** → parênteses nele: `-( a, -(b, c) )` = `a - (b - c)`;
- fora isso, sem parênteses: `-( -(a, b), c )` = `a - b - c`.

---

## Parte 8 — CST: o que é e o lexer com prefixo

**CST (Árvore de Sintaxe Concreta)** = árvore que segue a gramática **ao pé da letra**: cada regra aplicada vira um nó e cada token vira uma folha. Também chamada **parse tree** ou **árvore de derivação** [M7].

**As 4 características [M7]:**

1. **Fiel à gramática** — um nó por regra aplicada, inclusive as de passagem (`<instrucao>`, `<termo>`).
2. **Guarda todos os tokens** — parênteses, chaves, `=` e palavras-chave viram folhas.
3. **Sem perdas (lossless)** — lendo as folhas da esquerda para a direita, recupera-se o código-fonte.
4. **Verbosa** — muitos nós desnecessários para o significado (é o motivo de existir a AST).

**A única diferença do lexer do Material 7:** espaços e comentários **não são jogados fora** — ficam no `prefixo` do **token seguinte** [cód. M7]:

```python
class Token:
    def __init__(self, tipo, texto, prefixo):
        self.tipo, self.texto = tipo, texto
        self.prefixo = prefixo                 # espaços e comentários que vieram ANTES dele

# dentro do lexer:
if tipo in ("ESPACO", "COMENTARIO"):
    prefixo += texto                           # acumula
else:
    tokens.append(Token(tipo, texto, prefixo))
    prefixo = ""                               # entrega ao token "de verdade" e zera
...
tokens.append(Token("EOF", "", prefixo))       # o que sobrou no fim do arquivo
```

**Onde fica cada pedaço** em `x =   5 // cinco`:

- os três espaços antes do `5` → `prefixo` do token `NUMERO "5"`;
- o espaço e o `// cinco` → `prefixo` do **próximo token real**. Na instrução isolada, o próximo é o **EOF** [gab. S3Q10]; num programa com `retorna 0` na linha de baixo, é o `RETORNO` [cód. M7].

Espaço e comentário **nunca viram nó** — nem na CST nem na AST. Viram texto dentro do atributo `prefixo` de uma folha.

**Lossless na prática** [cód. M7]:

```python
def para_texto(cst):
    return "".join(f.token.prefixo + f.token.texto for f in folhas(cst))
# o programa confere: "Sim, caractere por caractere."
```

**Refatoração pela CST** [cód. M7] — `renomear(cst, "x", "valor")` troca o texto **apenas das folhas `NOME` com texto `x`**; espaços, indentação e comentários ficam idênticos (exemplo da aba Refatoração do laboratório).

---

## Parte 9 — Da CST para a AST e a contagem de nós

O `ParserCST` tem um método por regra da BNF e cada um devolve um `NoCST` com **todos** os filhos. A função `cst_para_ast` [cód. M7] transforma:

| Nó da CST | Vira na AST |
|---|---|
| `<programa>` | `PROGRAMA [INSTRUCOES, RETORNO]` (a folha EOF é descartada) |
| `<instrucoes>` | `INSTRUCOES` |
| `<instrucao>` | **some** — cadeia unitária, devolve o filho |
| `<atribuicao>` | `ATRIBUICAO "="` com `[IDENTIFICADOR, expressão]` — `NOME` vira `IDENTIFICADOR`, o `IGUAL` some |
| `<entrada>` | `ENTRADA [IDENTIFICADOR, TEXTO]` |
| `<saida>` | `SAIDA [expressão]` — `ESCREVA` e os parênteses somem |
| `<condicional>` / `<loop>` | `CONDICIONAL` / `LOOP` — `SE`, `SENAO`, `ENQUANTO` e as chaves somem |
| `<condicao>` | `CONDICAO` com o operador (ou `"!"`) |
| `<expressao>` ou `<termo>` com **um** filho | **some** — só repassa o filho |
| `<expressao>` ou `<termo>` com operador | `EXPRESSAO <op>`, dobrando à esquerda |
| `<fator>` com `( … )` | **some** — os parênteses somem, devolve a expressão de dentro |
| `<fator>` simples | `NUMERO` / `IDENTIFICADOR` / `TEXTO` |
| `<retorno>` | `RETORNO <número>` |

- Um `<termo>` só vira `EXPRESSAO` quando tem **mais de um filho** (um `MUL`/`DIV` entre fatores) [gab. S3Q9].
- A AST sai igual à do Material 5 (mesma `NoAST`), então o `transpilador_python` do Material 6 funciona **sem alterações** sobre ela [gab. S1Q11].

### Contar nós sem desenhar a árvore inteira

**CST** = folhas + nós internos:

- **folhas** = número de tokens (palavra-chave, nome, número, operador, `=`, `(`, `)`);
- **internos** = `<instrucao>` + `<atribuicao>` (ou `<saida>`) + **1 `<expressao>` por expressão** (a principal + 1 por par de parênteses) + **1 `<termo>` por parcela** de `+`/`-` + **1 `<fator>` por operando** (inclusive o `( … )`).

**AST** = raiz (`ATRIBUICAO` + `IDENTIFICADOR`, ou só `SAIDA`) + **1 `EXPRESSAO` por operador** + **1 nó por operando**.

Exemplo — `escreva(a * (b + c) - d)`:
- tokens: `escreva ( a * ( b + c ) - d )` = 12 folhas;
- internos: 2 (`<instrucao>`, `<saida>`) + 2 expressões + 4 termos (`a * (b + c)` e `d` na de fora; `b` e `c` na de dentro) + 5 fatores (`a`, `(b + c)`, `b`, `c`, `d`) = 13;
- **CST = 25** · **AST** = 1 + 3 operadores + 4 operandos = **8**.

Todas conferidas no programa da aula [cód. M7]:

| Instrução | CST | AST |
|---|---|---|
| `x = 5` | 8 | 3 |
| `escreva(k)` · `escreva(total)` | 9 | 2 |
| `y = a * b` · `media = soma / 2` | 11 | 5 |
| `escreva(n * 2)` | 12 | 4 |
| `soma = x + 10` | 12 | 5 |
| `x = (7)` | 13 | 3 |
| `area = base * altura / 2` · `q = 100 / 10 / 5` | 14 | 7 |
| `total = preco * 3 + frete` · `saldo = saldo - taxa * 2` | 15 | 7 |
| `z = 10 - 4 - 3` | 16 | 7 |
| `x = 2 * (3 + 4)` · `y = (a + b) * c` · `w = (p + q) / r` | 20 | 7 |
| `escreva(x * (y - 2))` · `escreva(2 * (n - 1))` · `escreva((a + b) * 2)` | 21 | 6 |
| `d = a - (b - c)` | 21 | 7 |
| `escreva(a * (b + c) - d)` | 25 | 8 |

Repare: `x = (7)` tem 13 nós na CST porque os parênteses abrem uma **segunda cadeia** `<expressao> → <termo> → <fator>`; na AST sobram só `ATRIBUICAO`, `IDENTIFICADOR x` e `NUMERO 7` [gab. S3Q8]. E `x = 5` tem `<termo>` e `<fator>` mesmo sem multiplicação porque a CST registra **toda** regra aplicada, inclusive as de passagem [gab. S2Q7].

---

## Parte 10 — CST × AST, onde cada uma é usada e as ferramentas

| | **CST** | **AST** |
|---|---|---|
| Também chamada | parse tree / árvore de derivação | Árvore Sintática Abstrata |
| Segue | a gramática, regra por regra | o significado do programa |
| Pontuação `( ) { } =` | presente, como folhas | ausente |
| Nós de passagem | presentes (`<termo>`, `<fator>` …) | eliminados |
| Espaços e comentários | podem ser guardados (lossless) | descartados |
| Tamanho de `x = 2 * (3 + 4)` | 20 nós | 7 nós |
| Reconstrói o código? | sim, caractere por caractere | não |

> **"A CST responde *como está escrito?*; a AST responde *o que significa?*"** [M7]

| CST — quando o **texto** importa | AST — quando o **significado** importa |
|---|---|
| formatadores de código (Black, do Python) | análise semântica (tipos, escopo, variáveis) |
| realce de sintaxe e IDEs (Tree-sitter) | otimização (ex.: calcular `2 * 3` antes de rodar) |
| refatoração sem perder comentários (**LibCST**, **Roslyn** do C#) | geração de código (`transpilador_python`) |
| mensagens de erro com linha e coluna exatas | interpretadores (módulo `ast` do Python) |

**Geradores de parser (*parser generators*)** — recebem a gramática (BNF) e geram o parser automaticamente; o produto é um analisador que reconhece a entrada e monta a parse tree (CST) [M7]. No curso o parser é escrito **à mão** (descida recursiva), para enxergar cada nó.

| Ferramenta | O que lembrar |
|---|---|
| **YACC** | *"Yet Another Compiler-Compiler"* · Bell Labs, início dos anos 1970, no Unix · Stephen C. Johnson |
| **GNU Bison** | sucessor **livre e compatível** do YACC, do projeto GNU · gera parsers em C/C++ |
| **ANTLR** | *"ANother Tool for Language Recognition"* · **Terence Parr** · gera parsers em **Java, Python, C#** e outras · exibe a parse tree |

**Distratores recorrentes:** Babel = transpilador de JavaScript · LibCST e Roslyn = refatoração baseada em CST · pip = instalador de pacotes Python · o YACC **não** é sucessor do Bison (é o contrário) · o ANTLR **não** é sucessor do Bison nem do YACC.

---

## Parte 11 — Método para as 4 questões de árvore (Q13–Q16)

### A) Instrução → AST

1. Raiz: `[ATRIBUICAO: =]` com `[IDENTIFICADOR: nome]` como 1º filho — ou só `[SAIDA]` para `escreva(…)`.
2. Na expressão, ache o operador que é avaliado **por último**: o `+`/`-` **mais à direita** fora de parênteses; se não houver, o `*`/`/` mais à direita fora de parênteses. Ele é o nó de cima.
3. O que está à esquerda dele é o 1º filho; o que está à direita, o 2º. Repita em cada lado.
4. Parênteses que envolvem a expressão inteira de um lado: tire-os e continue.
5. Folhas: `[NUMERO: 3]` para número, `[IDENTIFICADOR: x]` para nome.

### B) AST → instrução

Leia em ordem (esquerda, operador, direita) e ponha parênteses pela regra da Parte 7: `+`/`-` abaixo de `*`/`/`, ou mesma precedência como filho direito.

### C) Instrução → CST

Modelo da atribuição (a saída troca `<atribuicao>` por `<saida>` com `ESCREVA "escreva"`, `ABRE_PAR "("`, `<expressao>`, `FECHA_PAR ")"`):

```text
<instrucao>
└── <atribuicao>
    ├── NOME "x"
    ├── IGUAL "="
    └── <expressao>        ← um <termo> por parcela de + / -, com SOMA/SUB entre eles
        └── <termo>        ← um <fator> por fator de * / /, com MUL/DIV entre eles
            └── <fator>    ← NUMERO / NOME, ou ABRE_PAR <expressao> FECHA_PAR
                └── NUMERO "5"
```

Checagem final: todo `NUMERO`/`NOME` tem um `<fator>` como pai; todo `<fator>` está dentro de um `<termo>`; todo `<termo>` dentro de uma `<expressao>`. Operadores da mesma expressão ficam **lado a lado como irmãos** (repetição `{ }` da EBNF), não aninhados. Confira o total com a contagem da Parte 9.

### D) CST → instrução

Leia **só as folhas**, da esquerda para a direita, e junte os textos entre aspas: `escreva` `(` `x` `*` `(` `y` `-` `2` `)` `)` → `escreva(x * (y - 2))`.

---

## Parte 12 — Pegadinhas (checklist da véspera)

- [ ] Lexer do **Material 6 descarta** espaço e comentário · lexer do **Material 7 guarda** no prefixo do **próximo token real** (o EOF só fica com o que sobra no fim).
- [ ] "São descartados, **como a AST faz**" é distrator — quem descarta é o lexer do Material 6.
- [ ] Espaço/comentário **nunca vira nó** (nem `ESPACO` nem `COMENTARIO` na AST/CST).
- [ ] Comentário MineonScript **não** vira `#` no Python; o único `#` é o cabeçalho.
- [ ] `senao` → `else` (não `elif`) · `!` → `not (...)` · `retorna 0` → `exit(0)` · `leia` → `input` · `escreva` → `print`.
- [ ] Condição do `if`/`while` **sem** parênteses; toda EXPRESSAO **com** parênteses.
- [ ] Recuo = 4 espaços por nível.
- [ ] O MineonScript **não tem análise semântica**: variável sem valor e `"texto" + 10` passam na transpilação.
- [ ] `@` → erro **léxico** · `x + )` → erro **sintático** · falta de `retorna` → erro **sintático** (`Esperado 'RETORNO', mas encontrado 'EOF'`).
- [ ] `!(x == y)` é erro sintático; o certo é `! x == y`.
- [ ] Mesma precedência agrupa **pela esquerda**: `10 - 4 - 3 = 3`, `100 / 10 / 5 = 2.0`.
- [ ] Parênteses **somem** na AST; a precedência vira profundidade.
- [ ] CST é **maior** que a AST e é a **sem perdas**; a AST nunca guarda prefixo.
- [ ] Na contagem: folhas = tokens; `x = 5` já tem 8 nós na CST; parênteses dobram a cadeia.
- [ ] CST = texto (Black, Tree-sitter, LibCST, Roslyn, erro com linha/coluna) · AST = significado (semântica, otimização, geração, interpretador).
- [ ] YACC (Bell Labs/Unix) → Bison (sucessor livre, GNU) · ANTLR (Terence Parr, várias linguagens) · Babel = transpilador.

---

## Parte 13 — Exercícios dos simulados

Os 48 exercícios dos três simulados, na íntegra. Resolva sem olhar e corrija pela Parte 14. Fontes: [Simulado 1](Aula08%20Simulado%201.md) · [Simulado 2](Aula08%20Simulado%202.md) · [Simulado 3](Aula08%20Simulado%203.md).

### Simulado 1

#### Questão 1 (0,50)

Sobre as etapas do transpilador MineonScript apresentadas no Material 6, analise as afirmações:

- I. O parser recebe a lista de tokens e devolve a AST.
- II. O transpilador MineonScript verifica se cada variável foi declarada antes de ser usada.
- III. O gerador percorre a AST recursivamente: para traduzir um nó, chama `transpilador_python` sobre os filhos dele.

Estão CORRETAS somente as afirmações:

- A. Apenas a I.
- B. Apenas a II.
- C. I e III.
- D. II e III.
- E. I, II e III.

#### Questão 2 (0,50)

Considere o programa MineonScript abaixo:

```text
i = 0
enquanto i < 3 {
    escreva(i)
    i = i + 1
}
retorna 0
```

No código Python gerado pelo transpilador, quais são, respectivamente, a linha do laço e a linha do incremento?

- A. `while (i < 3):` e `    i = i + 1`, com quatro espaços de recuo.
- B. `while i < 3:` e `i = (i + 1)`, sem recuo.
- C. `while i < 3 {` e `    i = (i + 1)`, mantendo as chaves.
- D. `while i < 3:` e `    i = (i + 1)`, com quatro espaços de recuo.
- E. `for i in range(3):` e `    i += 1`.

#### Questão 3 (0,50)

O gerador de código traduz cada tipo de nó da AST para uma construção Python.

Qual associação entre MineonScript e o Python gerado está INCORRETA?

- A. `escreva(x)` → `print(x)`
- B. `retorna 0` → `exit(0)`
- C. `senao` → `elif`
- D. `n = leia("Idade: ")` → `n = input("Idade: ")`
- E. `enquanto` → `while`

#### Questão 4 (0,50)

Na gramática do MineonScript, a negação é escrita antes da condição, sem parênteses: `<condicao> ::= NEGACAO <condicao>`.

```text
x = 7
se ! x > 5 {
    escreva("pequeno")
}
retorna 0
```

Qual linha Python é gerada para o `se`?

- A. `if !x > 5:`
- B. `if not (x > 5):`
- C. `if not x > 5:`
- D. `if (x > 5) == False:`
- E. Nenhuma: o MineonScript não aceita `!` antes de uma condição.

#### Questão 5 (0,50)

Um aluno documentou seu programa MineonScript com comentários `//` em várias linhas e, em seguida, o transpilou para Python.

O que acontece com esses comentários?

- A. Não aparecem no Python: o lexer descarta comentários e espaços, então eles nunca chegam à AST nem ao gerador.
- B. São convertidos em comentários Python iniciados por `#`.
- C. Viram strings dentro de chamadas `print`.
- D. Provocam um erro léxico, pois o lexer não reconhece `//`.
- E. São reunidos no topo do arquivo, logo após o cabeçalho gerado.

#### Questão 6 (0,50)

Compiladores, transpiladores e interpretadores tratam o código-fonte de formas diferentes.

Qual alternativa descreve corretamente o transpilador?

- A. Traduz o programa diretamente para código de máquina ou Assembly.
- B. Executa o programa linha a linha, sem gerar código em outra linguagem.
- C. Junta vários arquivos objeto em um executável final.
- D. Converte código de máquina de volta para uma linguagem de alto nível.
- E. Traduz entre linguagens de alto nível, como o MineonScript para Python.

#### Questão 7 (0,50)

O lexer usado na construção da CST (Material 7) é diferente do lexer do Material 6 em um ponto importante.

O que ele faz com espaços e comentários?

- A. Descarta-os, exatamente como o lexer do Material 6.
- B. Guarda-os no prefixo do token seguinte, para que a CST possa devolver o texto original.
- C. Transforma-os em nós ESPACO e COMENTARIO da AST.
- D. Gera um erro léxico quando encontra um comentário.
- E. Converte-os em tokens NOME.

#### Questão 8 (0,50)

Considere a instrução abaixo:

```text
y = a * b
```

Quantos nós têm, respectivamente, a CST e a AST dessa instrução, conforme o programa da aula?

- A. 11 e 5.
- B. 5 e 11.
- C. 9 e 5.
- D. 11 e 7.
- E. 13 e 5.

#### Questão 9 (0,50)

Considere a instrução `escreva(total)` e suas duas árvores. Analise as afirmações:

- I. Na CST, cada token vira uma folha, inclusive ESCREVA, ABRE_PAR e FECHA_PAR.
- II. Na AST, a palavra-chave `escreva` não aparece como folha: ela é representada pelo próprio tipo do nó SAIDA.
- III. Na AST, os parênteses viram nós filhos de SAIDA.

Estão CORRETAS somente as afirmações:

- A. Apenas a I.
- B. Apenas a III.
- C. II e III.
- D. I e II.
- E. I, II e III.

#### Questão 10 (0,50)

Pela repetição EBNF `<expressao> ::= <termo> { ( SOMA | SUB ) <termo> }`, a conversão para AST agrupa os operadores da esquerda para a direita.

```text
z = 10 - 4 - 3
escreva(z)
retorna 0
```

Após transpilar e executar o Python gerado, qual valor é exibido?

- A. 9
- B. -3
- C. 17
- D. Nada: ocorre um erro de sintaxe no Python.
- E. 3

#### Questão 11 (0,50)

Identifique cada item como VERDADEIRO (V) ou FALSO (F):

- ( ) Um formatador que padroniza a indentação sem perder comentários deve trabalhar sobre a CST.
- ( ) A função `transpilador_python` do Material 6 continua funcionando sem alterações quando recebe a AST construída a partir da CST.
- ( ) A AST guarda o prefixo de cada token e, por isso, também é sem perdas.
- ( ) Na CST de `x = 2 * (3 + 4)`, os parênteses aparecem como folhas dentro de um nó `<fator>`.

Escolha a alternativa que representa a sequência correta:

- A. V - V - V - V.
- B. V - F - F - V.
- C. V - V - F - V.
- D. F - V - F - V.
- E. V - V - F - F.

#### Questão 12 (0,50)

Geradores de parser produzem o analisador sintático a partir de uma gramática.

Qual das ferramentas abaixo é um gerador de parser capaz de produzir analisadores em várias linguagens-alvo, como Java, Python e C#?

- A. ANTLR.
- B. Babel.
- C. LibCST.
- D. Roslyn.
- E. pip.

#### Questão 13 (0,50)

Desenhe a árvore AST gerada a partir da instrução abaixo:

```text
total = preco * 3 + frete
```

#### Questão 14 (0,50)

Qual instrução originou a árvore AST abaixo?

```text
[ATRIBUICAO: =]
  [IDENTIFICADOR: y]
  [EXPRESSAO: *]
    [EXPRESSAO: +]
      [IDENTIFICADOR: a]
      [IDENTIFICADOR: b]
    [IDENTIFICADOR: c]
```

#### Questão 15 (0,50)

Desenhe a árvore CST gerada a partir da instrução abaixo:

```text
media = soma / 2
```

#### Questão 16 (0,50)

Transcreva a instrução a partir da árvore CST abaixo:

```text
<instrucao>
└── <saida>
    ├── ESCREVA "escreva"
    ├── ABRE_PAR "("
    ├── <expressao>
    │   └── <termo>
    │       ├── <fator>
    │       │   └── NOME "x"
    │       ├── MUL "*"
    │       └── <fator>
    │           ├── ABRE_PAR "("
    │           ├── <expressao>
    │           │   ├── <termo>
    │           │   │   └── <fator>
    │           │   │       └── NOME "y"
    │           │   ├── SUB "-"
    │           │   └── <termo>
    │           │       └── <fator>
    │           │           └── NUMERO "2"
    │           └── FECHA_PAR ")"
    └── FECHA_PAR ")"
```

---

### Simulado 2

#### Questão 1 (0,50)

Um aluno digitou, por engano, o programa abaixo:

```text
x = 2 @ 3
retorna 0
```

Em qual etapa o transpilador MineonScript interrompe a tradução?

- A. No lexer, com a mensagem de caractere inesperado, pois nenhum padrão de token reconhece `@`.
- B. No parser, porque `@` não é um operador previsto na gramática.
- C. No gerador, porque não existe tradução de `@` para Python.
- D. Somente ao executar o Python gerado.
- E. Na análise semântica, que verifica os operadores válidos.

#### Questão 2 (0,50)

Considere o programa abaixo:

```text
escreva(x + )
retorna 0
```

O que acontece ao transpilá-lo?

- A. O lexer acusa erro, pois não reconhece o caractere `)`.
- B. A tradução funciona e gera `print((x + ))`.
- C. O gerador completa a expressão com zero, gerando `print((x + 0))`.
- D. A tradução funciona; o erro só aparece ao executar o Python.
- E. O parser acusa erro: depois do `+` a gramática exige um `<termo>`, mas encontra FECHA_PAR.

#### Questão 3 (0,50)

Considere o programa MineonScript abaixo:

```text
i = 0
enquanto i < 10 {
    se i > 5 {
        escreva(i)
    }
    i = i + 1
}
retorna 0
```

No Python gerado, com quantos espaços de recuo aparece a linha `print(i)`?

- A. 4.
- B. 8.
- C. 0.
- D. 12.
- E. 2.

#### Questão 4 (0,50)

Lembre que o gerador envolve toda EXPRESSAO em parênteses e que o parser coloca a multiplicação mais fundo que a soma.

Qual linha Python é gerada para a instrução abaixo?

```text
r = a * b + c * d
```

- A. `r = a * b + c * d`
- B. `r = (a * (b + c) * d)`
- C. `r = (((a * b) + c) * d)`
- D. `r = ((a * b) + (c * d))`
- E. `r = (a * b) + (c * d)`

#### Questão 5 (0,50)

O programa abaixo é transpilado sem nenhuma mensagem de erro:

```text
escreva(total)
retorna 0
```

Ao executar o Python gerado, ocorre `NameError`. Qual alternativa explica a situação?

- A. O lexer deveria ter rejeitado `total`, pois não é palavra reservada.
- B. O parser deveria ter rejeitado `escreva` sem uma atribuição antes.
- C. O MineonScript não tem análise semântica: ninguém verifica se `total` recebeu valor antes de ser usado, e o erro só aparece na execução.
- D. O gerador traduziu `escreva` para a função errada.
- E. O `exit(0)` é executado antes do `print`.

#### Questão 6 (0,50)

Transpiladores traduzem entre linguagens de alto nível.

Qual das ferramentas abaixo é um exemplo de transpilador?

- A. GCC, quando gera código de máquina a partir de C.
- B. Babel, que converte JavaScript moderno (ES2015+) em versões mais antigas da linguagem.
- C. O interpretador CPython executando um script.
- D. Um montador (assembler) convertendo Assembly em código de máquina.
- E. Um linker juntando arquivos objeto em um executável.

#### Questão 7 (0,50)

Considere a instrução `x = 5`, que não tem nenhuma multiplicação nem parênteses.

Por que a CST dessa instrução contém os nós `<termo>` e `<fator>`?

- A. Porque o lexer cria esses nós para cada número encontrado.
- B. Porque o parser sempre supõe que haverá uma multiplicação.
- C. Porque a AST precisa deles para gerar o código Python.
- D. Porque são nós de erro inseridos quando a expressão é simples demais.
- E. Porque a CST registra cada regra da gramática aplicada, inclusive as de passagem com um único filho (`<expressao>` → `<termo>` → `<fator>` → NUMERO).

#### Questão 8 (0,50)

Considere a instrução abaixo:

```text
escreva(k)
```

Quantos nós têm, respectivamente, a CST e a AST dessa instrução?

- A. 9 e 2.
- B. 9 e 3.
- C. 7 e 2.
- D. 2 e 9.
- E. 8 e 2.

#### Questão 9 (0,50)

Considere a instrução abaixo, com espaços extras e um comentário:

```text
x  =  2*(3+4)   // dobro
```

Se tentássemos reconstruir o texto original percorrendo apenas a AST, o que se perderia?

- A. Apenas o comentário; os espaços ficam na AST.
- B. Apenas os números, que viram tipos na AST.
- C. Os espaços extras, o comentário e os parênteses, pois a AST não guarda prefixos nem pontuação.
- D. Nada: a AST também é sem perdas.
- E. O nome da variável `x`, que some na AST.

#### Questão 10 (0,50)

A conversão para AST agrupa operadores de mesma precedência da esquerda para a direita (dobra à esquerda).

```text
q = 100 / 10 / 5
escreva(q)
retorna 0
```

Após transpilar e executar o Python gerado, qual valor é exibido?

- A. 50.0
- B. 0.5
- C. 20.0
- D. 2.0
- E. Nada: ocorre `ZeroDivisionError`.

#### Questão 11 (0,50)

No Material 7, LibCST (Python) e Roslyn (C#) aparecem como exemplos de uso da CST.

Para que tipo de ferramenta elas são usadas?

- A. Interpretadores que executam o código diretamente da AST.
- B. Ferramentas de refatoração e transformação de código que precisam preservar formatação e comentários.
- C. Geradores de código de máquina para processadores x86.
- D. Analisadores léxicos que descartam espaços e comentários.
- E. Sistemas de controle de versão, como o Git.

#### Questão 12 (0,50)

Sobre os geradores de parser YACC e GNU Bison, é correto afirmar:

- A. O YACC foi criado no ambiente Unix, e o GNU Bison é seu sucessor livre e compatível.
- B. O YACC é um sucessor do Bison, criado para o Windows.
- C. Ambos são transpiladores de JavaScript.
- D. Ambos geram apenas a AST e nunca a árvore de derivação.
- E. O Bison é uma biblioteca de refatoração baseada em CST.

#### Questão 13 (0,50)

Desenhe a árvore AST gerada a partir da instrução abaixo:

```text
area = base * altura / 2
```

#### Questão 14 (0,50)

Qual instrução originou a árvore AST abaixo?

```text
[ATRIBUICAO: =]
  [IDENTIFICADOR: d]
  [EXPRESSAO: -]
    [IDENTIFICADOR: a]
    [EXPRESSAO: -]
      [IDENTIFICADOR: b]
      [IDENTIFICADOR: c]
```

#### Questão 15 (0,50)

Desenhe a árvore CST gerada a partir da instrução abaixo:

```text
escreva(n * 2)
```

#### Questão 16 (0,50)

Transcreva a instrução a partir da árvore CST abaixo:

```text
<instrucao>
└── <atribuicao>
    ├── NOME "w"
    ├── IGUAL "="
    └── <expressao>
        └── <termo>
            ├── <fator>
            │   ├── ABRE_PAR "("
            │   ├── <expressao>
            │   │   ├── <termo>
            │   │   │   └── <fator>
            │   │   │       └── NOME "p"
            │   │   ├── SOMA "+"
            │   │   └── <termo>
            │   │       └── <fator>
            │   │           └── NOME "q"
            │   └── FECHA_PAR ")"
            ├── DIV "/"
            └── <fator>
                └── NOME "r"
```

---

### Simulado 3

#### Questão 1 (0,50)

Analise as afirmações sobre o transpilador MineonScript do Material 6:

- I. O lexer descarta espaços e comentários.
- II. A AST guarda os parênteses da expressão como nós próprios.
- III. O gerador traduz `retorna 0` para `exit(0)`.

Estão CORRETAS somente as afirmações:

- A. Apenas a I.
- B. I e II.
- C. II e III.
- D. I e III.
- E. I, II e III.

#### Questão 2 (0,50)

Qual é a sequência de tokens produzida pelo lexer do Material 6 para a instrução abaixo?

```text
escreva(n + 1)
```

- A. ESCREVA, ABRE_PAR, NOME, ESPACO, SOMA, ESPACO, NUMERO, FECHA_PAR.
- B. ESCREVA, ABRE_PAR, NOME, SOMA, NUMERO, FECHA_PAR.
- C. ESCREVA, ABRE_PAR, IDENTIFICADOR, SOMA, NUMERO, FECHA_PAR.
- D. SAIDA, EXPRESSAO, NOME, NUMERO.
- E. ESCREVA, TEXTO, FECHA_PAR.

#### Questão 3 (0,50)

Considere o programa MineonScript abaixo:

```text
n = 3
enquanto ! n == 0 {
    n = n - 1
}
retorna 0
```

Qual é a linha do laço no Python gerado?

- A. `while ! n == 0:`
- B. `while not n == 0 {`
- C. `while (n != 0):`
- D. `while n == 0:`
- E. `while not (n == 0):`

#### Questão 4 (0,50)

O gerador sempre envolve uma EXPRESSAO em parênteses, como na tradução de `x = 2 + 3 * 4` para `x = (2 + (3 * 4))`.

Qual é a consequência dessa escolha?

- A. A precedência representada pela forma da AST é preservada no Python, mesmo que alguns parênteses fiquem redundantes.
- B. O Python passa a calcular as somas antes das multiplicações.
- C. O código gerado fica mais rápido na execução.
- D. Os parênteses são exigidos pela sintaxe do Python em toda atribuição.
- E. A expressão é calculada já na transpilação, e o Python recebe só o resultado.

#### Questão 5 (0,50)

Sobre a comunicação entre as etapas do transpilador MineonScript, o que o parser recebe e o que ele devolve?

- A. Recebe o código-fonte como texto e devolve a lista de tokens.
- B. Recebe a AST e devolve o código Python.
- C. Recebe a lista de tuplas (TIPO, VALOR) do lexer e devolve a raiz da AST, um NoAST do tipo PROGRAMA.
- D. Recebe o código Python e devolve a CST.
- E. Recebe a lista de tokens e devolve o código Python, sem árvore intermediária.

#### Questão 6 (0,50)

Um aluno esqueceu a linha final `retorna 0` no programa abaixo:

```text
x = 1
escreva(x)
```

O que acontece ao transpilá-lo?

- A. O código é traduzido normalmente, apenas sem o `exit(0)`.
- B. O lexer acusa erro, pois o arquivo termina sem o token RETORNO.
- C. O gerador insere `exit(0)` automaticamente.
- D. O parser acusa erro sintático, pois a gramática exige `<programa> ::= <instrucoes> <retorno>` e encontra o fim do arquivo.
- E. O erro só aparece ao executar o Python gerado.

#### Questão 7 (0,50)

Identifique cada item como VERDADEIRO (V) ou FALSO (F):

- ( ) A CST também é chamada de árvore de derivação (*parse tree*).
- ( ) A AST de uma instrução tem sempre mais nós que a CST.
- ( ) Os nós de passagem, como `<termo>` com um único filho, existem na CST e somem na AST.
- ( ) A AST é a estrutura usada pelo gerador de código.

Escolha a alternativa que representa a sequência correta:

- A. V - V - V - V.
- B. V - F - F - V.
- C. F - F - V - V.
- D. V - V - F - V.
- E. V - F - V - V.

#### Questão 8 (0,50)

Considere a instrução abaixo:

```text
x = (7)
```

Quantos nós têm, respectivamente, a CST e a AST dessa instrução?

- A. 11 e 3.
- B. 13 e 3.
- C. 13 e 5.
- D. 3 e 13.
- E. 9 e 3.

#### Questão 9 (0,50)

Na conversão CST → AST, quando um nó `<termo>` da CST dá origem a um nó EXPRESSAO na AST?

- A. Quando tem mais de um filho, isto é, quando contém um operador MUL ou DIV entre fatores.
- B. Sempre: todo `<termo>` vira um nó EXPRESSAO.
- C. Nunca: apenas `<expressao>` vira EXPRESSAO.
- D. Quando o seu único filho é um `<fator>` com número.
- E. Quando aparece dentro de parênteses.

#### Questão 10 (0,50)

Considere a instrução abaixo, com três espaços antes do 5 e um comentário ao final:

```text
x =   5 // cinco
```

Pela regra do prefixo usada no lexer da CST, onde ficam guardados esses espaços e o comentário?

- A. Ambos ficam no prefixo do token IGUAL.
- B. Ambos são descartados, como no Material 6.
- C. Os espaços ficam no prefixo do token NUMERO "5"; o comentário, no prefixo do token de fim de arquivo (EOF).
- D. Os espaços viram um nó ESPACO e o comentário, um nó COMENTARIO na CST.
- E. Ambos ficam guardados no nó ATRIBUICAO da AST.

#### Questão 11 (0,50)

Uma ferramenta de refatoração baseada na CST vai renomear a variável `x` para `valor` em um programa com comentários e indentação própria.

O que a ferramenta altera?

- A. Todas as folhas da CST, que são reescritas com formatação padronizada.
- B. A AST, que depois é convertida de volta em texto com os comentários.
- C. Apenas o primeiro `x` encontrado.
- D. Os comentários que citam `x`, mas não o código.
- E. Apenas as folhas NOME com texto `x`; o restante, inclusive comentários, fica idêntico.

#### Questão 12 (0,50)

Sobre o ANTLR, é correto afirmar:

- A. Foi criado nos laboratórios Bell no início dos anos 1970 e gera apenas código em C.
- B. Foi criado por Terence Parr e gera parsers em várias linguagens-alvo, como Java, Python e C#.
- C. É um sistema operacional derivado do Linux.
- D. É o sucessor livre e compatível do GNU Bison.
- E. É um transpilador de JavaScript moderno para JavaScript antigo.

#### Questão 13 (0,50)

Desenhe a árvore AST gerada a partir da instrução abaixo:

```text
saldo = saldo - taxa * 2
```

#### Questão 14 (0,50)

Qual instrução originou a árvore AST abaixo?

```text
[SAIDA]
  [EXPRESSAO: -]
    [EXPRESSAO: *]
      [IDENTIFICADOR: a]
      [EXPRESSAO: +]
        [IDENTIFICADOR: b]
        [IDENTIFICADOR: c]
    [IDENTIFICADOR: d]
```

#### Questão 15 (0,50)

Desenhe a árvore CST gerada a partir da instrução abaixo:

```text
soma = x + 10
```

#### Questão 16 (0,50)

Transcreva a instrução a partir da árvore CST abaixo:

```text
<instrucao>
└── <saida>
    ├── ESCREVA "escreva"
    ├── ABRE_PAR "("
    ├── <expressao>
    │   └── <termo>
    │       ├── <fator>
    │       │   └── NUMERO "2"
    │       ├── MUL "*"
    │       └── <fator>
    │           ├── ABRE_PAR "("
    │           ├── <expressao>
    │           │   ├── <termo>
    │           │   │   └── <fator>
    │           │   │       └── NOME "n"
    │           │   ├── SUB "-"
    │           │   └── <termo>
    │           │       └── <fator>
    │           │           └── NUMERO "1"
    │           └── FECHA_PAR ")"
    └── FECHA_PAR ")"
```

---

## Parte 14 — Gabarito unificado

### Respostas rápidas

| Questão | Simulado 1 | Simulado 2 | Simulado 3 |
|---|---|---|---|
| 1 | **C** | **A** | **D** |
| 2 | **D** | **E** | **B** |
| 3 | **C** | **B** | **E** |
| 4 | **B** | **D** | **A** |
| 5 | **A** | **C** | **C** |
| 6 | **E** | **B** | **D** |
| 7 | **B** | **E** | **E** |
| 8 | **A** | **A** | **B** |
| 9 | **D** | **C** | **A** |
| 10 | **E** | **D** | **C** |
| 11 | **C** | **B** | **E** |
| 12 | **A** | **A** | **B** |
| 13 | Árvore | Árvore | Árvore |
| 14 | Instrução | Instrução | Instrução |
| 15 | Árvore | Árvore | Árvore |
| 16 | Instrução | Instrução | Instrução |

### Gabarito comentado

A coluna **Resumo** indica a parte deste arquivo que resolve a questão.

| Sim. | Q | Resposta | Material | Resumo | Explicação |
|---|---|---|---|---|---|
| S1 | 1 | **C** | 6 | 3, 4 | II é falsa: o MineonScript não tem análise semântica, então não verifica declaração de variáveis. |
| S1 | 2 | **D** | 6 | 6 | LOOP vira `while` sem parênteses na condição (CONDICAO não gera parênteses); o bloco ganha um nível de indentação e a EXPRESSAO `i + 1` vira `(i + 1)`. Conferido executando o transpilador. |
| S1 | 3 | **C** | 6 | 6 | O bloco `senao` é traduzido para `else`, e não para `elif` (ver o tratamento de CONDICIONAL com três filhos). |
| S1 | 4 | **B** | 6 | 6 | CONDICAO com valor `"!"` gera `not (...)`. Conferido executando o transpilador. |
| S1 | 5 | **A** | 6 | 2 | O padrão COMENTARIO (`//.*`) é reconhecido e descartado junto com ESPACO. A única linha `#` do Python é o cabeçalho fixo `# Código gerado via Transpilador MineonScript`. |
| S1 | 6 | **E** | 6 | 1 | Definição de transpilador (Material 6): tradução entre linguagens de alto nível. |
| S1 | 7 | **B** | 7 | 8 | Propriedade sem perdas (lossless) da CST: espaços e comentários ficam no atributo `prefixo` do token seguinte. |
| S1 | 8 | **A** | 7 | 9 | CST: `<instrucao>`, `<atribuicao>`, NOME y, IGUAL, `<expressao>`, `<termo>`, `<fator>`, NOME a, MUL, `<fator>`, NOME b. AST: [ATRIBUICAO], [IDENTIFICADOR y], [EXPRESSAO *], [IDENTIFICADOR a], [IDENTIFICADOR b]. Conferido no programa. |
| S1 | 9 | **D** | 7 | 9, 5 | III é falsa: parênteses e pontuação somem na AST. |
| S1 | 10 | **E** | 7 | 7 | AST: `[EXPRESSAO -]([EXPRESSAO -](10, 4), 3)`, que gera `z = ((10 - 4) - 3)` = 3. Agrupar pela direita daria `10 - (4 - 3)` = 9. Conferido executando. |
| S1 | 11 | **C** | 7 | 9, 10 | Apenas o 3º item é falso: a AST descarta tokens e prefixos; só a CST é sem perdas. |
| S1 | 12 | **A** | 7 | 10 | ANTLR (Terence Parr) gera parsers em várias linguagens. Babel é transpilador; LibCST e Roslyn usam CST para refatoração; pip instala pacotes Python. |
| S1 | 13 | Árvore | 7 | 11, 7 | Abaixo. AST com 7 nós (a CST teria 15). |
| S1 | 14 | Instrução | 7 | 11, 7 | Abaixo. |
| S1 | 15 | Árvore | 7 | 11, 9 | Abaixo. CST com 11 nós. |
| S1 | 16 | Instrução | 7 | 11 | Abaixo. Leia as folhas da esquerda para a direita. |
| S2 | 1 | **A** | 6 | 4 | Erro léxico: `Caractere inesperado: '@' na posição 6`. Conferido executando o transpilador. |
| S2 | 2 | **E** | 6 | 3, 4 | Erro sintático: `Fator inesperado com token 'FECHA_PAR'`. Os tokens existem; a sequência é que não obedece à gramática. Conferido executando. |
| S2 | 3 | **B** | 6 | 6 | `print(i)` está dentro do `if`, que está dentro do `while`: `nivel_indentacao = 2`, e cada nível vale 4 espaços. Conferido executando. |
| S2 | 4 | **D** | 6 | 6, 7 | AST: `[EXPRESSAO +]` com filhos `[EXPRESSAO *](a, b)` e `[EXPRESSAO *](c, d)`. Conferido executando o transpilador. |
| S2 | 5 | **C** | 6 | 4 | Léxica e sintaticamente o programa é válido; a falta de declaração é um problema semântico, verificado apenas pelo Python em tempo de execução. |
| S2 | 6 | **B** | 6 | 1 | Babel traduz JavaScript para JavaScript (alto nível para alto nível), como o MineonScript para Python. |
| S2 | 7 | **E** | 7 | 9 | Cadeias unitárias: a CST de `x = 5` tem 8 nós e a AST, 3. Conferido no programa. |
| S2 | 8 | **A** | 7 | 9 | CST: `<instrucao>`, `<saida>`, ESCREVA, ABRE_PAR, `<expressao>`, `<termo>`, `<fator>`, NOME k, FECHA_PAR. AST: [SAIDA] e [IDENTIFICADOR k]. Conferido no programa. |
| S2 | 9 | **C** | 7 | 8, 10 | Só a CST é sem perdas: suas folhas, com os prefixos, devolvem o texto caractere por caractere. |
| S2 | 10 | **D** | 7 | 7 | Gera `q = ((100 / 10) / 5)` = 2.0 (a divisão `/` do Python devolve float). Agrupar pela direita daria `100 / (10 / 5)` = 50.0. Conferido executando. |
| S2 | 11 | **B** | 7 | 10 | Slide "Onde cada uma é usada": refatoração (LibCST, Roslyn) usa CST. |
| S2 | 12 | **A** | 7 | 10 | YACC (*Yet Another Compiler-Compiler*) nasceu no Unix; o Bison é seu sucessor livre e compatível. |
| S2 | 13 | Árvore | 7 | 11, 7 | Abaixo. AST com 7 nós (a CST teria 14). |
| S2 | 14 | Instrução | 7 | 11, 7 | Abaixo. |
| S2 | 15 | Árvore | 7 | 11, 9 | Abaixo. CST com 12 nós. |
| S2 | 16 | Instrução | 7 | 11 | Abaixo. Leia as folhas da esquerda para a direita. |
| S3 | 1 | **D** | 6 | 2, 5, 6 | II é falsa: os parênteses não viram nós; a precedência fica na forma da árvore. |
| S3 | 2 | **B** | 6 | 2 | Espaços são descartados; IDENTIFICADOR e SAIDA são tipos de nó da AST, não de token. Conferido executando o lexer. |
| S3 | 3 | **E** | 6 | 6 | CONDICAO com valor `"!"` gera `not (...)`, e o LOOP vira `while`. Conferido executando o transpilador. |
| S3 | 4 | **A** | 6 | 6, 7 | Trecho da EXPRESSAO: `return f"({esq} {no.valor} {dir})"`. |
| S3 | 5 | **C** | 6 | 1, 3 | Ordem: `lexer(codigo)` → tokens; `Parser(tokens).parse_programa()` → AST; `transpilador_python(ast)` → Python. |
| S3 | 6 | **D** | 6 | 3, 4 | Mensagem: `Esperado 'RETORNO', mas encontrado 'EOF'`. Conferido executando o transpilador. |
| S3 | 7 | **E** | 7 | 8, 9, 10 | Apenas o 2º item é falso: a AST é menor que a CST. |
| S3 | 8 | **B** | 7 | 9 | Os parênteses abrem uma segunda cadeia `<expressao>` → `<termo>` → `<fator>` na CST (13 nós); na AST restam [ATRIBUICAO], [IDENTIFICADOR x] e [NUMERO 7]. Conferido no programa. |
| S3 | 9 | **A** | 7 | 9 | Um `<termo>` com um único filho apenas o repassa (cadeia unitária); com operador, vira [EXPRESSAO \* ou /]. |
| S3 | 10 | **C** | 7 | 8 | Espaços e comentários vão para o prefixo do token SEGUINTE; depois do comentário só existe o EOF. |
| S3 | 11 | **E** | 7 | 8 | É o exemplo da aba Refatoração do laboratório: só as folhas NOME "x" mudam. |
| S3 | 12 | **B** | 7 | 10 | A alternativa sobre os laboratórios Bell descreve o YACC; o sucessor livre do YACC é o Bison; o transpilador de JavaScript é o Babel. |
| S3 | 13 | Árvore | 7 | 11, 7 | Abaixo. AST com 7 nós (a CST teria 15). |
| S3 | 14 | Instrução | 7 | 11, 7 | Abaixo. |
| S3 | 15 | Árvore | 7 | 11, 9 | Abaixo. CST com 12 nós. |
| S3 | 16 | Instrução | 7 | 11 | Abaixo. Leia as folhas da esquerda para a direita. |

> **Simulado 3** — **Nota nossa à Q10 (conferida no programa):** a resposta C vale para a instrução **isolada**, como o enunciado apresenta — depois do comentário não há outro token, então ele cai no EOF. Num **programa completo** (com `retorna 0` na linha de baixo), o comentário e a quebra de linha vão para o prefixo do token `RETORNO`, que é o "token seguinte". A regra é sempre a mesma: **prefixo do próximo token real**; o EOF só recebe o que sobra no fim do arquivo.

### Respostas das questões de árvore

#### Simulado 1 · Q13

```text
[ATRIBUICAO: =]
  [IDENTIFICADOR: total]
  [EXPRESSAO: +]
    [EXPRESSAO: *]
      [IDENTIFICADOR: preco]
      [NUMERO: 3]
    [IDENTIFICADOR: frete]
```

#### Simulado 1 · Q14

```text
y = (a + b) * c
```

A soma está mais funda que a multiplicação na árvore; por isso a instrução precisa dos parênteses em `(a + b)`.

#### Simulado 1 · Q15

```text
<instrucao>
└── <atribuicao>
    ├── NOME "media"
    ├── IGUAL "="
    └── <expressao>
        └── <termo>
            ├── <fator>
            │   └── NOME "soma"
            ├── DIV "/"
            └── <fator>
                └── NUMERO "2"
```

#### Simulado 1 · Q16

```text
escreva(x * (y - 2))
```

#### Simulado 2 · Q13

```text
[ATRIBUICAO: =]
  [IDENTIFICADOR: area]
  [EXPRESSAO: /]
    [EXPRESSAO: *]
      [IDENTIFICADOR: base]
      [IDENTIFICADOR: altura]
    [NUMERO: 2]
```

#### Simulado 2 · Q14

```text
d = a - (b - c)
```

A subtração da direita está mais funda; sem parênteses, `a - b - c` seria agrupado pela esquerda e geraria outra árvore.

#### Simulado 2 · Q15

```text
<instrucao>
└── <saida>
    ├── ESCREVA "escreva"
    ├── ABRE_PAR "("
    ├── <expressao>
    │   └── <termo>
    │       ├── <fator>
    │       │   └── NOME "n"
    │       ├── MUL "*"
    │       └── <fator>
    │           └── NUMERO "2"
    └── FECHA_PAR ")"
```

#### Simulado 2 · Q16

```text
w = (p + q) / r
```

#### Simulado 3 · Q13

```text
[ATRIBUICAO: =]
  [IDENTIFICADOR: saldo]
  [EXPRESSAO: -]
    [IDENTIFICADOR: saldo]
    [EXPRESSAO: *]
      [IDENTIFICADOR: taxa]
      [NUMERO: 2]
```

#### Simulado 3 · Q14

```text
escreva(a * (b + c) - d)
```

A soma está mais funda que a multiplicação; por isso `(b + c)` precisa de parênteses. A subtração de `d` fica no topo.

#### Simulado 3 · Q15

```text
<instrucao>
└── <atribuicao>
    ├── NOME "soma"
    ├── IGUAL "="
    └── <expressao>
        ├── <termo>
        │   └── <fator>
        │       └── NOME "x"
        ├── SOMA "+"
        └── <termo>
            └── <fator>
                └── NUMERO "10"
```

#### Simulado 3 · Q16

```text
escreva(2 * (n - 1))
```
