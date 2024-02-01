#include "binary_trees.h"

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if binary tree is perfect, 0 otherwise or if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    int height, leaf_level;

    if (tree == NULL)
        return (0);

    height = binary_tree_height(tree);
    leaf_level = binary_tree_leaf_level(tree);

    return (height == leaf_level ? 1 : 0);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure height
 *
 * Return: If tree is NULL, return 0
 *         Otherwise, return the height of the tree
 */
int binary_tree_height(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    int left_height = binary_tree_height(tree->left);
    int right_height = binary_tree_height(tree->right);

    if (left_height > right_height)
        return (left_height + 1);
    else
        return (right_height + 1);
}

/**
 * binary_tree_leaf_level - Measures the level of the leaf node
 * furthest from the root
 * @tree: A pointer to the root node of the tree to measure height
 *
 * Return: Leaf node level furthest from root, or -1 if NULL
 */
int binary_tree_leaf_level(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (-1);

    if (is_leaf(tree))
        return (0);

    int left_level = binary_tree_leaf_level(tree->left);
    int right_level = binary_tree_leaf_level(tree->right);

    if (left_level > right_level)
        return (left_level + 1);
    else
        return (right_level + 1);
}

/**
 * is_leaf - Checks if a node is a leaf node in a binary tree
 * @node: A pointer to the node to check
 *
 * Return: 1 if node is a leaf, 0 otherwise
 */
int is_leaf(const binary_tree_t *node)
{
    if (node->left == NULL && node->right == NULL)
        return (1);

    return (0);
}
