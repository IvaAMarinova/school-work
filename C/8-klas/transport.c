#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* month();
int main()
{
    srand(time(NULL));

    int km, stop, count = 0;
    float price;

    for(;;){
        do {
            printf("How many km: ");
            scanf("%d", &km);
            if (km < 1 || km > 1000) {
                printf("Try again!\n");
            }
            count = 1;
        } while(km < 1 || km > 1000);


        if (km <= 100) {
            price = km * 0.29;
        }
        if (km > 100 && km <= 200) {
            price = (100 * 0.29) + (km - 100) * 0.39;
        }
        if (km > 200) {
            price = 100 * 0.29 + 200 * 0.39 + (km - 200) * 0.49;

        }

        if (count % 3 == 0) {
            price = price * 0.9;
        }

        printf("Order can be done in %s for %.2f leva\n\n", month(), price);

        printf("If you want to quit the program type 0. If you want to continue type 1.\n");
        scanf("%d", &stop);

        if (stop == 0) {
            break;
        }

    }
    return 0;
}

char* month()
{
    srand(time(NULL));
    int one_month;

    one_month = rand() % 12;

    char* months[12] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};

    return months[one_month];
}
