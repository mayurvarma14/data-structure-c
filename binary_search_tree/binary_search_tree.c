#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "queue.c"

Node *bst_create_new(int value)
{
    Node *n = malloc(sizeof(Node));
    check_address(n);
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

Node *bst_insert(Node *n, int value)
{
    if (n == NULL)
    {
        Node *new_node = bst_create_new(value);
        n = new_node;
    }
    else
    {
        if (value < n->data)
        {
            n->left = bst_insert(n->left, value);
        }
        else if (value > n->data)
        {
            n->right = bst_insert(n->right, value);
        }
    }
    return n;
}

// TODO:void bst_delete(Node *n, int value)
// {
// }

void bst_destroy(Node *n)
{
    if (n)
    {
        bst_destroy(n->left);
        bst_destroy(n->right);
        free(n);
    }
}

int bst_min(Node *n)
{
    if (n == NULL)
    {
        error("Node is NULL cannot find min");
    }

    while (n->left != NULL)
    {
        n = n->left;
    }
    return n->data;
}

int bst_max(Node *n)
{
    if (n == NULL)
    {
        error("Node is NULL cannot find max");
    }

    while (n->right != NULL)
    {
        n = n->right;
    }
    return n->data;
}

int bst_get_height(Node *n)
{
    int height = 0;
    if (n)
    {
        Queue *q = queue_new();
        queue_enqueue(q, n);
        queue_enqueue(q, NULL);
        while (!queue_is_empty(q))
        {
            Node *node = queue_dequeue(q);
            if (node == NULL)
            {
                height++;
                queue_enqueue(q, NULL);
            }
            else
            {
                if (node->left)
                    queue_enqueue(q, node->left);
                if (node->right)
                    queue_enqueue(q, node->right);
            }
        }
        queue_destroy(q);
    }
    return height;
}

bool bst_is_binary_search_tree(Node *n)
{
}

bool bst_is_value_in_tree(Node *n, int value)
{
    if (n)
    {
        while (n != NULL)
        {
            if (n->data == value)
                return true;
            else if (value < n->data)
                n = n->left;
            else
                n = n->right;
        }
    }
    return false;
}

int bst_get_size(Node *n)
{
    if (n == NULL)
        return 0;
    return bst_get_size(n->left) + bst_get_size(n->right) + 1;
}

void bst_print(Node *n, char type[])
{
    printf("\nSize:%d\n", bst_get_size(n));
    printf("==========================[%s]\n", type);
    if (strcmp(type, "inorder") == 0)
        bst_inorder(n);
    if (strcmp(type, "preorder") == 0)
        bst_preorder(n);
    if (strcmp(type, "postorder") == 0)
        bst_postorder(n);
    if (strcmp(type, "levelorder") == 0)
        bst_levelorder(n);
    printf("\n==========================\n\n");
}

void bst_inorder(Node *n)
{
    if (n)
    {
        bst_inorder(n->left);
        printf(" %d ", n->data);
        bst_inorder(n->right);
    }
}

void bst_preorder(Node *n)
{
    if (n)
    {
        printf(" %d ", n->data);
        bst_preorder(n->left);
        bst_preorder(n->right);
    }
}

void bst_postorder(Node *n)
{
    if (n)
    {
        bst_postorder(n->left);
        bst_postorder(n->right);
        printf(" %d ", n->data);
    }
}

void bst_levelorder(Node *n)
{
    if (n)
    {
        Queue *q = queue_new();
        queue_enqueue(q, n);
        while (!queue_is_empty(q))
        {
            Node *node = queue_dequeue(q);
            printf(" %d ", node->data);
            if (node->left)
            {

                queue_enqueue(q, node->left);
            }
            if (node->right)
            {
                queue_enqueue(q, node->right);
            }
        }
        queue_destroy(q);
    }
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

// TODO:get_successor
