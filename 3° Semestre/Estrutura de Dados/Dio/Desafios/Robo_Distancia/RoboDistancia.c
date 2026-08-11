#include <stdio.h>

void verificaDistancia(int distancia) {
    if(distancia <= 10){
        printf("O robô está próximo!");
    }else {
        printf("O robô está longe!");
    }
}

int main() {
    int distancia;

    //TODO: Ler a entrada com a função "scanf" e atribuir à "distancia".
    scanf("%d", &distancia);
    
    verificaDistancia(distancia);
    //TODO: Tendo em vista a função "verificaDistancia", imprima a saída.
    
  return 0;
}
