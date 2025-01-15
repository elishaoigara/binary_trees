#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree
 * @tree: A pointer to the root node of the BST
 * @value: The value to search in the tree
 *
 * Return: A pointer to the node containing the value, or NULL if not found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
    if (!tree)
        return (NULL);

    if (tree->n == value)
        return ((bst_t *)tree);

    if (value < tree->n)
        return (bst_search(tree->left, value));
    else
        return (bst_search(tree->right, value));
}

