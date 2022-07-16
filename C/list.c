// dynamic single linked list

#include <malloc.h>

struct stack
{
    int data;
    struct stack* next;
};

enum bool{ false, true };

enum bool create(struct stack** stack)
{
    struct stack* a = realloc(0, sizeof **stack);
    *stack = a;
    (*stack)->data = 0;
    (*stack)->next = 0;
    return a ? true : false;
}

enum bool push(struct stack **a, int elem)
{
    (*a)->data = elem;
    struct stack* b;
    create(&b);
    b->next = *a;
    *a = b;
    return b ? true : false;
}

enum bool pop(struct stack** stack, int* elem)
{
    if ((*stack)->next)
    {
        *stack = (*stack)->next;
        *elem = (*stack)->data;
        return true;
    }
    return false;
}

void destroy(struct stack** a)
{
    *a = realloc(*a, 0);
}

void main()
{
    int out;
    struct stack* top;
    create(&top);

    push(&top, 30);
    push(&top, 20);
    push(&top, 10);

    pop(&top, &out);
    pop(&top, &out);
    pop(&top, &out);
    pop(&top, &out);

    destroy(&top);
}