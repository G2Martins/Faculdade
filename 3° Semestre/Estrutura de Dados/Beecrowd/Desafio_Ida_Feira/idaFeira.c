#include <stdio.h>
#include <string.h>

int main() {
    int N, M, P, i, j, qtd;
    char produto[51], lista[51];
    double preco, total;

    scanf("%d", &N);
    while (N--) {
        scanf("%d", &M);
        char produtos[M][51];
        double precos[M];

        for (i = 0; i < M; i++) {
            scanf("%s %lf", produtos[i], &precos[i]);
        }

        scanf("%d", &P);
        total = 0.0;
        for (i = 0; i < P; i++) {
            scanf("%s %d", lista, &qtd);
            for (j = 0; j < M; j++) {
                if (strcmp(lista, produtos[j]) == 0) {
                    total += qtd * precos[j];
                    break;
                }
            }
        }
        printf("R$ %.2lf\n", total);
    }

    return 0;
}
