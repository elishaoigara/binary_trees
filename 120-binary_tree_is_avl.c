#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Helper function to check the height of the tree */
int height(const binary_tree_t *node)
{
    int left_height, right_height;

    if (!node)
        return -1;

    left_height = height(node->left);
    right_height = height(node->right);

    return (left_height > right_height ? left_height : right_height) + 1;
}

/* Helper function to check if a tree is a valid binary search tree */
int is_bst(const binary_tree_t *node, int min, int max)
{
    if (!node)
        return 1;

    if (node->n <= min || node->n >= max)
        return 0;

    return is_bst(node->left, min, node->n) && is_bst(node->right, node->n, max);
}

/* Main function to check if the tree is a valid AVL Tree */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    int left_height, right_height;

    if (!tree)
        return 0;

    /* Check if it is a BST */
    if (!is_bst(tree, INT_MIN, INT_MAX))
        return 0;

    /* Check if the balance factor is valid */
    left_height = height(tree->left);
    right_height = height(tree->right);

    if (abs(left_height - right_height) > 1)
        return 0;

    return binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right);
}

