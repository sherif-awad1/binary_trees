/*
* File: 1-binary_tree_insert_left.c
* Author: Sherif Awad
*/
/* Include the header file for binary trees */
#include "binary_trees.h"
/**
 * binary_tree_insert_left - Function to insert a new node as the left-child of
 *				a node in a binary tree
 * @parent: pointer to a parent node of type binary_tree_t. binary_tree_t
 * @value: the value that will be stored in the new node
 *
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	/* Declare a new node of type binary_tree_t */
	binary_tree_t *LeftNode;

	/* If the parent node is NULL, return NULL */
	if (parent == NULL)
		return (NULL);

	/* Create a new node with the given value and parent */
	LeftNode = binary_tree_node(parent, value);

	/* If memory allocation fails, return NULL */
	if (LeftNode == NULL)
		return (NULL);

	/* If the parent node already has a left child */
	if (parent->left != NULL)
	{
		/* Set left child of new node to the current left child of the parent */
		LeftNode->left = parent->left;

		/* Set the parent of the current left child of the parent to the new node */
		parent->left->parent = LeftNode;
	}

	/* Set the left child of the parent to the new node */
	parent->left = LeftNode;

	/* Return the new node */
	return (LeftNode);
}
