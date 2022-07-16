// rotates words in a string 
// "one two three " -> "three one two "

#include <stdio.h>
void rotate(char a[], unsigned size, int offset)
{
	size--;
	unsigned round = 0;

	do {
		char index = a[0];
		a[0] = a[size];
		for (unsigned i = size; i > 1; i--) {
			a[i] = a[i - 1];
		}
		a[1] = index;
		round++;
	} while (round < offset);
	for (unsigned j = 0; j <= size; j++) {
		printf("%c", a[j]);
	}
}

void main()
{
	char s[] = "one two three ";
	rotate(s, sizeof(s) - 1, 6);
}
