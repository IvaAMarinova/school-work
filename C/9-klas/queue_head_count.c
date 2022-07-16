// classic stack with head and count

enum { max_queue = 100 };

struct queue
{
    unsigned head, count;
    int array[max_queue];
};
enum bool{ false, true };

enum bool create(struct queue* q)
{
    for (unsigned i = 0; i < max_queue; i++) q->array[i] = 0;
    q->head = 1;
    q->count = 0;
    return q ? true : false;
}

enum bool enqueue(struct queue* q, int elem)
{
    if (q->count == max_queue) return false;
    q->array[q->head - 1] = elem;
    if (q->head == max_queue) q->head = 0;
    q->head++;
    q->count++;

    return true;
}

enum bool dequeue(struct queue* q, int* elem)
{
    if (!q->count) return false;
    int t = (q->head - 1) - q->count;
    if (t < 0) t = (t + max_queue) % max_queue;
    *elem = q->array[t];
    if (t == max_queue - 1) q->count = q->head - 1;
    else q->count--;
    return true;
}

void destroy(struct queue* q)
{
    unsigned i = max_queue;
    while (i--) q->array[i] = 0;
    q->head = 0;
    q->count = 0;
}

void main()
{
    struct queue q;
    int element = 0;

    create(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);

    dequeue(&q, &element);
    dequeue(&q, &element);
    dequeue(&q, &element);
    dequeue(&q, &element); 

    destroy(&q);
}