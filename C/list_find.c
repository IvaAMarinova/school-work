// finds element in list using key

#include <malloc.h>

struct list
{
    int key, value;
    struct list* next;
};

enum bool{ false, true };

enum bool find_key(struct list* l, int k, int* v)
{
    while (true)
    { 
        if (l->key == k)
        {
            *v = l->value;
            return true;
        }
        if (l->next == 0) return false;

        l = l->next;
    }
}

void main()
{
    struct list a = { 1, 10, 0 }, b = { 2, 20, &a }, c = { 3, 30, &b };
    int key = 4, value = 0;
 
    find_key(&c, key, &value);
}
