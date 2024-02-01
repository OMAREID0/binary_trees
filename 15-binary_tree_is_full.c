#include "binary_trees.h"

/**
 * is_full_recursive - Checks if a binary tree is full recursively
 * @tree: Pointer to root node of tree
 *
 * Return: 0 if tree is not full, 1 if full
*/
int is_full_recursive(const binary_tree_t *tree)
{
	int left_full, right_full;

	if (tree == NULL)
		return (1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	left_full = is_full_recursive(tree->left);
	right_full = is_full_recursive(tree->right);

	if (left_full == 0 || right_full == 0)
		return (0);

	return (1);
}

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to root node
 *
 * Return: 0 if tree is NULL or not full, 1 if full
*/ 
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_full_recursive(tree));
}
