/* tree.c */

#include <stdlib.h>
#include "tree.h"


// ======== typedef ========
typedef struct node node_t;
typedef struct tree tree_t;



// ======== compare siblings ========

/* compare two values to determine the node to turn left or right.
 *
 * 	equal == 0
 * 	/	\
 * left == -1	right == 1
 *
 * @value_1: the value of value_1
 * @value_2: the value of value_2
 */
int compare_value(int value_1, int value_2)
{
	// turn left, return -1
	if(value_1 > value_2) {
		return -1;

		// turn right, return 1
	}else if(value_1 < value_2) {
		return 1;

		// equal, return 1
	}else {
		return 0;
	}
}


// ======== node ========

/* Allocate a memory for a node.
 */
node_t *node_create()
{
	node_t *node = (node_t *) malloc ( sizeof(node_t) );
	return node;
}


/* Remove a node, including children of node.
 *
 * @tree: the node want to remove.
 */
void node_remove(node_t *node)
{
	if (node != NULL){
		node_remove(node -> left);
		node_remove(node -> right);
		free(node);
	}
}


/* Initialize a node.
 *
 * @tree: the node want to initialize.
 */
node_t *node_init(node_t *node)
{
	node -> value = 0;
	node -> data = NULL;
	node -> left = NULL;
	node -> right = NULL;
	return node;
}

/* input a value into a node
 */
node_t *node_input_value(node_t *node, int value)
{
	node -> value = value;
	return node;
}

/* input a data into a node.
 */
node_t *node_input_data(node_t *node, void *input_data)
{
	node -> data = input_data;
	return node;
}


// ======== tree ========

/* Allocate a memory for a tree.
 */
tree_t *tree_create()
{
	tree_t *tree = (tree_t*) malloc ( sizeof(tree_t) );
	return tree;
}


/* Initialize a tree.
 *
 * @tree: the tree want to initialize.
 */
void tree_init( tree_t *tree)
{
	tree -> root = NULL;
	tree -> count = 0;
}


/* Remove a tree.
 *
 * @tree: the tree want to remove.
 */
void tree_remove(tree_t *tree)
{
	if ( tree != NULL && tree->root != NULL ){
		node_remove(tree -> root);
		tree -> root = NULL;
		tree -> count = 0;
	}
}

/* Return the count of the tree.
 *
 * @tree: the tree we want to count node.
 */
int tree_count(tree_t *tree)
{
	return tree -> count;
}

// ======== insert node ========

/* insert a node into a node
 *
 * @node: the node to be inserted node
 * @value: the value of inserted node
 */
node_t *node_insert_node( node_t *node, int value)
{
	if (node == NULL){
		node_t *node = node_create();
		node_init(node);
		node_input_value(node, value);
		return node;

	}else{
		int compare_ret = compare_value(node->value, value);

		// If node -> value > input_value, turn left.
		if (compare_ret == -1 ){
			node -> left = node_insert_node(node->left, value);

			// If node -> value < input_value, turn right.
			// It the input_value has already contained in the tree, and put it in the right side.
		}else if (compare_ret == 1 || compare_ret == 0){
			node -> right = node_insert_node(node->right, value);

		}
		return node;
	}
}

/* insert a node into a tree
 *
 * @tree: the tree to be inserted node
 * @value: the value of inserted node
 */
tree_t *tree_insert_node( tree_t *tree, int value)
{
	tree -> root = node_insert_node(tree->root, value);
	(tree -> count) ++;

	return tree;
}
