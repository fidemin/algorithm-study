#include "ArrayStack.h"


void as_create_stack(as_stack_t** stack, int capacity) {
	*stack = (as_stack_t*) malloc(sizeof(as_stack_t));
	(*stack)->capacity = capacity;
	(*stack)->top = 0;
	(*stack)->nodes = (as_node_t*) malloc(sizeof(as_node_t) * capacity);
}

void as_destroy_stack(as_stack_t* stack) {
	free(stack->nodes);
	free(stack);
}

void as_push(as_stack_t* stack, as_element_type_t data) {
	stack->nodes[stack->top++].data = data;
}

as_element_type_t as_pop(as_stack_t* stack) {
	return stack->nodes[--(stack->top)].data;
}


as_element_type_t as_top(as_stack_t* stack) {
	return stack->nodes[(stack->top)-1].data;
}


int as_is_empty(as_stack_t* stack) {
	return (stack->top == 0);
}
