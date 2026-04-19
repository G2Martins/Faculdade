#include <stdio.h>
#include <math.h>

float mediaVeiculosHora(int tamanho, int veiculos[]) {
    int i, soma = 0;
    float media;
    for (i = 0; i < tamanho; i++) {
      soma += veiculos[i];
    }
    
    media = soma / (float)tamanho; // Convertendo tamanho para float para garantir divisão correta
    media = round(media);
    
    //TODO: Retornar a média arredondando o valor por meio da função "round".
    return media;
}

int main() {
    int tamanho, i;
    float media;

    scanf("%d", &tamanho);

    int veiculos[tamanho];
    for (i = 0; i < tamanho; i++) {
      scanf("%d", &veiculos[i]);
    }

    //TODO: Chamar a função "mediaVeiculosHora" e imprimir a saída de acordo com o enunciado.
    media = mediaVeiculosHora(tamanho, veiculos);
    
    printf("Média de veículos por hora: %.f\n", media); // Correção na impressão do valor médio
    return 0;
}