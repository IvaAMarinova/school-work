// checks how many empty spaces on the chess there are to move a bishop 
// from random position

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int moves_bishop(int, int);
int main() {

    srand(time(NULL));
    int x, y;

    x = 1 + (rand() % 8);
    y = 1 + (rand() % 8);

    printf("position bishop - %d/%d has %d moves!", x, y, moves_bishop(x, y));

    return 0;
}

int moves_bishop(int x, int y)
{
    int br = 0;
    int a = x, b = y;

    for (x = a, y = b; x + 1 <= 8 && y + 1 <= 8; br++, x++, y++);
    for (x = a, y = b; x + 1 <= 8 && y - 1 >= 1; br++, x++, y--);
    for (x = a, y = b; x - 1 >= 1 && y + 1 <= 8; br++, x--, y++);
    for (x = a, y = b; x - 1 >= 1 && y - 1 >= 1; br++, x--, y--);

    return br;
}

