#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_delete - Deletes an entire binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Description: If tree is NULL, do nothing.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;

	/* Delete left subtree */
	binary_tree_delete(tree->left);

	/* Delete right subtree */
	binary_tree_delete(tree->right);

	/* Free current node */
	free(tree);
}
