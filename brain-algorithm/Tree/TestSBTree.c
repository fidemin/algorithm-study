#include <stdio.h>
#include "TestRunner.h"
#include "SBTree.h"

int test_sbt_create_node() {
	sbt_node_t* node = sbt_create_node('A');
	_assert(node->data == 'A');
	_assert(node->left_child == NULL);
	_assert(node->right_child == NULL);
	sbt_destroy_tree(node);
	return 0;
}

int test_sbt_traversals() {
	sbt_node_t* root = sbt_create_node('A');
	sbt_node_t* child1 = sbt_create_node('B'); 
	sbt_node_t* gchild1 = sbt_create_node('C'); 
	sbt_node_t* gchild2 = sbt_create_node('D'); 
	sbt_node_t* child2 = sbt_create_node('E'); 
	sbt_node_t* gchild3 = sbt_create_node('F'); 
	sbt_node_t* gchild4 = sbt_create_node('G'); 

	root->left_child = child1;
	child1->left_child = gchild1;
	child1->right_child = gchild2;

	root->right_child = child2;
	child2->left_child = gchild3;
	child2->right_child = gchild4;

	printf("[PRINT] Preorder Traversal\n");
	sbt_preorder_traversal(root);
	printf("[PRINT] Inorder Traversal\n");
	sbt_inorder_traversal(root);
	printf("[PRINT] Postorder Traversal\n");
	sbt_postorder_traversal(root);

	sbt_destroy_tree(root);
	return 0;

}

int all_tests() {
	_verify(test_sbt_create_node);
	_verify(test_sbt_traversals);
	return 0;
}

int main(int argc, char **argv) {
	int result = all_tests();
	if (result == 0)
		printf("PASSED\n");
	printf("Tests run: %d\n", tests_run);
	return result!=0;
}
