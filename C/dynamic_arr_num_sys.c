// prints stack with numbers
// numbers were turned from dec to given numeral system

#include <malloc.h>
#include <stdio.h>

struct stack
{
    unsigned length;
    int array[];
};

enum bool{ false, true, no = false, yes = true };

enum bool create(struct stack **stack)
{
    struct stack* a = realloc(0, sizeof ** stack);
    a->length = 0;
    *stack = a;
    return a ? true : false;
}

enum bool push(struct stack** a, int elem)
{
    *a = realloc(*a, sizeof **a + sizeof(*a)->array[0] * ++(*a)->length);
    if (*a) {
        (*a)->array[(*a)->length - 1] = elem;
        return true;
    }
    return false;
}

enum bool pop(struct stack** stack, int* elem)
{
    *elem = (*stack)->array[(*stack)->length - 1];
    if (*stack) {
        *stack = realloc(*stack, sizeof * *stack + sizeof(*stack)->array[0] * --(*stack)->length);
        printf("%c", *elem);
        return true;
    }
    return false;
}

void destroy(struct stack* a)
{
    a = realloc(a, 0);
}

void print_radix(struct stack** a, unsigned n, unsigned radix)
{
    create(&a);
    int remainder, element = 0;

    while (n != 0)
    {
        remainder = n % radix;
        if (remainder < 10)
            push(&a, 48 + remainder);
        else
            push(&a, 55 + remainder);
        pop(&a, &element);
        n = n / radix;
    } 
    destroy(a);
}

void main()
{
    struct stack* a;
   
    print_radix(&a, 10, 16); // A
    printf("\n");
    print_radix(&a, 1012, 16); // 4F3
    printf("\n");
    print_radix(&a, 999, 2); // 1110011111
    printf("\n");
    print_radix(&a, 10, 10); // 10
    printf("\n");
}

