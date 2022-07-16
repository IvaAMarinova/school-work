// sums two numbers from already existing file

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) // give filename as second argv argument
{
    FILE *f = fopen(argv[2], "r");
    int number1, number2, sum;

    if (f == NULL) 
    {
        printf("Can't open file for reading.\n");
        return 0;
    }

    fscanf(f, "%d", &number1);
    fscanf(f, "%d", &number2);
    printf("Sum of numbers %d and %d is %d", number1, number2, number1 + number2);
    return 0;
}
