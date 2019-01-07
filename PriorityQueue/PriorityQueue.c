#include "PriorityQueue.h"

pq_queue_t* pq_create_queue(int capacity) {
	pq_queue_t* queue = (pq_queue_t*) malloc(sizeof(pq_create_queue));
	queue->capacity = capacity;
	queue->used = 0;
	queue->nodes = (pq_node_t*) malloc(sizeof(pq_node_t) * capacity);
	return queue;
}

void pq_destroy_queue(pq_queue_t* queue) {
	free(queue->nodes);
	free(queue);
}

void pq_swap(pq_queue_t* queue, int pos1, int pos2) {
	pq_node_t tmp;
	tmp.priority = queue->nodes[pos1].priority;
	tmp.data = queue->nodes[pos1].data;
	queue->nodes[pos1].priority = queue->nodes[pos2].priority;
	queue->nodes[pos1].data = queue->nodes[pos2].data;
	queue->nodes[pos2].priority = tmp.priority;
	queue->nodes[pos2].data = tmp.data;
}


void pq_enqueue(pq_queue_t* queue, int priority, void* data) {
	int current = queue->used;
	queue->nodes[current].priority = priority;
	queue->nodes[current].data = data;
	queue->used++;

	while (1) {
		if (current == 0) {
			break;
		}

		if (queue->nodes[(current-1) / 2].priority > queue->nodes[current].priority) {
			pq_swap(queue, (current-1)/2, current);
			current = (current-1) / 2;
		} else {
			break;
		}
	}
}


pq_node_t pq_dequeue(pq_queue_t* queue) {
	pq_node_t returned = queue->nodes[0];
	queue->nodes[0] = queue->nodes[queue->used-1];
	queue->used--;
	int current = 0;

	while (1) {
		if ((queue->used -1) < 2*current + 1) {
			break;
		}

		if ((queue->used -1) < 2*current + 2) {
			pq_node_t current_node = queue->nodes[current];
			pq_node_t left = queue->nodes[2*current + 1];	
			
			if (left.priority < current_node.priority) {
				pq_swap(queue, 2*current +1, current);
			}
			break;
		}

		pq_node_t current_node = queue->nodes[current];
		pq_node_t left = queue->nodes[2*current + 1];
		pq_node_t right = queue->nodes[2*current + 2];

		if ((left.priority < current_node.priority) || (right.priority < current_node.priority)) {
			if (left.priority <= right.priority) {
				pq_swap(queue, 2*current +1, current);
				current = 2*current + 1;
			} else {
				pq_swap(queue, 2*current +2, current);
				current = 2*current + 2;	
			}
		} else {
			break;
		}
	}
	return returned;
}
