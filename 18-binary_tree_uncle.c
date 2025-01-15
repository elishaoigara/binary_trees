#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: A pointer to the node to find the uncle
 * Return: A pointer to the uncle node, or NULL if there is no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
    if (!node || !node->parent || !node->parent->parent)
        return NULL;

    if (node->parent == node->parent->parent->left)
        return node->parent->parent->right;
    else if (node->parent == node->parent->parent->right)
        return node->parent->parent->left;

    return NULL;  /* If the node has no uncle */
}

