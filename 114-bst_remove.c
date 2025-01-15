#include "binary_trees.h"

/**
 * bst_minimum - Find the minimum value node in a BST
 *
 * @node: pointer to the node to search from
 *
 * Return: pointer to the node with the minimum value
 */
static bst_t *bst_minimum(bst_t *node)
{
    while (node && node->left)
        node = node->left;
    return (node);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree
 *
 * @root: pointer to the root node of the tree
 * @value: value to remove
 *
 * Return: pointer to the new root node of the tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
    if (!root)
        return (NULL);

    if (value < root->n)
        root->left = bst_remove(root->left, value);
    else if (value > root->n)
        root->right = bst_remove(root->right, value);
    else
    {
        // Node to be deleted found
        if (!root->left)
        {
            bst_t *temp = root->right;
            free(root);
            return (temp);
        }
        else if (!root->right)
        {
            bst_t *temp = root->left;
            free(root);
            return (temp);
        }

        // Node has two children: get the inorder successor (smallest in the right subtree)
        bst_t *temp = bst_minimum(root->right);

        // Copy the inorder successor's content to this node
        root->n = temp->n;

        // Delete the inorder successor
        root->right = bst_remove(root->right, temp->n);
    }

    return (root);
}

