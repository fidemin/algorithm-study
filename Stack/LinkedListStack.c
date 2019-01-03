#include "LinkedListStack.h"


int lls_str_equal(const char* s1, const char* s2) {
	while (*s1 != '\0' && *s1 == *s2) {
		++s1;
		++s2;
	}

	if (*s1 == *s2) {
		return 1;
	}

	return 0;
}

void lls_create_stack(lls_stack_t** stack) {
	*stack = (lls_stack_t*) malloc(sizeof(lls_stack_t));
	(*stack)->head = NULL;
	(*stack)->top = NULL;
}

void lls_destroy_stack(lls_stack_t* stack) {
	lls_node_t* top = stack->top;
	if (top != NULL) {
		lls_node_t* old = top;
		top = top->next_node;
		free(old->data);
		free(old);
	}
	free(stack);
}

// linkedlist is connected for stack. The direction is reverse, which means that top stack node's
// next node is pointing to the stack node before the top stack node.
void lls_push(lls_stack_t* stack, lls_element_type_t data) {
	lls_node_t* new_node = (lls_node_t*) malloc(sizeof(lls_node_t));
	new_node->data = strdup(data);
	new_node->next_node = NULL;

	if (stack->head == NULL) {
		stack->head = new_node;
		stack->top = new_node;
	} else {	
		new_node->next_node = stack->top;
		stack->top = new_node;
	}
}

lls_element_type_t lls_pop(lls_stack_t* stack) {
	if (stack->head == stack->top) {
		stack->head = NULL;
	}
	lls_node_t* old_top = stack->top;
	stack->top = stack->top->next_node;
	old_top->next_node = NULL;
	lls_element_type_t returned = strdup(old_top->data);
	free(old_top->data);
	free(old_top);

	return returned;
}


lls_element_type_t lls_top(lls_stack_t* stack) {
	return strdup(stack->top->data);
}

int lls_is_empty(lls_stack_t* stack) {
	return (stack->top == NULL && stack->head == NULL);
}


int lls_get_size(lls_stack_t* stack) {
	lls_node_t* current = stack->top;
	int count = 0;

	while (current != NULL) {
		current = current->next_node;
		count++;
	}
	return count;
}
