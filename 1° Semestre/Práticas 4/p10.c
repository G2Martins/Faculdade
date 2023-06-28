/* Faça um programa em C que leia o número de mês, valide o número com os meses
 * definidos por uma enumeração e imprima o nome do mês. */

#include <stdio.h>

int main() {
  //    POSIÇÃO   0    1    2    3    4    5    6    7    8    9    10   11   12
  enum meses_e {null, jan, fev, mar, abr, mai, jun, jul, ago, set, out, nov, dez };

  char nomes_mes[13][10] = {"null","janeiro","fevereiro","marco","abril","maio","junho","agosto","setembro","outubro","novembro","dezembro"};

  int mes = -1;
  printf("Entre com o numero do mes: ");
  scanf("%d", &mes);

  switch (mes) 
    {
      case jan:
        printf("O Mes Escolhido foi %s", nomes_mes[jan]); break;
      case fev:
        printf("O Mes Escolhido foi %s", nomes_mes[fev]); break;
      case mar:
        printf("O Mes Escolhido foi %s", nomes_mes[mar]); break;
      case abr:
        printf("O Mes Escolhido foi %s", nomes_mes[abr]); break;
      case mai:
        printf("O Mes Escolhido foi %s", nomes_mes[mai]); break;
      case jun:
        printf("O Mes Escolhido foi %s", nomes_mes[jun]); break;
      case jul:
        printf("O Mes Escolhido foi %s", nomes_mes[jul]); break;
      case ago:
        printf("O Mes Escolhido foi %s", nomes_mes[ago]); break;
      case set:
        printf("O Mes Escolhido foi %s", nomes_mes[set]); break;
      case out:
        printf("O Mes Escolhido foi %s", nomes_mes[out]); break;
      case nov:
        printf("O Mes Escolhido foi %s", nomes_mes[nov]); break;
      case dez:
        printf("O Mes Escolhido foi %s", nomes_mes[dez]); break;
      default:
        printf("Numero do mes invalido!"); break;
    }

  return 0;
}
