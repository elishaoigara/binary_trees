#include "binary_trees.h"

/**
 * height - Measures the height of a binary tree
 * @node: Pointer to the node to measure the height of
 * Return: The height of the tree
 */
size_t height(const avl_t *node)
{
    if (node == NULL)
        return (0);
    return (1 + MAX(height(node->left), height(node->right)));
}

/**
 * balance_factor - Measures the balance factor of a node in the tree
 * @node: Pointer to the node to measure the balance factor of
 * Return: The balance factor of the node
 */
int balance_factor(const avl_t *node)
{
    if (node == NULL)
        return (0);
    return (height(node->left) - height(node->right));
}

/**
 * avl_insert - Inserts a value into an AVL tree
 * @tree: A double pointer to the root node of the tree
 * @value: The value to insert into the tree
 * Return: A pointer to the root node of the tree after insertion
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    if (tree == NULL)
        return (NULL);

    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        return (*tree);
    }

    if (value < (*tree)->n)
        (*tree)->left = avl_insert(&(*tree)->left, value);
    else if (value > (*tree)->n)
        (*tree)->right = avl_insert(&(*tree)->right, value);
    else
        return (*tree);  /* Return the tree if the value is already present */

    /* Balance the tree after insertion */
    int balance = balance_factor(*tree);

    /* Left heavy (left subtree is taller) */
    if (balance > 1 && value < (*tree)->left->n)
        return (binary_tree_rotate_right(*tree)); /* Left-Left case */

    /* Right heavy (right subtree is taller) */
    if (balance < -1 && value > (*tree)->right->n)
        return (binary_tree_rotate_left(*tree)); /* Right-Right case */

    /* Left-right case */
    if (balance > 1 && value > (*tree)->left->n)
    {
        (*tree)->left = binary_tree_rotate_left((*tree)->left);
        return (binary_tree_rotate_right(*tree));
    }

    /* Right-left case */
    if (balance < -1 && value < (*tree)->right->n)
    {
        (*tree)->right = binary_tree_rotate_right((*tree)->right);
        return (binary_tree_rotate_left(*tree));
    }

    return (*tree);  /* Return the unchanged node pointer */
}

