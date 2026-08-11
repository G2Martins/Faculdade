//Escreva a função int calcularMedia(int n, int vet[n]); que percorra um array de n inteiros e retorne a média de todos os números de vet maiores que 3.
#include <stdio.h>

float calcularmedia(int n, int vet [n]) 
{
    int vetMaior3[n];
    float total = 0.0f;
    int tamanho = 0;
    
    for (int i = 0; i < n; i++) 
    {
        if (vet[i] > 3) {
            vetMaior3[tamanho] = vet[i];
            tamanho ++;
        } 
    }

    if(tamanho == 0){
        return 0.0;
    }
    
    for (int j = 0; j < tamanho; j++) {
        total += vetMaior3[j];
    }
    
    return total / tamanho;
}

int main() {
    int n[] = {3,5,6,7,8};
    int *ptr = n;
    float media = calcularmedia(5, ptr);
    
    printf("media : %.2f", media);
    return 0;
}