#include <stdio.h>
#include "TestRunner.h"
#include "LinkedList.h"

int test_sll_create_node() {
	sll_node_t* node = sll_create_node(1);
	_assert(node != NULL);
	_assert(node->next_node == NULL);
	_assert(node->data == 1);
	sll_destroy_node(node);
	return 0;
} 

int test_sll_append_node() {
	sll_node_t* list = NULL;
	sll_node_t* node1 = sll_create_node(2);
	sll_node_t* node2 = sll_create_node(3);
	sll_append_node(&list, node1);
	sll_append_node(&list, node2); 
	_assert(list->data == node1->data);
	_assert(list->next_node == node2);
	sll_destroy_node(node1);
	sll_destroy_node(node2);
	return 0;
}

int test_sll_insert_node_after() {
	sll_node_t* list = NULL;
	sll_node_t* node1 = sll_create_node(2);
	sll_node_t* node2 = sll_create_node(3);
	sll_append_node(&list, node1);
	sll_append_node(&list, node2);

	sll_node_t* new_node = sll_create_node(5);
	sll_insert_node_after(node1, new_node);
	_assert(node1->next_node == new_node);
	_assert(new_node->next_node == node2);
	sll_destroy_node(node1);
	sll_destroy_node(node2);
	sll_destroy_node(new_node);
	return 0;
}

int test_sll_insert_node_before() {
	sll_node_t* list = NULL;
	sll_node_t* node1 = sll_create_node(2);
	sll_node_t* node2 = sll_create_node(3);	
	sll_append_node(&list, node1);
	sll_append_node(&list, node2);

	// insert new node before head of list
	sll_node_t* new_head = sll_create_node(6);
	sll_insert_node_before(&list, node1, new_head);
	_assert(list == new_head);
	_assert(list->next_node == node1);

	// insert new node before node2
	sll_node_t* new_node = sll_create_node(5);
	sll_insert_node_before(&list, node2, new_node);
	_assert(node1->next_node == new_node);
	_assert(new_node->next_node == node2);
	sll_destroy_node(node1);
	sll_destroy_node(node2);
	sll_destroy_node(new_node);
	sll_destroy_node(new_head);
	return 0;
}

int test_sll_remove_node() {
	sll_node_t* list = NULL;
	sll_node_t* node1 = sll_create_node(2);
	sll_node_t* node2 = sll_create_node(3);	
	sll_node_t* node3 = sll_create_node(3);	
	sll_node_t* node4 = sll_create_node(3);	
	sll_append_node(&list, node1);
	sll_append_node(&list, node2);
	sll_append_node(&list, node3);
	sll_append_node(&list, node4);

	sll_node_t* removed = sll_remove_node(&list, node3);
	_assert(removed == node3);
	_assert(removed->next_node == NULL);
	_assert(node2->next_node == node4);

	sll_node_t* removed_head = sll_remove_node(&list, node1);
	_assert(removed_head == node1);
	_assert(removed_head->next_node == NULL);
	_assert(list == node2);

	sll_destroy_node(node1);
	sll_destroy_node(node2);
	sll_destroy_node(node3);
	sll_destroy_node(node4);

	return 0;	
}

int test_sll_get_node_at() {
	sll_node_t* list = NULL;
	sll_node_t* node1 = sll_create_node(2);
	sll_node_t* node2 = sll_create_node(3);	
	sll_node_t* node3 = sll_create_node(3);	
	sll_node_t* node4 = sll_create_node(3);	
	sll_append_node(&list, node1);
	sll_append_node(&list, node2);
	sll_append_node(&list, node3);
	sll_append_node(&list, node4);

	sll_node_t* node_head = sll_get_node_at(list, 0);
	_assert(node_head == node1);
	sll_node_t* node_at_2 = sll_get_node_at(list, 2);
	_assert(node_at_2 == node3);
	sll_node_t* node_last = sll_get_node_at(list, 3);
	_assert(node_last == node4);
	sll_node_t* node_out_of_index = sll_get_node_at(list, 5);
	_assert(node_out_of_index == NULL);

	sll_destroy_node(node1);
	sll_destroy_node(node2);
	sll_destroy_node(node3);
	sll_destroy_node(node4);

	return 0;	
}

int test_sll_get_node_count() {
	sll_node_t* list = NULL;
	_assert(sll_get_node_count(list) == 0);

	sll_node_t* node1 = sll_create_node(2);
	sll_node_t* node2 = sll_create_node(3);	
	sll_node_t* node3 = sll_create_node(3);	
	sll_node_t* node4 = sll_create_node(3);	
	sll_append_node(&list, node1);
	sll_append_node(&list, node2);
	sll_append_node(&list, node3);
	sll_append_node(&list, node4);
	_assert(sll_get_node_count(list) == 4);

	sll_destroy_node(node1);
	sll_destroy_node(node2);
	sll_destroy_node(node3);
	sll_destroy_node(node4);

	return 0;
}

int test_destroy_all_nodes() {
	sll_node_t* list = NULL;
	sll_node_t* node1 = sll_create_node(2);
	sll_node_t* node2 = sll_create_node(3);	
	sll_node_t* node3 = sll_create_node(3);	
	sll_node_t* node4 = sll_create_node(3);	
	sll_append_node(&list, node1);
	sll_append_node(&list, node2);
	sll_append_node(&list, node3);
	sll_append_node(&list, node4);
	
	destroy_all_nodes(&list);
	_assert(list == NULL);

	return 0;
}


int all_tests() {
	_verify(test_sll_create_node);
	_verify(test_sll_append_node);
	_verify(test_sll_insert_node_after);
	_verify(test_sll_insert_node_before);
	_verify(test_sll_remove_node);
	_verify(test_sll_get_node_at);
	_verify(test_sll_get_node_count);
	_verify(test_destroy_all_nodes);
	return 0;
}

int main(int argc, char **argv) {
	int result = all_tests();
	if (result == 0)
		printf("PASSED\n");
	printf("Tests run: %d\n", tests_run);
	return result!=0;
}
