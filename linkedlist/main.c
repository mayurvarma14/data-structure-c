#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.c"

int main()
{
    LinkedList *list = list_new();
    for (int i = 1; i <= 5; i++)
    {
        list_push_start(list, i);
    }
    for (int i = 6; i <= 10; i++)
    {
        list_push_end(list, i);
    }
    list_print(list);
    // list_push_start(list, 63);
    // list_print(list);
    printf("Value at start:%d\n", list_start(list));
    printf("Value at end:%d\n", list_end(list));
    printf("Pop Start:%d\n", list_pop_start(list));
    printf("Pop End:%d\n", list_pop_end(list));
    list_print(list);
    printf("Value at index 1:%d\n", list_value_at(list, 1));
    printf("Value at index 4:%d\n", list_value_at(list, 4));
    printf("Delete value at index 3:%d\n", list_delete(list, 3));
    printf("Remove node with value 8\n");
    list_remove(list, 8);
    printf("Remove node with value 10\n");
    list_remove(list, 10);
    list_print(list);
    printf("Reverse linked list\n");
    list_reverse(list);
    list_print(list);
    list_destroy(list);

    return 0;
}
