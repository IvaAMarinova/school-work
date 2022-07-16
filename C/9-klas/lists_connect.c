// connects two lists

struct list
{
    int value;
    struct list* next;
};

struct list* list_cat(struct list* a, struct list* b)
{
    
    if (!a) return b;

    if (!b) return a;

    struct list* ap = a;
    while (a->next) a = a->next;
    a->next = b;

    return ap;
}

void main()
{
    struct list a1 = { 3, 0 }, a2 = { 2, &a1 }, a3 = { 1, &a2 };
    struct list b1 = { 6, 0 }, b2 = { 5, &b1 }, b3 = { 4, &b2 };

    list_cat(&a3, &b3); // a3 holds answer

    struct list c1 = { 3, 0 }, c2 = { 2, &c1 }, c3 = { 1, &c2 };

    list_cat(&c3, 0); // c3 holds answer

    struct list d1 = { 3, 0 }, d2 = { 2, &d1 }, d3 = { 1, &d2 };

    list_cat(0, &d3); // d3 holds answer

}