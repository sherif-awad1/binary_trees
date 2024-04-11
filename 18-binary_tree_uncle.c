/*
* File: 18-binary_tree_uncle.c
* Author: Sherif Awad
*/
/* Including the binary_trees header file */
#include "binary_trees.h"

/**
 * binary_tree_uncle - Function to find the uncle of a node in a binary tree
 * @node: pointer to the node whose uncle we’re finding
 * Return: Pointer to the uncle node if it exists, NULL otherwise.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	/* If node NULL, node's parent is NULL node's gp is NULL, return NULL */
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	/* If node P is Lchild of GP, return Rchild of the GP */
	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);

	/* If node parent is RChild of its GP return Lchild of the GP uncle node) */
	return (node->parent->parent->left);
}
