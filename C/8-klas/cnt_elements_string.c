#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[1000];
    int c = 0;

    printf("Type your string(max 100 symbols):\n");
    gets(str);

    while(str[c] != '\0'){
        c++;
    }
    printf("Your strings has --> %d <-- elements\n", c);

    return 0;
}
