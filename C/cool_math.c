// i am sorry, i too don't know what is happening
// .. only if past me left ANY info about this one
// it would've been nice (what does super_cool_math_actions() even mean)

#include <stdio.h>
#include <stdlib.h>

int super_cool_math_actions(unsigned int given_num)
{
    unsigned int current = 1;

    while (given_num > current) {
            if (given_num % current) {
                printf("No answer, sori motori");
                return 0;
            }
            given_num = given_num /current;
            current++;
        }

    return current;
}

void main()
{
    unsigned int given_num, current = 1;

    do {
        printf("Whats your num: ");
        scanf("%d", &given_num);
    } while (given_num < 0 && given_num > 65000);

    printf("The answer is: %d", super_cool_math_actions(given_num));
}