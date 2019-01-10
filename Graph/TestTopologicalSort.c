#include <stdio.h>
#include "TestRunner.h"
#include "ALGraph.h"
#include "SinglyLinkedList.h"
#include "TopologicalSort.h"

int test_ts_sort() {
	alg_graph_t* graph = alg_create_graph();
	alg_vertex_t* vertex1 = alg_create_vertex(1);
	alg_add_vertex(graph, vertex1);
	alg_vertex_t* vertex2 = alg_create_vertex(2);
	alg_add_vertex(graph, vertex2);
	alg_vertex_t* vertex3 = alg_create_vertex(3);
	alg_add_vertex(graph, vertex3);
	alg_vertex_t* vertex4 = alg_create_vertex(4);
	alg_add_vertex(graph, vertex4);
	alg_vertex_t* vertex5 = alg_create_vertex(5);
	alg_add_vertex(graph, vertex5);
	alg_vertex_t* vertex6 = alg_create_vertex(6);
	alg_add_vertex(graph, vertex6);
	alg_vertex_t* vertex7 = alg_create_vertex(7);
	alg_add_vertex(graph, vertex7);
	alg_vertex_t* vertex8 = alg_create_vertex(8);
	alg_add_vertex(graph, vertex8);

	alg_add_edge(vertex1, vertex3, 1);
	alg_add_edge(vertex3, vertex6, 1);
	alg_add_edge(vertex6, vertex8, 1);
	alg_add_edge(vertex1, vertex4, 1);
	alg_add_edge(vertex4, vertex6, 1);
	alg_add_edge(vertex4, vertex7, 1);
	alg_add_edge(vertex7, vertex8, 1);
	alg_add_edge(vertex2, vertex3, 1);
	alg_add_edge(vertex2, vertex5, 1);
	alg_add_edge(vertex5, vertex7, 1);

	alg_print_graph(graph);

	sll_node_t* list = NULL;
	ts_sort(graph, &list);

	sll_node_t* current = list;
	_assert(vertex2 == current->data);
	current = current->next_node;
	_assert(vertex5 == current->data);
	current = current->next_node;
	_assert(vertex1 == current->data);
	current = current->next_node;
	_assert(vertex4 == current->data);
	current = current->next_node;
	_assert(vertex7 == current->data);
	current = current->next_node;
	_assert(vertex3 == current->data);
	current = current->next_node;
	_assert(vertex6 == current->data);
	current = current->next_node;
	_assert(vertex8 == current->data);
	current = current->next_node;
	_assert(NULL == current);

	sll_destroy_all_nodes(&list);
	alg_destroy_graph(graph);

	
	return 0;
}

int all_tests() {
	_verify(test_ts_sort);
	return 0;
}

int main(int argc, char **argv) {
	int result = all_tests();
	if (result == 0)
		printf("PASSED\n");
	printf("Tests run: %d\n", tests_run);
	return result!=0;
}
