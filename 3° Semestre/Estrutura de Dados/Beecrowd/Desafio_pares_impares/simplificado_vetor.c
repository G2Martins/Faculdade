#include <stdio.h>
#include <stdlib.h>

int compare_asc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int compare_desc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main(){
    int total_operacoes;
    scanf("%d", &total_operacoes);
    
    int *par = (int *) malloc(total_operacoes * sizeof(int));
    int *impar = (int *) malloc(total_operacoes * sizeof(int));
    int numero;
    int indice_par = 0, indice_impar = 0;

    for(int i = 0; i < total_operacoes; i++){
        scanf("%d", &numero);

        if( numero % 2 == 0)
            par[indice_par++] = numero;
        else
            impar[indice_impar++] = numero;
    }
    
    qsort(par, indice_par, sizeof(int), compare_asc);
    qsort(impar, indice_impar, sizeof(int), compare_desc);

    for(int i = 0; i < indice_par; i++)
        printf("%d\n", par[i]);

    for(int i = 0; i < indice_impar; i++)
        printf("%d\n", impar[i]);

    free(par);
    free(impar);

    return 0;
}
