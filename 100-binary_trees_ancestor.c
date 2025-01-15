#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * 
 * Return: pointer to the lowest common ancestor or NULL if no common ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    const binary_tree_t *ancestor1 = first;

    /* If either is NULL, return NULL */
    if (!first || !second)
        return (NULL);

    /* Traverse both nodes upwards */
    while (ancestor1)
    {
        const binary_tree_t *temp = second;
        /* Check if the second node is in the first node's ancestor path */
        while (temp)
        {
            if (temp == ancestor1)
                return (binary_tree_t *)ancestor1;
            temp = temp->parent;
        }
        ancestor1 = ancestor1->parent;
    }

    /* No common ancestor found */
    return (NULL);
}

