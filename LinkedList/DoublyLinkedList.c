#include "DoublyLinkedList.h"

dll_node_t* dll_create_node(dll_element_type_t new_data) {
	dll_node_t* node = malloc(sizeof(dll_node_t));
	node->data = new_data;
	node->next_node = NULL;
	node->prev_node = NULL;
	return node;
}

void dll_destroy_node(dll_node_t* node) {
	free(node);
}


void dll_append_node(dll_node_t** head, dll_node_t* node) {
	if (*head == NULL) {
		*head = node;
	} else {
		dll_node_t* current = *head;
		while (current->next_node != NULL) {
			current = current->next_node;
		}
		current->next_node = node;
		node->prev_node = current;
	}
}


void dll_insert_node_after(dll_node_t* current, dll_node_t* new_node) {
	current->next_node->prev_node = new_node;
	new_node->next_node = current->next_node;

	current->next_node = new_node;
	new_node->prev_node = current;

}


void dll_insert_node_before(dll_node_t** head, dll_node_t* current, dll_node_t* new_node) {
	if (*head == current) {
		*head = new_node;
		new_node->next_node = current;
		current->prev_node = new_node;
		return;
	}

	current->prev_node->next_node = new_node;
	new_node->prev_node = current->prev_node;

	current->prev_node = new_node;
	new_node->next_node = current;
}


dll_node_t* dll_remove_node(dll_node_t** head, dll_node_t* removed) {
	if (*head == removed) {
		*head = (*head)->next_node;
		(*head)->prev_node->next_node = NULL;
		(*head)->prev_node = NULL;
		return removed;
	}

	removed->prev_node->next_node = removed->next_node;
	removed->next_node->prev_node = removed->prev_node;
	
	removed->prev_node = NULL;
	removed->next_node = NULL;
	return removed;
}


dll_node_t* dll_get_node_at(dll_node_t* head, int idx) {
	dll_node_t* current = head;
	while (current != NULL && (--idx) >= 0) {
		current = current->next_node;
	}
	return current;
}

int dll_get_node_count(dll_node_t* head) {
	dll_node_t* current = head;
	int count = 0;

	while (current != NULL) {
		current = current->next_node;
		count++;
	}

	return count;
}

void dll_destroy_all_nodes(dll_node_t** head) {
	dll_node_t* current = *head;

	while (current != NULL) {
		dll_node_t* removed = current;
		current = current->next_node;
		removed->next_node = NULL;
		removed->prev_node = NULL;
		free(removed);
	}

	*head = NULL; 
}
