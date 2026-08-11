#include <stdio.h>
#include <math.h>

int main() {
    int largura, comprimento;
    float area, tempo;

    scanf("%d", &largura);
    scanf("%d", &comprimento);

    //TODO: Calcular a área do local e o tempo que o robo levará para limpá-lo.
    
    area = largura * comprimento;
    
   if (area > 600) {
        printf("Valor máximo ultrapassado.\n");
        return 0;
    }
    
    tempo = area / 5;
    tempo = ceil((float)tempo);
    
    printf("O robô de limpeza levará %f minutos para limpar a sala.", tempo);
    //TODO: Imprimir a saída de acordo com o enunciado deste desafio.

  return 0;
}