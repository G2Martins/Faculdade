#include <stdio.h>
#include <stdlib.h>

typedef struct carta {
    // estrutura das cartas 
    int valor;
    struct carta *proximo;
} carta;

typedef struct baralho {
    // estrutura do baralho
    int quantidade;
    struct carta *topo;
    // criei uma estrutura para guardar as cartas descartadas
    struct carta *descarte;
} baralho;

baralho *criaBaralho() {
    // maloca armazenamento para o baralho
    baralho *novoBaralho;
    novoBaralho = (baralho *)malloc(sizeof(baralho));
    novoBaralho->quantidade = 0;
    novoBaralho->topo = NULL;
    novoBaralho->descarte = NULL;
    return novoBaralho;
}

carta *criaCarta() {
    //maloca armazenamento para a carta
    carta *novaCarta;
    novaCarta = (carta *)malloc(sizeof(carta));
    novaCarta->valor = 0;
    novaCarta->proximo = NULL;
    return novaCarta;
}

void inserirCarta(int novoValor, baralho *Baralho) {
    // essa função vai inserir valores no baralho
    carta *ponteiro;
    carta *novaCarta;
    if (Baralho == NULL) {
        return;
    }
    novaCarta = criaCarta();
    novaCarta->valor = novoValor;
    if (Baralho->topo == NULL) {
        Baralho->topo = novaCarta;
    } else {
        ponteiro = Baralho->topo;
        while (ponteiro->proximo != NULL) {
            ponteiro = ponteiro->proximo;
        }
        ponteiro->proximo = novaCarta;
    }
    Baralho->quantidade++;
}

void jogarParaBaixo(baralho *Baralho) {
    // fiz essa função para não colocar tudo na função do jogo, a função do jogo vai somente descartar as cartas e chamar essa função
    //para redefinir a ordem do baralho
    carta *aux, *ponteiroTopo, *ponteiroFundo;
    //fazer ponteiroTopo apontar para a carta do topo
    ponteiroTopo = Baralho->topo;
    // ao final do while o ponteiroFundo vai apontar para o ultimo valor 
    ponteiroFundo = Baralho->topo;
    while (ponteiroFundo->proximo != NULL) {
        ponteiroFundo = ponteiroFundo->proximo;
    }
    // aux vai apontar para a segunda carta do baralho
    aux = ponteiroTopo->proximo;
    //fiz esse if porque quando a quantidade for 1 ele não jogar fora a carta restante no baralho
    if (Baralho->quantidade > 1) {
        //topo vai receber conteudo de aux
        Baralho->topo = aux;
        ponteiroFundo->proximo = ponteiroTopo;
        //ponteiroTopo->proximo vai receber NULL para não criar um while infinito exemplo 2->3->4->2->3->4->2->...
        ponteiroTopo->proximo = NULL;
    } else {
        // quando chegar nesse else eu só vou jogar o segundo para o primeiro e o primeiro para o ultimo
        Baralho->topo->proximo = NULL;
        ponteiroFundo->proximo = aux;
    }
}

void horaDoJogo(baralho *Baralho) {
    carta *ponteiroFundo;
    carta *ponteiroTopo;
    carta *aux;
    carta *ant;
    if (Baralho == NULL) {
        return;
    }
    // mesma logica, ao final do while ponteiroFundo vai receber a ultima carta 
    ponteiroFundo = Baralho->topo;
    while (ponteiroFundo->proximo != NULL) {
        ponteiroFundo = ponteiroFundo->proximo;
    }
    //ponteiro topo aponta para o primeiro
    ponteiroTopo = Baralho->topo;
    // esse while vai servir para sempre que eu quiser descartar uma carta ou seja quando a quantidade for >1
    while (Baralho->quantidade > 1) {
        // diminui a quantidade periodicamente
        Baralho->quantidade--;
        //sempre que entrar no while garanto que ponteiroTopo e ponteiroFundo aponte sempre para o primeiro e ultimo
        ponteiroTopo = Baralho->topo;
        ponteiroFundo = Baralho->topo;
        while (ponteiroFundo != NULL) {
            ponteiroFundo = ponteiroFundo->proximo;
        }
        //se for a primeira ocasião de descarte ou seja quando o descarte estiver vazio
        if (Baralho->descarte == NULL) {
            // aux vai receber o segundo valor
            aux = ponteiroTopo->proximo;
            // descarte vai receber o primeiro valor
            Baralho->descarte = ponteiroTopo;
            //ant vai receber ponteiroTopo
            ant = ponteiroTopo;
            //ant vai fazer com que esse valor deixe de apontar para os elementos do baralho evitando aquele caso do 1->2->3->1->...
            ant->proximo = NULL;
            //topo vai receber a carta abaixo do topo
            Baralho->topo = aux;
            //joga na função para reorganizar as cartas
            jogarParaBaixo(Baralho);
        } else {
            //quando entrar nessa condição eu tenho que garantir que ant aponte para o ultimo valor de descarte
            ant = Baralho->descarte;
            while (ant->proximo != NULL) {
                ant = ant->proximo;
            }
            //aux vai receber a segunda carta no baralho
            aux = ponteiroTopo->proximo;
            //a ultima carta do descarte vai receber a primeira carta do baralho
            ant->proximo = ponteiroTopo;
            //faço o ant ir para essa carta 
            ant = ant->proximo;
            //NULLO o ant->proximo para evitar o caso de repetição
            ant->proximo = NULL;
            //agora o topo do baralho vai receber a segunda carta
            Baralho->topo = aux;
            //reorganizo o baralho
            jogarParaBaixo(Baralho);
        }
    }
    return;
}

void printarDecarte(baralho *Baralho) {
    carta *aux;
    aux = Baralho->descarte;
    printf("Valores no descarte: ");
    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->proximo;
    }
    printf("\nValor que sobrou no Baralho: %d", Baralho->topo->valor);
}


void menu() {
    int opcao, opcao2;
    int valor;
    baralho *uno;
    do {
        uno = criaBaralho();
        printf("Bem Vindo ao jogo de Cartas do Miron:\n");
        printf("As regras do jogo são bla bla bla descarta e joga embaixo :)\n");
        printf("Voce tem duas opcoes:\n");
        printf("1. Adicionar cartas com valores definidos por voce\n");
        printf("2. Definir automaticamente o numero de cartas\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                do {
                    printf("Digite o valor da Carta (0 para finalizar): ");
                    scanf("%d", &valor);
                    if (valor != 0) {
                        inserirCarta(valor, uno);
                    }
                } while (valor != 0);
                    if (uno->quantidade > 0) { // Verifica se há cartas inseridas
                        horaDoJogo(uno);
                        printarDecarte(uno);
                    } else {
                        printf("Nenhuma carta inserida.\n");
                    }
                    break;


            case 2:
                printf("Digite ate que numero fazer o baralho: ");
                scanf("%d", &valor);
                for (int i = 1; i <= valor; i++) {
                    inserirCarta(i, uno);
                }
                horaDoJogo(uno);
                printarDecarte(uno);
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }

        printf("\nDeseja jogar novamente? (1 - SIM / 0 - NAO): ");
        scanf("%d", &opcao2);
    } while (opcao2 != 0);
}

int main() {
    menu();
    return 0;
}