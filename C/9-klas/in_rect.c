// checks if point is in rectangle

#include <stdio.h>

struct point
{
	int x, y;
};

struct rectangle
{
	struct point start, end;
};

in_rect(struct rectangle r, struct point p)
{
	return (r.start.x < p.x && r.start.y < p.y && r.end.x > p.x && r.end.y > p.y);
}

void main()
{
	struct point p = { 8, 9 };
	struct rectangle r = { {5, 5}, {10, 11} };

	in_rect(r, p);
}
