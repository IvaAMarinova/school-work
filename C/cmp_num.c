// compares numbers 

#include <stdio.h>

less(int l, int r)
{
	return l < r;
}

less_eq(int l, int r)
{
	return (less(l, r) || equal(l, r));
}

greater(int l, int r)
{
	return r < l;
}

greater_eq(int l, int r)
{
	return (greater(l, r) || equal(l, r));
}

equal(int l, int r)
{
	return !(less(l, r) || greater(l, r));
}

different(int l, int r)
{
	return less(l, r) || greater(l, r);
}

void main()
{
	different(1, 1);
	less(1, 1);
	less_eq(1, 1);
	greater(1, 1);
	greater_eq(1, 1);
	equal(1, 1);
	different(1, 1);
}
