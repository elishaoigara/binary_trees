#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node
 * @node: A pointer to the node to find the sibling
 * Return: A pointer to the sibling node, or NULL if there is no sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
    if (!node || !node->parent)
        return NULL;

    if (node->parent->left == node)
        return node->parent->right;
    else if (node->parent->right == node)
        return node->parent->left;

    return NULL;  /* If the node has no sibling */
}

