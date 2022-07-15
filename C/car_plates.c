#include <stdio.h>
#include <stdlib.h>

int convert(char);
int check(char*);
int calculate_answerK(int, int, int);
int calculate_answer(int, int, int);

int main()
{
    int alphabet[12] = {'A', 'B', 'E', 'K', 'M', 'H', 'O', 'P', 'C', 'T', 'Y', 'X'};
    char given_plate[20];
    int num, a, b, answerKAT, answer;
    int numbers[4];

    do {
        printf("What is your car plate?\n");
        scanf("%s", &given_plate[0]);
    } while (check(given_plate) == 0);

    num = (given_plate[0] - '0') * 1000 + (given_plate[1] - '0') * 100 + (given_plate[2] - '0') * 10 + (given_plate[3] - '0');

    a = convert(given_plate[4]);
    b = convert(given_plate[5]);


    answerKAT = calculate_answerK(num, a, b);
    answer = calculate_answer(num, a, b);

    printf("Answer Kat = %d\nAnswer = %d", answerKAT, answer);
    return 0;
}

int calculate_answerK(int num, int a, int b)
{
    return num + (((b * 1) + (a * 12)) * 10000);

}

int calculate_answer(int num, int a, int b)
{
    return num * 144 + ((b * 1) + (a * 12));

}

int check(char *given)
{
    int i;

    if (strlen(given) > 6) {
        return 0;
    }

    for (i = 0; i < 4; i++) {
        if (given[i] < '0' || given[i] > '9') {
            return 0;
        }
    }

    if(convert(given[4]) == -1) {
        return 0;
    }
    if(convert(given[5]) == -1) {
        return 0;
    }

    return 1;
}

int convert(char letter)
{
    switch(letter) {
    case ('A'):
        return 0;
        break;
    case ('B'):
        return 1;
        break;
    case ('E'):
        return 2;
        break;
    case ('K'):
        return 3;
        break;
    case ('M'):
        return 4;
        break;
    case ('H'):
        return 5;
        break;
    case ('O'):
        return 6;
        break;
    case ('P'):
        return 7;
        break;
    case ('C'):
        return 8;
        break;
    case ('T'):
        return 9;
        break;
    case ('Y'):
        return 10;
        break;
    case ('X'):
        return 11;
        break;
    default:
        return -1;
    }

}
