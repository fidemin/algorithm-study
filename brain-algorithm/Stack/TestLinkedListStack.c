#include <stdio.h>
#include "TestRunner.h"
#include "LinkedListStack.h"

int test_lls_str_equal() {
	const char *str1 = "hello";
    const char *str2 = strdup(str1);
	const char *str3 = "worl";
	_assert(lls_str_equal(str1, str3) == 0);
	_assert(lls_str_equal(str3, str1) == 0);
	_assert(lls_str_equal(str1, str2) == 1);
	return 0;
}

int test_lls_create_stack() {
	lls_stack_t* stack = NULL;
	lls_create_stack(&stack);
	_assert(stack->head == NULL);
	_assert(stack->top == NULL);
	lls_destroy_stack(stack);

	return 0;
}

int test_lls_push() {
	lls_stack_t* stack = NULL;
	lls_create_stack(&stack);
	lls_push(stack, "abc");
	_assert(lls_str_equal(stack->top->data, "abc"));
	_assert(lls_str_equal(stack->head->data, "abc"));
	_assert(stack->head->next_node == NULL);
	lls_push(stack, "abcd");
	_assert(lls_str_equal(stack->top->data, "abcd"));
	_assert(lls_str_equal(stack->top->next_node->data, "abc"));
	_assert(lls_str_equal(stack->head->data, "abc"));
	lls_destroy_stack(stack);
	return 0;
};

int test_lls_pop() {
	lls_stack_t* stack = NULL;
	lls_create_stack(&stack);
	lls_push(stack, "abc");
	lls_push(stack, "abcd");
	lls_element_type_t data1 = lls_pop(stack);
	_assert(lls_str_equal(data1, "abcd") == 1);

	lls_element_type_t data2 = lls_pop(stack);
	_assert(lls_str_equal(data2, "abc") == 1);
	_assert(stack->top == NULL);
	_assert(stack->head == NULL);
	free(data1);
	free(data2);
	lls_destroy_stack(stack);

	return 0;
}

int test_lls_top() {
	lls_stack_t* stack = NULL;
	lls_create_stack(&stack);
	lls_push(stack, "abc");
	lls_push(stack, "abcd");
	lls_element_type_t data1 = lls_top(stack);
	_assert(lls_str_equal(data1, "abcd") == 1);
	free(data1);
	lls_destroy_stack(stack);
	return 0;
}

int test_lls_is_empty() {
	lls_stack_t* stack = NULL;
	lls_create_stack(&stack);
	_assert(lls_is_empty(stack) == 1);
	lls_push(stack, "abc");
	_assert(lls_is_empty(stack) == 0);
	lls_destroy_stack(stack);
	return 0;
}

int test_lls_get_size() {
	lls_stack_t* stack = NULL;
	lls_create_stack(&stack);
	_assert(lls_get_size(stack) == 0);
	lls_push(stack, "abc");
	_assert(lls_get_size(stack) == 1);
	lls_push(stack, "abcd");
	_assert(lls_get_size(stack) == 2);
	return 0;
}

int all_tests() {
	_verify(test_lls_str_equal);
	_verify(test_lls_create_stack);
	_verify(test_lls_push);
	_verify(test_lls_pop);
	_verify(test_lls_top);
	_verify(test_lls_is_empty);
	_verify(test_lls_get_size);
    return 0;
}

int main(int argc, char **argv) {
    int result = all_tests();
    if (result == 0)
        printf("PASSED\n");
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
