#include <stdio.h>
#include "stack.c"

int main()
{
    Stack *s = stack_new();
    int upper = 100, lower = 1, num, totalNumbers = 10;
    for (int i = 0; i < totalNumbers; i++)
    {
        num = (rand() % (upper - lower + 1)) + lower;
        stack_push(s, num);
    }
    stack_print(s);
    printf("Peek:%d\n", stack_peek(s));
    printf("Push 54\n");
    stack_push(s, 54);
    printf("Stack size:%d\n", stack_size(s));
    for (int i = 0; i < 8; i++)
    {
        printf("Pop:%d\n", stack_pop(s));
    }
    printf("Peek:%d\n", stack_peek(s));
    stack_print(s);
    return 0;
}