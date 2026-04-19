#include <stdio.h>
#include <stdlib.h>

void reordenar_par(int *par, int indice_par);
void reordenar_impar(int *impar, int indice_impar);
void mostrar_vetor(int *vetor, int indice);
void mostrar_vetor_impar(int *vetor, int indice);
void concatenar(int *vetor1, int *vetor2, int tam1, int tam2);


int main(){
    int total_operacoes;

    scanf("%d", &total_operacoes);
    
    
    int *par = (int *) malloc(total_operacoes * sizeof(int));
    int *impar = (int *) malloc(total_operacoes * sizeof(int));
    int numero;
    int indice_par = -1, indice_impar = -1;

    for(int i = 0; i < total_operacoes; i++){
        scanf("%d", &numero);

        if( numero % 2 == 0)
        {
            par[++indice_par] = numero;
            

        }
        else
        {
            impar[++indice_impar] = numero;
        }
    }
    
    reordenar_par(par, indice_par);
    reordenar_impar(impar, indice_impar);

    concatenar(par, impar, indice_par + 1, indice_impar + 1);


    free(par);
    free(impar);


    return 0;
}

void reordenar_par(int *par, int indice_par)
{
    // Aplicar Bubble Sort para ordenar o vetor par em ordem crescente
    for (int i = 0; i < indice_par; i++) {
        for (int j = 0; j < indice_par - i; j++) {
            if (par[j] > par[j + 1]) {
                int temp = par[j];
                par[j] = par[j + 1];
                par[j + 1] = temp;
            }
        }
    }
}

void reordenar_impar(int *impar, int indice_impar)
{
    // Aplicar Bubble Sort para ordenar o vetor impar em ordem decrescente
    for (int i = 0; i < indice_impar; i++) {
        for (int j = 0; j < indice_impar - i; j++) {
            if (impar[j] < impar[j + 1]) {
                int temp = impar[j];
                impar[j] = impar[j + 1];
                impar[j + 1] = temp;
            }
        }
    }
}


void mostrar_vetor(int *vetor, int indice)
{
    printf("Vetor: ");
    for(int i = 0; i <= indice; i++)  // Ajuste na condição do loop
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");  // Adicionar nova linha para separar a saída dos dois vetores
}

void mostrar_vetor_impar(int *vetor, int indice)
{
    printf("Vetor: ");
    for (int i = indice; i >= 0; i--)  // Loop de i = indice até 0 (ordem decrescente)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");  // Adicionar nova linha para separar a saída dos dois vetores
}

void concatenar(int *vetor1, int *vetor2, int tam1, int tam2) {
    int i = 0, j = 0;

    printf("\n");
    // Imprimir vetor de pares em ordem crescente
    while (i < tam1) {
        printf("%d\n", vetor1[i++]);
    }
    // Imprimir vetor de ímpares em ordem decrescente
    while (j < tam2) {
        printf("%d\n", vetor2[j++]);
    }
    
    printf("\n");
}