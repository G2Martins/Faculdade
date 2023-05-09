/* Faça um programa em C que converta um tempo expresso em segundos para um
  valor em horas, minutos e segundos (ex.: 1000 segundos corresponde a 0 horas
  16 minutos e 40 segundos).*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int seg;
  int min;
  int horas;
  int resto;

  printf("Qual tempo em segundos?");
  scanf("%d", &seg);

  horas = seg / 3600;
  resto = seg % 3600;
  min = resto / 60;
  seg = resto % 60;

  printf("O Tempo Inserido equivale a %d horas, %d minutos e %d segundos.", horas, min, seg);

  return 0;
  
}
