#include <stdio.h>
#include "TestRunner.h"
#include "ArrayStack.h"

int test_as_create_stack() {
	as_stack_t* stack = NULL;
	int capacity = 4;
	as_create_stack(&stack, capacity);
	_assert(stack->capacity == capacity);
	_assert(stack->top == 0);
	as_destroy_stack(stack);

	return 0;
}

int test_as_push() {
	as_stack_t* stack = NULL;
	int capacity = 4;
	as_create_stack(&stack, capacity);
	as_push(stack, 3);
	_assert(stack->nodes[0].data == 3);
	_assert(stack->top == 1);
	as_push(stack, 2);
	_assert(stack->nodes[1].data == 2);
	_assert(stack->top == 2);
	as_destroy_stack(stack);
	return 0;
};

int test_as_push_with_resizing() {
	as_stack_t* stack = NULL;
	int capacity = 1;
	as_create_stack(&stack, capacity);
	as_push(stack, 3);

	/* FOR MEMORY CHECK: stack dynamically copy  */
	as_node_t* node = (as_node_t*) malloc(sizeof(as_node_t));
	node->data = 123;
	/* FOR MEMORY CHECK END */

	// first resizing
	as_push(stack, 2);	
	_assert(stack->nodes[1].data == 2);
	_assert(stack->top == 2);
	_assert(stack->capacity == 2);

	// second resizing
	as_push(stack, 4);	
	_assert(stack->nodes[2].data == 4);
	_assert(stack->top == 3);
	as_push(stack, 5);
	_assert(stack->nodes[3].data == 5);
	_assert(stack->top == 4);
	_assert(stack->capacity == 4);
	

	/* FOR MEMORY CHECK: stack dynamically copy  */
	as_push(stack, 6);
	as_push(stack, 7);
	as_push(stack, 8);
	_assert(node->data == 123);
	/* FOR MEMORY CHECK END */

	as_destroy_stack(stack);
	return 0;
}

int test_as_pop() {
	as_stack_t* stack = NULL;
	int capacity = 4;
	as_create_stack(&stack, capacity);
	as_push(stack, 3);
	as_push(stack, 2);
	as_element_type_t data1 = as_pop(stack);
	_assert(stack->top == 1);
	_assert(data1 == 2);
	as_element_type_t data2 = as_pop(stack);
	_assert(stack->top == 0);
	_assert(data1 = 3);
	as_destroy_stack(stack);

	return 0;
}

int test_as_pop_with_resizing() {
	as_stack_t* stack = NULL;
	int capacity = 1;
	as_create_stack(&stack, capacity);
	as_push(stack, 3);
	
	// capacity: 1->2
	as_push(stack, 2);

	// capacity: 2->4
	as_push(stack, 1);

	//printf("capacity: %d\n", stack->capacity);
	//printf("top: %d\n", stack->top);
	// capacity 4->2
	as_element_type_t data1 = as_pop(stack);
	_assert(stack->top == 2);
	_assert(data1 == 1);
	_assert(stack->capacity == 2);
	
	//printf("capacity: %d\n", stack->capacity);
	//printf("top: %d\n", stack->top);
	// capacity: 2 -> 1 
	as_element_type_t data2 = as_pop(stack);
	_assert(stack->top == 1);
	_assert(data2 == 2);
	_assert(stack->capacity == 1);

	// capacity doesn't change
	as_element_type_t data3 = as_pop(stack);
	_assert(stack->top == 0);
	_assert(data3 == 3);
	_assert(stack->capacity == 1);

	as_destroy_stack(stack);

	return 0;
}

int test_as_top() {
	as_stack_t* stack = NULL;
	int capacity = 4;
	as_create_stack(&stack, capacity);
	as_push(stack, 3);
	as_push(stack, 2);
	as_element_type_t data1 = as_top(stack);
	_assert(stack->top == 2);
	_assert(data1 == 2);
	return 0;
}

int test_as_is_empty() {
	as_stack_t* stack = NULL;
	int capacity = 4;
	as_create_stack(&stack, capacity);
	_assert(as_is_empty(stack) == 1);
	as_push(stack, 3);
	_assert(as_is_empty(stack) == 0);
	return 0;
}

int all_tests() {
	_verify(test_as_create_stack);
	_verify(test_as_push);
	_verify(test_as_push_with_resizing);
	_verify(test_as_pop);
	_verify(test_as_pop_with_resizing);
	_verify(test_as_top);
	_verify(test_as_is_empty);
    return 0;
}

int main(int argc, char **argv) {
    int result = all_tests();
    if (result == 0)
        printf("PASSED\n");
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
