/*
* File: 8-binary_tree_postorder.c
* Author: Sherif Awad
*/
/* Include the header file for binary trees */
#include "binary_trees.h"

/**
 * binary_tree_postorder - Function to traverse a binary tree in postorder
 * @tree: pointer to the root node of the binary tree that you’re traversing
 * @func: function pointer points to function that takes
 *			int input and returns nothing
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	/* If the tree and function pointer are not NULL */
	if (tree && func)
	{
		/* Recursively traverse the left subtree in postorder */
		binary_tree_postorder(tree->left, func);

		/* Recursively traverse the right subtree in postorder */
		binary_tree_postorder(tree->right, func);

		/* Call the function on the value of the current node */
		func(tree->n);
	}
}
