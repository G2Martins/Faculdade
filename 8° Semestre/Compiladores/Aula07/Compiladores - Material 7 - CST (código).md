"""  
CST do MineonScript \- Compiladores, Material 7  
\==============================================

Monta a CST (Árvore de Sintaxe Concreta) de um programa MineonScript, mostra que ela devolve o texto original e, por fim, constrói a AST (a mesma do Material 5\) a partir da CST.

Só usa a biblioteca padrão do Python (nada de pip, Java ou VSCode).

Uso:  
  python3 cst\_mineonscript.py                      \-\> usa o programa de exemplo  
  python3 cst\_mineonscript.py programa.mines       \-\> lê um arquivo .mines  
  python3 cst\_mineonscript.py \-e "x \= 2 \* (3 \+ 4)" \-\> uma única instrução  
  python3 cst\_mineonscript.py programa.mines \--renomear x valor  
                                                   \-\> refatoração pela CST  
"""  
import re  
import sys

\# \---------------------------------------------------------------------  
\# 1\. LEXER  
\#    Igual ao do Material 5, com uma diferença: espaços e comentários  
\#    NÃO são jogados fora. Eles ficam guardados no "prefixo" do token  
\#    seguinte, para que a CST consiga reconstruir o texto original.  
\# \---------------------------------------------------------------------  
TOKENS \= \[  
    ("COMENTARIO", r"//.\*"),  
    ("ESPACO", r"\\s+"),  
    ("SE", r"\\bse\\b"),  
    ("SENAO", r"\\bsenao\\b"),  
    ("ENQUANTO", r"\\benquanto\\b"),  
    ("ESCREVA", r"\\bescreva\\b"),  
    ("LEIA", r"\\bleia\\b"),  
    ("RETORNO", r"\\bretorna\\b"),  
    ("IGUALDADE", r"=="),  
    ("IGUAL", r"="),  
    ("MAIOR", r"\>"),  
    ("MENOR", r"\<"),  
    ("NEGACAO", r"\!"),  
    ("SOMA", r"\\+"),  
    ("SUB", r"-"),  
    ("MUL", r"\\\*"),  
    ("DIV", r"/"),  
    ("ABRE\_CHAVE", r"\\{"),  
    ("FECHA\_CHAVE", r"\\}"),  
    ("ABRE\_PAR", r"\\("),  
    ("FECHA\_PAR", r"\\)"),  
    ("NUMERO", r"\\d+"),  
    ("TEXTO", r"\\".\*?\\""),  
    ("NOME", r"\[a-zA-Z\_\]\[a-zA-Z0-9\_\]\*"),  
\]  
TOKENS\_COMPILADOS \= \[(tipo, re.compile(padrao)) for tipo, padrao in TOKENS\]

class Token:  
    def \_\_init\_\_(self, tipo, texto, prefixo):  
        self.tipo \= tipo        \# ex.: "NUMERO"  
        self.texto \= texto      \# ex.: "42"  
        self.prefixo \= prefixo  \# espaços e comentários que vieram ANTES dele

def lexer(codigo):  
    tokens \= \[\]  
    pos \= 0  
    prefixo \= ""  \# acumula espaços/comentários até aparecer um token "de verdade"  
    while pos \< len(codigo):  
        for tipo, padrao in TOKENS\_COMPILADOS:  
            achou \= padrao.match(codigo, pos)  
            if achou:  
                texto \= achou.group(0)  
                if tipo in ("ESPACO", "COMENTARIO"):  
                    prefixo \+= texto  
                else:  
                    tokens.append(Token(tipo, texto, prefixo))  
                    prefixo \= ""  
                pos \= achou.end()  
                break  
        else:  
            raise SyntaxError(f"Caractere inesperado: '{codigo\[pos\]}' na posição {pos}")  
    tokens.append(Token("EOF", "", prefixo))  \# o que sobrou no fim do arquivo  
    return tokens

\# \---------------------------------------------------------------------  
\# 2\. NÓ DA CST  
\#    \- nó interno: uma regra da gramática, ex.: \<expressao\>  
\#    \- folha: um token, ex.: NUMERO "2"  
\# \---------------------------------------------------------------------  
class NoCST:  
    def \_\_init\_\_(self, rotulo, filhos=None, token=None):  
        self.rotulo \= rotulo  
        self.filhos \= filhos if filhos is not None else \[\]  
        self.token \= token  \# só as folhas têm token

    def eh\_folha(self):  
        return self.token is not None

    def descricao(self):  
        if not self.eh\_folha():  
            return self.rotulo                      \# ex.: \<expressao\>  
        if self.rotulo \== "EOF":  
            texto \= "EOF"  
        elif self.rotulo \== "TEXTO":  
            texto \= f"TEXTO {self.token.texto}"     \# o texto já tem aspas  
        else:  
            texto \= f'{self.rotulo} "{self.token.texto}"'  
        comentarios \= re.findall(r"//.\*", self.token.prefixo)  
        if comentarios:                             \# a CST guarda até os comentários\!  
            texto \+= "   \<- " \+ " ".join(comentarios)  
        return texto

def desenhar(no, margem="", ultimo=True, raiz=True):  
    """Desenha a árvore com ├── e └── (o mesmo formato do slide)."""  
    if raiz:  
        linhas \= \[no.descricao()\]  
        nova\_margem \= ""  
    else:  
        linhas \= \[margem \+ ("└── " if ultimo else "├── ") \+ no.descricao()\]  
        nova\_margem \= margem \+ ("    " if ultimo else "│   ")  
    for i, filho in enumerate(no.filhos):  
        eh\_ultimo \= i \== len(no.filhos) \- 1  
        linhas.append(desenhar(filho, nova\_margem, eh\_ultimo, raiz=False))  
    return "\\n".join(linhas)

\# \---------------------------------------------------------------------  
\# 3\. PARSER QUE CONSTRÓI A CST  
\#    Cada método corresponde a uma regra da BNF e devolve um NoCST  
\#    com TODOS os filhos: regras, palavras-chave, parênteses e chaves.  
\# \---------------------------------------------------------------------  
class ParserCST:  
    def \_\_init\_\_(self, tokens):  
        self.tokens \= tokens  
        self.pos \= 0

    def atual(self, adiante=0):  
        """Tipo do token atual (ou de um token mais à frente)."""  
        indice \= min(self.pos \+ adiante, len(self.tokens) \- 1\)  
        return self.tokens\[indice\].tipo

    def consumir(self, tipo\_esperado):  
        """Confere o token, avança e devolve uma FOLHA da CST."""  
        token \= self.tokens\[self.pos\]  
        if token.tipo \!= tipo\_esperado:  
            raise SyntaxError(  
                f"Erro Sintático: esperado '{tipo\_esperado}', "  
                f"encontrado '{token.tipo}' ('{token.texto}')"  
            )  
        self.pos \+= 1  
        return NoCST(token.tipo, token=token)

    \# \<programa\> ::= \<instrucoes\> \<retorno\>  
    def programa(self):  
        no \= NoCST("\<programa\>", \[self.instrucoes(), self.retorno()\])  
        no.filhos.append(self.consumir("EOF"))  \# guarda o final do arquivo  
        return no

    \# \<instrucoes\> ::= { \<instrucao\> }  
    def instrucoes(self):  
        no \= NoCST("\<instrucoes\>")  
        while self.atual() not in ("FECHA\_CHAVE", "RETORNO", "EOF"):  
            no.filhos.append(self.instrucao())  
        return no

    \# \<instrucao\> ::= \<atribuicao\> \| \<entrada\> \| \<saida\> \| \<condicional\> \| \<loop\>  
    def instrucao(self):  
        if self.atual() \== "NOME" and self.atual(2) \== "LEIA":  
            filho \= self.entrada()  
        elif self.atual() \== "NOME":  
            filho \= self.atribuicao()  
        elif self.atual() \== "ESCREVA":  
            filho \= self.saida()  
        elif self.atual() \== "SE":  
            filho \= self.condicional()  
        elif self.atual() \== "ENQUANTO":  
            filho \= self.loop()  
        else:  
            raise SyntaxError(f"Instrução inválida iniciando com '{self.atual()}'")  
        return NoCST("\<instrucao\>", \[filho\])

    \# \<atribuicao\> ::= NOME IGUAL \<expressao\>  
    def atribuicao(self):  
        return NoCST("\<atribuicao\>", \[  
            self.consumir("NOME"),  
            self.consumir("IGUAL"),  
            self.expressao(),  
        \])

    \# \<entrada\> ::= NOME IGUAL LEIA ABRE\_PAR TEXTO FECHA\_PAR  
    def entrada(self):  
        return NoCST("\<entrada\>", \[  
            self.consumir("NOME"),  
            self.consumir("IGUAL"),  
            self.consumir("LEIA"),  
            self.consumir("ABRE\_PAR"),  
            self.consumir("TEXTO"),  
            self.consumir("FECHA\_PAR"),  
        \])

    \# \<saida\> ::= ESCREVA ABRE\_PAR \<expressao\> FECHA\_PAR  
    def saida(self):  
        return NoCST("\<saida\>", \[  
            self.consumir("ESCREVA"),  
            self.consumir("ABRE\_PAR"),  
            self.expressao(),  
            self.consumir("FECHA\_PAR"),  
        \])

    \# \<condicional\> ::= SE \<condicao\> ABRE\_CHAVE \<instrucoes\> FECHA\_CHAVE  
    \#                   \[ SENAO ABRE\_CHAVE \<instrucoes\> FECHA\_CHAVE \]  
    def condicional(self):  
        no \= NoCST("\<condicional\>", \[  
            self.consumir("SE"),  
            self.condicao(),  
            self.consumir("ABRE\_CHAVE"),  
            self.instrucoes(),  
            self.consumir("FECHA\_CHAVE"),  
        \])  
        if self.atual() \== "SENAO":  
            no.filhos \+= \[  
                self.consumir("SENAO"),  
                self.consumir("ABRE\_CHAVE"),  
                self.instrucoes(),  
                self.consumir("FECHA\_CHAVE"),  
            \]  
        return no

    \# \<loop\> ::= ENQUANTO \<condicao\> ABRE\_CHAVE \<instrucoes\> FECHA\_CHAVE  
    def loop(self):  
        return NoCST("\<loop\>", \[  
            self.consumir("ENQUANTO"),  
            self.condicao(),  
            self.consumir("ABRE\_CHAVE"),  
            self.instrucoes(),  
            self.consumir("FECHA\_CHAVE"),  
        \])

    \# \<condicao\> ::= \<expressao\> \<operador\_relacional\> \<expressao\>  
    \#              \| NEGACAO \<condicao\>  
    def condicao(self):  
        if self.atual() \== "NEGACAO":  
            return NoCST("\<condicao\>", \[self.consumir("NEGACAO"), self.condicao()\])  
        return NoCST("\<condicao\>", \[  
            self.expressao(),  
            self.operador\_relacional(),  
            self.expressao(),  
        \])

    \# \<operador\_relacional\> ::= IGUALDADE \| MENOR \| MAIOR  
    def operador\_relacional(self):  
        if self.atual() not in ("IGUALDADE", "MENOR", "MAIOR"):  
            raise SyntaxError(f"Operador relacional esperado, encontrado '{self.atual()}'")  
        return NoCST("\<operador\_relacional\>", \[self.consumir(self.atual())\])

    \# \<expressao\> ::= \<termo\> { ( SOMA \| SUB ) \<termo\> }  
    def expressao(self):  
        no \= NoCST("\<expressao\>", \[self.termo()\])  
        while self.atual() in ("SOMA", "SUB"):  
            no.filhos \+= \[self.consumir(self.atual()), self.termo()\]  
        return no

    \# \<termo\> ::= \<fator\> { ( MUL \| DIV ) \<fator\> }  
    def termo(self):  
        no \= NoCST("\<termo\>", \[self.fator()\])  
        while self.atual() in ("MUL", "DIV"):  
            no.filhos \+= \[self.consumir(self.atual()), self.fator()\]  
        return no

    \# \<fator\> ::= NUMERO \| NOME \| TEXTO \| ABRE\_PAR \<expressao\> FECHA\_PAR  
    def fator(self):  
        if self.atual() in ("NUMERO", "NOME", "TEXTO"):  
            return NoCST("\<fator\>", \[self.consumir(self.atual())\])  
        if self.atual() \== "ABRE\_PAR":  
            return NoCST("\<fator\>", \[  
                self.consumir("ABRE\_PAR"),  
                self.expressao(),  
                self.consumir("FECHA\_PAR"),  
            \])  
        raise SyntaxError(f"Fator inesperado: '{self.atual()}'")

    \# \<retorno\> ::= RETORNO NUMERO  
    def retorno(self):  
        return NoCST("\<retorno\>", \[self.consumir("RETORNO"), self.consumir("NUMERO")\])

\# \---------------------------------------------------------------------  
\# 4\. A CST NÃO PERDE NADA: basta ler as folhas da esquerda para a direita  
\# \---------------------------------------------------------------------  
def folhas(no):  
    if no.eh\_folha():  
        return \[no\]  
    resultado \= \[\]  
    for filho in no.filhos:  
        resultado \+= folhas(filho)  
    return resultado

def para\_texto(cst):  
    return "".join(f.token.prefixo \+ f.token.texto for f in folhas(cst))

def renomear(cst, antigo, novo):  
    """Refatoração: troca o nome de uma variável sem mexer em espaços e comentários."""  
    for folha in folhas(cst):  
        if folha.rotulo \== "NOME" and folha.token.texto \== antigo:  
            folha.token.texto \= novo

\# \---------------------------------------------------------------------  
\# 5\. DA CST PARA A AST (a mesma NoAST do Material 5\)  
\# \---------------------------------------------------------------------  
class NoAST:  
    def \_\_init\_\_(self, tipo, valor=None, filhos=None):  
        self.tipo \= tipo  
        self.valor \= valor  
        self.filhos \= filhos if filhos is not None else \[\]

    def \_\_repr\_\_(self, level=0):  
        ret \= "  " \* level \+ f"\[{self.tipo}"  
        if self.valor is not None:  
            ret \+= f": {self.valor}"  
        ret \+= "\]\\n"  
        for filho in self.filhos:  
            ret \+= filho.\_\_repr\_\_(level \+ 1\)  
        return ret

def cst\_para\_ast(no):  
    f \= no.filhos  \# atalho

    if no.rotulo \== "\<programa\>":  
        return NoAST("PROGRAMA", filhos=\[cst\_para\_ast(f\[0\]), cst\_para\_ast(f\[1\])\])

    if no.rotulo \== "\<instrucoes\>":  
        return NoAST("INSTRUCOES", filhos=\[cst\_para\_ast(filho) for filho in f\])

    if no.rotulo \== "\<instrucao\>":  \# cadeia unitária: some na AST  
        return cst\_para\_ast(f\[0\])

    if no.rotulo \== "\<atribuicao\>":  \# NOME IGUAL \<expressao\>  
        return NoAST("ATRIBUICAO", "=", \[NoAST("IDENTIFICADOR", f\[0\].token.texto),  
                                         cst\_para\_ast(f\[2\])\])

    if no.rotulo \== "\<entrada\>":  \# NOME IGUAL LEIA ( TEXTO )  
        return NoAST("ENTRADA", filhos=\[NoAST("IDENTIFICADOR", f\[0\].token.texto),  
                                        NoAST("TEXTO", f\[4\].token.texto)\])

    if no.rotulo \== "\<saida\>":  \# ESCREVA ( \<expressao\> )  
        return NoAST("SAIDA", filhos=\[cst\_para\_ast(f\[2\])\])

    if no.rotulo \== "\<condicional\>":  \# SE \<condicao\> { ... } \[SENAO { ... }\]  
        filhos \= \[cst\_para\_ast(f\[1\]), cst\_para\_ast(f\[3\])\]  
        if len(f) \> 5:  
            filhos.append(cst\_para\_ast(f\[7\]))  
        return NoAST("CONDICIONAL", filhos=filhos)

    if no.rotulo \== "\<loop\>":  \# ENQUANTO \<condicao\> { ... }  
        return NoAST("LOOP", filhos=\[cst\_para\_ast(f\[1\]), cst\_para\_ast(f\[3\])\])

    if no.rotulo \== "\<condicao\>":  
        if f\[0\].eh\_folha():  \# NEGACAO \<condicao\>  
            return NoAST("CONDICAO", "\!", \[cst\_para\_ast(f\[1\])\])  
        operador \= f\[1\].filhos\[0\].token.texto  
        return NoAST("CONDICAO", operador, \[cst\_para\_ast(f\[0\]), cst\_para\_ast(f\[2\])\])

    if no.rotulo in ("\<expressao\>", "\<termo\>"):  
        \# \[operando, op, operando, op, operando ...\] vira uma árvore inclinada à esquerda  
        esq \= cst\_para\_ast(f\[0\])  
        for i in range(1, len(f), 2):  
            esq \= NoAST("EXPRESSAO", f\[i\].token.texto, \[esq, cst\_para\_ast(f\[i \+ 1\])\])  
        return esq

    if no.rotulo \== "\<fator\>":  
        if len(f) \== 3:  \# ( \<expressao\> ): os parênteses somem  
            return cst\_para\_ast(f\[1\])  
        token \= f\[0\].token  
        tipo \= {"NUMERO": "NUMERO", "NOME": "IDENTIFICADOR", "TEXTO": "TEXTO"}\[token.tipo\]  
        return NoAST(tipo, token.texto)

    if no.rotulo \== "\<retorno\>":  
        return NoAST("RETORNO", f\[1\].token.texto)

    raise ValueError(f"Nó desconhecido: {no.rotulo}")

def contar\_cst(no):  
    return 1 \+ sum(contar\_cst(filho) for filho in no.filhos)

def contar\_ast(no):  
    return 1 \+ sum(contar\_ast(filho) for filho in no.filhos)

\# \---------------------------------------------------------------------  
\# 6\. PROGRAMA PRINCIPAL  
\# \---------------------------------------------------------------------  
EXEMPLO \= """// calcula o dobro de um valor positivo  
x \= leia("Digite um valor: ")  
se x \> 0 {  
    escreva(x \* 2\)   // dobro  
} senao {  
    escreva("VALOR INVALIDO")  
}  
retorna 0  
"""

def titulo(texto):  
    print("\\n" \+ "=" \* 60 \+ f"\\n{texto}\\n" \+ "=" \* 60\)

def principal(args):

    if args\[:1\] \== \["-?"\]:  
        print(\_\_doc\_\_)  
        return

    if args\[:1\] \== \["-e"\]:  \# uma única instrução, ex.: \-e "x \= 2 \* (3 \+ 4)"  
        codigo \= args\[1\]  
        parser \= ParserCST(lexer(codigo))  
        cst \= parser.instrucao()  
        parser.consumir("EOF")  
    else:  
        if args and not args\[0\].startswith("--"):  
            with open(args\[0\], "r", encoding="utf-8") as arquivo:  
                codigo \= arquivo.read()  
        else:  
            codigo \= EXEMPLO  
        cst \= ParserCST(lexer(codigo)).programa()

    titulo("1. CÓDIGO-FONTE")  
    print(codigo)

    titulo("2. CST \- ÁRVORE DE SINTAXE CONCRETA")  
    print(desenhar(cst))

    titulo("3. A CST DEVOLVE O TEXTO ORIGINAL?")  
    print("Sim, caractere por caractere." if para\_texto(cst) \== codigo else "Não\!")

    if "--renomear" in args:  
        i \= args.index("--renomear")  
        antigo, novo \= args\[i \+ 1\], args\[i \+ 2\]  
        renomear(cst, antigo, novo)  
        titulo(f"3b. REFATORAÇÃO PELA CST: {antigo} \-\> {novo} (comentários preservados)")  
        print(para\_texto(cst))

    titulo("4. AST \- CONSTRUÍDA A PARTIR DA CST")  
    ast \= cst\_para\_ast(cst)  
    print(ast, end="")

    titulo("5. COMPARAÇÃO")  
    print(f"CST: {contar\_cst(cst)} nós   \|   AST: {contar\_ast(ast)} nós")

if \_\_name\_\_ \== "\_\_main\_\_":  
    try:  
        principal(sys.argv\[1:\])  
    except SyntaxError as erro:  
        print(f"\\n{erro}")  
        sys.exit(1)  
