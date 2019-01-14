#ifndef LCRS_TREE_H
#define LCRS_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef char lcrs_element_type_t;

typedef struct _lcrs_node {
	struct _lcrs_node* child;
	struct _lcrs_node* sibling;
	lcrs_element_type_t data;
} lcrs_node_t;

lcrs_node_t* lcrs_create_node(lcrs_element_type_t data);
void lcrs_destroy_node(lcrs_node_t* node);
void lcrs_destroy_tree(lcrs_node_t* node);
void lcrs_add_child_node(lcrs_node_t* parent, lcrs_node_t* child);
void lcrs_print_tree(lcrs_node_t* node, int depth);
void lcrs_print_nodes_at_level(lcrs_node_t* node, int level);

#endif

