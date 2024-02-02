#include "binary_trees.h"

/**
 * depth - Measures the depth of a binary tree
 * @tree: pointer to the root node of the tree to measure the depth
 *
 * Return: The depth of the tree
 */
static int depth(const binary_tree_t *tree)
{
    int d = 0;
    while (tree)
    {
        d++;
        tree = tree->left;
    }
    return d;
}

/**
 * is_perfect - helper function to check if the tree is perfect
 * @tree: pointer to the root node of the tree
 * @d: depth of the tree
 * @level: level of the current node
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
static int is_perfect(const binary_tree_t *tree, int d, int level)
{
    if (tree == NULL)
        return 1;

    // If leaf node, check if its level matches the depth of the tree
    if (tree->left == NULL && tree->right == NULL)
        return (d == level + 1);

    // If internal node and one child is missing
    if (tree->left == NULL || tree->right == NULL)
        return 0;

    // Check recursively for every node
    return is_perfect(tree->left, d, level + 1) && is_perfect(tree->right, d, level + 1);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    int d = depth(tree);
    return is_perfect(tree, d, 0);
}

