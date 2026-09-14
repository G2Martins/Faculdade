"""
Analisador léxico (tokenizer) do MineonScript.

Uso:
    python lexer.py <arquivo.mines> [-coment]

Sem o argumento -coment, os comentários de linha são descartados junto com os
espaços em branco (comportamento padrão de um lexer). Com -coment, eles entram
no fluxo de tokens como qualquer outro token.

Material 3 / Aula 04 — Prof. Roger Rocha Ferreira.
"""

import re
import sys

# Definição dos tipos de tokens e seus padrões.
#
# A ORDEM DESTA LISTA É A REGRA DE DESEMPATE do lexer: o laço de análise varre
# a lista de cima para baixo e para no primeiro padrão que casar. Padrão mais
# longo tem que vir antes do prefixo dele, senão o prefixo vence e o token
# longo nunca é reconhecido. Os três casos onde isso importa estão marcados.
TOKENS = [
    ("COMENTARIO",  r"//.*"),                       # ANTES de DIV: senão "//" vira dois tokens DIV
    ("ESPACO",      r"\s+"),

    ("SE",          r"\bse\b"),
    ("SENAO",       r"\bsenao\b"),
    ("ENQUANTO",    r"\benquanto\b"),
    ("ESCREVA",     r"\bescreva\b"),
    ("LEIA",        r"\bleia\b"),
    ("RETORNO",     r"\bretorna\b"),

    ("IGUALDADE",   r"=="),                         # ANTES de IGUAL: senão "==" vira dois tokens IGUAL
    ("IGUAL",       r"="),
    ("MAIOR",       r">"),
    ("MENOR",       r"<"),
    ("NEGACAO",     r"!"),

    ("SOMA",        r"\+"),
    ("SUB",         r"-"),
    ("MULT",        r"\*"),
    ("DIV",         r"/"),                          # DEPOIS de COMENTARIO

    ("ABRE_CHAVE",  r"\{"),
    ("FECHA_CHAVE", r"\}"),
    ("ABRE_PAR",    r"\("),
    ("FECHA_PAR",   r"\)"),

    ("NUMERO",      r"\d+"),
    ("TEXTO",       r"\".*?\""),
    ("NOME",        r"[a-zA-Z_][a-zA-Z0-9_]*"),     # ÚLTIMO: casa com qualquer palavra reservada também
]

# Tokens que o lexer reconhece mas não repassa para o parser.
DESCARTADOS = {"ESPACO", "COMENTARIO"}


def compilar_tokens():
    """Traduz cada padrão de string para autômato (objeto compilado do re)."""
    TOKENS_COMP = []
    for tipo, padrao in TOKENS:
        regex_comp = re.compile(padrao)
        TOKENS_COMP.append((tipo, regex_comp))
    return TOKENS_COMP


def analisar(codigo, TOKENS_COMP, manter_comentario=False):
    """Percorre o código e devolve a lista de tokens (tipo, lexema, linha)."""
    descartados = DESCARTADOS - {"COMENTARIO"} if manter_comentario else DESCARTADOS

    tokens = []
    pos = 0
    while pos < len(codigo):
        match = None
        for tipo, padrao in TOKENS_COMP:
            match = padrao.match(codigo, pos)
            if match:
                if tipo not in descartados:
                    linha = codigo.count("\n", 0, pos) + 1
                    tokens.append((tipo, match.group(0), linha))
                pos = match.end(0)
                break
        if not match:
            linha = codigo.count("\n", 0, pos) + 1
            coluna = pos - (codigo.rfind("\n", 0, pos) + 1) + 1
            raise SyntaxError(
                f"Caractere inesperado: {codigo[pos]!r} (linha {linha}, coluna {coluna})"
            )
    return tokens


def main():
    argumentos = sys.argv[1:]
    manter_comentario = "-coment" in argumentos
    arquivos = [a for a in argumentos if not a.startswith("-")]

    if len(arquivos) != 1:
        print("Uso: python lexer.py <arquivo.mines> [-coment]", file=sys.stderr)
        return 1

    try:
        with open(arquivos[0], encoding="utf-8") as f:
            codigo = f.read()
    except OSError as erro:
        print(f"Não foi possível ler o arquivo: {erro}", file=sys.stderr)
        return 1

    try:
        tokens = analisar(codigo, compilar_tokens(), manter_comentario)
    except SyntaxError as erro:
        print(f"Erro léxico: {erro}", file=sys.stderr)
        return 1

    print(f"{'LINHA':>5}  {'TOKEN':<12}  LEXEMA")
    for tipo, lexema, linha in tokens:
        print(f"{linha:>5}  {tipo:<12}  {lexema!r}")
    print(f"\n{len(tokens)} tokens reconhecidos.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
