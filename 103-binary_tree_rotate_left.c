#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Rotates a binary tree to the left.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node of the tree once rotated.
 *         If tree is NULL or has no right child, return the tree unchanged.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
    binary_tree_t *new_root;

    if (tree == NULL || tree->right == NULL)
        return (tree);

    new_root = tree->right;           /* Make right child the new root */
    tree->right = new_root->left;     /* Move the left child of new root to right of tree */
    if (new_root->left != NULL)
        new_root->left->parent = tree; /* Set the parent of the moved node */
    new_root->left = tree;            /* Make tree the left child of new root */
    tree->parent = new_root;          /* Set the parent of the original root to new root */

    return (new_root);                /* Return the new root of the tree */
}

