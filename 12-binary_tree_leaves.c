#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree.
 * @tree: A pointer to the root node of the tree to count the leaves.
 *
 * Return: The number of leaves. If tree is NULL, returns 0.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
    size_t leaves = 0;

    if (tree == NULL)
        return (0);

    /* A leaf node is a node without children */
    if (tree->left == NULL && tree->right == NULL)
        return (1);

    /* Recurse on both left and right subtrees */
    leaves += binary_tree_leaves(tree->left);
    leaves += binary_tree_leaves(tree->right);

    return (leaves);
}

