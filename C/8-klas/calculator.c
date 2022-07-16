#include <stdio.h>
int main()
{
    float a, b;
    char c;

    
    printf("symbol:");
    scanf("%c", &c);
    c = getchar();
    while(c !=  '+' && c != '-' && c != '*' && c != '/');

    printf("number one:");
    scanf("%d", &a);
    printf("number two:");
    scanf("%d", &b);
    getchar();

    switch(c){
    case '+': a += b; break;
    case '-': a -= b; break;
    case '*': a *= b; break;
    case '/': a /= b; break;
    }
    

    printf("answer = %f ", a);
    return 0;
}