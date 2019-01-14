#ifndef LINKED_LIST_QUEUE_H
#define LINKED_LIST_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef int llq_element_type_t;

typedef struct _llq_node {
	llq_element_type_t data;
	struct _llq_node* next;
} llq_node_t;

typedef struct _llq_queue {
	llq_node_t* head;
	llq_node_t* tail;
	int size;
} llq_queue_t;

llq_queue_t* llq_create_queue();
void llq_destroy_queue(llq_queue_t* queue);
llq_node_t* llq_create_node(llq_element_type_t data);
void llq_destroy_node(llq_node_t* node);
void llq_enqueue(llq_queue_t* queue, llq_node_t* node);
llq_node_t* llq_dequeue(llq_queue_t* queue); 
int llq_is_empty(llq_queue_t* queue);

#endif
