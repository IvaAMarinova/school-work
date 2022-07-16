
#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int count_ppl;
    int count_days;
    char season[6];
}packet;

void input(packet*);
float discount(packet*);

int main()
{
    packet* trip_packet;
    packet* t_packet;

    trip_packet = malloc(sizeof(packet));

    t_packet = trip_packet;

    if (trip_packet == NULL) {
        printf("There is not enough memory, sorry\n");
        return 1;
    }

    input(t_packet);

    printf("A trip for %d people, for %d days in the %s season costs %.2f lv!\n", t_packet->count_ppl, t_packet->count_days, t_packet->season, discount(t_packet));

    free(trip_packet);
    return 0;
}
void input(packet* p)
{
    char winter[] = "winter";
    char autumn[] = "autumn";
    char summer[] = "summer";
    char spring[] = "spring";

    do {
        printf("How many people are there: ");
        scanf("%d", &p->count_ppl);
    } while (p->count_ppl < 1 || p->count_ppl > 20);

    for (;;) {
        printf("What season: ");
        scanf("%s", &p->season);

        if (strcmp(winter, p->season) == 0) {
            break;
        }
        if (strcmp(autumn, p->season) == 0) {
            break;
        }
        if (strcmp(spring, p->season) == 0) {
            break;
        }
        if (strcmp(summer, p->season) == 0) {
            break;
        }
    }

    do {
        printf("For how many days: ");
        scanf("%d", &p->count_days);
    } while (p->count_days < 1 || p->count_days > 20);
}
float discount(packet* p)
{
    float prise;
    char winter[] = "winter";
    char autumn[] = "autumn";
    char summer[] = "summer";
    char spring[] = "spring";

    if (p->count_ppl <= 5) {
        prise = p->count_ppl * p->count_days * 5.50;
        if (p->count_days > 3) {
            prise = prise - (prise * 0.1);
            if (strcmp(winter, p->season) == 0) {
                prise = prise + (prise * 0.08);
            }
            if (strcmp(summer, p->season) == 0) {
                prise = prise - (prise * 0.15);
            }
        }
        if (p->count_days <= 3) {
            if (strcmp(winter, p->season) == 0) {
                prise = prise + (prise * 0.08);
            }
            if (strcmp(summer, p->season) == 0) {
                prise = prise - (prise * 0.15);
            }
        }
    }
    if (p->count_ppl > 5) {
        prise = p->count_ppl * p->count_days * 4.50;
        if (p->count_days > 3) {
            prise = prise - (prise * 0.1);
            if (strcmp(winter, p->season) == 0) {
                prise = prise + (prise * 0.08);
            }
            if (strcmp(summer, p->season) == 0) {
                prise = prise - (prise * 0.15);
            }
        }
        if (p->count_days <= 3) {
            if (strcmp(winter, p->season) == 0) {
                prise = prise + (prise * 0.08);
            }
            if (strcmp(summer, p->season) == 0) {
                prise = prise - (prise * 0.15);
            }
        }
    }

    return prise;
}
