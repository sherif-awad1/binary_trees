/*
* File: 16-binary_tree_is_perfect.c
* Author: Sherif Awad
*/

/* Include the header file for binary trees */
#include "binary_trees.h"

unsigned char check_if_leaf_node(const binary_tree_t *node);
size_t calculate_depth(const binary_tree_t *tree);
const binary_tree_t *find_leaf_node(const binary_tree_t *tree);
int check_if_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * check_if_leaf_node - Function to check if a node is a leaf node
 * @node: pointer to the node that we’re checking
 * Return: 1 if the node is a leaf node, 0 otherwise.
 */
unsigned char check_if_leaf_node(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * calculate_depth - Function to calculate the depth of a node in a binary tree
 * @tree: pointer to the node that we’re calculating the depth for
 * Return: The depth of the node in the binary tree.
 */
size_t calculate_depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + calculate_depth(tree->parent) : 0);
}

/**
 * find_leaf_node - Function to find a leaf node in a binary tree
 * @tree: pointer to the root node of the binary tree that we’re working with
 * Return: Pointer to a leaf node in the binary tree.
 */
const binary_tree_t *find_leaf_node(const binary_tree_t *tree)
{
	if (check_if_leaf_node(tree) == 1)
		return (tree);
	return (tree->left ? find_leaf_node(tree->left) :
			find_leaf_node(tree->right));
}

/**
 * check_if_perfect_recursive - check if a binary tree is perfect
 * @tree: pointer to the root node of the binary tree that we’re working with
 * @leaf_depth: the depth of a leaf node in the binary tree
 * @level: the current level in the binary tree
 * Return: 1 if the binary tree is perfect, 0 otherwise.
 */
int check_if_perfect_recursive(const binary_tree_t *tree,
							   size_t leaf_depth, size_t level)
{
	if (check_if_leaf_node(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (check_if_perfect_recursive(tree->left, leaf_depth, level + 1) &&
			check_if_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - Function to check if a binary tree is perfect
 * @tree: pointer to the root node of the binary tree that we’re working with
 * Return: If tree NULL return 0. Otherwise, call check_if_perfect_recursive
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (check_if_perfect_recursive(tree,
				calculate_depth(find_leaf_node(tree)), 0));
}
