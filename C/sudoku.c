// 8-klas

// sudoku game

// put initial sudoku game board numbers in separate file and put
// filename as second command line argument
// all board digits must be given with only one spaces between them!
// no tabs! no nothing!
// or just paste the three examples at the end and try with them.
// i know its annoying to search for boards and type them out like that
// but hey, it was the eaziest at the time, plus i was young so its forgiven
// might fix this one day

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0

int board[9][9];

int main(int argc, char* argv[])
{
    FILE* f;
    int i = 0, j = 0;

    f = fopen(argv[2], "r");

    if (f == NULL) {
        printf("Error reading file");
        return False;
    }

    for (i = 0; i <= 8; i++) {
        for (j = 0; j <= 8; j++) {
            fscanf(f, "%d", &board[i][j]);
        }
    }

    fclose(f);
    return True;
}

void print_board()
{
    int i, j;

    for (i = 0; i <= 8; i++) {
        for (j = 0; j <= 8; j++) {
            printf("%d ", board[i][j]);
            if ((j + 1) % 3 == 0) {
                printf("|| ");
            }
            else printf(" | ");

        }
        printf("\n");
        if ((i + 1) % 3 == 0) {
            printf("============================================\n");
        }
    }
}

int solve_board(int row, int col)
{
    int value;

    if (row == 8 && col == 9) {
        return True;
    }

    if (col == 9) {
        row++;
        col = 0;
    }

    if (board[row][col] > 0) {
        return solve_board(row, col + 1);
    }

    for (value = 1; value <= 9; value++) {
        if (check_valid(row, col, value) == True) {
            board[row][col] = value;
            if (solve_board(row, col + 1) == True) {
                return True;
            }
        }
        board[row][col] = 0;
    }

    return False;
}

int check_valid(int row, int col, int num)
{
    int i, j, nr, nc;

    for (i = 0; i <= 8; i++) {
        if (board[row][i] == num) {
            return False;
        }
    }
    for (i = 0; i <= 8; i++) {
        if (board[i][col] == num) {
            return False;
        }
    }

    nr = row - row % 3;
    nc = col - col % 3;

    for (i = 0; i <= 2; i++) {
        for (j = 0; j <= 2; j++) {
            if (board[i + nr][j + nc] == num) {
                return False;
            }
        }
    }
    return True;
}

int main()
{
    init_board();
    printf("Board before\n");
    print_board();
    if (solve_board(0, 0) == True) {
        printf("\n");
        printf("Solved board\n");
        print_board();
    }
    else {
        printf("No solution!");
    }

    return 0;
}

// first game
//8 0 0 0 0 0 0 0 0 0 0 3 6 0 0 0 0 0 0 7 0 0 9 0 2 0 0 0 5 0 0 0 7 0 0 0 0 0 0 0 4 5 7 0 0 0 0 0 1 0 0 0 3 0 0 0 1 0 0 0 0 6 8 0 0 8 5 0 0 0 1 0 0 9 0 0 0 0 4 0 0

// second game
//2 0 5 0 0 9 0 0 4 0 0 0 0 0 0 3 0 7 7 0 0 8 5 6 0 1 0 4 5 0 7 0 0 0 0 0 0 0 9 0 0 0 1 0 0 0 0 0 0 0 2 0 8 5 0 2 0 4 1 8 0 0 6 6 0 8 0 0 0 0 0 0 1 0 0 2 0 0 7 0 8

// third game
//3 0 5 4 0 2 0 6 0 4 9 0 7 6 0 1 0 8 6 0 0 1 0 3 2 4 5 0 0 3 9 0 0 5 8 0 9 6 0 0 5 8 7 0 3 0 8 1 3 0 4 0 9 2 0 5 0 6 0 1 4 0 0 2 0 0 5 4 9 0 7 0 1 4 9 0 0 7 3 0 6
