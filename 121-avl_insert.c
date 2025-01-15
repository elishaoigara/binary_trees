#include "binary_trees.h"

/* Helper function to get the balance factor of a node */
int balance_factor(const avl_t *node)
{
    if (!node)
        return 0;
    return height(node->left) - height(node->right);
}

/* Helper function to insert a node in the AVL tree */
avl_t *avl_insert(avl_t **tree, int value)
{
    if (!tree)
        return NULL;

    /* Step 1: Perform the normal BST insert */
    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        return *tree;
    }

    if (value < (*tree)->n)
        (*tree)->left = avl_insert(&(*tree)->left, value);
    else if (value > (*tree)->n)
        (*tree)->right = avl_insert(&(*tree)->right, value);

    /* Step 2: Update the height of the current node */
    (*tree)->height = 1 + ((height((*tree)->left) > height((*tree)->right)) ?
                           height((*tree)->left) : height((*tree)->right));

    /* Step 3: Get the balance factor */
    int balance = balance_factor(*tree);

    /* Step 4: Perform rotations to balance the tree if necessary */
    if (balance > 1 && value < (*tree)->left->n)
        return binary_tree_rotate_right(*tree);  /* Left Left Case */
    if (balance < -1 && value > (*tree)->right->n)
        return binary_tree_rotate_left(*tree);   /* Right Right Case */
    if (balance > 1 && value > (*tree)->left->n)
    {
        (*tree)->left = binary_tree_rotate_left((*tree)->left);  /* Left Right Case */
        return binary_tree_rotate_right(*tree);
    }
    if (balance < -1 && value < (*tree)->right->n)
    {
        (*tree)->right = binary_tree_rotate_right((*tree)->right); /* Right Left Case */
        return binary_tree_rotate_left(*tree);
    }

    return *tree;
}

