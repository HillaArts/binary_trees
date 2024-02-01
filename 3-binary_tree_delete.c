#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree
 * @tree: pointer to the root node of the tree to delete
 * 
 * Description: Performs a post-order traversal to safely delete all nodes.
 */
void binary_tree_delete(binary_tree_t *tree)
{
    if (tree == NULL)
        return;

    /* Recursively delete left subtree */
    binary_tree_delete(tree->left);

    /* Recursively delete right subtree */
    binary_tree_delete(tree->right);

    /* Delete current node */
    free(tree);
}
