#include "binary_trees.h"

/**
 * bst_insert - Inserts a value into a Binary Search Tree
 * @tree: A pointer to the root node of the BST
 * @value: The value to be inserted into the tree
 *
 * Return: A pointer to the newly created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    bst_t *new_node, *current, *parent;

    if (!tree)
        return (NULL);

    /* Create a new node */
    new_node = binary_tree_node(NULL, value);
    if (!new_node)
        return (NULL);

    /* If the tree is empty, make the new node the root */
    if (*tree == NULL)
    {
        *tree = new_node;
        return (new_node);
    }

    current = *tree;
    parent = NULL;

    /* Traverse the tree to find the correct position */
    while (current)
    {
        parent = current;
        if (value < current->n)
            current = current->left;
        else if (value > current->n)
            current = current->right;
        else
        {
            /* Value already exists, do nothing */
            free(new_node);
            return (NULL);
        }
    }

    /* Insert the new node */
    if (value < parent->n)
        parent->left = new_node;
    else
        parent->right = new_node;

    new_node->parent = parent;
    return (new_node);
}

