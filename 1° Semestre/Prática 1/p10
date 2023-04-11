/* Faça um programa em C que calcule a decomposição de um número inteiro
 qualquer em unidade, dezena, centena e milhar (ex.: 5637 é decomposto em 7
 unidades, 3 dezenas, 6 centenas e 5 milhares). */

#include <stdio.h>

int main() {

  int input;
  int num;
  int unidade;
  int dezena;
  int centena;
  int milhar;

  printf("\nDigite um número inteiro:\n");
  scanf("%d", &input);

  num = input;
  unidade = num % 10;

  num = (num - unidade) / 10;
  dezena = num % 10;

  num = (num - dezena) / 10;
  centena = num % 10;

  num = (num - centena) / 10;
  milhar = num % 10;

  printf(
      "%d é decomposto em %d unidades, %d dezenas, %d centenas e %d milhares",
      input, unidade, dezena, centena, milhar);

  return 0;
}

/*No código apresentado, a variável "num" é utilizada para armazenar o valor
original de entrada e é modificada a cada cálculo para extrair os dígitos de
unidade, dezena, centena e milhar.

Ao utilizar a operação de módulo (%), você obtém o resto da divisão de "num" por
10, que representa o dígito da unidade. Em seguida, você subtrai esse valor de
"num" e divide "num" por 10 para remover o dígito da unidade e obter o valor
restante. Esse valor restante é então usado para extrair os dígitos da dezena,
centena e milhar, seguindo o mesmo processo.

Portanto, não é necessário declarar novas variáveis para cada cálculo. A mesma
variável "num" é usada para armazenar o valor restante após cada extração de
dígito, permitindo que você obtenha os dígitos em sequência. Cada extração de
dígito não requer uma nova variável, pois o valor de "num" é atualizado a cada
iteração do processo de extração.*/
