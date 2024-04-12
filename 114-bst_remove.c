/*
* File: 114-bst_remove.c
* Author: Sherif Awad
*/
/* Include the header file for binary trees */
#include "binary_trees.h"

bst_t *find_inorder_successor(bst_t *root);
bst_t *delete_bst_node(bst_t *root, bst_t *node);
bst_t *remove_bst_value_recursive(bst_t *root, bst_t *current_node, int value);
bst_t *bst_remove(bst_t *root, int value);


/**
 * find_inorder_successor - Finds the inorder successor of a given node.
 * @root: Pointer to the root of the binary search tree.
 *
 * Return: Pointer to the inorder successor node.
 */
bst_t *find_inorder_successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * delete_bst_node - Deletes a node from the binary search tree.
 * @root: Pointer to the root of the binary search tree.
 * @node: Pointer to the node to be deleted.
 *
 * Return: Pointer to the new root of the tree after deletion.
 */
bst_t *delete_bst_node(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}

	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}

	successor = find_inorder_successor(node->right);
	node->n = successor->n;

	return (delete_bst_node(root, successor));
}

/**
 * remove_bst_value_recursive - Removes value from binary search tree recursiv
 * @root: Pointer to the root of the binary search tree.
 * @current_node: Pointer to the current node being checked.
 * @value: Value to be removed.
 *
 * Return: Pointer to the new root of the tree after removal.
 */
bst_t *remove_bst_value_recursive(bst_t *root, bst_t *current_node, int value)
{
	if (current_node != NULL)
	{
		if (current_node->n == value)
			return (delete_bst_node(root, current_node));
		if (current_node->n > value)
			return (remove_bst_value_recursive(root, current_node->left, value));
		return (remove_bst_value_recursive(root, current_node->right, value));
	}
	return (NULL);
}

/**
 * bst_remove - Removes a value from the binary search tree.
 * @root: Pointer to the root of the binary search tree.
 * @value: Value to be removed.
 * Return: Pointer to the new root of the tree after removal.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (remove_bst_value_recursive(root, root, value));
}
