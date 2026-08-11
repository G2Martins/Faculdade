#include <stdio.h>
#define MAX 5

int main() 
{

    int i = 0, j = 0, k = 0;
    int vitorias_trocas[5]; // vitorias trocas

    while(k <= MAX) 
    {
        
        for (j = 0; j < k; j++)
        {
            for(i = 0; i < (k - j); i++) {
                if(jogadores[i].vitorias > jogadores[i].vitorias)
                {
                    vitorias_trocas[i] = jogadores[i+1].vitorias;
                    vitorias_trocas[i+1] = jogadores[i].vitorias;
                    jogadores[i].vitorias = vitorias_trocas[i];
                    jogadores[i+1].vitorias = vitorias_trocas[i+1];
                }
            }
        }
    
    }
        printf("+------------------------------------------+\n");
        printf("+--------  BEM Vindo ao ScoreBoards -------+\n");
        printf("+-                                        -+\n");
        printf("+- NOME:          WINS:      LOSES:       -+\n");

            for (i = 0; i <= k; i++)
            {
                printf("%3.s\t%10.2d\t%10.2d\n", jogadores[k].player_name, jogadores[k].vitorias, jogadores[k].derrotas);
            } 
            
        //printf("%-20.20s %03i %12.2f\n"
        //printf("\n\n");
        //melhor_de_x = 0;
        //break;
        
    
}