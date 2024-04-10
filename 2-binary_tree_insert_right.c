/*
* File: 2-binary_tree_insert_right.c
* Author: Sherif Awad
*/
/* Include the header file for binary trees */
#include "binary_trees.h"

/**
 * binary_tree_insert_right - Function to insert new node as
 *				right-child of node in binary tree
 * @parent: pointer to a parent node of type binary_tree_t. binary_tree_t
 * @value: the value that will be stored in the new node
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	/* Declare a new node of type binary_tree_t */
	binary_tree_t *RightNode;

	/* If the parent node is NULL, return NULL */
	if (parent == NULL)
		return (NULL);

	/* Create a new node with the given value and parent */
	RightNode = binary_tree_node(parent, value);

	/* If memory allocation fails, return NULL */
	if (RightNode == NULL)
		return (NULL);

	/* If the parent node already has a right child */
	if (parent->right != NULL)
	{
		/* Set right child of new node to the current right child of the parent */
		RightNode->right = parent->right;

		/* Set the parent of the current right child of the parent to the new node */
		parent->right->parent = RightNode;
	}

	/* Set the right child of the parent to the new node */
	parent->right = RightNode;

	/* Return the new node */
	return (RightNode);
}
