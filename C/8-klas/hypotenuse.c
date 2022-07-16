#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double a, b, c;

    printf("Hi! \n Please enter\n");
    printf("cathetus a: ");
    scanf("%lf", &a);
    printf("cathetus b: ");
    scanf("%lf", &b);

    c = a * a + b * b;

    printf("Hypotenuse = %.2f", sqrt(c));
    return 0;
}
