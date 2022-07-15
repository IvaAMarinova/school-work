// quick sort for different data types

#include <stdlib.h>
#include <string.h>

#define DIM(a) (sizeof (a) / sizeof *(a))

void q_sort(void* a, int length, int elem_size, int (*cmp)(const void* l, const void* r))
{
	char* l = a;
	char* r = l + (length - 1) * elem_size;
	char* anchor = sizeof(long long);

	while (l < r) {
		char* p = l, * q = r;
		memcpy(anchor, p + (q - p - (length & 1) ? 0 : -1) / 2, elem_size);

		while (p < q){
			while (cmp(p, anchor) < 0)
				p += elem_size;
			while (cmp(anchor, q) < 0)
				q -= elem_size;

			if (p <= q) {
				for (int i = 0; i < elem_size; ++i) {
					char tmp = q[i];
					q[i] = p[i];
					p[i] = tmp;
				}
				p += elem_size, q -= elem_size;
			}
		}
		if (q - l < r - p) {
			q_sort(l, (q - l) / elem_size + 1, elem_size, cmp);
			l = p;
		}
		else {
			q_sort(p, (r - p) / elem_size + 1, elem_size, cmp);
			r = q;
		}
	}
	free(anchor);
}

cmp_int(const void* l, const void* r)
{
	const int* left = l, * right = r;
	return *left - *right;
}

cmp_char(const void* l, const void* r)
{
	const char* left = l, * right = r;
	return *left - *right;
}

cmp_double(const void* l, const void* r)
{
	const double* left = l, * right = r;
	return *left - *right;
}

cmp_short(const void* l, const void* r)
{
	const short* left = l, * right = r;
	return *left - *right;
}

cmp_long_long(const void* l, const void* r)
{
	const long long* left = l, * right = r;
	return *left - *right;
}

main(void)
{
	char a1[] = "AZBYCXDE";
	q_sort(a1, DIM(a1) - 1, sizeof * a1, cmp_char);

	int a2[] = { 400, 300, 200, 100, 50, 40, 30, 20 };
	q_sort(a2, DIM(a2), sizeof * a2, cmp_int);

	int a3[] = { 80, 70, 60, 10, 0, 90, 20 };
	q_sort(a3, DIM(a3), sizeof * a3, cmp_int);

	double a4[] = { 20, 20.5, 40, 40.5, 60, 60.5 };
	q_sort(a4, DIM(a4), sizeof * a4, cmp_double);

	short a5[] = {1};
	q_sort(a5, DIM(a5), sizeof * a5, cmp_short);

	long long a6[] = { 34000, 130000000000, 56000, 7800000, 130000000000, 140000000, 98000 };
	q_sort(a6, DIM(a6), sizeof * a6, cmp_long_long);

	int a7[] = { 12, 56, 90, 213, 266, 654 };
	q_sort(a7, DIM(a7), sizeof * a7, cmp_int);

	int a8[] = { 10, 20, 60, 80, 70, 50 };
	q_sort(a8, DIM(a8), sizeof * a8, cmp_int);

	int a9[] = { 12, 23, 34, 45, 45, 56, 67 };
	q_sort(a9, DIM(a9), sizeof * a9, cmp_int);

	int a10[10] = { 0 };
	q_sort(a10, DIM(a10), sizeof * a10, cmp_int);
	
}