#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree
 * @tree: A pointer to the root node of the tree to rotate
 * 
 * Return: The new root node of the tree after the rotation
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
    binary_tree_t *new_root;

    if (tree == NULL || tree->left == NULL)
        return (tree);

    new_root = tree->left;  // The new root will be the left child of the current root
    tree->left = new_root->right;  // The right child of the new root becomes the left child of the original root
    if (new_root->right)
        new_root->right->parent = tree;  // Update the parent pointer if necessary

    new_root->right = tree;  // The current root becomes the right child of the new root
    tree->parent = new_root;  // Update the parent pointer of the original root

    return (new_root);  // Return the new root node
}

