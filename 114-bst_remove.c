#include "binary_trees.h"

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: A pointer to the root node of the tree
 * @value: The value to remove
 * 
 * Return: The new root of the tree after the removal
 */
bst_t *bst_remove(bst_t *root, int value)
{
    bst_t *temp;

    if (!root)
        return (NULL); /* Return NULL if root is NULL */

    /* Traverse the tree to find the node */
    if (value < root->n)
        root->left = bst_remove(root->left, value);
    else if (value > root->n)
        root->right = bst_remove(root->right, value);
    else
    {
        /* Node to be deleted found */

        /* Case 1: Node has no children (leaf node) */
        if (!root->left && !root->right)
        {
            free(root);
            return (NULL);
        }
        /* Case 2: Node has only one child */
        else if (!root->left || !root->right)
        {
            temp = root;
            root = (root->left) ? root->left : root->right;
            free(temp);
        }
        /* Case 3: Node has two children */
        else
        {
            temp = bst_minimum(root->right);
            root->n = temp->n;
            root->right = bst_remove(root->right, temp->n);
        }
    }

    return (root);
}

