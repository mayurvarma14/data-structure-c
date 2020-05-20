#include <stdio.h>
#include "queue.c"

int main()
{
    Queue *q = queue_new();
    int upper = 100, lower = 1, num, totalNumbers = 16;
    for (int i = 0; i < totalNumbers; i++)
    {
        num = (rand() % (upper - lower + 1)) + lower;
        queue_enqueue(q, i + 1);
    }
    queue_print(q);
    for (int i = 0; i < 12; i++)
    {
        printf("Dequeue:%d\n", queue_dequeue(q));
    }
    queue_print(q);
    queue_enqueue(q, 101);
    queue_enqueue(q, 102);
    queue_print(q);
    for (int i = 0; i < 3; i++)
    {
        printf("Dequeue:%d\n", queue_dequeue(q));
    }
    queue_print(q);
    queue_destroy(q);
    return 0;
}