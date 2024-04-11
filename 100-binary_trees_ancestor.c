/*
* File: 100-binary_trees_ancestor.c
* Author: Sherif Awad
*/
/* Including the binary_trees header file */
#include "binary_trees.h"

/**
 * binary_trees_ancestor - Function to find lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: Pointer to lowest common ancestor node if it exists, NULL otherwise
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *first_parent, *second_parent;

	/* If either of the nodes is NULL, return NULL */
	if (!first || !second)
		return (NULL);

	/* If the nodes are the same, return a pointer to either of the nodes */
	if (first == second)
		return ((binary_tree_t *)first);

	first_parent = first->parent, second_parent = second->parent;

	/* If 1st node is P of 2nd node or 1st node has no P and 2nd node has  p */
	/* recursively call function with the 1st node and P of 2nd node */
	if (first == second_parent || !first_parent ||
			(!first_parent->parent && second_parent))
		return (binary_trees_ancestor(first, second_parent));

	/* If the 2nd node P of 1st node or 2nd node has no P and 1st node has P */
	/* recursively call function with P of 1st node and 2nd node */
	else if (first_parent == second || !second_parent ||
			(!second_parent->parent && first_parent))
		return (binary_trees_ancestor(first_parent, second));

	/* else, recursively call function with  parents of first, second nodes */
	return (binary_trees_ancestor(first_parent, second_parent));
}

