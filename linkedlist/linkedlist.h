#include <stdbool.h>

typedef struct LinkedListNode
{
    int data;
    struct LinkedListNode *next;
} Node;

typedef struct SinglyLinkedList
{
    Node *head;
    Node *tail;
    int size;

} LinkedList;

// Create new linked list
LinkedList *list_new();

// Create new node with given value
Node *node_new(int);

// Get linked list size
int list_size(LinkedList *);

// Insert element at start
void list_push_start(LinkedList *, int);

// Delete element at start
int list_pop_start(LinkedList *);

// Insert element at end
void list_push_end(LinkedList *, int);

// Delete element at end
int list_pop_end(LinkedList *);

// Get value of first node
int list_start(LinkedList *);

// Get value of last node
int list_end(LinkedList *);

// Get value at index
int list_value_at(LinkedList *, int);

// Insert value at given index
void list_insert(LinkedList *, int, int);

// Delete value at given index
int list_delete(LinkedList *, int);

// Remove node with give value from start
void list_remove(LinkedList *, int);

// Reverse linked list
void list_reverse(LinkedList *);

// Check if linked list is empty
bool list_is_empty(LinkedList *);

// Delete linked list
void list_destroy(LinkedList *);

// Print linked list and size
void list_print(LinkedList *);

// Print error message
void error(char[]);

// Check memory address
void check_address(void *);