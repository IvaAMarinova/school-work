// calculates perimeter of given polygon

#include <math.h>
struct point
{
    double x, y;
};

double distance(struct point a, struct point b)
{
    return sqrt(((b.x - a.x) * (b.x - a.x)) + ((b.y - a.y) * (b.y - a.y)));
}

double perimeter(struct point* poly, unsigned cnt)
{
    double face = distance(poly[0], poly[cnt - 1]);

    for (unsigned i = 0; i < cnt - 1; i++) face += distance(poly[i], poly[i+1]);

    return face;
}

int main()
{
    struct point poly[] =
    {
            { 0,0 },
            { 0,1 },
            { 1,1 },
            { 1,0 },
    };

    struct point poly2[] =
    {
            { 0,0 },
            { 0,10 },
            { 10,10 },
            { 10,0 },
    };

    struct point poly6[] =
    {
            { 0,0 },
            { 0,10 },
            { 10,10 },
            { 10,15 },
            { 0,15 },
    };

    perimeter(poly, 4);
    perimeter(poly2, 4);
    perimeter(poly6, 5);
}

