
#include <stdio.h>
#include <stdlib.h>

typedef void *data;
typedef struct _linked_list linked_list;

linked_list *get_linked_list_instance();

void remove_linked_list_instance();

void add_node(linked_list *, data);

data remove_node(linked_list *);
