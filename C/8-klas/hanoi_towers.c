#include <stdio.h>
#include <stdlib.h>
void hanoi(int, char, char, char);

int main()
{
    int n;

    printf("How many disks are there: ");
    scanf("%d", &n);

    printf("answer:\n");
    hanoi(n, 'A', 'C', 'B');
    return 0;
}
void hanoi(int n, char from, char to, char extra)
{
    if (n == 1)
    {
        printf("Move disk 1 from tower %c to tower %c\n", from, to);
        return;
    }
    hanoi(n - 1, from, extra, to);
    printf("Move disk %d from tower %c to tower %c\n", n, from, to);
    hanoi(n - 1, extra, to, from);
}
