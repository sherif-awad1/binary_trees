/*
* File: 7-binary_tree_inorder.c
* Author: Sherif Awad
*/
/* Include the header file for binary trees */
#include "binary_trees.h"

/**
 * binary_tree_inorder - Function to traverse a binary tree in inorder
 * @tree: pointer to the root node of the binary tree that you’re traversing
 * @func: function pointer points to function that takes
 *			int input and returns nothing
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	/* If the tree and function pointer are not NULL */
	if (tree && func)
	{
		/* Recursively traverse the left subtree in inorder */
		binary_tree_inorder(tree->left, func);

		/* Call the function on the value of the current node */
		func(tree->n);

		/* Recursively traverse the right subtree in inorder */
		binary_tree_inorder(tree->right, func);
	}
}
