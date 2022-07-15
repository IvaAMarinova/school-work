// returns the average of given numbers
// implementation of stdarg.h

#include <stdarg.h>
double avg_va(unsigned cnt, ...)
{
    va_list list;
    va_start(list, cnt);
    double sum = 0;
 
    for (int i = 0; i < cnt; i++) {
        sum += va_arg(list, double);
    }
    va_end(list); 

    return sum / cnt;
}

void main()
{
    avg_va(3, 3., 1., 2.);
    avg_va(5, 1., 1., 2., 3., 3., 2.);
    avg_va(3, 5.5, 8.3, -2e2);
}
