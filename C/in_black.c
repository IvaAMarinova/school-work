// checks if a chess square is black or white

int in_black(unsigned r, unsigned x, unsigned y)
{
	return ((x / r) % 2) == ((y / r) % 2);
}

void main()
{
	in_black(10, 10, 10);
	in_black(10, 5, 10);
	in_black(2, 9, 5);
}