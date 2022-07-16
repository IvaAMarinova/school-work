#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double a, b, c, x1, x2, D;

    printf("give me value for a: ");
    scanf("%lf", &a);
    printf("give me value for b: ");
    scanf("%lf", &b);
    printf("give me value for c: ");
    scanf("%lf", &c);

    D = (b * b) - (4 * a * c);

    printf("D = %.2lf\n", D);

    if (D < 0){
        printf("There are no solutions, sorry!");
    }
    if (D > 0){
        x1 = (-b - sqrt(D)) / (2 * a);
        x2 = (-b + sqrt(D)) / (2 * a);
        printf("There are two solutions, x1 = %.2lf and x2 = %.2lf", x1, x2);
    }
    if (D == 0){
        x1 = x2 = - b / (2 * a);
        printf("There is only one solution and its x1 = x2 = %.2lf", x1);
    }
}