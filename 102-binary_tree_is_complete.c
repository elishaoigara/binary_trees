#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: A pointer to the root node of the tree
 *
 * Return: 1 if complete, 0 if not complete or tree is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    // Initialize a queue for level-order traversal
    binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 1024); // A queue size can be chosen based on the tree size
    int front = 0, rear = 0;
    bool is_leaf = false;

    // Start by adding the root to the queue
    queue[rear++] = (binary_tree_t *)tree;

    while (front < rear)
    {
        binary_tree_t *current = queue[front++];

        // If we encounter a non-leaf node after a leaf node, it's not complete
        if (is_leaf && (current->left || current->right))
            return (0);

        // If left child exists, add it to the queue, otherwise mark as leaf
        if (current->left)
        {
            queue[rear++] = current->left;
        }
        else
        {
            is_leaf = true; // No left child, mark as leaf
        }

        // If right child exists, add it to the queue, otherwise mark as leaf
        if (current->right)
        {
            queue[rear++] = current->right;
        }
        else
        {
            is_leaf = true; // No right child, mark as leaf
        }
    }

    free(queue); // Free the allocated queue memory
    return (1); // The tree is complete
}

