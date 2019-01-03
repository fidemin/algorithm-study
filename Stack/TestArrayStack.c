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
	_verify(test_as_pop);
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
