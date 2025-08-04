#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char board[3][3];
void initializeBoard() {
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            board[i][j] = '1' + i * 3 + j;
}
void printBoard() {
    int i;
    for (i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2) printf("---|---|---\n");
    }
}
char checkWinner() {
    int i;
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return board[0][i];
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return board[0][2];
    return ' ';
}
int isDraw() {
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return 0;
    return 1;
}
int makeMove(char player, int cell) {
    if (cell < 1 || cell > 9) return 0;
    int row = (cell - 1) / 3;
    int col = (cell - 1) % 3;
    if (board[row][col] == 'X' || board[row][col] == 'O') return 0;
    board[row][col] = player;
    return 1;
}
int main() {
    char player = 'X';
    int cell;
    char input[10], *endptr;
    float floatInput;
    initializeBoard();
    while (1) {
        printBoard();
        printf("Player %c, enter cell number (1-9): ", player);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;
        floatInput = strtof(input, &endptr);
        if (*endptr != '\0') {
            printf("Invalid input. Try again.\n");
            continue;
        }
        cell = (int) floatInput;
        if (cell < 1 || cell > 9 || !makeMove(player, cell)) {
            printf("Invalid move. Try again.\n");
            continue;
        }
        if (checkWinner() != ' ') {
            printBoard();
            printf("Player %c wins!\n", checkWinner());
            break;
        }
        if (isDraw()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }
        player = (player == 'X') ? 'O' : 'X';
    }
}
