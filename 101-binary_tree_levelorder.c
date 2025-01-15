#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to the function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    binary_tree_t *queue[1024];
    int front = 0, rear = 0;

    /* Return if tree or func is NULL */
    if (tree == NULL || func == NULL)
        return;

    /* Enqueue the root node */
    queue[rear++] = (binary_tree_t *)tree;

    while (front != rear)
    {
        /* Dequeue the front node */
        binary_tree_t *node = queue[front++];
        
        /* Call the function on the node */
        func(node->n);

        /* Enqueue left and right children */
        if (node->left)
            queue[rear++] = node->left;
        if (node->right)
            queue[rear++] = node->right;
    }
}

