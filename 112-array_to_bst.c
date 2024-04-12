/*
* File: 112-array_to_bst.c
* Author: Sherif Awad
*/
/* Include the header file for binary trees */
#include "binary_trees.h"

/**
 * array_to_bst - Converts an array of integers into a binary search tree.
 * @array: Pointer to the first element of the integer array.
 * @size: Number of elements in the array.
  * Return: Pointer to the root of the newly created binary search tree,
 *         or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *bst_root = NULL;
	size_t i, j;

	if (array == NULL)
		return (NULL);

	/* Iterate through the array elements */
	for (i = 0; i < size; i++)
	{
		/* Check if the current value already exists in the tree */
		for (j = 0; j < i; j++)
		{
			if (array[j] == array[i])
				break;
		}

		/* If the value is unique, insert it into the BST */
		if (j == i)
		{
			if (bst_insert(&bst_root, array[i]) == NULL)
				return (NULL);
		}
	}

	return (bst_root);
}
