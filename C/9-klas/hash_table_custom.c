// hash table for custom element given by user

struct hash_item
{
    struct hash_item* next;
};
typedef void* (*key_of)(struct hash_item* item);
typedef (*compare)(void* l, void* r);
typedef unsigned (*hash)(void* key, unsigned len);

struct hash_table
{
    unsigned table_len, elements;
    struct hash_item** list_heads;
    key_of key;
    compare cmp;
    hash hash;
};

void create(struct hash_table* t, key_of k, compare c, hash h)
{
    t->list_heads = calloc((t->table_len = 3), sizeof(struct hash_item*));
    t->elements = 0;
    t->key = k;
    t->cmp = c;
    t->hash = h;   
}

void insert(struct hash_table* t, struct hash_item* list)
{
    struct hash_item** a = &t->list_heads[t->hash(t->key(list), t->table_len)];
    list->next = *a;
    *a = list;
}

struct hash_item** find(struct hash_table* t, void* key)
{
    for (struct hash_item** p = t->list_heads + t->hash(key, t->table_len); *p; p = &(*p)->next) if (!(t->cmp(key, t->key(*p)))) return p;
    return 0;
}

void remove(struct hash_table* t, struct hash_item** found)
{
    struct hash_item** p = t->list_heads + t->hash(t->key(*found), t->table_len);
    while (*p)
    {
        if (p == found)
        {
            struct hash_item* pp = *p;
            *p = (*p)->next;
            realloc(pp, 0);
            t->elements--;
        }
        else p = &(*p)->next;
    }
}


// user given 

struct key_value
{
    struct hash_item list;
    char id[10];
    char name[];
};
void* key_of_name(struct hash_item* item)
{
    return ((struct key_value*)item)->name;
}
cmp_name(void* l, void* r)
{
    return strcmp((char*)l, (char*)r);
}
unsigned hash_name(void* key, unsigned len)
{
    char* s = (char*)key;
    unsigned res = 0;
    while (*s)
        res += *s++;
    return res % len;
}

void main()
{
    struct hash_table table;
    create(&table, key_of_name, cmp_name, hash_name);
    struct key_value* p = malloc(sizeof * p + sizeof "Iva Marinova");
    strcpy(p->name, "Iva Marinova");
    memcpy(p->id, "1234567890", 10);
    insert(&table, &p->list);
    struct hash_item** res = find(&table, "Iva Marinova");
    if (res)
    {
        ((struct key_value*)*res)->id;
        remove(&table, res);
    }
}