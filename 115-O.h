#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

/* Structure for the Binary Search Tree */
typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} bst_t;

/* Function Prototypes */
bst_t *bst_insert(bst_t **tree, int value);
bst_t *bst_search(const bst_t *tree, int value);
bst_t *bst_remove(bst_t *root, int value);

#endif /* _BINARY_TREES_H_ */

