# Questionário — Aula 03 (BNF · Material 3)

> Gabarito comentado. Cada resposta é justificada **pela gramática literal do Material 3**, transcrita abaixo — não por convenção geral de BNF. Quando as duas divergem, vale o slide.

## Gramática de referência (Material 3, transcrita do PDF)

```bnf
<programa>   ::= <instrucoes> <retorno>

<instrucoes> ::= <instrucao> | <instrucao> <instrucoes>

<instrucao>  ::= <atribuicao>
               | <saida>
               | <entrada>
               | <condicional>
               | <loop>

<atribuicao> ::= <identificador> "=" <expressao>

<saida>      ::= "print" "(" <expressao> ")"

<entrada>    ::= <identificador> "=" "input" "(" <string> ")"

<condicional> ::= "se" <condicao> "{" <instrucoes> "}"
                | "se" <condicao> "{" <instrucoes> "}" "senao" "{" <instrucoes> "}"

<loop>       ::= "enquanto" <condicao> "{" <instrucoes> "}"

<condicao>   ::= <expressao> <operador_relacional> <expressao>
               | "!" <condicao>

<operador_relacional> ::= "==" | "<" | ">"

<expressao>  ::= <termo>
               | <expressao> "+" <termo>
               | <expressao> "-" <termo>

<termo>      ::= <fator>
               | <termo> "*" <fator>
               | <termo> "/" <fator>

<fator>      ::= <numero>
               | <identificador>
               | "(" <expressao> ")"

<retorno>    ::= "retorna" <numero>

<identificador> ::= letra {letra | digito}
<numero>        ::= digito {digito}
```

**Notação declarada no slide:** cada linha define uma regra · `< >` = nome de categoria · `" "` = texto literal no código · `|` = "ou" · `{ }` = "pode repetir várias vezes".

---

## Questão 1 — Regra recursiva de soma

> Considere a seguinte regra em BNF:
> `<e> ::= <t> | <e> "+" <t>`
> O que essa regra descreve?

- [ ] Expressão booleana
- [ ] Expressão condicional
- [ ] Expressão com multiplicação
- [x] **Expressão com soma**
- [ ] Expressão de atribuição

**Por quê:** é a regra `<expressao>` do próprio Material 3, com os nomes abreviados (`<e>` = expressão, `<t>` = termo). O único literal na regra é `"+"`, então ela só descreve soma. As duas alternativas dizem: ou a expressão é um termo sozinho (caso base), ou é uma expressão seguida de `+` e um termo (caso recursivo).

**Detalhe que a prova pode cobrar:** a recursão está **à esquerda** (`<e>` aparece como primeiro símbolo da própria regra). Isso torna a soma **associativa à esquerda** — `1 + 2 + 3` deriva como `(1 + 2) + 3`.

**Por que as outras estão erradas:** booleana exigiria operadores lógicos; condicional exigiria `se`/`senao`; multiplicação exigiria o literal `"*"` (que está em `<termo>`, não aqui); atribuição exigiria o literal `"="`.

---

## Questão 2 — Aspas `" "`

> Na BNF, o que significa o uso de aspas `" "` em uma regra?

- [ ] Nome de categoria
- [ ] Agrupamento
- [x] **Texto literal no código**
- [ ] Comentário
- [ ] Repetição

**Por quê:** o slide define literalmente — *"O que aparece em aspas `" "` é texto literal no código"*. É o **terminal** da gramática: o caractere ou palavra que aparece exatamente assim no programa escrito. Em `<saida> ::= "print" "(" <expressao> ")"`, tudo entre aspas (`print`, `(`, `)`) tem que ser digitado igual; só `<expressao>` é substituível.

**Pegadinha:** "Nome de categoria" é a definição de `< >`, não de `" "`. São os dois lados da mesma moeda — `< >` é o que se expande (não-terminal), `" "` é o que não se expande (terminal).

---

## Questão 3 — Símbolo `|`

> Na BNF, o símbolo `|` significa:

- [ ] Comentário
- [x] **Alternativa 'ou'**
- [ ] Repetição
- [ ] Agrupamento
- [ ] Concatenação

**Por quê:** o slide define — *"O símbolo `|` significa 'ou'"*. Separa as alternativas de uma mesma regra: `<operador_relacional> ::= "==" | "<" | ">"` quer dizer que um operador relacional é `==` **ou** `<` **ou** `>`, escolhendo exatamente um.

**Por que "Concatenação" está errada:** concatenação em BNF é a **justaposição** (símbolos escritos lado a lado, como `"retorna" <numero>`). O `|` é o oposto — em vez de "um depois do outro", é "um ou o outro".

---

## Questão 4 — Chaves `{ }`

> Na BNF, o uso de `{ }` significa:

- [ ] Agrupamento exclusivo
- [ ] Definição literal
- [ ] Alternativa obrigatória
- [x] **Repetição zero ou mais vezes**
- [ ] Comentário de bloco

**Por quê:** o slide define — *"As chaves `{ }` significam 'pode repetir várias vezes'"*. O **"pode"** é a parte que importa: repetir zero vez também é válido. Prova disso está na própria gramática: `<identificador> ::= letra {letra | digito}` aceita o identificador `x` (uma letra e nenhuma repetição). Se `{ }` exigisse pelo menos uma repetição, `x` seria inválido — e ele é o identificador usado em todos os exemplos do slide.

**Cuidado com a colisão de símbolos:** neste material `{ }` tem **dois papéis diferentes**. Como *metassímbolo* (fora de aspas) = repetição. Como *terminal* (entre aspas, em `"{"` e `"}"` na regra `<condicional>` e `<loop>`) = a chave literal que delimita bloco de código no MineonScript. A pergunta é sobre o primeiro caso.

---

## Questão 5 — Regra de identificador

> Considere:
> `<id> ::= <tetra> { <tetra> | <trita> }`
> Qual é o significado dessa regra?

- [ ] O id só contém símbolos especiais não podendo combinar tetras ou tritas
- [x] **O id começa com tetra e pode ter tetras ou tritas**
- [ ] O id termina obrigatoriamente em trita
- [ ] O id começa com trita
- [ ] O id só contém tetras maiúsculas

**Por quê:** é a regra `<identificador> ::= letra {letra | digito}` do Material 3, com os nomes trocados (`tetra` ↔ letra, `trita` ↔ dígito). A leitura é posicional:

1. **Fora das chaves**, no início: `<tetra>` obrigatório e único → o id **sempre começa com tetra**.
2. **Dentro das chaves**: `<tetra> | <trita>` repetível zero ou mais vezes → depois do primeiro símbolo, vem qualquer combinação (inclusive nenhuma).

É a regra clássica de identificador de linguagem de programação: começa com letra, continua com letra ou dígito. É o que impede `2x` de ser um nome de variável válido.

**Por que as outras estão erradas:** "termina obrigatoriamente em trita" — `{ }` não obriga nada, nem fixa o último símbolo. "Começa com trita" — inverte a regra; trita só aparece dentro das chaves. "Só tetras maiúsculas" — a gramática não diz nada sobre caixa. "Só símbolos especiais" — contradiz a regra inteira.

---

## Questão 6 — Regra de dígito

> Dada a regra:
> `<data> ::= "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9"`
> O que ela define?

- [ ] Conjunto de símbolos especiais
- [ ] Conjunto de letras maiúsculas
- [ ] Conjunto de palavras reservadas
- [x] **Conjunto de dígitos decimais**
- [ ] Conjunto de operadores aritméticos

**Por quê:** as alternativas são exatamente os dez algarismos de `0` a `9`, cada um como terminal entre aspas, ligados por `|` (escolha de um). Isso é a definição da **base 10** — o não-terminal `digito` que o Material 3 usa em `<numero> ::= digito {digito}` e em `<identificador>`.

Combinando as duas regras: `<numero>` = um dígito seguido de zero ou mais dígitos, ou seja, qualquer inteiro não-negativo (`7`, `42`, `1990`).

**Não se deixe levar pelo nome `<data>`.** O nome do não-terminal é arbitrário em BNF — o que define a categoria é o lado direito da regra, não o rótulo. Aqui o rótulo sugere "data/calendário", mas o conteúdo é dígito decimal.

---

## Questão 7 — Instruções válidas (múltipla escolha)

> Identifique as instruções válidas para o BNF do MineonScript apresentado no Material 3.

| # | Instrução | Veredito |
|---|---|---|
| 1 | `x = 10` | ✅ **válida** |
| 2 | `print(x + 5)` | ✅ **válida** |
| 3 | `se x > 0 { print(x) } senao { print(0) }` | ✅ **válida** |
| 4 | `input(x)` | ❌ inválida |
| 5 | `enquanto x < 10 { x = x + 1 }` | ✅ **válida** |
| 6 | `retorna 42` | ✅ **válida** |
| 7 | `retorna x + 1` | ❌ inválida |
| 8 | `print x` | ❌ inválida |

**Marcar:** `x = 10` · `print(x + 5)` · `se x > 0 { print(x) } senao { print(0) }` · `enquanto x < 10 { x = x + 1 }` · `retorna 42`

### Derivação de cada uma

**1. `x = 10` ✅** — casa com `<atribuicao> ::= <identificador> "=" <expressao>`.
`x` é `<identificador>` (letra, zero repetições) · `10` é `<numero>` → `<fator>` → `<termo>` → `<expressao>`.

**2. `print(x + 5)` ✅** — casa com `<saida> ::= "print" "(" <expressao> ")"`.
Os três terminais (`print`, `(`, `)`) estão presentes e na ordem. O argumento `x + 5` deriva por `<expressao> "+" <termo>`, com `x` como `<identificador>` → `<fator>` e `5` como `<numero>` → `<fator>` → `<termo>`.

**3. `se x > 0 { print(x) } senao { print(0) } ` ✅** — casa com a **segunda** alternativa de `<condicional>` (a versão com `senao`).
Condição `x > 0` = `<expressao> <operador_relacional> <expressao>`, e `>` está na lista de `<operador_relacional>`. Os dois blocos entre `"{" "}"` contêm `<instrucoes>` válidas (`print(x)` e `print(0)`, ambas `<saida>`).

**4. `input(x)` ❌** — **esta é a pegadinha da questão.** A gramática **não tem** uma instrução `input` isolada. A única regra que menciona `input` é:

```bnf
<entrada> ::= <identificador> "=" "input" "(" <string> ")"
```

`input` só existe **dentro de uma atribuição**. A forma válida seria `x = input("digite: ")`. `input(x)` falha por dois motivos independentes: (a) não há `<identificador> "="` antes, e (b) o argumento tem que ser `<string>`, não um identificador.

**5. `enquanto x < 10 { x = x + 1 }` ✅** — casa com `<loop> ::= "enquanto" <condicao> "{" <instrucoes> "}"`.
Condição `x < 10` usa `<` (está em `<operador_relacional>`); o corpo `x = x + 1` é uma `<atribuicao>` válida, com `x + 1` derivando por `<expressao> "+" <termo>`.

**6. `retorna 42` ✅** — casa com `<retorno> ::= "retorna" <numero>`.
`42` é `digito {digito}`. Note que `<retorno>` é obrigatório em `<programa> ::= <instrucoes> <retorno>` — todo programa MineonScript termina retornando um número ao SO.

**7. `retorna x + 1` ❌** — a regra exige `<numero>`, **não** `<expressao>`.

```bnf
<retorno> ::= "retorna" <numero>          ← literal do slide
```

`x + 1` é uma `<expressao>`, e `<numero>` não deriva expressão nenhuma (`<numero> ::= digito {digito}` só produz sequência de algarismos). Como a gramática não tem regra que transforme `<expressao>` em `<numero>`, a derivação trava. Só um literal numérico serve depois de `retorna`.

**8. `print x` ❌** — faltam os parênteses.

```bnf
<saida> ::= "print" "(" <expressao> ")"   ← "(" e ")" são terminais obrigatórios
```

Terminal entre aspas não é opcional nem decorativo: se está na regra, tem que aparecer no código. Sem `(` e `)` a instrução não casa com nenhuma alternativa de `<instrucao>`.

### Regra de bolso pra questões desse tipo

Nunca julgue pela "cara" da instrução (ela parece Python, logo é válida). Ache o não-terminal que ela deveria casar, e confira **símbolo por símbolo**: todo terminal entre aspas tem que estar presente, na ordem, e todo não-terminal tem que ter uma derivação que chegue no que foi escrito. Foi exatamente essa checagem que reprovou `input(x)` e `retorna x + 1` — duas instruções que "parecem certas" e não são.

---

## Observações sobre o Material 3 (não caem na prova, mas valem pro tradutor)

Inconsistências reais do slide, anotadas pra não virarem bug quando a Unidade IV for implementada:

1. **`<string>` nunca é definida.** A regra `<entrada>` usa `<string>` como argumento do `input`, mas não existe nenhuma linha `<string> ::= ...` na gramática. É um não-terminal órfão — o parser vai precisar dessa regra pra funcionar.
2. **O LEXER do slide não bate com a BNF do slide.** A lista `TOKENS_FONTE` define os tokens `ESCREVA` (`\bescreva\b`) e `LEIA` (`\bleia\b`), enquanto a gramática usa os literais `"print"` e `"input"`. Um dos dois está desatualizado; decidir qual antes de escrever o parser.
3. **`<operador_relacional>` só tem `==`, `<` e `>`.** Não há `!=`, `>=` nem `<=`. A negação é feita pela regra `"!" <condicao>`, então `x != y` se escreve `!(x == y)`. Isso resolve a pendência do `!=` que ficou anotada no `Exercicio C` — a linguagem já tem como expressar, só não com um operador dedicado.
4. **Precedência está correta na gramática do MineonScript** (`<expressao>` → `<termo>` → `<fator>`, com `*` `/` no nível mais interno), mas a **proposta de solução do KK-102 no mesmo slide abandona esse cuidado** e usa `<operacao_binaria> ::= <expressao> "op" <expressao>`, que é ambígua. Ver a decisão de projeto em [Exercicio BNF KK-102.md](Exercicio%20BNF%20KK-102.md).
