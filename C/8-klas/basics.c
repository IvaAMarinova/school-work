#include <stdio.h>
#include <stdlib.h>


int sum(int n){
    int a, i;
    a = 0;
    i = 0;

    do {
        a = i + a;
        i++;
    } while (i <= n);

    return a;
}

int sum_recursion(int n){
    if (n != 0)
        return n + sum_recursion(n - 1);
        else
            return n;

}

int pow(float a, int n, float result){
    int i;
    result = 1;

    for(i = 0; i < n; i++){
        result = result * a;
    }
    return result;
}

int pow_recursion(int a, int result, int n){
    if (n == 0)
        return result;
    return stepen(a, a * result, n - 1);
}


int p_bin(int a, int result, int n) {
    if(a == 0)
        return result;
    return p_bin(a / 2, (a % 2) * (n) + result, n * 10);
}

#include <stdio.h>
#include <stdlib.h>


int print_one_hundred()
{
    int i;

    for(i = 0; i < 100; i++){
        printf("hi sisters\n");
    }
    return 0;
}  

int print_backward_digits()
{
    int i;

    for(i = 100; i > 0; i--){
        printf("%d  ", i);
    }
    return 0;
}

int print_n_times()
{
    int i, n;
    printf("n:");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        printf("eyo!  ");
    }
    return 0;
}

int print_even_numbers_to_100()
{
    int i;
    for(i = 0; i < 100; i++){
        if(i % 2 == 0)
            printf("%d ", i);
    }
    return 0;
}

int print_odd_numbers_to_100()
{
    int i;
    for(i = 0; i < 100; i++){
        if(i % 2 != 1)
            printf("%d ", i);
    }
    return 0;
}


int print_even_numbers_to_n()
{
    int i, n;

    printf("n:");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        if(i % 2 == 0)
            printf("%d ", i);
    }
    return 0;
} 
int print_odd_numbers_to_n()
{
    int i, n;

    printf("n:");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        if(i % 2 == 1)
            printf("%d ", i);
    }
    return 0;
}

int check_even()
{
    int n;

    printf("your num: ");
    scanf("%d", &n);

    if(n % 2 == 0)
        printf("yes");
        else printf("no");
    return 0;

}

int check_devides_by_3()
{
    int n;

    printf("your num: ");
    scanf("%d", &n);

    if(n % 3 == 0)
        printf("yes");
        else printf("no");
    return 0;

}


int check_devides_by_5()
{
    int n;

    printf("your num: ");
    scanf("%d", &n);

    if(n % 5 == 0)
        printf("yes");
        else printf("no");
    return 0;

}



int check_simple_num()
{
    int n, i;


    printf(" num = ");
    scanf("%d", &n);


    for(i = 2; i < n; i++){
        if (n % i == 0) {
            printf("This number is not prosto");
            return;
        }
    }
    printf("This number is prosto");
    return 0;
}

int swap_one()
{
    int a, b, c;

    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);

    c = a;
    a = b;
    b = c;

    printf("new numbers are a = %d, b = %d", a, b);
    return 0;
}

int swap_two()
{
    int a, b;

    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);

    a = a + b;
    b = a - b;
    a = a - b;

    printf("new numbers are a = %d, b = %d", a, b);
    return 0;
}


int ascii_n()
{
    char a;
    printf("num:");
    scanf("%c",&a);
    printf("%d",a);
}

int figure()
{
    int i, a;

    printf("y\n");
    printf("ye\n");
    printf("yee");
    for(a = 0; a < 100; a++){
        for(i = 0; i < a ; i++)
        {
            printf("yeet");
        }
        printf("\n");
    }
}

#include <stdio.h>
#include <stdlib.h>
/*
От N на брой числа изведете най-голямото и най-малкото.
a. Пазете числата в масив
b. прочетете ги от екрана
*/
int min_and_max()
{
    int array[100];
    int min, max, n, i, a;

    printf("how many numbers? :");
    scanf("%d", &n);

    printf("give me your elements:");

    for(i = 0; i < n; i++)
        {
	      scanf("%d",&array[i]);
	    }

    max = array[0];
    min = array[0];

    for(i = 1; i < n; i++)
    {
        if(array[i] > max)
        {
            max = array[i];
        }


        if(array[i] < min)
        {
            min = array[i];
        }
    }

    for(a = 0; a < n; a++){
      printf("%d", array[a]);
    }

    printf("\n max is : %d\n", max);
    printf("min is : %d\n", min);

}


struct point {
    int x;
    int y;
};

int what_quadrant()
{
    struct point pt;

    printf("GIVE ME X:");
    scanf("%u", &pt.x);
    printf("GIVE ME Y:");
    scanf("%u", &pt.y);

    if(pt.x >= 0 && pt.y >= 0){
        printf("first!");
    }
    if(pt.x < 0 && pt.y >= 0){
        printf("second!");
    }
    if(pt.x < 0 && pt.y < 0){
        printf("third!");
    }
    if(pt.x >= 0 && pt.y < 0){
        printf("fourth!");
    }
}

int multiplication(int a, int b)
{
    int b, a;
    if (b != 1){
        a = a + multiplication(a, b - 1);
    }

    return a;
}

#include <stdio.h>
#include <stdlib.h>

int sum_rec(int n)
{
    int s;
    s = n;

    if(s != 0) {
        s = n + fact(n - 1);
    }

    return s;

}
*/
/*
//if a num contains a digit
int fact(int, int);
int main()
{
    int a, b;

    printf("gimme your number:\n");
    scanf("%d", &a);
    printf("gimme your digit\n");
    scanf("%d", &b);


    if(fact(a, b)){
        printf("yes");
    } else printf("no");

    return 0;
}
int fact(int a, int b)
{
    if (a % 10 == b)
        return 1;
    else if (a/10 == 0)
        return 0;
    else
        return fact(a / 10, b);
}
*/
// multiplication by summing
int fact(int a,int b);
int main()
{
    int a,b;

    printf("gimme first num\n");
    scanf("%d", &a);
    printf("gimme second num\n");
    scanf("%d",&b);
    printf("\n");

    printf("answer equals to %d", fact(a,b));

    return 0;
}
int fact(int a, int b)
{
    if(b != 1)
    {
        a = a + fact(a, b - 1);
    }
    return a;
}
