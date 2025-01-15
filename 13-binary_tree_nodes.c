#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least one child in a binary tree.
 * @tree: A pointer to the root node of the tree to count the nodes.
 *
 * Return: The number of nodes with at least one child. If tree is NULL, returns 0.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
    size_t nodes = 0;

    if (tree == NULL)
        return (0);

    /* A node with at least one child has either a left or a right child */
    if (tree->left != NULL || tree->right != NULL)
        nodes = 1;

    /* Recurse on both left and right subtrees */
    nodes += binary_tree_nodes(tree->left);
    nodes += binary_tree_nodes(tree->right);

    return (nodes);
}

