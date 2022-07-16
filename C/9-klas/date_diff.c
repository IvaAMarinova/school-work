// returns diiference of two dates in days


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
struct date { unsigned day, month; int year; };

int date_diff(struct date d1, struct date d2)
{
	unsigned days1 = date2num(d1.year, d1.month, d1.day), days2 = date2num(d2.year, d2.month, d2.day), days_res = 0;
	if (days1 >= days2) days_res = days1 - days2;
	else days_res = days2 - days1;
	return days_res;
}

int date2num(int year, unsigned month, unsigned day)
{
	day += --year * 365 - 1 + days_in_month[month - 1];
	year += 2 < month;
	day += year / 4 - year / 100 + year / 400;

	return day;
}

void main(int argc, const char* const argv[])
{
	struct date d1 = { 1, 1, 1}, d2 = { 22, 6, 2006};
	date_diff(d1, d2);
}