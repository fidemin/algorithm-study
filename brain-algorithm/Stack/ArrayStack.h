#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H
#include <stdio.h>
#include <stdlib.h>

typedef int as_element_type_t;

typedef struct {
	as_element_type_t data;
} as_node_t;

typedef struct {
	int capacity;
	int top;
	as_node_t* nodes;
} as_stack_t;

void as_create_stack(as_stack_t** stack, int capacity);
void as_destroy_stack(as_stack_t* stack);
void as_push(as_stack_t* stack, as_element_type_t data);
as_element_type_t as_pop(as_stack_t* stack);
as_element_type_t as_top(as_stack_t* stack);
int as_is_empty(as_stack_t* stack);

#endif
