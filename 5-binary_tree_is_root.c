/*
* File: 5-binary_tree_is_root.c
* Author: Sherif Awad
*/
/* Include the header file for binary trees */
#include "binary_trees.h"

/**
 * binary_tree_is_root - Function to check if a node is a root in a binary tree
 * @node: pointer to a node of type binary_tree_t
 * Return: 1 if node is a leaf, otherwise 0
 *			If node is NULL, return 0
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	/* If the node is NULL or has a parent, return 0 */
	if (node == NULL || node->parent != NULL)
		return (0);

	/* If the node is not NULL and does not have a parent, return 1 */
	return (1);
}
