#include <stdlib.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
    avl_t *tree;
    int array[] = {
        79, 47, 68, 87, 84, 91, 21, 32, 34, 2,
        20, 22, 98, 1, 62, 95
    };
    size_t n = sizeof(array) / sizeof(array[0]);

    /* Build the AVL tree from the array */
    tree = array_to_avl(array, n);
    if (!tree)
        return (1);

    /* Print the tree */
    binary_tree_print(tree);
    return (0);
}

