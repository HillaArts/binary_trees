#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node's parent
 * @node: pointer to the node to find the sibling of its parent
 *
 * Return: pointer to the sibling node, NULL if node or its parent is NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
    if (node == NULL || node->parent == NULL)
        return NULL;

    binary_tree_t *parent = node->parent;

    if (parent->parent == NULL)
        return NULL;

    if (parent->parent->left == parent)
        return parent->parent->right;
    else
        return parent->parent->left;
}

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node to find the uncle
 *
 * Return: pointer to the uncle node, NULL if node is NULL or has no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
    return binary_tree_sibling(node);
}
