#include <stdio.h>
#include "array.h"
#include "array.c"

int main()
{
    Array *a = array_new();
    int upper = 100, lower = 1, num, totalNumbers = 10;
    array_print(a);
    for (int i = 0; i < totalNumbers; i++)
    {
        num = (rand() % (upper - lower + 1)) + lower;
        array_push(a, num);
    }
    array_print(a);
    printf("Value at index 5:%d\n", array_at(a, 5));
    printf("Pop element from array:%d\n", array_pop(a));
    printf("Insert element at index 7 value 45\n");
    array_insert(a, 7, 45);
    printf("Insert element at index 2 value 45\n");
    array_insert(a, 2, 45);
    printf("Push value 27\n");
    array_push(a, 27);
    printf("Prepend value 18\n");
    array_prepend(a, 18);
    printf("Delete element at index 4\n");
    array_delete(a, 4);
    array_print(a);
    printf("Find value 45 Index:%d\n", array_find(a, 45));
    printf("Find value 523: Return value of function:  %d\n", array_find(a, 523));
    printf("Remove all occurrence 45 from array\n");
    array_remove(a, 45);
    array_print(a);

    return 0;
}