/* Este código cria uma matriz 3x3 para representar o tabuleiro do 
jogo da velha. O jogador 'X' começa e pode escolher uma posição no 
tabuleiro digitando um número de 1 a 9. O jogo continua até que um 
jogador vença ou ocorra um empate. O código verifica se há um vencedor 
ou empate após cada jogada. O programa usa funções 
para modularizar o código e torná-lo mais fácil de ler e manter.*/

#include <iostream>
using namespace std;

char board[3][3] = {'1','2','3','4','5','6','7','8','9'};
char player = 'X';

void drawBoard() {
    cout << "JOGO DA VELHA" << endl;
    cout << "-------------" << endl;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-------------" << endl;
}

void playerTurn() {
    int choice;
    cout << "Vez do jogador " << player << endl;
    cout << "Escolha uma posição (1-9): ";
    cin >> choice;

    int row = (choice-1) / 3;
    int col = (choice-1) % 3;

    if(board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Posição inválida. Tente novamente." << endl;
        playerTurn();
    } else {
        board[row][col] = player;
    }
}

bool checkWin() {
    for(int i=0; i<3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true;
        }
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }
    return false;
}

bool checkTie() {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer() {
    if(player == 'X') {
        player = 'O';
    } else {
        player = 'X';
    }
}

int main() {
    while(true) {
        drawBoard();
        playerTurn();
        if(checkWin()) {
            drawBoard();
            cout << "Jogador " << player << " ganhou!" << endl;
            break;
        }
        if(checkTie()) {
            drawBoard();
            cout << "Empate!" << endl;
            break;
        }
        switchPlayer();
    }

    return 0;
}

