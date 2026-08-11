#include <stdio.h>

char board[3][3]; // Tabuleiro do jogo

// Função para inicializar o tabuleiro
void initialize_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
}

// Função para imprimir o tabuleiro
void print_board() {
    int i, j;
    printf("\n  0 1 2\n");
    for (i = 0; i < 3; i++) {
        printf("%d ", i);
        for (j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se há um vencedor
char check_winner() {
    int i;
    // Verificando linhas e colunas
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-') {
            return board[i][0]; // Retorna o símbolo do vencedor
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-') {
            return board[0][i]; // Retorna o símbolo do vencedor
        }
    }
    // Verificando diagonais
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return board[1][1]; // Retorna o símbolo do vencedor
    }
    return ' '; // Retorna espaço se não houver vencedor
}

// Função para marcar uma posição no tabuleiro
void mark_board(int row, int col, char symbol) {
    if (board[row][col] == '-') {
        board[row][col] = symbol;
    } else {
        printf("Posição inválida! Tente novamente.\n");
    }
}

int main() {
    int row, col, player = 1;
    char symbol, winner;
    initialize_board();
    printf("Bem-vindo ao Jogo da Velha!\n");
    printf("Jogador 1: X\n");
    printf("Jogador 2: O\n\n");
    print_board();
    do {
        player = (player % 2) ? 1 : 2;
        symbol = (player == 1) ? 'X' : 'O';
        printf("Jogador %d, digite a linha e coluna para marcar '%c': ", player, symbol);
        scanf("%d %d", &row, &col);
        mark_board(row, col, symbol);
        print_board();
        winner = check_winner();
        player++;
    } while (winner == ' ' && row >= 0 && row < 3 && col >= 0 && col < 3);
    if (winner != ' ') {
        printf("Parabéns! O jogador %c venceu!\n", winner);
    } else {
        printf("Empate!\n");
    }
    return 0;
}
