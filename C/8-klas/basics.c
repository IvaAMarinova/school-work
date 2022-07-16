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

void print_one_hundred()
{
    for(int i = 0; i < 100; i++) printf("hi sisters\n");
}  

void print_backward_digits()
{
    int i;

    for(i = 100; i > 0; i--){
        printf("%d  ", i);
    }
}

void print_n_times()
{
    int i, n;
    printf("n:");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        printf("Hello world!  ");
    }
}

void print_even_numbers_to_100()
{
    int i;
    for(i = 0; i < 100; i++){
        if(i % 2 == 0)
            printf("%d ", i);
    }
}

void print_odd_numbers_to_100()
{
    int i;
    for(i = 0; i < 100; i++){
        if(i % 2 != 1)
            printf("%d ", i);
    }
}


void print_even_numbers_to_n()
{
    int i, n;

    printf("n:");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        if(i % 2 == 0)
            printf("%d ", i);
    }
} 

void print_odd_numbers_to_n()
{
    int i, n;

    printf("n:");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        if(i % 2 == 1)
            printf("%d ", i);
    }
}

int check_even()
{
    int n;

    printf("your num: ");
    scanf("%d", &n);

    if(n % 2 == 0)
    {
        printf("yes");
        return 1;
    }     
    printf("no");
    return 0;

}

int check_devides_by_5()
{
    int n;

    printf("your num: ");
    scanf("%d", &n);

    if(n % 5 == 0)
    {
        printf("yes");
        return 1;
    }     
    printf("no");
    return 0;
}

int check_simple_num()
{
    int n, i;


    printf(" num = ");
    scanf("%d", &n);


    for(i = 2; i < n; i++){
        if (n % i == 0) {
            printf("This number is not simple");
            return 0;
        }
    }
    printf("This number is simpleo");
    return 1;
}

void swap_one()
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
}

void swap_two()
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
}

void ascii_n()
{
    char a;
    printf("num:");
    scanf("%c",&a);
    printf("%d",a);
}

// prints a simple figure 
void figure()
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

void min_and_max()
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

void what_quadrant()
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
    if (b != 1) a = a + multiplication(a, b - 1);
    return a;
}

int sum_rec(int n)
{
    int s = n;
    if(s != 0) s = n + fact(n - 1);
    return s;
}

int num_contains_digit(int a, int b)
{
    if (a % 10 == b)
        return 1;
    else if (a/10 == 0)
        return 0;
    else
        return fact(a / 10, b);
}

// finds given character and prints all characters after that
int find_char()
{
    char str[100], wanted, buffer[100];

    printf("Give me your string: ");
    scanf("%s", &str);

    printf("Gimme your wanted symbol: ");
    getchar();
    wanted = getchar();

    int lenght = strlen(str);

    for (int i = 0; i < length; i++) {
        if (wanted == str[i]) {
            printf("You have a matching character in %d position\n", i + 1);
            for (int j = 0; str[i] != '\0'; j++, i++) {
                buffer[j] = str[i + 1];
            }
            printf("The rest of the string is: %s\n", buffer);
        }
        if ((i + 1) == lenght) {
            printf("There is no answer, sorry");
            return 0;  
        }
    }
    return 1;
}

int max_num()
{
    int a, b, c, max;

    printf("number 1:");
    scanf("%d", &a);
    printf("number 2:");
    scanf("%d", &b);
    printf("number 3:");
    scanf("%d", &c);

    if (a > b) max = a;
    else max = b;
    if (c > max)
        max = c;

    printf("max number = %d", max);
    return max;
}

void simple_dividers()
{
    int n, c = 0, i = 2, j;

    do {
        printf("num = ");
        scanf("%d", &n);
    } while (n <= 1);

    while(n >= i){
        if(n % i == 0){
            j = 2;
            while(i % j > 0)
                j++;
            if (j == i) {
                printf("%d is a simple devider\n", i);
                c++;
            }

        }
        i++;
    }
    printf ("The number has this many %d simple deviders\n", c);
}

void guess_random_num()
{
    int given_num, chosen_num;

    for(int i = 0; i < 1; i++) chosen_num = rand() % 100;

    printf("Your number (it must be >0 and <100): ");
    scanf("%d", &given_num);

    if(given_num == chosen_num) printf("Congratulations! You were right!");
    else if (given_num < chosen_num) printf("Oops, your number is too low.");
    else if (given_num > chosen_num) printf("Oops, your number is too high.");
}

float avr_grade()
{
    int n, i;
    float a, sum, avr;

    do{
        printf("n =");
        scanf("%d", &n);
    }while(n < 0);

    sum = 0;
    i = 1;

    while(i <= n){
        printf("new grade: ");
        scanf("%f", &a);
        sum = sum + a;
        i++;
    }
    avr = sum / n;

    printf("avr = %f", avr);
    return avr;
}