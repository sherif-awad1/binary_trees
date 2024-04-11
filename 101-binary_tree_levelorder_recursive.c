/*
* File: 101-binary_tree_levelorder_rectusive.c
* Author: Sherif Awad
*/

/* Include the header file for binary trees */
#include "binary_trees.h"

/**
 * traverse_levels - Function to traverse levels of the binary tree
 * @head: pointer to the head of the linked list
 * @func: function pointer to the function to be applied to each node
 */
void traverse_levels(linked_list_node *head, void (*func)(int))
{
	linked_list_node *child_nodes = NULL, *current_node = NULL;

	if (!head)
		return;
	for (current_node = head; current_node != NULL; current_node = current_node->next_node)
	{
		func(current_node->tree_node->n);
		child_nodes = fetch_child_nodes(child_nodes, current_node->tree_node);
	}
	traverse_levels(child_nodes, func);
	free_linked_list(child_nodes);
}

/**
 * fetch_child_nodes - Function to get the children of a node in the binary tree
 * @head: pointer to the head of the linked list
 * @parent_node: pointer to the parent node in the binary tree
 * Return: Pointer to the head of the linked list
 */
linked_list_node *fetch_child_nodes(linked_list_node *head, const binary_tree_t *parent_node)
{
	if (parent_node->left)
		head = add_to_list(head, parent_node->left);
	if (parent_node->right)
		head = add_to_list(head, parent_node->right);
	return (head);
}

/**
 * add_to_list - Function to append a node to the linked list
 * @head: pointer to the head of the linked list
 * @tree_node: pointer to the node in the binary tree to be added to the linked list
 * Return: Pointer to the head of the linked list
 */
linked_list_node *add_to_list(linked_list_node *head, const binary_tree_t *tree_node)
{
	linked_list_node *new_node = NULL, *last_node = NULL;

	new_node = malloc(sizeof(*new_node));
	if (new_node)
	{
		new_node->tree_node = tree_node;
		new_node->next_node = NULL;
		if (!head)
			head = new_node;
		else
		{
			last_node = head;
			while (last_node->next_node)
				last_node = last_node->next_node;
			last_node->next_node = new_node;
		}
	}
	return (head);
}

/**
 * free_linked_list - Function to free the linked list
 * @head: pointer to the head of the linked list
 */
void free_linked_list(linked_list_node *head)
{
	linked_list_node *temp_node = NULL;

	while (head)
	{
		temp_node = head->next_node;
		free(head);
		head = temp_node;
	}
}

/**
 * binary_tree_levelorder - Function to perform level order traversal of the binary tree
 * @tree: pointer to the root of the binary tree
 * @func: function pointer to the function to be applied to each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	linked_list_node *child_nodes = NULL;

	func(tree->n);
	child_nodes = fetch_child_nodes(child_nodes, tree);
	traverse_levels(child_nodes, func);

	free_linked_list(child_nodes);
}
