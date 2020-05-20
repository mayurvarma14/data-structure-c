#include <stdbool.h>

typedef struct DynamicArrayQueue
{
    int front;
    int rear;
    int size;
    int capacity;
    int *data;
} Queue;

// Create new queue
Queue *queue_new();

// Insert item in queue
void queue_enqueue(Queue *, int);

// Delete and return item from queue
int queue_dequeue(Queue *);

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

// Print error message
void error(char[]);

// Check memory address
void check_address(void *);