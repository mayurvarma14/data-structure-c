// Dynamic circular array implementation of queue
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

Queue *queue_new()
{
    Queue *q = malloc(sizeof(Queue));
    check_address(q);
    q->size = 0;
    q->capacity = 1;
    q->front = -1;
    q->rear = -1;
    q->data = (Node **)malloc(sizeof(Node *) * q->capacity);
    check_address(q->data);
    return q;
}

void queue_enqueue(Queue *q, Node *value)
{
    queue_resize(q);
    // Increase rear value by 1
    q->rear = (q->rear + 1) % q->capacity;
    if (queue_is_empty(q))
        q->front++;

    q->size++;
    *(q->data + q->rear) = value;
}

Node *queue_dequeue(Queue *q)
{
    // Check if queue if empty
    if (queue_is_empty(q))
    {
        error("Queue is empty cannot dequeue item");
    }
    // Get value to remove from queue
    Node *value = *(q->data + q->front);
    // Calculate new front value by increasing front by 1
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % q->capacity;
    }
    q->size--;
    queue_resize(q);
    return value;
}

int queue_size(Queue *q)
{
    return q->size;
}

bool queue_is_empty(Queue *q)
{
    return queue_size(q) == 0;
}

bool queue_is_full(Queue *q)
{
    return queue_size(q) == q->capacity;
}

void queue_resize(Queue *q)
{
    int size = queue_size(q);
    // Check if queue if full
    if (queue_is_full(q))
    {
        // Double the array capacity
        q->capacity *= 2;
        q->data = (Node **)realloc(q->data, sizeof(Node *) * q->capacity);
        // If there are items before front in array then shift them right
        if (q->rear < q->front)
        {
            for (int i = 0; i <= q->rear; i++)
            {
                *(q->data + (q->capacity / 2) + i) = *(q->data + i);
            }
            q->rear = (q->capacity / 2) + q->rear;
        }
    }
    // Shrink by half if queue size is 1/4 of capacity
    else if (size < q->capacity / 4)
    {
        // If items do not start from index 0 then
        // shift items to start from index 0 of array
        if (q->front != 0)
        {
            // If rear is present in 1/4 of array then
            // shift from backward else shift from front
            if (q->rear < q->capacity / 4)
            {
                for (int i = size - 1; i >= 0; i--)
                {
                    *(q->data + i) = *(q->data + q->rear);
                    q->rear = (--q->rear + q->capacity) % q->capacity;
                }
            }
            else
            {
                for (int i = 0; i < size; i++)
                {
                    *(q->data + i) = *(q->data + q->front + i);
                }
            }
            q->front = 0;
            q->rear = size - 1;
        }

        q->capacity /= 2;
        q->data = (Node **)realloc(q->data, sizeof(Node *) * q->capacity);
    }
}

void queue_destroy(Queue *q)
{
    free(q->data);
    free(q);
}

void queue_print(Queue *q)
{
    int size = queue_size(q);
    printf("\nSize:%d\n", size);
    printf("Capacity:%d\n", q->capacity);
    printf("Front:%d\n", q->front);
    printf("Rear:%d\n", q->rear);
    printf("Queue data:\n");
    if (!queue_is_empty(q))
    {

        for (int i = q->front; i != q->rear; i = (i + 1) % q->capacity)
        {
            printf("Index:%d   Value:%d\n", i, (*(q->data + i))->data);
        }
        printf("Index:%d   Value:%d\n", q->rear, (*(q->data + q->rear))->data);
        // for (int i = q->front; i != q->rear + 1; i = (i + 1) % q->capacity)
        // {
        //     printf("Value:%d\n", *(q->data + i));
        // }
    }
    printf("==========================\n\n");
}
