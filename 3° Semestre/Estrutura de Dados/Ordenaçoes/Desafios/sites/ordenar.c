#include <stdio.h>

void imprimeArray(int arr[], int size); 
void Bubble(int vetor[], int tamanho);
void troca(int* xp, int* yp);
void ordenacaoPorSelecao(int arr[], int n);

int main () {

    int opcao;
    printf("+--------------------------------+");
    printf("+- Escolha o tipo de ordenação  -+\n");
    printf("+- 1. Ordenacao por Bubble      -+\n");
    printf("+- 2. Ordenacao por Selection   -+\n");
    printf("Digite a opcao: ");
    scanf("%d", &opcao);

    int array[] = {3, 4, 9, 2, 5, 1, 8};
    int tamanho = sizeof(array) / sizeof(array[0]);

    switch(opcao) {
        case 1:
            Bubble(array, tamanho);
            printf("Array ordenado por BubbleSort: \n");
            imprimeArray(array, tamanho);
            break;
        case 2:
            printf("Array ordenado por Fusão: \n");
            break;
        default:
            printf("Opção inválida!\n");
    }

    return 0;
}

// Função que ordena por bubbleSort
void Bubble(int vetor[], int tamanho){
    
    int pass, i, aux;
    int trocou = 1;

    for (pass = 0; pass < tamanho - 1 && trocou; pass++)
    {
        trocou=0;
        for (i = 0; i < tamanho - 1 - pass; i++)
        {
            if (vetor[i] > vetor[i + 1])
            
            {
                trocou=1;
                aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
            }
        }
    }

}

// Função para imprimir um array
void imprimeArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Função para trocar dois elementos
void troca(int* xp, int* yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Função para implementar o Selection Sort
void ordenacaoPorSelecao(int arr[], int n) {
    int i, j, indice_min;

    for (i = 0; i < n - 1; i++) {
        indice_min = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[indice_min])
                indice_min = j;

        troca(&arr[indice_min], &arr[i]);
    }
}