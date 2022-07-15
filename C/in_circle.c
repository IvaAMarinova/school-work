// checks if a point is in circle

#include <stdio.h>
#include<math.h>

int in_circle(int Cx, int Cy, int r, int x, int y)
{
	int c = sqrt(pow(x - Cx, 2) + pow(y - Cy, 2));

	if (c < r)
	{
		return 1;
	}
	else return 0;
}

int main()
{
	if (in_circle(2, 1, 3, 5, 1)) {
		printf("True\n");
	}
	else printf("no\n");

	if (in_circle(2, 1, 3, 7, 7)) {
		printf("True\n");
	}
	else printf("no\n");

	if (in_circle(2, 1, 3, 2, 2)) {
		printf("True\n");
	}
	else printf("no\n");

}
