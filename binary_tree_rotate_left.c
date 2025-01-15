#include "binary_tree_s.h"

/**
 * binary_tree_rotate_left - Rotates a binary tree node to the left
 * @tree: Root node of the tree to rotate
 * 
 * Return: New root node after rotation
 */
avl_t *binary_tree_rotate_left(avl_t *tree)
{
    avl_t *new_root = tree->right;
    avl_t *temp = new_root->left;

    new_root->left = tree;
    tree->right = temp;

    /* Update parents */
    if (temp)
        temp->parent = tree;
    new_root->parent = tree->parent;
    tree->parent = new_root;

    /* Update heights */
    tree->height = 1 + ((height(tree->left) > height(tree->right)) ? height(tree->left) : height(tree->right));
    new_root->height = 1 + ((height(new_root->left) > height(new_root->right)) ? height(new_root->left) : height(new_root->right));

    return (new_root);
}

