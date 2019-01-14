#include "LinkedListQueue.h"


llq_queue_t* llq_create_queue() {
	llq_queue_t* queue = (llq_queue_t*) malloc(sizeof(llq_queue_t));
	queue->size = 0;
	queue->head = NULL;
	queue->tail = NULL;
	return queue;
}

void llq_destroy_queue(llq_queue_t* queue) {
	llq_node_t* current = queue->head;
	while (current != NULL) {
		llq_node_t* old = current;
		current = current->next;
		llq_destroy_node(old);
	}
	free(queue);
}


llq_node_t* llq_create_node(llq_element_type_t data) {
	llq_node_t* node = (llq_node_t*) malloc(sizeof(llq_node_t));
	node->next = NULL;
	node->data = data;
	return node;
}


void llq_destroy_node(llq_node_t* node) {
	free(node);
}



void llq_enqueue(llq_queue_t* queue, llq_node_t* node) {
	queue->size++;

	if (queue->head == NULL && queue->tail == NULL) {
		queue->head = node;
		queue->tail = node;
		return;
	}

	queue->tail->next = node;
	queue->tail = node;
}


llq_node_t* llq_dequeue(llq_queue_t* queue) {
	if (queue->head == NULL && queue->tail == NULL) {
		return NULL;
	}

	queue->size--;
	llq_node_t* returned = queue->head;
	queue->head = queue->head->next;

	if (queue->head == NULL) {
		queue->tail = NULL;
	}

	return returned;
}

int llq_is_empty(llq_queue_t* queue) {
	return (queue->head == NULL && queue->tail == NULL && queue->size == 0);
}
