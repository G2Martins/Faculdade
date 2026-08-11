#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#define MAX 5

int main()
{

struct player_t
    {
        char player_name[31];
        int vitorias;
        int derrotas;
    };
    
    struct player_t jogadores[5];

    jogadores[0].vitorias = 20;
    strcpy (jogadores[0].player_name, "Luisa");
    jogadores[0].derrotas = 10;
    
    jogadores[1].vitorias = 19;
    strcpy (jogadores[1].player_name, "Gustavo");
    jogadores[1].derrotas = 10;
    
    jogadores[2].vitorias = 18;
    strcpy (jogadores[2].player_name, "Guilherme");
    jogadores[2].derrotas = 10;

    jogadores[3].vitorias = 17;
    strcpy (jogadores[3].player_name, "Franscisco");
    jogadores[3].derrotas = 10;
    
    jogadores[4].vitorias = 16;
    strcpy (jogadores[4].player_name, "Adalberto");
    jogadores[4].derrotas = 10;

    printf("\n\n");
    printf("+------------------------------------------+\n");
    printf("+--------  BEM Vindo ao ScoreBoards -------+\n");
    printf("+-                                        -+\n");
    printf("+- NOME:          WINS:      LOSES:       -+\n");

    for (int i = 0; i < MAX; i++)
    {
        printf("%-10s\t%5.2d\t%9.2d\n", jogadores[i].player_name, jogadores[i].vitorias, jogadores[i].derrotas);
    }
    
    sleep(5);
    system("cls");
    
    
    
    
    
    
    
    return 0;
}