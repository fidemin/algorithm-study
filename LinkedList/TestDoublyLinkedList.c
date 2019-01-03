#include <stdio.h>
#include "TestRunner.h"
#include "DoublyLinkedList.h"

int test_dll_create_node() {
	dll_node_t* node = dll_create_node(1);
	_assert(node != NULL);
	_assert(node->prev_node == NULL);
	_assert(node->next_node == NULL);
	_assert(node->data == 1);
	dll_destroy_node(node);
	return 0;
} 

int test_dll_append_node() {
	dll_node_t* list = NULL;
	dll_node_t* node1 = dll_create_node(2);
	dll_node_t* node2 = dll_create_node(3);
	dll_append_node(&list, node1);
	dll_append_node(&list, node2); 
	_assert(list->data == node1->data);
	_assert(list->next_node == node2);
	_assert(node2->prev_node == node1);
	dll_destroy_node(node1);
	dll_destroy_node(node2);
	return 0;
}

int test_dll_insert_node_after() {
	dll_node_t* list = NULL;
	dll_node_t* node1 = dll_create_node(2);
	dll_node_t* node2 = dll_create_node(3);
	dll_append_node(&list, node1);
	dll_append_node(&list, node2);

	dll_node_t* new_node = dll_create_node(5);
	dll_insert_node_after(node1, new_node);
	_assert(node1->next_node == new_node);
	_assert(new_node->next_node == node2);
	_assert(new_node->prev_node == node1);
	_assert(node2->prev_node == new_node);
	dll_destroy_node(node1);
	dll_destroy_node(node2);
	dll_destroy_node(new_node);
	return 0;
}

int test_dll_insert_node_before() {
	dll_node_t* list = NULL;
	dll_node_t* node1 = dll_create_node(2);
	dll_node_t* node2 = dll_create_node(3);	
	dll_append_node(&list, node1);
	dll_append_node(&list, node2);

	// insert new node before head of list
	dll_node_t* new_head = dll_create_node(6);
	dll_insert_node_before(&list, node1, new_head);
	_assert(list == new_head);
	_assert(new_head->next_node == node1);
	_assert(node1->prev_node == new_head);

	// insert new node before node2
	dll_node_t* new_node = dll_create_node(5);
	dll_insert_node_before(&list, node2, new_node);
	_assert(node1->next_node == new_node);
	_assert(new_node->prev_node == node1);
	_assert(new_node->next_node == node2);
	_assert(node2->prev_node == new_node);
	dll_destroy_node(node1);
	dll_destroy_node(node2);
	dll_destroy_node(new_node);
	dll_destroy_node(new_head);
	return 0;
}

int test_dll_remove_node() {
	dll_node_t* list = NULL;
	dll_node_t* node1 = dll_create_node(2);
	dll_node_t* node2 = dll_create_node(3);	
	dll_node_t* node3 = dll_create_node(3);	
	dll_node_t* node4 = dll_create_node(3);	
	dll_append_node(&list, node1);
	dll_append_node(&list, node2);
	dll_append_node(&list, node3);
	dll_append_node(&list, node4);

	// remove head node
	dll_node_t* removed_head = dll_remove_node(&list, node1);
	_assert(removed_head == node1);
	_assert(removed_head->next_node == NULL);
	_assert(list == node2);
	_assert(node2->prev_node == NULL);

	// remove node
	dll_node_t* removed = dll_remove_node(&list, node3);
	_assert(removed == node3);
	_assert(removed->next_node == NULL);
	_assert(removed->prev_node == NULL);
	_assert(node2->next_node == node4);
	_assert(node4->prev_node == node2);

	dll_destroy_node(node1);
	dll_destroy_node(node2);
	dll_destroy_node(node3);
	dll_destroy_node(node4);

	return 0;	
}

int test_dll_get_node_at() {
	dll_node_t* list = NULL;
	dll_node_t* node1 = dll_create_node(2);
	dll_node_t* node2 = dll_create_node(3);	
	dll_node_t* node3 = dll_create_node(3);	
	dll_node_t* node4 = dll_create_node(3);	
	dll_append_node(&list, node1);
	dll_append_node(&list, node2);
	dll_append_node(&list, node3);
	dll_append_node(&list, node4);

	dll_node_t* node_head = dll_get_node_at(list, 0);
	_assert(node_head == node1);
	dll_node_t* node_at_2 = dll_get_node_at(list, 2);
	_assert(node_at_2 == node3);
	dll_node_t* node_last = dll_get_node_at(list, 3);
	_assert(node_last == node4);
	dll_node_t* node_out_of_index = dll_get_node_at(list, 5);
	_assert(node_out_of_index == NULL);

	dll_destroy_node(node1);
	dll_destroy_node(node2);
	dll_destroy_node(node3);
	dll_destroy_node(node4);

	return 0;	
}

int test_dll_get_node_count() {
	dll_node_t* list = NULL;
	_assert(dll_get_node_count(list) == 0);

	dll_node_t* node1 = dll_create_node(2);
	dll_node_t* node2 = dll_create_node(3);	
	dll_node_t* node3 = dll_create_node(3);	
	dll_node_t* node4 = dll_create_node(3);	
	dll_append_node(&list, node1);
	dll_append_node(&list, node2);
	dll_append_node(&list, node3);
	dll_append_node(&list, node4);
	_assert(dll_get_node_count(list) == 4);

	dll_destroy_node(node1);
	dll_destroy_node(node2);
	dll_destroy_node(node3);
	dll_destroy_node(node4);

	return 0;
}

int test_dll_destroy_all_nodes() {
	dll_node_t* list = NULL;
	dll_node_t* node1 = dll_create_node(2);
	dll_node_t* node2 = dll_create_node(3);	
	dll_node_t* node3 = dll_create_node(3);	
	dll_node_t* node4 = dll_create_node(3);	
	dll_append_node(&list, node1);
	dll_append_node(&list, node2);
	dll_append_node(&list, node3);
	dll_append_node(&list, node4);
	
	dll_destroy_all_nodes(&list);
	_assert(list == NULL);

	return 0;
}


int all_tests() {
	_verify(test_dll_create_node);
	_verify(test_dll_append_node);
	_verify(test_dll_insert_node_after);
	_verify(test_dll_insert_node_before);
	_verify(test_dll_remove_node);
	_verify(test_dll_get_node_at);
	_verify(test_dll_get_node_count);
	_verify(test_dll_destroy_all_nodes);
	return 0;
}

int main(int argc, char **argv) {
	int result = all_tests();
	if (result == 0)
		printf("PASSED\n");
	printf("Tests run: %d\n", tests_run);
	return result!=0;
}
