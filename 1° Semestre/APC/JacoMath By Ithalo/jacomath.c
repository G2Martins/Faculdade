#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <math.h>


/*- Criar um conjunto de operações e quatro respostas que serão escolhidas de forma aleatória;
- Salvar o nome do jogador, quantidade de acertos e quantidade de erros;
- Permitir escolher o nível do jogo entre: i) básico - 4 operações; ii) médio - 6 operações; e iii) operações - 8 operações;
- Listar os resultados dos jogadores na ordem de maior pontuação para menor pontuação.
*/
int main() 
{
    int jogar = 1;

     while (jogar == 1)
    {
        int jogar = 2;
        char player_name[55];
        
        printf("Seja bem-vindo ao:\n\n");

        /*printf("░░░░░██╗░█████╗░░█████╗░░█████╗░███╗░░░███╗░█████╗░████████╗██╗░░██╗");
        printf("░░░░░██║██╔══██╗██╔══██╗██╔══██╗████╗░████║██╔══██╗╚══██╔══╝██║░░██║");
        printf("░░░░░██║███████║██║░░╚═╝██║░░██║██╔████╔██║███████║░░░██║░░░███████║");
        printf("██╗░░██║██╔══██║██║░░██╗██║░░██║██║╚██╔╝██║██╔══██║░░░██║░░░██╔══██║");
        printf("╚█████╔╝██║░░██║╚█████╔╝╚█████╔╝██║░╚═╝░██║██║░░██║░░░██║░░░██║░░██║");
        printf("░╚════╝░╚═╝░░╚═╝░╚════╝░░╚════╝░╚═╝░░░░░╚═╝╚═╝░░╚═╝░░░╚═╝░░░╚═╝░░╚═╝");*/
        printf("\nDigite o Seu nome \n");
        fgets(player_name, sizeof(player_name), stdin);
        player_name[strcspn(player_name, "\n")] = '\0';

        while(jogar == 2)
        {
            int escolha;

            printf("\n\n");
            printf("+--------------------------------+\n");
            printf("+       Well Done! %s            +\n", player_name);
            printf("+   Escolha a dificuldade!       +\n");
            printf("+    1 - Facil                   +\n"); // 4 operações      SOMA , SUBTRAÇAO, MULTIPLICAÇÃO E DIVISÃO
            printf("+    2 - Medio                   +\n"); // 6 operações      SOMA , SUBTRAÇAO, MULTIPLICAÇÃO, DIVISÃO, POTENCIA E RAIZ QUADRADA
            printf("+    3 - Dificil                 +\n"); // 8 operações      SOMA , SUBTRAÇAO, MULTIPLICAÇÃO, DIVISÃO, POTENCIA , RAIZ QUADRADA, PORCENTAGEM E 
            printf("+    4 - Pontuacao               +\n");
            printf("+    0 - Sair                    +\n");
            printf("+--------------------------------+\n");
            printf("Operacao:");
            scanf("%d", &escolha);
            getchar();

            printf("\n\n");
        
            switch (escolha) 
            {
                case 1: 
                {
                    int adicao_1;
                    int adicao_2;
                    int soma_adicao;
                    int jogada_adicao;            
                    
                    srand(time(NULL));

                    adicao_1 = rand() % 100 + 1;
                    adicao_2 = rand() % 100 + 1;
                    soma_adicao = adicao_1 + adicao_2;
                    
                    printf("\nNumero 1: %d\n", adicao_1);
                    printf("\nNumero 2: %d\n", adicao_2);
                    printf("\nDigite o resultado: %d + %d ?\n", adicao_1, adicao_2);
                    scanf("%d", &jogada_adicao);

                    if(soma_adicao == jogada_adicao)
                    {
                        printf("\nValor Correto da Adicao = |%d|, Valor Enviado pelo user = |%d|\n", soma_adicao, jogada_adicao);
                        printf("\nParabens, A Operação Matemática Esta Correta\n");
                        sleep(3);
                        system("clear");
                        
                    }else
                    {
                        printf("\nValor Correto da Adicao = |%d|, Valor Enviado pelo user = |%d|\n", soma_adicao, jogada_adicao);
                        printf("\nDeu Ruim!, Operacao Matematica Esta Incorreta\n");
                        sleep(3);
                        system("clear");
                    }

                    int subtracao_1;
                    int subtracao_2;
                    int soma_subtracao;
                    int jogada_subtracao;            
                    
                    srand(time(NULL));

                    subtracao_1 = rand() % 100 + 1;
                    subtracao_2 = rand() % 100 + 1;
                    soma_subtracao = subtracao_1 - subtracao_2;
                    
                    printf("\nNumero 1: %d\n", subtracao_1);
                    printf("\nNumero 2: %d\n", subtracao_2);
                    printf("\nDigite o resultado: %d - %d ?\n", subtracao_1, subtracao_2);
                    scanf( "%d", &jogada_subtracao);

                    if(soma_subtracao == jogada_subtracao)
                    {
                        printf("\nValor Correto da Subtracao = |%d|, Valor Enviado pelo user = |%d\n", soma_subtracao, jogada_subtracao);
                        printf("\nParabens, A Operação Matemática Esta Correta\n");
                        sleep(3);
                        system("clear");
                    }else
                    {
                        printf("\nValor Correto da Subtracao = |%d|, Valor Enviado pelo user = |%d|\n", soma_subtracao, jogada_subtracao);
                        printf("\nDeu Ruim!, Operacao Matematica Esta Incorreta\n");
                        sleep(3);
                        system("clear");
                    }    
                    
                    int multiplicacao_1;
                    int multiplicacao_2;
                    int valor_multiplicacao;
                    int jogada_multiplicacao;            
                    
                    srand(time(NULL));

                    multiplicacao_1 = rand() % 100 + 1;
                    multiplicacao_2 = rand() % 100 + 1;
                    valor_multiplicacao = (multiplicacao_1 * multiplicacao_2);
                    
                    printf("\nNumero 1: %d\n", multiplicacao_1);
                    printf("\nNumero 2: %d\n", multiplicacao_2);
                    printf("\nDigite o resultado: %d x %d ?\n", multiplicacao_1, multiplicacao_2);
                    scanf( "%d", &jogada_multiplicacao);

                    if(valor_multiplicacao == jogada_multiplicacao)
                    {
                        printf("\nValor Correto da Multiplicacao = |%d|, Valor Enviado pelo user = |%d|\n", valor_multiplicacao, jogada_multiplicacao);
                        printf("\nParabens, A Operação Matemática Esta Correta\n");
                        sleep(3);
                        system("clear");
                    }else
                    {
                        printf("\nValor Correto da Multiplicacao = |%d|, Valor Enviado pelo user = |%d|\n", valor_multiplicacao, jogada_multiplicacao);
                        printf("\nDeu Ruim!, Operacao Matematica Esta Incorreta\n");
                        sleep(3);
                        system("clear");
                    }

                    
                    float divisao_1;
                    float divisao_2;
                    float valor_divisao;
                    float jogada_divisao;            
                    
                    srand(time(NULL));

                    divisao_1 = rand() % 100 + 1;
                    divisao_2 = rand() % 100 + 1;
                    valor_divisao = (multiplicacao_1 / multiplicacao_2);
                    
                    printf("\nNumero 1: %d\n", divisao_1);
                    printf("\nNumero 2: %d\n", divisao_2);
                    printf("\nDigite o resultado: %d / %d ?\n", divisao_1, divisao_2);
                    scanf( "%.2f", &jogada_divisao);

                    if(valor_divisao == jogada_divisao)
                    {
                        printf("\nValor Correto da Divisao = |%.2f|, Valor Enviado pelo user = |%.2f|\n", valor_divisao, jogada_divisao);
                        printf("\nParabens, A Operação Matemática Esta Correta\n");
                        sleep(3);
                        system("clear");
                    }else
                    {
                        printf("\nValor Correto da Divisao = |%.2f|, Valor Enviado pelo user = |%.2f|\n", valor_divisao, jogada_divisao);
                        printf("\nDeu Ruim!, Operacao Matematica Esta Incorreta\n");
                        sleep(3);
                        system("clear");
                    }

                }    
                case 2:
                {
                    
                    break;
                }
                
                case 3:
                {

                    break;
                }
                
                case 4:
                {
                    break;
                }                
                
                case 0:
                {
                    system("clear");
                    exit(0);
                    break; 
                }
                
                default: 
                {
                    printf("\e[1;31mOpção inválida!\e[0m Pressione ENTER para continuar...\n");
                    getchar();
                }       
            }        
        
            int opcao_recomecar = -1;
            printf("\n\n");
            printf("+--------------------------------------+\n");
            printf("+-        Well Done! %s               -+\n", player_name);
            printf("+- 1 - Sair do Jogo                   -+\n");
            printf("+- 2 - Recomecar o Jogo               -+\n");
            printf("+- 0 - Retornar Para O Menu Principal -+\n");
            printf("+--------------------------------------+\n");
            printf("+- Operacao:");
            scanf("%i", &opcao_recomecar);
            getchar();
            printf("\n");

            switch (opcao_recomecar)
            {
            case 1:
                printf("Finalizando ...");
                exit(0);
                break;
            
            case 2:
                jogar = 1;
                break;
            
            case 0:
                jogar = 2;
                break;
            
            default:
            {
                printf("\e[1;31mOpção inválida!\e[0m Pressione ENTER para continuar...\n");
                getchar();
                jogar = 2;
                break;
            }
        
            }
        
        }
    }
    
  
  return 0;
}