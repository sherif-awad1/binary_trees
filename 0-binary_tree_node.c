/*
* File: 0-binary_tree_node.c
* Author: Sherif Awad
*/

/* Include the header file for binary trees */
#include "binary_trees.h"

/**
 * binary_tree_node - Function to create a new node in a binary tree
 * @parent: a pointer to a parent node of type binary_tree_t
 * @value: the value that will be stored in the new node
 * Return: pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    /* Declare a new node */
	binary_tree_t *NewNode;

    /* Allocate memory for the new node */
	NewNode = malloc(sizeof(binary_tree_t));

    /* If memory allocation fails, return NULL */
	if (NewNode == NULL)
		return (NULL);

    /* Assign the input value to the new node */
	NewNode->n = value;

    /* Assign the input parent to the new node */
	NewNode->parent = parent;

    /* Initialize the left child of the new node to NULL */
	NewNode->left = NULL;

    /* Initialize the right child of the new node to NULL */
	NewNode->right = NULL;

    /* Return the new node */
	return (NewNode);
}

