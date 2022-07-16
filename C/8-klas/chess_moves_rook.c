// checks how many empty spaces on the chess there are to move a rook 
// from random position

#include<stdlib.h>
#include<stdio.h>
#include<time.h>
int movesRook(int, int);

int main() {

    srand(time(NULL));
    int x, y, ans;

    x = 1 + (rand() % 8);
    y = 1 + (rand() % 8);

    ans = movesRook(x, y);

    printf("position rook - %d/%d has %d moves!", x, y, ans);

    return 0;
}

int movesRook(int x, int y)
{

    int br = 0;
    int a = x, b = y;

    for (y = b; y - 1 >= 1; br++, y--);
    for (x = a; x + 1 <= 8; br++, x++);
    for (y = b; y + 1 <= 8; br++, y++);
    for (x = a; x - 1 >= 1; br++, x--);

    return br;
}
