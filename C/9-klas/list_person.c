// creates list which elements represent people


#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <malloc.h>

struct id
{
    unsigned char value[10];
    struct id* next;
    char key[];
};

void create(struct id** list)
{
    *list = 0;
}

enum bool{ false, true } add(struct id** list, const char* key, const unsigned char value[10])
{
    struct id* new = malloc(sizeof * new + strlen(key) + 1);
    if (!new)
        return false;
    memcpy(new->value, value, sizeof new->value);
    strcpy(new->key, key);
    new->next = *list;
    *list = new;
    return true;
}
enum bool find(struct id** list, const char* key, unsigned char value[10])
{
    struct id* p = *list;
    while (p)
    {
        if (!strcmp(p->key, key))
        {
            memcpy(value, p->value, 10);
            return true;
        }
        p = p->next;
    }
    return false;
}
enum bool remove(struct id** list, const char* key)
{
    struct id* p = *list;
    struct id* pointer_last = *list;
    while (p)
    {
        int res = strcmp(p->key, key);
        
        if (!res)
        {
            if (p == pointer_last)
            {
                struct id* pointer_current = p;
                *list = (*list)->next;
                pointer_current = realloc(pointer_current, 0);
                return true;
            }
            struct id* pointer_current = p;
            pointer_last->next = p->next;
            pointer_current = realloc(pointer_current, 0);
            return true;
        }
        pointer_last = p;
        p = p->next;
    }
    return false;
}

void main()
{
    struct id* control;
    char res[10];

    create(&control);

    add(&control, "Karina", "1111111111");
    add(&control, "Iva", "2222222222");
    add(&control, "Sashka", "3333333333");
    add(&control, "Kolyo", "4444444444");
    add(&control, "Tomi", "5555555555");
    
    remove(&control, "Tomi");
    
    find(&control, "Karina", res);

    remove(&control, "Iva");
}