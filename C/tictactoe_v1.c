// 8 klas

// my first tic tac toe from 2021

// it's important to note that the way i calculate the smart move
// isn't something innovative or elegant, i just played the game until
// i found the winning patern. basically it's a bunch of if statements..
// but hey, it works!!! and most importantly, it can't be beaten sooo..

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int step = 0;
void create_board(void);
void print_board(void);
void player_move(void);
int check_full_line(void);
void computer_move(void);
void first_empty(int*, int*);
int check_winner();
int check_possible_win(char, int*, int*); 
void smart_move(int*, int*); 

char board[3][3];

int main()
{
    printf("This is my game of Tic Tac Toe.\n");
    printf("I am challenging YOU to beat ME! Bet you can't.\n");
    printf("You'll be playing with 'X' and I (the program) with 'O'.\n");
    printf("Also, to select a box you'll need to tell me it's coordinates, they are from 1-3!\n");
    printf("Good luck!!!.... you'll need it.\n");
    printf("\n");

    create_board();

    for (;;) {
        print_board();
        player_move();
        if (check_winner()) return;
        computer_move();
        if (check_winner()) return;
    }
    return 0;
}
void create_board()
{
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
            board[i][j] = ' ';
    }
}
void print_board()
{
    for (int t = 0; t < 3; t++) {
        printf(" %c || %c || %c ", board[t][0], board[t][1], board[t][2]);
        if (t != 2)
            printf("\n---||---||---\n");
    }
    printf("\n");
}
void player_move()
{
    int x, y;
    printf("Enter [X][Y] coordinates for your move (ex: 1 1):  ");
    scanf("%d%*c%d", &x, &y);

    x--; y--;

    if (board[x][y] != ' ') {
        printf("Invalid move, you cant place it there, try again.\n");
        player_move();
    }
    else board[x][y] = 'X';
    step++;
}

int check_full_line(void)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ') {
            return board[i][0];
        }
    }
    for (i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ') {
            return board[0][i];
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2];
    }

    return 0;

}

void computer_move(void)
{
    int x = 0, y = 0;

    if (check_possible_win('O', &x, &y)) {
    }
    else if (check_possible_win('X', &x, &y)) {
    }
    else smart_move(&x, &y);

    board[x][y] = 'O';
}

int check_possible_win(char b, int* x, int* y)
{
    int i;
    for (i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][1] == b && board[i][2] == ' ') {
            *x = i, *y = 2;
            return 1;
        }
    for (i = 0; i < 3; i++)
        if (board[i][0] == board[i][2] && board[i][2] == b && board[i][1] == ' ') {
            *x = i, *y = 1;
            return 1;
        }
    for (i = 0; i < 3; i++)
        if (board[i][1] == board[i][2] && board[i][2] == b && board[i][0] == ' ') {
            *x = i, *y = 0;
            return 1;
        }

    for (i = 0; i < 3; i++)
        if (board[0][i] == board[1][i] && board[1][i] == b && board[2][i] == ' ') {
            *x = 2, *y = i;
            return 1;
        }

    for (i = 0; i < 3; i++) {
        if (board[1][i] == board[2][i] && board[2][i] == b && board[0][i] == ' ') {
            *x = 0, *y = i;
            return 1;
        }
    }

    for (i = 0; i < 3; i++)
        if (board[0][i] == board[2][i] && board[2][i] == b && board[1][i] == ' ') {
            *x = 1, *y = i;
            return 1;
        }

    if (board[0][0] == board[1][1] && board[1][1] == b && board[2][2] == ' ') {
        *x = 2, *y = 2;
        return 1;
    }
    if (board[0][0] == board[2][2] && board[2][2] == b && board[1][1] == ' ') {
        *x = 1, *y = 1;
        return 1;
    }
    if (board[1][1] == board[2][2] && board[2][2] == b && board[0][0] == ' ') {
        *x = 0, *y = 0;
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == b && board[2][0] == ' ') {
        *x = 2, *y = 0;
        return 1;
    }
    if (board[1][1] == board[2][0] && board[2][0] == b && board[0][2] == ' ') {
        *x = 0, *y = 2;
        return 1;
    }
    if (board[0][2] == board[2][0] && board[2][0] == b && board[1][1] == ' ') {
        *x = 1, *y = 1;
        return 1;
    }
    return 0;
}

void first_empty(int* x, int* y)
{
    for (int a = 0; a < 3; a++) {
        for (int b = 0; b < 3; b++) {
            if (board[a][b] == ' ') {
                *x = a;
                *y = b;
                return;
            }
        }
    }
}

int check_winner()
{
    int c = check_full_line();

    if (c == 'X') {
        print_board();
        printf("-------------------You won!-------------------");
        return 1;
    }
    if (c == 'O') {
        print_board();
        printf("-------------------I WON HAHA LOSER!-------------------");
        return 1;
    }
    if (c == 0) {
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                if (board[x][y] == ' ') {
                    return 0;
                }
            }
        }
    }
    print_board();
    printf("-------------------We are draw! Better luck next time.-------------------");
    return 1;
}

void smart_move(int* x, int* y)
{
    if (step == 1) {
        if (board[0][0] == 'X' || board[0][2] == 'X' || board[2][0] == 'X' || board[2][2] == 'X') {
            *x = 1, *y = 1;
        }
    }

    if (step > 1 && board[1][1] == 'O') {
        if (board[0][1] == ' ' && board[2][1] == ' ') {
            *x = 2, *y = 1;
            return;
        }
        if (board[1][0] == ' ' && board[1][2] == ' ') {
            *x = 1, *y = 2;
            return;
        }
    }

    if (board[0][0] == 'X' && board[2][2] == 0) {
        *x = 2, *y = 2;
        return;
    }
    if (board[0][2] == 'X' && board[2][0] == ' ') {
        *x = 2;
        *y = 0;
        return;
    }
    if (board[2][0] == 'X' && board[0][2] == ' ') {
        *x = 0, *y = 2;
        return;
    }
    if (board[2][2] == 'X' && board[0][0] == ' ') {
        *x = 0, *y = 0;
        return;
    }

    if (board[0][0] == 'X' && board[2][2] == 'X') {
        if (board[0][2] == ' ') {
            *x = 0, *y = 2;
            return;
        }
        if (board[2][0] == ' ') {
            *x = 2, *y = 0;
            return;
        }
    }
    if (board[2][0] == 'X' && board[0][2] == 'X') {
        if (board[0][0] == ' ') {
            *x = 0, *y = 0;
            return;
        }
        if (board[2][2] == ' ') {
            *x = 2, *y = 2;
            return;
        }
    }

    if (board[1][1] == ' ') {
        *x = 1, *y = 1;
        return;
    }
    first_empty(x, y);
}
