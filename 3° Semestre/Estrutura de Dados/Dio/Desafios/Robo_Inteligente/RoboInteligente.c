#include <stdio.h>

void classificarNumero(int numero, int *positivos, int *negativos) {
  if (numero < 0) {
    printf("negativo!\n");
    (*negativos)++;
  } else if (numero > 0) {
    printf("positivo!\n");
    (*positivos)++;
  }
}

int main() {
    int numero, positivos = 0, negativos = 0;
    
    do
    {
        scanf("%d", &numero);
        classificarNumero(numero, &positivos, &negativos);
    } while (numero != 0);

    //TODO: Imprimir a saída no padrão definido neste desafio.
    
    printf("%d números positivos, %d números negativos", positivos, negativos);
    return 0;
}