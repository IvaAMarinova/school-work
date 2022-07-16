#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[100], matching, wanted;
    int done = 0, i;

    printf("Give me your string: ");
    scanf("%s", &str);

    printf("Gimme your wanted symbol: ");
    getchar();
    wanted = getchar();



    for (i = 0; str[i] != '\0'; i++) {
        if (wanted == str[i]) {
            printf("You have a matching character in %d position.\n", i);
            done = 1;
        }
        if (done == 1) {
            printf("the rest characters are %c\n", str[i]);
        }

    }
    if (done == 0) {
        printf("there is no answer sorry\n");
    }


    return 0;
}
