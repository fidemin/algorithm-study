#include <stdio.h>
#include "TestRunner.h"
#include "BinarySearchTree.h"


int test_bst_create_node() {
	bst_node_t* node = bst_create_node(1);
	node->data = 1;
	node->left = NULL;
	node->right = NULL;
	bst_destroy_node(node);
	return 0;
}

int test_bst_search_node() {
	bst_node_t* node1 = bst_create_node(23);
	bst_node_t* node2 = bst_create_node(11);
	bst_node_t* node3 = bst_create_node(139);
	bst_node_t* node4 = bst_create_node(1);
	bst_node_t* node5 = bst_create_node(14);
	bst_node_t* node6 = bst_create_node(67);
	bst_node_t* node7 = bst_create_node(871);

	node1->left = node2;
	node1->right = node3;
	node2->left = node4;
	node2->right = node5; 
	node3->left = node6;
	node3->right = node7;

	bst_node_t* found = bst_search_node(node1, 871);
	_assert(node7 == found);

	bst_node_t* found2 = bst_search_node(node1, 1);
	_assert(node4 == found2);

	bst_node_t* not_found = bst_search_node(node1, 1000);
	_assert(NULL == not_found);

	bst_destroy_node(node1);
	bst_destroy_node(node2);
	bst_destroy_node(node3);
	bst_destroy_node(node4);
	bst_destroy_node(node5);
	bst_destroy_node(node6);
	bst_destroy_node(node7);
	return 0;	
}

int test_bst_insert_node() {
	bst_node_t* node1 = bst_create_node(23);
	bst_node_t* node2 = bst_create_node(11);
	bst_node_t* node3 = bst_create_node(139);
	bst_node_t* node4 = bst_create_node(1);
	bst_node_t* node5 = bst_create_node(14);
	bst_node_t* node6 = bst_create_node(67);
	bst_node_t* node7 = bst_create_node(871);

	bst_insert_node(node1, node2);
	_assert(node2 == node1->left);

	bst_insert_node(node1, node3);
	_assert(node3 == node1->right);

	bst_insert_node(node1, node4);
	_assert(node4 == node2->left);

	bst_insert_node(node1, node5);
	_assert(node5 == node2->right);

	bst_insert_node(node1, node6);
	_assert(node6 == node3->left);

	bst_insert_node(node1, node7);
	_assert(node7 == node3->right);

	bst_destroy_node(node1);
	bst_destroy_node(node2);
	bst_destroy_node(node3);
	bst_destroy_node(node4);
	bst_destroy_node(node5);
	bst_destroy_node(node6);
	bst_destroy_node(node7);
	return 0;	
}

int test_bst_remove_node() {
	bst_node_t* node1 = bst_create_node(23);
	bst_node_t* node2 = bst_create_node(11);
	bst_node_t* node3 = bst_create_node(139);
	bst_node_t* node4 = bst_create_node(1);
	bst_node_t* node5 = bst_create_node(14);
	bst_node_t* node6 = bst_create_node(67);
	bst_node_t* node7 = bst_create_node(871);

	bst_node_t* root = node1;

	bst_insert_node(root, node2);
	bst_insert_node(root, node3);
	bst_insert_node(root, node4);
	bst_insert_node(root, node5);
	bst_insert_node(root, node6);
	bst_insert_node(root, node7);

	bst_node_t* removed7 = bst_remove_node(&root, 871);
	_assert(node7 == removed7);
	_assert(node3->right == NULL);

	bst_node_t* removed3 = bst_remove_node(&root, 139);
	_assert(node3 == removed3);
	_assert(node1->right == node6);

	bst_node_t* removed2 = bst_remove_node(&root, 11); 
	_assert(node1->left == node5);
	_assert(node2 == removed2); 
	_assert(node5->left == node4);
	_assert(node5->right == NULL);

	bst_node_t* removed1 = bst_remove_node(&root, 23);
	_assert(removed1 == node1);
	_assert(root == node6);
	_assert(node6->left == node5);

	bst_destroy_node(node1);
	bst_destroy_node(node2);
	bst_destroy_node(node3);
	bst_destroy_node(node4);
	bst_destroy_node(node5);
	bst_destroy_node(node6);
	bst_destroy_node(node7);
	return 0;	
}
int all_tests() {
	//_verify(test_sample);
	_verify(test_bst_create_node);
	_verify(test_bst_search_node);
	_verify(test_bst_insert_node);
	_verify(test_bst_remove_node);
	return 0;
}

int main(int argc, char **argv) {
	int result = all_tests();
	if (result == 0)
		printf("PASSED\n");
	printf("Tests run: %d\n", tests_run);
	return result!=0;
}
