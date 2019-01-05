#include "DisjointSet.h"

ds_node_t* ds_create_node(void* data) {
	ds_node_t* node = (ds_node_t*) malloc(sizeof(ds_node_t));
	node->data = data;
	node->rank = 0;
	node->parent = NULL;
	return node;
}

void ds_destroy_node(ds_node_t* node) {
	free(node);
}


void ds_union(ds_node_t* node1, ds_node_t* node2) {
	// ds_find is worst case O(log N)
	ds_node_t* root1 = ds_find(node1);
	ds_node_t* root2 = ds_find(node2);

	// unoin by rank
	if (root1->rank < root2->rank) {
		root1->parent = root2;
	} else {
		root2->parent = root1;
	} 

	if (root1->rank == root2->rank) {
		root1->rank++;
	} 
}

ds_node_t* ds_find(ds_node_t* node) {
	// worst O(log N) ; best O(alpha(N)) which is almost constant
	if (node->parent == NULL) {
		return node;
	}

	// path compression
	return node->parent = ds_find(node->parent);
}
