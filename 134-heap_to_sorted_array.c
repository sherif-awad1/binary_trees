/*
* File: 134-heap_to_sorted_array.c
* Author: Sherif Awad
*/

/* Include the header file for AVL tree operations */
#include "binary_trees.h"

/**
 * calculate_total_nodes - Calculates the total number of nodes in a binary tr
 * @tree: Pointer to the root node of the tree
 * Return: The total number of nodes in the tree
 */
size_t calculate_total_nodes(const binary_tree_t *tree)
{
	size_t left_subtree_size = 0;  /* Size of the left subtree */
	size_t right_subtree_size = 0; /* Size of the right subtree */

	/* Base case: If the tree is NULL, return 0 */
	if (!tree)
		return (0);

	/* Recursively calculate the size of the left subtree, if it exists */
	if (tree->left)
		left_subtree_size = 1 + calculate_total_nodes(tree->left);

	/* Recursively calculate the size of the right subtree, if it exists */
	if (tree->right)
		right_subtree_size = 1 + calculate_total_nodes(tree->right);

	/* Return the sum of the sizes of both subtrees */
	return (left_subtree_size + right_subtree_size);
}

/**
 * heap_to_sorted_array - Converts a max heap to a sorted array
 * @heap: Pointer to the root node of the max heap
 * @array_size: Pointer to store the size of the resulting sorted array
 * Return: pointer to array containing the heap's elements in sorted order
 */
int *heap_to_sorted_array(heap_t *heap, size_t *array_size)
{
	int index;
	int *sorted_elements = NULL;

	/* If the heap or array_size pointer is NULL, return NULL */
	if (!heap || !array_size)
		return (NULL);

	/* Calculate size of heap (+1 for root) and allocate memory for array */
	*array_size = calculate_total_nodes(heap) + 1;
	sorted_elements = malloc(sizeof(int) * (*array_size));

	/* If memory allocation fails, return NULL */
	if (!sorted_elements)
		return (NULL);

	/* Extract elements from heap and insert into array in sorted order */
	for (index = 0; heap; index++)
		sorted_elements[index] = heap_extract(&heap);

	/* Return the pointer to the sorted array */
	return (sorted_elements);
}
