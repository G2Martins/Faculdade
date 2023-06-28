//Faça um programa em C que leia uma estrutura contendo dia, mês e ano e imprima a data tanto no formato BR (dd/mm/aaaa) quanto no formato US (mm/dd/aaaa).
#include <stdio.h>

struct Data_t {
    int dia;
    int mes;
    int ano;
};

int main() {
    struct Data_t data;

    printf("Digite o dia: ");
    scanf("%d", &data.dia);

    printf("Digite o mês: ");
    scanf("%d", &data.mes);

    printf("Digite o ano: ");
    scanf("%d", &data.ano);
 
    printf("Data no formato BR: %02d/%02d/%04d\n", data.dia, data.mes, data.ano);

    return 0;
}
