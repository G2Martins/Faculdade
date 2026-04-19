#include <stdio.h>
#include <unistd.h>  //Para usar a função sleep e dinamizar o projeto
#include <stdlib.h>  //Para tratamento de exceções de strings em opções de int
#include <string.h>  //Para lidar com strings
#include <ctype.h>   //Para lidar com strings
#define MAX 5

int main() {
  
int certo = 0;       //verifica se cada scanf retorna um valor indicando que a entrada deu certo
  
int opcao = -1;      //Alternativas no Menu do Jogo

int personagem = -1; //Alternativas entre os personagens do Jogo

int nivel = -1;      // Alternativas entres os níveis de jogabilidade
  
int escolha_1 = -1;  //Primeira escolha no jogo

int escolha_2 = -1;  //Segunda escolha no jogo
  
int escolha_3 = -1;  //Terceira escolha no jogo
  
int escolha_4 = -1;  //Quarta escolha no jogo
  
int escolha_5 = -1;  //Quinta escolha no jogo
  
int escolha_6 = -1;  //Sexta escolha no jogo
  
int escolha_7 = -1;  //Sétima escolha no jogo
  
char charada[10];    //Armazena a resosta do jogador à charada proposta no jogo

char resposta[10] = "O NADA"; // Resposta da charada
    
int pontuacao[10][6];//Armazena a pontuação dos jogadores

int jogador = 0;     //Declara qual o jogador atual

int continuar = 0;
int jogar;
int k = 0;

struct player_t
{
    char nome[21];
    int pontuacao;
    int vitorias;
    int derrotas;
};

struct player_t jogadores[5];
int a;
for(a = 0; a<MAX; a++){
  jogadores[a].vitorias = 0;
  jogadores[a].derrotas = 0;
  jogadores[a].pontuacao = 0;
  strcpy(jogadores[a].nome, " ");
}
while(jogar == 1 && k < MAX)
{
  system("clear");// Nome do Jogador
  printf("     ========================================================================================================================================\n");
  printf("                                          ▄▄▄▄███▄▄▄▄      ▄████████    ▄██████▄  ███    █▄     ▄████████                                    \n");    
  printf("                                        ▄██▀▀▀███▀▀▀██▄   ███    ███   ███    ███ ███    ███   ███    ███                                    \n");   
  printf("                                        ███   ███   ███   ███    ███   ███    █▀  ███    ███   ███    █▀                                     \n");    
  printf("                                        ███   ███   ███   ███    ███  ▄███        ███    ███   ███                                           \n");    
  printf("                                        ███   ███   ███ ▀███████████ ▀▀███ ████▄  ███    ███ ▀███████████                                    \n");    
  printf("                                        ███   ███   ███   ███    ███   ███    ███ ███    ███          ███                                    \n");    
  printf("                                        ███   ███   ███   ███    ███   ███    ███ ███    ███    ▄█    ███                                    \n");    
  printf("                                         ▀█   ███   █▀    ███    █▀    ████████▀  ████████▀   ▄████████▀                                     \n");    
  printf("     ========================================================================================================================================\n");
  printf("                             SEJA BEM VINDO BRAVO GUERREIRO, AO MAGUS, O RPG NARRATIVO MAIS TEMIDO DE TODOS                                  \n");
  printf("                                                                                                                                             \n");
  printf("                                       ||DIGITE ABAIXO O SEU NOME PARA INICIAR A SUA JORNADA||                                               \n");
  printf("     >>");
  scanf("%s", player.nome);
  while(1){
        /*MENU DO JOGO*/ 
      system("clear");
      printf("     ========================================================================================================================================\n");
      printf("                                          ▄▄▄▄███▄▄▄▄      ▄████████    ▄██████▄  ███    █▄     ▄████████                                    \n");    
      printf("                                        ▄██▀▀▀███▀▀▀██▄   ███    ███   ███    ███ ███    ███   ███    ███                                    \n");   
      printf("                                        ███   ███   ███   ███    ███   ███    █▀  ███    ███   ███    █▀                                     \n");    
      printf("                                        ███   ███   ███   ███    ███  ▄███        ███    ███   ███                                           \n");    
      printf("                                        ███   ███   ███ ▀███████████ ▀▀███ ████▄  ███    ███ ▀███████████                                    \n");    
      printf("                                        ███   ███   ███   ███    ███   ███    ███ ███    ███          ███                                    \n");    
      printf("                                        ███   ███   ███   ███    ███   ███    ███ ███    ███    ▄█    ███                                    \n");    
      printf("                                         ▀█   ███   █▀    ███    █▀    ████████▀  ████████▀   ▄████████▀                                     \n");    
      printf("     ========================================================================================================================================\n");
      printf("\n");
      printf("     Olá, %s! Seja muito bem vindo(a) ao M A G U S, você acha que está preparado(a) para este desafio? \n     Então comece um  novo jogo ou saia de fininho HA HA HA!\n", player.nome);
      printf("\n");
      printf("     1.【      Ｎｏｖｏ　Ｊｏｇｏ    】\n");
      printf("\n");
      printf("     2.【   Ｎｏｖｏ Ｊｏｇａｄｏｒ  】 \n");
      printf("\n");
      printf("     3.【           Ｓａｉr          】\n");
      printf("\n");
      printf("     ========================================================================================================================================\n");
      printf("     > ");
      certo = scanf("%i", &opcao); //Capta a opção do Jogador
      getchar();
      
      switch(opcao){
        case 1:{//Inicia o Jogo
          system("clear");
          printf("     ========================================================================================================================================\n");
          printf("                                          ▄▄▄▄███▄▄▄▄      ▄████████    ▄██████▄  ███    █▄     ▄████████                                    \n");    
          printf("                                        ▄██▀▀▀███▀▀▀██▄   ███    ███   ███    ███ ███    ███   ███    ███                                    \n");   
          printf("                                        ███   ███   ███   ███    ███   ███    █▀  ███    ███   ███    █▀                                     \n");    
          printf("                                        ███   ███   ███   ███    ███  ▄███        ███    ███   ███                                           \n");    
          printf("                                        ███   ███   ███ ▀███████████ ▀▀███ ████▄  ███    ███ ▀███████████                                    \n");    
          printf("                                        ███   ███   ███   ███    ███   ███    ███ ███    ███          ███                                    \n");    
          printf("                                        ███   ███   ███   ███    ███   ███    ███ ███    ███    ▄█    ███                                    \n");    
          printf("                                         ▀█   ███   █▀    ███    █▀    ████████▀  ████████▀   ▄████████▀                                     \n");    
          printf("     ========================================================================================================================================\n");
          printf("\n");
          printf("     Olha só! Parece que temos um jogador corajoso na área!\n");
          printf("     Muito bem,então... Vamos começar!\n");
          printf("     ========================================================================================================================================\n");
          sleep(1);
          printf("     >Era uma vez, um filho de feiticeiros que morava em uma pequena vila.\n\n");
          sleep(1);
          printf("     >Devido a uma perseguição, os pais tiveram que abandoná-lo em um cesto embaixo de uma árvore na floresta perto da vila\n\n");
          sleep(1);
          printf("     >Zauber conseguiu sobreviver por conta de algumas pessoas que moravam isolados na floresta e o encontraram.\n\n");
          sleep(1);
          printf("     >Após vários anos, ele já era um hábil feiticeiro e, acabou encontrando uma elfa passando na floresta!\n\n");
          sleep(1);
          printf("     >Seu nome era Quelle e ela era bem jovem. Eles formaram um bela amizade que durou por anos, até que...\n\n");
          sleep(1);
          printf("     >Eles descobriram a existência de um cajado muito poderoso que estava escondido perto de onde eles estavam!\n\n");
          sleep(1);
          printf("     >Depois disso, eles acabaram brigando e entraram em uma corrida pelo Cajado MAGUS\n\n");
          sleep(1);
          printf("     >Sua missão é, como um destes personagens, ganhar esta corrida pelo cajado depois de enfrentar todas as dificuldades no caminho!\n\n");
          sleep(1);
          printf("     >Boa Sorte,Jogador...\n\n");
          printf("     ========================================================================================================================================\n\n\n");
          sleep(1);
          printf("     █████ █████ █████ █████ █████ █████ █████ █████ █████ █████ █████ █████ █████ █████ █████ █████ █████ █████ █████ █████ █████ █████ ████\n\n\n");
          printf("     ========================================================================================================================================\n");
          sleep(1);
          while(1){
            system("clear");
            printf("     ========================================================================================================================================\n");
            printf("                                          ▄▄▄▄███▄▄▄▄      ▄████████    ▄██████▄  ███    █▄     ▄████████                                    \n");    
            printf("                                        ▄██▀▀▀███▀▀▀██▄   ███    ███   ███    ███ ███    ███   ███    ███                                    \n");   
            printf("                                        ███   ███   ███   ███    ███   ███    █▀  ███    ███   ███    █▀                                     \n");    
            printf("                                        ███   ███   ███   ███    ███  ▄███        ███    ███   ███                                           \n");    
            printf("                                        ███   ███   ███ ▀███████████ ▀▀███ ████▄  ███    ███ ▀███████████                                    \n");    
            printf("                                        ███   ███   ███   ███    ███   ███    ███ ███    ███          ███                                    \n");    
            printf("                                        ███   ███   ███   ███    ███   ███    ███ ███    ███    ▄█    ███                                    \n");    
            printf("                                         ▀█   ███   █▀    ███    █▀    ████████▀  ████████▀   ▄████████▀                                     \n");    
            printf("     ========================================================================================================================================\n");
            printf("\n");
            printf("\n\n     𝓔𝓼𝓬𝓸𝓵𝓱𝓪 𝓢𝓮𝓾 𝓟𝓮𝓻𝓼𝓸𝓷𝓪𝓰𝓮𝓶 : \n");
            printf("\n\n");
            printf("             -                                           (~~~~~~~)                                                                             \n");
            printf("           ------                                     < )  0   0  ( >                                                                          \n");
            printf("        ------------                                   (    <      )                                                                           \n");
            printf("          | 0 0 |                                     )   -____-    (                                                                          \n");
            printf("          @X - /@                                        |      |                                                                              \n");
            printf("            @Y@                                                                                                                                \n");
            printf("      (1) Z A U B E R                                  (2) Q U E L L E                                                                         \n");
            printf("     ========================================================================================================================================\n");
            printf("\n");
            printf("     >");
            certo = scanf("%i", &personagem);
            getchar();
            
            switch(personagem){   
              case 1: {//Zauber Escolhido
                while(1){
                  system("clear");
                  printf("     ========================================================================================================================================\n");
                  printf("                                          ▄▄▄▄███▄▄▄▄      ▄████████    ▄██████▄  ███    █▄     ▄████████                                    \n");    
                  printf("                                        ▄██▀▀▀███▀▀▀██▄   ███    ███   ███    ███ ███    ███   ███    ███                                    \n");   
                  printf("                                        ███   ███   ███   ███    ███   ███    █▀  ███    ███   ███    █▀                                     \n");    
                  printf("                                        ███   ███   ███   ███    ███  ▄███        ███    ███   ███                                           \n");    
                  printf("                                        ███   ███   ███ ▀███████████ ▀▀███ ████▄  ███    ███ ▀███████████                                    \n");    
                  printf("                                        ███   ███   ███   ███    ███   ███    ███ ███    ███          ███                                    \n");    
                  printf("                                        ███   ███   ███   ███    ███   ███    ███ ███    ███    ▄█    ███                                    \n");    
                  printf("                                         ▀█   ███   █▀    ███    █▀    ████████▀  ████████▀   ▄████████▀                                     \n");    
                  printf("     ========================================================================================================================================\n");
                  printf("\n");
                  printf("     Escolha a dificuldade do jogo: \n\n");//Escolha de Nível de Jogo
                  printf("     ==============================================================  𝓝 𝓲 𝓿 𝓮 𝓲 𝓼 ============================================================\n\n");
                  printf("     ❶ - Básico\n     ❷ - Médio\n     ❸ - Avançado\n");
                  printf("     >");
                  certo=scanf("%i", &nivel);
                  getchar();
                
                
                switch(nivel){
                    case 1: {
                    printf("     ========================================================================================================================================\n");
                    printf("     ============================================================== 𝓑 𝓪 𝓼 𝓲 𝓬 𝓸 =============================================================\n");
                    printf("     ========================================================================================================================================\n");
                    printf("     Entrando no Mundo como Zauber...\n");
                    sleep(0);
                    printf("                                                         --- 𝐀 𝐭 𝐫 𝐢 𝐛 𝐮 𝐭 𝐨 𝐬 ---\n     𝐒 𝐚 𝐛 𝐞 𝐝 𝐨 𝐫 𝐢 𝐚\n\n     𝐏 𝐚 𝐜 𝐢 𝐞 𝐧 𝐜 𝐢 𝐚\n\n     𝐕 𝐚 𝐠 𝐚 𝐫 𝐨 𝐬 𝐢 𝐝 𝐚 𝐝 𝐞\n\n");
                    printf("     ========================================================================================================================================\n");
                    sleep(0);
                    printf("     >Você acorda em sua torre...\n\n");
                    while(1){
                    printf("     >Sair logo da torre? (S = 1 ; N = 2)");
                    certo = scanf("%i", &escolha_1);
                    getchar();
                      
                    printf("     ========================================================================================================================================\n");
            
                    
                    switch(escolha_1){ //Saindo da Torre(1)
                      case 1: {
                        player.pontuacao += 1;
                        printf("                                                              ========== + 10 ==========                                              \n\n");
                        printf("     >Saindo da torre...\n\n");
                        printf("     >Ao sair da torre, você se depara com uma bifurcação!\n\n");
                        printf("     >Você vê um lado de Floresta e um lado de Deserto...\n\n");
                        
                        while(1){
                        printf("     >Qual caminho irá escolher? (Floresta = 1 ; Deserto = 2)");
                        certo= scanf("%i",&escolha_2);
                        
                          switch(escolha_2){//Indo para a Floresta(1)
                            case 1:{
                              printf("     \n     >Você ajeita as botas e segue para a Floresta...\n\n");
                              printf("     >Ao entrar na floresta, se depara com um duende!\n\n");
                              printf("     >Duende~'Olááá,caro mago! Buscando matéria prima novamente?'\n\n");
                              printf("     >Zauber~'Não desta vez...Aliás,você sabe onde fica o santuário Magiccelium?'\n\n");
                              printf("     >Duende~'Ora, que surpresa! Bem...Se não me engano fica por aquele lado ali.'\n\n");
                              sleep(2);
                              printf("     Você confiará sua trilha no Duende? (S = 1; N = 2)");
                              certo = scanf("%i", &escolha_3);
                              switch(escolha_3)
                              {
                                  
                                case 1:{//Indo no caminho do Duende(1)
                                      printf("     \n     >Decide por confiar no Duende e segue na direção apontada...\n\n");
                                      printf("     >Você anda calmamente pela floresta...\n\n");
                                      printf("     >De repente ouve um zumbido muito forte!\n\n");
                                      printf("     >Um ninho de vespas venenosas acaba de ser atacado e elas estão furiosas!!!\n\n");
                                      printf("     >Você quer atravessar a nuvem de vespas? (S = 1 ; N = 2)");
                                      certo = scanf("%i", &escolha_4);
                                      printf("\t ========================================================================================================================================\n");
                                      if(escolha_4 == 1){//Atravessando as vespas(1)
                                        printf("     \n     >Você corre confiante para atravessar\n\n");
                                        sleep(0);
                                        printf("     >......Ufa! Apesar de algumas ferroadas te deixarem tonto, você sobrevive e atravessa\n\n");
                                        printf("     >Você segue seu caminho...\n\n");
                                        printf("     >Certa hora, você se vê diante de um paredão rochoso que não é possível passar por cima.\n\n");
                                        printf("     >Olhando melhor...Você vê uma fresta bem apertada que parece dar no outro lado.\n\n");
                                        printf("     >Você quer atravessar pela fresta? ( S = 1; N = 2)");
                                        certo = scanf("%i", &escolha_6);
                                        if(escolha_6 == 1){//Passando Pela Fresta(1)
                                          printf("     \n     >Você respira fundo...Se expreme para passar e,...\n\n");
                                          printf("     >Deu certo!! Você passou.\n\n");
                                          printf("     >Em seguida, você olha para a frente e se depara com um enorme santuário!!!\n\n");
                                          printf("     >Zauber~'AH! O belíssimo Santuário Magiccelium!'\n\n");
                                          printf("                                                        /      /      \n");
                                          printf("                                                       ||______||     \n");
                                          printf("                                                       || ^  ^ ||     \n");
                                          printf("                                                        | |  | |/     \n");
                                          printf("                                                        |______|      \n"); 
                                          printf("                      __                                |  __  |      \n");  
                                          printf("                     /          ________________________|_/   _|__    \n");
                                          printf("                    / ^^       /=========================/ ^^  ===|   \n");
                                          printf("                   /  []      /=========================/  []   ==|   \n");
                                          printf("                  /________  /=========================/________ =|   \n");
                                          printf("               *  |        |/==========================|        |=|   \n");
                                          printf("              *** | ^^  ^^ |---------------------------| ^^  ^^ |--   \n");
                                          printf("             *****| []  [] |           _____           | []  [] | |   \n");
                                          printf("            *******        |          /_____           |      * | |   \n");
                                          printf("           *********^^  ^^ |  ^^  ^^  |  |  |  ^^  ^^  |     ***| |   \n");
                                          printf("          ***********]  [] |  []  []  |  |  |  []  []  | ===***** |   \n");
                                          printf("         *************     |         @|__|__|@         |/ |*******|   \n");
                                          printf("        ***************   ***********--=====--**********| *********   \n");
                                          printf("        ***************___*********** |=====| **********|***********  \n");
                                          printf("         *************     ********* /=======  ******** | *********   \n\n");
                                          printf("     >Você entra rapidamente no santuário\n\n");
                                          printf("     >Você se depara com um mantedor do santuário:\n\n");
                                          printf("     >Mantedor~'Olá! Como posso ajudá-lo?'\n\n");
                                          printf("     >Zauber~'Olá,homem santo! Estou atrás do Cajado MAGUS!!'\n\n");
                                          printf("     >Mantedor~'Ah sim... O famoso Cajado...'\n\n");
                                          printf("     >O Mantedor respira calmamente, olha nos teus olhos e diz: \n\n");
                                          printf("     >Mantedor~'É mais poderoso que os deuses, mais maligno que os demônios. É algo que os pobres tem e os ricos precisam.\n     Se você comê-lo, você morre. O que é isto? \n     (O Tempo = 1 ; O Nada = 2)>'");//CHARADA
                                          certo = scanf("%i", &escolha_7);
                                          if(escolha_7 == 2){//Acertou a charada
                                            printf("     >O Mantedor da uma risada... Mantedor~'Muito Sábio! Pois bem... Me acompanhe'\n\n");
                                            printf("     >Ele te leva até a cova do antigo Feiticeiro Ancião Magiccelium e em uma nuvem de fumaça, desaparece!\n\n");
                                            printf("     >Você abre a cova e lá está!!! O CAJADO MAGUS!!!");
                                            printf("     >PARABÉNS, JOGADOR!!! VOCÊ GANHOU A CORRIDA PELO CAJADO CONTRA A ELFA QUELLE!!!\n\n");
                                            printf("                                                        ========== 𝐕 𝐈 𝐓 𝐎 𝐑 𝐈 𝐀! ==========                                         \n");
                                            printf("Continuar jogando como: %s?", player.nome);
                                            scanf("%i", &continuar);
                                            switch(continuar){
                                              case 1:{
                                                continue; 
                                                
                                              }
                                              case 2:{
                                                break;
                                              }
                                            }
                                            
                                          }
                                        
                                          else if(escolha_7 == 1){//Errou a charada
                                            printf("     >Mantedor~'Você precisa mais do que isso para ser digno do MAGUS!'\n\n");
                                            printf("     >O Mantedor joga uma fumaça em seu rosto que faz com que você adormeça profundamente!\n\n");
                                            printf("     >Ao acordar, o santuário está vazio... Assim como a cova do antigo  Feiticeiro Ancião Magiccelium...\n\n");
                                            printf("                                                        ========== 𝕱𝖎𝖒 𝕯𝖊 𝕵𝖔𝖌𝖔 ==========                                            \n");
                                            return 0;
                                          }
                                        }
                                      else if(strcmp(charada, resposta) != 0){//Não atravessa as vespas
                                        printf("     \n     >Você decide por esperar...\n\n");
                                        printf("     >Elas estavam realmente furiosas... Demorou algumas horas para poder passar.\n\n");
                                        printf("     >Você segue seu caminho...\n\n");
                                        printf("     >Certa hora, você se vê diante de um paredão rochoso que não é possível passar por cima.\n\n");
                                        printf("     >Olhando melhor...Você vê uma fresta bem apertada que parece dar no outro lado.\n\n");
                                        printf("     >Você quer atravessar pela fresta? ( S = 1; N = 2");
                                       certo = scanf("%i", &escolha_6);
                                        if(escolha_6 == 1){//Atravessando a fresta
                                          printf("     \n     >Você deixa a corda no chão...Se expreme para passar...\n\n");
                                          printf("     >Ufa! Deu certo e você passou.\n\n");
                                          printf("     >Em seguida, você olha para a frente e se depara com um enorme santuário!!!\n\n");
                                          printf("     >Zauber~'AH! O belíssimo Santuário Magiccelium!'\n\n");
                                          printf("                                                        /      /      \n");
                                          printf("                                                       ||______||     \n");
                                          printf("                                                       || ^  ^ ||     \n");
                                          printf("                                                        | |  | |/     \n");
                                          printf("                                                        |______|      \n"); 
                                          printf("                      __                                |  __  |      \n");  
                                          printf("                     /          ________________________|_/   _|__    \n");
                                          printf("                    / ^^       /=========================/ ^^  ===|   \n");
                                          printf("                   /  []      /=========================/  []   ==|   \n");
                                          printf("                  /________  /=========================/________ =|   \n");
                                          printf("               *  |        |/==========================|        |=|   \n");
                                          printf("              *** | ^^  ^^ |---------------------------| ^^  ^^ |--   \n");
                                          printf("             *****| []  [] |           _____           | []  [] | |   \n");
                                          printf("            *******        |          /_____           |      * | |   \n");
                                          printf("           *********^^  ^^ |  ^^  ^^  |  |  |  ^^  ^^  |     ***| |   \n");
                                          printf("          ***********]  [] |  []  []  |  |  |  []  []  | ===***** |   \n");
                                          printf("         *************     |         @|__|__|@         |/ |*******|   \n");
                                          printf("        ***************   ***********--=====--**********| *********   \n");
                                          printf("        ***************___*********** |=====| **********|***********  \n");
                                          printf("         *************     ********* /=======  ******** | *********   \n\n");
                                          printf("     >Você entra rapidamente no santuário\n\n");
                                          printf("     > Abre a cova do antigo Feiticeiro Ancião Magiccelium e...\n\n");
                                          printf("     >Só possui marcas do cajado... Quelle passou antes de você!\n\n");
                                          printf("                                                        ========== 𝕱𝖎𝖒 𝕯𝖊 𝕵𝖔𝖌𝖔 ==========                                              \n");//FIM
                                          return 0;
                                        }
                                      }
                                    }
                                  }
                                case 2:{//Indo no caminho diferente do Duende
                                printf("     Espera o Duende se afastar e vai pelo outro caminho...\n");
                              }
                            }
                         case 2:{//Indo para o deserto
                            printf("     Você verifica seu cantil e segue para o Deserto...\n");
                          }
                          }
                          }
                        }
}
                      case 2:{//Fica na torre
                        printf("     \n     >Você resolveu ficar e... Achou um pedaço pesado de corda!\n\n");
                        printf("     >Deseja levá-lo em sua aventura? (S = 1; N = 2)");
                        certo = scanf("%i",&escolha_2);
                        printf("     ========================================================================================================================================\n");
                        if(escolha_2 == 1){//Pegando a Corda
                          printf("     \n     >Levando corda ao ombro...\n\n");
                          sleep(1);
                          printf("     >Ao sair da torre, você se depara com uma bifurcação!\n\n");
                          sleep(3);
                          printf("     >Você vê um lado de Floresta e um lado de Deserto...\n\n");
                          sleep(3);
                          printf("     >Qual caminho irá escolher? (Floresta = 1 ; Deserto = 2)");
                          certo = scanf("%i",&escolha_3);
                          printf("     ========================================================================================================================================\n");
                          if(escolha_3 == 1){//Indo para a Floresta
                            printf("     \n     >Você ajeita as botas e segue para a Floresta...\n\n");
                            sleep(5);
                            printf("     >Ao entrar na floresta, se depara com um duende!\n\n");
                            sleep(5);
                            printf("     >Duende~'Olááá,caro mago! Buscando matéria prima novamente?'\n\n");
                            sleep(5);
                            printf("     >Zauber~'Não desta vez...Aliás,você sabe onde fica o santuário Magiccelium?'\n\n");
                            sleep(5);
                            printf("     >Duende~'Ora, que surpresa! Bem...Se não me engano fica por aquele lado ali.'\n\n");
                            sleep(2);
                            printf("     >Você confiará sua trilha no Duende? (S = 1; N = 2)");
                            certo = scanf("%i", &escolha_4);
                            printf("     ========================================================================================================================================\n");
                            if(escolha_4 == 1){//Indo no caminho do Duende
                              printf("     \n     >Decide por confiar no Duende e segue na direção apontada...\n\n");
                              printf("     >Você anda calmamente pela floresta...\n\n");
                              printf("     >De repente ouve um zumbido muito forte!\n\n");
                              printf("     >Um ninho de vespas venenosas acaba de ser atacado e elas estão furiosas!!!\n\n");
                              printf("     >Você quer atravessar a nuvem de vespas? (S = 1 ; N = 2)");
                              certo = scanf("%i", &escolha_5);
                              printf("\t ========================================================================================================================================\n");
                              if(escolha_5 == 1){//Atravessando as vespas
                                printf("     \n     >Você corre confiante para atravessar\n\n");
                                printf("     >Logo que recebe algumas ferroadas, percebe que está pesado demais para correr!\n\n");
                                printf("     >Você começa a ficar tonto, a corda cai de seu ombro,sua visão se escurece...\n\n");
                                printf("                                                        ========== 𝕱𝖎𝖒 𝕯𝖊 𝕵𝖔𝖌𝖔 ==========                                                \n");
                                return 0;
                              }
                              else if(escolha_5 == 2){//Não Atravessa as vespas
                                printf("     \n     >Você decide por esperar...\n\n");
                                printf("     >Elas estavam realmente furiosas... Demorou algumas horas para poder passar.\n\n");
                                printf("     >Você segue seu caminho...\n\n");
                                printf("     >Certa hora, você se vê diante de um paredão rochoso que não é possível passar por cima.\n\n");
                                printf("     >Olhando melhor...Você vê uma fresta bem apertada que parece dar no outro lado.\n\n");
                                printf("     >Você quer atravessar pela fresta? ( S = 1; N = 2) ");
                                certo = scanf("%i", &escolha_6);
                                if(escolha_6 == 1){//Passando pela fresta
                                  printf("     \n     >Você deixa a corda no chão...Se expreme para passar...\n\n");
                                  printf("     >Ufa! Deu certo e você passou.\n\n");
                                  printf("     >Em seguida, você olha para a frente e se depara com um enorme santuário!!!\n\n");
                                  printf("     >Zauber~'AH! O belíssimo Santuário Magiccelium!'\n\n");
                                  printf("                                                        /      /      \n");
                                  printf("                                                       ||______||     \n");
                                  printf("                                                       || ^  ^ ||     \n");
                                  printf("                                                        | |  | |/     \n");
                                  printf("                                                        |______|      \n"); 
                                  printf("                      __                                |  __  |      \n");  
                                  printf("                     /          ________________________|_/   _|__    \n");
                                  printf("                    / ^^       /=========================/ ^^  ===|   \n");
                                  printf("                   /  []      /=========================/  []   ==|   \n");
                                  printf("                  /________  /=========================/________ =|   \n");
                                  printf("               *  |        |/==========================|        |=|   \n");
                                  printf("              *** | ^^  ^^ |---------------------------| ^^  ^^ |--   \n");
                                  printf("             *****| []  [] |           _____           | []  [] | |   \n");
                                  printf("            *******        |          /_____           |      * | |   \n");
                                  printf("           *********^^  ^^ |  ^^  ^^  |  |  |  ^^  ^^  |     ***| |   \n");
                                  printf("          ***********]  [] |  []  []  |  |  |  []  []  | ===***** |   \n");
                                  printf("         *************     |         @|__|__|@         |/ |*******|   \n");
                                  printf("        ***************   ***********--=====--**********| *********   \n");
                                  printf("        ***************___*********** |=====| **********|***********  \n");
                                  printf("         *************     ********* /=======  ******** | *********   \n\n");
                                  printf("     >Você entra rapidamente no santuário\n\n");
                                  printf("     > Abre a cova do antigo Feiticeiro Ancião Magiccelium e...\n\n");
                                  printf("     >Só possui marcas do cajado... Quelle passou antes de você!\n\n");
                                  printf("                                                        ========== 𝕱𝖎𝖒 𝕯𝖊 𝕵𝖔𝖌𝖔 ==========                                              \n");
                                }
                              }
                            }
                            else if(escolha_4 == 2){//Indo no caminho diferente do duende
                              printf("     Espera o Duende se afastar e vai pelo outro caminho...\n");
                            }
                          }
                          else if(escolha_3 == 2){//Indo para o Deserto
                            printf("     Você verifica seu cantil e segue para o Deserto...\n");
                          }
                          else{
                            printf("     Opção Inválida!\n");
                          }
                        }
                        else if(escolha_2 == 2){//Saindo da Torre
                          printf("     Você deixa o pedaço de corda e sai da torre em seguida.\n");
                          printf("     Saindo da torre...\n\n");
                          printf("     >Ao sair da torre, você se depara com uma bifurcação!\n\n");
                          printf("     >Você vê um lado de Floresta e um lado de Deserto...\n\n");
                          do{
                            printf("     >Qual caminho irá escolher? (Floresta = 1 ; Deserto = 2)");
                            certo= scanf("%i",&escolha_2);
                            if(escolha_2 != 1 && escolha_2 != 2){
                              printf("     >Opção Inválida! Tente Novamente...\n");
                              continue;
                            }
                            break;
                          }while(1);
                          if(escolha_2 == 1){//Indo Para a Floresta
                            printf("     \n     >Você ajeita as botas e segue para a Floresta...\n\n");
                            printf("     >Ao entrar na floresta, se depara com um duende!\n\n");
                            printf("     >Duende~'Olááá,caro mago! Buscando matéria prima novamente?'\n\n");
                            printf("     >Zauber~'Não desta vez...Aliás,você sabe onde fica o santuário Magiccelium?'\n\n");
                            printf("     >Duende~'Ora, que surpresa! Bem...Se não me engano fica por aquele lado ali.'\n\n");
                            sleep(2);
                            printf("     Você confiará sua trilha no Duende? (S = 1; N = 2)");
                            certo = scanf("%i", &escolha_3);
                            if(escolha_3 == 1){//Indo no caminho do Duende
                              printf("     \n     >Decide por confiar no Duende e segue na direção apontada...\n\n");
                              printf("     >Você anda calmamente pela floresta...\n\n");
                              printf("     >De repente ouve um zumbido muito forte!\n\n");
                              printf("     >Um ninho de vespas venenosas acaba de ser atacado e elas estão furiosas!!!\n\n");
                              printf("     >Você quer atravessar a nuvem de vespas? (S = 1 ; N = 2)");
                              certo = scanf("%i", &escolha_4);
                              printf("\t ========================================================================================================================================\n");
                              if(escolha_4 == 1){//Atravessando as vespas
                                printf("     \n     >Você corre confiante para atravessar\n\n");
                                sleep(0);
                                printf("     >......Ufa! Apesar de algumas ferroadas te deixarem tonto, você sobrevive e atravessa\n\n");
                                printf("     >Você segue seu caminho...\n\n");
                                printf("     >Certa hora, você se vê diante de um paredão rochoso que não é possível passar por cima.\n\n");
                                printf("     >Olhando melhor...Você vê uma fresta bem apertada que parece dar no outro lado.\n\n");
                                printf("     >Você quer atravessar pela fresta? ( S = 1; N = 2)");
                            }
                          }
          
          
          
          
          
          
          
          
          
          
          
          
          
          
                          
                        }
                        else{
                          printf("     Escolha Inválida!\n");
                        }
                      }
                      } //Fecha o case 2
                  /*    case 2:{//Fica na torre
                        printf("     \n     >Você resolveu ficar e... Achou um pedaço pesado de corda!\n\n");
                        printf("     >Deseja levá-lo em sua aventura? (S = 1; N = 2)");
                        certo = scanf("%i",&escolha_2);
                        printf("     ========================================================================================================================================\n");
                        if(escolha_2 == 1){//Pegando a Corda
                          printf("     \n     >Levando corda ao ombro...\n\n");
                          sleep(1);
                          printf("     >Ao sair da torre, você se depara com uma bifurcação!\n\n");
                          sleep(3);
                          printf("     >Você vê um lado de Floresta e um lado de Deserto...\n\n");
                          sleep(3);
                          printf("     >Qual caminho irá escolher? (Floresta = 1 ; Deserto = 2)");
                          certo = scanf("%i",&escolha_3);
                          printf("     ========================================================================================================================================\n");
                          if(escolha_3 == 1){//Indo para a Floresta
                            printf("     \n     >Você ajeita as botas e segue para a Floresta...\n\n");
                            sleep(5);
                            printf("     >Ao entrar na floresta, se depara com um duende!\n\n");
                            sleep(5);
                            printf("     >Duende~'Olááá,caro mago! Buscando matéria prima novamente?'\n\n");
                            sleep(5);
                            printf("     >Zauber~'Não desta vez...Aliás,você sabe onde fica o santuário Magiccelium?'\n\n");
                            sleep(5);
                            printf("     >Duende~'Ora, que surpresa! Bem...Se não me engano fica por aquele lado ali.'\n\n");
                            sleep(2);
                            printf("     >Você confiará sua trilha no Duende? (S = 1; N = 2)");
                            certo = scanf("%i", &escolha_4);
                            printf("     ========================================================================================================================================\n");
                            if(escolha_4 == 1){//Indo no caminho do Duende
                              printf("     \n     >Decide por confiar no Duende e segue na direção apontada...\n\n");
                              printf("     >Você anda calmamente pela floresta...\n\n");
                              printf("     >De repente ouve um zumbido muito forte!\n\n");
                              printf("     >Um ninho de vespas venenosas acaba de ser atacado e elas estão furiosas!!!\n\n");
                              printf("     >Você quer atravessar a nuvem de vespas? (S = 1 ; N = 2)");
                              certo = scanf("%i", &escolha_5);
                              printf("\t ========================================================================================================================================\n");
                              if(escolha_5 == 1){//Atravessando as vespas
                                printf("     \n     >Você corre confiante para atravessar\n\n");
                                printf("     >Logo que recebe algumas ferroadas, percebe que está pesado demais para correr!\n\n");
                                printf("     >Você começa a ficar tonto, a corda cai de seu ombro,sua visão se escurece...\n\n");
                                printf("                                                        ========== 𝕱𝖎𝖒 𝕯𝖊 𝕵𝖔𝖌𝖔 ==========                                                \n");
                                return 0;
                              }
                              else if(escolha_5 == 2){//Não Atravessa as vespas
                                printf("     \n     >Você decide por esperar...\n\n");
                                printf("     >Elas estavam realmente furiosas... Demorou algumas horas para poder passar.\n\n");
                                printf("     >Você segue seu caminho...\n\n");
                                printf("     >Certa hora, você se vê diante de um paredão rochoso que não é possível passar por cima.\n\n");
                                printf("     >Olhando melhor...Você vê uma fresta bem apertada que parece dar no outro lado.\n\n");
                                printf("     >Você quer atravessar pela fresta? ( S = 1; N = 2) ");
                                certo = scanf("%i", &escolha_6);
                                if(escolha_6 == 1){//Passando pela fresta
                                  printf("     \n     >Você deixa a corda no chão...Se expreme para passar...\n\n");
                                  printf("     >Ufa! Deu certo e você passou.\n\n");
                                  printf("     >Em seguida, você olha para a frente e se depara com um enorme santuário!!!\n\n");
                                  printf("     >Zauber~'AH! O belíssimo Santuário Magiccelium!'\n\n");
                                  printf("                                                        /      /      \n");
                                  printf("                                                       ||______||     \n");
                                  printf("                                                       || ^  ^ ||     \n");
                                  printf("                                                        | |  | |/     \n");
                                  printf("                                                        |______|      \n"); 
                                  printf("                      __                                |  __  |      \n");  
                                  printf("                     /          ________________________|_/   _|__    \n");
                                  printf("                    / ^^       /=========================/ ^^  ===|   \n");
                                  printf("                   /  []      /=========================/  []   ==|   \n");
                                  printf("                  /________  /=========================/________ =|   \n");
                                  printf("               *  |        |/==========================|        |=|   \n");
                                  printf("              *** | ^^  ^^ |---------------------------| ^^  ^^ |--   \n");
                                  printf("             *****| []  [] |           _____           | []  [] | |   \n");
                                  printf("            *******        |          /_____           |      * | |   \n");
                                  printf("           *********^^  ^^ |  ^^  ^^  |  |  |  ^^  ^^  |     ***| |   \n");
                                  printf("          ***********]  [] |  []  []  |  |  |  []  []  | ===***** |   \n");
                                  printf("         *************     |         @|__|__|@         |/ |*******|   \n");
                                  printf("        ***************   ***********--=====--**********| *********   \n");
                                  printf("        ***************___*********** |=====| **********|***********  \n");
                                  printf("         *************     ********* /=======  ******** | *********   \n\n");
                                  printf("     >Você entra rapidamente no santuário\n\n");
                                  printf("     > Abre a cova do antigo Feiticeiro Ancião Magiccelium e...\n\n");
                                  printf("     >Só possui marcas do cajado... Quelle passou antes de você!\n\n");
                                  printf("                                                        ========== 𝕱𝖎𝖒 𝕯𝖊 𝕵𝖔𝖌𝖔 ==========                                              \n");
                                }
                              }
                            }
                            else if(escolha_4 == 2){//Indo no caminho diferente do duende
                              printf("     Espera o Duende se afastar e vai pelo outro caminho...\n");
                            }
                          }
                          else if(escolha_3 == 2){//Indo para o Deserto
                            printf("     Você verifica seu cantil e segue para o Deserto...\n");
                          }
                          else{
                            printf("     Opção Inválida!\n");
                          }
                        }
                        else if(escolha_2 == 2){//Saindo da Torre
                          printf("     Você deixa o pedaço de corda e sai da torre em seguida.\n");
                          printf("     Saindo da torre...\n\n");
                          printf("     >Ao sair da torre, você se depara com uma bifurcação!\n\n");
                          printf("     >Você vê um lado de Floresta e um lado de Deserto...\n\n");
                          do{
                            printf("     >Qual caminho irá escolher? (Floresta = 1 ; Deserto = 2)");
                            certo= scanf("%i",&escolha_2);
                            if(escolha_2 != 1 && escolha_2 != 2){
                              printf("     >Opção Inválida! Tente Novamente...\n");
                              continue;
                            }
                            break;
                          }while(1);
                          if(escolha_2 == 1){//Indo Para a Floresta
                            printf("     \n     >Você ajeita as botas e segue para a Floresta...\n\n");
                            printf("     >Ao entrar na floresta, se depara com um duende!\n\n");
                            printf("     >Duende~'Olááá,caro mago! Buscando matéria prima novamente?'\n\n");
                            printf("     >Zauber~'Não desta vez...Aliás,você sabe onde fica o santuário Magiccelium?'\n\n");
                            printf("     >Duende~'Ora, que surpresa! Bem...Se não me engano fica por aquele lado ali.'\n\n");
                            sleep(2);
                            printf("     Você confiará sua trilha no Duende? (S = 1; N = 2)");
                            certo = scanf("%i", &escolha_3);
                            if(escolha_3 == 1){//Indo no caminho do Duende
                              printf("     \n     >Decide por confiar no Duende e segue na direção apontada...\n\n");
                              printf("     >Você anda calmamente pela floresta...\n\n");
                              printf("     >De repente ouve um zumbido muito forte!\n\n");
                              printf("     >Um ninho de vespas venenosas acaba de ser atacado e elas estão furiosas!!!\n\n");
                              printf("     >Você quer atravessar a nuvem de vespas? (S = 1 ; N = 2)");
                              certo = scanf("%i", &escolha_4);
                              printf("\t ========================================================================================================================================\n");
                              if(escolha_4 == 1){//Atravessando as vespas
                                printf("     \n     >Você corre confiante para atravessar\n\n");
                                sleep(0);
                                printf("     >......Ufa! Apesar de algumas ferroadas te deixarem tonto, você sobrevive e atravessa\n\n");
                                printf("     >Você segue seu caminho...\n\n");
                                printf("     >Certa hora, você se vê diante de um paredão rochoso que não é possível passar por cima.\n\n");
                                printf("     >Olhando melhor...Você vê uma fresta bem apertada que parece dar no outro lado.\n\n");
                                printf("     >Você quer atravessar pela fresta? ( S = 1; N = 2)");
                            }
                            }                
                        }
                        else{
                          printf("     Escolha Inválida!\n");
                        }
                      }
                      } //Fecha o case 2  */
                      default:{
                        printf("Opção Inválida\n");
                        while(escolha_1 != 1 && escolha_1 != 2){
                          printf("     Sair logo da torre? (S = 1 ; N = 2)");
                          certo = scanf("%i",&escolha_1);
                          sleep(5);
                        }
                      }//Fecha o default
                    // Fecha o switch(escolha_1)
                    break;
                  
                  }  
                    case 2:{
                    printf("     ========================================================================================================================================\n");
                    printf("     =============================================================== 𝕸  𝖊 𝖉 𝖎 𝖔 =============================================================\n");
                    printf("     ========================================================================================================================================\n");
                    return 0;
                  }
                    case 3: {
                    printf("     ========================================================================================================================================\n");
                    printf("     ============================================================ 𝓐 𝓿 𝓪 𝓷 ç 𝓪 𝓭 𝓸 ===========================================================\n");
                    printf("     ========================================================================================================================================\n");
                    return 0;
                  }
                    default: {
                      printf("Escolha uma opção válida!!!\n");
                  }
                    }
                  }
              }//fecha personagem == 1
              case 2: {//Quelle escolhida
                printf("     Escolha a dificuldade do jogo:");
                printf("     ==𝒩Í𝒱𝐸𝐿==\n\n");
                printf("     [1] - Básico\n[2] - Médio\n[3] - Avançado\n");
                printf("     >");
                certo=scanf("%i", &nivel);
                getchar();
                switch(nivel){
                  case 1: {
                    printf("     ========================================================================================================================================\n");
                    printf("     ============================================================== 𝓑 𝓪 𝓼 𝓲 𝓬 𝓸 =============================================================\n");
                    printf("     ========================================================================================================================================\n");
                    printf("     Entrando no Mundo como Quelle...\n");
                    sleep(2);
                    printf("     --- 𝐀 𝐭 𝐫 𝐢 𝐛 𝐮 𝐭 𝐨 𝐬 ---\n     𝐀 𝐠 𝐢 𝐥 𝐢 𝐝 𝐚 𝐝 𝐞\n     𝐄 𝐬 𝐩 𝐞 𝐫 𝐭 𝐞 𝐳 𝐚\n     𝐈 𝐦 𝐩 𝐚 𝐜 𝐢 𝐞 𝐧 𝐜 𝐢 𝐚\n");
                    printf("     ========================================================================================================================================\n");
                    sleep(5);
                    printf("     Você acorda em sua casa...\n");
                    printf("     Sair logo da casa? (S = 1; N = 2)");
                    certo = scanf("%i", &escolha_1);
                    if(escolha_1 == 1){//Saindo da Casa
                      printf("     Saindo da casa....\n");
                    }
                    else if(escolha_1 == 2){//Ficando na Casa
                      printf("     Você decide ficar em casa e...Encontrou uma capa sibilus!\n");
                      printf("     Deseja levar a capa para sua aventura?");
                      certo = scanf("%i", &escolha_2);
                    }
                  }
                  case 2: {
                    printf("     ========================================================================================================================================\n");
                    printf("     =============================================================== 𝕸  𝖊 𝖉 𝖎 𝖔 =============================================================\n");
                    printf("     ========================================================================================================================================\n");
                  }
                  case 3: {
                    printf("     ========================================================================================================================================\n");
                    printf("     ============================================================ 𝓐 𝓿 𝓪 𝓷 ç 𝓪 𝓭 𝓸 ===========================================================\n");
                    printf("     ========================================================================================================================================\n");
                  }
                  default: {}
                }
                }//fecha personagem == 2
              default:{
                printf("     Escolha um dos personagens disponíveis!!\n");
            }//fecha else
                }//fecha case 1  
              }
            }
          }
        }
    case 2:{
        ;
        system("clear");// Nome do Jogador
          printf("     ========================================================================================================================================\n");
          printf("                                          ▄▄▄▄███▄▄▄▄      ▄████████    ▄██████▄  ███    █▄     ▄████████                                    \n");    
          printf("                                        ▄██▀▀▀███▀▀▀██▄   ███    ███   ███    ███ ███    ███   ███    ███                                    \n");   
          printf("                                        ███   ███   ███   ███    ███   ███    █▀  ███    ███   ███    █▀                                     \n");    
          printf("                                        ███   ███   ███   ███    ███  ▄███        ███    ███   ███                                           \n");    
          printf("                                        ███   ███   ███ ▀███████████ ▀▀███ ████▄  ███    ███ ▀███████████                                    \n");    
          printf("                                        ███   ███   ███   ███    ███   ███    ███ ███    ███          ███                                    \n");    
          printf("                                        ███   ███   ███   ███    ███   ███    ███ ███    ███    ▄█    ███                                    \n");    
          printf("                                         ▀█   ███   █▀    ███    █▀    ████████▀  ████████▀   ▄████████▀                                     \n");    
          printf("     ========================================================================================================================================\n");
          printf("                             SEJA BEM VINDO BRAVO GUERREIRO, AO MAGUS, O RPG NARRATIVO MAIS TEMIDO DE TODOS                                  \n");
          printf("                                                                                                                                             \n");
          printf("                                       ||DIGITE ABAIXO O SEU NOME PARA INICIAR A SUA JORNADA||                                               \n");
          printf("     >> ");
          scanf("%s", player.nome);
          break;
          }//fecha case 2
    case 3:{ // Opção 2: Sair do Jogo
    system("clear");
    printf("     Eu sabia que ia escapar, a vitória cabe somente aos fortes! \n     Até logo, pobre desertor!");
    sleep(1);
    return 0;
  }//fecha case 3
    default:{ //Opção 3: Opção Inválida
    printf("\n");
    system("clear");
    printf("     Escolha uma das opções válidas pô, me ajuda a te ajudar!\n");
    sleep(1);
    break;
  }//fecha default  
    } 
        }//fecha case 1
}//Fecha o laço for


return 0;

};
