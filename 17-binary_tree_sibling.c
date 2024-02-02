#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: pointer to the node to find the sibling
 *
 * Return: pointer to the sibling node, NULL if node is NULL or has no sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
    if (node == NULL || node->parent == NULL)
        return NULL;

    /* Check if node is the left child of its parent */
    if (node->parent->left == node)
    {
        /* Return the right sibling if it exists */
        return node->parent->right;
    }
    else
    {
        /* Return the left sibling if it exists */
        return node->parent->left;
    }
}
