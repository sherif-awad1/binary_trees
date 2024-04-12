/*
* File: 113-bst_search.c
* Author: Sherif Awad
*/
/* Include the header file for binary trees */
#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a binary search tree.
 * @tree: Pointer to the root of the binary search tree.
 * @value: Value to search for.
 * Return: Pointer to the node containing the value, or NULL if not found.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		/* If the current node contains the value, return it */
		if (tree->n == value)
			return ((bst_t *)tree);

		/* Search in the left subtree if value is less than current node */
		if (tree->n > value)
			return (bst_search(tree->left, value));

		/* Search in the right subtree if value is greater than current node */
		return (bst_search(tree->right, value));
	}

	return (NULL); /* Value not found or invalid input */
}

