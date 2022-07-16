// classical hash table
// can rehash itself

#include <stdlib.h>
#include <malloc.h>
#include <math.h>

struct hash_item
{
    unsigned key, data;
    struct hash_item* next;
};
struct hash_table
{
    unsigned table_len, elements;
    struct hash_item** list_heads;
};

enum bool{ false, true };

unsigned hash(unsigned key, unsigned l)
{
    return key % l;
}

void __insert(struct hash_table* t, unsigned key, unsigned data)
{
    struct hash_item* new = malloc(sizeof * new);
    struct hash_item** p = t->list_heads + hash(key, t->table_len);
    *new = (struct hash_item){ .key = key, .data = data, .next = *p };
    *p = new;
    return true;
}

void rehash(struct hash_table* t)
{
    unsigned for_larger = t->elements > t->table_len, for_smaller = t->elements < t->table_len / 4;
    if ( for_larger || for_smaller)
    {
        unsigned length = for_larger ? t->table_len * 2 : t->table_len / 4;
        struct hash_table new = { .table_len = length, .elements = t->elements, .list_heads = calloc(length, sizeof(struct hash_item*)) };
        for (unsigned i = 0; i < t->table_len; i++)
        {
            struct hash_item* p;
            for (p = t->list_heads[i]; p; p = p->next)
            {
                __insert(&new, p->key, p->data);
            }
        }
        t->table_len = new.table_len;
        t->list_heads = new.list_heads;
    }
}

void create(struct hash_table *t) 
{
    t->list_heads = calloc((t->table_len = 3), sizeof(struct hash_item*));
    t->elements = 0;
}

void insert(struct hash_table* t, unsigned key, unsigned data)
{
    rehash(t);
    struct hash_item* new = malloc(sizeof * new);
    struct hash_item** p = t->list_heads + hash(key, t->table_len);
    *new = (struct hash_item){ .key = key, .data = data, .next = *p };
    *p = new;
    t->elements++;
}

struct hash_item** find(struct hash_table* t, unsigned key)
{
    struct hash_item** p = t->list_heads + hash(key, t->table_len);
    for (; *p; p = &(*p)->next) if ((*p)->key == key) return p;
    return p;
}

unsigned value_of(struct hash_item** found)
{
    return (*found)->data;
}

struct hash_item** find_next(struct hash_item** found)
{
    struct hash_item** p = &(*found)->next;
    unsigned key = (*found)->next->key;
    for (; *p; p = &(*p)->next) if ((*p)->key == key) return p;
}

void remove(struct hash_table* t, struct hash_item** found)
{
    struct hash_item* dest = *found;
    *found = (*found)->next;
    realloc(dest, 0);
    t->elements--;
    rehash(t);
}

#define MIN (a) < (b) ? a : b

unsigned prime_near(unsigned n)
{
    unsigned a = n / 6 * 6;
}

void main()
{
    prime_near(35);

    int a = 26;
    a = a / 6;
    a = a * 6;
    struct hash_table t;
    create(&t);
    insert(&t, 1, 10);
    insert(&t, 2, 20);
    insert(&t, 3, 30);
    insert(&t, 4, 40);
    rehash(&t);
    remove(&t, find(&t, 3));
    
    insert(&t, 9, 90);
    insert(&t, 9, 80);
    insert(&t, 9, 70);
    find_next(find(&t, 9));
    value_of(find(&t, 9));
}