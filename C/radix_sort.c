// sorts binary numbers using radix

void sort(unsigned* l, unsigned* r, unsigned mask)
{
	if (r <= l || mask == 0)
		return;

	unsigned* p = l, * q = r, tmp;
	while (p < q)
	{
		while (p <= r && (~*p & mask)) ++p;
		while (l <= q && (*q & mask)) --q;

		if (p < q) tmp = *q, *q = *p, *p = tmp;
		
	}

	sort(l, q, mask >> 1);
	sort(p, r, mask >> 1);
}

void rsort(unsigned* l, unsigned size)
{
	sort(l, l + size - 1, 1 << 31);
}

void main()
{
	unsigned a[] = { 1100, 1010, 1111, 100 };
	rsort(a, sizeof a / sizeof * a);

	unsigned a1[] = { 11100, 1011010, 11101 };
	rsort(a1, sizeof a1 / sizeof * a1);

	unsigned a2[] = { 1100, 1100, 1100, 1100 };
	rsort(a2, sizeof a2 / sizeof * a2);

	unsigned a3[] = { 1100 };
	rsort(a3, sizeof a3 / sizeof * a3);
}