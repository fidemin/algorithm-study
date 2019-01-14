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
	if (stack->top == stack->capacity) {
		int new_capa = stack->capacity * 2;

		// update nodes
		as_node_t* old_nodes = stack->nodes;
		as_node_t* new_nodes = (as_node_t*) malloc(sizeof(as_node_t) * new_capa);
		for (int i = 0; i < stack->top; i++) {
			new_nodes[i] = old_nodes[i];
		}
		stack->nodes = new_nodes;
		free(old_nodes);
		
		// update capacity
		stack->capacity = new_capa; 
	}
	stack->nodes[stack->top++].data = data;
}

as_element_type_t as_pop(as_stack_t* stack) {
	as_element_type_t returned = stack->nodes[--(stack->top)].data;
	if ((stack->capacity >= 2) && (stack->top == stack->capacity / 2)) {
		int new_capa = stack->capacity / 2;

		as_node_t* old_nodes = stack->nodes;
		as_node_t* new_nodes = (as_node_t*) malloc(sizeof(as_node_t) * new_capa);
		for (int i = 0; i < new_capa; i++) {
			new_nodes[i] = old_nodes[i];
		}
		stack->nodes = new_nodes;
		free(old_nodes);

		stack->capacity = new_capa;
	}
	return returned;
}


as_element_type_t as_top(as_stack_t* stack) {
	return stack->nodes[(stack->top)-1].data;
}


int as_is_empty(as_stack_t* stack) {
	return (stack->top == 0);
}
