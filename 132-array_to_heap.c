/*
* File: 132-array_to_heap.c
* Author: Sherif Awad
*/
/* Include the header file for AVL tree operations */
#include "binary_trees.h"

/**
 * array_to_heap - Converts an array of integers into a Max Binary Heap
 * @array: Pointer to the first element of the array
 * @size: The number of elements in the array
 * Return: A pointer to the root node of the created Max Binary Heap
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int i;
	heap_t *root = NULL;

	/* Iterate over each element in the array */
	for (i = 0; i < size; i++)
	{
		/* Insert the current element into the heap */
		heap_insert(&root, array[i]);
	}

	/* Return the pointer to the root of the heap */
	return (root);
}
