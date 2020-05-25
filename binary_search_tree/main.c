#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree.c"

int main()
{
    Node *root = bst_insert(NULL, 5);
    bst_insert(root, 4);
    bst_insert(root, 7);
    bst_insert(root, 9);
    bst_insert(root, 6);
    bst_insert(root, 3);
    bst_insert(root, 2);
    bst_insert(root, 1);
    bst_print(root, "inorder");
    bst_print(root, "preorder");
    bst_print(root, "postorder");
    bst_print(root, "levelorder");
    printf("Binary search tree height:%d\n", bst_get_height(root));
    printf("Check if value 5 is in tree:%s\n", bst_is_value_in_tree(root, 5) ? "true" : "false");
    printf("Check if value 8 is in tree:%s\n", bst_is_value_in_tree(root, 8) ? "true" : "false");
    printf("Min:%d\n", bst_min(root));
    printf("Max:%d\n", bst_max(root));
    bst_destroy(root);
    return 0;
}