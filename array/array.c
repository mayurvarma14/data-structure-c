// Dynamic array implementation

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

Array *array_new()
{
    Array *a = malloc(sizeof(Array));
    check_address(a);
    a->capacity = 1;
    a->size = 0;
    a->data = (int *)malloc(a->capacity * sizeof(int));
    check_address(a->data);
    return a;
}

void array_push(Array *a, int element)
{
    array_resize(a);
    *(a->data + a->size) = element;
    a->size++;
}

int array_size(Array *a)
{
    return a->size;
}

int array_capacity(Array *a)
{
    return a->capacity;
}

bool array_is_empty(Array *a)
{
    return array_size(a) == 0;
}

bool array_is_full(Array *a)
{
    return array_size(a) == array_capacity(a);
}

int array_at(Array *a, int index)
{
    return *(a->data + index);
}

void array_insert(Array *a, int index, int value)
{
    // Get current array size
    int size = array_size(a);
    if (index >= array_size(a) || index < 0)
    {
        error("Array index out of bound");
    }
    // Shift last element only and increase size+1
    // This will resize array when array is full
    // as there is no space to shift elements
    array_push(a, *(a->data + size - 1));
    // Shift remaining elements till index to right
    for (int i = size - 1; index < i; i--)
    {
        *(a->data + i) = *(a->data + i - 1);
    }
    *(a->data + index) = value;
}

void array_prepend(Array *a, int value)
{
    array_insert(a, 0, value);
}

int array_pop(Array *a)
{
    array_resize(a);
    if (array_is_empty(a))
    {
        error("Array is empty cannot remove element from empty array");
    }
    a->size--;
    int element = *(a->data + a->size);
    return element;
}

void array_delete(Array *a, int index)
{
    if (index >= array_size(a) || index < 0)
    {
        error("Array index out of bound");
    }
    // Get last element and update size-1
    // and check if resizing is required
    int lastElement = array_pop(a);
    int lastIndex = array_size(a) - 1;
    // Shift remaining elements till index to left
    for (int i = index; i < lastIndex; i++)
    {
        *(a->data + i) = *(a->data + i + 1);
    }
    // Update last element
    if (lastIndex >= 0)
        *(a->data + lastIndex) = lastElement;
}

void array_remove(Array *a, int value)
{
    int size = array_size(a);
    for (int i = 0; i < size; i++)
    {
        if (*(a->data + i) == value)
        {
            array_delete(a, i);
            i--; //Start checking value from same index
        }
    }
}

int array_find(Array *a, int value)
{
    int size = array_size(a);
    for (int i = 0; i < size; i++)
    {
        if (*(a->data + i) == value)
        {
            return i;
        }
    }
    // if value is not found return -1
    return -1;
}

void array_resize(Array *a)
{
    // Double capacity if array is full
    if (array_is_full(a))
    {
        a->capacity *= 2;
        a->data = (int *)realloc(a->data, a->capacity * sizeof(int));
    }
    // If size of array is 1/4 of capacity shrink it by half
    else if (array_size(a) < array_capacity(a) / 4)
    {
        a->capacity /= 2;
        a->data = (int *)realloc(a->data, a->capacity * sizeof(int));
    }
}
void array_destroy(Array *a)
{
    free(a->data);
    free(a);
}
void array_print(Array *a)
{
    int capacity = array_size(a);
    printf("\nSize:%d\n", array_size(a));
    printf("Capacity:%d\n", array_capacity(a));
    printf("Array elements:\n");
    for (int i = 0; i < capacity; i++)
    {
        printf("Index:%d   Value:%d\n", i, *(a->data + i));
    }
    printf("==========================\n\n");
}

void check_address(void *p)
{
    if (!p)
    {
        error("Unable to allocate memory");
    }
}

void error(char msg[])
{
    printf("%s\n", msg);
    exit(EXIT_FAILURE);
}