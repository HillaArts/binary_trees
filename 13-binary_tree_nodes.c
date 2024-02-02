#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least one child in a binary tree
 * @tree: pointer to the root node of the tree to count the number of nodes
 *
 * Return: number of nodes with at least one child, 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    /* A node is considered a 'parent' node if it has at least one child. */
    if (tree->left || tree->right)
    {
        /* Recursively count the nodes in both subtrees and add 1 for the current node. */
        return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
    }
    
    /* If a node doesn't have any children, it doesn't contribute to the count. */
    return (0);
}
