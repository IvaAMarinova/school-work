// checks if point is in triangle

#include <math.h>
struct point
{
    double x, y;
};

struct triangle
{
    struct point a, b, c;
};

double distance(struct point a, struct point b)
{
    return sqrt(((b.x - a.x) * (b.x - a.x)) + ((b.y - a.y) * (b.y - a.y)));
}

double face(struct point a, struct point b, struct point c)
{
    double h = (distance(a, b) + distance(b, c) + distance(c, a)) / 2;
    return sqrt(h * (h - distance(a, b)) * (h - distance(b, c)) * (h - distance(c, a)));
}

int inside(struct triangle t, struct point p)
{
    return (face(t.a, t.b, p) + face(t.b, t.c, p) + face(t.a, t.c, p) - face(t.a, t.b, t.c)) <= 0.000000000000001;
}

void main()
{
    inside((struct triangle) { (struct point) { 0, 0 }, (struct point) { 10, 0 }, (struct point) { 10, 10 } }, (struct point) {20, 20}); // greshno
    inside((struct triangle) { (struct point) { 0, 0 }, (struct point) { 10, 0 }, (struct point) { 10, 10 } }, (struct point) { 9, 5 }); // vqrno

    inside((struct triangle) { (struct point) { 10, 10 }, (struct point) { 50, 0 }, (struct point) { 50, 80 } }, (struct point) { 100, 100 }); // greshno
    inside((struct triangle) { (struct point) { 10, 10 }, (struct point) { 50, 0 }, (struct point) { 50, 80 } }, (struct point) { 45, 20 }); // vqrno

    inside((struct triangle) { (struct point) { 0, 0 }, (struct point) { -10, 0 }, (struct point) { -10, -10 } }, (struct point) { -20, -20 }); // greshno
    inside((struct triangle) { (struct point) { 0, 0 }, (struct point) { -10, 0 }, (struct point) { -10, -10 } }, (struct point) { -9, -5 }); // vqrno

    // errors (as they should be)
    inside((struct triangle) { (struct point) { 0, 0 }, (struct point) { -10, 0 }, (struct point) { -10, -10 } }, (struct point) { 20, 20 });
    inside((struct triangle) { (struct point) { 0, 0 }, (struct point) { 10, 1 }, (struct point) { 5, 5 } }, (struct point) { 21, 20 });
    inside((struct triangle) { (struct point) { 1, 1 }, (struct point) { 1, 3 }, (struct point) { 3, 3 } }, (struct point) { 22, 6 });
}