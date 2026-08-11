# Exercício B — Sistema de notas (3 notas, média e conceito)

> Extensões: operadores `>=` e `<=`. Extra do slide: validação das notas (0 a 10) com `enquanto` para evitar médias inexistentes como -1 ou 14.

```
declarar n1, n2, n3, media

mostrar "Digite a nota 1 (0 a 10): "
ler n1
enquanto n1 < 0 faca
    mostrar "Nota inválida. Digite novamente (0 a 10): "
    ler n1
fim
enquanto n1 > 10 faca
    mostrar "Nota inválida. Digite novamente (0 a 10): "
    ler n1
fim

mostrar "Digite a nota 2 (0 a 10): "
ler n2
enquanto n2 < 0 faca
    mostrar "Nota inválida. Digite novamente (0 a 10): "
    ler n2
fim
enquanto n2 > 10 faca
    mostrar "Nota inválida. Digite novamente (0 a 10): "
    ler n2
fim

mostrar "Digite a nota 3 (0 a 10): "
ler n3
enquanto n3 < 0 faca
    mostrar "Nota inválida. Digite novamente (0 a 10): "
    ler n3
fim
enquanto n3 > 10 faca
    mostrar "Nota inválida. Digite novamente (0 a 10): "
    ler n3
fim

media = (n1 + n2 + n3) / 3

mostrar "Média: "
mostrar media

se media >= 7 entao
    mostrar "Aprovado"
senao
    se media >= 5 entao
        mostrar "Recuperação"
    senao
        mostrar "Reprovado"
    fim
fim
```
