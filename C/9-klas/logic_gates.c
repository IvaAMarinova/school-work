// all logic gates (that i know of)

int nand(int a, int b) 
{
	return !(a && b);
}

int nor(int a, int b)
{
	return !(a || b);
}

int not(int a) 
{
	return nand(a, a);
}

int and(int a, int b) 
{
	return not(nand(a, b));
}

int or(int a, int b)
{
	return nand(not(a), not (b));
}

int xor(int a, int b)
{
	return and (or (a, b), nand(a, b));
}

main()
{
	return 0;
}


