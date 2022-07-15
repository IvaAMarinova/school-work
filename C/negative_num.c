// turns a positive number to negative

#include <stdio.h>
int neg(int x)
{
	return ~x + 1;
}

void main()
{
	printf("%d", neg(3));
}