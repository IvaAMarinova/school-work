// implementation of ring
// + function remove_duplicates()

#include <malloc.h>

enum bool{ false, true, no = false, yes = true };
struct ring
{
    struct ring* next;
    int key, value;
};

void create(struct ring* control)
{
    control->key = 0;
    control->next = control;
    control->value = 0;
}
enum bool add(struct ring* control, int key, int value)
{
    struct ring* a = realloc(0, sizeof * a);
    a->key = key;
    a->value = value;
    a->next = control->next;
    control->next = a;
    return a ? true : false;
}

enum bool find(struct ring* control, int key, int* res)
{
    struct ring* pc = control->next;

    while (pc != control)
    {
        if (pc->key == key) {
            *res = pc->value;
            return true;
        }
        pc = pc->next;
    }
    return false;
}

void remove_duplicates(struct ring* r)
{
    struct ring* help = r->next;
    for (r = r->next; r->next != help; r = r->next) {
        struct ring* r1 = r->next;
        struct ring* pr1 = r;
        for (; r1 != help; r1 = r1->next)
        {
            if (r1->key == r->key) pr1->next = r1->next;
            else pr1 = pr1->next;
        }
    }
}

void destroy(struct ring* control)
{
    struct ring* stop = control;
    control = control->next;
    while (control != stop)
    {
        struct ring* help = control;
        control = control->next;
        help = realloc(help, 0);
    }
}

void main()
{
    struct ring control;
    create(&control);
    add(&control, 1, 2);
    add(&control, 5, 1);
    add(&control, 3, 10);
    add(&control, 5, 11);
    add(&control, 5, 12);
    add(&control, 8, 14);
    add(&control, 8, 15);
    add(&control, 8, 16);
    add(&control, 9, 18);
    remove_duplicates(&control);

    destroy(&control);
}