#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another node
 * @parent: pointer to the node to insert the right child in
 * @value: value to store in the new node
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node;

    if (!parent)
        return (NULL);

    new_node = malloc(sizeof(binary_tree_t));
    if (!new_node)
        return (NULL);

    new_node->n = value;
    new_node->parent = parent;
    new_node->left = NULL; /* New node has no left child initially */
    new_node->right = parent->right; /* New node's right child is parent's current right child */

    if (parent->right != NULL)
        parent->right->parent = new_node; /* Set the parent of the old right child to new node */

    parent->right = new_node; /* Set the parent's right child to new node */

    return (new_node);
}
