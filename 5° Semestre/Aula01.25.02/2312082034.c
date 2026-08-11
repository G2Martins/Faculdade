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

void ComprarPC(){
    system("clear || cls");
    printf("Parabens, voce acaba de comprar um pc gamer que custou: \n");
    printf("R$: 8.500,00\n");
    sleep(2);
}

void CupomDesconto(){
    system("clear || cls");
    printf("Parabens, voce acaba de ganhar um cupom de desconto de 10 reais\n");
    printf("Codigo: VERAO10\n");
    sleep(2);
}

void UltimasOfertas(){
    system("clear || cls");
    printf("Últimas Ofertas:\n");
    printf("1 - Iphone X R$ 3.200,00\n");
    printf("2 - Iphone 12 R$ 8.200,00\n");
    printf("3 - Samsung S24 R$ 5.230,00\n");
    sleep(2);
}

void ProdutosMaisVendidos(){
    system("clear || cls");
    printf("Produtos Mais Vendidos:\n");
    printf("1 - Samsung TV 55' R$ 4.200,00\n");
    printf("2 - Iphone 14 Pro Max R$ 9.200,00\n");
    printf("3 - LG Tv 60' R$ 6.230,00\n");
    sleep(2);
}

void PlanoAssinatura(){
    system("clear || cls");
    printf("Plano de Assinaturas:\n");
    printf("1 - Basico R$ 20\n");
    printf("2 - Pro R$ 50\n");
    printf("3 - Master R$ 70\n");
    sleep(2);
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
