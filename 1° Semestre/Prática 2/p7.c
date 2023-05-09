/* Faça um programa em C que leia o valor da hora de trabalho e o total de horas trabalhadas no mês e calcule o salário bruto, o salário líquido, e os impostos descontados. Considere IR igual a 25% e INSS igual a 11%.*/

#include <stdio.h>

int main() {
float valor_hora_trabalho = 0.0f;
int total_horas_trabalhadas = 0;
int deu_certo = 0;

printf("\nDigite o valor da sua hora trabalho:\n");
deu_certo = scanf("%f", &valor_hora_trabalho);

printf("\nDigite o total de horas trabalhadas:\n");
deu_certo = scanf("%i", &total_horas_trabalhadas);

printf("Informacoes enviadas pelo user\n|Valor da hora:%.2f| |Horas Trabalhadas:%.2ih|\n", valor_hora_trabalho,total_horas_trabalhadas);

float salario_bruto = (valor_hora_trabalho * total_horas_trabalhadas); 

printf("\n");
printf("\nSalario Bruto: R$ %.2f", salario_bruto);

const float IR = 0.25;
const float INSS = 0.11; 

float IR_descontado = IR * salario_bruto;
float INSS_descontado = INSS * salario_bruto;
  
printf("\n");
printf("\nValor do IR = %.2f\n",IR_descontado);
printf("Valor do INSS = %.2f\n",INSS_descontado);
float salario_liquido = salario_bruto - (IR_descontado + INSS_descontado);

printf("\nSalario Liquido: R$ %.2f\n", salario_liquido);
printf("\n\n");
  printf("--------------------------\n");
  printf(" C O N T R A C H E Q U E  \n");
  printf("--------------------------\n");
  printf("Item:           Valor:\n");
  printf("Salario Bruto R$ %8.2f\n", salario_bruto);
  printf("IR Descontado R$ %8.2f\n", IR_descontado);
  printf("INSS desconto R$ %8.2f\n", INSS_descontado);
  printf("Salario Final R$ %8.2f\n", salario_liquido);
  
  return 0;
}
