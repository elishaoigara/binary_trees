#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: The number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
    avl_t *tree = NULL;
    size_t mid;

    if (!array || size == 0)
        return (NULL);

    /* Find the median element of the array */
    mid = size / 2;

    /* Insert the middle element into the AVL tree */
    avl_insert(&tree, array[mid]);

    /* Recursively build the left subtree from the left half of the array */
    array_to_avl_helper(array, mid, &tree, 0);

    /* Recursively build the right subtree from the right half of the array */
    array_to_avl_helper(array + mid + 1, size - mid - 1, &tree, 1);

    return (tree);
}

/**
 * array_to_avl_helper - Recursively inserts elements from the array into the AVL tree
 * @array: Pointer to the subarray to insert elements from
 * @size: The number of elements in the subarray
 * @tree: Double pointer to the root node of the AVL tree
 * @direction: Direction to determine if inserting to the left or right
 */
void array_to_avl_helper(int *array, size_t size, avl_t **tree, int direction)
{
    size_t mid;

    if (size == 0)
        return;

    /* Find the median of the subarray */
    mid = size / 2;

    if (direction == 0)
        avl_insert(tree, array[mid]);
    else
        avl_insert(tree, array[mid]);

    /* Insert the left half */
    array_to_avl_helper(array, mid, tree, 0);

    /* Insert the right half */
    array_to_avl_helper(array + mid + 1, size - mid - 1, tree, 1);
}

