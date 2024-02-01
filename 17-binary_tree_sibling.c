#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds sibling node of input node
 * @node: Pointer to the node to find sibling
 *
 * Return: Pointer to sibling node, NULL if no sibling or
 * node is invalid.
*/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
  if (node == NULL || node->parent == NULL)
    return (NULL);

  if (node->parent->left == node)  
    return (node->parent->right);

  return (node->parent->left); 
}
