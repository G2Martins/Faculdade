#include <stdio.h>

void troca(int* xp, int* yp);
void ordenacaoPorSelecao(int arr[], int n);
void ordenacaoPorFusao(int arr[], int l, int r);
void fusao(int arr[], int l, int m, int r); // Adicionada a declaração da função fusao()
void imprimeArray(int arr[], int size);

int main() {
    int opcao;
    printf("Escolha o tipo de ordenação:\n");
    printf("1. Ordenacao por Selecao\n");
    printf("2. Ordenacao por Merge\n");
    printf("Digite a opcao: ");
    scanf("%d", &opcao);

    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);       
                                        
    switch(opcao) {
        case 1:
            ordenacaoPorSelecao(arr, n);
            printf("Array ordenado por Seleção: \n");
            imprimeArray(arr, n);
            break;
        case 2:
            ordenacaoPorFusao(arr, 0, n - 1);
            printf("Array ordenado por Fusão: \n");
            imprimeArray(arr, n);
            break;
        default:
            printf("Opção inválida!\n");
    }

    return 0;
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

// Função para implementar o Merge Sort
void ordenacaoPorFusao(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        ordenacaoPorFusao(arr, l, m);
        ordenacaoPorFusao(arr, m + 1, r);
        fusao(arr, l, m, r); 
    }
}

// Função para mesclar duas sub-arrays de arr[]
// A primeira sub-array é arr[l..m]
// A segunda sub-array é arr[m+1..r]
void fusao(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Arrays temporários
    int L[n1], R[n2];

    // Copia os dados para os arrays temporários L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    // Mescla os arrays temporários de volta em arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função para imprimir um array
void imprimeArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
