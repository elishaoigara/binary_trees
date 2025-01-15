#include "binary_tree_s.h"

/**
 * height - Returns the height of a binary tree node
 * @node: Pointer to the node to measure height of
 * 
 * Return: Height of the node, or 0 if node is NULL
 */
size_t height(const avl_t *node)
{
    if (node == NULL)
        return (0);

    return (node->height);
}

