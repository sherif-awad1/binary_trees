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
 * Return: Pointer to the inserted node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *newNode, *nodeToSwap;
	int treeSize, leafCount, subtreeSize, bitMask, treeLevel, tempValue;

	/* If the pointer to the root is NULL, return NULL */
	if (!root)
		return (NULL);
	/* If the heap is empty, create a new root node with the value */
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	/* Calculate the size of the heap */
	treeSize = binary_tree_size(tree);
	leafCount = treeSize;
	/* Determine the level of the tree where the new node will be inserted */
	for (treeLevel = 0, subtreeSize = 1; leafCount >= subtreeSize;
			subtreeSize *= 2, treeLevel++)
		leafCount -= subtreeSize;
	/* Find the position to insert the new node */
	for (bitMask = 1 << (treeLevel - 1); bitMask != 1; bitMask >>= 1)
		tree = leafCount & bitMask ? tree->right : tree->left;
	/* Create the new node and insert it into the tree */
	newNode = binary_tree_node(tree, value);
	/* Attach the new node to the appropriate child of the tree */
	leafCount & 1 ? (tree->right = newNode) : (tree->left = newNode);

	/* Swap the new node with its parent nodes to maintain max-heap property */
	nodeToSwap = newNode;
	while (nodeToSwap->parent && (nodeToSwap->n > nodeToSwap->parent->n))
	{
		tempValue = nodeToSwap->n;
		nodeToSwap->n = nodeToSwap->parent->n;
		nodeToSwap->parent->n = tempValue;
		newNode = newNode->parent;
	}
	/* Return the pointer to the newly inserted node */
	return (newNode);
}

/**
 * binary_tree_size - Calculates the size of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: The total number of nodes in the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	/* If the tree is NULL, its size is 0 */
	if (!tree)
		return (0);

	/* Return the size of the left subtree + size of the right subtree + 1 */
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

