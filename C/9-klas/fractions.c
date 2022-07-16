// Initializes fractions (regular and with floating point)
// performs mathematical functions with them and returns answer

struct fraction {
    enum { regular_fraction, floating_point } type;
    union {
        struct {
            int nom, denom;
        };
        double d;
    };
} p;

struct fraction init_double(double d)
{
    return (struct fraction) { floating_point, { .d = d } };
}

struct fraction init_regular(int nom, int denom)
{
    return (struct fraction) { regular_fraction, { .nom = nom, .denom = denom } };
}

struct fraction add(struct fraction a, struct fraction b)
{
    if (a.type != b.type) {
        struct fraction* pb = &b, * pa = &a;
        if (a.type & !(b.type)) reg_to_float(pb);
        else reg_to_float(pa);
    }
    if (a.type == floating_point) return (struct fraction) { floating_point, .d = a.d + b.d }; 
    int Nod = nod(a.nom * b.denom + b.nom * a.denom, a.denom * b.denom);
    return (struct fraction) { regular_fraction, { .nom = (a.nom * b.denom + b.nom * a.denom) / Nod, .denom = (a.denom * b.denom) / Nod } };
}

struct fraction mul(struct fraction a, struct fraction b)
{
    if (a.type != b.type) {
        struct fraction* pb = &b, * pa = &a;
        if (a.type & !(b.type)) reg_to_float(pb);
        else reg_to_float(pa);
    }
    
    if (a.type == floating_point) return (struct fraction) { floating_point, .d = a.d * b.d };
    int Nod = nod(a.nom * b.denom + b.nom * a.denom, a.denom * b.denom);
    return (struct fraction) { regular_fraction, { .nom = (a.nom  + b.nom) / Nod, .denom = a.denom * b.denom / Nod } };
}

int nod(int a, int b)
{
    a = (a > 0) ? a : -a;
    b = (b > 0) ? b : -b;

    while (a != b) {
        if (a > b) a -= b;
        else b -= a;
    }
    return a;
}

reg_to_float(struct fraction* p)
{
    p->d = (double)p->nom / (double)p->denom;
    p->type = floating_point;
}

void main()
{ 
    double a = 3.14;
    init_double(a);

    int b = 3, c = 14;
    init_regular(b, c);
  
    double d = -2.2, e1 = 300, e2 = 16;
    add(init_double(d), init_regular(e1, e2)); // 16.55
    
    double f = 1.1, g = 2.2;
    add(init_double(f), init_double(g)); // 3.3

    double h = 0.6;
    int i1 = 5, i2 = 6;
    add(init_double(h), init_regular(i1, i2)); // 1.4

    int j1 = 3, j2 = 7, k1 = 1, k2 = 9;
    add(init_regular(j1, j2), init_regular(k1, k2)); // 34 / 63
   
    double l = 1.1, m1 = 300, m2 = 16;
    mul(init_double(l), init_regular(m1, m2)); // 20.6

    double n = 2.2, o = 2.2;
    mul(init_double(n), init_double(o)); // 4.84

    int p1 = 1, p2 = 1, q1 = 3, q2 = 63;
    mul(init_regular(p1, p2), init_regular(q1, q2)); // 1 / 21
}