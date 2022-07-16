// finds number which needs to be converted in strings
// converts to any given numeral system 
// implements stdarg.h

#include <stdio.h>
#include <stdarg.h>

void convert(unsigned source, unsigned n) {
	unsigned hex = 0;
	if (!source) return;
	else {
		hex = source % n;
		convert(source / n, n);
	}
	if (hex > 9) printf("%c", 'A' + (hex - 10));
	else printf("%d", hex);
}

unsigned char_to_unsigned(char* s)
{
	unsigned digit = 0;
	while (*s && *s >= '0' && *s <= '9') {
		digit = digit * 10 + (*s - '0');
		s++;
	}
	return digit; 
}

void print_f(const char* fmt, ...)
{
	va_list list;
	va_start(list, fmt);
	unsigned n = 0;

	while (*fmt)
	{
		if (*fmt != '%') printf("%c", *fmt);
		else {
			fmt++;
			convert(va_arg(list, unsigned), char_to_unsigned(fmt));
			fmt++;
			if (*fmt == ' ' || *fmt == ',')
				printf("%c", *fmt);
		}
		fmt++; 
	} 
	printf("\n");
	va_end(list);	
}

void main()
{
	print_f("number 10 in 7 = %7, number 10 in 8 = %8", 10, 10); // number 10 in 7 = 13, number 10 in 8 = 12 //
	print_f("number 34 in 10 = %10, number 10 in 16 = %16", 34, 10); // number 34 in 10 = 34, number 10 in 16 = A	
	print_f("number 5 in 2 = %2, number 44 in 20 = %20, number 4 in 3 = %3", 5, 44, 4); // number 5 in 2 = 101, number 44 in 20 = 24, number 4 in 3 = 11
	
}