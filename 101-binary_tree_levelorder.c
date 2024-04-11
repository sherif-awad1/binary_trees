/*
* File: 101-binary_tree_levelorder.c
* Author: Sherif Awad
*/

/* Include the header file for binary trees */
#include "binary_trees.h"
levelorder_queue_t *create_queue_node(binary_tree_t *tree_node);
void push_node(binary_tree_t *tree_node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int));
void pop_node(levelorder_queue_t **head);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/**
 * create_queue_node - Function to create a new queue node
 * @tree_node: pointer to the node in the binary tree
 * Return: Pointer to the newly created queue node
 */
levelorder_queue_t *create_queue_node(binary_tree_t *tree_node)
{
	levelorder_queue_t *new_node;

	new_node = malloc(sizeof(levelorder_queue_t));
	if (new_node == NULL)
		return (NULL);

	new_node->tree_node = tree_node;
	new_node->next_node = NULL;

	return (new_node);
}

/**
 * free_queue - Function to free the queue
 * @head: pointer to the head of the queue
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *temp_node;

	while (head != NULL)
	{
		temp_node = head->next_node;
		free(head);
		head = temp_node;
	}
}

/**
 * push_node - Function to push a node to the queue
 * @tree_node: pointer to the node in the binary tree
 * @head: pointer to the head of the queue
 * @tail: double pointer to the tail of the queue
 * @func: function pointer to the function to be applied to each node
 */
void push_node(binary_tree_t *tree_node, levelorder_queue_t *head,
			   levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *new_node;

	func(tree_node->n);
	if (tree_node->left != NULL)
	{
		new_node = create_queue_node(tree_node->left);
		if (new_node == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next_node = new_node;
		*tail = new_node;
	}
	if (tree_node->right != NULL)
	{
		new_node = create_queue_node(tree_node->right);
		if (new_node == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next_node = new_node;
		*tail = new_node;
	}
}

/**
 * pop_node - Function to pop a node from the queue
 * @head: double pointer to the head of the queue
 */
void pop_node(levelorder_queue_t **head)
{
	levelorder_queue_t *temp_node;

	temp_node = (*head)->next_node;
	free(*head);
	*head = temp_node;
}

/**
 * binary_tree_levelorder - Function to perform level order traversal of binary
 * @tree: pointer to the root of the binary tree
 * @func: function pointer to the function to be applied to each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *head, *tail;

	if (tree == NULL || func == NULL)
		return;

	head = tail = create_queue_node((binary_tree_t *)tree);
	if (head == NULL)
		return;

	while (head != NULL)
	{
		push_node(head->tree_node, head, &tail, func);
		pop_node(&head);
	}
}
