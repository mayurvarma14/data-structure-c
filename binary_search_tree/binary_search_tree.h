#include <stdbool.h>

typedef struct BinaryTreeNode
{
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
} Node;

// Crete new node
Node *bst_create_new(int);

// Insert value in tree
Node *bst_insert(Node *, int);

// Delete value in tree
void bst_delete(Node *, int);

// Delete tree
void bst_destroy(Node *);

// Get min value from tree
int bst_min(Node *);

// Get max value from tree
int bst_max(Node *);

// Get tree height
int bst_get_height(Node *);

// Get height of tree If null then return 0
bool bst_is_binary_search_tree(Node *);

// Check if value is present in tree
bool bst_is_value_in_tree(Node *, int);

// Get total number of nodes in tree
int bst_get_size(Node *);

// Print tree, size
void bst_print(Node *, char type[]);

// Inorder traversal
void bst_inorder(Node *);

// Preorder traversal
void bst_preorder(Node *);

// Postorder traversal
void bst_postorder(Node *);

// Levelorder traversal
void bst_levelorder(Node *);

// Print error message
void error(char[]);

// Check memory address
void check_address(void *);

// get_successor // returns next-highest value in tree after given value, -1 if none
