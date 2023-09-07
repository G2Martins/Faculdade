# Repositório destinado aos trabalhos/Projetos do Semestre

## Projeto 1
### Explicação do Projeto:
- Considere um array de inteiros bidimensional (matriz) imagem[10][10].
- Na memória essa matriz é representada de forma sequencial, onde cada elemento (pixel)
da imagem, corresponde à um inteiro de 4 bytes, sendo o byte 1 podendo representar o canal alfa
(A), o byte 2 o canal azul (B), o byte 3 o canal verde (G) e o byte 4 o canal vermelho (R).
### +------------------------------------ A Partir disso ----------------------------------------------+
- Exercício 1: Utilize o ponteiro pchar para acessar byte a byte de cada pixel da imagem2 e
remover a cor vermelha, como por exemplo: pchar[3] = 0 ou *(pchar+3) = 0.

- Exercício 2 - Utilize o ponteiro pchar para acessar byte a byte de cada pixel da imagem3 e
transformá-la em uma imagem em escala de cinza. A escala de cinza pode ser definida atribuindo
aos canais R, G e B média de seus valores, como por exemplo:
unsigned char cinza = (pchar[1] + pchar[2] + pchar[3])/3;
pchar[1] = cinza; pchar[2] = cinza; pchar[3] = cinza.
### +--------------------------------------------------------------------------+
