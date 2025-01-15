#include "binary_trees.h"

/* Helper function for array_to_avl */
void array_to_avl_helper(int *array, size_t size, avl_t **tree, int direction);

/**
 * array_to_avl - Builds an AVL tree from an array
 * @array: A pointer to the array to be used for building the AVL tree
 * @size: The size of the array
 * Return: A pointer to the root node of the AVL tree, or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
    avl_t *tree = NULL;

    if (array == NULL || size == 0)
        return (NULL);

    array_to_avl_helper(array, size, &tree, 0);
    return (tree);
}

/**
 * array_to_avl_helper - Helper function to recursively build the AVL tree
 * @array: The array to build the tree from
 * @size: The size of the current subtree
 * @tree: A double pointer to the root node of the tree
 * @direction: The direction of recursion (0 for left, 1 for right)
 */
void array_to_avl_helper(int *array, size_t size, avl_t **tree, int direction)
{
    size_t mid;

    if (size == 0)
        return;

    mid = size / 2;

    /* Insert the middle element of the array as root */
    avl_insert(tree, array[mid]);

    /* Recursively build the left and right subtrees */
    array_to_avl_helper(array, mid, tree, 0);  /* Left */
    array_to_avl_helper(array + mid + 1, size - mid - 1, tree, 1);  /* Right */
}

