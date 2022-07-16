#include <stdio.h>
#include <stdlib.h>
void power();
void whether_it_accures();
void how_many_times();
void prime();
void main(void)
{
    int op;

    do{
        printf("\n");
        printf("-------------------------------------------------------\n");
        printf("1. Calculate n power a:\n");
        printf("2. Determine whether a digit occurs in number n:\n");
        printf("3. Determine how many times a digit occurs in number n:\n");
        printf("4. Determine if number n is simple:\n");
        printf("5. Exit:\n");
        printf("-------------------------------------------------------\n");
        scanf("%d", &op);

        switch(op){
            case (1):
                power();
                break;
            case (2):
                hether_it_accures();
            break;
            case (3):
                how_many_times();
            break;
            case (4):
                prime();
            break;
            case (5):
                return 0;
        }
    } while (op != 5);
}


void power()
{
    int n, i;
    float result, a;

    do{
        printf("n = ");
        scanf("%d", &n);
    } while(n < 0);

    printf("a = ");
    scanf("%f", &a);

    result = 1;

    for(i = 0; i < n; i++){
        result = result * a;
    }
    printf("result = %f", result);

    return;
}
void whether_it_accures()
{
    int n, a;
    do{
        printf("number = ");
        scanf("%d", &n);
    } while (n < 0);

    do{
        printf("wanted number:");
        scanf("%d", &a);
    }while(a < 1 && a > 9);

    while(n > 0){
        if(n % 10 == a){
            printf("yes");
            return;
        }
        n = n / 10;
    }
    printf("no");
    return;
}
void how_many_times()
{
    int n, a, c;
    c = 0;
    do{
        printf("number = ");
        scanf("%d", &n);
    } while (n < 0);

    do{
        printf("wanted number:");
        scanf("%d", &a);
    }while(a < 1 && a > 9);

    while(n > 0){
        if(n % 10 == a){
           c = c + 1;
        }
        n = n / 10;
    }
    printf("answer = %d", c);
    return;
}
void prime()
{
    int n, i;

    do {
        printf(" num = ");
        scanf("%d", &n);
    } while (n < 1);

    i = 2;

    while(i < n) {
        if (n % i == 0) {
            printf("This number is not prime: (%d)\n", i);
            return 1;
            }
            i++;
            }
            printf("This number is prime \n");
    return;
}
