/*
* File: 121-avl_insert.c
* Author: Sherif Awad
*/
/* Include the header file for AVL tree operations */
#include "binary_trees.h"

/* Function prototypes */

size_t calculateHeight(const binary_tree_t *tree);
int calculateBalance(const binary_tree_t *tree);
avl_t *insertValueRecursively(avl_t **tree, avl_t *parent,
		avl_t **newNode, int value);
avl_t *avl_insert(avl_t **tree, int value);

/**
 * calculateHeight - Calculate the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: the height of the tree If tree is NULL, return 0
 */
size_t calculateHeight(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t leftHeight = 0, rightHeight = 0;

		/* Calculate the height of the left subtree, if it exists */
		leftHeight = tree->left ? 1 + calculateHeight(tree->left) : 1;
		/* Calculate the height of the right subtree, if it exists */
		rightHeight = tree->right ? 1 + calculateHeight(tree->right) : 1;

		/* Return the greater of the two heights */
		return ((leftHeight > rightHeight) ? leftHeight : rightHeight);
	}
	/* If the tree is NULL, the height is 0 */
	return (0);
}

/**
 * calculateBalance - Compute the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to calculate the balance factor
 * Return: the balance factor of the tree
 *         If tree is NULL, return 0
 */
int calculateBalance(const binary_tree_t *tree)
{
	/* balance factor is difference between heights of left and right subtrees */
	return (tree != NULL ? calculateHeight(tree->left) -
			calculateHeight(tree->right) : 0);
}

/**
 * insertValueRecursively - Recursively insert a value in an AVL tree
 * @tree: double pointer to the root node of the AVL tree
 * @parent: pointer to the parent node
 * @newNode: double pointer to the newly inserted node
 * @value: the value to insert in the tree
 * Return: pointer to the inserted node
 *         If the value is already present, return the existing node
 *         If memory allocation fails, return NULL
 */
avl_t *insertValueRecursively(avl_t **tree, avl_t *parent,
		avl_t **newNode, int value)
{
	int balanceFactor;

	if (*tree == NULL)
		return (*newNode = binary_tree_node(parent, value));

	/* If value is less than current node's value, insert it into left subtree */
	if ((*tree)->n > value)
	{
		(*tree)->left = insertValueRecursively(&(*tree)->left,
				*tree, newNode, value);
		/* If the left child could not be created, return NULL */
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = insertValueRecursively(&(*tree)->right,
				*tree, newNode, value);
		/* If the right child could not be created, return NULL */
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);
	balanceFactor = calculateBalance(*tree);
	if (balanceFactor > 1 && value < (*tree)->left->n)
		return (binary_tree_rotate_right(*tree));
	if (balanceFactor < -1 && value > (*tree)->right->n)
		return (binary_tree_rotate_left(*tree));
	if (balanceFactor > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		return (binary_tree_rotate_right(*tree));
	}
	if (balanceFactor < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		return (binary_tree_rotate_left(*tree));
	}
	return (*tree);
}

/**
 * avl_insert - Insert a value in an AVL tree
 * @tree: double pointer to the root node of the AVL tree
 * @value: the value to insert in the tree
 * Return: pointer to the newly inserted node
 *         If the tree is NULL, return NULL
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *newNode = NULL;

	/* If the tree pointer is NULL, return NULL */
	if (tree == NULL)
		return (NULL);
	/* If the tree is empty, create a new root node with the given value */
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	insertValueRecursively(tree, *tree, &newNode, value);
	return (newNode);
}
