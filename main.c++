#define _CRT_SECUIRE_NO_WARNINGS
#include <stdio.h>

char grid[3][3];

void initializeGrid() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid[i][j] = ' ';
        }
    }
}

void printGrid() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", grid[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
}

int checkWin() {
    for (int i = 0; i < 3; i++) {
        if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][0] != ' ') return 1;
        if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[0][i] != ' ') return 1;
    }
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != ' ') return 1;
    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] != ' ') return 1;
    return 0;
}

int main() {
    initializeGrid();
    char player = 'X';
    int row, col, moves = 0;
    while (1) {
        printGrid();
        printf("Player %c, enter row and column (0-2): ", player);
        scanf("%d %d", &row, &col);
        if (row < 0 || row > 2 || col < 0 || col > 2 || grid[row][col] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }
        grid[row][col] = player;
        moves++;
        if (checkWin()) {
            printGrid();
            printf("Player %c wins!\n", player);
            break;
        }
        if (moves == 9) {
            printGrid();
            printf("It's a draw!\n");
            break;
        }
        player = (player == 'X') ? 'O' : 'X';
    }
    return 0;
}
