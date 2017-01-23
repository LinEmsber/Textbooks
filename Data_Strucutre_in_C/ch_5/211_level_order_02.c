/* level order traversal in iterative method and use queue */

// gcc 211_level_order_02.c tree.c

#include <stdio.h>
#include "tree.h"

// A structure, queue, for saving node.
typedef struct queue queue_t;

struct queue{
	node_t *element;
	struct queue *next;
};

/* enqueue
 *
 * @queue: the target queue which we want to input nodes into it.
 * @node: the target node
 */
void enqueue(queue_t **queue, node_t *node)
{
	queue_t *q  = NULL;
	queue_t *head  = *queue;

        // check the queue is exist or not.
	if( !(*queue) ){
		q = (queue_t *) malloc( sizeof(queue_t) );
		q -> element = node;
		q -> next = NULL;
		*queue = q;

        // if the queue is exist, we add the new node behind its last node.
	}else{
		q = *queue;

                // move to the queue's last node
		while(q->next)
			q = q->next;

		queue_t *current_node = (queue_t *) malloc( sizeof(queue_t) );
		q->next = current_node;
		current_node -> element = node;
		current_node -> next = NULL;
		*queue = head;
	}
}

/* check the queue is exist or not
 *
 * @queue: the target queue
 */
int is_empty( queue_t *queue )
{
	if( !queue )
                return 1;

	return 0;
}

/* obtain the queue's first node
 *
 * @queue: the target queue
 */
node_t *front(queue_t *queue)
{
	if(queue)
		return queue->element;
}

/* remove the queue's first node
 *
 * @queue: the target queue
 */
void dequeue(queue_t **queue)
{
	queue_t *q = *queue;
	queue_t *node_to_delete = q;

	q = node_to_delete->next;
	node_to_delete = NULL;

	free(node_to_delete);

	*queue = q;
}

// print tree in order level in tertive method which is with queue.
void print_node_order_level_itertive(node_t * node)
{

	queue_t *q =  NULL;
	enqueue(&q, node);

	while( !is_empty(q) ){

		node_t *current_node = front(q);

		printf("%d ", current_node->value);

                dequeue(&q);

                // input the children into queue
		if(current_node->left)
			enqueue(&q, current_node->left);
		if(current_node->right)
			enqueue(&q, current_node->right);
	}
}

int main()
{
	int height = 0;

	tree_t *t = tree_create();
	tree_init(t);

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

	print_node_order_level_itertive(t -> root);
	printf("\n");

}
