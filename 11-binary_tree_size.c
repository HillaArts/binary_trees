#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 *
 * Return: the size of the tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    /* Calculate the size of the left and right subtrees, then add 1 (for the root) */
    return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
