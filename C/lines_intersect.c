// checks if two lines intersect each other

struct point
{
    double x, y;
};
struct segment
{
    struct point a, b;
};

enum bool{ false, true };

int orientation(struct point a, struct point b, struct point c)
{
    int res = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - c.x);
    return (res == 0) ? 0 : (res > 0) ? 1 : 2;
}

enum bool intersection(struct segment p, struct segment q, struct point* result)
{
    int d1 = orientation(p.a, q.a, p.b), d2 = orientation(p.a, q.a, q.b), d3 = orientation(p.b, q.b, p.a), d4 = orientation(p.b, q.b, q.a);

    if (d1 != d2 && d3 != d4) {
        if (orientation(p.a, p.b, q.a) != orientation(p.a, p.b, q.b) && orientation(q.a, q.b, p.a) != orientation(q.a, q.b, p.b))
        {
            double A1 = p.b.y - p.a.y, B1 = p.a.x - p.b.x, C1 = A1 * p.a.x + B1 * p.a.y;
            double A2 = q.b.y - q.a.y, B2 = q.a.x - q.b.x, C2 = A2 * q.a.x + B2 * q.a.y;

            double det = A1 * B2 - A2 * B1;
            result->x = (B2 * C1 - B1 * C2) / det;
            result->y = (A1 * C2 - A2 * C1) / det;
        }
        return true;
    }
    return false;
}

int main()
{
    struct point result;

    intersection((struct segment) { (struct point) { 1, 0 }, (struct point) { 0, 1 } }, 
        (struct segment) { (struct point) { 0, 0 }, (struct point) { 1, 1 } }, &result); // yes

    intersection((struct segment) { (struct point) { 1, 1 }, (struct point) { 0, 0 } }, 
        (struct segment) { (struct point) { 5, 5 }, (struct point) { 20, 20 } }, &result); // no
}