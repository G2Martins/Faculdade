# Exercício E — Fila de banco com prioridades

> Fila única com fichas: G (Gestante) > I (Idoso) > P (PcD) > N (Normal). Desempate: quem chegou primeiro (fila já ordenada por chegada). Entrada: lista `[P, I, G, N, I]` → Saída: ordem de atendimento (`G, I, I, P, N`).
>
> A dica do professor permite termos como "lista de números"; usamos extensões de lista: `lista`, `tamanho(l)`, `contem(l, x)` (existe elemento?), `remover_primeiro(l, x)` (remove e retorna o primeiro `x` da lista, respeitando ordem de chegada).

```
declarar fila, proximo

fila = [P, I, G, N, I]

enquanto tamanho(fila) > 0 faca

    se contem(fila, G) entao
        proximo = remover_primeiro(fila, G)
    senao
        se contem(fila, I) entao
            proximo = remover_primeiro(fila, I)
        senao
            se contem(fila, P) entao
                proximo = remover_primeiro(fila, P)
            senao
                proximo = remover_primeiro(fila, N)
            fim
        fim
    fim

    mostrar "Atender: "
    mostrar proximo
fim
```

**Saída para `[P, I, G, N, I]`:** `G, I, I, P, N`.

**Extra — evitar espera "eterna" do Normal:** sistema de *aging* (envelhecimento): a cada ciclo, quem espera ganha pontos; após X ciclos sem atendimento, a ficha Normal é promovida de prioridade (ou regra fixa: a cada 3 prioritários atendidos, atende-se 1 Normal). Garante que ninguém fica indefinidamente na fila.
