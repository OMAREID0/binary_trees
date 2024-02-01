#include "binary_trees.h"

/**
 * binary_tree_balance - Calculates balance factor of a binary tree
 * @tree: Pointer to root node of tree
 *
 * Return: 0 if tree is NULL, else difference in height of left
 * and right subtrees
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (left_height - right_height);
}

/**
 * binary_tree_height - Measures height of a binary tree
 * @tree: Pointer to root node
 *
 * Return: 0 if tree is NULL, else height of tree
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}
