#include "binary_trees.h"

/**
 * is_bst_helper - Helper function to recursively check if a tree is a BST
 * @tree: Pointer to the root node of the tree
 * @min: The minimum allowable value for the current node
 * @max: The maximum allowable value for the current node
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int is_bst_helper(const binary_tree_t *tree, int min, int max)
{
    if (tree == NULL)
        return (1);

    /* Check the current node's value is within the allowed range */
    if (tree->n <= min || tree->n >= max)
        return (0);

    /* Recursively check the left and right subtrees */
    return (is_bst_helper(tree->left, min, tree->n) && is_bst_helper(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    /* Call the helper function with the full range of integer values */
    return (is_bst_helper(tree, INT_MIN, INT_MAX));
}

