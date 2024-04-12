/*
* File: 122-array_to_avl.c
* Author: Sherif Awad
*/
/* Include the header file for AVL tree operations */
#include "binary_trees.h"

/**
 * array_to_avl - Convert an array to an AVL tree
 * @array: pointer to the first element of the array
 * @size: the number of elements in the array
 * Return: pointer to the root node of the created AVL tree
 *         If the array is NULL, return NULL
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL; /* Initialize the tree */
	size_t i, j;

	/* If the input array is NULL, there's nothing to convert */
	if (array == NULL)
		return (NULL);

	/* Iterate over each element in the array */
	for (i = 0; i < size; i++)
	{
		/* Check for duplicate values in the array up to the current element */
		for (j = 0; j < i; j++)
		{
			/* If a duplicate is found, break from the inner loop */
			if (array[j] == array[i])
				break;
		}
		/* If no duplicates were found, j will equal i */
		if (j == i)
		{
			/* Insert the unique value into the AVL tree */
			if (avl_insert(&tree, array[i]) == NULL)
				/* If insertion fails, return NULL */
				return (NULL);
		}
	}

	/* Return the pointer to the root node of the AVL tree */
	return (tree);
}
