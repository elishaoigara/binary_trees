#include "binary_trees.h"

/**
 * binary_tree_postorder - Goes through a binary tree using post-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node. The value in the node
 *        must be passed as a parameter to this function.
 *
 * Return: None.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    binary_tree_postorder(tree->left, func);   /* Traverse left subtree */
    binary_tree_postorder(tree->right, func);  /* Traverse right subtree */
    func(tree->n);                             /* Visit the node */
}

