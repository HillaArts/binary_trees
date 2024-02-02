#include "binary_trees.h"
#include <stdlib.h>

/**
 * depth - Measures the depth of a node in a binary tree
 * @node: pointer to the node to measure the depth
 *
 * Return: the depth of the node
 */
size_t depth(const binary_tree_t *node)
{
    size_t d = 0;
    while (node != NULL)
    {
        d++;
        node = node->parent;
    }
    return d;
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node of the two given nodes,
 * or NULL if no common ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    size_t depth_first = depth(first), depth_second = depth(second);
    const binary_tree_t *deeper = depth_first > depth_second ? first : second;
    const binary_tree_t *shallower = depth_first > depth_second ? second : first;
    size_t diff = depth_first > depth_second ? depth_first - depth_second : depth_second - depth_first;

    /* Align both nodes at the same depth */
    while (diff > 0)
    {
        deeper = deeper->parent;
        diff--;
    }

    /* Find the common ancestor */
    while (deeper != NULL && shallower != NULL && deeper != shallower)
    {
        deeper = deeper->parent;
        shallower = shallower->parent;
    }

    return (binary_tree_t *)(deeper && shallower ? deeper : NULL);
}

