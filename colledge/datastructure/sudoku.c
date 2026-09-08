#include <stdio.h>
#include <stdbool.h>

#define N 9

void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d", board[i][j]);
            if ((j + 1) % 3 == 0 && j < N) printf("|");
            else printf(" ");
        }
        printf("\n");
        if ((i + 1) % 3 == 0 && i < N - 1) {
            printf("- - - - - - - - -\n");
        }
    }
}

bool isValid(int board[N][N], int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (board[row][x] == num) return false;
    }
    for (int x = 0; x < N; x++) {
        if (board[x][col] == num) return false;
    }
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == num) return false;
        }
    }
    return true;
}

bool solve(int board[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (isValid(board, row, col, num)) {
                        board[row][col] = num;
                        if (solve(board)) return true;
                        board[row][col] = 0; 
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    int board[N][N] = {0};

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    if (solve(board)) {
        printBoard(board);
    }

    return 0;
}

/*
8 0 1 0 3 4 6 0 9 
6 9 2 0 5 7 1 3 0 
3 7 4 0 6 0 0 5 2 
0 1 8 0 2 6 3 9 7 
2 0 7 9 8 3 4 1 5 
0 3 9 4 7 0 2 6 0 
7 4 0 3 1 0 9 0 0 
9 8 3 6 4 5 0 2 1 
1 2 0 7 9 8 5 4 3
*/