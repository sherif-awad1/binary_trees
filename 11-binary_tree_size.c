/*
* File: 11-binary_tree_size.c
* Author: Sherif Awad
*/
/* Include the header file for binary trees */
#include "binary_trees.h"

/**
 * binary_tree_size - Function to calculate the size of a binary tree
 * @tree: pointer to the root node of the binary tree that we’re working with
 * Return: size and if tree is NULL, function must return 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	/* Initialize the size of the tree to 0 */
	size_t size = 0;

	/* If the tree is not NULL */
	if (tree)
	{
		/* Increment the size for the current node */
		size += 1;

		/* Recursively add the size of the left subtree */
		size += binary_tree_size(tree->left);

		/* Recursively add the size of the right subtree */
		size += binary_tree_size(tree->right);
	}

	/* Return the size of the tree */
	return (size);
}
