#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stddef.h>  /* for size_t */

/* Structure for binary tree node */
typedef struct binary_tree_s {
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
    size_t height;  /* height of the node */
} avl_t;

/* Function prototypes */
avl_t *avl_insert(avl_t **tree, int value);
size_t height(const avl_t *node);  /* Declare height function here */
int balance_factor(avl_t *node);
avl_t *binary_tree_rotate_left(avl_t *tree);
avl_t *binary_tree_rotate_right(avl_t *tree);
avl_t *binary_tree_node(avl_t *parent, int value);
void binary_tree_print(const avl_t *tree);

#endif /* BINARY_TREE_H */

