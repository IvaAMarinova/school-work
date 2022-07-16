// x ^ answer = y

#include <stdio.h>

unsigned log(unsigned x, unsigned y)
{
    unsigned power = 1, x1 = x;

    for (;;)
    {
        if (x1 == y)
        {
            return power;
        }
        else if (x1 > y)
        {
            return power - log(x, x1 / y);
        }
        power = power * 2;
        x1 = x1 * x1;
    }

}

void main()
{
    log(3, 243); // 3 ^ answer = 243
    log(3, 81);
    log(3, 729);
    log(2, 64);
}

