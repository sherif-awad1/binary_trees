/*
* File: 3-binary_tree_delete.c
* Author: Sherif Awad
*/
/* Include the header file for binary trees */
#include "binary_trees.h"
/**
 * binary_tree_delete - Function to delete a binary tree
 * @tree: pointer to the root node of a binary tree
 */

void binary_tree_delete(binary_tree_t *tree)
{
	/* If the tree is not NULL */
	if (tree != NULL)
	{
		/* Recursively delete the left subtree */
		binary_tree_delete(tree->left);

		/* Recursively delete the right subtree */
		binary_tree_delete(tree->right);

		/* Free the memory allocated for the current node */
		free(tree);
	}
}
