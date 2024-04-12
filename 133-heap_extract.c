/*
* File: 133-heap_extract.c
* Author: Sherif Awad
*/
/* Include the necessary header files */
#include "binary_trees.h"
#include <stdlib.h>

/**
 * calculate_height - Calculates the height of a binary tree
 * @root: Pointer to the root node of the tree
 * Return: The height of the tree
 */
size_t calculate_height(const heap_t *root)
{
	size_t left_height = 0;	 /* Height of the left subtree */
	size_t right_height = 0; /* Height of the right subtree */

	/* Base case: if root is NULL, height is 0 */
	if (!root)
		return (0);

	/* Calculate height of left subtree if it exists */
	if (root->left)
		left_height = 1 + calculate_height(root->left);

	/* Calculate height of right subtree if it exists */
	if (root->right)
		right_height = 1 + calculate_height(root->right);

	/* Return the greater of the two heights */
	if (left_height > right_height)
		return (left_height);
	return (right_height);
}

/**
 * compute_size - Calculates the size of a binary tree
 * @root: Pointer to the root node of the tree
 * Return: The size of the tree
 */
size_t compute_size(const binary_tree_t *root)
{
	size_t left_size = 0;  /* Size of the left subtree */
	size_t right_size = 0; /* Size of the right subtree */

	/* Base case: if root is NULL, size is 0 */
	if (!root)
		return (0);

	/* Recursively calculate the size of the left subtree */
	if (root->left)
		left_size = 1 + compute_size(root->left);

	/* Recursively calculate the size of the right subtree */
	if (root->right)
		right_size = 1 + compute_size(root->right);

	/* Return the total size of the tree */
	return (left_size + right_size);
}

/**
 * preorder_traverse - Traverses tree in preorder to find the node
 * @root: Pointer to the root node of the tree
 * @target_node: Double pointer to update with the found node
 * @target_height: The height at which to find the node
 */
void preorder_traverse(heap_t *root, heap_t **target_node,
		size_t target_height)
{
	/* Base case: if root is NULL, return */
	if (!root)
		return;

	/* If the desired height is reached, update the target_node pointer */
	if (!target_height)
		*target_node = root;
	target_height--;

	/* Recursively traverse the left and right subtrees */
	preorder_traverse(root->left, target_node, target_height);
	preorder_traverse(root->right, target_node, target_height);
}

/**
 * reheapify - Restores the max heap property of a binary heap
 * @root: Pointer to the root node of the heap
 */
void reheapify(heap_t *root)
{
	int swap_value;
	heap_t *current_node, *child_node; /* Pointers to traverse the heap */

	/* Base case: if root is NULL, return */
	if (!root)
		return;

	current_node = root;

	/* Loop to restore the heap property */
	while (1)
	{
		/* If there is no left child, break the loop */
		if (!current_node->left)
			break;
		/* If there is no right child, use the left child */
		if (!current_node->right)
			child_node = current_node->left;
		else
		{
			/* Choose the child with the greater value */
			if (current_node->left->n > current_node->right->n)
				child_node = current_node->left;
			else
				child_node = current_node->right;
		}
		/* If the current node's value is greater, break the loop */
		if (current_node->n > child_node->n)
			break;
		/* Swap the values of the current node and the chosen child */
		swap_value = current_node->n;
		current_node->n = child_node->n;
		child_node->n = swap_value;
		/* Move to the next node down the heap */
		current_node = child_node;
	}
}

/**
 * heap_extract - Extracts the root value of a max heap
 * @root: Double pointer to the root node of the heap
 * Return: The value of the extracted root
 */
int heap_extract(heap_t **root)
{
	int extracted_value;
	heap_t *root_node, *last_node; /* Pointers to traverse the heap */

	/* Base case: if root or *root is NULL, return 0 */
	if (!root || !*root)
		return (0);

	root_node = *root;
	extracted_value = root_node->n; /* Store the value of the root node */

	/* If the root has no children, free it and set root to NULL */
	if (!root_node->left && !root_node->right)
	{
		*root = NULL;
		free(root_node);
		return (extracted_value);
	}

	/* Find the last node in the heap */
	preorder_traverse(root_node, &last_node, calculate_height(root_node));

	/* Replace the root's value with the last node's value */
	root_node->n = last_node->n;
	/* Remove the last node from the heap */
	if (last_node->parent->right)
		last_node->parent->right = NULL;
	else
		last_node->parent->left = NULL;
	free(last_node);		  /* Free the last node */
	reheapify(root_node);	  /* Restore the heap property */
	*root = root_node;		  /* Update the root pointer */
	return (extracted_value); /* Return the extracted value */
}
