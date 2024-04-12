/*
* File: 103-binary_tree_rotate_left.c
* Author: Sherif Awad
*/

/* Include the header file for binary trees */
#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Function to perform left-rotation on binary tree
 * @root: pointer to the root of the binary tree
 * Return: Pointer to the new root of the binary tree after rotation
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *root)
{
	binary_tree_t *pivot_node, *temp_node;

	/* If the root or its right child is NULL, return NULL */
	if (root == NULL || root->right == NULL)
		return (NULL);

	/* Pivot node is the right child of the root */
	pivot_node = root->right;
	/* Temp node is the left child of the pivot node */
	temp_node = pivot_node->left;
	/* Make the root the left child of the pivot node */
	pivot_node->left = root;
	/* Make the temp node the right child of the root */
	root->right = temp_node;
	/* Update the parent of the temp node */
	if (temp_node != NULL)
		temp_node->parent = root;
	/* Update the parent of the root */
	temp_node = root->parent;
	root->parent = pivot_node;
	/* Update the parent of the pivot node */
	pivot_node->parent = temp_node;
	/* Update the child of the temp node */
	if (temp_node != NULL)
	{
		if (temp_node->left == root)
			temp_node->left = pivot_node;
		else
			temp_node->right = pivot_node;
	}

	/* Return the new root of the binary tree */
	return (pivot_node);
}
