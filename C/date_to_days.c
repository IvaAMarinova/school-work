// turns date to sum of days

#include <stdio.h>

const int days_in_month[12] = { 
	0,
	31,
	31 + 28,
	31 + 28 + 31,
	31 + 28 + 31 + 30,
	31 + 28 + 31 + 30 + 31,
	31 + 28 + 31 + 30 + 31 + 30,
	31 + 28 + 31 + 30 + 31 + 30 + 31,
	31 + 28 + 31 + 30 + 31 + 30 + 31 + 31,
	31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30,
	31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31,
	31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30
};
	
int date2num(int year, unsigned month, unsigned day)
{
	day += --year * 365 - 1 + days_in_month[month - 1];
	year += 2 < month;
	day += year / 4 - year / 100 + year / 400;
	
	return day;
}

void main() {
	date2num(1, 12, 31);
	date2num(4, 3, 1);
	date2num(4, 2, 28);
	date2num(1, 1, 2);
	date2num(11, 1, 1);
}