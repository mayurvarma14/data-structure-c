#include <stdbool.h>
typedef struct DynamicArray
{
    int size;
    int capacity;
    int *data;
} Array;

// Create new array
Array *array_new();

// Check memory address
void check_address(void *);

// Append element at end
void array_push(Array *, int);

// Get length of array
int array_size(Array *);

// Get capacity of array
int array_capacity(Array *);

// Check if array is empty
bool array_is_empty(Array *);

// Check if array is full
bool array_is_full(Array *);

// Get element at given index
int array_at(Array *, int);

// Insert element at given index
void array_insert(Array *, int, int);

// Insert at beginning of array
void array_prepend(Array *, int);

// Delete and return the last element in array
int array_pop(Array *);

// Delete element at given index
void array_delete(Array *, int);

// Delete all matching elements with the given value
void array_remove(Array *, int);

// Find given value and return first index
// with that value else return -1 if not found
int array_find(Array *, int);

// Resize to double when array is full, if size is 1/4
// while deleting element resize to half
void array_resize(Array *);

// Delete array
void array_destroy(Array *);

// Print array, size, capacity
void array_print(Array *);

// Print error message
void error(char[]);