#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "linkedlist.h"

LinkedList *list_new()
{
    LinkedList *list = malloc(sizeof(LinkedList));
    check_address(list);
    list->size = 0;
    list->head = list->tail = NULL;
    return list;
}

Node *node_new(int value)
{
    Node *node = malloc(sizeof(Node));
    check_address(node);
    node->data = value;
    node->next = NULL;
    return node;
}

int list_size(LinkedList *list)
{
    return list->size;
}

void list_push_start(LinkedList *list, int value)
{
    Node *node = node_new(value);

    if (list_is_empty(list))
    {
        list->head = list->tail = node;
    }
    else
    {
        node->next = list->head;
        list->head = node;
    }
    list->size++;
}

int list_pop_start(LinkedList *list)
{
    if (list_is_empty(list))
    {
        error("Linked list is empty cannot pop");
    }
    Node *node = list->head;
    int value = node->data;
    if (list->head == list->tail)
    {
        list->head = list->tail = NULL;
    }
    else
    {
        list->head = node->next;
    }
    free(node);
    list->size--;
    return value;
}

void list_push_end(LinkedList *list, int value)
{
    Node *node = node_new(value);
    if (list_is_empty(list))
    {
        list->head = list->tail = node;
    }
    else
    {
        list->tail->next = node;
        list->tail = node;
    }

    list->size++;
}

int list_pop_end(LinkedList *list)
{
    if (list_is_empty(list))
    {
        error("Linked list is empty cannot pop");
    }
    Node *current = list->head;
    Node *previous = NULL;
    if (list->head == list->tail)
    {
        list->head = list->tail = NULL;
    }
    else
    {
        while (current->next != NULL)
        {
            previous = current;
            current = current->next;
        }
        previous->next = NULL;
        list->tail = previous;
    }
    int value = current->data;
    free(current);
    list->size--;
    return value;
}

int list_start(LinkedList *list)
{
    if (list_is_empty(list))
    {
        error("Linked list is empty cannot get first element");
    }

    return list->head->data;
}

int list_end(LinkedList *list)
{
    if (list_is_empty(list))
    {
        error("Linked list is empty cannot get last element");
    }
    return list->tail->data;
}

int list_value_at(LinkedList *list, int index)
{
    int i = 0, size = list_size(list);
    if (list_is_empty(list))
    {
        error("Linked list is empty cannot get value at given index");
    }
    if (index > size - 1 || index < 0)
    {
        error("Index out of bound");
    }
    Node *current = list->head;
    while (index != i)
    {
        current = current->next;
        i++;
    }
    return current->data;
}

void list_insert(LinkedList *list, int, int);

int list_delete(LinkedList *list, int index)
{
    int i = 0, value, size = list_size(list);
    if (list_is_empty(list))
    {
        error("Linked list is empty cannot delete value at given index");
    }
    if (index > size - 1 || index < 0)
    {
        error("Index out of bound");
    }
    if (index == 0)
    {
        return list_pop_start(list);
    }
    else if (index == size - 1)
    {
        return list_pop_end(list);
    }
    Node *current = list->head;
    Node *previous = NULL;
    while (index != i)
    {
        previous = current;
        current = current->next;
        i++;
    }
    previous->next = current->next;
    value = current->data;
    free(current);
    list->size--;
    return value;
}

void list_remove(LinkedList *list, int value)
{
    if (list_is_empty(list))
    {
        error("Linked list is empty cannot delete value at given index");
    }
    Node *current = list->head;
    Node *previous = NULL;
    while (current != NULL && current->data != value)
    {
        previous = current;
        current = current->next;
    }
    if (current == NULL)
    {
        printf("Node with value %d not found\n", value);
        return;
    }
    if (list->head == current)
    {
        list_pop_start(list);
        return;
    }
    else if (list->tail == current)
    {
        list_pop_end(list);
        return;
    }
    previous->next = current->next;
    free(current);
    list->size--;
}

void list_reverse(LinkedList *list)
{
    if (list_is_empty(list))
    {
        error("Linked list is empty cannot reverse");
    }
    if (list_size(list) == 1)
    {
        return;
    }
    Node *current = list->head;
    Node *previous = NULL, *next;
    list->tail = list->head;
    while (current->next != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    current->next = previous;
    list->head = current;
}

bool list_is_empty(LinkedList *list)
{
    return list->size == 0;
}

void list_destroy(LinkedList *list)
{
    if (!list_is_empty(list))
    {

        Node *current = list->head;
        Node *previous = NULL;
        while (current->next != NULL)
        {
            previous = current;
            current = current->next;
            free(previous);
        }
        free(current);
    }
    free(list);
}

void list_print(LinkedList *list)
{
    Node *current = list->head;
    int i = 0;
    printf("\nSize:%d\n", list_size(list));
    while (current != NULL)
    {
        printf("Index:%d   Value:%d\n", i, current->data);
        i++;
        current = current->next;
    }
    printf("==========================\n\n");
}

void error(char msg[])
{
    printf("%s\n", msg);
    exit(EXIT_FAILURE);
}

void check_address(void *address)
{
    if (!address)
    {
        error("Unable to allocate memory");
    }
}