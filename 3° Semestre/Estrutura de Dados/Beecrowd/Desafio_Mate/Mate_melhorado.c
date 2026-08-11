#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct roda {
    int total_pessoas;
    float total_garrafa;
    float total_copo;
} roda;

struct pessoa_t {
    char nome[13];
}; 

roda* cria_roda(){
    roda *nova_roda;
    nova_roda = (roda*)calloc(1, sizeof(roda));
    
    return nova_roda;
}

int main(){
    roda *roda_1 = cria_roda();

    scanf("%d %f %f", &roda_1->total_pessoas, &roda_1->total_garrafa, &roda_1->total_copo);
    
    struct pessoa_t pessoa[roda_1->total_pessoas]; 

    for(int i = 0; i < roda_1->total_pessoas; i++)
    {
        scanf("%s", pessoa[i].nome);
       
    }
    
    float garrafa_restante = roda_1->total_garrafa;
    int indice_ultima_pessoa = 0;

    while (garrafa_restante >= roda_1->total_copo) {
        for(int i = 0; i < roda_1->total_pessoas; i++) {
            if (garrafa_restante >= roda_1->total_copo) {
                garrafa_restante -= roda_1->total_copo;
                indice_ultima_pessoa = i + 1;
            } else {
                break;
            }
        }
    }

    printf("%s %.1f\n", pessoa[indice_ultima_pessoa].nome, garrafa_restante);
    
    return 0;
}
