#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure the height.
 * Return: The height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    if (!tree)
        return 0;

    size_t left_height = binary_tree_height(tree->left);
    size_t right_height = binary_tree_height(tree->right);

    return (left_height > right_height ? left_height : right_height) + 1;
}

/**
 * is_perfect_helper - Helper function to check if the tree is perfect
 * @tree: A pointer to the root node of the tree to check.
 * @height: The height of the tree.
 * @level: The current level of the tree.
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int is_perfect_helper(const binary_tree_t *tree, size_t height, size_t level)
{
    if (!tree)
        return 1;

    if (!tree->left && !tree->right)  // Leaf node
        return (height == level + 1);

    if (!tree->left || !tree->right)  // One child missing
        return 0;

    return is_perfect_helper(tree->left, height, level + 1) &&
           is_perfect_helper(tree->right, height, level + 1);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: A pointer to the root node of the tree to check.
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    if (!tree)
        return 0;

    size_t height = binary_tree_height(tree);
    return is_perfect_helper(tree, height, 0);
}

