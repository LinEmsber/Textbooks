/* level order traversal */

// gcc 211_level_order_01.c tree.c

#include <stdio.h>
#include "tree.h"

// Compute the level(height) of a tree, the number of nodes along the longest path
// from the root node down to the farthest leaf node.
int node_level(node_t* node)
{
	if (node == NULL){
		return 0;
	}else{
		// compute the height of each subtree
		int l_height = node_level(node->left);
		int r_height = node_level(node->right);

		// use the larger one
		if (l_height > r_height){
			return l_height + 1;
		}else{
			return r_height + 1;
		}
	}
}

// Print nodes at a given level.
int print_node_given_level(node_t* root, int level)
{
	// check node is exist or not
	if (root == NULL){
		return 0;
	}

	// find the children nodes in recursive way.
	if (level == 1){
		printf("%d ", root->value);
	}else if (level > 1){
		print_node_given_level(root->left, level-1);
		print_node_given_level(root->right, level-1);
	}

	return 1;
}

// function to line by line print level order traversal a tree
void print_node_level_order(node_t* root)
{
	int i;
	int h = node_level(root);

	for (i = 1; i <= h; i++){
		print_node_given_level(root, i);
		printf("\n");
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

        print_node_level_order(t -> root);

}
