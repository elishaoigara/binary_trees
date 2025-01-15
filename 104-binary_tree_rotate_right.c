#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree
 * @tree: A pointer to the root node of the tree to rotate
 * 
 * Return: The new root node of the tree after the rotation, or NULL if tree is NULL
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
    binary_tree_t *new_root;

    if (tree == NULL || tree->left == NULL)
        return (tree);

    new_root = tree->left;  /* The new root will be the left child of the current root */
    tree->left = new_root->right;  /* The right child of the new root becomes the left child of the current root */
    
    if (new_root->right != NULL)
        new_root->right->parent = tree;  /* Update parent pointer of the old right child */

    new_root->right = tree;  /* The current root becomes the right child of the new root */
    new_root->parent = tree->parent;  /* The parent of the current root becomes the parent of the new root */

    if (tree->parent != NULL)  /* If the current root had a parent, update its child pointer */
    {
        if (tree == tree->parent->left)
            tree->parent->left = new_root;
        else
            tree->parent->right = new_root;
    }

    tree->parent = new_root;  /* The current root now has the new root as its parent */

    return (new_root);  /* Return the new root node */
}

