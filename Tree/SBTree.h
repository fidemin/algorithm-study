#ifndef SB_Tree_H
#define SB_Tree_H

#include <stdio.h>
#include <stdlib.h>

typedef char sbt_element_type_t;

typedef struct _sbt_node {
	struct _sbt_node* left_child;
	struct _sbt_node* right_child; 
	sbt_element_type_t data;
} sbt_node_t;

sbt_node_t* sbt_create_node(sbt_element_type_t data);
void sbt_destroy_node(sbt_node_t* node);
void sbt_preorder_traversal(sbt_node_t* node);
void sbt_inorder_traversal(sbt_node_t* node);
void sbt_postorder_traversal(sbt_node_t* node);

#endif
