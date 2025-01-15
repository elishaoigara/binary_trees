#include "binary_tree_s.h"
#include <stdlib.h>

/**
 * balance_factor - Computes the balance factor of a node
 * @node: Pointer to the node to calculate balance factor for
 * 
 * Return: Balance factor of the node
 */
int balance_factor(avl_t *node)
{
    return (height(node->left) - height(node->right));
}

/**
 * avl_insert - Inserts a value in an AVL Tree and balances it
 * @tree: Double pointer to the root of the tree
 * @value: Value to insert
 * 
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    avl_t *node = NULL;
    int balance;

    if (*tree == NULL)
    {
        node = binary_tree_node(NULL, value);
        *tree = node;
        return (node);
    }

    if (value < (*tree)->n)
        node = avl_insert(&(*tree)->left, value);
    else if (value > (*tree)->n)
        node = avl_insert(&(*tree)->right, value);
    else
        return (NULL);  /* No duplicates allowed */

    /* Update height of current node */
    (*tree)->height = 1 + ((height((*tree)->left) > height((*tree)->right)) ? height((*tree)->left) : height((*tree)->right));

    /* Check balance factor */
    balance = balance_factor(*tree);

    /* Left heavy */
    if (balance > 1 && value < (*tree)->left->n)
        return (binary_tree_rotate_right(*tree));

    /* Right heavy */
    if (balance < -1 && value > (*tree)->right->n)
        return (binary_tree_rotate_left(*tree));

    /* Left-Right case */
    if (balance > 1 && value > (*tree)->left->n)
    {
        (*tree)->left = binary_tree_rotate_left((*tree)->left);
        return (binary_tree_rotate_right(*tree));
    }

    /* Right-Left case */
    if (balance < -1 && value < (*tree)->right->n)
    {
        (*tree)->right = binary_tree_rotate_right((*tree)->right);
        return (binary_tree_rotate_left(*tree));
    }

    return (*tree);
}

