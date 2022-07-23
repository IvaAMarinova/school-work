// turns a number with floating point to different numeral system

#include <stdio.h>

int to_fixed(double x) {
    return x * (1 << 16);
}

double from_fixed(int x) {
    return (double)x / (1 << 16);
}

int fixed_to_int(int fixed) {
    return fixed >> 16;
}

int fixed_frac(int fixed) {
    if (fixed < 0) {
        return fixed | ~0 << 16;
    }
    else {
        return fixed & ((1 << 16) - 1);
    }
}

void print_part(int x, int radix) {
    int rem;
    int i, j = 0;
    char tmp[32];

    while (x) {
        rem = x % radix;
        if (rem < 10) {
            tmp[j] = 48 + rem;
        }
        else {
            tmp[j] = 65 + (rem - 10);
        }
        j++;
        x = x / radix;
    }

    for (i = j - 1; i >= 0; i--) {
        printf("%c", tmp[i]);
    }
}

void print_fixed(int fixed, unsigned char radix) 
{
    print_part(fixed_to_int(fixed), radix);
    printf(".");
    print_part((from_fixed(fixed_frac(fixed)) * 1000000), radix);
    printf("\n");
}

void main() {
    double a = 3.14;

    print_fixed(to_fixed(3.14), 10);
    print_fixed(to_fixed(3.14), 2);
    print_fixed(to_fixed(3.14), 16);
    print_fixed(to_fixed(3.14), 3);
}