#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int verificarPalpite(int palpite, int numeroAleatorio){

    if(palpite > numeroAleatorio){
        return 1;
    }else if (palpite < numeroAleatorio){
        return -1;
    }
    
    return 0;
}

int receberPalpite()
{
    int palpite;
    
    scanf("%d", &palpite);
    return palpite;
}

int gerarNumeroAleatorio(int min, int max){
   int numeroAletorio; 
    
    numeroAletorio = rand() % max + min;
    return numeroAletorio;
}

// Implemente estas funções
void novoJogo(){
    int tentativas = 1;
    int verificacao = 1;
    int palpite;                            // Min  Max
    int numero_aleatorio = gerarNumeroAleatorio(1, 100);

    printf("DEBUG: %d", numero_aleatorio);
    printf("\n\n");
    printf("+----------- S E J A  B E M - V I N D O -------------+\n");
    printf("+ A 0  N O S S O  J O G O  D E  A D V I N H A C A O  +\n");
    printf("+---------------------------------------------------+\n");

    while(verificacao != 0)
    {

        printf("\nQual e o seu palpite? ");

        palpite = receberPalpite();
        verificacao = verificarPalpite(palpite, numero_aleatorio);

        if(verificacao == 1){
            printf("Muito alto, tente novamente!\n");
        }else if(verificacao == -1){
            printf("Muito baixo, tente novamente!\n");
        }else if(verificacao == 0){
            printf("Parabens, voce acertou o numero apos %d tentativas!\n", tentativas);
            break;
        }

        tentativas++;
    }
}

void limparTela(){
    system("cls");
}


int main() {
  char jogarNovamente;
  
    // necessário uma única vez para obtenção de número aleatório
  srand(time(NULL));
  
  do {
    limparTela();
    novoJogo();
    printf("\nGostaria de jogar novamente? (s/n): ");
    scanf(" %c", &jogarNovamente);
  } while (jogarNovamente == 's' || jogarNovamente == 'S');

  return 0;
}
