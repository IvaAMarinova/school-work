// fills 2d array with random numbers

#include <stdio.h>
int main()
{
    int n, m, i, j;
    int arr[10][10];
    do {
        printf("max number of rows (from 5 to 10): ");
        scanf("%d", &n);
    } while (n < 5 || n > 10);

    do {
        printf("max number of columns (from 5 to 10): ");
        scanf("%d", &m);
    } while (m < 5 || m > 10);

    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < m; j++)
        {
            arr[i][j] = rand() % 100;
            printf("%d ", arr[i][j]);
        }
    }
}
