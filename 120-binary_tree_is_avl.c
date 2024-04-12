/*
* File: 120-binary_tree_is_avl.c
* Author: Sherif Awad
*/
/* Include the header file for binary trees */
#include "binary_trees.h"
#include "limits.h"

/**
 * treeHeight - Calculates the height of a binary tree.
 * @tree: Pointer to the root of the binary tree.
 * Return: Height of the tree.
 */
size_t treeHeight(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t leftHeight = 0, rightHeight = 0;

		leftHeight = tree->left ? 1 + treeHeight(tree->left) : 1;
		rightHeight = tree->right ? 1 + treeHeight(tree->right) : 1;
		return ((leftHeight > rightHeight) ? leftHeight : rightHeight);
	}
	return (0);
}

/**
 * isAVLRecursive - Checks if a binary tree is an AVL tree.
 * @node: Pointer to the current node being checked.
 * @minValue: Minimum allowed value for nodes in the subtree.
 * @maxValue: Maximum allowed value for nodes in the subtree.
 * Return: 1 if the tree is an AVL tree, 0 otherwise.
 */
int isAVLRecursive(const binary_tree_t *node, int minValue, int maxValue)
{
	size_t leftHeight, rightHeight, heightDifference;

	if (node != NULL)
	{
		if (node->n < minValue || node->n > maxValue)
			return (0);

		leftHeight = treeHeight(node->left);
		rightHeight = treeHeight(node->right);
		heightDifference = (leftHeight > rightHeight) ?
			leftHeight - rightHeight : rightHeight - leftHeight;

		if (heightDifference > 1)
			return (0);

		return (isAVLRecursive(node->left, minValue, node->n - 1) &&
				isAVLRecursive(node->right, node->n + 1, maxValue));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Determines if a binary tree is an AVL tree.
 * @tree: Pointer to the root of the binary tree.
 * Return: 1 if the tree is an AVL tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (isAVLRecursive(tree, INT_MIN, INT_MAX));
}

