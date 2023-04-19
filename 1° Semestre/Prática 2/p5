/*Faça um programa em C que leia o peso e a altura de uma pessoa e calcule o índice de massa corporal (imc = peso / altura²).*/

#include <stdio.h>

int main() {
  float peso;
  float altura;
  float imc;

  printf("-------------------------------------\n");
  printf("| C A L C U L A D O R A  D E  I M C |\n");
  printf("-------------------------------------\n");

  printf("\nDigite seu em peso em Kg:\n");
  scanf("%f", &peso);

  printf("\nDigite sua altura em metros:\n");
  scanf("%f", &altura);

  printf("\nPeso e Altura Enviadas pelo user\n |Peso:%.2f Kg| |Altura:%.2fm|\n", peso,altura);
  
  imc = peso / (altura * altura);

  printf("\nO IMC Resultou em: %f\n",imc);

  if(imc < 16.9){
    printf("\n User se encontra muito abaixo do seu peso\n");
  }else if (imc < 18.4){
    printf("\n User se encontra abaixo do seu peso\n");
  }else if (imc < 24.9){
    printf("\n User se encontra na faixa normal do seu peso\n");
  }else if (imc < 29.9){
    printf("\n User se encontra acima do seu peso\n");
  }else if (imc < 34.9){
    printf("\n User se encontra na faixa de Obesidade I\n");
  }else if (imc < 40){
    printf("\n User se encontra na faixa de Obesidade II\n");
  }else if (imc > 40){
    printf("\n User se encontra na faixa de Obesidade III\n");
  }else{
     printf("\n User digitou informacoes invalidas!!\n");
  }
  
  
  return 0;
}
