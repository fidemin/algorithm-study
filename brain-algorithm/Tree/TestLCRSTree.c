#include <stdio.h>
#include "TestRunner.h"
#include "LCRSTree.h"

int test_lcrs_create_node() {
	lcrs_element_type_t data = 'A';
	lcrs_node_t* root = lcrs_create_node(data);
	_assert(root->child == NULL);
	_assert(root->sibling == NULL);
	_assert(root->data == data);
	lcrs_destroy_node(root);
	return 0;
}

int test_lcrs_add_child_node() {
	lcrs_node_t* root = lcrs_create_node('A');
	lcrs_node_t* child1 = lcrs_create_node('B');
	lcrs_node_t* child2 = lcrs_create_node('C');
	lcrs_node_t* g_child1 = lcrs_create_node('D');

	lcrs_add_child_node(root, child1);
	lcrs_add_child_node(root, child2);
	lcrs_add_child_node(child1, g_child1);

	_assert(root->child->data == 'B');
	_assert(root->child->sibling->data == 'C');
	_assert(root->child->child->data == 'D');

	lcrs_destroy_tree(root);
	return 0;
}

int test_lcrs_print_tree() {
	lcrs_node_t* root = lcrs_create_node('A');
	lcrs_node_t* child1 = lcrs_create_node('B');
	lcrs_node_t* child2 = lcrs_create_node('C');
	lcrs_node_t* child3 = lcrs_create_node('D');
	lcrs_node_t* g_child1 = lcrs_create_node('E');
	lcrs_node_t* g_child2 = lcrs_create_node('F');
	lcrs_node_t* g_child3 = lcrs_create_node('G');

	lcrs_add_child_node(root, child1);
	lcrs_add_child_node(root, child2);
	lcrs_add_child_node(root, child3);
	lcrs_add_child_node(child1, g_child1);
	lcrs_add_child_node(child1, g_child2);
	lcrs_add_child_node(child2, g_child3);

	lcrs_print_tree(root, 0);

	lcrs_destroy_tree(root);
	return 0;
}

int test_lcrs_print_nodes_at_level() {
	lcrs_node_t* root = lcrs_create_node('A');
	lcrs_node_t* child1 = lcrs_create_node('B');
	lcrs_node_t* child2 = lcrs_create_node('C');
	lcrs_node_t* child3 = lcrs_create_node('D');
	lcrs_node_t* g_child1 = lcrs_create_node('E');
	lcrs_node_t* g_child2 = lcrs_create_node('F');
	lcrs_node_t* g_child3 = lcrs_create_node('G');

	lcrs_add_child_node(root, child1);
	lcrs_add_child_node(root, child2);
	lcrs_add_child_node(root, child3);
	lcrs_add_child_node(child1, g_child1);
	lcrs_add_child_node(child1, g_child2);
	lcrs_add_child_node(child2, g_child3);

	lcrs_print_nodes_at_level(root, 0);
	lcrs_print_nodes_at_level(root, 1);
	lcrs_print_nodes_at_level(root, 2);

	lcrs_destroy_tree(root);
	return 0;
}

int all_tests() {
	_verify(test_lcrs_create_node);
	_verify(test_lcrs_add_child_node);
	_verify(test_lcrs_print_tree);
	_verify(test_lcrs_print_nodes_at_level);
	return 0;
}

int main(int argc, char **argv) {
	int result = all_tests();
	if (result == 0)
		printf("PASSED\n");
	printf("Tests run: %d\n", tests_run);
	return result!=0;
}
