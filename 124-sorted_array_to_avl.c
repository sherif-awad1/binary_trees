/*
* File: 124-sorted_array_to_avl.c
* Author: Sherif Awad
*/
/* Include the header file for AVL tree operations */
#include "binary_trees.h"

/**
 * buildSubTree - Recursively builds a subtree from a sorted array
 * @subTreeNode: Double pointer to the current node in the AVL tree
 * @sortedArray: Pointer to the first element of the sorted array
 * @subArraySize: The number of elements in the current sub-array
 * @subTreeMode: Indicator of whether to insert left (1) or right (2) subtree
 */
void buildSubTree(avl_t **subTreeNode, int *sortedArray,
		size_t subArraySize, int subTreeMode)
{
	size_t middleIndex;

	/* Base case: If there are no elements, return */
	if (subArraySize == 0)
		return;

	/* Find the middle index of the sub-array */
	middleIndex = (subArraySize / 2);
	/* Adjust the middle index if the sub-array size is even */
	middleIndex = (subArraySize % 2 == 0) ? middleIndex - 1 : middleIndex;

	/* If we are building the left subtree */
	if (subTreeMode == 1)
	{
		/* Create new node at left child with middle value of the sub-array */
		(*subTreeNode)->left = binary_tree_node(*subTreeNode,
				sortedArray[middleIndex]);
		/* Recursively build left subtree using left half of the sub-array */
		buildSubTree(&((*subTreeNode)->left), sortedArray, middleIndex, 1);
		/* Recursively build right subtree using right half of the sub-array */
		buildSubTree(&((*subTreeNode)->left), sortedArray + middleIndex + 1,
				(subArraySize - 1 - middleIndex), 2);
	}
	/* If we are building the right subtree */
	else
	{
		/* Create new node at right child with middle value of the sub-array */
		(*subTreeNode)->right = binary_tree_node(*subTreeNode,
				sortedArray[middleIndex]);
		/* Recursively build the left subtree using the left half of the sub-array */
		buildSubTree(&((*subTreeNode)->right), sortedArray, middleIndex, 1);
		/* Recursively build right subtree using the right half of the sub-array */
		buildSubTree(&((*subTreeNode)->right), sortedArray + middleIndex + 1,
				(subArraySize - 1 - middleIndex), 2);
	}
}

/**
 * sorted_array_to_avl - Convert a sorted array to an AVL tree
 * @array: Pointer to the first element of the sorted array
 * @size: The number of elements in the array
 * Return: A pointer to the root node of the created AVL tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *treeRoot;	/* Pointer to the root of the AVL tree */
	size_t middleIndex; /* Index of the middle element in the array */

	/* Initialize the tree root as NULL */
	treeRoot = NULL;

	/* If the array is empty, return NULL */
	if (size == 0)
		return (NULL);

	/* Calculate the middle index of the array */
	middleIndex = (size / 2);
	/* Adjust the middle index if the size is even */
	middleIndex = (size % 2 == 0) ? middleIndex - 1 : middleIndex;

	/* Create the root node with the middle element of the array */
	treeRoot = binary_tree_node(treeRoot, array[middleIndex]);

	/* Recursively build the left and right subtrees */
	buildSubTree(&treeRoot, array, middleIndex, 1);
	buildSubTree(&treeRoot, array + middleIndex + 1, (size - 1 - middleIndex), 2);

	/* Return the pointer to the root node of the AVL tree */
	return (treeRoot);
}
