#include <stdbool.h>
#include "binary_search_tree.h"

typedef struct DynamicArrayQueue
{
    int front;
    int rear;
    int size;
    int capacity;
    Node **data;
} Queue;

// Create new queue
Queue *queue_new();

// Insert item in queue
void queue_enqueue(Queue *, Node *);

// Delete and return item from queue
Node *queue_dequeue(Queue *);

// Get queue size
int queue_size(Queue *);

// Check if queue is empty
bool queue_is_empty(Queue *);

// Check if queue is full
bool queue_is_full(Queue *);

// Auto resize queue
void queue_resize(Queue *);

// Delete queue
void queue_destroy(Queue *);

// Print queue, size, capacity front, rear
void queue_print(Queue *);
