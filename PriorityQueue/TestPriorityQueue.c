#include <stdio.h>
#include "TestRunner.h"
#include "PriorityQueue.h"

int test_pq_create_queue() {
	pq_queue_t* queue = pq_create_queue(100);
	_assert(100 == queue->capacity);
	_assert(0 == queue->used);

	pq_destroy_queue(queue);
	
	return 0;
}

int test_pq_enqueue() {
	pq_queue_t* queue = pq_create_queue(100);
	pq_enqueue(queue, 161, (void*) 1);
	_assert(1 == queue->used);
	_assert(161 == queue->nodes[0].priority);
	_assert(1 == (int) queue->nodes[0].data);
	
	pq_enqueue(queue, 52, (void*) 2);
	pq_enqueue(queue, 67, (void*) 3);
	pq_enqueue(queue, 8, (void*) 4);
	pq_enqueue(queue, 2, (void*) 5);
	pq_enqueue(queue, 7, (void*) 6);
	pq_enqueue(queue, 13, (void*) 7);

	_assert(7 == queue->used);

	int priorities[] = {2, 8, 7, 161, 52, 67, 13};
	int datas[] = {5, 4, 6, 1, 2, 3, 7};

	for (int i = 0; i < queue->used; i++) {
		_assert(priorities[i] == queue->nodes[i].priority);
		_assert(datas[i] == (int) queue->nodes[i].data);
	}

	pq_destroy_queue(queue);

	return 0;
}

int test_pq_dequeue() {
	/*
	 *	        2
	 *	       /  \
	 *	     8      7
	 *	    / \    / \
	 *	  161  52  67 13
	*/
	pq_queue_t* queue = pq_create_queue(100);
	pq_enqueue(queue, 161, (void*) 1);
	pq_enqueue(queue, 52, (void*) 2);
	pq_enqueue(queue, 67, (void*) 3);
	pq_enqueue(queue, 8, (void*) 4);
	pq_enqueue(queue, 2, (void*) 5);
	pq_enqueue(queue, 7, (void*) 6);
	pq_enqueue(queue, 13, (void*) 7);
	
	pq_node_t node2 = pq_dequeue(queue);
	
	_assert(6 == queue->used);
	_assert(2 == node2.priority);
	_assert(5 == (int) node2.data);

	int priorities1[] = {7, 8, 13, 161, 52, 67};
	int datas1[] = {6, 4, 7, 1, 2, 3};
	for (int i = 0; i < queue->used; i++) {
		_assert(priorities1[i] == queue->nodes[i].priority);
		_assert(datas1[i] == (int) queue->nodes[i].data);
	}

	pq_node_t node7 = pq_dequeue(queue);

	_assert(5 == queue->used);
	_assert(7 == node7.priority);
	_assert(6 == (int) node7.data);
	
	int priorities2[] = {8, 52, 13, 161, 67};
	int datas2[] = {4, 2, 7, 1, 3};
	for (int i = 0; i < queue->used; i++) {
		_assert(priorities2[i] == queue->nodes[i].priority);
		_assert(datas2[i] == (int) queue->nodes[i].data);
	}
	pq_dequeue(queue);
	pq_dequeue(queue);
	pq_dequeue(queue);
	pq_dequeue(queue);
	
	pq_node_t last = pq_dequeue(queue);
	_assert(0 == queue->used);
	_assert(161 == last.priority);
	_assert(1 == (int) last.data);

	



	return 0;
}

int all_tests() {
	_verify(test_pq_create_queue);
	_verify(test_pq_enqueue);
	_verify(test_pq_dequeue);
	return 0;
}

int main(int argc, char **argv) {
	int result = all_tests();
	if (result == 0)
		printf("PASSED\n");
	printf("Tests run: %d\n", tests_run);
	return result!=0;
}
