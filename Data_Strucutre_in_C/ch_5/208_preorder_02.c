/* transfer a binary tree into linked list using level order traversal */

// gcc 211_level_order_03.c tree.c

#include <stdio.h>
#include "tree.h"


// ====== structrue =====
// linked list node
typedef struct l_node l_node_t;
struct l_node{
	void *data;
	struct l_node *next;
};


// linked list
typedef struct list list_t;
struct list{
	l_node_t * head;
	int length;
};

// ===== operations =====
// To create a new node.
l_node_t * l_node_create( void * data)
{
	l_node_t *node = (l_node_t *) malloc( sizeof(l_node_t) );

	node -> data = data;
	node -> next = NULL;

	return node;
}

// To initialize a list that is using mutex for thread-safe.
void list_init(list_t *list)
{
	list -> head = NULL;
	list -> length = 0;
}

// To create a linked list.
list_t * list_create()
{
	list_t *list = (list_t *)malloc(sizeof(list_t));
	return list;
}


// Insert a node into a list
list_t * list_insert_data( list_t * list, void * data)
{
	// set a current node to search the last node in the list
	l_node_t * tmp;
	l_node_t * current = list -> head;
	l_node_t * n = l_node_create(data);

	if ( current == NULL )
		list -> head = n;
	else{
		while ( current != NULL){
			tmp = current;
			current = current -> next;
		}

		tmp -> next = n;
		tmp -> next -> next = NULL;
	}

	list -> length++;

	return list;
}




// print tree in order level in tertive method which is with queue.
void node_order_level_to_list( list_t *l, node_t * root)
{

	// If this tree still have any node, we continue the loop
	if ( root ){
		list_insert_data(l, root);

		// input the children into queue
		if(root -> left)
			// enqueue(&q, root -> left);
			node_order_level_to_list( l, root -> left);
		if(root -> right)
			// enqueue(&q, root -> right);
			node_order_level_to_list( l, root -> right);
	}

}

int main()
{
	// create a linked list
	list_t * l = list_create();
	list_init(l);

	// create a binary tree
	tree_t *t = tree_create();
	tree_init(t);

	// save something into tree
	tree_insert_node(t, 30);
	tree_insert_node(t, 10);
	tree_insert_node(t, 50);
	tree_insert_node(t, 5);
	tree_insert_node(t, 40);
	tree_insert_node(t, 60);
	tree_insert_node(t, 15);
	tree_insert_node(t, 35);
	tree_insert_node(t, 45);
	tree_insert_node(t, 70);

	// transfer a tree into list
	node_order_level_to_list( l, t -> root);

	// print out the result
	l_node_t * h = l -> head;
	for (h ; h != NULL; h = h -> next){
		printf("%d ", ( (node_t *) (h -> data) ) -> value );
	}
	printf("\n");

}
