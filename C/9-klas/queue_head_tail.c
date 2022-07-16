// classic stack with head and tail

enum { max_queue = 100 };

struct queue
{
    unsigned head, tail;
    int array[max_queue];
};
enum bool{ false, true};

enum bool create(struct queue* q)
{
    for (unsigned i = 0; i < max_queue; i++) {
        q->array[i] = 0;
    }
    q->head = 1;
    q->tail = 0;

    return q ? true : false;
}

enum bool enqueue(struct queue* q, int elem)
{
    if(q->tail == q->head || q->head == max_queue && q->tail == 0) return false;
    q->array[q->head - 1] = elem;
    if (q->head == max_queue) q->head = 0;
    q->head++;
    
    return true;
}

enum bool dequeue(struct queue* q, int* elem)
{
    if (q->tail == q->head - 1 || q->head == 1 && q->tail == max_queue - 1) return false;
    *elem = q->array[q->tail];
    if (q->tail == max_queue - 1) q->tail = 0;
    else q->tail++;
    return true;
}

void destroy(struct queue* q)
{
    unsigned i = max_queue;
    while (i--)
    {
        q->array[i] = 0;
    }
    q->head = 0;
    q->tail = 0;
}

void main()
{
    struct queue q;
    int element = 0;

    create(&q);

    enqueue(&q, 1); // true
    enqueue(&q, 2); // true
    enqueue(&q, 3); // true
    enqueue(&q, 4); // true

    dequeue(&q, &element); // 1
    dequeue(&q, &element); // 2
    dequeue(&q, &element); // 3
    dequeue(&q, &element); // 4

    destroy(&q);
}