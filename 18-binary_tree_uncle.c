#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds uncle node of given node
 * @node: Pointer to node to find uncle
 * 
 * Return: Pointer to uncle node, NULL if node has no uncle
 * or is invalid.
*/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
  if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
    return (NULL);

  if (node->parent->parent->left == node->parent)
    return (node->parent->parent->right);

  return (node->parent->parent->left);
}
