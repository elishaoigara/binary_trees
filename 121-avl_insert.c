#include "binary_trees.h"

/**
 * height - Calculates the height of a binary tree.
 * @node: Pointer to the root node.
 *
 * Return: Height of the node.
 */
int height(const binary_tree_t *node)
{
    int left_height, right_height;

    if (!node)
        return (0);

    left_height = height(node->left);
    right_height = height(node->right);

    return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * balance_factor - Calculates the balance factor of a node.
 * @node: Pointer to the node.
 *
 * Return: Balance factor.
 */
int balance_factor(const binary_tree_t *node)
{
    if (!node)
        return (0);

    return (height(node->left) - height(node->right));
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: Double pointer to the root of the AVL tree.
 * @value: The value to insert.
 *
 * Return: Pointer to the inserted node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    
    	if (!*tree)
        return (*tree = binary_tree_node(NULL, value));

    if (value < (*tree)->n)
        (*tree)->left = avl_insert(&((*tree)->left), value);
    else if (value > (*tree)->n)
    	    (*tree)->right = avl_insert(&((*tree)->right), value);
    else
        return (*tree);

    balance = balance_factor(*tree);

    /* Left Left Case */
    if (balance > 1 && value < (*tree)->left->n)
        return (binary_tree_rotate_right(*tree));

    /* Right Right Case */
    if (balance < -1 && value > (*tree)->right->n)
        return (binary_tree_rotate_left(*tree));

    /* Left Right Case */
    if (balance > 1 && value > (*tree)->left->n)
    {
        (*tree)->left = binary_tree_rotate_left((*tree)->left);
        return (binary_tree_rotate_right(*tree));
    }

    /* Right Left Case */
    if (balance < -1 && value < (*tree)->right->n)
    {
        (*tree)->right = binary_tree_rotate_right((*tree)->right);
        return (binary_tree_rotate_left(*tree));
    }

    return (*tree);
}

