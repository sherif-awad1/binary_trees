/*
* File: 13-binary_tree_nodes.c
* Author: Sherif Awad
*/
#include "binary_trees.h"

/* Include the header file for binary trees */
#include "binary_trees.h"

/**
 * binary_tree_nodes - Function to count number of non-leaf node in binary tree
 * @tree: pointer to the root node of the binary tree that we’re working with
 * Return: count of leaves and if tree is NULL return 0
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	/* Initialize the count of non-leaf nodes to 0 */
	size_t WithOutLaves = 0;

	/* If the tree is not NULL */
	if (tree)
	{
		/* If node has L or R child increment 1, else add 0 */
		WithOutLaves += (tree->left || tree->right) ? 1 : 0;

		/* Recursively add number of non-leaf nodes in the left subtree */
		WithOutLaves += binary_tree_nodes(tree->left);

		/* Recursively add number of non-leaf nodes in the right subtree */
		WithOutLaves += binary_tree_nodes(tree->right);
	}

	/* Return the count of non-leaf nodes */
	return (WithOutLaves);
}
