#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
    bst_t *tree;
    int array[] = {
        79, 47, 68, 87, 84, 91, 21, 32, 34, 2,
        20, 22, 98, 1, 62, 95
    };
    size_t n = sizeof(array) / sizeof(array[0]);
    bst_t *node;

    tree = array_to_bst(array, n);  // Build BST from array
    if (!tree)
        return (1);  // Return error if tree creation failed
    
    binary_tree_print(tree);  // Print the created tree
    
    // Search for a node with value 32
    node = bst_search(tree, 32);
    if (node)
        printf("Found: %d\n", node->n);  // If found, print the node's value
    else
        printf("Node not found\n");

    binary_tree_print(node);  // Print the subtree rooted at node (if found)
    
    // Search for a node with value 512 (which doesn't exist in the tree)
    node = bst_search(tree, 512);
    printf("Node should be nil -> %p\n", (void *)node);  // Expect NULL if not found

    return (0);  // Return success
}

