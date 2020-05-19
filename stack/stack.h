#include <stdbool.h>

typedef struct DynamicArrayStack
{
    int size;
    int top;
    int capacity;
    int *data;
} Stack;

// Create new stack
Stack *stack_new();

// Push data to the top of stack
void stack_push(Stack *, int);

// Pop data from the top of stack and return it
int stack_pop(Stack *);

// Peek data from top of stack
int stack_peek(Stack *);

// Check if stack is empty
bool stack_is_empty(Stack *);

// Check if stack is full
bool stack_is_full(Stack *);

// Get stack size
int stack_size(Stack *);

// Auto resize stack
void stack_resize(Stack *);

// Delete stack
void stack_destroy(Stack *);

// Print stack, size, capacity
void stack_print(Stack *);

// Print error message
void error(char[]);

// Check memory address
void check_address(void *);