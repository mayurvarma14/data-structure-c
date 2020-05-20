#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

Stack *stack_new()
{
    Stack *s = malloc(sizeof(Stack));
    check_address(s);
    s->size = 0;
    s->capacity = 1;
    s->top = -1;
    s->data = (int *)malloc(sizeof(int) * s->capacity);
    check_address(s->data);
    return s;
}

void stack_push(Stack *s, int value)
{
    stack_resize(s);
    *(s->data + s->top + 1) = value;
    s->top++;
    s->size++;
}

int stack_pop(Stack *s)
{
    if (stack_is_empty(s))
    {
        error("Stack is empty cannot pop item from stack");
    }
    int value = *(s->data + s->top);
    s->top--;
    s->size--;
    stack_resize(s);
    return value;
}

int stack_peek(Stack *s)
{
    if (stack_is_empty(s))
    {
        error("Stack is empty cannot peek at top");
    }
    return *(s->data + s->top);
}

bool stack_is_empty(Stack *s)
{
    return stack_size(s) == 0;
}

bool stack_is_full(Stack *s)
{
    return stack_size(s) == s->capacity;
}

int stack_size(Stack *s)
{
    return s->size;
}

void stack_resize(Stack *s)
{
    // Double stack capacity if full
    if (stack_is_full(s))
    {
        s->capacity *= 2;
        s->data = (int *)realloc(s->data, sizeof(int) * s->capacity);
    }
    // Shrink by half if stack size is 1/4 of capacity
    else if (stack_size(s) < s->capacity / 4)
    {
        s->capacity /= 2;
        s->data = (int *)realloc(s->data, sizeof(int) * s->capacity);
    }
}

void stack_destroy(Stack *s)
{
    free(s->data);
    free(s);
}

void stack_print(Stack *s)
{
    int size = stack_size(s);
    printf("\nSize:%d\n", size);
    printf("Capacity:%d\n", s->capacity);
    printf("Stack data:\n");
    for (int i = 0; i < size; i++)
    {
        printf("Index:%d   Value:%d\n", i, *(s->data + i));
    }
    printf("==========================\n\n");
}

void error(char msg[])
{
    printf("%s\n", msg);
    exit(EXIT_FAILURE);
}

void check_address(void *address)
{
    if (!address)
    {
        error("Unable to allocate memory");
    }
}