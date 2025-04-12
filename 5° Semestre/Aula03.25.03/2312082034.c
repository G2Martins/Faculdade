#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  
#include <ctype.h>

void menu()
{
    system("clear || cls");
    printf("==========================================\n");
    printf("=           Bem-vindo G2Store            =\n");
    printf("= 1 - Comprar um PC Gamer                =\n");
    printf("= 2 - Conseguir Cupom de Desconto        =\n");
    printf("= 3 - Últimas Ofertas                    =\n");
    printf("= 4 - Produtos Mais Vendidos             =\n");
    printf("= 5 - Plano de Assinaturas               =\n");
    printf("= X - Sair                                =\n");
    printf("==========================================\n");
    printf("Operacao: ");
}



int main()
{
    int continua = 1;

    // Enquanto A variavel "continua" for verdade o laço while
    // Continuara até que o usuario digite X
    while(continua)
    {   
        // Char operacao com 50 espaços para evitar erro do usuario ao digitar 
        // e reexibir mais de uma vez a mensagem de comando inválido
        char operacao[50];
        
        menu();
        
        fgets(operacao, sizeof(operacao), stdin);
        
        // Colocar o primeiro elemento da lista para letra Maiúscula 
        // para evitar o programa de exibir a mensagem de de comando inválido  no caso de 'x' e 'X'
        // e sim encerrar o programa 
        operacao[0] = toupper(operacao[0]);

        
        switch (operacao[0])
        {
        case '1':
            ComprarPC();
            break;
        
        case '2':
            CupomDesconto();
            break;
        
        case '3':
            UltimasOfertas();
            break;
        
        case '4':
            ProdutosMaisVendidos();
            break;
        
        case '5':
            PlanoAssinatura();
            break;
        
        case 'X':
            system("clear || cls");
            printf("Saindo do Sistema...\n");
            continua = 0;
            break;

        default: // Mensagem de erro para todas entradas inválidas
            system("clear || cls");
            printf("Operacao Invalida tente novamente!!\n");    
            sleep(1);
            break;
        }
    }

    return 0;
}
