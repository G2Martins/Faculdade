#include <stdio.h>
#include <stdlib.h>
// 0,4 * 8 = 3,2 E 0,6 * 8 = 4,8). Resultado = 4,8 + 3,2 = 8 //

int main() {
  int nota1;
  int nota2;
  int resultado;
  
  printf("Qual a sua nota da A1?\n");
    scanf("%d", &nota1);

  printf("Qual a sua nota de A2\n");
    scanf("%d", &nota2);

  printf("Aguarde Enquanto analisamos os seus dados!!.\n");

  printf("Notas Enviadas Pelo Aluno. \nA1:%d A2:%d\n", nota1,nota2);
   
  resultado = (0.4 * nota1) + (0.6 * nota2);

  printf("Sua media final foi: %d", resultado);
  
  return 0;
}
