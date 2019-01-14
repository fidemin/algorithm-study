#include <stdio.h>
#include "TestRunner.h"
#include "CircularQueue.h"

int test_cq_create_queue() {
	cq_queue_t* queue = NULL;
	int capacity = 4;
	cq_create_queue(&queue, capacity);
	_assert(queue->front == 0);
	_assert(queue->rear == 0);
	_assert(queue->capacity == capacity);
	cq_destroy_queue(queue);
	return 0;
}

int test_cq_enqueue() {
	cq_queue_t* queue = NULL;
	int capacity = 4;
	cq_create_queue(&queue, capacity);
	cq_enqueue(queue, 1);
	_assert(queue->nodes[0].data == 1);
	_assert(queue->rear == 1);
	_assert(queue->front == 0);
	
	cq_enqueue(queue, 2);
	cq_enqueue(queue, 3);
	cq_enqueue(queue, 4);
	_assert(queue->nodes[3].data == 4);
	_assert(queue->rear == 4);

	cq_enqueue(queue, 5); 
	_assert(queue->rear == 4);
	return 0;	
}

int test_cq_dequeue() {
	cq_queue_t* queue = NULL;
	int capacity = 4;
	cq_create_queue(&queue, capacity);
	cq_enqueue(queue, 1);
	cq_enqueue(queue, 2);
	cq_enqueue(queue, 3);
	cq_enqueue(queue, 4); // full

	element_type_t data = cq_dequeue(queue);
	_assert(data == 1);
	_assert(queue->front == 1);

	cq_dequeue(queue);
	cq_dequeue(queue);
	element_type_t data1 = cq_dequeue(queue);
	_assert(data1 == 4);
	_assert(queue->front == 4);

	// dequeuing empyt queue
	cq_dequeue(queue);
	_assert(queue->front == 4);

	return 0;
}

int test_cq_circular_enqueue_dequeue() {
	cq_queue_t* queue = NULL;
	int capacity = 4;
	cq_create_queue(&queue, capacity);
	cq_enqueue(queue, 1);
	cq_enqueue(queue, 2);
	cq_enqueue(queue, 3);
	cq_enqueue(queue, 4); // full

	cq_dequeue(queue);
	cq_dequeue(queue);

	cq_enqueue(queue, 5);
	_assert(queue->rear == 0);
	_assert(queue->nodes[4].data == 5);
	cq_enqueue(queue, 6);
	_assert(queue->rear == 1);
	_assert(queue->nodes[0].data == 6);
	_assert(cq_is_full(queue) == 1);

	cq_enqueue(queue, 6); // enqueuing to full queue
	// no change to queue->rear
	_assert(queue->rear == 1);

	cq_dequeue(queue);
	cq_dequeue(queue);
	cq_dequeue(queue);
	// front should be zero.
	_assert(queue->front == 0);

	element_type_t data = cq_dequeue(queue);
	_assert(data == 6);
	_assert(queue->front == 1);
	_assert(cq_is_empty(queue) == 1);

	// dequeuing empty queue
	cq_dequeue(queue);
	_assert(queue->front == 1);

	return 0;
}

int all_tests() {
	_verify(test_cq_create_queue);
	_verify(test_cq_enqueue);
	_verify(test_cq_dequeue);
	_verify(test_cq_circular_enqueue_dequeue);
    return 0;
}

int main(int argc, char **argv) {
    int result = all_tests();
    if (result == 0)
        printf("PASSED\n");
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
