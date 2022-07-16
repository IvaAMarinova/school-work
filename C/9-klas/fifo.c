// implementation of tail (FIFO - First In First Out)

#include <malloc.h>
enum bool{ false, true, no = false, yes = true };
struct q
{
    struct q_item* head, * tail;
};

struct q_item
{
    struct q_item* next;
    int data;
};

void create(struct q* q)
{
    q->head = 0;
    q->tail = 0;
}

enum bool enqueue(struct q* q, int data)
{
    struct q_item* a = realloc(0, sizeof * a);

    a->data = data;
    a->next = 0;
    if (!q->tail) q->tail = a;
    if (q->head) q->head->next = a;
    q->head = a;
    if (q->head) return true;
    else return false;
}

enum bool dequeue(struct q* q, int* data)
{
    if (!q->tail) return false;
    *data = q->tail->data;
    struct q_item* a;
    a = q->tail;
    q->tail = q->tail->next;
    a = realloc(a, 0);
    return true;
}

void destroy(struct q* q)
{
    int a = 0;
    while (dequeue(q, &a));
}

int main()
{
    struct q q;
    int a = 0;

    create(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    dequeue(&q, &a);
    dequeue(&q, &a);
    dequeue(&q, &a);
    
    destroy(&q);
}