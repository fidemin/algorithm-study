#include "SinglyLinkedList.h"

sll_node_t* sll_create_node(sll_element_type_t new_data) {
	sll_node_t* node = malloc(sizeof(sll_node_t));
	node->data = new_data;
	node->next_node = NULL;
	return node;
}

void sll_destroy_node(sll_node_t* node) {
	free(node);
}


void sll_append_node(sll_node_t** head, sll_node_t* node) {
	if (*head == NULL) {
		*head = node;
	} else {
		sll_node_t* current = *head;
		while (current->next_node != NULL) {
			current = current->next_node;
		}
		current->next_node = node;
	}
}


void sll_insert_node_after(sll_node_t* current, sll_node_t* new_node) {
	sll_node_t* old_next_node = current->next_node;
	current->next_node = new_node;
	new_node->next_node = old_next_node;
}


void sll_insert_node_before(sll_node_t** head, sll_node_t* current, sll_node_t* new_node) {
	sll_node_t* before = *head;
	if (before == current) {
		*head = new_node;
		new_node->next_node = current;
		return;
	}
	while (before->next_node != current && before->next_node != NULL) {
		before = before->next_node;
	}
	if (before != NULL) {
		before->next_node = new_node;
		new_node->next_node = current;
	}
}


sll_node_t* sll_remove_node(sll_node_t** head, sll_node_t* removed) {
	sll_node_t* current = *head;
	if (current == removed) {
		*head = current->next_node;
		current->next_node = NULL;
		return removed;
	}
	while (current->next_node != removed && current->next_node != NULL) {
		current = current->next_node;
	}
	if (current != NULL) {
		removed = current->next_node;
		current->next_node = removed->next_node;
		removed->next_node = NULL;
	}
	return removed;
}


sll_node_t* sll_get_node_at(sll_node_t* head, int idx) {
	sll_node_t* current = head;
	while (current != NULL && (--idx) >= 0) {
		current = current->next_node;
	}
	return current;
}


int sll_get_node_count(sll_node_t* head) {
	sll_node_t* current = head;
	int count = 0;

	while (current != NULL) {
		current = current->next_node;
		count++;
	}

	return count;
}


void sll_destroy_all_nodes(sll_node_t** head) {
	sll_node_t* current = *head;

	while (current != NULL) {
		sll_node_t* removed = current;
		current = current->next_node;
		free(removed);
	}

	*head = NULL; 
}
