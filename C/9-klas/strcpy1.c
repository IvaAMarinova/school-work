// essentialy the same as the strcpy() func

#include <stdio.h>

void strcpy(char* dest, const char* src)
{
	while (*dest++ = *src++)
	*dest = '\0';
}


void main()
{
	char buffer[100];
	strcpy(buffer, "Hello");
}