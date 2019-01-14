#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct _pq_node {
	int priority;
	void* data;
} pq_node_t;

typedef struct _pq_queue {
	int capacity;
	int used;
	pq_node_t* nodes;
} pq_queue_t;

pq_queue_t* pq_create_queue(int capacity);
void pq_destroy_queue(pq_queue_t* queue);
void pq_enqueue(pq_queue_t* queue, int priority, void* data);
pq_node_t pq_dequeue(pq_queue_t* queue);
int pq_is_empty(pq_queue_t* queue);

#endif
