# Exercício C — Jogo de adivinhação (1 a 100)

> Programa registra número oculto de 1 a 100; jogador chuta até acertar. Feedback: É maior / É menor / É bem maior / É bem menor / Acertou. "Bem" = diferença maior que 20. Programa tem "memória curta": só lembra do último palpite.
> Extensões usadas: `aleatorio`, `enquanto ... faca ... fim`, `>=`, `<=`.

```
declarar segredo, palpite, diferenca

aleatorio segredo

mostrar "Adivinhe o número de 1 a 100: "
ler palpite

enquanto palpite > segredo faca
    diferenca = palpite - segredo
    se diferenca > 20 entao
        mostrar "É bem menor!"
    senao
        mostrar "É menor!"
    fim
    mostrar "Tente de novo: "
    ler palpite
fim

enquanto palpite < segredo faca
    diferenca = segredo - palpite
    se diferenca > 20 entao
        mostrar "É bem maior!"
    senao
        mostrar "É maior!"
    fim
    mostrar "Tente de novo: "
    ler palpite
fim

mostrar "Acertou!"
```

**Nota:** os dois `enquanto` em sequência não cobrem o jogador que alterna entre chutar alto e baixo. Versão robusta exige laço único com condição composta (`palpite != segredo`), que a linguagem ainda não tem — proposta natural de extensão: operador `!=` e/ou `enquanto palpite != segredo faca`.
