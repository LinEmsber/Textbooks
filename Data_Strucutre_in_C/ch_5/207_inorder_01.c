/* inorder traversal */

// gcc 207_inorder_01.c tree.c

#include <stdio.h>
#include "tree.h"

void node_inorder(node_t *root)
{

        if (root){
                node_inorder(root -> left);
                printf("%d ", root -> value);
                node_inorder(root -> right);
        }
}

int main()
{
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

        node_inorder(t -> root);
        printf("\n");
}
