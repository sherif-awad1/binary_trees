/*
* File: 131-heap_insert.c
* Author: Sherif Awad
*/

/* Include the header file for AVL tree operations */
#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * @value: The value to insert into the heap
 * Return: A pointer to the inserted node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *currentNode, *newNode, *swapNode;
	int totalNodes, leafCount, levelNodes, levelBit, treeLevel, swapValue;

	/* Check if root is NULL */
	if (!root)
		return (NULL);

	/* Create a new node if heap is empty */
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));

	/* Initialize variables */
	currentNode = *root;
	totalNodes = binary_tree_size(currentNode);
	leafCount = totalNodes;

	/* Calculate the number of nodes at the current level */
	for (treeLevel = 0, levelNodes = 1; leafCount >= levelNodes;
			levelNodes *= 2, treeLevel++)
		leafCount -= levelNodes;
	for (levelBit = 1 << (treeLevel - 1); levelBit != 1; levelBit >>= 1)
		currentNode = leafCount & levelBit ?
			currentNode->right : currentNode->left;

	newNode = binary_tree_node(currentNode, value);
	leafCount & 1 ? (currentNode->right = newNode) :
		(currentNode->left = newNode);
	swapNode = newNode;
	for (; swapNode->parent && (swapNode->n > swapNode->parent->n);
			swapNode = swapNode->parent)
	{
		swapValue = swapNode->n;
		swapNode->n = swapNode->parent->n;
		swapNode->parent->n = swapValue;
		newNode = newNode->parent;
	}

	/* Return the new node */
	return (newNode);
}

/**
 * binary_tree_size - Calculates the size of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: The total number of nodes in the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	/* Return 0 if tree is NULL */
	if (!tree)
		return (0);

	/* Recursively calculate the size of the tree */
	return (binary_tree_size(tree->left) +
			binary_tree_size(tree->right) + 1);
}
