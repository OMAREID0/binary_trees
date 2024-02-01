#include "binary_trees.h"

int binary_tree_is_perfect(const binary_tree_t *tree)
{
  int height = 0;

  if (tree == NULL)
    return 0;

  /* Calculate tree height recursively */
  if (tree->left)  
  {
    int left_height = 1 + binary_tree_is_perfect(tree->left);
    height = left_height;
  }

  if (tree->right) 
  {
    int right_height = 1 + binary_tree_is_perfect(tree->right);
    height = (height >= right_height) ? height : right_height;
  }

  /* Check if leaf node */
  if (tree->left == NULL && tree->right == NULL)
    return 0;

  /* Check if both subtrees are perfect */
  int left_perfect = binary_tree_is_perfect(tree->left); 
  int right_perfect = binary_tree_is_perfect(tree->right);

  if (left_perfect == height - 1 && right_perfect == height - 1)
    return height;

  /* Tree is not perfect */
  return 0;
}
