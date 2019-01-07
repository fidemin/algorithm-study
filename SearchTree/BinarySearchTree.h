#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef int bst_element_type_t;

typedef struct _bst_node {
	struct _bst_node* left;
	struct _bst_node* right;
	bst_element_type_t data;
} bst_node_t;

bst_node_t* bst_create_node(bst_element_type_t data);
bst_node_t* bst_search_node(bst_node_t* root, bst_element_type_t data);
void bst_insert_node(bst_node_t* root, bst_node_t* node);
bst_node_t* bst_remove_node(bst_node_t** root, bst_element_type_t target);
void bst_destroy_node(bst_node_t* node);

#endif
