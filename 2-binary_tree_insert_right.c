#include "binary_trees.h"
/**
 *binary_tree_insert_right - inserts a node as the right-child of another node.
 *@parent - parent of the node
 *@value: stored data.
 *
 *Returns: the adress of the created node.
 *Otherwise: Null if failed.
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


