#include <stdio.h>
#include "TestRunner.h"
#include "DisjointSet.h"

int test_ds_create_node() {
	ds_node_t* node = ds_create_node((void*) 1);
	_assert(1 == (int) node->data);
	_assert(0 == node->rank);
	_assert(NULL == node->parent);
	ds_destroy_node(node);
	return 0;
}

int test_ds_union() {
	ds_node_t* root0 = ds_create_node((void*) 0);
	ds_node_t* root1 = ds_create_node((void*) 1);
	ds_node_t* root2 = ds_create_node((void*) 2);
	ds_node_t* node2_1 = ds_create_node((void*)2);
	ds_union(root2, node2_1);
	_assert(1 == root2->rank);

	ds_union(root1, root2);
	_assert(root1->parent == root2);

	ds_union(root0, root1);
	_assert(root0->parent == root2);

	ds_destroy_node(node2_1);
	ds_destroy_node(root0);
	ds_destroy_node(root1);
	ds_destroy_node(root2);
	return 0;
}

int test_ds_find() {
	ds_node_t* root = ds_create_node((void*) 1);
	ds_node_t* node1_1 = ds_create_node((void*) 2);
	ds_node_t* node1_2 = ds_create_node((void*) 3);
	node1_2->parent = node1_1;
	node1_1->parent = root;
	_assert(root == ds_find(node1_2));
	_assert(root == node1_2->parent);

	ds_destroy_node(node1_2);
	ds_destroy_node(node1_1);
	ds_destroy_node(root);

	return 0;
}

int all_tests() {
	_verify(test_ds_create_node);
	_verify(test_ds_union);
	_verify(test_ds_find);
	return 0;
}

int main(int argc, char **argv) {
	int result = all_tests();
	if (result == 0)
		printf("PASSED\n");
	printf("Tests run: %d\n", tests_run);
	return result!=0;
}
