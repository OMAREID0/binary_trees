#include "binary_trees.h"

/**
 * is_leaf - Checks if node is leaf in binary tree
 * @node: Pointer to node to check
 *
 * Return: 1 if node is leaf, 0 otherwise
*/
unsigned char is_leaf(const binary_tree_t *node)  
{
	if (node->left == NULL && node->right == NULL)
		return (1);
	else
		return (0);
}

/**
 * depth - Measures depth of node in binary tree 
 * @tree: Pointer to node to measure depth
 *
 * Return: Depth of node
*/
size_t depth(const binary_tree_t *tree)
{
	if (tree->parent != NULL)
		return (1 + depth(tree->parent));
	else 
		return (0);
}

/**
 * get_leaf - Finds leaf node in binary tree
 * @tree: Pointer to root node
 *
 * Return: Pointer to first leaf node encountered
*/
const binary_tree_t *_get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);

	if (tree->left)
		return (get_leaf(tree->left));
	else
		return (get_leaf(tree->right));
}

/**
 * is_perfect_recursive - Checks binary tree is perfect recursively 
 * @tree: Pointer to root node
 * @leaf_depth: Depth of leaf node
 * @level: Current level
 *
 * Return: 1 if perfect, 0 if not
*/
int is_perfect_recursive(const binary_tree_t *tree, 
			size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
		is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/** 
 * binary_tree_is_perfect - Checks if binary tree is perfect
 * @tree: Pointer to root node
 * 
 * Return: 1 if perfect, 0 if NULL or not perfect
*/
int binary_tree_is_perfect(const binary_tree_t *tree) 
{
	if (tree == NULL)
		return (0);

	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0)); 
}
