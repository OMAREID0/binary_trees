#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right child of parent.
 * @parent: Pointer to the parent node.
 * @value: Value to be stored in the new node.
 *
 * Return: Address of the created node.
 *         Otherwise, NULL if failed.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new = binary_tree_node(parent, value);

	if (!parent || !new)
		return (NULL);

	if (parent->right)
	{
		new->right = parent->right;
		parent->right->parent = new;
	}
	parent->right = new;
	return (new);
}


