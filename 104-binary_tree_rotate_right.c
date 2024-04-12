/*
* File: 104-binary_tree_rotate_right.c
* Author: Sherif Awad
*/
/* Include the header file for binary trees */
#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Function to perform right-rotation on binary tree
 * @root: pointer to the root of the binary tree
 * Return: Pointer to the new root of the binary tree after rotation
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *root)
{
	binary_tree_t *pivot_node, *temp_node;

	/* If the root or its left child is NULL, return NULL */
	if (root == NULL || root->left == NULL)
		return (NULL);

	/* Pivot node is the left child of the root */
	pivot_node = root->left;
	/* Temp node is the right child of the pivot node */
	temp_node = pivot_node->right;
	/* Make the root the right child of the pivot node */
	pivot_node->right = root;
	/* Make the temp node the left child of the root */
	root->left = temp_node;
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
