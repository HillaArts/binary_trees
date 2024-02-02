#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder - goes through a binary tree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node's value
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    const binary_tree_t *queue[1024];
    int start = 0, end = 0;

    if (tree == NULL || func == NULL)
        return;

    queue[end++] = tree;

    while (start < end)
    {
        const binary_tree_t *current = queue[start++];

        func(current->n);

        if (current->left != NULL)
            queue[end++] = current->left;

        if (current->right != NULL)
            queue[end++] = current->right;
    }
}
