#include "115-O.h"
#include <stdio.h>

int main(void)
{
    bst_t *tree = NULL;
    bst_t *node;

    /* Insert values into the tree */
    bst_insert(&tree, 50);
    bst_insert(&tree, 30);
    bst_insert(&tree, 20);
    bst_insert(&tree, 40);
    bst_insert(&tree, 70);
    bst_insert(&tree, 60);
    bst_insert(&tree, 80);

    /* Search for a value in the tree */
    node = bst_search(tree, 40);
    printf("Found node with value: %d\n", node ? node->n : -1);

    /* Remove a node from the tree */
    tree = bst_remove(tree, 30);
    node = bst_search(tree, 30);
    printf("Found node with value: %d\n", node ? node->n : -1);

    return (0);
}

