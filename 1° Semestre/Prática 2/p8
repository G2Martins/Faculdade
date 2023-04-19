/*Faça um programa em C que leia as coordenadas de dois pontos (x1, y1) e (x2, y2) e calcule a distância entre eles (d = raiz_quadrada((x2-x1)² + (y2-y1)²)).*/

#include <stdio.h>
#include <math.h>

int main() {
  float cordenada_x1 = 0.0f;
  float cordenada_x2 = 0.0f;
  float cordenada_y1 = 0.0f;
  float cordenada_y2 = 0.0f;
  int deu_certo = 0;

  
  printf("\nDigite o valor de x1\n");
  deu_certo = scanf("%f", &cordenada_x1);
  
  printf("\nDigite o valor de x2:\n");
  deu_certo = scanf("%f", &cordenada_x2);

  printf("\nDigite o valor de y1:\n");
  deu_certo = scanf("%f", &cordenada_y1);

  printf("\nDigite o valor de y2:\n");
  deu_certo = scanf("%f", &cordenada_y2);

  float distancia = sqrt( pow(cordenada_x1-cordenada_x2,2) + pow(cordenada_y1-cordenada_y2,2));

  printf("\nA Distancia entre os pontos (%.1f,%1.f) e (%.1f, %.1f): %.2f\n", cordenada_x1,cordenada_y1,cordenada_x2,cordenada_y2,distancia);

  return 0;
}
