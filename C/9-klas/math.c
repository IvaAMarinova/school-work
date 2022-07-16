#include <stdio.h>
#include <stdlib.h>

int math(int x)
{
    int result, lower_num = 2, higher_num = x / 2, middle;

    if (x < 2) {
        return x;
    }

    do {
        middle = (lower_num + higher_num) / 2;

        if (middle * middle == x) {
            return middle;
        }
        if (middle * middle < x) {
            lower_num = middle + 1;
        }
        if (middle * middle > x) {
            higher_num = middle - 1;
        }
    } while (lower_num <= higher_num);

    if (result * result != x) {
        return 0;
    }
    return result;
}

void main()
{
    int given_number, answer;

    do {
        printf("Number = x^2: ");
        scanf("%d", &given_number);
    } while (given_number < 0 && given_number > 65000);


    answer = math(given_number);
    if (answer != 0) {
        printf("Answer = %d", answer);
    }
    else printf("There is no answer chao");
}
