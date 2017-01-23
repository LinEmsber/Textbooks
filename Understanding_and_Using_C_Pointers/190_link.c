
#include "190_link.h"


typedef struct _node{
	data *d;
	struct _node *next;
}

struct _linked_list{
	node *head;
}



linked_list *get_linked_list_instance()
{
	linked_list *list = (linked_list *) malloc(sizeof(linked_list));
	list -> head = NULL;
	return list;
}


void remove_linked_list_instance(linked_list *list)
{
	node *tmp = list -> head;
	while(tmp != NULL){
		free(tmp->data);
		node *current = tmp;
		tmp = tmp -> next;
		free(current);
	}
	free(list);
}

void add_node(linked_list *, data)
{
	node *n = (node *)malloc (sizeof(node));
	node -> d = data;

	if (list -> head == NULL){
		list -> head = node;
		node -> next = NULL;
	}else{
		node -> next = list -> head;
		list -> head = node;
	}
}


data remove_node(linked_list *)
{
	if (list -> head == NULL){
		return NULL;
	}else{
		node *tmp = list -> head;
		data *d;

		list -> head = list -> head -> next;
		data = tmp -> d;
		free(tmp);

		return data;
	}
}
