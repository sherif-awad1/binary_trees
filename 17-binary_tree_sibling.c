/*
* File: 17-binary_tree_sibling.c
* Author: Sherif Awad
*/

/* Including the binary_trees header file */
#include "binary_trees.h"

/**
 * binary_tree_sibling - Function to find sibling of a node in a binary tree
 * @node: pointer to the node whose sibling we’re finding
 * Return: Pointer to the sibling node if it exists, NULL otherwise.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	/* If the node is NULL or the node's parent is NULL, return NULL */
	if (node == NULL || node->parent == NULL)
		return (NULL);

	/* If the node Lchild of it parent, return Rchild of the parent) */
	if (node->parent->left == node)
		return (node->parent->right);

	/* If the node is Rchild of its parent, return Lchild of the parent */
	return (node->parent->left);
}

