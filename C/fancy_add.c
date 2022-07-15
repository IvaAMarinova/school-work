// a long way to add two numbers

unsigned add(unsigned x, unsigned y)
{
	unsigned help;

	while (y != 0) {
		help = x & y;
		x ^= y;
		y = help << 1;
	}
	return x;
}

void main()
{
	add(0, 0);
	add(-1, 2);
	add(3, 1);
}