/*
* File: 102-binary_tree_is_complete.c
* Author: Sherif Awad
*/
/* Include the header file for binary trees */
#include "binary_trees.h"

/**
 * create_queue_node - Function to create a new queue node
 * @tree_node: pointer to the node in the binary tree
 * Return: Pointer to the newly created queue node
 */
levelorder_queue_t *create_queue_node(binary_tree_t *tree_node)
{
	levelorder_queue_t *new_queue_node;

	new_queue_node = malloc(sizeof(levelorder_queue_t));
	if (new_queue_node == NULL)
		return (NULL);

	new_queue_node->tree_node = tree_node;
	new_queue_node->next_node = NULL;

	return (new_queue_node);
}

/**
 * free_queue - Frees a levelorder_queue_t queue.
 * @head: A pointer to the head of the queue.
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
 * push_to_queue - Function to push a node to the queue
 * @tree_node: pointer to the node in the binary tree
 * @head: pointer to the head of the queue
 * @tail: double pointer to the tail of the queue
 */
void push_to_queue(binary_tree_t *tree_node, levelorder_queue_t *head,
				   levelorder_queue_t **tail)
{
	levelorder_queue_t *new_queue_node;

	new_queue_node = create_queue_node(tree_node);
	if (new_queue_node == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next_node = new_queue_node;
	*tail = new_queue_node;
}

/**
 * pop_from_queue - Function to pop a node from the queue
 * @head: double pointer to the head of the queue
 */
void pop_from_queue(levelorder_queue_t **head)
{
	levelorder_queue_t *temp_node;

	temp_node = (*head)->next_node;
	free(*head);
	*head = temp_node;
}

/**
 * binary_tree_is_complete - Function to check if a binary tree is complete
 * @tree: pointer to the root of the binary tree
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *head, *tail;
	unsigned char flag = 0;

	if (tree == NULL)
		return (0);

	head = tail = create_queue_node((binary_tree_t *)tree);
	if (head == NULL)
		exit(1);

	while (head != NULL)
	{
		if (head->tree_node->left != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push_to_queue(head->tree_node->left, head, &tail);
		}
		else
			flag = 1;
		if (head->tree_node->right != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push_to_queue(head->tree_node->right, head, &tail);
		}
		else
			flag = 1;
		pop_from_queue(&head);
	}
	return (1);
}
