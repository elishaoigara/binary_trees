#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * binary_tree_print - Prints a binary tree in a pretty way
 * @tree: pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
    if (!tree)
        return;

    printf(".-------(%d)-------.\n", tree->n);

    if (tree->left)
        printf("  .--(%d)--.     ", tree->left->n);
    else
        printf("           .--(nil)--.     ");

    if (tree->right)
        printf(".--(%d)--.\n", tree->right->n);
    else
        printf(".--(nil)--.\n");

    binary_tree_print(tree->left);
    binary_tree_print(tree->right);
}

