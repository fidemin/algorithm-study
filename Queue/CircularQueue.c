#include "CircularQueue.h"

void cq_create_queue(cq_queue_t** queue, int capacity) {
	*queue = (cq_queue_t*) malloc(sizeof(cq_queue_t));
	(*queue)->capacity = capacity;
	(*queue)->front = 0;
	(*queue)->rear = 0;
	(*queue)->nodes = (cq_node_t*) malloc(sizeof(cq_node_t)*(capacity+1));
}

void cq_destroy_queue(cq_queue_t* queue) {
	free(queue->nodes);
	free(queue);
}

void cq_enqueue(cq_queue_t* queue, element_type_t data) {
	if (cq_is_full(queue)) {
		printf("[WARNING] queue is full\n");
		return;	
	}

	queue->nodes[queue->rear].data = data;
	queue->rear = cq_next_idx(queue->rear, queue->capacity);
}

element_type_t cq_dequeue(cq_queue_t* queue) {
	if (queue->front == queue->rear) {
		// empty
		printf("[WARNING] queue is empty\n");
		return 0;
	}
	element_type_t returned = queue->nodes[queue->front].data;
	queue->front = cq_next_idx(queue->front, queue->capacity);
	return returned;
}

int cq_is_full(cq_queue_t* queue) {
	return cq_next_idx(queue->rear, queue->capacity) % (queue->capacity+1) == queue->front;
}

int cq_is_empty(cq_queue_t* queue) {
	return queue->rear == queue->front;
}

int cq_next_idx(int idx, int capacity) {
	return (idx + 1) % (capacity + 1);
}
