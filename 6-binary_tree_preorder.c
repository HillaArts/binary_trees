#include "binary_trees.h"

/**
 * binary_tree_preorder - goes through a binary tree using pre-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 *	The value in the node must be passed as a parameter to this function.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	return;

	func(tree->n); /* Visit the root node */
	binary_tree_preorder(tree->left, func); /* Traverse the left subtree */
	binary_tree_preorder(tree->right, func); /* Traverse the right subtree */
}
