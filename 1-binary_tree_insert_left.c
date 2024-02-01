#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node.
 * @parent: pointer to the parent of the noe.
 * @value: value to store.
 *
 * @Return: Address of the created node.
 *         Otherwise, NULL if failed.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (!parent)
		return (NULL);

	new = binary_tree_node(parent, value);

	if (!new)
		return (NULL);

	if (parent->left)
	{
		new->left = parent->left;
		parent->left->parent = new;
	}
	parent->left = new;
	return (new);
}
