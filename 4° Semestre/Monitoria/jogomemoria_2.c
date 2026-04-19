#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define coberto 0
#define descoberto 1
#define MAX 5

int tabuleiro_1_definido[4][5] = {
  {0, 1, 2, 3, 4},
  {5, 6, 7, 8, 9},
  {0, 1, 2, 3, 4},
  {5, 6, 7, 8, 9}
};

int main(){
    int jogar = 1;

	struct player_t
    {
        char player_name[31];
        int acertos;
		int erros;
    };
    struct player_t jogadores[5];
    
    int a; // Inicializando com valores as variáveis
    for (a = 0; a < 5; a++)
    {
        jogadores[a].acertos = 0;
		jogadores[a].erros = 0;
        strcpy(jogadores[a].player_name, "");
    }
	
	int k = 0;

    while(jogar == 1 && k < MAX)
	{
		printf("Bem vindo ao jogo da Memoria\n"); 
		printf("Digite o seu nome:\n");
        scanf("%[^\n]s", jogadores[k].player_name);
        getchar();
		int jogar = 2;

		while(jogar == 2)
		{
			system("cls");
			int operacao = 0;
			int linha_1 = 0;
			int coluna_1 = 0;
			int jogar = 3;

			printf("Bem vindo\n"); 
			printf("Escolha uma das opcoes abaixo:\n");
			printf("+- (1) Jogar  		   -+\n");
			printf("+- (2) Sair   		   -+\n");
			printf("+- (3) Lista de Scores -+\n");
			printf("+- (4) Novo Jogador -+\n");
			printf("+- Operacao: ");
			scanf("%d%*c", &operacao);

			if(operacao == 1)
			{
				while(jogar == 3) //Definir quebra do laço
				{
					system("cls");

					for(linha_1 = 0; linha_1 < 4; linha_1++)
					{ 
						for(coluna_1 = 0; coluna_1 < 5; coluna_1++){ 
							printf("|%d|", tabuleiro_1_definido[linha_1][coluna_1]);
						}

						printf( "\n"); 
					}   
					sleep(2);
					jogar = 4;

					while(jogar == 4) //Laço do jogo
					{
						system("cls");
						int tentativas = 3; // Número máximo de tentativas

						printf("Bem-vindo ao jogo!\n");

						for (int i = 0; i < 4; i++) 
						{
							for (int j = 0; j < 5; j++) 
							{
								int palpite;
								printf("Digite seu palpite para matriz[%d][%d]: ", i, j);
								scanf("%d", &palpite);

								if (palpite == tabuleiro_1_definido[i][j]) {
									printf("Parabéns! Você acertou!\n");
									jogadores[k].acertos ++;
								} else {
									printf("Ops! Você errou. Tente novamente.\n");
									j--; // Faz com que o usuário repita a tentativa para a mesma posição
									tentativas--;
									jogadores[k].erros ++;

									if (tentativas == 0) {
										printf("Você atingiu o número máximo de tentativas.\n");
										j++;
									}
								}
							}
						}

						for(linha_1 = 0; linha_1 < 4; linha_1++)
						{ 
							for(coluna_1 = 0; coluna_1 < 5; coluna_1++){ 
								printf("|%d|", tabuleiro_1_definido[linha_1][coluna_1]);
							}

							printf( "\n"); 
						}   
						sleep(4);

						system("cls");

						int opcao_recomecar = -1;
						printf("\n\n");
						printf("+--------------------------------------+\n");
						printf("+-        Muito bem! %s          -+\n", jogadores[k].player_name);
						printf("+- 1 - Retornar Para O Menu Principal -+\n");
						printf("+- 0 - Sair Do Jogo                   -+\n");
						printf("+--------------------------------------+\n");
						printf("+- Operacao:");
						scanf("%d", &opcao_recomecar);
						getchar();
						printf("\n");

						switch (opcao_recomecar)
						{
							case 1:
							{
								system("cls");
								jogar = 2;
								break;
							}
							case 0:
							{
								printf("Finalizando ...");
								sleep(1);
								system("cls");
								exit(0);
								break;
							}
							default:
							{
								system("cls");
								printf("Opção inválida!");
								sleep(1);
								system("cls");
								jogar = 4;
								break;
							}
						}					
					}
				}
			}else if(operacao == 2){
				printf("Finalizando ...");
				sleep(1);
				system("cls");
				exit(0);
				break;
			}else if(operacao == 3)
			{
				for (int i = 0; i < 4; i++) // Buble Sort
				{
					for (int j = i + 1; j < 5; j++)
					{
						if (jogadores[i].acertos < jogadores[j].acertos)
						{
							struct player_t troca = jogadores[i];
							jogadores[i] = jogadores[j];
							jogadores[j] = troca;
						}
					}
				}
		
				printf("\n\n");
				printf("+----------------------------------------------+\n");
				printf("+--------  BEM Vindo ao Lista de Scores -------+\n");
				printf("+-                                        	  -+\n");
				printf("+- NOME:          WINS:      JOGADAS:         -+\n");
		
				for (int i = 0; i < MAX; i++)
				{
					printf("%-10s\t%5.2d\t%8.2d\n", jogadores[i].player_name, jogadores[i].acertos, jogadores[i].erros);
				}
				printf("\n\n\n\n\n\n");
				sleep(5);	
			}else if(operacao == 4){
				jogar = 1;
				k += 1;
				system("cls");
				break;
			}
		}
        
    }

       
    return 0;
}