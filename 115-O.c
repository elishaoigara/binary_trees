#include <stdio.h>
#include <stdlib.h>

/* Structure for the Binary Search Tree */
typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} bst_t;

/* Function to insert a value into the BST (O(log n)) */
bst_t *bst_insert(bst_t **tree, int value)
{
    bst_t *node = NULL, *temp = *tree;

    if (!tree)
        return (NULL);
    node = malloc(sizeof(bst_t));
    if (!node)
        return (NULL);
    node->n = value;
    node->left = node->right = node->parent = NULL;

    if (!*tree)
        *tree = node;
    else
    {
        while (temp)
        {
            if (value < temp->n)
            {
                if (!temp->left)
                {
                    temp->left = node;
                    node->parent = temp;
                    break;
                }
                temp = temp->left;
            }
            else if (value > temp->n)
            {
                if (!temp->right)
                {
                    temp->right = node;
                    node->parent = temp;
                    break;
                }
                temp = temp->right;
            }
            else
            {
                free(node);
                return (NULL);
            }
        }
    }
    return (node);
}

/* Function to search a value in the BST (O(log n)) */
bst_t *bst_search(const bst_t *tree, int value)
{
    while (tree)
    {
        if (value < tree->n)
            tree = tree->left;
        else if (value > tree->n)
            tree = tree->right;
        else
            return ((bst_t *)tree);
    }
    return (NULL);
}

/* Function to remove a node from the BST (O(log n)) */
bst_t *bst_remove(bst_t *root, int value)
{
    bst_t *temp;
    if (!root)
        return (NULL);

    if (value < root->n)
        root->left = bst_remove(root->left, value);
    else if (value > root->n)
        root->right = bst_remove(root->right, value);
    else
    {
        if (!root->left)
        {
            temp = root->right;
            free(root);
            return (temp);
        }
        else if (!root->right)
        {
            temp = root->left;
            free(root);
            return (temp);
        }
        temp = root->right;
        while (temp && temp->left)
            temp = temp->left;
        root->n = temp->n;
        root->right = bst_remove(root->right, temp->n);
    }
    return (root);
}

int main(void)
{
    bst_t *tree = NULL;
    bst_t *node;

    bst_insert(&tree, 50);
    bst_insert(&tree, 30);
    bst_insert(&tree, 20);
    bst_insert(&tree, 40);
    bst_insert(&tree, 70);
    bst_insert(&tree, 60);
    bst_insert(&tree, 80);

    node = bst_search(tree, 40);
    printf("Found node with value: %d\n", node ? node->n : -1);

    tree = bst_remove(tree, 30);
    node = bst_search(tree, 30);
    printf("Found node with value: %d\n", node ? node->n : -1);

    return (0);
}

