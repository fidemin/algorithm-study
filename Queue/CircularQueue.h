#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef int element_type_t;

typedef struct {
	element_type_t data;
} cq_node_t;

typedef struct {
	int capacity;
	int front;
	int rear;
	cq_node_t* nodes;
} cq_queue_t;

void cq_create_queue(cq_queue_t** queue, int capacity);
void cq_destroy_queue(cq_queue_t* queue);
void cq_enqueue(cq_queue_t* queue, element_type_t data);
element_type_t cq_dequeue(cq_queue_t* queue);
int cq_is_full(cq_queue_t* queue);
int cq_is_empty(cq_queue_t* queue);
int cq_next_idx(int idx, int capacity);

#endif

