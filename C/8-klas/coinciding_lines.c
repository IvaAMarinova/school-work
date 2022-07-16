#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define True 1
#define False 0


typedef struct {
    int x;
    int y;
    int c;
} line;

typedef struct {
    line first;
    line second;
    line third;
    line fourth;
    line fifth;
} list;

int check(line, line);
int main()
{
    list a;
    a.first.c = 0;
    a.second.c = 0;
    a.third.c = 0;
    a.fourth.c = 0;
    a.fifth.c = 0;
    int max, ans;


    trace();
    do {
        printf("Give me cordinates for the first line!\n");
        scanf("%d %d", &a.first.x, &a.first.y);
    } while (a.first.x <= 0 && a.first.y > 10000);

    do {
        printf("Give me cordinates for the second line!\n");
        scanf("%d %d", &a.second.x, &a.second.y);
    } while (a.second.x <= 0 && a.second.y > 10000);

    do {
        printf("Give me cordinates for the third line!\n");
        scanf("%d %d", &a.third.x, &a.third.y);
    } while (a.third.x <= 0 && a.third.y > 10000);

    do {
        printf("Give me cordinates for the fourth line!\n");
        scanf("%d %d", &a.fourth.x, &a.fourth.y);
    } while (a.fourth.x <= 0 && a.fourth.y > 10000);

    do {
        printf("Give me cordinates for the fifth line!\n");
        scanf("%d %d", &a.fifth.x, &a.fifth.y);
    } while (a.fifth.x <= 0 && a.fifth.y > 10000);

    if (check(a.first, a.second)) {
        a.first.c++;
        a.second.c++;
    }
    if (check(a.first, a.third)) {
        a.first.c++;
        a.third.c++;
    }
    if (check(a.first, a.fourth)) {
        a.first.c++;
        a.fourth.c++;
    }
    if (check(a.first, a.fifth)) {
        a.first.c++;
        a.fifth.c++;
    }
    if (check(a.second, a.third)) {
        a.second.c++;
        a.third.c++;
    }
    if (check(a.second, a.fourth)) {
        a.second.c++;
        a.fourth.c++;
    }
    if (check(a.second, a.fifth)) {
        a.second.c++;
        a.fifth.c++;
    }
    if (check(a.third, a.fourth)) {
        a.third.c++;
        a.fourth.c++;
    }
    if (check(a.third, a.fifth)) {
        a.third.c++;
        a.fifth.c++;
    }
    if (check(a.fourth, a.fifth)) {
        a.fourth.c++;
        a.fifth.c++;
    }

    ans = 1;
    max = a.first.c;
    if (max < a.second.c) {
        ans = 2;
        max = a.second.c;
    }
    if (max < a.third.c) {
        ans = 3;
        max = a.third.c;
    }
    if (max < a.fourth.c) {
        ans = 4;
        max = a.fourth.c;
    }
    if (max < a.fifth.c) {
        ans = 5;
        max = a.fifth.c;
    }

    printf("the answer is line %d and it crosses %d times\n", ans, max);

    printf("count 1 - %d count 2 - %d count 3 - %d count 4 - %d count 5 - %d\n", a.first.c, a.second.c, a.third.c, a.fourth.c, a.fifth.c);
    trace();
    return 0;
}
int check(line a, line b)
{
    if (a.y >= b.x && a.y <= b.y) {
        return True;
    }
    if (a.x >= b.x && a.x <= b.y) {
        return True;
    }
    return False;
}
