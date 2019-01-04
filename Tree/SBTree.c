#include "SBTree.h"

sbt_node_t* sbt_create_node(sbt_element_type_t data) {
	sbt_node_t* node = (sbt_node_t*) malloc(sizeof(sbt_node_t));
	node->data = data;
	node->left_child = NULL;
	node->right_child = NULL;
	return node;
}

void sbt_destroy_node(sbt_node_t* node) {
	node->left_child = NULL;
	node->right_child = NULL;
	free(node);
}

void sbt_preorder_traversal_sub(sbt_node_t* node) {
	if (node == NULL) {
		printf("[WARNING] null node cannot be printed");
		return;
	}

	printf("%c", node->data);
	if (node->left_child != NULL) {
		printf(" ( ");
		sbt_preorder_traversal_sub(node->left_child);	
	}

	if (node->left_child != NULL && node->right_child != NULL) {
		printf(", ");
	}

	if (node->right_child != NULL) {
		sbt_preorder_traversal_sub(node->right_child);	
		printf(" )");
	} 
}

void sbt_preorder_traversal(sbt_node_t* node) {
	if (node == NULL) {
		printf("[WARNING] null node cannot be printed");
		return;
	}

	printf("(");
	sbt_preorder_traversal_sub(node);
	printf(")\n");
}

void sbt_inorder_traversal(sbt_node_t* node) {
	if (node == NULL) {
		printf("[WARNING] null node cannot be printed");
		return;
	}

	if (node->left_child != NULL) {
		sbt_inorder_traversal(node->left_child);	
	}
	
	printf("%c\n", node->data);

	if (node->right_child != NULL) {
		sbt_inorder_traversal(node->right_child);	
	} 
}

void sbt_postorder_traversal(sbt_node_t* node) {
	if (node == NULL) {
		printf("[WARNING] null node cannot be printed");
		return;
	}

	if (node->left_child != NULL) {
		sbt_postorder_traversal(node->left_child);	
	}
	
	if (node->right_child != NULL) {
		sbt_postorder_traversal(node->right_child);	
	} 
	
	printf("%c\n", node->data);
}
