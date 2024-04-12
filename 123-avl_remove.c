/*
* File: 123-avl_remove.c
* Author: Sherif Awad
*/
/* Include the header file for AVL tree operations */
#include "binary_trees.h"

/**
 * balanceTree - Balance an AVL tree
 * @treeRef: double pointer to the root node of the AVL tree
 */
void balanceTree(avl_t **treeRef)
{
	int balanceValue;

	/* Return if the tree reference is NULL or the node is NULL */
	if (treeRef == NULL || *treeRef == NULL)
		return;
	/* Return if the node is a leaf node */
	if ((*treeRef)->left == NULL && (*treeRef)->right == NULL)
		return;
	/* Balance the left subtree */
	balanceTree(&(*treeRef)->left);
	/* Balance the right subtree */
	balanceTree(&(*treeRef)->right);
	/* Get the balance value of the current node */
	balanceValue = binary_tree_balance((const binary_tree_t *)*treeRef);
	/* Rotate right if the balance value is greater than 1 (left-heavy) */
	if (balanceValue > 1)
		*treeRef = binary_tree_rotate_right((binary_tree_t *)*treeRef);
	/* Rotate left if the balance value is less than -1 (right-heavy) */
	else if (balanceValue < -1)
		*treeRef = binary_tree_rotate_left((binary_tree_t *)*treeRef);
}

/**
 * findSuccessor - Find the successor of a node in a BST
 * @nodePtr: pointer to the node in the BST
 * Return: the value of the successor node
 */
int findSuccessor(bst_t *nodePtr)
{
	int leftMostValue = 0;

	/* Return 0 if the node pointer is NULL */
	if (nodePtr == NULL)
	{
		return (0);
	}
	else
	{
		/* Recursively find the leftmost child */
		leftMostValue = findSuccessor(nodePtr->left);
		/* If leftmost child is not found, return the current node's value */
		if (leftMostValue == 0)
		{
			return (nodePtr->n);
		}
		/* Return the leftmost child's value */
		return (leftMostValue);
	}
}

/**
 * determineRemovalType - Remove node from aST and determine the type of remova
 * @rootNode: pointer to the root node of the BST
 * Return: the value to replace the removed node or 0 if no replacement needed
 */
int determineRemovalType(bst_t *rootNode)
{
	int replacementValue = 0;

	if (!rootNode->left && !rootNode->right)
	{
		if (rootNode->parent->right == rootNode)
			rootNode->parent->right = NULL;
		else
			rootNode->parent->left = NULL;
		free(rootNode);
		return (0);
	}
	/* If the node has one child, replace it with the child */
	else if ((!rootNode->left && rootNode->right) ||
			(!rootNode->right && rootNode->left))
	{
		if (!rootNode->left)
		{
			if (rootNode->parent->right == rootNode)
				rootNode->parent->right = rootNode->right;
			else
				rootNode->parent->left = rootNode->right;
			rootNode->right->parent = rootNode->parent;
		}
		if (!rootNode->right)
		{
			if (rootNode->parent->right == rootNode)
				rootNode->parent->right = rootNode->left;
			else
				rootNode->parent->left = rootNode->left;
			rootNode->left->parent = rootNode->parent;
		}
		free(rootNode);
		return (0);
	}
	else
	{
		replacementValue = findSuccessor(rootNode->right);
		rootNode->n = replacementValue;
		return (replacementValue);
	}
}

/**
 * removeValueFromBST - Remove a value from a BST
 * @rootNode: pointer to the root node of the BST
 * @valueToRemove: the value to remove from the BST
 * Return: pointer to the root node of the BST after removal
 */
bst_t *removeValueFromBST(bst_t *rootNode, int valueToRemove)
{
	int removalType = 0;

	/* Return NULL if the root node is NULL */
	if (rootNode == NULL)
		return (NULL);
	/* Recursively search for the value in the left subtree */
	if (valueToRemove < rootNode->n)
		removeValueFromBST(rootNode->left, valueToRemove);
	/* Recursively search for the value in the right subtree */
	else if (valueToRemove > rootNode->n)
		removeValueFromBST(rootNode->right, valueToRemove);
	/* If the value is found, remove the node */
	else if (valueToRemove == rootNode->n)
	{
		removalType = determineRemovalType(rootNode);
		/* If the node had two children, remove the successor */
		if (removalType != 0)
			removeValueFromBST(rootNode->right, removalType);
	}
	/* Return NULL if the value is not found */
	else
		return (NULL);
	/* Return the root node of the BST */
	return (rootNode);
}

/**
 * avl_remove - function is responsible for removing given value from AVL tree
 * @root: A pointer to the root node of the AVL tree.
 * @value: The integer value to be removed from the AVL tree.
 * Return: This function returns a pointer to the root node of the AVL treea
 * fter the value has been removed and the tree has been rebalanced.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	/* Cast the root to bst_t* and call removeValueFromBST to remove the value */
	avl_t *updatedRoot = (avl_t *)removeValueFromBST((bst_t *)root, value);

	/* Return NULL if the updated root is NULL after removal */
	if (updatedRoot == NULL)
		return (NULL);
	/* Balance the AVL tree after removal */
	balanceTree(&updatedRoot);
	/* Return the root of the balanced AVL tree */
	return (updatedRoot);
}
