#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_delete - Deletes an entire binary tree.
 * @tree: A pointer to the root node of the tree to delete.
 *
 * Description: Recursively traverses the tree, deleting each node.
 */
void binary_tree_delete(binary_tree_t *tree)
{
    if (tree == NULL)
        return;

    /* Recursively delete the left and right children */
    binary_tree_delete(tree->left);
    binary_tree_delete(tree->right);

    /* Free the current node */
    free(tree);
}

