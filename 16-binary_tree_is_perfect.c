#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure
 *
 * Return: height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);

	return (right_height + 1);
}

/**
 * _binary_tree_is_perfect - checks if tree is perfect recursively
 * @tree: pointer to the node
 * @height: height of the tree
 * @level: current level
 *
 * Return: 1 if perfect, 0 otherwise
 */
int _binary_tree_is_perfect(const binary_tree_t *tree, size_t height,
		size_t level)
{
	if (tree == NULL)
		return (0);

	/* Leaf */
	if (tree->left == NULL && tree->right == NULL)
		return (height == level);

	/* If one child is NULL and other is not */
	if (tree->left == NULL || tree->right == NULL)
		return (0);

	/* Check subtrees */
	return (_binary_tree_is_perfect(tree->left, height, level + 1) &&
			_binary_tree_is_perfect(tree->right, height, level + 1));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);

	return (_binary_tree_is_perfect(tree, height, 0));
}
