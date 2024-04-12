/*
* File: 130-binary_tree_is_heap.c
* Author: Sherif Awad
*/
/* Include the header file for AVL tree operations */
#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"


/**
 * validateMaxHeap - Validates that a binary tree follows max-heap properties
 * @node: Pointer to the root node of the tree to validate
 * Return: 1 if node follows max-heap properties, 0 otherwise
 */
int validateMaxHeap(const binary_tree_t *node)
{
	int leftValid = 1, rightValid = 1;

	/* Base case: If the node is NULL, it's considered valid */
	if (!node)
		return (1);
	/* If the node is a leaf, it's valid */
	if (!node->left && !node->right)
		return (1);
	/* Validate the left subtree */
	if (node->left)
	{
		/* If the left child is greater than the node, it's not valid */
		if (node->n <= node->left->n)
			return (0);
		/* Recursively validate the left subtree */
		leftValid = validateMaxHeap(node->left);
	}
	/* Validate the right subtree */
	if (node->right)
	{
		/* If the right child is greater than the node, it's not valid */
		if (node->n <= node->right->n)
			return (0);
		/* Recursively validate the right subtree */
		rightValid = validateMaxHeap(node->right);
	}
	/* Return true only if both subtrees are valid */
	return (leftValid && rightValid);
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a complete max-heap
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a complete max-heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int isComplete; /* Variable to store result of completeness check */

	/* Base case: If the tree is NULL, it's not a heap */
	if (!tree)
		return (0);

	/* Check if the tree is complete */
	isComplete = binary_tree_is_complete(tree);
	/* If the tree is not complete, it's not a heap */
	if (!isComplete)
		return (0);
	/* Check if the tree is a max-heap */
	return (validateMaxHeap(tree));
}
