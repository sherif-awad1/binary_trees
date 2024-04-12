/*
* File: 110-binary_tree_is_bst.c
* Author: Sherif Awad
*/
/* Include the header file for binary trees */
#include "binary_trees.h"
#include <limits.h>

/**
 * bst_helper - Checks if a binary tree is a valid binary search tree.
 * @tree: Pointer to the root of the binary tree.
 * @min_val: Minimum allowed value for nodes in the subtree.
 * @max_val: Maximum allowed value for nodes in the subtree.
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int bst_helper(const binary_tree_t *tree, int min_val, int max_val)
{
	if (tree != NULL)
	{
		if (tree->n < min_val || tree->n > max_val)
			return (0);

		/* Recursively check left and right subtrees */
		return (bst_helper(tree->left, min_val, tree->n - 1) &&
				bst_helper(tree->right, tree->n + 1, max_val));
	}
	return (1); /* Empty tree is considered a valid BST */
}

/**
 * binary_tree_is_bst - Determines if binary tree is valid binary search tree
 * @tree: Pointer to the root of the binary tree.
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Check if the tree is a valid BST within the entire range */
	return (bst_helper(tree, INT_MIN, INT_MAX));
}
