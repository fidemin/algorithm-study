#include "LCRSTree.h"

lcrs_node_t* lcrs_create_node(lcrs_element_type_t data) {
	lcrs_node_t* node = (lcrs_node_t*) malloc(sizeof(lcrs_node_t));
	node->child = NULL;
	node->sibling = NULL;
	node->data = data;
	return node;
}


void lcrs_destroy_node(lcrs_node_t* node) {
	node->child = NULL;
	node->sibling = NULL;
	free(node);
}


void lcrs_destroy_tree(lcrs_node_t* node) {
	if (node == NULL) {
		printf("NULL node cannot be destroyed");
		return;
	}

	if (node->child != NULL) {
		lcrs_destroy_tree(node->child);
	}

	if (node->sibling != NULL) {
		lcrs_destroy_tree(node->sibling);
	}

	lcrs_destroy_node(node);

}


void lcrs_add_child_node(lcrs_node_t* parent, lcrs_node_t* child) {
	lcrs_node_t* last_child = parent->child;
	if (last_child == NULL) {
		parent->child = child;
		return;
	}

	while (last_child->sibling != NULL) {
		last_child = last_child->sibling;
	}
	last_child->sibling = child;
	
}


void lcrs_print_tree(lcrs_node_t* node, int depth) {
	if (node == NULL) {
		printf("NULL node cannot be printed");
		return;
	}

	for (int i=0; i < depth; i++) {
		printf(" ");
	}

	printf("%c\n", node->data);

	if (node->child != NULL) {
		lcrs_print_tree(node->child, depth+1);
	}

	if (node->sibling != NULL) {
		lcrs_print_tree(node->sibling, depth);
	}
}

void lcrs_print_node_at_level_with_depth(lcrs_node_t* node, int level, int depth) {
	if (depth == level) {
		printf("%c\n", node->data);
	}

	if (node->child != NULL && depth <= level) {
		lcrs_print_node_at_level_with_depth(node->child, level, depth+1);
	}

	if (node->sibling != NULL) {
		lcrs_print_node_at_level_with_depth(node->sibling, level, depth);
	}
}

void lcrs_print_nodes_at_level(lcrs_node_t* node, int level) {
	printf("print nodes at level: %d\n", level);
	if (node == NULL) {
		printf("NULL node cannot be printed");
		return;
	}

	lcrs_print_node_at_level_with_depth(node,level,0);
}
