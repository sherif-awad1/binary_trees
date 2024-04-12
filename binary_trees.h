#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

/* Include libery needed for the project */
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;

/**
 * struct node_s - singly linked list
 * @tree_node: const binary tree node
 * @next_node: points to the next node
 */
typedef struct node_s
{
	const binary_tree_t *tree_node;
	struct node_s *next_node;
} linked_list_node;
/**
 * struct levelorder_queue_s - Level order traversal queue.
 * @tree_node: A node of a binary tree.
 * @next_node: The next node to traverse to in the binary tree.
 */
typedef struct levelorder_queue_s
{
	binary_tree_t *tree_node;
	struct levelorder_queue_s *next_node;
} levelorder_queue_t;


void binary_tree_print(const binary_tree_t *);
/* task 0 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
/* task 1 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
/* task 2 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
/* task 3 */
void binary_tree_delete(binary_tree_t *tree);
/* task 4 */
int binary_tree_is_leaf(const binary_tree_t *node);
/* task 5 */
int binary_tree_is_root(const binary_tree_t *node);
/* task 6 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
/* task 7 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
/* task 8 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
/* task 9 & 14 */
size_t binary_tree_height(const binary_tree_t *tree);
/* task 10 */
size_t binary_tree_depth(const binary_tree_t *tree);
/* task 11 */
size_t binary_tree_size(const binary_tree_t *tree);
/* task 12 */
size_t binary_tree_leaves(const binary_tree_t *tree);
/* task 13 */
size_t binary_tree_nodes(const binary_tree_t *tree);
/* task 14 */
int binary_tree_balance(const binary_tree_t *tree);
/* task 15 */
int binary_tree_is_full(const binary_tree_t *tree);
int is_binary_tree_full(const binary_tree_t *tree);
/* task 16 */

unsigned char check_if_leaf_node(const binary_tree_t *node);
size_t calculate_depth(const binary_tree_t *tree);
const binary_tree_t *find_leaf_node(const binary_tree_t *tree);
int check_if_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level);
int binary_tree_is_perfect(const binary_tree_t *tree);
/* task 17 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
/* task 18 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
/* task 19 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second);
/* task 20 */
levelorder_queue_t *create_queue_node(binary_tree_t *tree_node);
void push_node(binary_tree_t *tree_node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int));
void pop_node(levelorder_queue_t **head);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
/* task 21 */
int binary_tree_is_complete(const binary_tree_t *tree);
/* task 22 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
/* task 23 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);
/* task 24 */

/* task 25 */

/* task 26 */

/* task 27 */

/* task  */







#endif /* _BINARY_TREES_H_ */
