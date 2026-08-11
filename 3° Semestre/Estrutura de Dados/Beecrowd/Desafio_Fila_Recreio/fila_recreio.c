#include <stdio.h>

int main() {
    int numeroDeTestes, numeroDeAlunos, i, j, contador;
    int notasDosAlunos[1000], notasOrdenadas[1000];

    scanf("%d", &numeroDeTestes);

    while (numeroDeTestes--) 
    {
        scanf("%d", &numeroDeAlunos);

        for (i = 0; i < numeroDeAlunos; i++) {
            scanf("%d", &notasDosAlunos[i]);
            notasOrdenadas[i] = notasDosAlunos[i];
        }

        // Ordenando o array de notas
        for (i = 0; i < numeroDeAlunos; i++) {
            for (j = i + 1; j < numeroDeAlunos; j++) {
                if (notasOrdenadas[i] < notasOrdenadas[j]) {
                    int temp = notasOrdenadas[i];
                    notasOrdenadas[i] = notasOrdenadas[j];
                    notasOrdenadas[j] = temp;
                }
            }
        }

        // Contando o número de alunos que não precisaram trocar de lugar
        contador = 0;
        for (i = 0; i < numeroDeAlunos; i++) {
            if (notasDosAlunos[i] == notasOrdenadas[i]) {
                contador++;
            }
        }

        printf("%d\n", contador);
    }

    return 0;
}
