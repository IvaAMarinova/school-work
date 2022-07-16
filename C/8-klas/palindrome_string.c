#include <string.h>


int main()
{
    char str[1000];
    int i,n,c=0;

    printf("Type your string(max 100 symbols):\n");
    gets(str);

    n = strlen(str);

    for(i = 0;i < n/2; i++)
    {
    	if(str[i] == str[n - i - 1])
    	c++;
 	}

 	if(c == i)
 	    printf("Your string is palindrome!");
    else
        printf("Your string is not palindrome...");

    return 0;
}
