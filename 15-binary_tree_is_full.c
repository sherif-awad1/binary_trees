/*
* File: 15-binary_tree_is_full.c
* Author: Sherif Awad
*/
/* Include the header file for binary trees */
#include "binary_trees.h"

/**
 * is_binary_tree_full - Function to check if a binary tree is full
 * @tree: pointer to the root node of the binary tree that we’re working with
 * Return: If tree is not full, 0 otherwise, 1.
 */
int is_binary_tree_full(const binary_tree_t *tree)
{
	/* If the tree is not NULL */
	if (tree != NULL)
	{
		/* If node has one child or L or R subtree is not full, return 0 */
		if ((tree->left != NULL && tree->right == NULL) ||
			(tree->left == NULL && tree->right != NULL) ||
			is_binary_tree_full(tree->left) == 0 ||
			is_binary_tree_full(tree->right) == 0)
			return (0);
	}

	/* If the tree is NULL or the current node is a leaf node, return 1 */
	return (1);
}

/**
 * binary_tree_is_full - Function to check if a binary tree is full
 * @tree: pointer to the root node of the binary tree that we’re working with
 * Return: If tree NULL, return 0 Otherwise, call function is_binary_tree_full.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	/* If the tree is NULL, return 0 */
	if (tree == NULL)
		return (0);

	/* Call function is_binary_tree_full tree as argument and return its*/
	return (is_binary_tree_full(tree));
}
