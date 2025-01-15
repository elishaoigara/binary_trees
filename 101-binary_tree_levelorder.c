#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * 
 * Return: Nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    binary_tree_t **queue;
    int front = 0, rear = 0, size = 0;
    binary_tree_t *current;

    if (!tree || !func)
        return;

    // Allocating memory for the queue (to store nodes for level-order)
    queue = malloc(sizeof(binary_tree_t *) * 1024); // Arbitrary size of 1024
    if (!queue)
        return;

    // Enqueue root node
    queue[rear++] = (binary_tree_t *)tree;
    size++;

    // Process each node in the queue
    while (size > 0)
    {
        // Dequeue node and apply the function
        current = queue[front++];
        size--;
        func(current->n);  // Apply func to current node's value

        // Enqueue left and right children if they exist
        if (current->left)
        {
            queue[rear++] = current->left;
            size++;
        }
        if (current->right)
        {
            queue[rear++] = current->right;
            size++;
        }
    }

    // Free the queue
    free(queue);
}

