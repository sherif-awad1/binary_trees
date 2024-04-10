/*
* File: 10-binary_tree_depth.c
* Author: Sherif Awad
*/
/* Include the header file for binary trees */
#include "binary_trees.h"

/**
 * binary_tree_depth - Function to calculate the depth of node in binary tree
 * @tree: pointer to the root node of the binary tree that we’re working with
 * Return: depth and if tree is NULL, function must return 0
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
