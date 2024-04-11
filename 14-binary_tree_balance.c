/*
* File: 14-binary_tree_balance.c
* Author: Sherif Awad
*/
/* Include the header file for binary trees */
#include "binary_trees.h"

/**
 * binary_tree_balance - Function to calculate balance factor of a binary tree
 * @tree: pointer to the root node of the binary tree that we’re working with
 * Return: balance factor and if tree is NULL return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	/* If the tree is not NULL */
	if (tree)
	{
		/* Return difference between the heights of the left and right subtrees */
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
	}

	/* If the tree is NULL, return 0 */
	return (0);
}
/**
 * binary_tree_height - Function to calculate the height of a binary tree
 * @tree: pointer to the root node of the binary tree that we’re working with
 * Return: haight and if tree is NULL, function must return 0
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	/* If the tree is not NULL */
	if (tree)
	{
		/* Declare variables to store the heights of the left and right subtrees */
		size_t l = 0, r = 0;
		/* Calculate height of left subtree if it exists, otherwise set it to 0 */
		l = tree->left ? 1 + binary_tree_height(tree->left) : 0;

		/* Calculate height of right subtree if it exists, otherwise set it to 0 */
		r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		/* Return the greater of the two heights */
		return ((l > r) ? l : r);
	}

	/* If the tree is NULL, return 0 */
	return (0);
}
