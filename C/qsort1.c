// Quick sort

void qsort(int* left, int* right)
{
	while (left < right)
	{
		int* p = left, * q = right, anchor = left[(right - left) / 2];
		while (p < q)
		{
			while (*p < anchor) p++;
			while (anchor < *q) q--;

			if (p <= q) {
				int swap = *p;
				*p = *q; *q = swap;
				p++; q--;
			}

		}
		if (q - left < right - p) {
			qsort(left, q);
			left = p;
		}
		else {
			qsort(p, right);
			right = q;
		}
	}
}

main()
{

	int a1[] = { 100, 20, 200, 30, 300, 40, 400, 50 };
	qsort(a1, a1 + sizeof a1 / sizeof * a1 - 1);

	int a2[] = { 400, 300, 200, 100, 50, 40, 30, 20 };
	qsort(a2, a2 + sizeof a2 / sizeof * a2 - 1);

	int a3[] = { 80, 70, 60, 10, 0, 90, 20 };
	qsort(a3, a3 + sizeof a3 / sizeof * a3 - 1);

	int a4[] = { 10, 20, 30, 40, 50, 60 };
	qsort(a4, a4 + sizeof a4 / sizeof * a4 - 1);

	int a5[] = { 1 };
	qsort(a5, a5 + sizeof a5 / sizeof * a5 - 1);

	int a10[] = { 69, 69, 69, 69 };
	qsort(a10, a10 + sizeof a10 / sizeof * a10 - 1);
}
