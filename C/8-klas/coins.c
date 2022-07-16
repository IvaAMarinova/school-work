#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int count;
    int coin_value;
    char *representation;
}coin;

void calculate(int, coin[]);
int main()
{
    coin coins[] = {{0, 100, "1 lv"}, {0, 20, "20 st"}, {0, 5, "5 st"}, {0, 1, "1 st"}};
    float sum;
    int sum_tr, i;

    do {
        printf("What is your sum: ");
        scanf("%f", &sum);
    } while (sum <=0 || sum > 100);

    sum_tr = (int)(sum * 100);

    printf("Its %d in coins\n", sum_tr);

    calculate(sum_tr, coins);

    for(i = 0; i < 4; i++) {
        printf("We use %d coins of value %s\n", coins[i].count, coins[i].representation);
}

    return 0;
}
void calculate(int sum, coin coins[])
{
    int unsigned rest;
    int i;

    for(i = 0; i < 4; i++) {
        coins[i].count = sum / coins[i].coin_value;
        rest = sum % coins[i].coin_value;
        if (rest == 0) {
            return 0;
        }
        sum = rest;
    }
    return;
}
