#include <stdio.h>
int determine(int);
int max_num(int);
int min_num(int);

int main()
{
    int op;

    for(;;)
{
    do
    {
        printf("\n");
            printf("-------------------------------------------------------\n");
            printf("1. Determine number n fibonacci \n");
            printf("2. Max number fibonachi that's not bigger n \n");
            printf("3. Min number fibonachi that's not lower n\n");
            printf("4. Exit\n");
            printf("-------------------------------------------------------\n");
            scanf("%d", &op);
        }
        while (op <1 && op > 4);

        switch(op)
        {
        case (1):
        {
            int n, ans;

            printf("n = ");
            scanf("%d", &n);

            ans = determine(n);

            printf("answer = %d", ans);
            break;
        }
        case (2):
        {
            int dadeno, ans;

            printf("n = ");
            scanf("%d", &dadeno);

            ans = max_num(dadeno);

            printf("answer = %d", ans);
            break;
        }
        case (3):
        {
            int dadeno, ans;

            printf("n = ");
            scanf("%d", &dadeno);

            ans = min_num(dadeno);

            printf("answer = %d", ans);
            break;
        }
        break;
        case (4):
            return 0;
        }
    }
    return 0;

}
int determine(n)
{
    int f1, f2, i, next_n;

    f1 = 0;
    f2 = 0;
    i = 0;

    for (i = 1; i <= n; i++)
    {

        next_n = f1 + f2;
        if (next_n == 0)
        {
            next_n = 1;
        }
        f1 = f2;
        f2 = next_n;

    }

    return next_n;
}
int max_num(dadeno)
{
    int f1, f2, i, next_n;

    f1 = 0;
    f2 = 0;
    i = 0;

    for (;;)
    {
        next_n = f1 + f2;

        if (next_n == 0)
        {
            next_n = 1;
        }
        if(next_n > dadeno)
        {
            return f2;
        }
        f1 = f2;
        f2 = next_n;
    }
}
int min_num(dadeno)
{
    int f1, f2, i, next_n;

    f1 = 0;
    f2 = 0;
    i = 0;

    for (;;)
    {
        next_n = f1 + f2;

        if (next_n == 0)
        {
            next_n = 1;
        }
        if(next_n >= dadeno)
        {
            return next_n;
        }
        f1 = f2;
        f2 = next_n;
    }
}
