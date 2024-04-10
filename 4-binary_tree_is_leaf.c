/*
* File: 4-binary_tree_is_leaf.c
* Author: Sherif Awad
*/
/* Include the header file for binary trees */
#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Function to check if a node is a leaf in a binary tree
 * @node: pointer to a node of type binary_tree_t
 * Return: 1 if node is a leaf, otherwise 0
 *			If node is NULL, return 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	/* If the node is NULL or has left or right child, return 0 */
	if (node == NULL || node->left != NULL || node->right != NULL)
		return (0);

	/* If the node is not NULL and does not have left or right child, return 1 */
	return (1);
}
