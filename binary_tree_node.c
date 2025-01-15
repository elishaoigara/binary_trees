#include "binary_tree_s.h"
#include <stdlib.h>

/**
 * binary_tree_node - Creates a new binary tree node
 * @parent: Parent node of the new node
 * @value: Value to store in the new node
 * 
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *binary_tree_node(avl_t *parent, int value)
{
    avl_t *node;

    node = malloc(sizeof(avl_t));
    if (!node)
        return (NULL);

    node->n = value;
    node->parent = parent;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;  /* New node's height is 1 */

    return (node);
}

