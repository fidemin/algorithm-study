#include <stdio.h>
#include "TestRunner.h"
#include "LinkedListQueue.h"

int test_llq_create_queue() {
	llq_queue_t* queue = llq_create_queue();
	_assert(NULL == queue->head);
	_assert(NULL == queue->tail);
	_assert(0 == queue->size);

	llq_destroy_queue(queue);
	return 0;
}

int test_llq_create_node() {
	llq_node_t* node = llq_create_node(1);
	_assert(NULL == node->next);
	_assert(1 == node->data);
	llq_destroy_node(node);
	return 0;
}

int test_llq_enqueue() {
	llq_queue_t* queue = llq_create_queue();
	llq_node_t* node1 = llq_create_node(1);
	llq_enqueue(queue, node1);
	_assert(node1 == queue->head);
	_assert(node1 == queue->tail);
	_assert(1 == queue->size);

	llq_node_t* node2 = llq_create_node(2);
	llq_enqueue(queue, node2);
	_assert(node1 == queue->head);
	_assert(node2 == queue->tail);
	_assert(2 == queue->size);

	llq_destroy_queue(queue);
	return 0;
}

int test_llq_dequeue() {
	llq_queue_t* queue = llq_create_queue();
	llq_node_t* node1 = llq_create_node(1);
	llq_enqueue(queue, node1);

	llq_node_t* node2 = llq_create_node(2);
	llq_enqueue(queue, node2);

	llq_node_t* node3 = llq_create_node(3);
	llq_enqueue(queue, node3);

	llq_node_t* deq1 = llq_dequeue(queue);
	_assert(node1 == deq1);
	_assert(node2 == queue->head);
	_assert(node3 == queue->tail);
	_assert(2 == queue->size);

	llq_node_t* deq2 = llq_dequeue(queue);
	_assert(node2 == deq2);
	_assert(node3 == queue->head);
	_assert(node3 == queue->tail);
	_assert(1 == queue->size);

	llq_node_t* deq3 = llq_dequeue(queue);
	_assert(node3 == deq3);
	_assert(NULL == queue->head);
	_assert(NULL == queue->tail);
	_assert(0 == queue->size);

	llq_destroy_node(node1);
	llq_destroy_node(node2);
	llq_destroy_node(node3);
	llq_destroy_queue(queue);
	return 0;
}

int test_llq_is_empty() {
	llq_queue_t* queue = llq_create_queue();
	_assert(1 == llq_is_empty(queue));
	llq_enqueue(queue, llq_create_node(1));
	_assert(0 == llq_is_empty(queue));
	
	llq_destroy_queue(queue);
	return 0;
}

int all_tests() {
	_verify(test_llq_create_queue);
	_verify(test_llq_create_node);
	_verify(test_llq_enqueue);
	_verify(test_llq_dequeue);
	_verify(test_llq_is_empty);
	return 0;
}

int main(int argc, char **argv) {
	int result = all_tests();
	if (result == 0)
		printf("PASSED\n");
	printf("Tests run: %d\n", tests_run);
	return result!=0;
}
