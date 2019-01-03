#ifndef LINKED_LIST_STACK_H
#define LINKED_LIST_STACK_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* lls_element_type_t;

int lls_str_equal(const char* s1, const char* s2);

typedef struct _lls_node {
	lls_element_type_t data;
	struct _lls_node* next_node;
} lls_node_t;

typedef struct {
	lls_node_t* head;
	lls_node_t* top;
} lls_stack_t;

void lls_create_stack(lls_stack_t** stack);
void lls_destroy_stack(lls_stack_t* stack);
void lls_push(lls_stack_t* stack, lls_element_type_t data);
lls_element_type_t lls_pop(lls_stack_t* stack);
lls_element_type_t lls_top(lls_stack_t* stack);
int lls_is_empty(lls_stack_t* stack);
int lls_get_size(lls_stack_t* stack);

#endif
