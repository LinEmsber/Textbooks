/* tree.h */


#include <stdio.h>
#include <stdlib.h>


// ======== typedef ========
typedef struct tree tree_t;
typedef struct node node_t;


// ======== structure ========
struct tree
{
        struct node *root;
        int count;
};

struct node
{
        int value;
        void *data;
        struct node *left;
        struct node *right;
};


// ======== compare siblings ========
int compare_value(int value_1, int value_2);


// ======== node ========
node_t *node_create();
void node_remove(node_t *node);
node_t *node_init(node_t *node);
node_t *node_input_value(node_t *node, int value);
node_t *node_input_data(node_t *node, void *input_data);


// ======== tree ========
tree_t *tree_create();
void tree_init( tree_t *tree);
void tree_remove(tree_t *tree);
int tree_count(tree_t *tree);


// ======== insert node ========
node_t *node_insert_node( node_t *node, int value);
tree_t *tree_insert_node( tree_t *tree, int value);
