/*
* File: 121-avl_insert.c
* Author: Sherif Awad
*/
/* Include the header file for binary trees */
#include "binary_trees.h"

/**
 * binaryTreeHeight - Calculates the height of a binary tree.
 * @tree: Pointer to the root node of the binary tree.
 * Return: Height of the tree.
 */
size_t binaryTreeHeight(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t leftHeight = 0, rightHeight = 0;

		/* Calculate height of left subtree */
		leftHeight = tree->left ? 1 + binaryTreeHeight(tree->left) : 1;
		/* Calculate height of right subtree */
		rightHeight = tree->right ? 1 + binaryTreeHeight(tree->right) : 1;
		/* Return maximum of left and right subtree heights */
		return ((leftHeight > rightHeight) ? leftHeight : rightHeight);
	}
	return (0); /* Empty tree has height 0 */
}

/**
 * binaryTreeBalance - Calculates the balance factor of a binary tree.
 * @tree: Pointer to the root node of the binary tree.
 * Return: Balance factor (left height - right height).
 */
int binaryTreeBalance(const binary_tree_t *tree)
{
	/* Calculate balance factor for a given node */
	return (tree != NULL ? binaryTreeHeight(tree->left) -
			binaryTreeHeight(tree->right) : 0);
}

/**
 * avlInsertRecursive - Inserts a value into an AVL tree recursively.
 * @tree: Pointer to the root node of the AVL tree.
 * @parent: Pointer to the parent node.
 * @newNode: Pointer to store the newly inserted node.
 * @value: Value to insert.
 * Return: Pointer to the inserted node.
 */
avl_t *avlInsertRecursive(avl_t **tree, avl_t *parent,
		avl_t **newNode, int value)
{
	int balanceFactor;

	/* If tree is empty, create a new node */
	if (*tree == NULL)
		return (*newNode = binary_tree_node(parent, value));
	/* Recursively insert into left or right subtree */
	if ((*tree)->n > value)
	{
		(*tree)->left = avlInsertRecursive(&(*tree)->left, *tree, newNode, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avlInsertRecursive(&(*tree)->right, *tree, newNode, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		/* Value already exists, no insertion needed */
		return (*tree);

	/* Update balance factor and perform rotations if necessary */
	balanceFactor = binaryTreeBalance(*tree);
	if (balanceFactor > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (balanceFactor < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (balanceFactor > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (balanceFactor < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: Pointer to the root node of the AVL tree.
 * @value: Value to insert.
 * Return: Pointer to the newly inserted node.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *newNode = NULL;

	/* Handle empty tree case */
	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	/* Insert recursively and return the newly inserted node */
	return (avlInsertRecursive(tree, *tree, &newNode, value));
}
