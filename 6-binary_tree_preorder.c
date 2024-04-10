/*
* File: 6-binary_tree_preorder.c
* Author: Sherif Awad
*/
/* Include the header file for binary trees */
#include "binary_trees.h"
/**
 * binary_tree_preorder - Function to traverse a binary tree in preorder
 * @tree: pointer to the root node of the binary tree that we’re traversing
 * @func: function pointer points to function that takes
 *			int input and returns nothing
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	/* If the tree and function pointer are not NULL */
	if (tree && func)
	{
		/* Call the function on the value of the current node */
		func(tree->n);

		/* Recursively traverse the left subtree in preorder */
		binary_tree_preorder(tree->left, func);

		/* Recursively traverse the right subtree in preorder */
		binary_tree_preorder(tree->right, func);
	}
}
