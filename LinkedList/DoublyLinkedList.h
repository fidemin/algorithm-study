#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int dll_element_type_t;

typedef struct dll_node
{
	dll_element_type_t data;
	struct dll_node* prev_node;
	struct dll_node* next_node;
} dll_node_t;

dll_node_t* dll_create_node(dll_element_type_t new_data);
void dll_destroy_node(dll_node_t* node);
void dll_append_node(dll_node_t** head, dll_node_t* node);
void dll_insert_node_after(dll_node_t* current, dll_node_t* new_node);
void dll_insert_node_before(dll_node_t** head, dll_node_t* current, dll_node_t* new_node);
dll_node_t* dll_remove_node(dll_node_t** head, dll_node_t* removed);
dll_node_t* dll_get_node_at(dll_node_t* head, int position);
int dll_get_node_count(dll_node_t* head);
void dll_destroy_all_nodes(dll_node_t** head);
#endif
