#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int sll_element_type_t;

typedef struct sll_node
{
	sll_element_type_t data;
	struct sll_node* next_node;
} sll_node_t;

sll_node_t* sll_create_node(sll_element_type_t new_data);
void sll_destroy_node(sll_node_t* node);
void sll_append_node(sll_node_t** head, sll_node_t* node);
void sll_insert_node_after(sll_node_t* current, sll_node_t* new_node);
void sll_insert_node_before(sll_node_t** head, sll_node_t* current, sll_node_t* new_node);
sll_node_t* sll_remove_node(sll_node_t** head, sll_node_t* removed);
sll_node_t* sll_get_node_at(sll_node_t* head, int position);
sll_node_t* sll_linear_search(sll_node_t* head, int data);
sll_node_t* sll_move_to_front(sll_node_t** head, int data);
sll_node_t* sll_transpose(sll_node_t** head, int data);
int sll_get_node_count(sll_node_t* head);
void sll_destroy_all_nodes(sll_node_t** head);
#endif
