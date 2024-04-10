/*
* File: 12-binary_tree_leaves.c
* Author: Sherif Awad
*/
/* Include the header file for binary trees */
#include "binary_trees.h"

/**
 * binary_tree_leaves - Function to count number of leaves in a binary tree
 * @tree: pointer to the root node of the binary tree that we’re working with
 * Return: count of leaves and if tree is NULL return 0
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	/* Initialize the count of leaves to 0 */
	size_t CountOfLaves = 0;

	/* If the tree is not NULL */
	if (tree)
	{
		/* If node is leaf ,increment by 1, otherwise add 0 */
		CountOfLaves += (!tree->left && !tree->right) ? 1 : 0;

		/* Recursively add the number of leaves in the left subtree */
		CountOfLaves += binary_tree_leaves(tree->left);

		/* Recursively add the number of leaves in the right subtree */
		CountOfLaves += binary_tree_leaves(tree->right);
	}

	/* Return the count of leaves */
	return (CountOfLaves);
}
